//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀 on 13-1-28.
//  Copyright (c) 2013年 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TBSDKAccountInfo;

@protocol TBSDKConfigurationPrivate <NSObject>

- (void)setTimestampOffset:(NSTimeInterval)offset;
- (void)setDeviceID:(NSString *)deviceID_;

@end

/** TBSDK环境设置 */
typedef enum {
    TBSDKEnvironmentDebug =  1,     /**< 枚举，预发环境 */
    TBSDKEnvironmentDaily,          /**< 枚举，日常环境 */
    TBSDKEnvironmentDailyTwo,       /**< 枚举，日常二套环境 */
    TBSDKEnvironmentRelease         /**< 枚举，正式环境 */
}TBSDKEnvironment;

/** 实体类存储着TBSDK的配置信息
 *
 * 实体类存储着TBSDK的配置信息，如果appkey，ttid等
 */
@interface TBSDKConfiguration : NSObject<TBSDKConfigurationPrivate>

//! 设置环境. PS:需要自己设置测试环境的APPKey Secret
@property (nonatomic, unsafe_unretained) TBSDKEnvironment                       environment;

//! 应用程序的 app name
@property (nonatomic, strong) NSString                                          *appName;

//! 应用程序的 appKey
@property (nonatomic, strong) NSString                                          *appKey;

//! 安全黑匣子 多appkey逻辑
@property (nonatomic, strong) NSString                                          *securityAppKey;

//! 应用程序的 appSecret
//@property (nonatomic, strong) NSString                                          *appSecret;

//! 手机唯一识别码，TBSDK联网自动获取
@property (nonatomic, strong) NSString                                          *deviceID;

//! 软件版本号，比如 4.2.3      
@property (nonatomic, strong, readonly) NSString                                *appVersion;

//! 无线埋点的 ttid
@property (nonatomic, strong) NSString                                          *wapTTID;

//! 无线 MTOP API 的请求地址，调用者可以设置自己的“wapAPIURL”
@property (nonatomic, strong) NSString                                          *wapAPIURL;

@property (nonatomic, strong) NSString                                          *topAPIURL;

//! 本地时间与服务器的时间差(秒)，TBSDK负责联网获取
@property (nonatomic, unsafe_unretained, readonly) NSTimeInterval               timestampOffset;

/** 老的deviceId。
 *
 *  如果是首次使用TBSDKNetworkSDK，并且app以前就有获取deviceId的逻辑，需传入oldDeviceId。因为TBSDKNetworkSDK在获取新的deviceId的时候需要老的deviceId。\n
 *  如果不是首次使用TBSDKNetworkSDK，oldDeviceId将被忽略
 *  详情请看：http://dev.wireless.taobao.net/mediawiki/index.php?title=Mtop.sys.newDeviceId
 *
 **/
@property (nonatomic, strong) NSString                                          *oldDeviceId;

/** 记录老的DeviceId */
@property (nonatomic, strong) NSString                                          *networkSDKOldDeviceId;

/** 存放了与登录相关信息，如sid，ecode等 */
@property (nonatomic, strong) TBSDKAccountInfo                                  *accountInfo;

/** 是否使用黑匣子。YES，表示使用黑匣子。NO，表示使用黑匣子。默认为YES */
@property (nonatomic, unsafe_unretained) BOOL                                   safeSecret;

@property (nonatomic, strong) NSString                                          *mtopOriginalUrl;

@property (nonatomic, strong) NSString                                          *topOriginalUrl;

/** MTOP 多套测试环境配置 */
@property (nonatomic, strong) NSString                                          *tproject;

@property (nonatomic, strong) NSString                                          *wapAPISecurityURL;

@property (nonatomic, strong) NSString                                          *debugId;

@property (nonatomic, strong) NSString*                                         defaultDomain;

@property(strong, nonatomic) NSString                                           *utdid;

@property(strong, nonatomic) NSString                                           *authCode;

@property(strong, nonatomic) NSString                                           *uid;

// 没必要atomic, 这个值的修改肯定是初始阶段
@property(assign, atomic, readonly)  uint64_t                                   features;

@property (assign, nonatomic) BOOL                                              supportOpenAccsOut;

+ (id)shareInstance;

//! 请将api字符串转换为小写
+ (void)addEcodeSignAPI:(NSArray *)API;

+ (NSDate *)timeStampFixedWithServer;

/*!
 *
 */
- (void)setTimestampOffset:(NSTimeInterval)offset;

/*!
 * 打开、关闭全站https
 */
- (void) enableAllSiteHttps;
- (void) disableAllSiteHttps;

/*!
 * open or close white security function
 */
- (void) enableWhiteSecurity;
- (void) unableWhiteSecurity;

/*!
 * 设置一个应用级别的请求头, 注意 设置的值不会被持久化，只是在应用生命周期内有效
 * @param name
 * @param value
 *
 */
- (void) setApplicationRequestHeader: (NSString*) value forKey: (NSString*) key;

/*!
 * 获取一个应用级别的请求头的值
 * @param name
 * @return
 *              setApplicationRequestHeader设置的值
 */
- (NSString*) getApplicationRequestHeader: (NSString*) name;

/*!
 * 获取当前的应用级别的请求头
 * @return
 *              NSDictionary
 */
- (NSDictionary*) getCurrentApplicationRequestHeader;

/*!
 * 移除一个应用级别的请求头
 * @param name
 *
 */
- (void) removeApplicationRequestHeader: (NSString*) name;

/*!
 * 移除所以应用级别的请求头
 * @param name
 *
 */
- (void) removeAllApplicationRequestHeader;

/*!
 *
 */
- (void) loadAVCV;

@end
