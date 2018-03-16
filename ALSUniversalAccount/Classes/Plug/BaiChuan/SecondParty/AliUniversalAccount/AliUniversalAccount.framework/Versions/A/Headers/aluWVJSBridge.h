//
//  aluWVJSBridge.h
//  AliUniversalAccount
//
//  Created by Bangzhe Liu on 15/10/14.
//  Copyright © 2015年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WVDynamicHandler.h"

@interface aluWVJSBridge : WVDynamicHandler

+ (void)getUmid:(NSDictionary *)param
          withCallback:(WVJSBResponse)callback
           withWebView:(UIWebView *)webview
    withViewController:(UIViewController *)viewController;

@end
