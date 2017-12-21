//
// SecurityGuardSDK version 2.3.0
//

#import <Foundation/Foundation.h>

/**
 *
 * The notification message identifier. Which will be send out when the DNS hijacking check is finished.
 *
 * Note: If there is no domain hijacking, the notification will be sent with a null userInfo.
 *
 * User should register an notification observer to receive this meesage.
 *
 */
#ifndef DNSHijackingNotification
#define DNSHijackingNotification  @"DNSHijackingNotification"
#endif

/**
 *  DNS 校验接口
 */
@protocol ISecurityDNSComponent <NSObject>

/**
 *  Call this method to initialize the security DNS component.
 *
 *  @return True if the component initialize successfully. False initialize failed.
 */
- (BOOL) initSecurityDNS;

/**
 *  Call this method to check if DNS server is hijacking.
 *
 * The notification message "DNSHijackingNotification" will be send out when the DNS server is hijacking.
 *
 * User should register an notification observer to receive this meesage.
 *
 *  @param urls The target urls, check if DNS server can route them to the correct address.
 *
 */
- (void) checkSecurityDNS: (NSArray*) urls;


@end


