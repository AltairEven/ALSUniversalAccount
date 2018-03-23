/*
 * NSDictionary+WVUtility.h
 *
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * 包含 NSDictionary 的扩展方法。
 */
@interface NSDictionary (WVUtility)

/**
 * [NSDictioanry description] 会将中文显示为 unicode 编码，这个方法中做了额外的转换，会显示成原始的 unicode 字符。
 */
- (NSString *)wvUnicodeDescription;

/**
 * 会返回一个 dummy 对象，在获取 description 时会返回当前 NSDictionary 的 unicode description。
 * 可以延迟 NSDictionary 的序列化，在某些情况下（如输出日志）时可以带来性能提升。
 */
- (id)wvLazyDescription;

@end
