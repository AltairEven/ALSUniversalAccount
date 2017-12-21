//
//  UIColor+GColor.m
//  iphone51buy
//
//  Created by icson apple on 12-6-12.
//  Copyright (c) 2012年 icson. All rights reserved.
//

#import "UIColor+GColor.h"

@implementation UIColor (GColor)
+ (UIColor *)colorWithNSInteger:(NSUInteger)_uinteger
{
	return [UIColor colorWithRed: (0xFF & (_uinteger >> 16)) / 255.0 green: (0xFF & (_uinteger >> 8)) / 255.0 blue: (0xFF & (_uinteger))/255.0 alpha: (0xFF & (_uinteger >> 24)) / 255.0];
}

+ (UIColor *)colorWithHexString:(NSString *)hexString {
    if (!hexString || [hexString isEqualToString:@""]) {
        return nil;
    }
    unsigned red,green,blue;
    NSRange range;
    range.length = 2;
    range.location = 1;
    [[NSScanner scannerWithString:[hexString substringWithRange:range]] scanHexInt:&red];
    range.location = 3;
    [[NSScanner scannerWithString:[hexString substringWithRange:range]] scanHexInt:&green];
    range.location = 5;
    [[NSScanner scannerWithString:[hexString substringWithRange:range]] scanHexInt:&blue];
    UIColor *color= [UIColor colorWithRed:red/255.0f green:green/255.0f blue:blue/255.0f alpha:1];
    return color;
}

+ (UIColor *)colorWithRGBString:(NSString *)rgbString {
    if (!rgbString || ![rgbString isKindOfClass:[NSString class]]) {
        return nil;
    }
    NSArray *colorArray = [rgbString componentsSeparatedByString:@","];
    if ([colorArray count] < 3) {
        return nil;
    }
    UIColor *color = [UIColor colorWithRed:[[colorArray objectAtIndex:0] floatValue]/255.0 green:[[colorArray objectAtIndex:1] floatValue]/255.0 blue:[[colorArray objectAtIndex:2] floatValue]/255.0 alpha:1];
    return color;
}

@end
