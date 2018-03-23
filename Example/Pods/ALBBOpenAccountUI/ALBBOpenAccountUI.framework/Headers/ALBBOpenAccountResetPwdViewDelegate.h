//
//  ALBBOpenAccountResetPwdViewDelegate.h
//  ALBBOpenAccountUI
//
//  Created by zhoulai on 15/7/3.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALBBOpenAccountResetPwdViewController.h"
@protocol ALBBOpenAccountResetPwdViewDelegate <NSObject>


@optional

- (void)resetPwdViewDidLoad:(ALBBOpenAccountResetPwdViewController *) viewController;


- (void)resetPwdViewWillAppear:(ALBBOpenAccountResetPwdViewController *) viewController;
- (void)resetPwdViewDidAppear:(ALBBOpenAccountResetPwdViewController *) viewController;

- (void)resetPwdViewWillDisappear;
- (void)resetPwdViewDidDisappear;

- (void)resetPwdViewWillLayoutSubviews:(ALBBOpenAccountResetPwdViewController *) viewController;
- (void)resetPwdViewDidLayoutSubviews:(ALBBOpenAccountResetPwdViewController *) viewController;


@end
