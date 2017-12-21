//
//  UITabBar+Badge.m
//  KidsTC
//
//  Created by Altair on 12/7/15.
//  Copyright © 2015 KidsTC. All rights reserved.
//

#import "UITabBar+Badge.h"

#define BadgeIdexStart (1000)
#define TabbarItemNums (4)

@implementation UITabBar (Badge)

- (UILabel *)setBadgeWithValue:(NSString *)value atIndex:(int)index {
    //移除之前的小红点
    [self removeBadgeOnItemIndex:index];
    if (!value || ![value isKindOfClass:[NSString class]]) {
        return nil;
    }
    
    //新建小红点
    CGRect frame = CGRectZero;
    CGFloat yPosition = 5;
    CGFloat rightMargin = 20;
    CGFloat badgeSide = 0;
    NSUInteger stringLentgh = [value length];
    CGFloat barItemWidth = self.frame.size.width / [self.items count];
    CGFloat barItemRightSide = barItemWidth * (index + 1);
    if (stringLentgh == 0) {
        badgeSide = 6;
        CGFloat xPosition = barItemRightSide - badgeSide - rightMargin;
        frame = CGRectMake(xPosition, yPosition, badgeSide, badgeSide);
        value = @"";
    } else {
        badgeSide = 14;
        CGFloat xPosition = barItemRightSide - badgeSide - rightMargin;
        frame = CGRectMake(xPosition, yPosition, badgeSide, badgeSide);
    }
    UILabel *badgeLabel = [[UILabel alloc] initWithFrame:frame];
    [badgeLabel setFont:[UIFont systemFontOfSize:10]];
    [badgeLabel setTextAlignment:NSTextAlignmentCenter];
    [badgeLabel setText:value];
    badgeLabel.tag = BadgeIdexStart + index;
    badgeLabel.layer.cornerRadius = frame.size.width / 2;
    badgeLabel.layer.masksToBounds = YES;
    
    [self addSubview:badgeLabel];
    return badgeLabel;
}

//移除小红点
- (void)removeBadgeOnItemIndex:(int)index{
    //按照tag值进行移除
    for (UIView *subView in self.subviews) {
        if (subView.tag == BadgeIdexStart + index) {
            [subView removeFromSuperview];
        }
    }
}

@end
