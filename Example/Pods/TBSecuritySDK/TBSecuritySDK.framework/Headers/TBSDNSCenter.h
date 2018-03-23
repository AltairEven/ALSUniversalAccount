//
// TBSecuritySDK version 2.3.0
//

#import <Foundation/Foundation.h>



/**
 *  dns校验通过通知来触发；当需要做dns校验的时候，发送通知；
 */
#ifndef NeedVerifyDNSNotification
#define NeedVerifyDNSNotification  @"NeedVerifyDNSNotification"
#endif

/**
 *  dns校验后如果存在被劫持的dns，则发送通知，userinfo中返回正确的dns映射列表；
 */
#ifndef DNSHijackingNotification
#define DNSHijackingNotification  @"DNSHijackingNotification"
#endif


@interface TBSDNSCenter : NSObject

/**
 *  返回全局单例对象，在第一次调用时，会进行dns校验模块的初始化
 *
 *  @return 全局单例对象
 */
+ (TBSDNSCenter*) sharedInstance;

/**
 *  设置dns校验开关状态，默认为关闭，不做dns校验；enabled为yes时，开始dns校验，userinfo中包含正确的ip地址
 *
 *  @param enabled 是否打开dns校验
 */
- (void) setDNSCenterEnabled:(BOOL)enabled;

/**
 *  获取dns检验当前的开状态
 *
 *  @return 当前dns校验的开关状态
 */
- (BOOL) getDNSCenterEnabled;



@end
