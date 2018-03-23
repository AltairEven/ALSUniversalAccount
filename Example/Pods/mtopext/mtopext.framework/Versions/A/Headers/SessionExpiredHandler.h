//
//  FloodProtectionManager.h
//  mtopext
//
//  Created by sihai on 18/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorHandler.h"
#import "SessionExpiredContext.h"

@interface SessionExpiredHandler : NSObject<ErrorHandler>

/*!
 * session失效错误处理器初始化, 注册
 */
+ (SessionExpiredHandler*) getInstance;

/*!
 * 获取最近一次session失效的上下文
 * @return
 *              SessionExpiredContext
 */
- (SessionExpiredContext*) getExpiredContext;

/*!
 * 判断请求是否在黑名单
 * @param request
 * @return
 *              YES
 *              NO
 */
- (BOOL) isInBlackList: (MtopExtRequest*) request;

@end
