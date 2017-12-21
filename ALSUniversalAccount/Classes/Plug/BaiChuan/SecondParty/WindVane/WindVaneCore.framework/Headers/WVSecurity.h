/*
 * WVSecurity.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

/**
 * 提供安全相关的功能。
 */
@interface WVSecurity : NSObject

/**
 * 从 .der 公钥证书文件中获取到公钥的 SecKeyRef 指针。
 */
+ (SecKeyRef)getRSAPublicKey:(NSData *)certificateData;

@end
