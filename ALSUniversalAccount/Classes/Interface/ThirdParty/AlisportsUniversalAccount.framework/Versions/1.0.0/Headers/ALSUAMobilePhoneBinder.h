//
//  ALSUAMobilePhoneBinder.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 13/03/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//


#import <Foundation/Foundation.h>

@interface ALSUAMobilePhoneBinder : NSObject

+ (instancetype)sharedBinder;

/**
 发送手机的短信验证码（绑定）
 
 @param phoneNumber 手机号
 @param result 发送结果
 @return 方法调用结果
 */
- (BOOL)sendVerificationCodeForMobilePhone:(NSString *)phoneNumber reslust:(void (^)(NSError *error, NSDictionary *userInfo))result;

/**
 绑定手机

 @param phoneNumber 手机号
 @param code 短信验证码
 @param result 绑定结果
 @return 方法调用结果
 */
- (BOOL)bindMobilePhone:(NSString *)phoneNumber withVerificationCode:(NSString *)code result:(void(^)(NSError *error, NSDictionary *userInfo))result;

/**
 验证验证码
 @param phoneNumber 手机号
 @param code 验证码
 @return 是否成功
 */
- (BOOL)validateOldMobilePhone:(NSString *)phoneNumber withVerificationCode:(NSString *)code result:(void(^)(NSError *error, NSDictionary *userInfo))result;

/**
 换绑手机号
 @param phoneNumber 手机号
 @param code 验证码
 @param tokenCode 前一步验证旧手机的手机验证码
 @return 是否成功
 */
- (BOOL)exchangeMobile:(NSString *)phoneNumber withVerificationCode:(NSString *)code  withTokenCode:(NSString *)tokenCode result:(void(^)(NSError *error, NSDictionary *userInfo))result;


@end
