//
//  NWUserLoger.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 4/19/16.
//  Copyright © 2016 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 * 日志级别
 */
typedef enum {
    NET_LOG_NONE    = -1,
    NET_LOG_ERROR   = 0,
    NET_LOG_WARNING = 1,
    NET_LOG_INFO    = 2,
    NET_LOG_DEBUG   = 3,
    NET_LOG_ALL     = 4,
} LOG_LEVEL;


extern void setNWLogLevel(LOG_LEVEL level);

/**
 * 用户自定义LOG输出回调接口
 */
@protocol NWUserLogDelegate <NSObject>

- (void)onLoging:(NSString *)message onLevel:(LOG_LEVEL)level inFile:(NSString *)file atLine:(int)line;

@end
