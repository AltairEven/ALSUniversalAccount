//
//  AccsProtocol.h
//  Pods
//
//  Created by 亿刀 on 15/4/3.
//
//

#import <Foundation/Foundation.h>
#import "TBAccsVariable.h"

@class TBAccsReceiveAndCallBackCenter;
@class TBAccsRequestQueue;
@class TBAccsConfiguration;

@protocol AccsProtocol <NSObject>

/**
 *  绑定app
 *
 *  @param appleToken   苹果APNS所需要deviceToken
 *  @param resultsBlock 请求响应回调
 */
- (void)bindAppWithAppleToken:(NSData *)appleToken
                     callBack:(TBAccsManagerResponseBlock)callBack;

/**
 *  解绑app
 *
 *  @param resultsBlock 请求响应回调
 */
- (void)unbindAppWithResultsBlock:(TBAccsManagerResponseBlock)callback;

/**
 *  绑定用户
 *
 *  @param userId       用户id
 *  @param resultsBlock 请求响应回调
 */
- (void)bindUserWithUserId:(NSString *)userId
                  callBack:(TBAccsManagerResponseBlock)callBack;

/**
 *  解绑用户
 *
 *  @param userId       用户id
 *  @param resultsBlock 请求响应回调
 */
- (void)unbindUserWithUserId:(NSString *)userId
                    callBack:(TBAccsManagerResponseBlock)callBack;

/**
 *  验证是否为通道错误
 *
 *  @param errorCode 错误码
 *  @param extP      附加参数，可为nil
 *
 *  @return YES，是通道错误。NO，非通道错误
 */
+ (BOOL)isChannelError:(int)errorCode extP:(NSDictionary *)extP;

/**
 *  数据出现错误，上报原始数据
 *
 *  @param dataID           请求id
 *  @param serviceID        服务id
 *  @param parameters       扩展字段，可谓为nil
 *
 *  @return YES，是通道错误。NO，非通道错误
 */
+ (NSError *)responseDataabnormal:(NSString *)dataID
                        serviceID:(NSString *)serviceID
                       parameters:(NSDictionary *)parameters;



@end