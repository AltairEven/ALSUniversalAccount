//
//  DTRpcContext.h
//  APMobileNetwork
//
//  Created by feisong on 16/8/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface DTRpcContext : NSObject

/**
 * 设置rpcheader
 * @param 字典类型的header
 */
+(void)setRpcHeader:(NSDictionary*)header;
/**
 * 获取rpcheader
 * @return 获取字典类型的header
 */

+(NSDictionary*)getRpcHeader;
/**
 *  移除rpcHeader
 */
+(void)removeRpcHeader;
/**
 *  设置是否是前台rpc
 */
+(void)setForegroundRPC:(BOOL)isForeground;
/**
 *  获取是否是前台rpc 默认是yes
 */
+(BOOL)isForegroundRPC;

/**
 *  设置网络层是否需要显示限流页面
 */
+(void)setShouldShowFlow:(BOOL)showFlow;
/**
 *  获取网络层是否需要显示限流页面
 */
+(BOOL)shouldShowFlow;

@end
