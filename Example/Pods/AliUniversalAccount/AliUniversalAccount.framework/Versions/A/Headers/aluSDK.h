//
//  aluSDK.h
//  UniversalAccount
//
//  Created by shaobin on 3/21/14.
//  Modified by madding.lip on 10/01/16.
//  Copyright (c) 2014 alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "aluUIAppearanceDelegate.h"
#import "aluAppInfo.h"
#import "aluUILoginMoreCustomDelegate.h"
#import "aluAlipayAsoHandler.h"
#import "aluApplyAsoTokenHandler.h"
#import "aluWebViewDelegate.h"

/**
 登录通知userInfo内的附加信息key值
 */
#define kLoginNotification_viewWillDisappear    @"isViewWillDisappear"
#define kLoginNotification_viewDidDisappear     @"isViewDidDisappear"
#define kLoginNotification_isSuc                @"isSuc"
#define kLoginNotification_cancelledByUser      @"isCancelledByUser"
#define kLoginNotification_resultData           @"resultData"
#define kLoginNotification_context              @"context"
#define kLoginNotification_cancelledByUserSystem @"isCancelledBySystem"

/**
 注册通知userInfo内的附加信息key值
 */
#define kRegisterNotification_isSuc             @"isSuc"
#define kRegisterNotification_resultData        @"resultData"
#define kRegisterNotification_context           @"context"

#define KLoginFromWhere                         @"fromWhere"//埋点的来源是登录还是注册 login，register


#define kLoginViewSizeWillChangeNotification    @"tb_loginViewSizeWillChange"
#define kLoginViewSizeDidChangeNotification     @"tb_loginViewSizeDidChange"

#pragma mark - 多语言
#define Chinese @"zh-Hans"
#define English @"en"

// result为登录服务返回的透传数据，各app自己解析
typedef void(^loginCallback)(id result, NSError *err, NSDictionary *reserved);
typedef void(^registerCallback)(id result, NSError *err, NSDictionary *reserved);
typedef void(^userChangedCallback)(id result, NSError *err, NSDictionary *reserved);
//typedef void(^retrievePwdCallback)(BOOL isSuc, NSError *err, NSDictionary *reserved);
//typedef void(^modifyPwdCallback)(BOOL isSuc, NSError *err, NSDictionary *reserved);
//typedef void(^bindPhoneCallback)(BOOL isSuc, NSError *err, NSDictionary *reserved);
//typedef void(^changePhoneCallback)(BOOL isSuc, NSError *err, NSDictionary *reserved);
//typedef void(^bindAlipayCallback)(BOOL isSuc, NSError *err, NSDictionary *reserved);
//typedef void(^bindTaobaoCallback)(BOOL isSuc, NSError *err, NSDictionary *reserved);

typedef void(^MBModelCallback)(BOOL isSuc, NSError *err, NSDictionary *reserved);

typedef void(^MBWebViewHandler)(NSString *urlString, NSDictionary *data);

//typedef void(^windVaneCallBack)(BOOL isCloseWebView, NSString* url);

typedef enum {
    kGateWayType_unspecified,
    kGateWayType_taobao,
    kGateWayType_alipay
}eGatewayType;

typedef NS_ENUM(NSInteger, GWServerSettings) {
    GWServerTaobaoOnline,                  // sdk 淘宝网关线上地址
    GWServerTaobaoPreOnline,            // sdk 淘宝网关预发地址
    GWServerTaobaoTest,           // sdk 淘宝网关测试环境地址:t2599
    GWServerTaobaoDev,             // sdk 淘宝网关开发环境地址:d1584
    GWServerAlipayOnline,                  // sdk 支付宝网关线上地址
    GWServerAlipayPreOnline,            // sdk 支付宝网关预发地址
    GWServerAlipayTest,           // sdk 支付宝网关测试环境地址
    GWServerAlipayDev,             // sdk 支付宝网关开发环境地址
    GWServerMdapOnline,          //埋点的线上地址
    GWServerMdapDev,              //埋点的开发地址
    GWServerAlipaySit             //sdk支付宝侧sit环境:aliusergw-1-64.test.alipay.net
};


@class aluSDK;

@interface aluSDK : NSObject

+ (aluSDK *)sharedInstance;

#pragma mark - 界面自定义
//须在初始化之前调用
- (void)setUIAppearanceDelegate:(id<aluUIAppearanceDelegate>)appearanceDelegate;
-(void)passwordLoginAsync:(UIViewController *)presentingController;
#pragma mark - 设置数据
//须在初始化之前调用
- (void)setTtid:(NSString *)ttid;
//设置快捷tid
- (void)setSafePayTid:(NSString *)tid;
//设置deviceId
- (void)setDeviceId:(NSString *)deviceId;
//设置deviceName
- (void)setDeviceName:(NSString *)deviceName;
//须在初始化之前调用
- (void)setAppId:(NSString *)appId;
//须在初始化之前调用
- (void)setAppKey:(NSString *)appKey;
//须在初始化之前调用
- (void)setAuthCode:(NSString *)authCode;
//须在初始化之前调用
- (void)setAppInfo:(aluAppInfo *)appInfo;
//须在初始化之前调用
- (void)setSite:(NSString*)site;
//须在初始化之前调用
- (void)setSSOTargetURL:(NSString *)targetURL;

- (void)setDebugLog:(BOOL )openDebugLog;
- (aluAppInfo *)getAppInfo;

#pragma mark - 配置项设置
//须在初始化之前调用! 管理地理位置定位
- (void)closeLocationManagerInSDK;

-(void)setNeedInitWindVane:(BOOL)needInitWindVane;
//须在初始化之前调用
- (void)setIsNeedMultilanguage:(BOOL)isNeedMultilanguage;
//多语言切换,须在初始化之前调用
- (void)setMultilanguage:(NSString *)multilanguage;

//设置环境
- (void)applyCustomGateway:(GWServerSettings)alipayGateway
             taobaoGateway:(GWServerSettings)taobaoGateway;

///**
// *  已经废弃, 空实现
// */
//- (void)setDefaultGatewayType:(eGatewayType)defaultGatewayType __attribute__((deprecated));
//
///**
// *  已经废弃, 空实现
// */
//- (void)applyCustomMonitorPointUploadUrl:(GWServerSettings )uploadUrl __attribute__((deprecated));
//线上->0；预发->1；日常->2，仅影响UMID token生成，须在初始化之前调用
//- (void)setUMIDEnviroment:(NSInteger)env;

-(void)setIsTaobaoGateWayNeedUnited:(BOOL)isTaobaoGateWayUnited;

//设置是否关闭“注册”入口
- (void)setIsRegistryEntryClosed:(BOOL)isRegistryEntryClosed;

//设置是否关闭“忘记密码”入口
- (void)setIsRetrivePasswordClosed:(BOOL)isRetrivePasswordClosed;

//设置是否关闭"支付宝账号登录"入口
- (void)setIsAlipayLoginEntryClosed:(BOOL)isAlipayLoginEntryClosed;

//设置是否关闭"SSOToast"
- (void)setIsShowSSOToastClosed:(BOOL)isShowSSOToastClosed;

//设置是否关闭"帮助页面"入口
- (void)setIsHelpPageOpen:(BOOL)isHelpPageOpen;

//设置是否关闭"登录界面"的滑动
- (void)setDisabledLoginPageScroll:(BOOL)isDisabled;

//设置是否打开跳转到登录界面的动画
- (void)closeLoginAnimation:(BOOL)closeLoginAnimation;

#pragma mark -业务方法
//初始化
- (void)initializeAsync:(NSTimeInterval)timeOut callback:(void(^)(BOOL isSuc, NSError *err))callback;
- (void)deinitialize;

/**
 * 登录，调用者传入presentingController，登录界面以present形式出现
 *
 * context, 登录成功，发送登录通知时NSNotification中的userInfo对象会包含此对象
 */
- (void)loginAsync:(UIViewController *)presentingController
           context:(id)context
          callback:(loginCallback)callback;

- (void)passwordLoginAsync:(UIViewController *)presentingController
                 extraInfo:(NSDictionary *)extraInfo
                 loginType:(eGatewayType)loginType
                   context:(id)context
                  callback:(loginCallback)callback;

- (void)alipayLoginAsync:(UIViewController *)presentingController
                 context:(id)context
                callback:(loginCallback)callback;

/**
 *  打开登录页面后，自动进入注册页面
 */
- (void)navigateToRestigerPage:(UIViewController *)presentingController;

/**
 *  创建一个申请ASO token的处理器
 *
 *  @return
 */
- (aluApplyAsoTokenHandler*)createApplyAsoTokenHandler;

/**
 * 创建一个handler用于免等. 根据支付宝办法的aso token建立淘宝登录态.
 * 注意:
 *      (1)该handler不能重复使用, 每次均需要重新创建.
 *      (2)在使用期间, 应该保存该对象的引用, 否则被系统释放调
 */
-(aluAlipayAsoHandler*)createAlipayAsoHandler;

/**
 * sso登录
 *
 * 登录不成功时，callback err参数包含错误信息，请使用[err localizedDescription]获取错误信息，
 * 如果callback为nil，则登录结果以通知形式发出
 */
- (void)ssoLoginAsync:(NSString *)ssoToken
             callback:(loginCallback)callback;

/**
 * 登出，真正的登出操作由各个app自己维护，app在做完自己的登出逻辑后，必须调用此接口，通知sdk
 */
- (void)logOut;

/**
 * 注册登录通知，参数格式参见[NSNotificationCenter addObserver], 通知对象NSNotification的
 * userInfo对象为一个NSDictionary对象，{@"isSuc":NSNumber,"context":调用loginAsync时传入的context}
 */
- (void)addLoginObserver:(id)observer selector:(SEL)aSelector;
- (void)removeLoginObserver:(id)observer;

- (void)addRegisterObserver:(id)observer selector:(SEL)aSelector;
- (void)removeRegisterObserver:(id)observer;

/**
 * 找回登录密码
 *
 * 如果push为真,parentController参数需要传为parentController的navigationController，则使用push方式，否则使用present方式
 */
- (void)retrievePasswordAsync:(UIViewController *)parentController callback:(MBModelCallback)callback;

/**
 * 修改登录密码
 *
 * 如果push为真,parentController参数需要传为parentController的navigationController，则使用push方式，否则使用present方式
 */
- (void)modifyPasswordAsync:(UIViewController *)parentController callback:(MBModelCallback)callback;
/**
 * 绑定手机
 *
 * 如果push为真,parentController参数需要传为parentController的navigationController，则使用push方式，否则使用present方式
 */
- (void)bindPhoneNumAsync:(UIViewController *)parentController callback:(MBModelCallback)callback;
/**
 * 换绑手机
 *
 * 如果push为真,parentController参数需要传为parentController的navigationController，则使用push方式，否则使用present方式
 */
- (void)changePhoneNumAsync:(UIViewController *)parentController callback:(MBModelCallback)callback;

/**
 * 绑定支付宝账户
 *
 * 如果parentController嵌在navigationController，则使用push方式，否则使用present方式
 */
- (void)bindAlipayAsync:(UIViewController *)parentController
               bizScene:(NSString*)bizScene
               signData:(NSString *)signData
               callback:(MBModelCallback)callback;

//账户管理
//- (NSArray *)getAllAccounts;
//- (void)removeAccount:(aluUserInfo *)account;

//设备ID
- (NSString *)getAPDIDSync;
- (NSString *)getUMIDSync; //返回为UMID token
- (NSString *)getUTDIDSync;
- (NSString *)getDeviceId;
- (NSString *)getDeviceName;
- (void)getAPDIDAsync:(NSTimeInterval)timeout callback:(void(^)(NSString * apdid))callback;
- (void)getUMIDAsync:(NSTimeInterval)timeout callback:(void(^)(NSString * umidtoken))callback;
- (void)getUTDIDAsync:(NSTimeInterval)timeout callback:(void(^)(NSString * utdid))callback;

//session管理
- (void)updateSession:(NSString *)newSession;
- (NSString *)getSession;

- (NSString *)getVersionNum;

- (NSString *)getSDKName;

- (void)postLoginNotification:(NSDictionary *)userInfo;

//登录页面Referer存储
- (void)addTBLoginViewReferer:(NSDictionary *)referer;
- (void)clearTBLoginViewReferers;
- (NSArray *)taobaoLoginViewReferers;
- (NSString *)taobaoLoginViewReferersJSONString;
#pragma mark - 界面定制
+ (BOOL)isCurrentDeviceSupportRegister;
+ (BOOL)isCurrentDeviceSupportForgetPassword;
- (void)doForgetPassword;

- (void)doCloseLoginPage;

- (void)setLoginMoreCustomDelegate:(id<aluUILoginMoreCustomDelegate>)delegate;

#pragma mark - 手淘专用
//打开sso确认界面
-(void)showSsoPage:(NSString*)appKey
                 t:(NSString*)t
             euuid:(NSString*)euuid
        ssoVersion:(NSString*)ssoVersion
              sign:(NSString*)sign
         targetURL:(NSString*)targetURL
               ext:(NSDictionary*)ext
            userId:(NSString*)userID
        taobaoNick:(NSString*)taobaoNick
       headPicLink:(NSString*)headPicLink
     slaveBundleId:(NSString*)slaveBundleId;

//注意：只能测试环境使用,to你给过nick密码一键登录
- (void)passwordMockEasyLoginAsync:(NSString *)username userPwd:(NSString *)password;

- (void)showH5Page:(UIViewController *)parentController
               url:(NSString *)url
          delegate:(id<aluWebViewDelegate>)delegate;

//注册接口
- (void)doRegister;

- (void)loginBoxUserChanged:(userChangedCallback)callback;

//横屏状态下也会默认垂直,设置之后跟随topview
- (void)disableRotate2Portrait;

@end
