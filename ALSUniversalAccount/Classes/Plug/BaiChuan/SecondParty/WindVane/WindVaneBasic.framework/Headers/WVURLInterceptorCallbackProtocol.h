/*
 * WVURLInterceptorCallbackProtocol.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

@protocol WVURLInterceptorCallbackProtocol <NSObject>

@required

/**
 [已废弃] URL 拦截的回调会在 shouldStartLoadWithRequest 回调返回 YES 之后调用。
 实际使用中与 shouldStartLoadWithRequest 比较容易混淆，因此总是建议在 shouldStartLoadWithRequest 回调中增加自己的逻辑，这里的 URL 拦截规则也不再更新。
 */
- (BOOL)interruptJumpToLocalPage:(NSInteger)target withParam:(NSDictionary *)params withRequest:(NSURLRequest *)request;

@end
