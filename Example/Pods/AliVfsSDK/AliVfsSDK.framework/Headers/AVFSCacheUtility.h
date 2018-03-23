//
//  AVFSCacheUtility.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/3/3.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

#define AVFSError(nCode, sMsg)        [NSError errorWithDomain:@"AliVfsSDK" code:nCode userInfo:@{@"msg":sMsg?:@""}]


@interface AVFSCacheUtility : NSObject

/**
 *  缓存总根目录
 *
 *  @return 缓存总根目录
 */
+ (NSString *)cacheRootDir;

/**
 *  模块根目录
 *
 *  @param moduleName 模块
 *
 *  @return 模块根目录
 */
+ (NSString *)moduleCachePathForModule:(NSString *)moduleName;

/**
 *  模块的文件夹目录
 *
 *  @param moduleName 模块
 *
 *  @return 模块的文件夹目录
 */
+ (NSString *)fileCacheDirPathForModule:(NSString *)moduleName;

/**
 *  模块的拓展文件夹目录
 *
 *  @param moduleName 模块
 *
 *  @return 模块的拓展文件夹目录
 */
+ (NSString *)levelFileCacheDirPathForModule:(NSString *)moduleName;

/**
 *  模块的数据库路径
 *
 *  @param moduleName 模块
 *
 *  @return 模块的数据库路径
 */
+ (NSString *)sqliteCachePathForModule:(NSString *)moduleName;

/**
 *  模块的加密数据库路径
 *
 *  @param moduleName 模块
 *
 *  @return 模块的数据库路径
 */
+ (NSString *)encryptSqliteCachePathForModule:(NSString *)moduleName;

/**
 *  流式大文件夹目录
 *
 *  @param moduleName 模块
 *
 *  @return 模块的流式大文件夹目录
 */
+ (NSString *)streamCacheDirPathForModule:(NSString *)moduleName;

/**
 *  流式缓存索引元数据文件路径
 *
 *  @return 元数据文件路径
 */
+ (NSString *)streamCacheMetaFilePath;

/**
 *  流式缓存暂存buffer文件路径
 *
 *  @param key 对应键
 *
 *  @return buffer文件路径
 */
+ (NSString *)streamCacheBufferFilePathForKey:(NSString *)key;

/**
 *  使用周期限制清理目录
 *
 *  @param dir 要清理的目录
 *  @param expireTime 最大时间周期
 *  @param isOneLevelMode 单层模式，开启的话不会进行二级目录的进入清理，而是把二级目录当做整体清理
 */
+ (void)trimDirectory:(NSString *)dir toTime:(long long)expireTime inOneLevelMode:(BOOL)isOneLevelMode;

/**
 *  使用大小限制清理目录
 *
 *  @param dir 要清理的目录
 *  @param byteLimit 最大尺寸
 *  @param isOneLevelMode 单层模式，开启的话不会进行二级目录的进入清理，而是把二级目录当做整体清理
 */
+ (void)trimDirectory:(NSString *)dir toBytes:(long long)byteLimit inOneLevelMode:(BOOL)isOneLevelMode;

@end
