//
//  NWPolicyDefine.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 4/26/16.
//  Copyright © 2016 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

/**
 * 通道状态
 */
typedef enum {
    kNWAisleNonexecution,                                           // 为执行，初始状态
    kNWAisleConnectSuccess,                                         // 建连成功
    kNWAisleConnectFail,                                            // 建连失败
    kNWAisleAuthFail,                                               // 鉴权失败
    kNWAisleServiceFail                                             // 业务层失败，返回5xx
} NWAisleStatus;





/**
 * 策略类型
 */
typedef enum {
    kNWAislePolicy,                                                 // 直接指定通道的策略
    kNWCnamePolicy                                                  // 通过cname来引用其他策略通道的策略
} NWPolicyType;





/**
 * 通道接口。 通道属于策略的主要子元素，一个策略包含多个通道。
 * 策略的定义请参考: IPolicy
 */
@interface NWAisle : NSObject
@property (nonatomic, strong) NSString          *publickey;         // 公钥
@property (nonatomic, strong) NSString          *protocol;          // 协议类型
@property (nonatomic, strong) NSString          *ip;                // ip
@property (nonatomic, assign) NSUInteger        port;               // port
@property (nonatomic, assign) BOOL              encrypt;            // 是否加密
@property (nonatomic, assign) BOOL              auth;               // 是否鉴权
@end





/**
 * 策略接口。策略中主要元素即是通道：IAisle
 * 备注：若type = kNWAislePolicy，需要实现aisles
 *      若type = kNWCnamePolicy，需要实现cname参数即可
 */
@interface NWPolicy : NSObject
@property (nonatomic, assign) NWPolicyType                    type;              // 策略类型
@property (nonatomic, assign, nonnull)  NSString              *host;             // 域名
@property (nonatomic, strong, nullable) NSArray<NWAisle *>    *aisles;           // 通道列表
@property (nonatomic, strong, nullable) NSString              *cname;            // 通过cname其他策略的host来定义策略内容
@end





/**
 * 策略中心接口。
 * 外部应用可以通过注册该策略中心接口，来实现策略的动态注入。
 */
@protocol NWPolicyDelegate <NSObject>



/**
 * 查询策略接口。
 * 根据 host 和 scheme 查询策略。
 *
 * @param host 目标host
 * @param scheme 请求scheme
 * @param acceleration 是否加速策略，加速策略定义: spdy, http2 等长连协议定义为加速策略，置为YES; http, https 等短连协议定义为非加速策略，置为NO.
 * @param success session在建联过程中，可以使用历史状态做优化，指示策略是否应该包含成功通道。该参数外部实现可以自己决定是否支持。
 *
 * @return NWPolicy*, 若没有针对改scheme://host 的策略，则可以返回nil
 */
- (nullable NWPolicy *)queryPolicy:(nonnull NSString *)host
                        withScheme:(nonnull NSString *)scheme
                  withAcceleration:(BOOL)acceleration
                  withSuccessAisle:(BOOL)success;



/**
 * 查询域名scheme。
 * 
 * @param host 目标host
 * @return NSString*: 该host对应的scheme, 如果没有则返回nil.
 */
- (nullable NSString *)queryScheme:(nonnull NSString *)host;




/**
 * 查询域名cname。
 *
 * @param host 目标host
 * @return NSString*: 该host对应的cname, 如果没有则返回原host.
 */
- (nonnull NSString *)queryCname:(nonnull NSString *)host;




/**
 * 更新策略状态。
 * 根据测量的执行结果，更新策略库，外部实现可以根据该回调来优化自己的策略库。
 */
- (void)updateAisleStatus:(nonnull NWAisle *)aisle withHost:(NSString*)host withStatus:(NWAisleStatus)status;



/**
 * 查询所有策略
 */
- (nullable NWPolicy *)queryPolicy:(nonnull NSString *)host;

@end



NS_ASSUME_NONNULL_END
