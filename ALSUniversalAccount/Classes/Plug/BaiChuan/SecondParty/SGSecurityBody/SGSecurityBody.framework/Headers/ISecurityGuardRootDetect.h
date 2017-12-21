//
//  ISecurityGuardRootDetect.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardRootDetect_h
#define ISecurityGuardRootDetect_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/RootDetect/IRootDetectComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/RootDetect/IRootDetectComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardRootDetect <NSObject, IRootDetectComponent, IOpenSecurityGuardPluginInterface>

@end

#endif /* ISecurityGuardRootDetect_h */
