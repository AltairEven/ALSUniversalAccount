//
//  UTTeamWork.h
//  miniUTSDK
//
//  Created by 宋军 on 15/1/4.
//  Copyright (c) 2015年 ___SONGJUN___. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UTTeamWork : NSObject

+(void) turnOnRealTimeDebug:(NSDictionary *) pDict;

+(void) trunOffRealTimeDebug;


//不再被ut外部调用!!!!!
//ut初始化时写死手淘的一份配置到缓存中
//+(void) loadConfsWhiteList;

+(void) setConfigMgr:(NSDictionary *) pDict withNameSpace: (NSString *) pName isUpdate:(BOOL) isUpdate;

+(void) setHasOrange;

@end
