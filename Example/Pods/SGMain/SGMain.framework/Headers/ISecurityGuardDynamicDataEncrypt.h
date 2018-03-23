//
//  ISecurityGuardDynamicDataEncrypt.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardDynamicDataEncrypt_h
#define ISecurityGuardDynamicDataEncrypt_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/DynamicDataEncrypt/IDynamicDataEncryptComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/DynamicDataEncrypt/IDynamicDataEncryptComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardDynamicDataEncrypt <IDynamicDataEncryptComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardDynamicDataEncrypt_h */
