//
//  NSString+UrlEscape.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "NSString+UrlEscape.h"

@implementation NSString (UrlEscape)

- (NSString*)urlEscape {
    return (NSString *)CFBridgingRelease(CFURLCreateStringByAddingPercentEscapes(NULL, (CFStringRef)self, NULL, (CFStringRef)@"!*'\"();:@&=+$,/?%#[]% ", kCFStringEncodingGB_18030_2000));
}

/*
 作用同上一个函数相反
 */
- (NSString *)urlUnescape
{
    return (NSString *)CFBridgingRelease(CFURLCreateStringByReplacingPercentEscapesUsingEncoding(NULL, (CFStringRef)self, (CFStringRef)@"!*'\"();:@&=+$,/?%#[]% ", kCFStringEncodingGB_18030_2000));
}

@end
