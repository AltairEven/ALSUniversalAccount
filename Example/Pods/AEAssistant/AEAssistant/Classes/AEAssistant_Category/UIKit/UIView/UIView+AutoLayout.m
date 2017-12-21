//
//  UIView+AutoLayout.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "UIView+AutoLayout.h"

@implementation UIView (AutoLayout)

- (BOOL)resetFirstLayoutAttribute:(NSLayoutAttribute)attribute withConstant:(CGFloat)constant {
    NSArray *leftBorderConstraintsArray = [self constraints];
    BOOL hasAttr = NO;
    for (NSLayoutConstraint *constraint in leftBorderConstraintsArray) {
        if (constraint.firstAttribute == attribute) {
            constraint.constant = constant;
            hasAttr = YES;
            break;
        }
    }
    return hasAttr;
}

@end
