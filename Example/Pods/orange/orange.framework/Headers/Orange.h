//
//  orange.h
//  orange
//
//  Created by 亿刀 on 15/8/20.
//  Copyright (c) 2015年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OrangeNamespaceModel.h"

#define ORANGE_SDK_VERSION @"1.4.5.72"

typedef NS_ENUM(NSInteger,OrangeUpateMode){
    OrangeUpateModeProbe, // 探针模式更新配置
    OrangeUpateModeEvent, // 事件模式更新配置(前后台切换Event)
    OrangeUpateModeProbeAndEvent // 探针和事件模式并存更新配置
};
/**
 *  Orange的唯一的接口类
 *
 *  http://tbdocs.alibaba-inc.com/pages/viewpage.action?pageId=263921764
 *
 */
@interface Orange : NSObject

/**
 *  启动orange，请在app启动的时候调用此方法，这个app生命周期只调用一次
 *  注意：请在后台线程调用此方法
 */
+ (void)run;

/**
 *  选取更新配置模式启动orange，请在app启动的时候调用此方法，这个app生命周期只调用一次
 *  注意：请在后台线程调用此方法
 */
+ (void)runMode:(OrangeUpateMode)mode;

/**
 *  获取配置内容，非hig级别配置，首次获取返回空，并触下载相应的配置，如果下载成功，业务方第二次调用此接口会返回远端配置
 *
 *  @param groupName     组名称，不能为nil，区分大小写
 *  @param key           配置的key，不能为nil，区分大小写
 *  @param defaultConfig 缺省值，可以为nil
 *  @param isDefault     返回的是否为缺省值，可以为nil
 *
 *  @return 配置的内容
 */
+ (id)getConfigByGroupName:(NSString *)groupName
                       key:(NSString *)key
             defaultConfig:(id)defaultConfig
                 isDefault:(BOOL *)isDefault;

/**
 *  获取整个组配置(和服务端的组对应), 业务方无需调用此接口，为测试使用
 *
 *  @param groupName 配置组的名字，区分大小写
 *
 *  @return 组的配置，如为空，返回nil
 */
+ (NSDictionary *)getGroupConfigByGroupName:(NSString *)groupName;

/**
 *  获取整个配置组MODEL
 *  @return 配置组MODEL
 */
+ (OrangeNamespaceModel *)getGroupConfigWithGroupName:(NSString *)groupName;

/**
 *  获取整个Custom自定义组配置(和服务端的组对应), 业务方无需调用此接口，为测试使用
 *
 *  @param groupName 配置组的名字，区分大小写
 *
 *  @return 组的配置，如为空，返回nil
 */
+ (NSString *)getCustomGroupConfigByGroupName:(NSString *)groupName;

/**
 *  设置自定义域名
 *  依次设置线上、预发、测试环境Host以及所对应的预置IP
 *  例子:
 *  @[@{@"线上域名",@[xx.xx.xx.xx,xx.xx.xx.xx,...]},
 *    @{@"预发域名",@[xx.xx.xx.xx,xx.xx.xx.xx,...]},
 *    @{@"日常域名",@[xx.xx.xx.xx,xx.xx.xx.xx,...]}
 *     ...]
 *
 */
+ (void)setCustomHosts:(NSArray *)hosts NS_DEPRECATED_IOS(2_0, 2_1, "已废弃，请使用 New Interface");;

#pragma mark New Interface
/**
 设置探针模式下需添加Orange探针的域名(默认不设置情况只模糊匹配'acs.m.taobao.com'域名添加探针头)
 
 @param onlineHost 线上匹配域名
 @param debugHost  预发匹配域名
 @param dailyHost  日常匹配域名
 */
+ (void)setProbeModeOnlineHost:(NSArray *) onlineHost debugHost:(NSArray *) debugHost dailyHost:(NSArray *) dailyHost;

/**
 设置Orange兜底数据中心域名

 @param onlineHost 线上数据中心域名
 @param debugHost  预发数据中心域名
 @param dailyHost  日常数据中心域名
 */
+ (void)setOrangeDataCenterOnlineHost:(NSString *) onlineHost debugHost:(NSString *) debugHost dailyHost:(NSString *) dailyHost;

/**
 设置Orange Ack上报域名

 @param onlineHost 线上ACK上报域名
 @param debugHost  预发ACK上报域名
 @param dailyHost  日常ACK上报域名
 */
+ (void)setOrangeAckReportOnlineHost:(NSString *) onlineHost debugHost:(NSString *) debugHost dailyHost:(NSString *) dailyHost;

/**
 设置Orange数据中心兜底VIP

 @param onlineIPList onelineIPList 线上兜底直连IP列表
 @param debugIPList   debugIPList   预发兜底直连IP列表
 @param dailyIPList   dailyIPList   日常兜底直连IP列表
 */
+ (void)setOrangeDataCenterOnlineIPList:(NSArray *) onlineIPList debugIPList:(NSArray *) debugIPList dailyIPList:(NSArray *) dailyIPList;

/**
 设置Orange ACK上报兜底VIP

 @param onlineIPList 线上兜底直连IP列表
 @param debugIPList  预发兜底直连IP列表
 @param dailyIPList  日常兜底直连IP列表
 */
+ (void)setOrangeACKOnlineIPList:(NSArray *) onlineIPList debugIPList:(NSArray *) debugIPList dailyIPList:(NSArray *) dailyIPList;

/**
 提供业务方设置自定义策略表达式 （策略表达式值必须是应用唯一固定）
 @param key    表达式对应的key
 @param value  表达式对应的value
 */
+ (void)setCustomCandidate:(NSString *)key value:(NSString *)value;

/**
 设置ACCS通道域名(依次 线上、预发、日常)，Orange的Beta测试通过ACCS长连通道推送配置到指定手机进行配置验证(二方淘系长连域名已内置可不设置，对于AE、Lazada、优酷这种部署独立Orange服务的APP请联系@岽篱 咨询ACCS域名)
 */
+ (void)setOrangeBetaModeAccsHost:(NSArray *)host;

+ (NSDictionary *)getKeyMap;

@end

FOUNDATION_EXTERN NSString * const indexACKNotification;// Orange 索引更新ACK通知
FOUNDATION_EXTERN NSString * const groupConfigACKNotification;// Orange 配置更新ACK通知
