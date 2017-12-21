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
 *  session
 */
- (NSString *)getAuthToken;
- (NSString *)sessionID;

/**
 *  刷新会话
 *  @discussion 如果返回sid,表示刷新成功
 *  如果err code等于ALBBOpenAccountCodeSessionExpireError，表示登录态过期，可以拉起登录页面
 *  如果err code等于ALBBOpenAccountCodeRefreshSessionError，表示刷新失败，可以补偿一次刷新
 *  其他err code可以弹窗提示
 */
- (void)refreshSessionIDWithCallback:(void (^)(NSString *sid, NSError *err))callback;

/**
 *  device
 */
- (NSString *)deviceId;
@end
