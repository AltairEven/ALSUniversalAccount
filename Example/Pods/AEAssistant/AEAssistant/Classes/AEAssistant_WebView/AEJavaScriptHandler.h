//
//  AEJavaScriptHandler.h
//  TestWebViewContainer
//
//  Created by Altair on 12/06/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>

@class AEJSHandlerContext;
@class AEJavaScriptHandler;

#pragma mark AEJavaScriptHandler

typedef UIView *(^AEJSHandledWebView)(AEJavaScriptHandler *jsHandler);

@interface AEJavaScriptHandler : NSObject <WKScriptMessageHandler>

@property (nonatomic, weak, readonly) UIView *webview;   //弱引用的webview实例，必须是UIWebView或者WKWebView对象

@property (nonatomic, copy) NSSet<AEJSHandlerContext *> *jsContexts;    //当前handle的context对象集合。调用setter方法后，即会注册对应的native方法。注1：对于WKWebView，建议在load之前就设置；而UIWebView，建议在finishLoad时设置。注2：如果不同的instanceOrClass定义了相同的selector，则在找到第一个可处理的instanceOrClass后，会停止遍历。

/**
 便捷生成JSHandler的方法
 
 @param webView 当前负责处理JS事务的webview
 @return JSHandler的类实例
 */
+ (instancetype)defaultHandlerWithWebView:(AEJSHandledWebView)webView;

/**
 设置当前负责处理JS事务的webview

 @param webView 当前负责处理JS事务的webview
 */
- (void)setAEJSHandledWebView:(AEJSHandledWebView)webView;

/**
 响应JS调用的方法，该方法被主动调起后，会执行相关的本地操作，从而自动执行jsContext中对应的native方法

 @param message WebKit中定义的script消息对象
 @return 是否找到对应的native方法并执行
 */
- (BOOL)responseToJSCallWithScriptMessage:(WKScriptMessage *)message;

@end

#pragma mark AEJSHandlerContext

@interface AEJSHandlerContext : NSObject <NSCopying>

@property (nonatomic, strong) id instanceOrClass;   //类实例或者类。根据实际执行SEL的类型来赋值。必填

@property (nonatomic, assign) SEL selector; //调用的Native方法。如果是实例方法，则instanceOrClass需赋值实例，如果是类方法，则instanceOrClass需赋值类。必填

@property (nonatomic, strong) id args;  //执行该Native方法的参数。在JSHandler捕获到时，传入到对应instanceOrClass执行的selector中

@property (nonatomic, copy) NSString *aliasName;    //context别名。由于selector有无参数的时候转化的string值不一样，所以会优先使用别名来注册JS调用的方法，如果别名没有赋值，则使用selector来注册。

/**
 便捷生成context对象的方法

 @param instanceOrClass 类实例或者类
 @param selector 调用的native方法
 @return context对象实例
 */
+ (instancetype)contextWithInstanceOrClass:(id)instanceOrClass selector:(SEL)selector aliasName:(NSString *)aliasName;

@end

#pragma mark WeakScriptMessageDelegate

/**
 弱引用的消息代理，用于WKWebView
 */
@interface WeakScriptMessageDelegate : NSObject <WKScriptMessageHandler>

@property (nonatomic, weak) id<WKScriptMessageHandler> scriptDelegate;

- (instancetype)initWithDelegate:(id<WKScriptMessageHandler>)scriptDelegate;

@end
