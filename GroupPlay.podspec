Pod::Spec.new do |spec|

  spec.name         = "GroupPlay"
  spec.version      = "1.1.0"
  spec.summary      = "A short description of GroupPlay."
  spec.description  = <<-DESC
                         "开放平台SDK最新版"
                      DESC
  spec.homepage     = "https://github.com/gongjujun/GroupPlay"
  spec.license      = "MIT"
  spec.author       = { "Hal" => "271584255@qq.com" }
  spec.platform     = :ios, "9.0"
  spec.ios.deployment_target = '9.0'
  spec.source       = { :git => "https://github.com/Halowl/GroupPlay.git", :tag => "#{spec.version}" }
  
  #spec.source_files = "GroupPlay.framework/Headers/*.{h,m,plist}"

  spec.requires_arc = true
  spec.vendored_frameworks = 'GroupPlay.framework'
  spec.framework  = "UIKit"
end
