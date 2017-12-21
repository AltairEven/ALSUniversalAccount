//
//  ISecurityGuardInitialize.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/12.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardInitialize_h
#define ISecurityGuardInitialize_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/Initialize/IInitializeComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/Initialize/IInitializeComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardInitialize <NSObject, IInitializeComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardInitialize_h */
