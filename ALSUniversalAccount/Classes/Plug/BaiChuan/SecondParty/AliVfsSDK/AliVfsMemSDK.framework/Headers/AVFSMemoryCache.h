//
//  AVFSMemoryCache.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/2/18.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^AVFSMemTrimBlock)(NSDictionary *trimDict);

@interface AVFSMemoryCache : NSObject

/**
 *  缓存名
 */
@property (copy, readonly) NSString *moduleName;

/**
 *  对象数限制，默认100
 */
@property (assign) NSUInteger countLimit;

/**
 *  byte数限制，默认1M
 */
@property (assign) NSUInteger bytesLimit;

/**
 *  初始化
 *
 *  @param name 缓存名
 *
 *  @return 实例
 */
- (instancetype)initWithModule:(NSString *)moduleName;

/**
 *  判断键对应的值是否存在
 *
 *  @param key 键
 *
 *  @return 值是否存在
 */
- (BOOL)containsObjectForKey:(NSString *)key;

/**
 *  KV查找
 *
 *  @param key 键
 *
 *  @return 值
 */
- (id)objectForKey:(NSString *)key;

/**
 *  KV设值
 *
 *  @param object 值
 *  @param key    键
 */
- (void)setObject:(id)object forKey:(NSString *)key;

/**
 *  带大小的KV设值
 *
 *  @param object 值
 *  @param key    键
 *  @param byteCount   byte数
 */
- (void)setObject:(id)object forKey:(NSString *)key withBytes:(NSUInteger)byteCount;

/**
 *  KV剔除
 *
 *  @param key 键
 */
- (void)removeObjectForKey:(NSString *)key;

/**
 *  全删除
 */
- (void)removeAllObjects;

/**
 *  总对象数
 *
 *  @return 总对象数
 */
- (NSUInteger)totalCount;

/**
 *  总Byte数
 *
 *  @return 总Byte数
 */
- (NSUInteger)totalBytes;

/**
 *  总清理，根据新设置的countLimit和bytesLimit
 */
//- (void)trimInBackground;

/**
 *  清理对象数
 *
 *  @param countLimit 对象数限制
 */
- (void)trimToCount:(NSUInteger)countLimit;

/**
 *  清理byte数
 *
 *  @param bytesLimit byte数限制
 */
- (void)trimToBytes:(NSUInteger)bytesLimit;

/**
 *  注册trim通知
 *
 *  @param block回调 
 */
- (void)registerTrimBlock:(AVFSMemTrimBlock)block;

/**
 *  取消trim通知
 */
- (void)unregisterTrimBlock;

@end
