//
//  NWPolicyViewer.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 2017/2/9.
//  Copyright © 2017年 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NWUserPolicy.h"

/**
 * 异步查询策略的数据返回回调。
 *
 * @param host: 查询的域名
 * @param ailses: 返回的通道列表，如果没有查询到，则返回nil.
 */
@protocol NWPolicyViewerDelegate <NSObject>

- (void)host:(nonnull NSString *)host withAisles:(nullable NSArray<NWAisle*> *)aisles;

@end



/**
 * 根据host查询策略接口
 */
@interface NWPolicyViewer : NSObject

/**
 * 设置AMDC的兜底IP。
 *
 * @param ips 兜底IP列表
 */
+ (void)setAmdcBuiltinIps:(nonnull NSArray<NSString*> *)ips;

/**
 * 获取AMDC的兜底IP。
 */
+ (nullable NSArray<NSString*> *)amdcBuiltinIps;


/**
 * 异步查询策略策略接口。
 *
 * @param host: 目标host
 * @param delegate: 异步返回数据的回调
 */
+ (void)asyncQueryHost:(nonnull NSString *)host withDelegate:(nonnull id<NWPolicyViewerDelegate>)delegate;


/**
 * 同步查询策略策略接口。若本地没有策略，则会触发异步AMDC请求。
 *
 * @param host: 目标host
 * @return 返回当前host的所有可用通道列表
 */
+ (nullable NSArray<NWAisle*> *)queryHostAisles:(nonnull NSString *)host;


/**
 * 同步查询策略策略接口。若本地没有策略，则会触发异步AMDC请求。
 *
 * @param host: 目标host
 * @return 返回当前host的第一个可用通道
 */
+ (nullable NWAisle *)queryHostAisle:(nonnull NSString *)host;


/**
 * 同步查询策略策略接口。若本地没有策略，则会触发异步AMDC请求。
 *
 * @param host: 目标host
 * @return 返回当前host的第一个可用IP
 */
+ (nullable NSString *)queryHostIP:(nonnull NSString *)host;

@end
