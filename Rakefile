require 'rake/rdoctask'

PROJECT    = "ShinyCocos.xcodeproj"
TARGET     = "ShinyCocos"
SDK_DEVICE = "iphoneos2.2.1"
SDK_SIMUL  = "iphonesimulator2.2.1"
XCODEBUILD = "/usr/bin/xcodebuild"
LIPO       = "/usr/bin/lipo"

def xcodebuild_str(config = "Debug")
  sdk = ENV['DEVICE'] ? SDK_DEVICE : SDK_SIMUL
  "#{XCODEBUILD} -project #{PROJECT} -target #{TARGET} -sdk #{sdk} -configuration #{config}" 
end

task :default => [:build]

desc "Build ShinyCocos"
task :build do
  sh "#{xcodebuild_str} build"
end

desc "Clean ShinyCocos"
task :clean do
  sh "#{xcodebuild_str} clean"
end

desc "Create release library"
task :distribution do
  libs = ["build/Release-iphoneos/libShinyCocos.a", "build/Release-iphonesimulator/libShinyCocos.a",
          "build/Debug-iphoneos/libShinyCocos.a", "build/Debug-iphonesimulator/libShinyCocos.a"]
  if File.exists?(libs[0]) && File.exists?(libs[1]) && File.exists?(libs[2]) && File.exists?(libs[3])
    fname_release = Date.today.strftime("libShinyCocos-%Y%m%d.a")
    fname_debug = Date.today.strftime("libShinyCocosd-%Y%m%d.a")
    sh "#{LIPO} -create #{libs[0]} #{libs[1]} -output build/#{fname_release}"
    sh "#{LIPO} -create #{libs[2]} #{libs[3]} -output build/#{fname_debug}"
    # copy libraries to template
    sh "rm -f Template/ShinyCocos/lib/*.a"
    sh "cp build/#{fname_release} Template/ShinyCocos/lib/"
    sh "cp build/#{fname_debug} Template/ShinyCocos/lib/"
    # make alias
    sh "cd Template/ShinyCocos/lib && ln -s #{fname_release} libShinyCocos.a"
    sh "cd Template/ShinyCocos/lib && ln -s #{fname_debug} libShinyCocosd.a"
  else
    $stderr.puts "You should build the release and debug targets first!"
  end
end

desc "Install Xcode Template"
task :install_template => [:distribution] do
  sh "sudo rm -rf '/Developer/Platforms/iPhoneOS.platform/Developer/Library/Xcode/Project Templates/Application/ShinyCocos Application'"
  sh "sudo cp -r Template '/Developer/Platforms/iPhoneOS.platform/Developer/Library/Xcode/Project Templates/Application/ShinyCocos Application'"
end

Rake::RDocTask.new do |rdoc|
  rdoc.rdoc_files = %w(
Integration/SC_init.m
Integration/SC_AVAudioPlayer.m
Integration/SC_Action.m
Integration/SC_AtlasSprite.m
Integration/SC_AtlasSpriteManager.m
Integration/SC_BitmatFontAtlas.m
Integration/SC_CocoaAdditions.m
Integration/SC_CocosNode.m
Integration/SC_Director.m
Integration/SC_Label.m
Integration/SC_LabelAtlas.m
Integration/SC_Layer.m
Integration/SC_Menu.m
Integration/SC_Scene.m
Integration/SC_Slider.m
Integration/SC_SolidShapeMap.m
Integration/SC_Sprite.m
Integration/SC_TMXTiledMap.m
Integration/SC_TextField.m
Integration/SC_TextureNode.m
Integration/SC_Transition.m
Integration/SC_Twitter.m
Integration/SC_UserDefaults.m
Integration/SC_ids.m
Integration/ShinyCocos.m
README.rdoc
  )
  rdoc.options += [
    '-E', 'm=c',
    '--main', 'README.rdoc'
  ]
end
