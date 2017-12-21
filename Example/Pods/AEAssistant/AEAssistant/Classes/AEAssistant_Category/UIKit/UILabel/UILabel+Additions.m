//
//  UILabel+Additions.m
//  iphone51buy
//
//  Created by icson apple on 12-6-23.
//  Copyright (c) 2012年 icson. All rights reserved.
//

#include <UIKit/UIKit.h>

#import "UILabel+Additions.h"

@implementation UILabel(Additions)

- (CGFloat)sizeToFitWithMaximumNumberOfLines:(NSInteger)lines
{
    return [self sizeOfSizeToFitWithMaximumNumberOfLines:lines].height;
}


- (CGSize)sizeOfSizeToFitWithMaximumNumberOfLines:(NSInteger)lines {
    self.numberOfLines = lines;
    CGSize maxSize = CGSizeMake(self.frame.size.width, lines * self.font.lineHeight);
    /////////edit by Altair, 20150320, for iOS 7+
    NSStringDrawingContext *context = [[NSStringDrawingContext alloc] init];
    context.minimumScaleFactor = 1.0;
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc]init];
    paragraphStyle.lineBreakMode = self.lineBreakMode;
    NSDictionary *attribute = [NSDictionary dictionaryWithObjectsAndKeys:
                               self.font, NSFontAttributeName,
                               paragraphStyle, NSParagraphStyleAttributeName, nil];
    CGSize size = [self.text boundingRectWithSize:maxSize
                                          options:(NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading)
                                       attributes:attribute
                                          context:nil].size;
    
    self.frame = CGRectMake(self.frame.origin.x, self.frame.origin.y, size.width, size.height);
    return size;
}

@end
