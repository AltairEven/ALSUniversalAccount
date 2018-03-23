//
//  AVFSCacheManager.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/2/19.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVFSCache.h"

@interface AVFSCacheManager : NSObject

/**
 *  单例
 *
 *  @return 单例
 */
+ (instancetype)sharedManager;

/**
 *  默认缓存
 *
 *  @return 默认缓存
 */
- (AVFSCache *)defaultCache;

/**
 *  特定模块缓存
 *
 *  @param moduleName 模块名
 *
 *  @return 特定模块缓存
 */
- (AVFSCache *)cacheForModule:(NSString *)moduleName;

/**
 *  模块缓存是否存在
 *
 *  @param moduleName 模块名
 *
 *  @return 缓存是否存在
 */
- (BOOL)cacheExistForModule:(NSString *)moduleName;

/**
 *  清除缓存
 *
 *  @param moduleName 模块名
 */
- (void)removeCacheForModule:(NSString *)moduleName;

/**
 *  系统设置清理缓存，会发送名为@"TBClearCacheNotification"的通知给各未接入统一存储的业务方
 */
- (void)clearCache;

/**
 *  监控目录进行缓存淘汰清理
 *
 *  @param dir 要监控的目录
 *  @param cachePolicy 清理策略，注意：默认设置是不清理！！！
 *  @param limitSize 缓存大小限制
 *  @param limitAge 缓存周期限制
 */
- (void)monitorDirectory:(NSString *)dir withCachePolicy:(AVFSCachePolicy)cachePolicy limitSize:(long long)limitSize limitAge:(long long)limitAge;

@end
