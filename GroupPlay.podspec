Pod::Spec.new do |spec|
  spec.name         = "GroupPlay"
  spec.version      = "1.1.0.0"
  spec.summary      = "A good activity tool for iOS"
  spec.description  = <<-DESC
                      "开放平台SDK最新版"
                      DESC
  spec.homepage     = "https://github.com/gongjujun"
  spec.license      = { :type => "MIT", :file => "LICENSE" }
  spec.author       = { "hal" => "sg6548676@gmail.com" }
  spec.platform     = :ios, '9.0'
  spec.ios.deployment_target = '9.0'
  spec.source       = { :git => "https://github.com/gongjujun/GroupPlay.git", :tag => "#{spec.version}" }
  spec.vendored_frameworks = 'GroupPlay.framework'
  spec.framework  = "UIKit"
  # spec.static_framework = true
  spec.requires_arc = true
  # spec.pod_target_xcconfig = { 'VALID_ARCHS' => 'x86_64 armv7 armv7s arm64' }
  # spec.xcconfig = { "HEADER_SEARCH_PATHS" => "$(SDKROOT)/usr/include/libxml2" }
  # spec.dependency "JSONKit", "~> 1.4"

  spec.pod_target_xcconfig = {
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'
  }
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
end
