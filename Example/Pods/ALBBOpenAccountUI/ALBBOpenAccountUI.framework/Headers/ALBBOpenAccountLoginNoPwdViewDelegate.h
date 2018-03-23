//
//  ALBBOpenAccountLoginNoPwdViewDelegate.h
//  Pods
//
//  Created by yixiao on 15/7/13.
//
//

#import <Foundation/Foundation.h>
#import "ALBBOpenAccountLoginNoPwdViewController.h"

@protocol ALBBOpenAccountLoginNoPwdViewDelegate <NSObject>

@optional
- (void)loginNoPwdViewDidLoad:(ALBBOpenAccountLoginNoPwdViewController *) viewController;

- (void)loginNoPwdViewWillAppear:(ALBBOpenAccountLoginNoPwdViewController *) viewController;
- (void)loginNoPwdViewDidAppear:(ALBBOpenAccountLoginNoPwdViewController *) viewController;

- (void)loginNoPwdViewWillDisappear;
- (void)loginNoPwdViewDidDisappear;

- (void)loginNoPwdViewWillLayoutSubviews:(ALBBOpenAccountLoginNoPwdViewController *) viewController;
- (void)loginNoPwdViewDidLayoutSubviews:(ALBBOpenAccountLoginNoPwdViewController *) viewController;


@end
