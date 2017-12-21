//
//  ALBBOpenAccountRegisterViewDelegate.h
//  ALBBOpenAccountUI
//
//  Created by zhoulai on 15/7/2.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ALBBOpenAccountRegisterViewController.h"
@protocol ALBBOpenAccountRegisterViewDelegate <NSObject>



@optional

- (void)registerViewDidLoad:(ALBBOpenAccountRegisterViewController *) viewController;


- (void)registerViewWillAppear:(ALBBOpenAccountRegisterViewController *) viewController;
- (void)registerViewDidAppear:(ALBBOpenAccountRegisterViewController *) viewController;

- (void)registerViewWillDisappear;
- (void)registerViewDidDisappear;

- (void)registerViewWillLayoutSubviews:(ALBBOpenAccountRegisterViewController *) viewController;
- (void)registerViewDidLayoutSubviews:(ALBBOpenAccountRegisterViewController *) viewController;

@end
