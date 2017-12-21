//
//  UINavigationBar+BackgroundColor.h
//  KidsTC
//
//  Created by 钱烨 on 9/22/15.
//  Copyright © 2015 KidsTC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UINavigationBar (backgroundColor)

- (void)aui_setBackgroundColor:(UIColor *)backgroundColor;

- (void)resetColorOverlay;

- (void)clearColorOverlay;

@end
