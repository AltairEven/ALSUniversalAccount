/*
 * WVUIToast.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <WindVaneBridge/WindVaneBridge.h>

@interface WVUIToast : WVDynamicHandler

/**
 * 居中显示 Toast。
 */
+ (void)toast:(NSString *)text toView:(UIView *)view displaytime:(NSTimeInterval)time withCallback:(void (^)(void))callback;

/**
 * 在指定的位置显示 Toast。
 */
+ (void)toast:(NSString *)text toView:(UIView *)view displaytime:(NSTimeInterval)time postion:(int)y withCallback:(void (^)(void))callback;

@end
