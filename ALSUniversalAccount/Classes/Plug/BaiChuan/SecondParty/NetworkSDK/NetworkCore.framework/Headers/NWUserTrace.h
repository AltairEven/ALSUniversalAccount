//
//  NWUTProtocol.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 2/2/16.
//  Copyright © 2016 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * 打点事件类型
 */
typedef enum {
    kUTRequest      = 0,                                // 请求打点
    kUTSession      = 2,                                // Session打点
    kUTChannel      = 1,                                // 通道打点, 手淘业务使用，其他业务可以不用关注
    kUTError        = 3,                                // 错误打点
    kUTAmdc         = 4,                                // AMDC打点
    kUTAts          = 5                                 // ATS 打点
}UTReportID;




/**
 * Request打点数据字典索引
 */
extern NSString*  const NW_UTR_KEY_BIZCODE;              // 请求的bizcode，定义在NWConnectionOption中，若未定义，则为@“”
extern NSString*  const NW_UTR_KEY_RESULT;               // 请求的结果，@"1"表示成功，@"0"表示失败
extern NSString*  const NW_UTR_KEY_HOST;                 // 请求的host
extern NSString*  const NW_UTR_KEY_IP;                   // 请求的ip
extern NSString*  const NW_UTR_KEY_PORT;                 // 请求的端口
extern NSString*  const NW_UTR_KEY_TIMESTAMP;            // 请求的本地绝对时间标签
extern NSString*  const NW_UTR_KEY_IS_SSL;               // 是否加密, @"1" 表示加密，@"0"表示明文
extern NSString*  const NW_UTR_KEY_IS_PROXY;             // 是否是代理环境, @“1”表示是，@“0”表示否
extern NSString*  const NW_UTR_KEY_IS_DNS;               // 是否使用策略调度, @“1”表示是，@“0”表示否
extern NSString*  const NW_UTR_KEY_IS_IPV6;              // 是否是IPv6-only网络, @“1”表示是，@“0”表示否
extern NSString*  const NW_UTR_KEY_PROXY_TYPE;           // 若使用代理，代理的类型(未实现)
extern NSString*  const NW_UTR_KEY_NET_TYPE;             // 网络类型: wifi, 2G, 3G, 4G
extern NSString*  const NW_UTR_KEY_PROTOCOL_TYPE;        // 协议类型
extern NSString*  const NW_UTR_KEY_RETRY_TIMES;          // 重试次数
extern NSString*  const NW_UTR_KEY_STATUS_CODE;          // 状态码，若请求成功，则为server返回的http状态码，若失败，参考定义的错误码
extern NSString*  const NW_UTR_KEY_ERROR_MESSAGE;        // 若请求失败，错误描述
extern NSString*  const NW_UTR_KEY_ERROR_TYPE;           // 若请求失败，错误的类型
extern NSString*  const NW_UTR_KEY_URL;                  // 请求的完整URL字符串
extern NSString*  const NW_UTR_KEY_FIRST_PACKAGE_TIME;   // 请求的首包到达时间: 从发送到第一个包到达的时间
extern NSString*  const NW_UTR_KEY_SEND_DATA_TIME;       // 发送数据时长
extern NSString*  const NW_UTR_KEY_SEND_DATA_SIZE;       // 发送数据大小
extern NSString*  const NW_UTR_KEY_RECV_DATA_TIME;       // 接收数据时长
extern NSString*  const NW_UTR_KEY_RECV_DATA_SIZE;       // 接收数据大小
extern NSString*  const NW_UTR_KEY_SERVER_RESPONSE_TIME; // 服务端响应时长，该数据是server端通过serverRT字段携带道端上
extern NSString*  const NW_UTR_KEY_SEND_WATING_TIME;     // 发送等待耗时
extern NSString*  const NW_UTR_KEY_SESSION_REUSE;        // 该请求是否通过复用session发送，@"1" 表示复用，@"0"表示新建
extern NSString*  const NW_UTR_KEY_TOTAL_RTT;            // 请求的总rtt
extern NSString*  const NW_UTR_KEY_USER_INFO;            // 请求用户自定义参数userinfo



/**
 * Session打点数据字典索引
 */
extern NSString*  const NW_UTS_KEY_RESULT;               // 连接结果，@"1"表示成功，@"0"表示失败
extern NSString*  const NW_UTS_KEY_HOST;                 // 连接的host
extern NSString*  const NW_UTS_KEY_IP;                   // 连接的ip
extern NSString*  const NW_UTS_KEY_PORT;                 // 连接的port
extern NSString*  const NW_UTS_KEY_TIMESTAMP;            // Session建立本地绝对时间标签
extern NSString*  const NW_UTS_KEY_CLOSE_REASON;         // 连接关闭的原因描述
extern NSString*  const NW_UTS_KEY_RETRY_TIMES;          // 建连的次数
extern NSString*  const NW_UTS_KEY_CONNECT_TYPE;         // 连接的类型描述字符串
extern NSString*  const NW_UTS_KEY_IP_REFER;             // 连接的IP来源：0:AMDC, 1:LocalDNS, 2:Built-in, 3:User Define
extern NSString*  const NW_UTS_KEY_IS_PROXY;             // 是否代理，@"1"表示是，@“0”表示否
extern NSString*  const NW_UTS_KEY_IS_TUNNEL;            // 是否隧道, @"1"表示是，@“0”表示否
extern NSString*  const NW_UTS_KEY_IS_IPV6;              // 是否是IPv6-only网络, @“1”表示是，@“0”表示否
extern NSString*  const NW_UTS_KEY_IS_KEEPALIVE;         // 是否保活
extern NSString*  const NW_UTS_KEY_IS_BACKGROUND;        // 是否后台运行
extern NSString*  const NW_UTS_KEY_NET_TYPE;             // 网络类型: wifi, 2G, 3G, 4G
extern NSString*  const NW_UTS_KEY_CONNECTION_TIME;      // 连接建连耗时
extern NSString*  const NW_UTS_KEY_LIVE_TIME;            // 连接生存时间
extern NSString*  const NW_UTS_KEY_AUTHENTICATION_TIME;  // 鉴权耗时
extern NSString*  const NW_UTS_KEY_SSL_SHAKE_TIME;       // SSL握手耗时
extern NSString*  const NW_UTS_KEY_SSL_CALL_TIME;        // SSL的RSA时间
extern NSString*  const NW_UTS_KEY_REQUEST_COUNT;        // 该连接的请求个数
extern NSString*  const NW_UTS_KEY_CUS_REQUEST_COUNT;    // 自定义帧请求个数
extern NSString*  const NW_UTS_KEY_STD_REQUEST_COUNT;    // 标准帧请求个数
extern NSString*  const NW_UTS_KEY_PING_PACKAGE_COUNT;   // ping包个数
extern NSString*  const NW_UTS_KEY_PING_INTERVAL;        // ping包周期
extern NSString*  const NW_UTS_KEY_ACK_TIME;             // 接收下行数据时延(未实现)
extern NSString*  const NW_UTS_KEY_SEND_DATA_SIZE;       // 上行流量大小
extern NSString*  const NW_UTS_KEY_RECV_DATA_SIZE;       // 下行流量大小
extern NSString*  const NW_UTS_KEY_INCEPT_COUNT;         // 下行请求数(未实现)
extern NSString*  const NW_UTS_KEY_ERROR_CODE;           // 若建连失败，错误码
extern NSString*  const NW_UTS_KEY_SDK_VERSION;          // SDK 版本


/**
 * ATS打点数据字典索引
 */
extern NSString*  const NW_UTA_KEY_HOST;                 // 域名
extern NSString*  const NW_UTA_KEY_URL;                  // URL
extern NSString*  const NW_UTA_KEY_RET;                  // 请求是否成功:@"1"表示成功，@“0”表示失败
extern NSString*  const NW_UTA_KEY_ECODE;                // 若失败，具体错误码
extern NSString*  const NW_UTA_KEY_TOTAL_TIME;           // 请求的总花费时间
extern NSString*  const NW_UTA_KEY_TYPE;                 // ATS 处理的逻辑：
                                                         // “0”：不处理；
                                                         // “1”:转换成HTTPS；
                                                         // ”2“:使用CFNetwork下发；
                                                         // "3":ATS-Proxy转发；
                                                         // "4":禁止

/**
 * 用户自定义打点输出回调接口
 */
@protocol NWUserTraceDelegate <NSObject>

- (void)onReportEvent:(UTReportID)eid withArgs:(NSDictionary *)args;

@end


