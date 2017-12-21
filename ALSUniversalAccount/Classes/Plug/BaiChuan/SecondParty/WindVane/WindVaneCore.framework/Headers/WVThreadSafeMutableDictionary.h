/*
 * WVThreadSafeMutableDictionary.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * 线程安全的 NSMutableDictionary。
 */
@interface WVThreadSafeMutableDictionary <KeyType, ObjectType> : NSMutableDictionary<KeyType, ObjectType>

/**
 * 使用指定文件的内容初始化。
 *
 * @param path 要读取的文件内容。
 */
+ (WVThreadSafeMutableDictionary<KeyType, ObjectType> *)dictionaryWithContentsOfFile:(NSString *)path;

/**
 * 使用指定 URL 的结果初始化。
 *
 * @param url 要读取的 URL。
 */
+ (WVThreadSafeMutableDictionary<KeyType, ObjectType> *)dictionaryWithContentsOfURL:(NSURL *)url;

/**
 * 使用指定文件的内容初始化。
 *
 * @param path 要读取的文件内容。
 */
- (WVThreadSafeMutableDictionary<KeyType, ObjectType> *)initWithContentsOfFile:(NSString *)path;

/**
 * 使用指定 URL 的结果初始化。
 *
 * @param url 要读取的 URL。
 */
- (WVThreadSafeMutableDictionary<KeyType, ObjectType> *)initWithContentsOfURL:(NSURL *)url;

///**
// * 返回键枚举器，枚举过程本身是非线程安全的，请谨慎使用。
// */
//- (NSEnumerator *)keyEnumerator;

@end
