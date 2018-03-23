//
//  NWNetworkQualityMonitor.h
//  TBSDKNetworkSDK
//
//  Created by Roger.Mu on 10/12/14.
//  Copyright (c) 2014 taobao.com, All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    SEMP_NotSemaphore = 0,
    SEMP_StrongSemaphore,
    SEMP_weakSemaphore
} NetworkQualityStatus;


@interface UTNetworkQualitylog : NSObject

@property (nonatomic) float wjas_rtt;
@property (nonatomic) float cdn_rtt;

- (void) writeLog:(NetworkQualityStatus) qualityStatusT;

@end

@interface NWQualityModule : NSObject

@property (atomic) float wjas_t1;
@property (atomic) float wjas_t2;
@property (atomic) float wjas_rtt1;
@property (atomic) float wjas_rtt2;
@property (nonatomic, strong) NSString *wjas_url;
@property (nonatomic) float wjas_limited;

@property (atomic) float cdn_t1;
@property (atomic) float cdn_t2;
@property (atomic) float cdn_rtt1;
@property (atomic) float cdn_rtt2;
@property (nonatomic, strong) NSString *cdn_url;
@property (nonatomic) float cdn_limited;

@property (atomic) int runtimeSec;
@property (atomic) CFAbsoluteTime timestemp;

- (NetworkQualityStatus) wjasQualityStatusModule;

- (NetworkQualityStatus) cdnQualityStatusModule;

@end

/**
 * Networksdk Network quality monitor class
 * network layout semaphore strong and weak to global notify
 */
@interface NWNetworkQualityMonitor : NSObject

@property (nonatomic) BOOL isStart;
@property (nonatomic) NetworkQualityStatus qualityStatus;
@property (atomic, strong) NWQualityModule *qualityModule;

+ (NWNetworkQualityMonitor *)shareInstance;

- (void) demoteNetworkQuality;

- (void) unDemoteNetworkQuality;

- (void) setqualityModule:(NSString *) moduleJson;

- (void) sendQualityStatus:(BOOL) isRefresh;

- (NetworkQualityStatus) currentNetworkQualityStatus;

@end
