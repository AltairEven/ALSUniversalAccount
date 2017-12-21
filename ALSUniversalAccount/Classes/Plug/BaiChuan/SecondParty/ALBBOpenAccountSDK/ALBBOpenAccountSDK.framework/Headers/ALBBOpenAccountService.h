//
//  ALBBOpenAccountService.h
//  ALBBOpenAccount
//
//  Created by zhoulai on 15/10/19.
//  Copyright © 2015年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ALBBOpenAccountSession;

typedef void (^ALBBOpenAccountSuccessCallback)(ALBBOpenAccountSession *currentSession);
typedef void (^ALBBOpenAccountFailedCallback)(NSError *error);

@protocol ALBBOpenAccountService

/**
 *  根据authToken获取登录态
 *
 *  @param authToken        authToken
 *  @param successCallback  成功会掉
 *  @param failedCallback   失败回调
 */
- (void)loginByAuthToken:(NSString *)authToken
         successCallback:(ALBBOpenAccountSuccessCallback)successCallback
          failedCallback:(ALBBOpenAccountFailedCallback)failedCallback;

/**
 *  更新用户信息
 *
 *  @param profile          用户基础信息
 *  @param callback         回调，更新成功error为nil，登录态失效的error code=ALBBOpenAccountCodeSessionExpireError
 */
- (void)updateAccountProfile:(NSDictionary *)profile
                    Callback:(void (^)(NSError *error))callback;


/**
 *  设置登录用户名（只允许loginid不存在时修改一次）
 *  @discussion 如果设置了登录用户名，并允许在账密登录界面通过用户名登录，请隐藏账密登录页的国家选择框(默认已隐藏)，不然无法通过loginid登录
 *  @param loginId          登录用户名，不能为空，为空直接返回
 *  @param callback         回调，更新成功error为nil，登录态失效的error code=ALBBOpenAccountCodeSessionExpireError
 */
- (void)setAccountLoginId:(NSString *)loginId
                 Callback:(void (^)(NSError *error))callback;

@end
