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

#import <objc/runtime.h>
#import "ruby.h"
#import "cocos2d.h"
#import "chipmunk.h"
#import "SC_ids.h"
#import <AVFoundation/AVAudioPlayer.h>
#import "SC_AVAudioPlayer.h"

typedef struct {
	id _obj;
} cocos_holder;

#define SC_GETTER_TEMPLATE(funcname, type) \
static inline type *funcname(VALUE obj) { \
	cocos_holder *ptr; \
	Data_Get_Struct(obj, cocos_holder, ptr);\
	return (type *)(ptr->_obj);\
}
static inline id sc_get_objc(VALUE obj) {
	cocos_holder *ptr;
	Data_Get_Struct(obj, cocos_holder, ptr);
	return (ptr->_obj);
}
SC_GETTER_TEMPLATE(CC_NODE, CocosNode)
SC_GETTER_TEMPLATE(CC_PXNODE, ParallaxNode)
SC_GETTER_TEMPLATE(CC_LAYER, Layer)
SC_GETTER_TEMPLATE(CC_MENU, Menu)
SC_GETTER_TEMPLATE(CC_SPRITE, Sprite)
SC_GETTER_TEMPLATE(CC_SCENE, Scene)
SC_GETTER_TEMPLATE(CC_ATLAS_ANIMATION, AtlasAnimation)
SC_GETTER_TEMPLATE(CC_ATLAS_SPRITE, AtlasSprite)
SC_GETTER_TEMPLATE(CC_ATLAS_SPRITE_MNG, AtlasSpriteManager)
SC_GETTER_TEMPLATE(CC_LABEL, Label)
SC_GETTER_TEMPLATE(CC_TRANS, TransitionScene)
SC_GETTER_TEMPLATE(UI_TFIELD, UITextField)
SC_GETTER_TEMPLATE(UI_SLIDER, UISlider)
SC_GETTER_TEMPLATE(AV_PLAYER, RBAudioPlayer)
SC_GETTER_TEMPLATE(CC_BMFONT, BitmapFontAtlas)
SC_GETTER_TEMPLATE(CC_TMXTILEDMAP, TMXTiledMap)
SC_GETTER_TEMPLATE(CC_TMXLAYER, TMXLayer)
// *Action getters
// generated by
// cat cocos2d-iphone/cocos2d/*Action.h | grep @interface | ruby -ne 'md = $_.match(/@interface +(\w+) *: *(\w+)/); puts "SC_GETTER_TEMPLATE(CC_#{md[1].upcase}, #{md[1]})" if md'
SC_GETTER_TEMPLATE(CC_ACTION, Action)
SC_GETTER_TEMPLATE(CC_FINITETIMEACTION, FiniteTimeAction)
SC_GETTER_TEMPLATE(CC_REPEATFOREVER, RepeatForever)
SC_GETTER_TEMPLATE(CC_SPEED, Speed)
SC_GETTER_TEMPLATE(CC_CAMERAACTION, CameraAction)
SC_GETTER_TEMPLATE(CC_ORBITCAMERA, OrbitCamera)
SC_GETTER_TEMPLATE(CC_EASEACTION, EaseAction)
SC_GETTER_TEMPLATE(CC_EASERATEACTION, EaseRateAction)
SC_GETTER_TEMPLATE(CC_EASEIN, EaseIn)
SC_GETTER_TEMPLATE(CC_EASEOUT, EaseOut)
SC_GETTER_TEMPLATE(CC_EASEINOUT, EaseInOut)
SC_GETTER_TEMPLATE(CC_EASEEXPONENTIALIN, EaseExponentialIn)
SC_GETTER_TEMPLATE(CC_EASEEXPONENTIALOUT, EaseExponentialOut)
SC_GETTER_TEMPLATE(CC_EASEEXPONENTIALINOUT, EaseExponentialInOut)
SC_GETTER_TEMPLATE(CC_EASESINEIN, EaseSineIn)
SC_GETTER_TEMPLATE(CC_EASESINEOUT, EaseSineOut)
SC_GETTER_TEMPLATE(CC_EASESINEINOUT, EaseSineInOut)
SC_GETTER_TEMPLATE(CC_WAVES3D, Waves3D)
SC_GETTER_TEMPLATE(CC_FLIPX3D, FlipX3D)
SC_GETTER_TEMPLATE(CC_FLIPY3D, FlipY3D)
SC_GETTER_TEMPLATE(CC_LENS3D, Lens3D)
SC_GETTER_TEMPLATE(CC_RIPPLE3D, Ripple3D)
SC_GETTER_TEMPLATE(CC_SHAKY3D, Shaky3D)
SC_GETTER_TEMPLATE(CC_LIQUID, Liquid)
SC_GETTER_TEMPLATE(CC_WAVES, Waves)
SC_GETTER_TEMPLATE(CC_TWIRL, Twirl)
SC_GETTER_TEMPLATE(CC_GRIDACTION, GridAction)
SC_GETTER_TEMPLATE(CC_GRID3DACTION, Grid3DAction)
SC_GETTER_TEMPLATE(CC_TILEDGRID3DACTION, TiledGrid3DAction)
SC_GETTER_TEMPLATE(CC_ACCELDECCELAMPLITUDE, AccelDeccelAmplitude)
SC_GETTER_TEMPLATE(CC_ACCELAMPLITUDE, AccelAmplitude)
SC_GETTER_TEMPLATE(CC_DECCELAMPLITUDE, DeccelAmplitude)
SC_GETTER_TEMPLATE(CC_STOPGRID, StopGrid)
SC_GETTER_TEMPLATE(CC_REUSEGRID, ReuseGrid)
SC_GETTER_TEMPLATE(CC_INSTANTACTION, InstantAction)
SC_GETTER_TEMPLATE(CC_SHOW, Show)
SC_GETTER_TEMPLATE(CC_HIDE, Hide)
SC_GETTER_TEMPLATE(CC_TOGGLEVISIBILITY, ToggleVisibility)
SC_GETTER_TEMPLATE(CC_PLACE, Place)
SC_GETTER_TEMPLATE(CC_CALLFUNC, CallFunc)
SC_GETTER_TEMPLATE(CC_CALLFUNCN, CallFuncN)
SC_GETTER_TEMPLATE(CC_CALLFUNCND, CallFuncND)
SC_GETTER_TEMPLATE(CC_INTERVALACTION, IntervalAction)
SC_GETTER_TEMPLATE(CC_SEQUENCE, Sequence)
SC_GETTER_TEMPLATE(CC_REPEAT, Repeat)
SC_GETTER_TEMPLATE(CC_SPAWN, Spawn)
SC_GETTER_TEMPLATE(CC_ROTATETO, RotateTo)
SC_GETTER_TEMPLATE(CC_ROTATEBY, RotateBy)
SC_GETTER_TEMPLATE(CC_MOVETO, MoveTo)
SC_GETTER_TEMPLATE(CC_MOVEBY, MoveBy)
SC_GETTER_TEMPLATE(CC_JUMPBY, JumpBy)
SC_GETTER_TEMPLATE(CC_JUMPTO, JumpTo)
SC_GETTER_TEMPLATE(CC_BEZIERBY, BezierBy)
SC_GETTER_TEMPLATE(CC_SCALETO, ScaleTo)
SC_GETTER_TEMPLATE(CC_SCALEBY, ScaleBy)
SC_GETTER_TEMPLATE(CC_BLINK, Blink)
SC_GETTER_TEMPLATE(CC_FADEIN, FadeIn)
SC_GETTER_TEMPLATE(CC_FADEOUT, FadeOut)
SC_GETTER_TEMPLATE(CC_FADETO, FadeTo)
SC_GETTER_TEMPLATE(CC_TINTTO, TintTo)
SC_GETTER_TEMPLATE(CC_TINTBY, TintBy)
SC_GETTER_TEMPLATE(CC_DELAYTIME, DelayTime)
SC_GETTER_TEMPLATE(CC_REVERSETIME, ReverseTime)
SC_GETTER_TEMPLATE(CC_ANIMATE, Animate)
SC_GETTER_TEMPLATE(CC_SHAKYTILES3D, ShakyTiles3D)
SC_GETTER_TEMPLATE(CC_SHATTEREDTILES3D, ShatteredTiles3D)
SC_GETTER_TEMPLATE(CC_SHUFFLETILES, ShuffleTiles)
SC_GETTER_TEMPLATE(CC_FADEOUTTRTILES, FadeOutTRTiles)
SC_GETTER_TEMPLATE(CC_FADEOUTBLTILES, FadeOutBLTiles)
SC_GETTER_TEMPLATE(CC_FADEOUTUPTILES, FadeOutUpTiles)
SC_GETTER_TEMPLATE(CC_FADEOUTDOWNTILES, FadeOutDownTiles)
SC_GETTER_TEMPLATE(CC_TURNOFFTILES, TurnOffTiles)
SC_GETTER_TEMPLATE(CC_WAVESTILES3D, WavesTiles3D)
SC_GETTER_TEMPLATE(CC_JUMPTILES3D, JumpTiles3D)
SC_GETTER_TEMPLATE(CC_SPLITROWS, SplitRows)
SC_GETTER_TEMPLATE(CC_SPLITCOLS, SplitCols)

#define INSPECT(obj) sc_protect_funcall(obj, id_sc_inspect, 0, 0)
#define RBCALL(obj, func) sc_protect_funcall(obj, rb_intern(func), 0, 0)

#define CHECK_ARGS_NUM(n) \
if (argc < n) { \
	rb_raise(rb_eArgError, "Invalid Number of Arguments"); \
}

#define CHECK_SUBCLASS(obj, klass) \
if (rb_obj_is_kind_of(obj, klass) == Qfalse) { \
	rb_raise(rb_eArgError, "Invalid object, expecting a %s", rb_class2name(klass)); \
}

#define CHECK_ARGS_NUM_AND_SUBCLASS(n, klass) \
CHECK_ARGS_NUM(n) \
CHECK_SUBCLASS(argv[0], klass)

extern VALUE rb_mCocos2D;
extern VALUE sc_acc_delegate;
extern NSMutableDictionary *sc_object_hash;
extern NSMutableDictionary *sc_schedule_methods;
extern NSMutableDictionary *sc_handler_hash;
extern id accDelegate;

VALUE sc_init(VALUE klass, cocos_holder **ret_ptr, id object, int argc, VALUE *argv, BOOL release_on_free);
VALUE rb_hash_with_touch(UITouch *touch);
VALUE rb_ary_with_set(NSSet *touches);
VALUE sc_protect_funcall(VALUE recv, ID mid, int n, ...);
void  sc_error(int state);
void  sc_method_swap(Class cls, SEL orig, SEL repl);

static inline CGRect sc_make_rect(VALUE rb_rect) {
	Check_Type(rb_rect, T_ARRAY);
	if (RARRAY_LEN(rb_rect) < 4) {
		rb_raise(rb_eArgError, "rect must be of at least 4 elements");
	}
	return CGRectMake(
		NUM2DBL(RARRAY_PTR(rb_rect)[0]),
		NUM2DBL(RARRAY_PTR(rb_rect)[1]),
		NUM2DBL(RARRAY_PTR(rb_rect)[2]),
		NUM2DBL(RARRAY_PTR(rb_rect)[3])
	);
}

/*
 * link an ruby object with an objective C one, throught a hash table
 */
static inline void sc_add_tracking(NSMutableDictionary *hash, id obj1, VALUE obj2) {
	[hash setObject:[NSValue valueWithPointer:(void *)obj2] forKey:[NSValue valueWithPointer:obj1]];
}


/*
 * remove tracking for a given object
 */
static inline void sc_remove_tracking_for(NSMutableDictionary *hash, id obj1) {
	[hash removeObjectForKey:[NSValue valueWithPointer:obj1]];
}

/*
 * get a ruby object associated to the ObjC-Object
 */
static inline VALUE sc_ruby_instance_for(NSMutableDictionary *hash, id obj1) {
	NSValue *v = [hash objectForKey:[NSValue valueWithPointer:obj1]];
	if (v == nil) {
		return Qnil;
	}
	VALUE rv = (VALUE)[v pointerValue];
	if (TYPE(rv) != T_NONE) {
		return rv;
	}
	// should never reach this
	NSLog(@"probably trying to call a hook on a dead ruby object: %@ (%d,%d,%d)",
		obj1,
		hash == sc_object_hash,
		hash == sc_handler_hash,
		hash == sc_schedule_methods);
	return Qnil;
}

void Init_ShinyCocos();
void Init_SC_Ruby_Extensions();
void Init_chipmunk();
