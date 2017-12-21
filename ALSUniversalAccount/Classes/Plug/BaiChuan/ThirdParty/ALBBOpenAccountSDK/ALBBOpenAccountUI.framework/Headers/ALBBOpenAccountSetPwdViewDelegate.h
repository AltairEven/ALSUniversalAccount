//
//  ALBBOpenAccountSetPwdViewDelegate.h
//  ALBBOpenAccountUI
//
//  Created by zhoulai on 15/7/3.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALBBOpenAccountSetPwdViewController.h"
@protocol ALBBOpenAccountSetPwdViewDelegate <NSObject>



@optional

- (void)setPwdViewDidLoad:(ALBBOpenAccountSetPwdViewController *) viewController;


- (void)setPwdViewWillAppear:(ALBBOpenAccountSetPwdViewController *) viewController;
- (void)setPwdViewDidAppear:(ALBBOpenAccountSetPwdViewController *) viewController;

- (void)setPwdViewWillDisappear;
- (void)setPwdViewDidDisappear;

- (void)setPwdViewWillLayoutSubviews:(ALBBOpenAccountSetPwdViewController *) viewController;
- (void)setPwdViewDidLayoutSubviews:(ALBBOpenAccountSetPwdViewController *) viewController;

@end
