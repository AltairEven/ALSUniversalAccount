//
//  ALSUAPasswordSetter.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 11/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ALSUAPasswordSetter : NSObject

+ (instancetype)sharedSetter;

/**
 发送手机的短信验证码（设置密码）
 
 @param phoneNumber 手机号
 @param result 发送结果
 @return 方法调用结果
 */
- (BOOL)sendVerificationCodeForMobilePhone:(NSString *)phoneNumber reslust:(void (^)(NSError *error, NSDictionary *userInfo))result;

/**
 密码修改
 @param phoneNumber 手机号
 @param code 验证码
 @param password 加密后的密码
 @return 是否成功
 */
- (BOOL)modifyMobilePhonePassword:(NSString *)phoneNumber withVerificationCode:(NSString *)code withPassword:(NSString *)password  result:(void(^)(NSError *error, NSDictionary *userInfo))result;

@end
