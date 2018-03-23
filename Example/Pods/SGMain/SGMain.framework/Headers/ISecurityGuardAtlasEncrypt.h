//
//  ISecurityGuardAtlasEncrypt.h
//  SecurityGuardWhiteBox
//
//  Created by lifengzhong on 15/11/9.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardAtlasEncrypt_h
#define ISecurityGuardAtlasEncrypt_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/AtlasEncrypt/IAtlasEncryptComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/AtlasEncrypt/IAtlasEncryptComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardAtlasEncrypt <NSObject, IAtlasEncryptComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardAtlasEncrypt_h */
