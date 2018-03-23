//
//  ISecurityGuardStaticDataEncrypt.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardStaticDataEncrypt_h
#define ISecurityGuardStaticDataEncrypt_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/StaticDataEncrypt/IStaticDataEncryptComponent.h>
#import <SecurityGuardSDKWatch/StaticDataEncrypt/StaticDataEncryptDefine.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/StaticDataEncrypt/IStaticDataEncryptComponent.h>
#import <SecurityGuardSDK/StaticDataEncrypt/StaticDataEncryptDefine.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardStaticDataEncrypt <NSObject, IStaticDataEncryptComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardStaticDataEncrypt_h */
