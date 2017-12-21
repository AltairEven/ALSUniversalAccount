//
//  ALBBOpenAccountUpdateMobileViewController.h
//  ALBBOpenAccountUI
//
//  Created by yixiao on 16/11/29.
//  Copyright © 2016年 Alibaba. All rights reserved.
//

#import "ALBBOpenAccountBaseController.h"
#import "ALBBOpenAccountWrapperView.h"

@interface ALBBOpenAccountUpdateMobileViewController : ALBBOpenAccountBaseController

//预留的外挂引用
@property (nonatomic, strong) IBOutletCollection(NSObject)NSArray *outletCollection;

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
@property (weak, nonatomic) IBOutlet UIButton *submitButton;


- (IBAction)submitBind;
- (IBAction)prefixNumberChoose:(id)sender;


@end
