//
//  ALBBOpenAccountRegisterViewDelegate.h
//  ALBBOpenAccountUI
//
//  Created by zhoulai on 15/7/2.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ALBBOpenAccountOneStepRegisterVC.h"
@protocol ALBBOpenAccountOneStepRegisterViewDelegate <NSObject>



@optional

- (void)registerViewDidLoad:(ALBBOpenAccountOneStepRegisterVC *) viewController;


- (void)registerViewWillAppear:(ALBBOpenAccountOneStepRegisterVC *) viewController;
- (void)registerViewDidAppear:(ALBBOpenAccountOneStepRegisterVC *) viewController;

- (void)registerViewWillDisappear;
- (void)registerViewDidDisappear;

- (void)registerViewWillLayoutSubviews:(ALBBOpenAccountOneStepRegisterVC *) viewController;
- (void)registerViewDidLayoutSubviews:(ALBBOpenAccountOneStepRegisterVC *) viewController;

@end
