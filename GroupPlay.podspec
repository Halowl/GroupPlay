Pod::Spec.new do |spec|

  spec.name         = "GroupPlay"
  spec.version      = "1.1.0"
  spec.summary      = "A short description of GroupPlay."
  spec.description  = <<-DESC
                         It is a marquee view used on iOS, which implement by Objective-C.
                      DESC
  spec.homepage     = "https://github.com/gongjujun/GroupPlay"
  spec.license      = "MIT"
  spec.author       = { "Hal" => "271584255@qq.com" }
  spec.platform     = :ios, "9.0"
  spec.source       = { :git => "https://github.com/Halowl/GroupPlay.git", :tag => "#{spec.version}" }
  spec.source_files = "GroupPlay.framework/Headers/*.{h,m,plist}"
  spec.module_name = "GroupPlay"

end
