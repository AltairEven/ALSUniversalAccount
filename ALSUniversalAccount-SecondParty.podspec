#
# Be sure to run `pod lib lint ALSUniversalAccount.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ALSUniversalAccount-SecondParty'
  s.version          = '0.0.0.8-SND'
  s.summary          = 'A short description of ALSUniversalAccount.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/AltairEven/ALSUniversalAccount'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'AltairEven' => 'qianye.qy@alibaba-inc.com' }
  s.source           = { :git => 'https://github.com/AltairEven/ALSUniversalAccount.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

    s.pod_target_xcconfig = {
    'FRAMEWORK_SEARCH_PATHS' => '$(inherited) $(PODS_ROOT)/**',
    'OTHER_LDFLAGS'          => '$(inherited) -undefined dynamic_lookup',
    'ENABLE_BITCODE'         => 'NO',
    'MACH_O_TYPE'            => 'staticlib'
    }
    
  s.subspec 'Public' do |pub|
    pub.vendored_frameworks = 'ALSUniversalAccount/Classes/Public/*.framework'
  end
  s.subspec 'Interface' do |int|
    int.dependency 'ALSUniversalAccount-SecondParty/Public'
    int.vendored_frameworks = 'ALSUniversalAccount/Classes/Interface/SecondParty/*.framework'
    int.resource_bundles = {
     	'ALSUniversalAccount' => ['ALSUniversalAccount/Assets/**/*.png']
    }

    # #第三方
    int.dependency 'TTTAttributedLabel', '~> 2.0.0'
    int.dependency 'SFHFKeychainUtils', '~> 0.0.1'
    int.dependency 'MBProgressHUD', '~> 0.9.0'

    
    int.dependency 'ALBBOpenAccountSDK',    '2.4.0.19'
    int.dependency 'ALBBOpenAccountUI',     '2.4.0.19'
    int.dependency 'ALBBOpenAccountSSO',    '2.4.0.19'
    int.dependency 'MtopSDK',              '1.8.0.2'
    int.dependency 'mtopext',              '1.7.0.7'
    int.dependency 'UserTrack',            '6.3.0.1'
    int.dependency 'SecurityGuardSDK',     '6.3.38'
    int.dependency 'SGMain',               '6.3.38'
    int.dependency 'SGSecurityBody',       '6.3.26'
    int.dependency 'SGNoCaptcha',          '6.3.20'
    int.dependency 'TBSecuritySDK',        '6.3.12'

    int.dependency 'AliUniversalAccount',  '3.0.5.7'
    int.dependency 'TBLoginCenter',        '1.3.9.5'
    int.dependency 'SmoothSSO'

    #int.dependency 'UMengUShare/Social/Sina'
    # 集成微信
    #int.dependency 'UMengUShare/Social/WeChat'
    # 集成qq
    #int.dependency 'UMengUShare/Social/QQ'
  end



#    s.subspec 'BaiChuan' do |bc|
#        bc.vendored_frameworks = 'ALSUniversalAccount/Classes/Plug/BaiChuan/SecondParty/**/*.framework'
#        bc.frameworks = 'CoreMotion', 'AssetsLibrary', 'AVFoundation', 'WebKit', 'Contacts', 'ContactsUI', 'CoreLocation', 'AddressBook', 'AddressBookUI', 'CoreBluetooth', 'MobileCoreServices', 'AudioToolbox', 'UserNotifications', 'MessageUI'
#        bc.ios.libraries = 'sqlite3.0', 'z.1.2.8', 'stdc++', 'resolv'
#    end
#s.subspec 'Plug' do |pl|
#   pl.dependency 'ALSUniversalAccount-SecondParty/Public'
# end

    
end
