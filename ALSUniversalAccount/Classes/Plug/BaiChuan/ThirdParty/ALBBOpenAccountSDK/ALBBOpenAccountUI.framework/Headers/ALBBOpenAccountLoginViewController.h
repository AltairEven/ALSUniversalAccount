//
//  ALBBOpenAccountLoginViewController.h
//  ALBBOpenAccountUI
//
//  Created by liqing on 15/4/24.
//  Copyright (c) 2015年 Alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ALBBOpenAccountWrapperView.h"
#import "ALBBOpenAccountBaseController.h"


@interface ALBBOpenAccountLoginViewController : ALBBOpenAccountBaseController
@property (assign, nonatomic) BOOL isNeedBackButtonHidden;

//预留的外挂引用
@property (nonatomic, strong) IBOutletCollection(NSObject)  NSArray *outletCollection;

// wrapper
@property (weak, nonatomic) IBOutlet ALBBOpenAccountWrapperView *wrapperView;
// form
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *heightOfFormView;

//locale
@property (weak, nonatomic) IBOutlet UILabel *prefixLabel;
@property (weak, nonatomic) IBOutlet UIButton *prefixIcon;
// username
@property (weak, nonatomic) IBOutlet UILabel *usernameLabel;
@property (weak, nonatomic) IBOutlet UITextField *usernameField;
@property (weak, nonatomic) IBOutlet UIButton *historyButton;
@property (weak, nonatomic) IBOutlet UITableView *historyView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *heightOfHistoryView;
// password
@property (weak, nonatomic) IBOutlet UIView *passwordView;
@property (weak, nonatomic) IBOutlet UILabel *passwordLabel;
@property (weak, nonatomic) IBOutlet UITextField *passwordField;
@property (weak, nonatomic) IBOutlet UIButton *visibleButton;
// checkcode
@property (weak, nonatomic) IBOutlet UIView *checkcodeView;
@property (weak, nonatomic) IBOutlet UILabel *checkcodeLabel;
@property (weak, nonatomic) IBOutlet UITextField *checkcodeField;
@property (weak, nonatomic) IBOutlet UIImageView *checkcodeImageView;
@property (weak, nonatomic) IBOutlet UIButton *refreshButton;
// control
@property (weak, nonatomic) IBOutlet UIButton *submitButton;


- (IBAction)submitLogin;
// 前往国家列表
- (IBAction)prefixNumberChoose:(id)sender;

// sso
- (IBAction)taobaoSSO:(id)sender;
- (IBAction)weChatSSO:(id)sender;
- (IBAction)weiBoSSO:(id)sender;
- (IBAction)qqSSO:(id)sender;
@end
