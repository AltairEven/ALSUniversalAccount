//
//  ALSUniversalAccountService.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 27/02/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AlisportsUniversalAccountPublic/AlisportsUniversalAccountPublic.h>

typedef enum {
    ALSUAEnvironmentDaily,
    ALSUAEnvironmentPreRelease,
    ALSUAEnvironmentRelease,
    ALSUAEnvironmentSandBox
}ALSUAEnvironment;

@interface ALSUniversalAccountService : NSObject

@property (nonatomic, copy, readonly) ALSUAOperationMode *currentUAMode;  //当前正在进行的账户操作模式

@property (nonatomic, assign) ALSUAEnvironment environment; //当前运行环境，默认ALSUAEnvironmentRelease

@property (nonatomic, copy) NSString *customHost;   //自定义host，默认passport.alisports.daily.taobao.net/passport，仅日常环境有效

/**
 全局单例服务

 @return 服务实例
 */
+ (instancetype)globalService;

/**
 异步初始化
 
 @param key 账户业务的appKey
 @param secret 账户业务的appSecret
 @param succeed 初始化成功回调
 @param failure 初始化失败回调
 */
- (void)asyncInitWithAppKey:(NSString *)key appSecret:(NSString *)secret succeed:(void(^)(void))succeed failure:(void(^)(NSError *))failure;

/**
 将指定的账户模式启动

 @param mode 账户插件模式
 @param delegate 账户代理，可以是<ALSUAOAuthInitializationProtocol>、 <ALSUABindMobilePhoneProtocol>或者<ALSUASetPasswordProtocol>等
 @return 启动是否成功
 */
- (BOOL)getUniversalAccountModeOnline:(ALSUAPlugMode *)mode delegate:(id)delegate;

/**
 将所有的账户模式启动
 
 @param delegate 账户代理，可以是<ALSUAOAuthInitializationProtocol>、 <ALSUABindMobilePhoneProtocol>或者<ALSUASetPasswordProtocol>等
 @param result 启动结果
 */
- (void)getAllUniversalAccountModeOnlineWithDelegate:(id)delegate response:(void(^)(NSDictionary<ALSUAPlugMode *, NSNumber *> *resultInfo))result;

/**
 开始账户操作
 
 @param mode 账户模式
 @param delegate 账户代理，可以是<ALSUAOAuthInitializationProtocol>、 <ALSUABindMobilePhoneProtocol>或者<ALSUASetPasswordProtocol>等
 @param response 结果回调
 @return 是否已经开始账户操作
 */
- (BOOL)startAccountOperationWithMode:(ALSUAOperationMode *)mode delegate:(id)delegate response:(void(^)(ALSUAResponse *resp))response;

/**
 停止当前正在进行的账户操作

 @return 是否停止成功
 */
- (BOOL)stopOperation;

/**
 是否已登录

 @return 是否已登录
 */
- (BOOL)hasLogin;

/**
 登出

 @return 是否发起了登出
 */
- (BOOL)logout;

/**
 处理跳转返回的事件信息

 @param app UIApplication对象，可直接透传系统的值
 @param url 入参URL
 @param options 相关参数
 @return 处理成功或失败
 */
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;


@end
