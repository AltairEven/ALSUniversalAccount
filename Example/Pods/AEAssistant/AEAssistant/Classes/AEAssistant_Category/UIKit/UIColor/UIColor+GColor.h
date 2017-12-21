//
//  UIColor+GColor.h
//  iphone51buy
//
//  Created by icson apple on 12-6-12.
//  Copyright (c) 2012年 icson. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (GColor)

+ (UIColor *)colorWithNSInteger:(NSUInteger)_uinteger;

+ (UIColor *)colorWithHexString:(NSString *)hexString;

+ (UIColor *)colorWithRGBString:(NSString *)rgbString;

@end
