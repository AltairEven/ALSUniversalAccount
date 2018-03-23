//
//  ALBBOpenAccountFindPwdViewController.h
//  ALBBOpenAccountUI
//
//  Created by liqing on 15/4/27.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ALBBOpenAccountBaseController.h"
#import "ALBBOpenAccountWrapperView.h"

@interface ALBBOpenAccountFindPwdViewController : ALBBOpenAccountBaseController

@property (nonatomic, strong) NSString *mobile;
//预留的外挂引用
@property (nonatomic, strong) IBOutletCollection(NSObject)  NSArray *outletCollection;

// wrapper
@property (weak, nonatomic) IBOutlet ALBBOpenAccountWrapperView *wrapperView;

@property (weak, nonatomic) IBOutlet UILabel *prefixLabel;
@property (weak, nonatomic) IBOutlet UIButton *prefixIcon;

// username
@property (weak, nonatomic) IBOutlet UILabel *usernameLabel;
@property (weak, nonatomic) IBOutlet UITextField *usernameField;
// smscode
@property (weak, nonatomic) IBOutlet UILabel *smscodeLabel;
@property (weak, nonatomic) IBOutlet UITextField *smscodeField;
@property (weak, nonatomic) IBOutlet UIButton *sendButton;

// control
@property (weak, nonatomic) IBOutlet UIButton *nextButton;

- (IBAction)prefixNumberChoose:(id)sender;

//图片验证码（已废弃）
@property (weak, nonatomic) IBOutlet UILabel *checkcodeLabel;
@property (weak, nonatomic) IBOutlet UITextField *checkcodeField;
@property (weak, nonatomic) IBOutlet UIImageView *checkcodeImageView;
@property (weak, nonatomic) IBOutlet UIButton *refreshButton;

@end
