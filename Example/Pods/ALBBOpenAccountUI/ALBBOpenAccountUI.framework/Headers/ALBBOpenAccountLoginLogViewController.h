//
//  ALBBOpenAccountLoginLogViewController.h
//  ALBBOpenAccountUI
//
//  Created by yixiao on 16/6/12.
//  Copyright © 2016年 Alibaba. All rights reserved.
//

#import "ALBBOpenAccountBaseController.h"

@interface ALBBOpenAccountLoginLogViewController : ALBBOpenAccountBaseController

@property (weak, nonatomic) IBOutlet UITableView *loginLogTableView;

@property (strong, nonatomic) IBOutlet UIView *headerView;

@property (strong,nonatomic) IBOutletCollection(NSObject) NSArray *outletCollection;

@end
