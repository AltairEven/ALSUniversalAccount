//
//  ThresholdHandler.h
//  mtopext
//  限流处理
//  Created by sihai on 18/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorHandler.h"

@interface ThresholdHandler : NSObject<ErrorHandler>

/*!
 * 降级模块初始化
 */
+ (ThresholdHandler*) getInstance;

/*!
 * 查询指定版本的API是否被限流了
 *
 * @param apiName
 * @param apiVersion
 * @return
 *              YES   API + Version 被限流了
 *              NO    未被限流
 */
- (BOOL) isThresholdedWithApiName:(NSString*) apiName apiVersion: (NSString*) apiVersion;

@end
