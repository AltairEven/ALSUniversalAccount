/*
 * UIColor+WVUtility.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <UIKit/UIKit.h>

/**
 * 提供 UIColor 类的扩展方法。
 */
@interface UIColor (WVUtility)

/**
 * 使用指定的十六进制颜色初始化 UIColor。
 */
+ (UIColor *)wvColorWithHex:(NSInteger)hexValue;

/**
 * 使用指定的十六进制颜色和透明度初始化 UIColor。
 */
+ (UIColor *)wvColorWithHex:(NSInteger)hexValue alpha:(CGFloat)alphaValue;

/**
 * 使用指定的十六进制颜色字符串初始化 UIColor。
 */
+ (UIColor *)wvColorWithHexString:(NSString *)hexString;

@end
