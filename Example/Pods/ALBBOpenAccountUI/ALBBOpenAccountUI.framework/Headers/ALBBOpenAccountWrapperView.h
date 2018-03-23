//
//  ALBBOpenAccountWrapperView.h
//  ALBBOpenAccountUI
//
//  Created by liqing on 15/5/14.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString * const ALBBOpenAccountKeyboardAdaptingModeAuto;
extern NSString * const ALBBOpenAccountKeyboardAdaptingModeVisibleRect;

@interface ALBBOpenAccountWrapperView : UIScrollView

#pragma mark keyboard settings
@property (assign, nonatomic) IBInspectable BOOL hidesKeyboardOnTap;
@property (assign, nonatomic) IBInspectable BOOL hidesKeyboardOnDrag;
@property (copy, nonatomic) IBInspectable NSString *keyboardAdaptingMode;

#pragma mark visible rect
@property (assign, nonatomic) IBInspectable CGRect keyboardAdaptingVisibleRect;

@end
