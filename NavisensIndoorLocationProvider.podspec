Pod::Spec.new do |s|
  s.name         = "NavisensIndoorLocationProvider"
  s.version      = "1.0.1"
  s.license      = { :type => 'MIT' }
  s.summary      = "Allows to set an IndoorLocation with Navisens"
  s.homepage     = "https://github.com/IndoorLocation/navisens-indoor-location-provider-ios.git"
  s.author       = { "Indoor Location" => "indoorlocation@mapwize.io" }
  s.platform     = :ios
  s.ios.deployment_target = '6.0'
  s.source       = { :git => "https://github.com/IndoorLocation/navisens-indoor-location-provider-ios.git", :tag => "#{s.version}" }
  s.source_files  = "navisens-indoor-location-provider-ios/Provider/*.{h,m}"
  s.dependency "IndoorLocation", "1.0.4"
end
