//
//  ALSUABaiChuanPlugInitializationInfo.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 17/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ALSUABaiChuanPlugInitializationInfo : NSObject <NSCopying>

@property (nonatomic, copy) NSString *appKey;

@property (nonatomic, copy) NSString *appSecret;

/**
 快捷创建实例对象的方法
 
 @param key appKey
 @param secret appSecret
 @return 类实例
 */
+ (instancetype)infoWithAppKey:(NSString *)key appSecret:(NSString *)secret;

@end



@protocol ALSUABaiChuanInitializationProtocol <NSObject>

@required

/**
 获取初始化信息
 
 @return 初始化信息数组
 */
- (ALSUABaiChuanPlugInitializationInfo *)baichuanInitilizationInfo;

@end
