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

/* setup cocos2d <-> ruby integration */
void ShinyCocosSetup(NSString *devLibs);
/* will require "main.rb" from the Resource Path */
void ShinyCocosStart(UIWindow *window, id appDelegate);
/* init chipmunk, call this before ShinyCocosStart() */
void ShinyCocosInitChipmunk();
/* clean up things */
void ShinyCocosStop();

/* cocos2d declarations, only the ones we need */
@interface Director : NSObject
+ (Director *)sharedDirector;
- (void)pause;
- (void)resume;
@end
