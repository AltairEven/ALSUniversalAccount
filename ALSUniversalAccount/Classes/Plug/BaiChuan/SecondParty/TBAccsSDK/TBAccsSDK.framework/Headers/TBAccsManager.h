//:::'###:::::'######:::'######:::'######::
//::'## ##:::'##... ##:'##... ##:'##... ##:
//:'##:. ##:: ##:::..:: ##:::..:: ##:::..::
//'##:::. ##: ##::::::: ##:::::::. ######::
// #########: ##::::::: ##::::::::..... ##:
// ##.... ##: ##::: ##: ##::: ##:'##::: ##:
// ##:::: ##:. ######::. ######::. ######::
//..:::::..:::......::::......::::......:::
//
//  TBAccsManager.h
//  TBAccsSDK
//
//  Created by 亿刀 on 15/3/23.
//  Copyright (c) 2015年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import <TBAccsSDK/TBAccsVariable.h>
#import <TBAccsSDK/AccsProtocol.h>
#import <TBAccsSDK/TBAccsRequestContext.h>

NS_ASSUME_NONNULL_BEGIN

UIKIT_EXTERN NSString *const kAccsSDKOperationTypeNotification;

#define k_Accs_Aisle_OK @"k_Accs_Aisle_OK"
#define k_Accs_Aisle_NO @"k_Accs_Aisle_NO"

#define ACCS_PUBKEY_SEQ_CDN    1      //EASY_CONNECT_SSSL_CDN_SEQNUM
#define ACCS_PUBKEY_PSEQ_CDN   1      //cdn去黑匣子使用相同的公钥
#define ACCS_PUBKEY_SEQ_ACCS   3      //EASY_CONNECT_SSSL_ACCS_SEQNUM
#define ACCS_PUBKEY_PSEQ_ACCS  4      //对应aserver明文公钥
#define ACCS_PUBKEY_SEQ_TEST   0      //EASY_CONNECT_SSSL_TEST_SEQNUM
#define ACCS_PUBKEY_SEQ_AE     5      //for AE
#define ACCS_PUBKEY_SEQ_ARUP   6      //for arup
#define ACCS_PUBKEY_PSEQ_ARUP  7      //for arup plaintext
#define ACCS_PUBKEY_SEQ_ADASH  8      //for adash
#define ACCS_PUBKEY_PSEQ_ADASH 9      //for adash plaintext
#define ACCS_PUBKEY_SEQ_OPEN   10     //for 第三方
#define ACCS_PUBKEY_PSEQ_OPEN  11     //for 第三方 plaintext
#define ACCS_PUBKEY_PSEQ_EMAS  12     // for EMAS

@class TBAccsReceiveAndCallBackCenter;
@class TBAccsRequestQueue;
@class TBAccsConfiguration;

@interface TBAccsManager : NSObject<AccsProtocol>

//当前acc是否可以发送请求，no，不能发起，yes，可以发起.
@property (nonatomic, assign, readonly) BOOL                                    canRequest;
@property (nonatomic, strong, readonly) TBAccsReceiveAndCallBackCenter          *accsReceiveAndCallBackCenter;
@property (nonatomic, strong, readonly) TBAccsRequestQueue                      *accsRequestQueue;
@property (nonatomic, strong, readonly) NSString                                *host;
@property (nonatomic, strong, readonly) TBAccsConfiguration                     *configuration;
@property (nonatomic, assign) BOOL supportLocalDNS;
@property (nonatomic, assign) BOOL userCustomHost;
@property (nonatomic, assign) int  slightSslPublicKeySeq;


/**
 * 自定义中心域名
 */
+ (void)setCenterHost:(nonnull NSString *)host;


/**
 * 获取当前默认 ACCS Host
 */
+ (nullable NSString *)currentDefaultAccsHost;

/**
 *  获取中心长连接操作对象
 */
+ (TBAccsManager *)centerAccsManager;


/**
 *  获取长连接操作对象，操作单元的时候调用此方法
 *
 *  @param  host   单元化对应的host
 */
+ (TBAccsManager *)accsManagerByHost:(nonnull NSString *)host;

/**
 * 静态注册下行消息callback. 注意：该注册方式与info.plist中注册相互冲突，因兼容性以及避免对已有业务的干扰，若
 * info.plist 中已经注册某serviceId对应的callback,  则该注册忽略，以info.plist中注册信息为准。
 *
 * @param serviceId 注册的service id
 * @param classname 注册的callback类名，该 callback 需实现 TBAccsCallbackProtocol 接口
 */
+ (void)registerNotificationCallback:(nonnull NSString *)serviceId withClassName:(nonnull NSString *)classname;



/**
 * 静态 bind service.
 * 1) 若调用该函数时，AccsManager 实例已经初始化成功，则立即执行；
 * 2) 若调用该函数时，AccsManager 实例并未初始化成功，则待实例初始化完成后，再执行bind动作
 */
+ (void)bindServiceWithId:(NSString *)serviceId
                 callBack:(TBAccsManagerResponseBlock)resultsBlock
        receviceDataBlock:(TBAccsManagerResponseBlock)receviceDataBlock;

    
/**
 *  启动ACCS实例
 */
- (void)startAccs;



/**
 *  传递callback到sdk
 *
 *  @param serviceId    业务id
 *  @param resultsBlock 绑定是否成功的回调
 *  @param receviceDataBlock 收到数据后的回调
 */
- (void)bindServiceWithServiceId:(nonnull NSString *)serviceId
                        callBack:(nullable TBAccsManagerResponseBlock)resultsBlock
               receviceDataBlock:(nonnull TBAccsManagerResponseBlock)receviceDataBlock;



- (void)bindServiceWithServiceId:(nonnull NSString *)serviceId
                        callBack:(nullable TBAccsManagerResponseBlock)callBack
               receviceDataBlock:(nonnull TBAccsManagerResponseBlock)receviceDataBlock
                             syn:(BOOL)syn;

/**
 *  发送绑定请求到服务端，
 *  注意：多数业务无需调用此接口
 *
 *  @param serviceId    业务id
 *  @param resultsBlock 绑定是否成功的回调
 *  @param receviceDataBlock 收到数据后的回调
 */
- (void)serverRealBindServiceID:(nonnull NSString *)serviceId
                       callBack:(nullable TBAccsManagerResponseBlock)resultsBlock;

/**
 *  将serviceID对应的callback置空，在没有重启app前，accsdk会忽略serviceID的下行消息，不产生任何serviceID对应的回调
 *
 *  注意：调用此接口需要谨慎
 *
 *  @param serviceId    业务id
 *  @param resultsBlock 请求响应回调
 */
- (void)unbindServiceWithServiceId:(nonnull NSString *)serviceId
                          callBack:(nullable TBAccsManagerResponseBlock)callBack;
/**
 * 服务端将serviceID和这台iOS设备真正解绑，在没有重新调用
 *      - (void)serverRealBindServiceID:(NSString *)serviceId
 *                             callBack:(TBAccsManagerResponseBlock)resultsBlock
 *                    receviceDataBlock:(TBAccsManagerResponseBlock)receviceDataBlock;
 * 接口前，此设备都不会接收到serviceID对应的消息
 *
 * 注意：此接口请谨慎调用。调用场景这里举例： 业务开发者希望当用户退出登录后，就不能接收serviceID为test的消息，这样可以调用此接口
 * 注意：调用此接口需要谨慎
 *
 *  @param serviceId    业务id
 *  @param resultsBlock 请求响应回调
 */
- (void)serverRealUNBindServiceID:(nonnull NSString *)serviceId
                         callBack:(nullable TBAccsManagerResponseBlock)callBack;

/**
 *  发送Request
 *
 *  @param data             发送的数据
 *  @param serviceId        业务id
 *  @param userId           用户id,可选，如果没有，填空即可
 *  @param routID           路由标示，没有特殊用处，请传入nil
 *  @param resultsBlock     请求响应回调
 *  @param otherParameters  扩展字段，暂时传入nil
 *
 *  @return 返回dataId，如果返回dataid为nil，说明发送失败。但dataid不为空不代表发送成功
 *  @note 大小限制为16k
 */
- (NSString *)sendRequestWithData:(nonnull NSData *)data
                        serviceId:(nonnull NSString *)serviceId
                           userId:(nullable NSString *)userId
                           routID:(nullable NSString *)routID
                  otherParameters:(nullable NSDictionary *)otherParameters
                         callBack:(nullable TBAccsManagerResponseBlock)callBack;


/**
 *  发送Request
 *
 *  @param data             发送的数据
 *  @param serviceId        业务id
 *  @param userId           用户id,可选，如果没有，填空即可
 *  @param routID           路由标示，没有特殊用处，请传入nil
 *  @param resultsBlock     请求响应回调
 *  @param otherParameters  扩展字段，暂时传入nil
 *  @param returnError      本地错误
 *
 *  @return 返回dataId
 *  @note 大小限制为16k
 */
- (NSString *)sendRequestWithData:(nonnull NSData *)data
                        serviceId:(nonnull NSString *)serviceId
                           userId:(nullable NSString *)userId
                           routID:(nullable NSString *)routID
                  otherParameters:(nullable NSDictionary *)otherParameters
                         callBack:(nullable TBAccsManagerResponseBlock)callBack
                            error:(NSError **)returnError;


/**
 *  发送Request
 *
 *  @param data             发送的数据
 *  @param serviceId        业务id
 *  @param userId           用户id,可选，如果没有，填空即可
 *  @param routID           路由标示，没有特殊用处，请传入nil
 *  @param timeout          超时时间
 *  @param callBack         请求响应回调
 *
 *  @return 返回dataId
 *  @note 大小限制为16k
 */
- (NSString *)sendRequestWithData:(nonnull NSData *)data
                        serviceId:(nonnull NSString *)serviceId
                           userId:(nullable NSString *)userId
                           routID:(nullable NSString *)routID
                          timeout:(NSTimeInterval)timeout
                         callBack:(nullable TBAccsManagerResponseBlock)callBack;


/**
 * 发送accs request请求
 * return dataid,
 */
- (NSString *)sendRequestWithContext:(nonnull TBAccsRequestContext *)context
                               error:(NSError **)returnError;


/**
 *  终止一个网络请求，如果这个请求还没有发送成功，这个请求会被终止发送。
 *  如果这个请求已经发送，cancel后，如果收到响应也不会回调给接受者
 */
- (void)cancelRequestByDataID:(nonnull NSString *)dataID;


@end

NS_ASSUME_NONNULL_END

