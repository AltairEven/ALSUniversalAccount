//
//  aluApplyAsoTokenHandler.h
//  AliUniversalAccount
//
//  Created by ethanzhou on 3/16/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  申请旺信token的callback
 *
 *  @param result   在千牛的场景里面, result是一个NSDictionary, 获取token的方式为result["token"]
 *  @param err      错误信息
 *  @param reserved 预留参数, 暂时为用上
 */
typedef void(^applyAsoTokenCallback)(id result, NSError *err, NSDictionary *reserved);
// 服务端返回的错误码
extern NSString* const aluApplyAsoTokenHandlerServerCode;
// session过期或者无效
extern NSString* const aluApplyAsoTokenHandlerSessionInvalid;

@interface aluApplyAsoTokenHandler : NSObject

/**
 *  申请token用于免等旺信,千牛等.
 *
 *  @param userId      为了排查错误, userId一定要带上.
 *  @param extraParams 其他扩展参数, 可以把Nick等信息放在里面, 更加方便排查错误
 *  @param callback    回调参数
 */
- (void)applyAsoTokenWithUserId:(NSString*)userId
                            ext:(NSDictionary*) extraParams
                       callback:(applyAsoTokenCallback)callback;

/**
 *  取消请求applyAsoTokenWithSid发起的请求, 本方法调用后,callback不会被执行
 */
- (void)cancel;

@end