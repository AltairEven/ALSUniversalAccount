//
//  ALBBOpenAccountBindPhoneViewController.h
//  ALBBOpenAccountUI
//
//  Created by yixiao on 16/6/13.
//  Copyright © 2016年 Alibaba. All rights reserved.
//

#import "ALBBOpenAccountBaseController.h"
#import "ALBBOpenAccountWrapperView.h"


@interface ALBBOpenAccountBindPhoneViewController : ALBBOpenAccountBaseController


@property (strong, nonatomic) IBOutletCollection(NSObject) NSArray *outletCollection;

@property (weak, nonatomic) IBOutlet ALBBOpenAccountWrapperView *wrapperView;


@property (weak, nonatomic) IBOutlet UILabel *prefixLabel;
@property (weak, nonatomic) IBOutlet UIButton *prefixIcon;
@property (weak, nonatomic) IBOutlet UITextField *phoneTextField;
@property (weak, nonatomic) IBOutlet UILabel *usernameLabel;
@property (weak, nonatomic) IBOutlet UIButton *submitButton;

- (IBAction)submit:(id)sender;
- (IBAction)prefixNumberChoose:(id)sender;
@end
