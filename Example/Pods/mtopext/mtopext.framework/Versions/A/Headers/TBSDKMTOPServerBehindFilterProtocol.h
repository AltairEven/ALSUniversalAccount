//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀 on 13-8-29.
//  Copyright (c) 2013年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum _TBSDKFilterKind {
    TBSDKFilterKindAll = 0,             //过滤所有返回
	TBSDKFilterKindSuccess = 1,         //过滤请求成功的返回
    TBSDKFilterKindFail = 2             //过滤请求失败的返回
} TBSDKFilterKind;

@class TBSDKMTOPServer;

@protocol TBSDKMTOPServerBehindFilterProtocol <NSObject>

@required

//! 是否在后台线程调用过滤器，YES，表示在非主线程中进行过滤，NO，表示在当前线程过滤（有可能是主线程）.默认NO.如果没有特殊用途建议设置为YES,以避免阻塞主线程。
- (TBSDKFilterKind)filterKind;

//! 过滤类型，默认“TBSDKFilterKindAll”
- (BOOL)isBackGround;

-   (void)mtopServer:(TBSDKMTOPServer *)mtopServer
             headers:(NSDictionary *)headers
        responseCode:(int)responseCode
            response:(id)response
additionalParameters:(NSDictionary *)additionalParameters;

@optional

//! 标示符
- (NSDictionary *)userInfo;

- (NSString *)identifier;

@end

@protocol TBSDKMTOPServerBehindFilterDelegate <NSObject>

@required

-   (void)mtopServer:(TBSDKMTOPServer *)mtopServer
             headers:(NSDictionary *)headers
        responseCode:(int)responseCode
            response:(id)response
additionalParameters:(NSDictionary *)additionalParameters;


@end
