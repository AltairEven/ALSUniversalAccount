//
//  AEJavaScriptHandler.m
//  TestWebViewContainer
//
//  Created by Altair on 12/06/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import "AEJavaScriptHandler.h"
#import <JavaScriptCore/JavaScriptCore.h>

@interface AEJavaScriptHandler ()

@property (nonatomic, copy) AEJSHandledWebView suitableWebView;

@property (nonatomic, strong) JSContext *uiWebViewJSContext;

- (void)removeWKScriptMessageHandler;

- (BOOL)responseToJSCallWithFullfillContext:(AEJSHandlerContext *)context;

@end

@implementation AEJavaScriptHandler

#pragma mark Initialization

+ (instancetype)defaultHandlerWithWebView:(AEJSHandledWebView)webView {
    AEJavaScriptHandler *handler = [[AEJavaScriptHandler alloc] init];
    [handler setAEJSHandledWebView:webView];
    return handler;
}

- (UIView *)webview {
    if (self.suitableWebView) {
        __weak typeof(self) weakSelf = self;
        return self.suitableWebView(weakSelf);
    }
    return nil;
}

#pragma mark Setter & Getter

- (void)setJsContexts:(NSSet<AEJSHandlerContext *> *)jsContexts {
    _jsContexts = [jsContexts copy];
    
    //注册JS
    if ([self.webview isKindOfClass:[WKWebView class]]) {
        WKWebView *wkWebView = (WKWebView *)self.webview;
        //WKWebView
        WeakScriptMessageDelegate *delegate = [[WeakScriptMessageDelegate alloc] initWithDelegate:self];
        if (delegate) {
            for (AEJSHandlerContext *jsContext in self.jsContexts) {
                if ([jsContext.aliasName length] > 0) {
                    [wkWebView.configuration.userContentController addScriptMessageHandler:delegate name:jsContext.aliasName];
                } else if (jsContext.selector) {
                    [wkWebView.configuration.userContentController addScriptMessageHandler:delegate name:NSStringFromSelector(jsContext.selector)];
                }
            }
        }
    } else if ([self.webview isKindOfClass:[UIWebView class]]) {
        UIWebView *uiWebView = (UIWebView *)self.webview;
        //UIWebView
        self.uiWebViewJSContext = [uiWebView valueForKeyPath:@"documentView.webView.mainFrame.javaScriptContext"];
        //打印异常
        self.uiWebViewJSContext.exceptionHandler = ^(JSContext *context, JSValue *exceptionValue) {
            context.exception = exceptionValue;
            NSLog(@"%@", exceptionValue);
        };
        __weak typeof(self) weakSelf = self;
        [weakSelf.jsContexts enumerateObjectsUsingBlock:^(AEJSHandlerContext *obj, BOOL * stop) {
            NSString *methodName = obj.aliasName;
            if ([methodName length] == 0) {
                methodName = NSStringFromSelector(obj.selector);
            }
            if ([methodName length] > 0) {
                weakSelf.uiWebViewJSContext[methodName] = ^ {
                    __strong typeof(weakSelf) strongSelf = weakSelf;
                    AEJSHandlerContext *context = [obj copy];
                    //提取参数
                    NSArray *args = [JSContext currentArguments];
                    if ([args count] == 1) {
                        context.args = [[args firstObject] toObject];
                    } else {
                        NSMutableArray *temp = [[NSMutableArray alloc] init];
                        for (JSValue *value in args) {
                            id argObj = [value toObject];
                            if (argObj) {
                                [temp addObject:argObj];
                            }
                        }
                        if ([temp count] == 1) {
                            context.args = [temp firstObject];
                        } else {
                            context.args = [temp copy];
                        }
                    }
                    //主线程调用
                    dispatch_async(dispatch_get_main_queue(), ^{
                        [strongSelf responseToJSCallWithFullfillContext:context];
                    });
                    
                };
            }
        }];
    }
}

#pragma mark WKScriptMessageHandler

- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message {
    [self responseToJSCallWithScriptMessage:message];
}

#pragma mark Super methods

- (void)dealloc {
    [self removeWKScriptMessageHandler];
}

#pragma mark Private methods

- (void)removeWKScriptMessageHandler {
    if ([self.webview isKindOfClass:[WKWebView class]]) {
        WKWebView *wkWebView = (WKWebView *)self.webview;
        for (AEJSHandlerContext *jsContext in self.jsContexts) {
            if ([jsContext.aliasName length] > 0) {
                [[wkWebView configuration].userContentController removeScriptMessageHandlerForName:jsContext.aliasName];
            } else if (jsContext.selector) {
                [[wkWebView configuration].userContentController removeScriptMessageHandlerForName:NSStringFromSelector(jsContext.selector)];
            }
        }
    }
}

- (BOOL)responseToJSCallWithFullfillContext:(AEJSHandlerContext *)context {
    if (!context) {
        return NO;
    }
    NSLog(@"%s", __FUNCTION__);
    NSLog(@"JS 调用了 %@ 方法，传回参数 %@", NSStringFromSelector(context.selector), context.args);
    if (!context.selector) {
        return NO;
    }
    if ([context.instanceOrClass respondsToSelector:context.selector]) {
        [context.instanceOrClass performSelector:context.selector withObject:context.args afterDelay:0];
        return YES;
    }
    return NO;
}

#pragma mark Public methods

- (void)setAEJSHandledWebView:(AEJSHandledWebView)webView {
    BOOL needReset = (webView != self.suitableWebView);
    self.suitableWebView = webView;
    if (needReset) {
        [self setJsContexts:self.jsContexts];
    }
}

- (BOOL)responseToJSCallWithScriptMessage:(WKScriptMessage *)message {
    AEJSHandlerContext *fullFillContext = nil;
    for (AEJSHandlerContext *context in self.jsContexts) {
        if ([context.aliasName isEqualToString:message.name] || [message.name isEqualToString:NSStringFromSelector(context.selector)]) {
            fullFillContext = [context copy];
            fullFillContext.args = message.body;
            break;
        }
    }
    return [self responseToJSCallWithFullfillContext:fullFillContext];
}

@end




@implementation AEJSHandlerContext

- (void)setAliasName:(NSString *)aliasName {
    if ([aliasName isKindOfClass:[NSString class]]) {
        _aliasName = aliasName;
    }
}

+ (instancetype)contextWithInstanceOrClass:(id)instanceOrClass selector:(SEL)selector aliasName:(NSString *)aliasName {
    if (!instanceOrClass || !selector) {
        return nil;
    }
    AEJSHandlerContext *context = [[AEJSHandlerContext alloc] init];
    context.instanceOrClass = instanceOrClass;
    context.selector = selector;
    context.aliasName = aliasName;
    return context;
}

#pragma mark NSCopying

- (id)copyWithZone:(nullable NSZone *)zone {
    AEJSHandlerContext *context = [[AEJSHandlerContext allocWithZone:zone] init];
    context.instanceOrClass = self.instanceOrClass;
    context.selector = self.selector;
    context.args = self.args;
    context.aliasName = self.aliasName;
    return context;
}

@end



@implementation WeakScriptMessageDelegate

- (instancetype)initWithDelegate:(id<WKScriptMessageHandler>)scriptDelegate {
    self = [super init];
    if (self) {
        _scriptDelegate = scriptDelegate;
    }
    return self;
}

- (void)userContentController:(WKUserContentController *)userContentController didReceiveScriptMessage:(WKScriptMessage *)message {
    [self.scriptDelegate userContentController:userContentController didReceiveScriptMessage:message];
}

@end
