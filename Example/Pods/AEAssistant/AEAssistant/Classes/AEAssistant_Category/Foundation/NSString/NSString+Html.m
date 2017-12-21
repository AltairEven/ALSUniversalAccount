//
//  NSString+Html.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "NSString+Html.h"

@implementation NSString (Html)

- (NSString *)stripTag {
    NSMutableString *html = [NSMutableString stringWithCapacity:[self length]];
    
    NSScanner *scanner = [NSScanner scannerWithString:self];
    [scanner setCharactersToBeSkipped:nil];
    NSString *tempText = nil;
    NSString *tagText = nil;
    BOOL skip = NO;
    
    while (![scanner isAtEnd]) {
        [scanner scanUpToString:@"<" intoString:&tempText];
        if (tempText != nil){
            if (!skip) {
                [html appendString:tempText];
            }
        }
        
        if (![scanner isAtEnd])
            [scanner setScanLocation:[scanner scanLocation] + 1];
        
        
        [scanner scanUpToString:@">" intoString:&tagText];
#define TAGTEXT_BEGIN_OF(str) ([tagText rangeOfString: (str)].location == 0)
        if (TAGTEXT_BEGIN_OF(@"script") || TAGTEXT_BEGIN_OF(@"style") || TAGTEXT_BEGIN_OF(@"img")) {
            skip = YES;
        } else {
            skip = NO;
            if (TAGTEXT_BEGIN_OF(@"br") || TAGTEXT_BEGIN_OF(@"/div") || TAGTEXT_BEGIN_OF(@"/p") || TAGTEXT_BEGIN_OF(@"/td")) {
                [html appendString: @"\n"];
            }
        }
#undef TAGTEXT_BEGIN_OF
        
        if (![scanner isAtEnd])
            [scanner setScanLocation:[scanner scanLocation] + 1];
        
        tagText = nil;
        tempText = nil;
    }
    
    return html;
}

@end
