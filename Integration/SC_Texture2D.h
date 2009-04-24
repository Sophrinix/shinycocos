/*
    ShinyCocos - ruby bindings for the cocos2d-iphone game framework
    Copyright (C) 2009, Rolando Abarca M.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

extern VALUE rb_cTexture2D;

VALUE rb_cTexture2D_s_save_tex_parameters(VALUE klass);
VALUE rb_cTexture2D_s_set_alias_tex_parameters(VALUE klass);
VALUE rb_cTexture2D_s_restore_tex_parameters(VALUE klass);
VALUE rb_cTexture2D_s_aliased(VALUE klass);

void init_rb_cTexture2D();
