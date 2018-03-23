//
//  aluWebViewControllerDelegate.h
//  UniversalAccount
//
//  Created by shaobin on 3/21/14.
//  Modified by madding.lip on 10/01/16.
//  Copyright (c) 2014 alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol aluWebViewDelegate <NSObject>

@required
- (void)willWebViewCloseCallback:(UIViewController *)controller
                         request:(NSURLRequest *)request
                          params:(NSDictionary *)params;

@end
