//
//  ISecurityGuardNoCaptcha.h
//  SecurityGuardNoCaptcha
//
//  Created by lifengzhong on 15/11/9.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardNoCaptcha_h
#define ISecurityGuardNoCaptcha_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/NoCaptcha/INoCaptchaComponent.h>
#import <SecurityGuardSDKWatch/NoCaptcha/NoCaptchaDefine.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/NoCaptcha/INoCaptchaComponent.h>
#import <SecurityGuardSDK/NoCaptcha/NoCaptchaDefine.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardNoCaptcha <NSObject, INoCaptchaComponent, IOpenSecurityGuardPluginInterface>


@end


#endif /* ISecurityGuardNoCaptcha_h */
