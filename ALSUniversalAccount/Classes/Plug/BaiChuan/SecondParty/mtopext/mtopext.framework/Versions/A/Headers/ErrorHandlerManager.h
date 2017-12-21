//
//  ErrorHandlerManager.h
//  mtopext
//
//  注意ErrorHandlerManager是非线程安全的, 不过目前我们不会在运行时, 修改处理器注册
//
//  Created by sihai on 17/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorHandler.h"
#import "MtopExtResponse.h"

@interface ErrorHandlerManager : NSObject

/*!
 * 获取单例
 * @return
 *              ErrorHandlerManager
 */
+ (ErrorHandlerManager*) getInstance;

/*!
 * 注册一个错误码处理器
 * @param code         错误码
 * @param handler      处理器
 * @return
 *              被覆盖的处理器
 */
- (id<ErrorHandler>) registerHandler: (NSString*) code handler: (id<ErrorHandler>) handler;

/*!
 * 注册一个HTTP错误码处理器
 * @param httpResponseCode          错误码
 * @param handler                   处理器
 * @return
 *              被覆盖的处理器
 */
- (id<ErrorHandler>) registerHttpHandler: (int) httpResponseCode handler: (id<ErrorHandler>) handler;

/*!
 * 处理错误
 */
- (ACTION) handle: (MtopExtResponse*) response;

@end
