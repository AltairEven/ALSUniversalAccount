/*
 * WVURLInterceptorRuleService.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import "WVURLInterceptorRuleObj.h"
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 整个 WVURLInterceptor 不再建议使用，请直接在 WindVaneDelegate 的 webView:shouldStartLoadWithRequest:navigationType: 回调中自行处理 URL 拦截。
 预计与 2019.1.1 删除
 */

#pragma mark -WVURLInterceptorRuleHandlerProtocol-

/*!
 * URL拦截服务处理器需要实现的协议
 */
@protocol WVURLInterceptorRuleHandlerProtocol <NSObject>

@required

/*
 * 获取URL拦截规则
 *
 * 返回结构类型：see @WVURLInterceptorRuleObj.h
 */
- (NSArray *)getURLInterceptorRule DEPRECATED_ATTRIBUTE;

/*
 * 是否开启URL拦截规则
 */
- (BOOL)isOpenURLInterceptor DEPRECATED_ATTRIBUTE;

@end

#pragma mark -WVURLInterceptorRuleService-

/*!
 * URL拦截规则处理器相关的服务
 */
@interface WVURLInterceptorRuleService : NSObject

/*
 * 注册URL拦截解析模块的规则处理器
 *
 * @urlInterceptorRuleHandler:URL拦截规则处理器
 */
+ (void)registeURLInterceptorRuleHandler:(id<WVURLInterceptorRuleHandlerProtocol>)urlInterceptorRuleHandler DEPRECATED_ATTRIBUTE;

/*
 * 获取注册的URL拦截解析模块的规则处理器
 *
 * @return:URL拦截解析规则处理器
 */
+ (id<WVURLInterceptorRuleHandlerProtocol>)registedURLInterceptorRuleHandler DEPRECATED_ATTRIBUTE;

/*
 * 是否已经注册过URL拦截解析模块的处理器
 */
+ (BOOL)isRegistedURLInterceptorRuleHandler DEPRECATED_ATTRIBUTE;

@end
