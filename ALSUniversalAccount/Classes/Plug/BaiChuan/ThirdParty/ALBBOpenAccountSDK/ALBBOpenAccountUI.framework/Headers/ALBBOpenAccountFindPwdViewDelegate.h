//
//  ALBBOpenAccountFindPwdViewDelegate.h
//  ALBBOpenAccountUI
//
//  Created by zhoulai on 15/7/3.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALBBOpenAccountFindPwdViewController.h"

@protocol ALBBOpenAccountFindPwdViewDelegate <NSObject>

@optional

- (void)findPwdViewDidLoad:(ALBBOpenAccountFindPwdViewController *) viewController;


- (void)findPwdViewWillAppear:(ALBBOpenAccountFindPwdViewController *) viewController;
- (void)findPwdViewDidAppear:(ALBBOpenAccountFindPwdViewController *) viewController;

- (void)findPwdViewWillDisappear;
- (void)findPwdViewDidDisappear;

- (void)findPwdViewWillLayoutSubviews:(ALBBOpenAccountFindPwdViewController *) viewController;
- (void)findPwdViewDidLayoutSubviews:(ALBBOpenAccountFindPwdViewController *) viewController;

@end
