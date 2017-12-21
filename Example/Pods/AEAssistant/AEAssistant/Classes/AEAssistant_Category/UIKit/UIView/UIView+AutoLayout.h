//
//  UIView+AutoLayout.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (AutoLayout)

- (BOOL)resetFirstLayoutAttribute:(NSLayoutAttribute)attribute withConstant:(CGFloat)constant;

@end
