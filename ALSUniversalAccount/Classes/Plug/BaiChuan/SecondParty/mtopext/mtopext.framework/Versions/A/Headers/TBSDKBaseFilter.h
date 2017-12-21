//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  TBSDKBaseFilter.h
//  TBSDKNetworkSDK
//
//  Created by 亿刀 on 13-9-24.
//  Copyright (c) 2013年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBSDKMTOPServerBehindFilterProtocol.h"

@interface TBSDKBaseFilter : NSObject<TBSDKMTOPServerBehindFilterProtocol>

@property (nonatomic, weak) id<TBSDKMTOPServerBehindFilterDelegate>delegate;

- (void)performDelegatWithMtopServer:(TBSDKMTOPServer *)mtopServer
                             headers:(NSDictionary *)headers
                        responseCode:(int)responseCode
                            response:(id)response
                additionalParameters:(NSDictionary *)additionalParameters;

@end
