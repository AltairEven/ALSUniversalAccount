//
//  ALSUAOperationPlug.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 04/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AlisportsUniversalAccountPublic/AlisportsUniversalAccountPublic.h>

/**
 阿里体育统一账户操作插件基类，可以以此为基类，创建操作插件类
 */
@interface ALSUAOperationPlug : NSObject <ALSUAPlugProtocal> {
    BOOL isOnline;
}

@end
