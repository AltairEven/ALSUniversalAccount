//
//  UTAnalytics.h
//  miniUTInterface
//
//  Created by 宋军 on 14-10-14.
//  Copyright (c) 2014年 ___SONGJUN___. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UTTracker.h"
#import "UTICrashCaughtListener.h"
#import "UTPlugin.h"
#import "UTIRequestAuthentication.h"

@interface UTAnalytics : NSObject

+(UTAnalytics *) getInstance;

-(void) setAppVersion:(NSString *) pAppVersion;

-(void) setChannel:(NSString *) pChannel;

-(void) updateUserAccount:(NSString *) pNick userid:(NSString *) pUserId;

-(void) userRegister:(NSString *) pUsernick;

-(void) updateSessionProperties:(NSDictionary *) pDict;

-(UTTracker *) getDefaultTracker;

-(UTTracker *) getTracker:(NSString *)  pTrackId;

// 如果接了安全保镖,调用此接口，不需要塞入secret
- (BOOL) setAppKey:(NSString *)appKey;

// 如果使用appkey-appsecret对，调用此接口
- (BOOL) setAppKey:(NSString *)appKey secret:(NSString *)secret;

- (void) setRequestAuthentication:(id<UTIRequestAuthentication>)pRequestAuth NS_DEPRECATED_IOS(2_0, 6_0, "Use setAppKey:secret: instead");

-(void) turnOnDebug;

//turnOnUTInfo和turnOnDebug只允许选择一种，turnOnDebug信息范围更广
-(void) turnOnUTInfo;

-(void) turnOffAllUTLog;

-(void) turnOffCrashHandler;

-(void) setCrashCaughtListener:(id<UTICrashCaughtListener>) aListener;

+(NSString *) utsid;

+ (void)registerPlugin:(NSObject<UTPlugin> *)plugin;

+ (void)unregisterPlugin:(NSObject<UTPlugin> *)plugin;

@end
