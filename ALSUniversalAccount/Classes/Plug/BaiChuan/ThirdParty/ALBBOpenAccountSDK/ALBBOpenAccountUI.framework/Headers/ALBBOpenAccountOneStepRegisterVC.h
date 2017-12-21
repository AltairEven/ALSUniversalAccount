//
//  ALBBOpenAccountRegisterViewController.h
//  ALBBOpenAccountUI
//
//  Created by zhoulai on 15/4/27.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//


#import "ALBBOpenAccountBaseController.h"
#import "ALBBOpenAccountWrapperView.h"

@interface ALBBOpenAccountOneStepRegisterVC : ALBBOpenAccountBaseController


//预留的外挂引用
@property (nonatomic, strong) IBOutletCollection(NSObject)  NSArray *outletCollection;


// wrapper
@property (weak, nonatomic) IBOutlet ALBBOpenAccountWrapperView *wrapperView;
// form
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *heightOfFormView;

@property (weak, nonatomic) IBOutlet UILabel *prefixLabel;
@property (weak, nonatomic) IBOutlet UIButton *prefixIcon;

// username
@property (weak, nonatomic) IBOutlet UILabel *usernameLabel;
@property (weak, nonatomic) IBOutlet UITextField *usernameField;

// password
@property (weak, nonatomic) IBOutlet UILabel *passwordLabel;
@property (weak, nonatomic) IBOutlet UITextField *passwordField;
@property (weak, nonatomic) IBOutlet UIButton *visibleButton;

// smscode
@property (weak, nonatomic) IBOutlet UILabel *smscodeLabel;
@property (weak, nonatomic) IBOutlet UITextField *smscodeField;
@property (weak, nonatomic) IBOutlet UIButton *sendButton;
// checkcode
@property (weak, nonatomic) IBOutlet UIView *checkcodeView;
@property (weak, nonatomic) IBOutlet UILabel *checkcodeLabel;
@property (weak, nonatomic) IBOutlet UITextField *checkcodeField;
@property (weak, nonatomic) IBOutlet UIImageView *checkcodeImageView;
@property (weak, nonatomic) IBOutlet UIButton *refreshButton;
// control
@property (weak, nonatomic) IBOutlet UIButton *submitButton;

- (IBAction)submitReg;
- (IBAction)prefixNumberChoose:(id)sender;
@end
