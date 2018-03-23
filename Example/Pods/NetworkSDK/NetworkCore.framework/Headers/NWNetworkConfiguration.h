//
//  NWNetworkConfiguration.h
//  ALINetworkSDK
//
//  Created by Roger.Mu on 1/19/15.
//  Copyright (c) 2015 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NWSessionConfiguration.h"
#import "NWNetworkTraceAnalysis.h"
#import "NWLocationProtocol.h"
#import "NWUserPolicy.h"
#import "NWUserTrace.h"
#import "NWUserLoger.h"

typedef enum {
    release = 0,    //线上环境
    releaseDebug,   //预发环境
    daily           //日常环境
} NetworkEnv;

#define NETWORK_PROTOCOL_SKIP                   @"network_skip"
#define NETWORK_PROTOCOL_CONNECTION_REGISTER    @"connection_register"
#define NETWORK_ENVIRONMENT_CHANGED             @"network_environment_changed"

#define SLIGHT_SSL_PUBKEY_SEQ_CDN    1      //EASY_CONNECT_SSSL_CDN_SEQNUM
#define SLIGHT_SSL_PUBKEY_PSEQ_CDN   1      //cdn去黑匣子使用相同的公钥
#define SLIGHT_SSL_PUBKEY_SEQ_ACCS   3      //EASY_CONNECT_SSSL_ACCS_SEQNUM
#define SLIGHT_SSL_PUBKEY_PSEQ_ACCS  4      //对应aserver明文公钥
#define SLIGHT_SSL_PUBKEY_SEQ_TEST   0      //EASY_CONNECT_SSSL_TEST_SEQNUM
#define SLIGHT_SSL_PUBKEY_SEQ_AE     5      //for AE
#define SLIGHT_SSL_PUBKEY_SEQ_ARUP   6      //for arup
#define SLIGHT_SSL_PUBKEY_PSEQ_ARUP  7      //for arup plaintext
#define SLIGHT_SSL_PUBKEY_SEQ_ADASH  8      //for adash
#define SLIGHT_SSL_PUBKEY_PSEQ_ADASH 9      //for adash plaintext
#define SLIGHT_SSL_PUBKEY_SEQ_OPEN   10     //for 第三方
#define SLIGHT_SSL_PUBKEY_PSEQ_OPEN  11     //for 第三方 plaintext
#define SLIGHT_SSL_PUBKEY_PSEQ_EMAS  12     // for EMAS

@interface NWNetworkConfiguration : NSObject

#pragma mark -- initial properties

@property (nonatomic, nullable, weak)     id<NWUserTraceDelegate>     utDelegate;         // 自定义 UT
@property (nonatomic, nullable, weak)     id<NWUserLogDelegate>       logDelegate;        // 自定义 LOG
@property (nonatomic, nullable, weak)     id<NWPolicyDelegate>        policyDelegate;     // 自定义 策略
@property (nonatomic, nullable, weak)     id<NWRequestCostProtocol>   traceProtocol;      // 记录请求和结束的轨迹
@property (nonatomic, nullable, weak)     id<NWRequestFlowProtocol>   flowProtocol;       // 记录请求流量
@property (nonatomic, nullable, weak)     id<NWLocationQueryProtocol> locationProtocol;   // 当前经纬度查询回调

@property (nonatomic, nullable, strong)             NSString          *appkey;
@property (nonatomic, nullable, strong)             NSString          *appSecret;         // 如果使用安全保镖，该参数不用填写
@property (nonatomic, nullable, strong)             NSString          *authCode;          // 安全保镖SDK的授权码，不传或为空串，使用默认加密文件
@property (nonatomic, nullable, strong)             NSString          *utdid;
@property (nonatomic, nullable, strong)             NSString          *longitude;
@property (nonatomic, nullable, strong)             NSString          *latitude;
@property (nonatomic, assign)                       NetworkEnv        netEnvironment;     // 设置网络环境: release, releaseDebug, daily
@property (nonatomic, assign)                       BOOL              isUseSecurityGuard; // 是否使用安全保镖，默认为YES
@property (nonatomic, assign)                       BOOL              isEnableAMDC;       // 是否启用AMDC, 默认为YES
@property (nonatomic, assign)                       BOOL              loadingAllRequest;  // 是否全局接管, 默认为YES
@property (nonatomic, assign)                       int               customAppkeyIndex;  // 自定义appkey在安全图片中的索引位置，默认不用设置


+ (nullable NWNetworkConfiguration *)shareInstance;

/**
 * 设置网络环境。
 * @param env 三种环境：release, releaseDebug, daily
 */
+ (void)setEnvironment:(NetworkEnv)env;


/**
 * 定制Aserver中心域名 
 * @param releaseHost  线上域名
 * @param debugHost    预发域名
 * @param dailyHost    日常域名
 */
+ (void)setAcsCenterHosts:(nullable NSString *)releaseHost debugHost:(nullable NSString *)debugHost dailyHost:(nullable NSString *)dailyHost;



/**
 * 定制预置IP
 * @param releaseIps 线上预置IP列表
 * @param debugIps   预发预置IP列表
 * @param dailyIps   日常预置IP列表
 */
+ (void)setAcsCenterIPs:(nullable NSArray *)releaseIps debugIps:(nullable NSArray *)debugIps dailyIps:(nullable NSArray *)dailyIps;



/**
 * 定制AMDC域名
 * @param releaseHost  线上域名
 * @param debugHost    预发域名
 * @param dailyHost    日常域名
 */
+ (void)setAmdcHosts:(nullable NSString *)releaseHost debugHost:(nullable NSString *)debugHost dailyHost:(nullable NSString *)dailyHost;



/**
 * 定制AMDC预置IP
 * @param releaseIps 线上预置IP列表
 * @param debugIps   预发预置IP列表
 * @param dailyIps   日常预置IP列表
 */
+ (void)setAmdcIPs:(nullable NSArray *)releaseIps debugIps:(nullable NSArray *)debugIps dailyIps:(nullable NSArray *)dailyIps;



/**
 * 定制预建连接。该接口已废弃。
 *
 * @param hosts      需要预建连接的域名
 */
+ (void)setPrebuiltConnections:(nullable NSArray *)hosts;



/**
 * 设置内置热域名。
 * 默认情况下，内置的是手机淘宝的热域名，如果应用需要定义自己的热域名，可调用该方法进行覆盖。
 *
 * @param domains 域名列表, 元素类型为NSString
 */
+ (void)setHotDomains:(nullable NSArray *)domains;


/**
 * 获取当前的设备的 utdid
 */
- (nullable NSString *)getAuthUtdid;


/**
 * 设置userid
 */
- (void)setuid:(nullable NSString *) uid;

- (void)setUid:(nullable NSString *) uid;

- (nullable NSString *)uid;


/**
 * 非全局接管场景下，需要接管的请求标识，通过 f-refer 识别。
 * 该设置需要在 loadingAllRequest=NO 的情况下才有效
 */
- (void)registerLoadingRefer:(nonnull NSString *)refer;


/**
 * 非全局接管场景下，查看该request是否需要接管，通过通过 f-refer 识别。
 * 该设置需要在 loadingAllRequest=NO 的情况下才有效
 */
- (BOOL)acceptRequestWithRefer:(nonnull NSURLRequest *)request;


/**
 * 设置session配置
 */
- (void)setSessionConfiguration:(nonnull NWSessionConfiguration *)configuration;


/**
 * 设置域名公钥索引
 */
- (void)setHost:(nonnull NSString *)host withSlightSslPubkeySeq:(int)seq;


/**
 * 获取当前域名公钥索引
 */
- (int)slightSslPubkeySeqWithHost:(nonnull NSString *)host;


/**
 * 查询session配置
 */
- (nullable NWSessionConfiguration *)sessionConfiguration:(nonnull NSString *)host;


/**
 * 获取网络sdk的版本号
 */
- (nonnull NSString *)getNetworkSDKVer;


/**
 * 获取客户端ip。
 * 端上的外网IP，需要有过AMDC请求才有值，如没有发生过AMDC请求，则该函数不会取到值。
 */
+ (nullable NSString *)getClientIp;

@end
