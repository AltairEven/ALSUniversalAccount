//
//  ALBBOpenAccountSSODelegate.h
//  ALBBOpenAccountUI
//
//  Created by yixiao on 16/9/18.
//  Copyright © 2016年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ALBBOpenAccountSSODelegate <NSObject>

@optional
- (void) openAccountSSOLoginError:(NSError *)error Session:(ALBBOpenAccountSession *)session;

@end
