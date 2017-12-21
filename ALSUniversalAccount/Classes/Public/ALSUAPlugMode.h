//
//  ALSUAPlugMode.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 13/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ALSUAOperationMode.h"

/**
 账户插件模式
 */

@interface ALSUAPlugMode : NSObject <NSCopying>

@property (nonatomic, copy, readonly) NSString *name; //模式名称

@property (nonatomic, readonly) ALSUniveraslAccountOperationType supportOperationType; //账号操作类型

/**
 初始化账户插件模式的方法
 
 @param name 模式名称
 @param type 支持的操作类型
 @return 类实例
 */
- (instancetype)initWithName:(NSString *)name supportOperationType:(ALSUniveraslAccountOperationType)type;

/**
 便捷创建账户插件模式实例的方法
 
 @param name 模式名称
 @param type 支持的操作类型
 @return 类实例
 */
+ (instancetype)modeWithName:(NSString *)name supportOperationType:(ALSUniveraslAccountOperationType)type;

/**
 判断和另一个账户插件模式是否相同
 
 @param mode 另一个账户插件模式
 @return 是否相同
 */
- (BOOL)isEqualToMode:(ALSUAPlugMode *)mode;

/**
 判断是否支持指定的账户操作模式
 
 @param mode 账户操作模式
 @return 是否支持
 */
- (BOOL)supportOperationMode:(ALSUAOperationMode *)mode;

/**
 判断是否支持指定的操作类型
 
 @param type 操作类型
 @return 是否支持
 */
- (BOOL)supportOperationType:(ALSUniveraslAccountOperationType)type;

@end

@interface ALSUALoginPlugMode : ALSUAPlugMode

@property (nonatomic, assign) BOOL needExchangeLoginResponseFromAccountCenter; //是否需要从账户中心刷新登录返回结果，默认YES

@end
