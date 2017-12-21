//
//  NSString+SubString.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "NSString+SubString.h"

@implementation NSString (SubString)

- (NSArray<NSString *> *)rangeStringsOfSubString:(NSString *)subString {
    if (![subString isKindOfClass:[NSString class]]) {
        return nil;
    }
    if ([subString length] == 0 || [self length] == 0) {
        return nil;
    }
    NSString *copyStr = self;
    NSMutableString *replaceString = [[NSMutableString alloc] init];
    for (NSUInteger index = 0; index < [subString length]; index ++) {
        [replaceString appendString:@"x"];
    }
    NSMutableArray *tempArray = [[NSMutableArray alloc] init];
    while ([copyStr rangeOfString:subString].location != NSNotFound) {
        NSRange  range  = [copyStr rangeOfString:subString];
        if (range.location != NSNotFound) {
            [tempArray addObject:NSStringFromRange(range)];
        }
        copyStr = [copyStr stringByReplacingCharactersInRange:NSMakeRange(range.location, range.length) withString:replaceString];
    }
    if ([tempArray count] > 0) {
        return [NSArray arrayWithArray:tempArray];
    }
    return nil;
}

- (NSString *)trimmedString {
    return [self stringByTrimmingCharactersInSet: [NSCharacterSet whitespaceAndNewlineCharacterSet]];
}

@end
