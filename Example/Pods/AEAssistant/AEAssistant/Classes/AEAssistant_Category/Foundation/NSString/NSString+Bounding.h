//
//  NSString+Bounding.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSString (Bounding)

- (CGSize)sizeOfMaxBoundingWidth:(CGFloat)width withLineBreakMode:(NSLineBreakMode)mode font:(UIFont *)font;

- (CGSize)sizeOfMaxBoundingWidth:(CGFloat)width withLineBreakMode:(NSLineBreakMode)mode font:(UIFont *)font maxLine:(NSUInteger)line;

@end


@interface NSAttributedString (Bounding)

- (CGSize)sizeOfAttributedStringWithMaxBoundingWidth:(CGFloat)width LineBreakMode:(NSLineBreakMode)mode Font:(UIFont *)font maxLine:(NSUInteger)line;

@end