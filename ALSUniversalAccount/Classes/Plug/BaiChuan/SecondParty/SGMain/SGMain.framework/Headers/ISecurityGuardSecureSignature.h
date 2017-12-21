//
//  ISecurityGuardSecureSignature.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardSecureSignature_h
#define ISecurityGuardSecureSignature_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/SecureSignature/ISecureSignatureComponent.h>
#import <SecurityGuardSDKWatch/SecureSignature/SecureSignatureDefine.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#import <SecurityGuardSDKWatch/SecurityGuardParamContext.h>
#else
#import <SecurityGuardSDK/SecureSignature/ISecureSignatureComponent.h>
#import <SecurityGuardSDK/SecureSignature/SecureSignatureDefine.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#import <SecurityGuardSDK/SecurityGuardParamContext.h>
#endif

@protocol ISecurityGuardSecureSignature <NSObject, ISecureSignatureComponent, IOpenSecurityGuardPluginInterface>

@end

#endif /* ISecurityGuardSecureSignature_h */
