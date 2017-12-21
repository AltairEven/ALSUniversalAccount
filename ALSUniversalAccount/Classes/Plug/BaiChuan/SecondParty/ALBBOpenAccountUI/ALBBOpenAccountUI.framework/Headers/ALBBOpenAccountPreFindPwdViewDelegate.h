//
//  ALBBOpenAccountPreFindPwdViewDelegate.h
//  ALBBOpenAccountUI
//
//  Created by yixiao on 17/6/5.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALBBOpenAccountPreFindPwdViewController.h"

@protocol ALBBOpenAccountPreFindPwdViewDelegate <NSObject>

@optional

- (void)preFindPwdViewDidLoad:(ALBBOpenAccountPreFindPwdViewController *) viewController;


- (void)preFindPwdViewWillAppear:(ALBBOpenAccountPreFindPwdViewController *) viewController;
- (void)preFindPwdViewDidAppear:(ALBBOpenAccountPreFindPwdViewController *) viewController;

- (void)preFindPwdViewWillDisappear;
- (void)preFindPwdViewDidDisappear;

- (void)preFindPwdViewWillLayoutSubviews:(ALBBOpenAccountPreFindPwdViewController *) viewController;
- (void)preFindPwdViewDidLayoutSubviews:(ALBBOpenAccountPreFindPwdViewController *) viewController;

@end
