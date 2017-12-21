//
//  AVFSMonitorConstant.h
//  AliVfsMonitor
//
//  Created by huangjy on 16/3/1.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

// 文件操作类型
typedef NS_ENUM(NSUInteger, AVFSFileOperate) {
    AVFSFileOperateRead = 1,
    AVFSFileOperateCreate,
    AVFSFileOperateWrite,
    AVFSFileOperateDelete
};

// Log日志级别
typedef NS_ENUM(NSInteger, AVFSMLogLevel) {
    AVFSMLogLevelDebug,
    AVFSMLogLevelWarning,
    AVFSMLogLevelError
};

// Log日志级别
typedef NS_ENUM(NSInteger, AVFSMCleanDismission) {
    AVFSMCleanDisAccess,
    AVFSMCleanDisCreate,
    AVFSMCleanDisModify
};

#define AVFSM_NOT_NIL_STR(a) (a?:@"")

/**
 * 未知模块
 **/
#define AVFSM_UNKNOWN_MODULE    @"unknown"
#define AVFSM_DOWNLOAD_MODULE    @"YKDownloadModule"
