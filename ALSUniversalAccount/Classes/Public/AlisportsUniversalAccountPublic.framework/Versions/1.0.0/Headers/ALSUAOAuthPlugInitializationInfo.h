//
//  ALSUAOAuthPlugInitializationInfo.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 17/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    ALSUAOAuthPlatformTypeNone,
    ALSUAOAuthPlatformTypeTaobao,
    ALSUAOAuthPlatformTypeWechat,
    ALSUAOAuthPlatformTypeSina,
    ALSUAOAuthPlatformTypeQQ
}ALSUAOAuthPlatformType;

/**
 登录SDK初始化信息
 */
@interface ALSUAOAuthPlugInitializationInfo : NSObject <NSCopying>

@property (nonatomic, assign) ALSUAOAuthPlatformType platformType;

@property (nonatomic, copy) NSString *appKey;

@property (nonatomic, copy) NSString *appSecret;

@property (nonatomic, copy) NSString *urlScheme;

@property (nonatomic, copy) NSString *redirectUrl; //ALSUAOAuthPlatformTypeTaobao时传入taobaoSSO urlscheme，ALSUAOAuthPlatformTypeSina时传入redirectUrl，

/**
 快捷创建实例对象的方法
 
 @param type platformType
 @param key appKey
 @param secret appSecret
 @param scheme urlScheme
 @param url redirectUrl
 @return 类实例
 */
+ (instancetype)infoWithOAuthPlatform:(ALSUAOAuthPlatformType)type appKey:(NSString *)key appSecret:(NSString *)secret urlScheme:(NSString *)scheme andRedirectUrl:(NSString *)url;

@end


@protocol ALSUAOAuthInitializationProtocol <NSObject>

@required

/**
 获取初始化信息
 
 @param platformType 授权平台类型
 @return 初始化信息数组
 */
- (ALSUAOAuthPlugInitializationInfo *)oauthInitilizationInfoForPlatform:(ALSUAOAuthPlatformType)platformType;

@end
