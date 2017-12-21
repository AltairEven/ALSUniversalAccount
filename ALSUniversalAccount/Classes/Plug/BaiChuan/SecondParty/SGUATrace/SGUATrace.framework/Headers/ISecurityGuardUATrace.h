//
//  ISecurityGuardUATrace.h
//  SecurityGuardUATrace
//
//  Created by lifengzhong on 15/11/9.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardUATrace_h
#define ISecurityGuardUATrace_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/UATrace/IUATraceComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/UATrace/IUATraceComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardUATrace <NSObject, IUATraceComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardUATrace_h */
