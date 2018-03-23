/*
 * WVJSBridgeCallbackDelegate.h
 * 
 * Created by WindVane.
 * Copyright (c) 2017年 阿里巴巴-淘宝技术部. All rights reserved.
 */

#import <Foundation/Foundation.h>

// 不再建议使用，为了旧版本过渡，目前只支持事件，其它回调不再支持
@protocol WVJSBridgeCallbackDelegate <NSObject>

@required

/**
 * 发送事件的回调。
 */
- (void)onFireEvent:(NSString *)eventName withParam:(NSDictionary *)param;

@end
