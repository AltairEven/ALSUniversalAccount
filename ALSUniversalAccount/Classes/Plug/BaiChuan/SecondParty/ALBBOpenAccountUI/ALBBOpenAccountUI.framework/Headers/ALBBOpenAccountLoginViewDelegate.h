//
//  ALBBOpenAccountLoginViewDelegate.h
//  ALBBOpenAccountUI
//
//  Created by zhoulai on 15/6/30.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ALBBOpenAccountLoginViewController.h"

@protocol ALBBOpenAccountLoginViewDelegate <NSObject>

@optional

- (void)loginViewDidLoad:(ALBBOpenAccountLoginViewController *) viewController;


- (void)loginViewWillAppear:(ALBBOpenAccountLoginViewController *) viewController;
- (void)loginViewDidAppear:(ALBBOpenAccountLoginViewController *) viewController;

- (void)loginViewWillDisappear;
- (void)loginViewDidDisappear;

- (void)loginViewWillLayoutSubviews:(ALBBOpenAccountLoginViewController *) viewController;
- (void)loginViewDidLayoutSubviews:(ALBBOpenAccountLoginViewController *) viewController;


@end
