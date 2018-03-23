//
//  AVFSAdapterManager.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/3/8.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AVFSAdapterManager : NSObject

/**
 *  单例
 *
 *  @return 单例
 */
+ (instancetype)sharedManager;

/**
 *  注册protocol的实现class
 *
 *  @param clazz    class
 *  @param protocol protocol
 */
- (void)injectImpWithClass:(Class)clazz forProtocol:(Protocol *)protocol;

/**
 *  获取对应的class
 *
 *  @param classKey class key
 *
 *  @return class
 */
- (Class)adapterImpClassForProtocol:(Protocol *)protocol;

@end
