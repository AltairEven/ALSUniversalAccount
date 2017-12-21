//
//  AVFSCacheConstants.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/2/29.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AVFS_DEFAULT_MODULE_NAME @"AVFSDefaultModule"
#define AVFS_ROOT_DIR @"/Documents/AVFSStorage"

#define AVFS_FILE_PATH_NAME @"files"
#define AVFS_LEVEL_FILE_PATH_NAME @"level_files"
#define AVFS_STREAM_FILE_PATH_NAME @"stream_files"
#define AVFS_SQLITE_NAME @"avfs.sqlite"
#define AVFS_ENCRYPT_SQLITE_NAME @"avfs_encrypt.sqlite"

#define AVFS_FIlE_INDEX_TABLE_NAME @"AVFS_FIlE_INDEX_TABLE"
#define AVFS_LEVEL_FIlE_INDEX_TABLE_NAME @"AVFS_LEVEL_FIlE_INDEX_TABLE"
#define AVFS_KV_TABLE_NAME @"AVFS_KV_TABLE"
#define AVFS_PRIVATE_TABLE_NAME @"AVFS_PRIVATE_TABLE"

/**
 *  Cache功能选项，可组合
 */
typedef NS_ENUM(NSUInteger, AVFSCacheOptions) {
    
    // 默认不加密，不进行校验
    AVFSCacheDefalut = 0,
    
    // 加密存储
    AVFSCacheEncrypt = 1 << 0,
    
    // 跳过内存，当储存比较大的文件，比如视频
    AVFSCacheSkipMemory = 1 << 1,
    
    // 文件校验，只有存文件时有效
    AVFSCacheFileVerify = 1 << 2,
    
    // 文件持久化，不可自动清理删除
    AVFSCachePersist = 1 << 3,
};

/**
 * Cache清理策略
 **/
typedef NS_ENUM(NSUInteger, AVFSCachePolicy) {
    // 默认不清理
    AVFSCachePolicyDefault = 0,
    // LRU清理
    AVFSCachePolicyLRU = 1,
    // LRU目录清理
    AVFSCachePolicyOneLevelLRU = 2,
};

/**
 * Cache源类型
 **/
typedef NS_ENUM(NSUInteger, AVFSCacheSource) {
    // 文件索引
    AVFSCacheFileIndex = 0,
    // 二级文件索引
    AVFSCacheLevelIndex = 1,
    // DB索引
    AVFSCacheDBIndex = 2
};

