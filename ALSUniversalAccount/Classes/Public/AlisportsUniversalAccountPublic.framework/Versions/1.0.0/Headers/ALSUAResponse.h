//
//  ALSUAResponse.h
//  wesg
//
//  Created by Altair on 22/02/2017.
//  Copyright © 2017 AliSports. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALSUAOperationMode.h"
#import "ALSUAPlugMode.h"

extern NSString *const kALSUABaichuanLoginStartNotification;
extern NSString *const kALSUABaichuanLoginFinishedNotification;

/**
 账户操作请求的返回
 */
@interface ALSUAResponse : NSObject

@property (nonatomic, copy) ALSUAOperationMode *originalMode;  //原始账户操作模式

@property (nonatomic, strong) NSError *error; //账户操作返回错误信息

@property (nonatomic, copy) NSDictionary *userInfo; //账户操作返回用户信息

@property (nonatomic, assign) BOOL operationFinished; //账户操作是否完成，默认创建时为YES

/**
 初始化账户操作请求返回的方法
 
 @param originalMode 原始账户操作模式
 @return 类实例
 */
- (instancetype)initWithOriginalMode:(ALSUAOperationMode *)originalMode;

@end


@interface ALSUALoginResponse : ALSUAResponse

@property (nonatomic, copy) NSString *appKey;  //接入的插件账户操作SDK的appkey

@property (nonatomic, copy) NSString *appUid;  //业务用户uid

@property (nonatomic, copy) NSString *token; //用户token，用于业务服务器校验登录态

@property (nonatomic, copy) NSString *ssoToken; //用户ssotoken，用于H5页面校验登录态

@property (nonatomic, copy) NSString *userType; //用户类型（弃用）

@property (nonatomic, copy) ALSUALoginPlugMode *plugMode;  //账户登录操作插件模式

- (instancetype)initWithOriginalMode:(ALSUAOperationMode *)originalMode plugMode:(ALSUALoginPlugMode *)plugMode;

- (NSString *)businessToken;

@end


@interface ALSUABindPhoneResponse : ALSUAResponse

@property (nonatomic, copy) NSString *phoneNumber;  //绑定的手机号

@end


@interface ALSUASetPasswordResponse : ALSUAResponse

@end


@interface ALSUABindTaobaoResponse : ALSUAResponse

@end
