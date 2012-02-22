#  main.rb
#  TestShinyCocos
#
#  Created by Rolando Abarca on 4/7/09.
#  Copyright (c) 2009 Games For Food SpA. All rights reserved.

%w(test_scene test_coordinates).each { |f|
  require f
}

Cocos2D::Director.set_orientation Cocos2D::Director::ORIENTATION_LANDSCAPE_LEFT
Cocos2D::Director.set_animation_interval 1/70.0
Cocos2D::Director.display_fps false

$scenes = [
  TestScene,
  TestCoordinates,
]
$curr_scene = 0
Cocos2D::Director.run_scene $scenes[$curr_scene].new
