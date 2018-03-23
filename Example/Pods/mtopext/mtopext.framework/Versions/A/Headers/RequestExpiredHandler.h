//
//  RequestExpiredHandler.h
//  mtopext
//
//  Created by sihai on 3/12/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RequestExpiredHandler : NSObject<ErrorHandler>

/*!
 * 获取实例
 */
+ (RequestExpiredHandler*) getInstance;

@end
