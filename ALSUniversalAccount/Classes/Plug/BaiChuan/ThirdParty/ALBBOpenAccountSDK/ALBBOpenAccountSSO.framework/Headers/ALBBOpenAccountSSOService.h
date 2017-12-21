//
//  ALBBOpenAccountSSOPluginServiceProtocol.h
//  ALBBOpenAccountSSOPluginAdapter
//
//  Created by yixiao on 16/10/13.
//  Copyright (c) 2016年 Alibaba. All rights reserved.
//



#import <Foundation/Foundation.h>
#import <ALBBOpenAccountSDK/ALBBOpenAccountSession.h>
#import <ALBBOpenAccountSDK/ALBBOpenAccountSDK.h>
#import <ALBBOpenAccountSSO/ALBBOpenAccountSSOLink.h>


@protocol SSODelegate <NSObject>
@optional
//三方授权登录回调
- (void)openAccountOAuthError:(NSError *)error Session:(ALBBOpenAccountSession *)session;

//绑定三方账号回调
- (void)openAccountBindError:(NSError *)error Session:(ALBBOpenAccountSession *)session ThirdInfo:(ALBBOpenAccountSSOLink *)link;
@end

typedef NS_ENUM(NSInteger, OAAuthPlatformType) {
    OAAuthPlatformType_TaoBao   = 1,
    OAAuthPlatformType_WechatSession,
    OAAuthPlatformType_Sina,
    OAAuthPlatformType_QQ
};

/** 获取实例: ALBBService(ALBBOpenAccountSSOService) */
@protocol ALBBOpenAccountSSOService <NSObject>


- (BOOL)setPlatform:(OAAuthPlatformType)platform
             appKey:(NSString *)appKey
          appSecret:(NSString *)appSecret
        redirectURL:(NSString *)redirectURL;

- (void)setTaobaoTargetUrl:(NSString *)url;

- (BOOL)handleOpenUrl:(NSURL *)url;

//第三方账号授权登录
- (void)oauthWithPlatForm:(OAAuthPlatformType)sType
             presentingVC:(UIViewController *)presentingController
                 delegate:(id<SSODelegate>)delegate;


//绑定第三方账号
- (void)oaBindWithPlatForm:(OAAuthPlatformType)sType
              presentingVC:(UIViewController *)presentingController
                  delegate:(id<SSODelegate>)delegate;

//获取三方账号绑定信息，登录态失效的error code=ALBBOpenAccountCodeSessionExpireError
- (void)getThirdBindInfoWithCallback:(void (^)(NSArray<ALBBOpenAccountSSOLink *> *accountLinks,NSError *error))callback;

//允许oa账号可以多次绑定同一平台的账号
- (void)enableMultiBind;

@end
