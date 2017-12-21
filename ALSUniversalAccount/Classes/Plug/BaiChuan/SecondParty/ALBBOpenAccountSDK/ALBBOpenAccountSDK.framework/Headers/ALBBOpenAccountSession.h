//
//  ALBBOpenAccountSession.h
//  ALBBOpenAccount
//
//  Created by zhoulai on 15/3/17.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ALBBOpenAccountSession;
@class ALBBOpenAccountUser;

#ifndef ALBB_OPENACCOUNT_TBLOGOUT_NOTIFICATION
#define ALBB_OPENACCOUNT_TBLOGOUT_NOTIFICATION @"albb_openaccount_tblogout_notification"
#endif

@interface ALBBOpenAccountSession : NSObject

/**
 *  区分当前成功登录的场景
 *  int LOGIN = 1;int REGISTER = 2;int RESET_PASSWORD = 3;int NO_PASSWORD_LOGIN = 4;
 */
@property(nonatomic,assign)int scenario;

+ (ALBBOpenAccountSession *)sharedInstance;

/**
 *  是否已有帐号登录
 *
 *  @return return value description
 */
- (BOOL) isLogin;

/**
 *  返回已经登录的帐号
 */
- (ALBBOpenAccountUser *) getUser;

/**
 *  注销当前已登录的帐号
 */
- (void)logout;

/**
 *  注销当前已登录的帐号,并清除淘宝登录态（如果有）
 */
- (void)logoutWithClearTaobaoSession;

/**
 *  session
 */
- (NSString *)getAuthToken;
- (NSString *)sessionID;

/**
 *  刷新会话
 *  @discussion 如果返回sid,表示刷新成功
 *  如果err code等于ALBBOpenAccountCodeSessionExpireError，表示登录态过期，可以拉起登录页面
 *  其他err code可以弹窗提示
 */
- (void)refreshSessionIDWithCallback:(void (^)(NSString *sid, NSError *err))callback;


- (NSString *)refreshToken;
/**
 *  刷新会话
 *  @discussion 如果返回sid,表示刷新成功
 *  如果err code等于ALBBOpenAccountCodeSessionExpireError，表示登录态过期，可以拉起登录页面
 *  其他err code可以弹窗提示
 */
- (void)refreshSessionIDWithRefreshToken:(NSString *)refreshToken
                                Callback:(void (^)(NSString *sid, NSError *err))callback;

/**
 *  device
 */
- (NSString *)deviceId;
@end
