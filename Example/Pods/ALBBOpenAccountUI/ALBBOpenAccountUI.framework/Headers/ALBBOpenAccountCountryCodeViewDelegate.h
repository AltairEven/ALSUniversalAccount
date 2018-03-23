//
//  ALBBOpenAccountCountryCodeViewDelegate.h
//  ALBBOpenAccountUI
//
//  Created by yixiao on 16/12/2.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ALBBOpenAccountUI/ALBBOpenAccountCountryCodeViewController.h>

@protocol ALBBOpenAccountCountryCodeViewDelegate <NSObject>

@optional

- (void)countryCodeViewDidLoad:(ALBBOpenAccountCountryCodeViewController *) viewController;


- (void)countryCodeViewWillAppear:(ALBBOpenAccountCountryCodeViewController *) viewController;
- (void)countryCodeViewDidAppear:(ALBBOpenAccountCountryCodeViewController *) viewController;

- (void)countryCodeViewWillDisappear;
- (void)countryCodeViewDidDisappear;

- (void)countryCodeViewWillLayoutSubviews:(ALBBOpenAccountCountryCodeViewController *) viewController;
- (void)countryCodeViewDidLayoutSubviews:(ALBBOpenAccountCountryCodeViewController *) viewController;

@end
