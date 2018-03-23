//
//  ISecurityGuardSimulatorDetect.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardSimulatorDetect_h
#define ISecurityGuardSimulatorDetect_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/SimulatorDetect/ISimulatorDetectComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/SimulatorDetect/ISimulatorDetectComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif


@protocol ISecurityGuardSimulatorDetect <NSObject, ISimulatorDetectComponent, IOpenSecurityGuardPluginInterface>

@end

#endif /* ISecurityGuardSimulatorDetect_h */
