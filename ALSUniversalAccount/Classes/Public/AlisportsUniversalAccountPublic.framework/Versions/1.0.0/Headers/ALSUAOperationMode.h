//
//  ALSUAOperationMode.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 13/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AlisportsUniversalAccountPublic/AlisportsUniversalAccountPublic.h>


/**
 预定义一些账户操作模式的名称，可参考使用，或者由外部使用者自定义
 */
extern NSString *const ALSUAModeAccount;
extern NSString *const ALSUAModeMobilePhone;
extern NSString *const ALSUAModeEmail;
extern NSString *const ALSUAModeBaiChuanCloud;
extern NSString *const ALSUAModeBaiChuanThirdParty;
extern NSString *const ALSUAModeTaoBao;
extern NSString *const ALSUAModeAlipay;
extern NSString *const ALSUAModeWechat;
extern NSString *const ALSUAModeQQ;
extern NSString *const ALSUAModeWeibo;

extern NSString *const ALSUAModeAuto;
extern NSString *const ALSUniversalAccount;

typedef enum {
    ALSUniveraslAccountOperationTypeNone                      = 0,                //无
    ALSUniveraslAccountOperationTypeLogin                     = 1 << 0,           //账号密码登录
    ALSUniveraslAccountOperationTypeNoPWLogin                 = 1 << 1,           //短信验证码登录
    ALSUniveraslAccountOperationTypeRegisterNLogin            = 1 << 2,           //注册并登录
    ALSUniveraslAccountOperationTypeSmoothSSO                 = 1 << 3,           //SSO登录
    ALSUniveraslAccountOperationTypeAutoLogin                 = 1 << 4,           //自动登录
    ALSUniveraslAccountOperationTypeRefreshSSOToken           = 1 << 5,           //刷新sso token
    ALSUniveraslAccountOperationTypeBindMobilePhone           = 1 << 6,           //绑定手机号
    ALSUniveraslAccountOperationTypeChangeBindMobilePhone     = 1 << 7,           //换绑手机号
    ALSUniveraslAccountOperationTypeSetPassword               = 1 << 8,           //设置登录密码
    ALSUniveraslAccountOperationTypeModifyPassword            = 1 << 9,           //修改登录密码
    ALSUniveraslAccountOperationTypeResetPassword             = 1 << 10,           //重置登录密码
    ALSUniveraslAccountOperationTypeCheckBindTaobao           = 1 << 11,          //查询是否已绑定淘宝账号
    ALSUniveraslAccountOperationTypeBindTaobao                = 1 << 12,          //绑定淘宝账号
    ALSUniveraslAccountOperationTypeTaobaoNoLogin             = 1 << 13,          //淘宝免登
    ALSUniveraslAccountOperationTypeAll                       = (1 << 14) - 1     //全部
}ALSUniveraslAccountOperationType;

typedef enum {
    ALSUABaiChuanTypeNone,
    ALSUABaiChuanTypeSecondParty,
    ALSUABaiChuanTypeThirdParty
}ALSUABaiChuanType;


typedef enum {
    ALSUAOperationModeTransitionTypePresent,
    ALSUAOperationModeTransitionTypePush
}ALSUAOperationModeTransitionType;

@interface ALSUAOperationMode : NSObject

@property (nonatomic, strong, readonly) NSString *name; //账户操作模式名称

@property (nonatomic, assign) BOOL allowCovers; //是否支持登录进程被替代，默认为YES

@property (nonatomic, readonly) ALSUniveraslAccountOperationType operationType; //账号操作类型，默认为ALSUniveraslAccountOperationTypeNone，建议根据实际账户操作插件的定义来赋值

@property (nonatomic, assign) ALSUABaiChuanType baichuanType;   //百川SDK类型，非百川不用赋值

@property (nonatomic, assign) ALSUAOperationModeTransitionType transitionType; //控制器转场类型，默认为ALSUAOperationModeTransitionTypePresent

@property (nonatomic, assign) ALSUAOAuthPlatformType oauthPlatformType; //oauth平台类型，默认为ALSUAOAuthPlatformType_None，只在ALSUniveraslAccountOperationType为ALSUniveraslAccountOperationTypeSmoothSSO时有效

/**
 便捷实例化方法

 @param name 模式名称
 @param type 操作类型
 @return 类实例
 */
+ (instancetype)modeWithName:(NSString *)name operationType:(ALSUniveraslAccountOperationType)type;

@end
