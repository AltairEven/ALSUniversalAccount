//
//  aluAlipayAsoHandler.h
//  AliUniversalAccount
//
//  Created by ethan on 6/17/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef void(^aluAlipayAsoCallback)(id result, NSError *err, NSDictionary *reserved);

@interface aluAlipayAsoHandler : NSObject

/**
 * 支付宝免等到淘宝.
 * 注意:aluAlipayAsoCallback不是在主线程执行, 如果需要在主线程执行, 请用在callback中使用
 *    dispatch_async(dispatch_get_main_queue(), ^{});
 */
-(void)asoFromAlipay:(NSDictionary *) alipayAsoParams
            reserved:(NSDictionary *) reserved
            callback:(aluAlipayAsoCallback)callback;

/**
 * 取消请求
 */
-(void)cancel;

/**
 *是否被取消
 */
-(BOOL)isCancelled;
@end