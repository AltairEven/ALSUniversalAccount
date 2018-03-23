//
//  ISecurityGuardStaticDataStore.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/7.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardStaticDataStore_h
#define ISecurityGuardStaticDataStore_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/StaticDataStore/IStaticDataStoreComponent.h>
#import <SecurityGuardSDKWatch/StaticDataStore/StaticDataStoreDefine.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/StaticDataStore/IStaticDataStoreComponent.h>
#import <SecurityGuardSDK/StaticDataStore/StaticDataStoreDefine.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardStaticDataStore <NSObject, IStaticDataStoreComponent, IOpenSecurityGuardPluginInterface>
@end


#endif /* ISecurityGuardStaticDataStore_h */
