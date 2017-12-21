//
//  ISecurityGuardDynamicDataStore.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardDynamicDataStore_h
#define ISecurityGuardDynamicDataStore_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/DynamicDataStore/IDynamicDataStoreComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/DynamicDataStore/IDynamicDataStoreComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardDynamicDataStore <NSObject, IDynamicDataStoreComponent, IOpenSecurityGuardPluginInterface>

@end


#endif /* ISecurityGuardDynamicDataStore_h */
