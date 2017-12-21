//
//  AVFSSQLiteCache.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/3/3.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import "AVFSCacheConstants.h"

@interface AVFSSQLiteCache : NSObject

/**
 *  缓存名
 */
@property (copy, readonly) NSString *moduleName;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 *  同步判断键对应的值是否存在
 *
 *  @param key 键
 *
 *  @return 值是否存在
 */
- (BOOL)containsObjectForKey:(NSString *)key;

/**
 *  异步判断键对应的值是否存在
 *
 *  @param key   键
 *  @param block 值是否存在回调
 */
- (void)containsObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key, BOOL contains))block;

/**
 *  同步KV查找
 *
 *  @param key 键
 *
 *  @return 值
 */
- (id<NSCoding>)objectForKey:(NSString *)key;

/**
 *  同步KV查找
 *
 *  @param key 键
 *  @param skipMemory 是否跳过内存
 *
 *  @return 值
 */
- (id<NSCoding>)objectForKey:(NSString *)key skipMemory:(BOOL)skipMemory;

/**
 *  异步KV查找
 *
 *  @param key   键
 *  @param block 值回调
 */
- (void)objectForKey:(NSString *)key withBlock:(void(^)(NSString *key, id<NSCoding> object))block;

/**
 *  异步KV查找
 *
 *  @param key   键
 *  @param skipMemory 是否跳过内存
 *  @param block 值回调
 */
- (void)objectForKey:(NSString *)key skipMemory:(BOOL)skipMemory withBlock:(void(^)(NSString *key, id<NSCoding> object))block;

/**
 *  同步KV设值
 *
 *  @param object 值
 *  @param key    键
 *  @param options   存储选项
 */
- (void)setObject:(id<NSCoding>)object forKey:(NSString *)key options:(AVFSCacheOptions)options;

/**
 *  异步KV设值
 *
 *  @param object 值
 *  @param key    键
 *  @param options   存储选项
 *  @param block  回调
 */
- (void)setObject:(id<NSCoding>)object forKey:(NSString *)key options:(AVFSCacheOptions)options withBlock:(void(^)(void))block;

/**
 *  同步KV剔除
 *
 *  @param key 键
 */
- (void)removeObjectForKey:(NSString *)key;

/**
 *  异步KV剔除
 *
 *  @param key   键
 *  @param block 回调
 */
- (void)removeObjectForKey:(NSString *)key withBlock:(void(^)(NSString *key))block;

/**
 *  同步全删除
 */
- (void)removeAllObjects;

/**
 *  所有key
 *
 *  @return key列表
 */
- (NSArray *)allkeys;

/**
 *  异步全删除
 *
 *  @param block 回调
 */
- (void)removeAllObjectsWithBlock:(void(^)(void))block;

/**
 *  同步获取总对象数
 *
 *  @return 总对象数
 */
- (NSUInteger)totalCount;

/**
 *  异步获取总对象数
 *
 *  @param block 总对象数回调
 */
- (void)totalCountWithBlock:(void(^)(NSUInteger totalCount))block;

/**
 *  同步获取总Byte数
 *
 *  @return 总Byte数
 */
- (NSUInteger)totalByte;

/**
 *  异步获取总Byte数
 *
 *  @param block 总Byte数回调
 */
- (void)totalByteWithBlock:(void(^)(NSUInteger totalCost))block;

/**
 *  同步清理个数
 *
 *  @param count 个数限制
 */
- (void)trimToCount:(NSUInteger)count;

/**
 *  异步清理个数
 *
 *  @param count 个数限制
 *  @param block 回调
 */
- (void)trimToCount:(NSUInteger)count withBlock:(void(^)(void))block;

/**
 *  同步清理占用空间
 *
 *  @param byte 空间大小限制
 */
- (void)trimToBytes:(NSUInteger)byte;

/**
 *  异步清理占用空间
 *
 *  @param byte  空间大小限制
 *  @param block 回调
 */
- (void)trimToBytes:(NSUInteger)byte withBlock:(void(^)(void))block;

/**
 *  同步时间周期清理
 *
 *  @param time 时间周期限制
 */
- (void)trimToTime:(NSTimeInterval)expireTime;

/**
 *  异步时间周期清理
 *
 *  @param time  时间周期限制
 *  @param block 回调
 */
- (void)trimToTime:(NSTimeInterval)expireTime withBlock:(void(^)(void))block;

@end
