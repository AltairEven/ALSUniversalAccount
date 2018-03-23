//
//  BeforeFilter.h
//  mtopext
//  前置过滤器
//  Created by sihai on 11/12/14.
//  Copyright (c) 2014 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MtopExtRequest.h"
#import "MtopExtResponse.h"
#import "FilterResult.h"

@protocol BeforeFilter <NSObject>

/*!
 * 获取filter的名字
 * @return
 *              NSString
 */
- (NSString*) getName;

/*!
 * 处理请求
 * @param request
 * @param result
 */
- (void) handle: (MtopExtRequest*) request result: (FilterResult*) result;

@end
