//
//  AEWebViewContainer.m
//  wesg
//
//  Created by Altair on 9/22/16.
//  Copyright © 2016 AliSports. All rights reserved.
//
#import "AEWebViewContainer.h"

@interface AEWebViewContainer () <WKNavigationDelegate, WKUIDelegate, UIWebViewDelegate>

- (void)setupWebView;

- (WKWebViewConfiguration *)wkWebViewConfiguration;

@end

@implementation AEWebViewContainer
@synthesize currentUrlRequest = _currentUrlRequest;

- (void)willMoveToSuperview:(UIView *)newSuperview {
    [super willMoveToSuperview:newSuperview];
    if (!self.wkWebView && !self.uiWebView) {
        //默认WKWebView
        [self setWebViewType:AEWebViewContainTypeWKWebView];
    }
}

- (void)dealloc{
    self.wkWebView.navigationDelegate = nil;
    self.wkWebView.UIDelegate = nil;
    self.wkWebView.scrollView.delegate = nil;
    
    self.uiWebView.delegate = nil;
    self.uiWebView.scrollView.delegate = nil;
}

#pragma mark Getter & Setter

- (void)setWebViewType:(AEWebViewContainType)webViewType {
    if (webViewType == _webViewType && (self.uiWebView || self.wkWebView)) {
        //type相同，并且有一种webview已经初始化过，则直接返回
        return;
    }
    _webViewType = webViewType;
    [self setupWebView];
}

- (NSURLRequest *)currentUrlRequest {
    NSURLRequest *urlRequest = nil;
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            urlRequest = self.uiWebView.request;
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            if (_currentUrlRequest) {
                urlRequest = _currentUrlRequest;
            } else {
                urlRequest = [NSURLRequest requestWithURL:self.wkWebView.URL];
            }
        }
            break;
        default:
            break;
    }
    return urlRequest;
}

- (NSURL *)currentUrl {
    NSURL *url = nil;
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            url = self.uiWebView.request.URL;
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            url = self.wkWebView.URL;
        }
            break;
        default:
            break;
    }
    return url;
}

- (BOOL)canGoBack {
    BOOL can = NO;
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            can = self.uiWebView.canGoBack;
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            can = self.wkWebView.canGoBack;
        }
            break;
        default:
            break;
    }
    return can;
}

- (BOOL)canGoForward {
    BOOL can = NO;
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            can = self.uiWebView.canGoForward;
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            can = self.wkWebView.canGoForward;
        }
            break;
        default:
            break;
    }
    return can;
}

- (BOOL)isLoading {
    BOOL loading = NO;
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            loading = self.uiWebView.isLoading;
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            loading = self.wkWebView.isLoading;
        }
            break;
        default:
            break;
    }
    return loading;
}

- (UIScrollView *)scrollView{
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            return _uiWebView.scrollView;
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            return _wkWebView.scrollView;
        }
            break;
        default:
            break;
    }
    return nil;
}

#pragma mark WKNavigationDelegate

- (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {
    WKNavigationActionPolicy policy = WKNavigationActionPolicyAllow;
    if (self.delegate && [self.delegate respondsToSelector:@selector(webViewContainer:shouldStartLoadWithRequest:navigationType:webViewType:)]) {
        NSInteger type = navigationAction.navigationType;
        if (type == -1) {
            type = AEWebViewNavigationTypeOther;
        }
        BOOL should = [self.delegate webViewContainer:self shouldStartLoadWithRequest:navigationAction.request navigationType:(AEWebViewNavigationType)type webViewType:AEWebViewContainTypeWKWebView];
        if (!should) {
            policy = WKNavigationActionPolicyCancel;
        }
    }
    if (decisionHandler) {
        decisionHandler(policy);
    }
    if (policy == WKNavigationActionPolicyAllow) {
        _currentUrlRequest = [navigationAction.request copy];
    }
}

- (void)webView:(WKWebView *)webView didStartProvisionalNavigation:(null_unspecified WKNavigation *)navigation {
    if (self.delegate && [self.delegate respondsToSelector:@selector(webViewContainerDidStartLoad:webViewType:)]) {
        [self.delegate webViewContainerDidStartLoad:self webViewType:AEWebViewContainTypeWKWebView];
    }
}

- (void)webView:(WKWebView *)webView didFinishNavigation:(null_unspecified WKNavigation *)navigation {
    NSLog(@"WKWebView DidFinishedLoading");
    if (self.delegate && [self.delegate respondsToSelector:@selector(webViewContainerDidFinishLoad:webViewType:)]) {
        [self.delegate webViewContainerDidFinishLoad:self webViewType:AEWebViewContainTypeWKWebView];
    }
}

- (void)webView:(WKWebView *)webView didFailNavigation:(null_unspecified WKNavigation *)navigation withError:(NSError *)error {
    NSLog(@"WKWebView DidFailNavigation, %@", error);
    if (self.delegate && [self.delegate respondsToSelector:@selector(webViewContainer:didFailLoadWithError:webViewType:)]) {
        [self.delegate webViewContainer:self didFailLoadWithError:error webViewType:AEWebViewContainTypeWKWebView];
    }
}

- (void)webView:(WKWebView *)webView didFailProvisionalNavigation:(WKNavigation *)navigation withError:(NSError *)error{
    NSLog(@"WKWebView DidFailProvisionalNavigation, %@", error);
}
#pragma mark WKUIDelegate

#pragma mark UIWebViewDelegate

- (BOOL)webView:(UIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType {
    if (self.delegate && [self.delegate respondsToSelector:@selector(webViewContainer:shouldStartLoadWithRequest:navigationType:webViewType:)]) {
        return [self.delegate webViewContainer:self shouldStartLoadWithRequest:request navigationType:(AEWebViewNavigationType)navigationType webViewType:AEWebViewContainTypeUIWebView];
    }
    return YES;
}

- (void)webViewDidStartLoad:(UIWebView *)webView {
    if (self.delegate && [self.delegate respondsToSelector:@selector(webViewContainerDidStartLoad:webViewType:)]) {
        [self.delegate webViewContainerDidStartLoad:self webViewType:AEWebViewContainTypeUIWebView];
    }
}

- (void)webViewDidFinishLoad:(UIWebView *)webView {
    NSLog(@"UIWebView DidFinishedLoading");
    if (self.delegate && [self.delegate respondsToSelector:@selector(webViewContainerDidFinishLoad:webViewType:)]) {
        [self.delegate webViewContainerDidFinishLoad:self webViewType:AEWebViewContainTypeUIWebView];
    }
}

- (void)webView:(UIWebView *)webView didFailLoadWithError:(NSError *)error {
    NSLog(@"UIWebView DidFailProvisionalNavigation, %@", error);
    if (self.delegate && [self.delegate respondsToSelector:@selector(webViewContainer:didFailLoadWithError:webViewType:)]) {
        [self.delegate webViewContainer:self didFailLoadWithError:error webViewType:AEWebViewContainTypeUIWebView];
    }
}


#pragma mark UIScrollViewDelegate


#pragma mark Private methods

- (void)setupWebView {
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            //initialization
            if (!_uiWebView) {
                _uiWebView= [[UIWebView alloc] init];
                [self.uiWebView setScalesPageToFit:YES];
                [self addSubview:self.uiWebView];
                [self.uiWebView setBackgroundColor:[UIColor clearColor]];
                [self setBackgroundColor:[UIColor clearColor]];
                
                //add constraint
                [self.uiWebView setTranslatesAutoresizingMaskIntoConstraints:NO];
                NSLayoutConstraint *left = [NSLayoutConstraint constraintWithItem:self.uiWebView attribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeLeft multiplier:1 constant:0];//+
                NSLayoutConstraint *top = [NSLayoutConstraint constraintWithItem:self.uiWebView attribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeTop multiplier:1 constant:0];//+
                NSLayoutConstraint *right = [NSLayoutConstraint constraintWithItem:self.uiWebView attribute:NSLayoutAttributeRight relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeRight multiplier:1 constant:0];//-
                NSLayoutConstraint *bottom = [NSLayoutConstraint constraintWithItem:self.uiWebView attribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeBottom multiplier:1 constant:0];//-
                
                [NSLayoutConstraint activateConstraints:@[left, right, top, bottom]];
            }
            if (_wkWebView) {
                [_wkWebView stopLoading];
            }
            [self bringSubviewToFront:self.uiWebView];
            self.uiWebView.delegate = self;
            [self.uiWebView loadRequest:self.currentUrlRequest ? self.currentUrlRequest : self.originalUrlRequest];
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            //initialization
            if (!_wkWebView) {
                _wkWebView = [[WKWebView alloc] initWithFrame:CGRectZero configuration:[self wkWebViewConfiguration]];
                [self addSubview:self.wkWebView];
                [self.wkWebView setBackgroundColor:[UIColor clearColor]];
                [self setBackgroundColor:[UIColor clearColor]];
                
                //add constraint
                [self.wkWebView setTranslatesAutoresizingMaskIntoConstraints:NO];
                NSLayoutConstraint *left = [NSLayoutConstraint constraintWithItem:self.wkWebView attribute:NSLayoutAttributeLeft relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeLeft multiplier:1 constant:0];//+
                NSLayoutConstraint *top = [NSLayoutConstraint constraintWithItem:self.wkWebView attribute:NSLayoutAttributeTop relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeTop multiplier:1 constant:0];//+
                NSLayoutConstraint *right = [NSLayoutConstraint constraintWithItem:self.wkWebView attribute:NSLayoutAttributeRight relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeRight multiplier:1 constant:0];//-
                NSLayoutConstraint *bottom = [NSLayoutConstraint constraintWithItem:self.wkWebView attribute:NSLayoutAttributeBottom relatedBy:NSLayoutRelationEqual toItem:self attribute:NSLayoutAttributeBottom multiplier:1 constant:0];//-
                
                [NSLayoutConstraint activateConstraints:@[left, right, top, bottom]];
                
            }
            if (_uiWebView) {
                [_uiWebView stopLoading];
            }
            [self bringSubviewToFront:self.wkWebView];
            self.wkWebView.UIDelegate = self;
            self.wkWebView.navigationDelegate = self;
            [self.wkWebView loadRequest:self.currentUrlRequest ? self.currentUrlRequest : self.originalUrlRequest];
        }
            break;
        default:
            break;
    }
}

- (WKWebViewConfiguration *)wkWebViewConfiguration {
    NSString *jScript = @"var meta = document.createElement('meta'); meta.setAttribute('name', 'viewport'); meta.setAttribute('content', 'width=device-width'); document.getElementsByTagName('head')[0].appendChild(meta);)";
    
    WKUserScript *wkUScript = [[WKUserScript alloc] initWithSource:jScript injectionTime:WKUserScriptInjectionTimeAtDocumentEnd forMainFrameOnly:YES];
    WKUserContentController *wkUController = [[WKUserContentController alloc] init];
    [wkUController addUserScript:wkUScript];
    
    WKWebViewConfiguration *config = [[WKWebViewConfiguration alloc] init];
    config.userContentController = wkUController;
    config.allowsInlineMediaPlayback = YES;
    config.preferences.javaScriptCanOpenWindowsAutomatically = NO;

    if ([[[UIDevice currentDevice] systemVersion] hasPrefix:@"8."]) {
        config.mediaPlaybackRequiresUserAction = NO;
    } else if ([[[UIDevice currentDevice] systemVersion] hasPrefix:@"9."]) {
        config.requiresUserActionForMediaPlayback = NO;
    } else {
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_10_0
        config.mediaTypesRequiringUserActionForPlayback = WKAudiovisualMediaTypeVideo;
#endif
    }
    
    return config;
}

#pragma mark Publick methods

- (void)loadRequest:(NSURLRequest *)request {
    _originalUrlRequest = request;
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            [self.uiWebView loadRequest:request];
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            [self.wkWebView loadRequest:request];
        }
            break;
        default:
            break;
    }
}

- (void)reload {
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            [self.uiWebView reload];
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            [self.wkWebView reload];
        }
            break;
        default:
            break;
    }
}

- (void)reloadFromOrigin {
    _currentUrlRequest = nil;
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            [self.uiWebView loadRequest:self.originalUrlRequest];
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            [self.wkWebView reloadFromOrigin];
        }
            break;
        default:
            break;
    }
}

- (void)stopLoading {
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            [self.uiWebView stopLoading];
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            [self.wkWebView stopLoading];
        }
            break;
        default:
            break;
    }
}

- (void)goBack {
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            [self.uiWebView goBack];
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            [self.wkWebView goBack];
        }
            break;
        default:
            break;
    }
}

- (void)goForward {
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            [self.uiWebView goForward];
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            [self.wkWebView goForward];
        }
            break;
        default:
            break;
    }
}

- (void)evaluateJavaScript:(NSString *)javaScriptString completionHandler:(void (^)(id completion, NSError * error))completionHandler {
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            NSString *compString = [self.uiWebView stringByEvaluatingJavaScriptFromString:javaScriptString];
            if (completionHandler) {
                NSError *err = nil;
                if (!compString) {
                    err = [NSError errorWithDomain:NSStringFromClass([self class]) code:-1 userInfo:@{NSLocalizedDescriptionKey : @"执行JS语句失败"}];
                }
                completionHandler(compString, err);
            }
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            [self.wkWebView evaluateJavaScript:javaScriptString completionHandler:completionHandler];
        }
            break;
        default:
            break;
    }
}

- (void)clearWebCache:(void (^)())finished {
    switch (self.webViewType) {
        case AEWebViewContainTypeUIWebView:
        {
            [[NSURLCache sharedURLCache] removeAllCachedResponses];
            if (finished) {
                finished();
            }
        }
            break;
        case AEWebViewContainTypeWKWebView:
        {
            if (![[[UIDevice currentDevice] systemVersion] hasPrefix:@"8."]) {
                if (finished) {
                    [self.wkWebView.configuration.websiteDataStore removeDataOfTypes:[WKWebsiteDataStore allWebsiteDataTypes] modifiedSince:[NSDate dateWithTimeIntervalSince1970:0] completionHandler:finished];
                } else {
                    [self.wkWebView.configuration.websiteDataStore removeDataOfTypes:[WKWebsiteDataStore allWebsiteDataTypes] modifiedSince:[NSDate dateWithTimeIntervalSince1970:0] completionHandler:^{
                        
                    }];
                }
            }
        }
            break;
        default:
        {
            if (finished) {
                finished();
            }
        }
            break;
    }
}

- (void)setupCustomUserAgent:(NSString *)cUA completionHandler:(void (^)(NSString *))completionHandler {
    if (self.webViewType == AEWebViewContainTypeWKWebView) {
        __weak typeof(self) weakSelf = self;
        [weakSelf.wkWebView evaluateJavaScript:@"navigator.userAgent" completionHandler:^(id completion, NSError * error) {
            if (!error) {
                __strong typeof(weakSelf) strongSelf = weakSelf;
                NSString *userAgent = completion;
                
                NSUInteger extLocation = [userAgent rangeOfString:cUA].location;
                if (extLocation != NSNotFound && extLocation > 1) {
                    //发现已设置cUA，则清空设置的cUA，并设置WK的（包括一个空格）
                    userAgent = [userAgent substringToIndex:extLocation - 1];
                }
                
                userAgent = [NSString stringWithFormat:@"%@ %@/WK", userAgent, cUA];
                
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_9_0
                strongSelf.wkWebView.customUserAgent = userAgent;
#else
                [strongSelf.wkWebView setValue:userAgent forKey:@"applicationNameForUserAgent"];
#endif
                if (completionHandler) {
                    completionHandler(userAgent);
                }
            }
        }];
    } else {
        UIWebView *webView = [[UIWebView alloc] initWithFrame:CGRectZero];
        NSString *userAgent = [webView stringByEvaluatingJavaScriptFromString:@"navigator.userAgent"];
        NSUInteger extLocation = [userAgent rangeOfString:cUA].location;
        if (extLocation != NSNotFound && extLocation > 1) {
            //发现已设置cUA，则清空设置的cUA，并设置UI的（包括一个空格）
            userAgent = [userAgent substringToIndex:extLocation - 1];
        }
        
        userAgent = [NSString stringWithFormat:@"%@ %@/UI", userAgent, cUA];
        NSDictionary *dictionnary = [[NSDictionary alloc] initWithObjectsAndKeys:userAgent, @"UserAgent", nil];
        [[NSUserDefaults standardUserDefaults] registerDefaults:dictionnary];
        if (completionHandler) {
            completionHandler(userAgent);
        }
    }
}

@end




