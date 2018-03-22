//
//  ALSUAPlugProtocal.h
//  Public
//
//  Created by Altair on 20/12/2017.
//  Copyright © 2017 Altair. All rights reserved.
//

#ifndef ALSUAPlugProtocal_h
#define ALSUAPlugProtocal_h


#endif /* ALSUAPlugProtocal_h */

#import "ALSUAPlugMode.h"
#import "ALSUAResponse.h"

typedef enum {
    ALSUABuiltInPlugStrategyNone = 0,
    ALSUABuiltInPlugStrategyAutoLogin       = 1 << 0,
    ALSUABuiltInPlugStrategyBindMobile      = 1 << 1,
    ALSUABuiltInPlugStrategySetPassword     = 1 << 2,
    ALSUABuiltInPlugStrategyBaichuanLogin   = 1 << 3,
    ALSUABuiltInPlugStrategyAll             = (1 << 4) - 1
}ALSUABuiltInPlugStrategy;

/**
 账户操作插件需要遵循的协议
 */
@protocol ALSUAPlugProtocal <NSObject>

@required

/**
 获取是否在线，即是否启动成功
 
 @return 是否在线
 */
- (BOOL)isOnLine;

/**
 获取账户插件模式
 
 @return 插件模式
 */
- (ALSUAPlugMode *)plugMode;

/**
 开始账户操作
 
 @param mode 账户操作请求
 @param delegate 账户操作请求的代理
 @param response 账户操作返回
 @return 是否开始操作成功，非操作结果
 */
- (BOOL)startAccountOperation:(ALSUAOperationMode *)mode withDelegate:(id)delegate response:(void(^)(ALSUAResponse *response))response;

@optional

/**
 启动账户操作插件
 
 @param delegate 账户操作插件启动所需信息的代理
 @return 启动是否成功
 */
- (BOOL)getOnlineWithOperationDelegate:(id)delegate;

/**
 停止账户操作
 
 @return 是否停止成功
 */
- (BOOL)stopOperation;

/**
 登出
 
 @return 登出操作成功或失败
 */
- (BOOL)logout;

/**
 是否可以处理跳转账户操作返回事件
 
 @param url 入参URL
 @return 是否可处理
 */
- (BOOL)respondsToOpenUrl:(NSURL *)url;

/**
 处理跳转账户操作返回的事件信息
 
 @param app UIApplication对象，可直接透传系统的值
 @param url 入参URL
 @param options 相关参数
 @return 处理成功或失败
 */
- (BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

@end
