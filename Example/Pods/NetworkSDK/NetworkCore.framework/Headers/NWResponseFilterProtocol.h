//
//  NWResponseFilterProtocol.h
//  ALINetworkSDK
//
//  Created by jiangpan on 17/1/5.
//  Copyright © 2017年 jiangpan. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NWResponseFilterProtocol <NSObject>

@required
/**
 获取过滤器名
 @return 返回过滤器名称
 */
- (NSString *)getFilterName;

/**
 处理拦截的Response
 @param response 拦截的响应
 */
- (void)handleResponse:(NSURLResponse *)response;

@end
