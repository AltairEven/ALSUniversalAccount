/*
 * WVModelObject.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVSerializable.h"
#import <Foundation/Foundation.h>

@interface WVModelObject : NSObject <WVSerializableProtocol>

/**
 * 使用指定字典初始化。
 *
 * @param dictionary 用于初始化的字典。
 */
- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

/**
 * 返回当前模型对应的字典。
 *
 * @return 转化后的字典
 */
- (NSDictionary *)dictionary;

@end

