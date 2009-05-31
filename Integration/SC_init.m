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
	[GET_OBJC(ptr) release];
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

/*
 * use this with caution, this is really slow!
 */
VALUE sc_ns_log(int argc, VALUE *argv, VALUE module) {
	/* create the template string */
	VALUE template_ary = rb_ary_new();
	int i;
	for (i=0; i < argc; i++) {
		if (TYPE(argv[i]) == T_STRING)
			rb_funcall(template_ary, id_sc_push, 1, argv[i]);
		else
			rb_funcall(template_ary, id_sc_push, 1, INSPECT(argv[i]));
	}
	VALUE template_final = rb_funcall(template_ary, id_sc_join, 1, rb_str_new2(" "));	
	
	NSLog([NSString stringWithCString:StringValueCStr(template_final) encoding:NSUTF8StringEncoding]);
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
	init_rb_cTexture2D();
	init_rb_cDirector();
	init_rb_cCocosNode();
	init_rb_cScene();
	init_rb_cTextureNode();
	init_rb_cSprite();
	init_rb_cAtlasSpriteManager();
	init_rb_cAtlasSprite();
	init_rb_cAtlasAnimation();
	init_rb_cTiledMap();
	init_rb_cLayer();
	init_rb_cMenu();
	init_rb_cMenuItemImage();
	init_rb_cSolidShapeMap();
	init_rb_cMenuItemAtlasSprite();
	init_rb_mTwitter();
	init_sc_cocoa_additions();
	
	/* common utility functions */
	rb_define_module_function(rb_mCocos2D, "ns_log", sc_ns_log, -1);
}

void Init_SC_Ruby_Extensions() {
	Init_encdb();
	Init_stringio();
	Init_syck();
	Init_zlib();
	// add your extensions init here!
}
