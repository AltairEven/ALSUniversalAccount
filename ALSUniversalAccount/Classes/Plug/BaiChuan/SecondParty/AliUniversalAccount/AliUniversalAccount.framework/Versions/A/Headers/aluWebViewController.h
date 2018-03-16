//
//  aluWVWebViewController.h
//
//
//  Created by bangzhe.lbz on 15-09-09.
//  Copyright (c) 2015年 alibaba. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WindVane/WindVane.h>
#import "aluUIAppearanceDelegate.h"
#import "aluWebViewDelegate.h"

#define aluWebView_GetHelpPageScript @"document.getElementById('aliusersdkHelperURL')?document.getElementById('aliusersdkHelperURL').value:''"

#define CLOSE_WEBVIEW_KEY @"callback"
#define ClOSE_WEBVIEW_URL @"https://www.alipay.com/webviewbridge"


#define aluWebViewControllerSchemeSms @"sms:"
#define aluWebViewControllerURL       @"aluH5WebViewControllerURL"

@interface aluWebViewController : WVWebViewController<aluNavigationBarAppearance>

@property (nonatomic, copy) NSString *callbackUrl;
@property (nonatomic, copy) NSDictionary *extendParms;
@property (nonatomic, assign) id<aluWebViewDelegate> delegate;

@property (nonatomic, assign, readonly) BOOL isNetWorkOK;

@property (nonatomic, assign) BOOL isForSSOH5Page;

@property (nonatomic, assign) BOOL closeNavBar;

- (void)addRightButtonInNaviBarWithUrl:(NSString*)url;
- (void)removeRightButtonInNaviBar;

- (void) startLoad;

- (void)onBack:(id)sender;

@end
