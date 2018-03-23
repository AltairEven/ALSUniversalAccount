//
//  FloodProtectionManager.h
//  mtopext
//
//  Created by sihai on 18/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ErrorHandler.h"
#import "FloodProtectionDelegate.h"

@interface FloodProtectionHandler : NSObject<ErrorHandler>

@property(weak, nonatomic) id<FloodProtectionDelegate> delegate;        // 上层设置的delegate

/*!
 * 防刷模块初始化
 */
+ (FloodProtectionHandler*) getInstance;

@end
