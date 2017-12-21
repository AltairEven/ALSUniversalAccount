/*
 * WVMonitorProtocol.h
 *
 * Created by WindVane.
 * Copyright (c) 2014年 阿里巴巴-无线事业部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <WindVaneCore/WVSerializable.h>

/**
 * WindVane 的监控信息 Protocol。
 * 会根据包含的属性埋性能监控埋点：
 *   会将 NSString * 类型的属性作为维度；
 *   会将 BOOL 类型的属性转换为 @"0"/@"1" 作为维度。
 *   会将数字类型的属性作为指标；
 *   不会访问其它类型。
 *   如果不希望属性作为维度/指标使用，那么可以实现 ignoredProperties 或 ignoredMonitorProperties 方法。
 * 如果实现了 error 方法，会自动埋相应的告警埋点。
 */
@protocol WVMonitorInfoProtocol <WVSerializableProtocol>

@optional

/**
 * 模块的名称，默认为 WindVane。
 */
+ (NSString * _Nonnull)monitorModule;

/**
 * 监控点的名称，默认为 Unknown。
 */
+ (NSString * _Nonnull)monitorPoint;

/**
 * 指标的数据范围。
 */
+ (NSDictionary<NSString *, NSString *> * _Nullable)monitorMeasureRange;

/**
 * 要被忽略的监控属性。
 *
 * @return 要被忽略的监控属性名称数组。
 */
+ (NSArray<NSString *> * _Nullable)ignoredMonitorProperties;

/**
 * 关联的错误信息，会根据是否包含错误信息，自动埋告警埋点。
 */
- (NSError * _Nullable)error;

/**
 * 告警埋点的 arg 参数值。
 */
- (NSString * _Nullable)errorArg;

@end
