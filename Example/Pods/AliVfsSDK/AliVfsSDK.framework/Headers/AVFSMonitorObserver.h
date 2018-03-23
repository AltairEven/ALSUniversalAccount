//
//  AVFSMonitorObserver.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/3/8.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, AVFSOperationFlag) {
    
    //文件读操作
    AVFSOperationFileRead= 1,
    
    //文件创建
    AVFSOperationFileCreate = 2,
    
    //文件写操作
    AVFSOperationFileWrite = 3,
    
    //文件删操作
    AVFSOperationFileDelete = 4,
};

@interface AVFSMonitorObserver : NSObject

/**
 *  单例
 *
 *  @return 单例
 */
+ (instancetype)sharedObserver;

/**
 *  发送监听信号
 *
 *  @param key          键名
 *  @param module       模块名
 *  @param attrs        属性列表
 */
- (void)notifyModule:(NSString *)module operate:(AVFSOperationFlag)operate attrs:(NSDictionary *)attrs;

@end
