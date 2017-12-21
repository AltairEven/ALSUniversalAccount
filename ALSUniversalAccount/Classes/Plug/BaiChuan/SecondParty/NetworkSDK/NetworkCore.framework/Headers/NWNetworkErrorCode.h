//
//  NWNetworkErrorCode.h
//  ALINetworkSDK
//
//  Created by Roger.Mu on 3/24/15.
//  Copyright (c) 2015 Taobao.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#define NETERR_NETWORK_UNREACHABLE                  -1009

#define NETERR_TNET_PING_TIMEOUT_ERROR              -2223

#define NETERR_AUTH_REQ_FAILED_ERROR                -5010

#define NETERR_AUTH_FORBIDDEN_ERROR                 -5020

#define NETERR_NO_SESSION                           -5002

#define NETERR_NO_POLICY                            -5003

#define NETERR_REQUEST_WAITING_TNET_SESSION_TIMEOUT -5004

#define NETERR_REQUEST_ATS_FORBIDDEN                -6000

#define NETERR_REQUEST_ATS_INVALID_APPKEY           -6001

#define NETERR_REQUEST_ATS_INVALID_DOMAIN           -6002

#define NETERR_REQUEST_SIMULATE_REQ_FAIL            -7001

#define NETERR_TNET_SESSION_STATUS_INVALID          -7002

extern NSString* const  ERR_DOMAIN_REQUEST_ERROR;

extern NSString* const  ERR_DOMAIN_SESSION_ERROR;

NSError* getErrorInfo(NSString* domain, int errorCode, int syserrorno);
