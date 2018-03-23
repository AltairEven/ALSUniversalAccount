//
//  ALBBOpenAccountWebViewDelegate.h
//  ALBBOpenAccountUI
//
//  Created by yixiao on 17/4/24.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ALBBOpenAccountWebViewDelegate <NSObject>

@optional

- (void)webViewDidLoad:(UIViewController *) viewController;
- (void)webViewWillAppear:(UIViewController *) viewController;
- (void)webViewDidAppear:(UIViewController *) viewController;
@end
