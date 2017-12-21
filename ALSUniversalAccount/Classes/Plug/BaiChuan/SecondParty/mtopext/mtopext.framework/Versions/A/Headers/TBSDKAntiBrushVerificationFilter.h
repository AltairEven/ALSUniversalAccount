//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  TBSDKAntiBrushVerificationFilter.h
//  TBSDKNetworkSDK
//
//  Created by 亿刀 on 13-9-24.
//  Copyright (c) 2013年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TBSDKBaseFilter.h"
#import "TBSDKMTOPServerBehindFilterProtocol.h"

@interface TBSDKAntiBrushVerificationFilter : TBSDKBaseFilter

+ (TBSDKAntiBrushVerificationFilter *)shareInstance;

@end
