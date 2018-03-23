//
//  ALSUASocket.h
//  wesg
//
//  Created by Altair on 22/02/2017.
//  Copyright © 2017 AliSports. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AlisportsUniversalAccountPublic/AlisportsUniversalAccountPublic.h>

/**
 账户操作插座
 */
@interface ALSUASocket : NSObject

@property (nonatomic, strong, readonly) NSSet<id<ALSUAPlugProtocal>> *plugsInSocket; //插座中已插入的插件

@property (nonatomic, readonly) ALSUABuiltInPlugStrategy plugStrategy;  //插件策略

/**
 账户操作插座单实例方法

 @return 类实例
 */
+ (instancetype)publicSocket;

/**
 插入内建插件
 
 @param strategy 插件策略
 */
- (void)plugInBuiltInPlugs:(ALSUABuiltInPlugStrategy)strategy;

/**
 插入插件

 @param plug 被插入的插件
 */
- (void)plugIn:(id<ALSUAPlugProtocal>)plug;

/**
 拔出插件

 @param mode 被拔出插件的账户操作模式
 */
- (void)plugOutWithMode:(ALSUAPlugMode *)mode;

/**
 获取对应账户操作模式的已插入插件

 @param mode 账户操作模式
 @return 对应账户操作模式的已插入插件
 */
- (id<ALSUAPlugProtocal>)plugWithMode:(ALSUAPlugMode *)mode;

/**
 获取包含对应账户操作模式的已插入插件
 
 @param mode 账户操作模式
 @return 对应账户操作模式的已插入插件
 */
- (id<ALSUAPlugProtocal>)plugSupportedOperationWithMode:(ALSUAOperationMode *)mode;

/**
 将对应账户操作模式的已插入插件启动

 @param mode 账户操作模式
 @param delegate 账户操作代理
 @return 是否启动成功
 */
- (BOOL)getOnlineForPlugWithMode:(ALSUAPlugMode *)mode withDelegate:(id)delegate;

/**
 将所有已插入的插件启动

 @param delegate 账户操作代理
 @param result 是否启动成功，resultInfo的key是账户操作模式，value是BOOL类型的启动成功标识
 */
- (void)getAllPlugsOnlineWithDelegate:(id)delegate response:(void(^)(NSDictionary<ALSUAPlugMode *, NSNumber *> *resultInfo))result;

/**
 获取可处理跳转账户操作返回的事件信息的账户操作SDK
 
 @param app UIApplication对象，可直接透传系统的值
 @param url 入参URL
 @param options 相关参数
 @return 能处理该信息的账户操作SDK
 */
- (id<ALSUAPlugProtocal>)respondingPlugForApplication:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey, id> *)options;

@end
