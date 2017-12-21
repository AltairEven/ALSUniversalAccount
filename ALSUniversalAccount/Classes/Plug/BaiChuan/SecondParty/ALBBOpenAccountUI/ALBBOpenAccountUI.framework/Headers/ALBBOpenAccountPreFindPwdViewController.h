//
//  ALBBOpenAccountPreFindPwdViewController.h
//  ALBBOpenAccountUI
//
//  Created by yixiao on 17/6/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "ALBBOpenAccountBaseController.h"

@interface ALBBOpenAccountPreFindPwdViewController : ALBBOpenAccountBaseController

@property(copy, nonatomic) NSString *username;

@property(weak, nonatomic) IBOutlet UILabel *usernameLabel;
@property(weak, nonatomic) IBOutlet UITextField *usernameTextField;


@property(weak, nonatomic) IBOutlet UIButton *submitButton;

@end
