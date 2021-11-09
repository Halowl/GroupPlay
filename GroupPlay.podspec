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
  
  s.platform = :ios, "9.0"
  s.ios.deployment_target = "9.0"
  s.vendored_frameworks = "GroupPlay/**/*.{framework}"
end


