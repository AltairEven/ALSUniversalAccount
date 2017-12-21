//
//  ALBBOpenAccountBindPhoneViewDelegate.h
//  ALBBOpenAccountUI
//
//  Created by yixiao on 16/6/14.
//  Copyright © 2016年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALBBOpenAccountUpdateMobileViewController.h"

@protocol ALBBOpenAccountBindPhoneViewDelegate <NSObject>

@optional

- (void)bindPhoneViewDidLoad:(ALBBOpenAccountUpdateMobileViewController *) viewController;


- (void)bindPhoneViewWillAppear:(ALBBOpenAccountUpdateMobileViewController *) viewController;
- (void)bindPhoneViewDidAppear:(ALBBOpenAccountUpdateMobileViewController *) viewController;

- (void)bindPhoneViewWillDisappear;
- (void)bindPhoneViewDidDisappear;

- (void)bindPhoneViewWillLayoutSubviews:(ALBBOpenAccountUpdateMobileViewController *) viewController;
- (void)bindPhoneViewDidLayoutSubviews:(ALBBOpenAccountUpdateMobileViewController *) viewController;


@end
