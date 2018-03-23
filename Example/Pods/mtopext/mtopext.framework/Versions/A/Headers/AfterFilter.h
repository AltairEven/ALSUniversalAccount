//
//  AfterFilter.h
//  mtopext
//
//  Created by sihai on 11/12/14.
//  Copyright (c) 2014 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MtopExtRequest.h"
#import "MtopExtResponse.h"
#import "FilterResult.h"

@protocol AfterFilter <NSObject>

/*!
 * 获取filter的名字
 * @return
 *              NSString
 */
- (NSString*) getName;

/*!
 * 处理请求和响应
 * @param request
 * @param response
 * @param result
 */
- (void) handle: (MtopExtRequest*) request response: (MtopExtResponse*) response result: (FilterResult*) result;

@end
