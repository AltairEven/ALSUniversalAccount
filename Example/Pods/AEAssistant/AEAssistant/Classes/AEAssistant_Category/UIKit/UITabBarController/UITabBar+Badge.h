//
//  UITabBar+Badge.h
//  KidsTC
//
//  Created by Altair on 12/7/15.
//  Copyright © 2015 KidsTC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITabBar (Badge)

- (UILabel *)setBadgeWithValue:(NSString *)value atIndex:(int)index;

@end
