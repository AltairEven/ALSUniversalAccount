//
//  ALBBOpenAccountSDK.h
//  ALBBOpenAccountSDK
//
//  Created by yixiao on 16/10/13.
//  Copyright (c) 2016年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ALBBOpenAccountSDK/ALBBOpenAccountService.h>
#import <ALBBOpenAccountSDK/ALBBOpenAccountSession.h>
#import <ALBBOpenAccountSDK/ALBBOpenAccountUser.h>
#import <ALBBOpenAccountSDK/ALBBOpenAccountDefine.h>

#if __has_include(<ALBBOpenAccountUI/ALBBOpenAccountUISDK.h>)
#import <ALBBOpenAccountUI/ALBBOpenAccountUISDK.h>
#endif

#if __has_include(<ALBBOpenAccountSSO/ALBBOpenAccountSSOSDK.h>)
#import <ALBBOpenAccountSSO/ALBBOpenAccountSSOSDK.h>
#endif

#if __has_include(<ALBBOpenAccountMTOP/ALBBOpenAccountMtopSessionManager.h>)
#import <ALBBOpenAccountMTOP/ALBBOpenAccountMtopSessionManager.h>
#endif

#define ALBBOpenAccountSDKVersion @"2.5.0.2"

#ifndef ALBBService
#define ALBBService(__protocol__) \
((id<__protocol__>)([[ALBBOpenAccountSDK sharedInstance] getService:@protocol(__protocol__)]))
#endif

#ifndef ALBBOpenAccountNotificationUserLoggedIn
#define ALBBOpenAccountNotificationUserLoggedIn                  @"ALBBOA_NOTIFICATION_USER_LOGGED_IN"
#endif

#ifndef ALBBOpenAccountNotificationUserLoggedOut
#define ALBBOpenAccountNotificationUserLoggedOut                 @"ALBBOA_NOTIFICATION_USER_LOGGED_OUT"
#endif

typedef NS_ENUM(NSUInteger, TaeSDKEnvironment) {
    /** 测试环境 */
    TaeSDKEnvironmentDaily,
    /** 预发环境 */
    TaeSDKEnvironmentPreRelease,
    /** 线上环境 */
    TaeSDKEnvironmentRelease,
    /** 沙箱环境 */
    TaeSDKEnvironmentSandBox
};


#pragma mark - SDK

@interface ALBBOpenAccountSDK : NSObject

+ (instancetype)sharedInstance;

/**
 ALBBOpenAccountSDK初始化，异步执行
 @param sucessCallback 初始化成功回调
 @param failedCallback 初始化失败回调
 */
- (void)asyncInit:(void (^)())sucessCallback
          failure:(void (^)(NSError *error))failedCallback;

/**
 获取ALBBOpenAccountSDK的service 实例
 @param protocol service的协议
 @return service实例
 */
- (id)getService:(Protocol *)protocol;

@end


#pragma mark - option
@interface ALBBOpenAccountSDK (Options)
/**
 设置国际化文件
 @param bundle 国际化文件所在bundle
 @param table 国际化文件strings文件名
 */
- (void)setLocaleStringBundle:(NSBundle *)bundle table:(NSString *)table;

/**
 打开SDK Debug日志
 */
- (void)setDebugLogOpen:(BOOL)isDebugLogOpen;

/**
 指定当前APP的版本，以便关联相关日志和crash分析信息, 如果不设置默认会取plist里的Bundle version
 @param version 版本号
 */
- (void)setAppVersion:(NSString *)version;

/**
 设置SDK发布渠道,包含渠道类型和渠道名
 */
- (void)setChannel:(NSString *)type name:(NSString *)name;

/**
 指定身份图片yw_1222.jpg的后缀,例如yw_1222_test.jpg的后缀为test
 @param postFix 后缀
 */
- (void)setSecGuardImagePostfix:(NSString *)postFix;

/**
 设置语言环境，不设置默认读取系统语言首选项
 @param locale @"en"/@"zh-Hans"/@"zh-Hant"
 */
- (void)setLocale:(NSString *)locale;

/**
 设置SDK 环境信息，SDK内部测试使用
 @param environmentType 见TaeSDKEnvironment
 */
- (void)setTaeSDKEnvironment:(TaeSDKEnvironment)environmentType;

- (TaeSDKEnvironment)getTaeSDKCurrentEnvironment;

#pragma mark - init
- (void)disableInitMemberSDK:(BOOL)disableInitMemberSDK;
- (void)disableInitUT:(BOOL)disableInitUT;
- (void)disableInitMtop:(BOOL)disableInitMtop;
- (void)disableInitSecurityGuard:(BOOL)disableInitSecurityGuard;

/** 重置数据 ，SDK内部测试使用*/
+ (void)reset;
@end




