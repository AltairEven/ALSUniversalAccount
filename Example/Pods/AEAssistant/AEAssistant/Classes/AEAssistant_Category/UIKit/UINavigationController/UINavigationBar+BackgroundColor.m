//
//  UINavigationBar+BackgroundColor.m
//  KidsTC
//
//  Created by 钱烨 on 9/22/15.
//  Copyright © 2015 KidsTC. All rights reserved.
//

#import "UINavigationBar+BackgroundColor.h"
#import <objc/runtime.h>

@implementation UINavigationBar (backgroundColor)

- (UIView *)overlay
{
    return objc_getAssociatedObject(self, @"kOverlayKey");
}

- (void)setOverlay:(UIView *)overlay
{
    objc_setAssociatedObject(self, @"kOverlayKey", overlay, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (void)aui_setBackgroundColor:(UIColor *)backgroundColor
{
    if (!self.overlay) {
        [self setBackgroundImage:[UIImage new] forBarMetrics:UIBarMetricsDefault];
        [self setShadowImage:[UIImage new]];
        
        // insert an overlay into the view hierarchy
        self.overlay = [[UIView alloc] initWithFrame:CGRectMake(0, -20, [UIScreen mainScreen].bounds.size.width, self.bounds.size.height + 20)];
        self.overlay.autoresizingMask = UIViewAutoresizingFlexibleWidth|UIViewAutoresizingFlexibleHeight;
        
        [self insertSubview:self.overlay atIndex:0];
    }
    self.overlay.backgroundColor = backgroundColor;
}

- (void)resetColorOverlay {
    if (self.overlay) {
        [self insertSubview:self.overlay atIndex:0];
    }
}

- (void)clearColorOverlay {
    [self setOverlay:nil];
}

@end
