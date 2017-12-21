//
//  UIView+ViewHierarchy.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "UIView+ViewHierarchy.h"

@implementation UIView (ViewHierarchy)

- (void)removeAllSubViews {
    for (UIView *subView in self.subviews) {
        [subView removeFromSuperview];
    }
}

@end
