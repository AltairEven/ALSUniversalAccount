//
//  aluNavigationController.h
//  UniversalAccount
//
//  Created by shaobin on 3/26/14.
//  Modified by madding.lip on 10/01/16.
//  Copyright (c) 2014 alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "aluUIAppearanceDelegate.h"

typedef void(^aluNavigationControllerHandler)();

@interface aluNavigationController : UINavigationController

@property(nonatomic, assign)BOOL needCancelNotification;
- (void)dismissViewControllerAnimated:(BOOL)flag completion:(void (^)(void))completion;

//供外部app dismiss时调用，通知receiver来做些事情
- (void)willBeDismissedBy:(NSObject*)notUsed;

//关闭当前页面
-(void)dismissAluControllerWithCompletitionHandler:(aluNavigationControllerHandler)handler;

@end
