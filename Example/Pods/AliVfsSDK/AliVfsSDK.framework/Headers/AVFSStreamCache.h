//
//  AVFSStreamCache.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/7/26.
//  Copyright © 2016年 TaoBao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AVFSStreamCache : NSObject

/**
 *  缓存模块名
 */
@property (copy, readonly) NSString *moduleName;

/**
 *  已存待续传数据长度
 *
 *  @param key 键
 *
 *  @return 已存长度，-1表示没有
 */
- (long long)resumingDataLengthForKey:(NSString *)key;

/**
 *  读buffer
 *
 *  @param key      键
 *  @param offset   偏移
 *  @param length   长度
 *
 *  @return 数据
 */
- (NSData *)readDataForKey:(NSString *)key range:(NSRange)range;

/**
 *  写buffer
 *
 *  @param data       数据
 *  @param key        键
 */
- (void)writeData:(NSData *)data offset:(unsigned long long)offset forKey:(NSString *)key;

/**
 *  结束写数据，底层会根据文件写入情况是否完整从而写入缓存目录
 *
 *  @param key 键
 */
- (void)finishWriteFileForKey:(NSString *)key;

/**
 *  已缓存
 *
 *  @param key 键
 *
 *  @return 缓存的文件路径
 */
- (NSString *)cachedFilePathForKey:(NSString *)key;

/**
 *  清除已缓存的文件
 *
 *  @param key 键
 */
- (void)removeCachedFileForKey:(NSString *)key;

/**
 *  同步获取总Byte数
 *
 *  @return 总Byte数
 */
- (NSUInteger)totalByte;

/**
 *  同步时间周期清理
 *
 *  @param time 时间周期限制
 */
- (void)trimToTime:(NSTimeInterval)expireTime;

/**
 *  同步大小清理
 *
 *  @param byteLimit 大小限制
 */
- (void)trimToBytes:(NSUInteger)byteLimit;



@end
