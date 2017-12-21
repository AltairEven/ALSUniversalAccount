//
//  TextSegueModel.m
//  KidsTC
//
//  Created by Altair on 1/16/16.
//  Copyright © 2016 KidsTC. All rights reserved.
//

#import "TextSegueModel.h"
#import "NSString+SubString.h"

@implementation TextSegueModel

- (instancetype)initWithLinkWords:(NSString *)linkWords wholeString:(NSString *)wholeString {
    if (![linkWords isKindOfClass:[NSString class]] || [linkWords length] == 0) {
        return nil;
    }
    if (![wholeString isKindOfClass:[NSString class]] || [wholeString length] == 0) {
        return nil;
    }
    self = [super init];
    if (self) {
        _linkColor = [UIColor blueColor];
        _wholeString = wholeString;
        _linkWords = linkWords;
        _linkRangeStrings = [self.wholeString rangeStringsOfSubString:self.linkWords];
    }
    return self;
}

@end
