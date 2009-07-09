/*
 *   ShinyCocos - ruby bindings for the cocos2d-iphone game framework
 *   Copyright (C) 2009, Rolando Abarca M.
 *
 *   This library is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU Lesser General Public
 *   License as published by the Free Software Foundation; either
 *   version 2.1 of the License.
 *
 *   This library is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#import <Foundation/Foundation.h>
#import "SC_common.h"

VALUE rb_mCocos2D;
NSMutableDictionary *sc_object_hash;
NSMutableDictionary *sc_schedule_methods;
NSMutableDictionary *sc_handler_hash;

#pragma mark Common

void sc_free(void *ptr) {
	[(((cocos_holder *)(ptr))->_obj) release];
	free(ptr);
}

VALUE sc_init(VALUE klass, cocos_holder **ret_ptr, id object, int argc, VALUE *argv, BOOL release_on_free) {
	VALUE obj;
	cocos_holder *ptr;
	if (release_on_free)
		obj = Data_Make_Struct(klass, cocos_holder, 0, sc_free, ptr);
	else
		obj = Data_Make_Struct(klass, cocos_holder, 0, free, ptr);
	ptr->_obj = object;
	rb_obj_call_init(obj, argc, argv);
	if (ret_ptr != nil)
		*ret_ptr = ptr;
	return obj;
}

VALUE rb_hash_with_touch(UITouch *touch) {
	// touch should be a hash in the ruby world
	// with keys like :location, :tap_count, :timestamp
	CGPoint loc = [touch locationInView:[touch view]];
	NSUInteger taps = [touch tapCount];
	VALUE h = rb_hash_new();
	rb_hash_aset(h, ID2SYM(id_sc_location), rb_ary_new3(2, rb_float_new(loc.x), rb_float_new(loc.y)));
	rb_hash_aset(h, ID2SYM(id_sc_tap_count), INT2FIX(taps));
	return h;
}

VALUE rb_ary_with_set(NSSet *touches) {
	NSArray *arr = [touches allObjects];
	VALUE rb_arr = rb_ary_new2([arr count]);
	for (UITouch *touch in arr) {
		rb_ary_push(rb_arr, rb_hash_with_touch(touch));
	}
	return rb_arr;
}

/*
 * like rb_funcall, but check if the receiver responds to the method
 */
VALUE sc_funcall(VALUE *args) {
	if (rb_respond_to(args[0], (ID)args[1]))
		return rb_funcall2(args[0], (ID)args[1], (long)args[2], (args+3));
	return Qnil;
}

#define va_init_list(a,b) va_start(a,b)
VALUE sc_protect_funcall(VALUE recv, ID mid, int n, ...) {
    VALUE *argv;
    va_list ar;
    va_init_list(ar, n);
	
    if (n > 0) {
		long i;
		argv = ALLOCA_N(VALUE, n+3);
		argv[0] = recv;
		argv[1] = (VALUE)mid;
		argv[2] = (VALUE)n;
		for (i = 0; i < n; i++) {
			argv[i+3] = va_arg(ar, VALUE);
		}
		va_end(ar);
    }
    else {
		argv = ALLOCA_N(VALUE, 4);
		argv[0] = recv;
		argv[1] = (VALUE)mid;
		argv[2] = (VALUE)n;
		argv[3] = 0;
    }
	int state;
	VALUE result = rb_protect(RUBY_METHOD_FUNC(sc_funcall), (VALUE)argv, &state);
	if (state != 0) {
		sc_error(state);
		return Qnil;
	}
	return result;
}

void sc_error(int state) {
	VALUE err    = rb_funcall(rb_gv_get("$!"), id_sc_message, 0, 0);
	VALUE err_bt = rb_gv_get("$@");
	VALUE err_bt_str = rb_funcall(err_bt, id_sc_join, 1, rb_str_new2("\n"));
	NSLog(@"RubyError: %s\n%s",
		  StringValueCStr(err),
		  StringValueCStr(err_bt_str));
}


/*
 * use this with caution, this is really slow!
 */
VALUE sc_ns_log(int argc, VALUE *argv, VALUE module) {
	/* create the template string */
	VALUE template_ary = rb_ary_new();
	int i;
	for (i=0; i < argc; i++) {
		if (TYPE(argv[i]) == T_STRING)
			sc_protect_funcall(template_ary, id_sc_push, 1, argv[i]);
		else
			sc_protect_funcall(template_ary, id_sc_push, 1, INSPECT(argv[i]));
	}
	VALUE template_final = sc_protect_funcall(template_ary, id_sc_join, 1, rb_str_new2(" "));	
	
	NSLog([NSString stringWithCString:StringValueCStr(template_final) encoding:NSUTF8StringEncoding]);
	return Qnil;
}

/*
 * call-seq:
 *   Cocos2D.display_alert(title, msg, delegate, cancel_title, *buttons_title)   #=> nil
 *
 * Delegate can be nil.
 */
VALUE sc_display_alert(int argc, VALUE *argv, VALUE module) {
	if (argc < 4) {
		rb_raise(rb_eArgError, "Invalid number of arguments");
	}
	Check_Type(argv[0], T_STRING);
	Check_Type(argv[1], T_STRING);
	// TODO
	// Check that argv[2] is a CocosNode or nil
	Check_Type(argv[3], T_STRING);
	UIAlertView *alert = [[UIAlertView alloc] initWithTitle:[NSString stringWithCString:StringValueCStr(argv[0]) encoding:NSUTF8StringEncoding]
													message:[NSString stringWithCString:StringValueCStr(argv[1]) encoding:NSUTF8StringEncoding]
												   delegate:((argv[2] == Qnil) ? nil : CC_NODE(argv[2]))
										  cancelButtonTitle:[NSString stringWithCString:StringValueCStr(argv[3]) encoding:NSUTF8StringEncoding]
										  otherButtonTitles:nil];
	if (argc > 4) {
		int i;
		for (i=4; i < argc; i++) {
			[alert addButtonWithTitle:[NSString stringWithCString:StringValueCStr(argv[i]) encoding:NSUTF8StringEncoding]];
		}
	}
	[alert show];
	[alert release];
	return Qnil;
}


/*
 * ShinyCocos
 * 
 * ## Notes
 * 
 * The "vendor" directory is where you put your ruby code. Make sure
 * that when adding the directory to your project, the option "Create
 * Folder References for any added folder" is set. That way, the
 * directory structure will be created in the app package.
 */
void Init_ShinyCocos() {
	rb_mCocos2D = rb_define_module("Cocos2D");
	
	/* init mini object table */
	sc_object_hash = [[NSMutableDictionary alloc] init];
	sc_handler_hash = [[NSMutableDictionary alloc] init];
	sc_schedule_methods = [[NSMutableDictionary alloc] init];
	
	/* init the integration classes */
	init_sc_ids();
	init_rb_mDirector();
	init_rb_cCocosNode();
	init_rb_cScene();
	init_rb_cTextureNode();
	init_rb_cSprite();
	init_rb_cAtlasSpriteManager();
	init_rb_cAtlasSprite();
	init_rb_cAtlasAnimation();
	init_rb_cTiledMap();
	init_rb_cLayer();
	init_rb_cLabel();
	init_rb_cLabelAtlas();
	init_rb_cMenu();
	init_rb_cMenuItemImage();
	init_rb_cMenuItemAtlasSprite();
	init_rb_cSolidShapeMap();
	init_rb_cTransitionScene();
	init_rb_mAction();
	init_rb_mTwitter();
	init_rb_mUserDefaults();
	init_rb_cTextField();
	init_rb_cSlider();
	init_rb_cAVAudioPlayer();
	init_rb_cBitmapFontAtlas();
	init_sc_cocoa_additions();
	
	/* common utility functions */
	rb_define_module_function(rb_mCocos2D, "ns_log", sc_ns_log, -1);
	rb_define_module_function(rb_mCocos2D, "display_alert", sc_display_alert, -1);
}

void Init_SC_Ruby_Extensions() {
	Init_encdb();
	Init_stringio();
	Init_syck();
	Init_zlib();
	// add your extensions init here!
}
