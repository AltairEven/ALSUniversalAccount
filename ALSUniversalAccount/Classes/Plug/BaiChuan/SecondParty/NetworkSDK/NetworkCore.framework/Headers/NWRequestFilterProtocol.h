//
//  NWExtRequestProtocol.h
//  ALINetworkSDK
//
//  Created by jiangpan on 16/12/19.
//  Copyright © 2016年 jiangpan. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NWRequestFilterProtocol <NSObject>

@required
/**
 获取过滤器名
 @return 返回过滤器名称
 */
- (NSString *)getFilterName;

/**
 扩展请求头内容
 @return 需扩展的请求头字段
 */
- (NSDictionary *)extRequestHeader;

/**
 需扩展请求头的域名列表
 @return 域名列表
 */
- (NSArray *)extRequestDomainList;

@end
