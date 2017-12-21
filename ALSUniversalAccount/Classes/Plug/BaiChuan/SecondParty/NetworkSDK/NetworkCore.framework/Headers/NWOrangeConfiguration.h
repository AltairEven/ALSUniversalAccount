//
//  NWOrangeConfiguration.h
//  ALINetworkSDK
//
//  Created by wuchen.xj on 8/18/16.
//  Copyright © 2016 wuchen.xj. All rights reserved.
//

#import <Foundation/Foundation.h>

#define NW_ORANGE_KEY_POLICY_MAX_EXPIRE_SECONDS         @"network_policy_max_expire_seconds"
#define NW_ORANGE_KEY_EMPTY_SCHEME_HTTPS_SWITCH         @"network_empty_scheme_https_switch"
#define NW_ORANGE_KEY_NETWORK_CACHE_ENABLED_SWITCH      @"network_cache_enabled_switch"
#define NW_ORANGE_KEY_NETWORK_FORCE_HTTPS_SWITCH        @"network_force_https_switch"
#define NW_ORANGE_KEY_NETWORK_HTTPS_PROXY_SWITCH        @"network_https_proxy_switch"
#define NW_ORANGE_KEY_NETWORK_USE_CFNETWORK_ECODES      @"network_use_cfnetwork_ecodes"
#define NW_ORANGE_KEY_NETWORK_CFNETWK_HTTP_SWITCH       @"network_cfnetwork_http_switch"
#define NW_ORANGE_KEY_NETWORK_CFNETWK_HTTP_BLACKLIST    @"network_cfnetwork_http_blacklist"
#define NW_ORANGE_KEY_NETWORK_DETECT_HTTPS_MAX_TIMEOUT  @"network_detect_https_max_timeout"
#define NW_ORANGE_KEY_MAX_HTTP_SESSION_CONCURRENT_COUNT @"network_max_http_session_concurrent_count"
#define NW_ORANGE_KEY_SPDY_ERROR_PROCESS_TYPE           @"network_spdy_error_process_type"
#define NW_ORANGE_KEY_NETWORK_OFF_SWITCH                @"network_off"
#define NW_ORANGE_KEY_NETWORK_FORCE_USE_CFNETWORK       @"network_force_use_cfnetwork"

@interface NWOrangeConfiguration : NSObject

+ (NWOrangeConfiguration *)sharedInstance;

- (void)setDefaultValue:(NSString *)value forKey:(NSString *)key;

- (void)updateNotification:(NSNotification *)notification;

- (BOOL)isAutoCompleteSchemeHttps;

- (BOOL)isCacheEnabled;

- (BOOL)isNetworkOff;

- (BOOL)isForce2Https;

- (BOOL)isHttpsProxyEnabled;

- (BOOL)isForceUseCFNetwork;

- (BOOL)isCFNetworkHttpEnabled:(NSString *)host;

- (BOOL)isDispatch2CFNetworkWhenError:(NSError *)error;

- (NSInteger)policyMaxExpireSeconds;

- (NSInteger)detectHttpsMaxTimeout;

- (NSInteger)maxHttpSessionConcurrentOperationCount;

- (NSInteger)processSpdyErrorType;

@end
