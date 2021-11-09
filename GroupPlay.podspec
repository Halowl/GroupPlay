Pod::Spec.new do |s|
  s.name             = "GroupPlay"
  s.version          = "1.1.0"
  s.summary          = "A marquee view used on iOS."
  s.description      = <<-DESC
                       It is a marquee view used on iOS, which implement by Objective-C.
                       DESC
  s.homepage         = "https://github.com/gongjujun/GroupPlay"
  # s.screenshots      = "www.example.com/screenshots_1", "www.example.com/screenshots_2"
  s.license          = 'MIT'
  s.author           = { "hal" => "sg6548676@gmail.com" }
  s.source           = { :git => "https://github.com/gongjujun/GroupPlay.git", :tag => s.version }
  # s.social_media_url = 'https://www.doyep.cn/'

  s.platform     = :ios
  # s.ios.deployment_target = '5.0'
  # s.osx.deployment_target = '10.7'
  s.requires_arc = true

  #s.source_files = 'WZMarqueeView/*'
  # s.resources = 'Assets'

  # s.ios.exclude_files = 'Classes/osx'
  # s.osx.exclude_files = 'Classes/ios'
  # s.public_header_files = 'Classes/**/*.h'
  s.vendored_frameworks = 'Framework.framework'
  s.frameworks = 'Foundation'

end
