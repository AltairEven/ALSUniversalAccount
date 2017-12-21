//
//  ISecurityGuardSecurityBody.h
//  SecurityGuardSecurityBody
//
//  Created by lifengzhong on 15/11/9.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardSecurityBody_h
#define ISecurityGuardSecurityBody_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/SecurityBody/ISecurityBodyComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/SecurityBody/ISecurityBodyComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardSecurityBody <NSObject, ISecurityBodyComponent, IOpenSecurityGuardPluginInterface>

@end

#endif /* ISecurityGuardSecurityBody_h */
