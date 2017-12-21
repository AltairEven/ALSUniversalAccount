//
//  NSString+DetectEmoji.m
//  iPhone51Buy
//
//  Created by Eric Shen on 2/18/14.
//  Copyright (c) 2014 icson. All rights reserved.
//

#import "NSString+DetectEmoji.h"

@implementation NSString (DetectEmoji)

+ (BOOL)detectEmoji:(NSString *)string
{
    NSUInteger len = [string lengthOfBytesUsingEncoding:NSUTF8StringEncoding];
    
    const char *utf8 = [string UTF8String];
    
    BOOL hasEmoji = NO;
    
    //0xF0(4,7) 0xE2(6) 0xC2(2) 0x30---0x39(4)
    
    for ( int i = 0; i < len; ) {
        
        unsigned int c = utf8[i];
        
        if ( c == 4294967280) {
            hasEmoji = YES;
            break;
        }
        
        if ( c == 4294967266) {
            hasEmoji = YES;
            break;
        }
        
        if ( c == 4294967234 ) {
            hasEmoji = YES;
            break;
        }
        if (c>0x29 && c < 0x40) {
            if (len - i > 6) {
                unsigned short d1 = utf8[i+1];
                unsigned short d2 = utf8[i+2];
                unsigned short d3 = utf8[i+3];
                unsigned short d4 = utf8[i+4];
                unsigned short d5 = utf8[i+5];
                unsigned short d6 = utf8[i+6];
                if ((d1 == 0xffe2)&&(d2 == 0xff83)&&(d3 == 0xffa3)&&(d4 == 0xffef)&&(d5 == 0xffb8)&&(d6 == 0xff8f)) {
                    hasEmoji = YES;
                    break;
                }
            }
        }
        if (c < 0xff) {
            i++;
            continue;
        }
        
        i += 3;
        
    }
    
    return hasEmoji;
}

@end
