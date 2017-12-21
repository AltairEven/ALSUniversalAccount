//
//  ALBBOpenAccountSetPwdViewController.h
//  ALBBOpenAccountUI
//
//  Created by liqing on 15/4/28.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ALBBOpenAccountBaseController.h"
#import "ALBBOpenAccountWrapperView.h"

@interface ALBBOpenAccountSetPwdViewController : ALBBOpenAccountBaseController
@property (copy, nonatomic) NSString *token;

//预留的外挂引用
@property (nonatomic, strong) IBOutletCollection(NSObject)  NSArray *outletCollection;

// wrapper
@property (weak, nonatomic) IBOutlet ALBBOpenAccountWrapperView *wrapperView;
// password
@property (weak, nonatomic) IBOutlet UILabel *passwordLabel;
@property (weak, nonatomic) IBOutlet UITextField *passwordField;
@property (weak, nonatomic) IBOutlet UIButton *visibleButton;
// control
@property (weak, nonatomic) IBOutlet UIButton *submitButton;


- (IBAction)submitPassword;
@end
