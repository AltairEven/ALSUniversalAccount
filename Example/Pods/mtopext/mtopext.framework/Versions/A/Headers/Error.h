//
//  Error.h
//  mtopext
//
//  Created by sihai on 4/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MtopSDK/TBSDKErrorRule.h>
#import "Constants.h"

@interface Error : NSObject

@property(assign, nonatomic) int       httpResponseCode;        // http响应码
@property(strong, nonatomic) NSString* code;                    // 错误码
@property(strong, nonatomic) NSString* msg;                     // 错误提示信息

@property(strong, nonatomic) NSString* subCode;                 // 子错误码
@property(strong, nonatomic) NSString* subMsg;                  // 子错误提示信息

@property(strong, nonatomic) NSError* rawError;                 // 原始的错误

/*!
 * 判断是否成功
 */
- (BOOL) isSucceed;

/*!
 * 初始化
 * @param httpResponseCode
 * @param code
 * @param msg
 * @return
 *          Error
 */
- (Error*) initWithHttpResponseCode: (int) httpResponseCode  code: (NSString*) code msg: (NSString*) msg;

/*!
 * 初始化
 * @param httpResponseCode
 * @param code
 * @param msg
 * @param subCode
 * @param subMsg
 * @return
 *          Error
 */
- (Error*) initWithHttpResponseCode: (int) httpResponseCode code: (NSString*) code msg: (NSString*) msg subCode: (NSString*) subCode subMsg: (NSString*) subMsg;

/*!
 * 为兼容, 转换成老的error
 * @return
 *          id<TBSDKErrorRule>
 *              
 */
- (id<TBSDKErrorRule>) toTbsdkError;

/*!
 * 判断是否为网络错误
 * @return
 *          YES
 *          NO
 */
- (BOOL) isNetworkError;

/*!
 * 判断是否为响应错误
 * @return
 *          YES
 *          NO
 */
- (BOOL) isResponseDataParseError;

/*!
 * 构造一个成功错误码
 */
+ (Error*) succeed;

@end
