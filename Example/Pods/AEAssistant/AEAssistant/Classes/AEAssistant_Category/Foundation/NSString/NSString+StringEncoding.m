//
//  NSString+StringEncoding.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "NSString+StringEncoding.h"

@implementation NSString (StringEncoding)

- (NSString *)UTF82GBK {
    return [[NSString alloc] initWithData:[self dataUsingEncoding:CFStringConvertEncodingToNSStringEncoding(NSUTF8StringEncoding)] encoding: kCFStringEncodingGB_18030_2000];
}

- (NSString *)GBK2UTF8 {
    return [[NSString alloc] initWithData:[self dataUsingEncoding:CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingGB_18030_2000)] encoding: NSUTF8StringEncoding];
}

@end
