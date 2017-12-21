//
//  NSString_1.m
//  iphone51buy
//
//  Created by Bai Haoquan on 12-9-11.
//  modify by qitao (add URLDecodedString, queryParameters)
//  Copyright (c) 2012年 icson. All rights reserved.
//

#import "NSString+UrlEncode.h"

@implementation NSString (UrlEncode)

- (NSString *) urlencode {
    NSMutableString *output = [NSMutableString string];
    const unsigned char *source = (const unsigned char *)[self UTF8String];
    size_t sourceLen = strlen((const char *)source);
    for (size_t i = 0; i < sourceLen; ++i) {
        const unsigned char thisChar = source[i];
        if (thisChar == ' '){
            [output appendString:@"+"];
        } else if (thisChar == '.' || thisChar == '-' || thisChar == '_' || thisChar == '~' ||
                   (thisChar >= 'a' && thisChar <= 'z') ||
                   (thisChar >= 'A' && thisChar <= 'Z') ||
                   (thisChar >= '0' && thisChar <= '9')) {
            [output appendFormat:@"%c", thisChar];
        } else {
            [output appendFormat:@"%%%02X", thisChar];
        }
    }
    return output;
}

- (NSString*)URLDecodedString
{
	NSString *result = (NSString *)CFBridgingRelease(CFURLCreateStringByReplacingPercentEscapesUsingEncoding(kCFAllocatorDefault,
																						   (CFStringRef)self,
																						   CFSTR(""),
																						   kCFStringEncodingUTF8));
	return result;
}

- (NSDictionary*)queryParameters
{
    NSMutableDictionary *dictionary = [[NSMutableDictionary alloc] init];
    NSString *queryString = [[self componentsSeparatedByString:@"\n"] objectAtIndex:0];
    NSArray *array = [queryString componentsSeparatedByString:@"&"];
    for (NSString *component in array){
        NSArray *pair = [component componentsSeparatedByString:@"="];
        NSString *key = [pair objectAtIndex:0];
        NSString *value = ([pair count] > 1) ? [pair objectAtIndex:1] : @"";
        [dictionary setValue:value forKey:key];
    }
    return dictionary;
}

@end
