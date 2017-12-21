//
//  FilterManager.h
//  mtopext
//
//  Created by sihai on 11/12/14.
//  Copyright (c) 2014 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MtopExtRequest.h"
#import "MtopExtResponse.h"
#import "BeforeFilter.h"
#import "AfterFilter.h"

@interface FilterManager : NSObject

/*!
 * 获取实(单例)
 */
+ (FilterManager*) getInstance;

/*!
 * 添加前置处理Filter
 * @param request
 */
- (void) addBeforeFilter: (id<BeforeFilter>) filter;

/*!
 * 添加后置处理Filter
 * @param request
 */
- (void) addAfterFilter: (id<AfterFilter>) filter;

/*!
 * 前置处理
 * @param request
 * @return
 *              FilterResult
 */
- (FilterResult*) doBefore: (MtopExtRequest*) request;

/*!
 * 前置处理
 * @param request
 * @param startFilter
 * @return
 *              FilterResult
 */
- (FilterResult*) doBefore: (MtopExtRequest*) request startFilter: (NSString*) startFilter;

/*!
 * 后置处理
 * @param request
 * @param response
 * @return
 *              FilterResult
 */
- (FilterResult*) doAfter: (MtopExtRequest*) request response: (MtopExtResponse*) response;

@end
