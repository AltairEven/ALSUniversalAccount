//
//  NSString+Bounding.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "NSString+Bounding.h"

@implementation NSString (Bounding)

- (CGSize)sizeOfMaxBoundingWidth:(CGFloat)width withLineBreakMode:(NSLineBreakMode)mode font:(UIFont *)font {
    return [self sizeOfMaxBoundingWidth:width withLineBreakMode:mode font:font maxLine:0];
}

- (CGSize)sizeOfMaxBoundingWidth:(CGFloat)width withLineBreakMode:(NSLineBreakMode)mode font:(UIFont *)font maxLine:(NSUInteger)line {
    if ([self length] == 0) {
        return CGSizeZero;
    }
    CGSize maxSize = CGSizeMake(width, line * font.lineHeight);
    
    /////////edit by Altair, 20150320, for iOS 7+
    NSStringDrawingContext *context = [[NSStringDrawingContext alloc] init];
    context.minimumScaleFactor = 1.0;
    
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc]init];
    paragraphStyle.lineBreakMode = mode;
    NSDictionary *attribute = [NSDictionary dictionaryWithObjectsAndKeys:
                               font, NSFontAttributeName,
                               paragraphStyle, NSParagraphStyleAttributeName, nil];
    
    CGSize size = [self boundingRectWithSize:maxSize
                                     options:(NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading)
                                  attributes:attribute
                                     context:nil].size;
    return size;
}

@end


@implementation NSAttributedString (Bounding)

- (CGSize)sizeOfAttributedStringWithMaxBoundingWidth:(CGFloat)width LineBreakMode:(NSLineBreakMode)mode Font:(UIFont *)font maxLine:(NSUInteger)line {
    if ([self length] == 0) {
        return CGSizeZero;
    }
    
    CGSize maxSize = CGSizeMake(width, line * font.lineHeight);
    
    /////////edit by Altair, 20150320, for iOS 7+
    NSStringDrawingContext *context = [[NSStringDrawingContext alloc] init];
    context.minimumScaleFactor = 1.0;
    
    NSMutableParagraphStyle *paragraphStyle = [[NSMutableParagraphStyle alloc]init];
    paragraphStyle.lineBreakMode = mode;
    NSDictionary *attribute = [NSDictionary dictionaryWithObjectsAndKeys:
                               font, NSFontAttributeName,
                               paragraphStyle, NSParagraphStyleAttributeName, nil];
    
    NSMutableAttributedString *copyString = [self mutableCopy];
    [copyString addAttributes:attribute range:NSMakeRange(0, [copyString length])];
    
    CGSize size = [copyString boundingRectWithSize:maxSize
                                     options:(NSStringDrawingUsesLineFragmentOrigin | NSStringDrawingUsesFontLeading)
                                     context:nil].size;
    return size;
}

@end