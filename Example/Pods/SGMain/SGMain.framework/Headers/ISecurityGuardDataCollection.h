//
//  ISecurityGuardDataCollection.h
//  SecurityGuardMain
//
//  Created by lifengzhong on 15/11/10.
//  Copyright © 2015年 Li Fengzhong. All rights reserved.
//

#ifndef ISecurityGuardDataCollection_h
#define ISecurityGuardDataCollection_h

#if TARGET_OS_WATCH
#import <SecurityGuardSDKWatch/DataCollection/IDataCollectionComponent.h>
#import <SecurityGuardSDKWatch/Open/IOpenSecurityGuardPlugin.h>
#else
#import <SecurityGuardSDK/DataCollection/IDataCollectionComponent.h>
#import <SecurityGuardSDK/Open/IOpenSecurityGuardPlugin.h>
#endif

@protocol ISecurityGuardDataCollection <NSObject, IDataCollectionComponent, IOpenSecurityGuardPluginInterface>

@end

#endif /* ISecurityGuardDataCollection_h */
