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
#import "ruby.h"
#import "SC_common.h"
#import "SC_CocosNode.h"
#import "SC_TextureNode.h"

VALUE rb_cTextureNode;

/* 
 * Must complete doc
 */
VALUE rb_cTextureNode_s_new(VALUE klass) {
	TextureNode *node = [[TextureNode alloc] init];
	VALUE rb_obj = common_init(klass, nil, node, YES);
	rb_hash_aset(rb_object_hash, INT2FIX((long)node), rb_obj);

	return rb_obj;
}

void init_rb_cTextureNode() {
#if 0
	rb_mCocos2D = rb_define_module("Cocos2D");
#endif
	rb_cTextureNode = rb_define_class_under(rb_mCocos2D, "TextureNode", rb_cCocosNode);
	rb_define_singleton_method(rb_cTextureNode, "new", rb_cTextureNode_s_new, 0);
}
