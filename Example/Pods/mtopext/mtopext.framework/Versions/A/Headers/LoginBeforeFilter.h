//
//  LoginBeforeFilter.h
//  mtopext
//
//  Created by sihai on 12/12/14.
//  Copyright (c) 2014 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BeforeFilter.h"

#define LOGIN_BEFORE_FILTER_NAME @"b_login_filter"

@interface LoginBeforeFilter : NSObject<BeforeFilter>

@property(assign, nonatomic) MtopSessionExpiredOption defaultSessionExpiredOption;          // 全局的默认

/*!
 * 获取单例
 */
+ (LoginBeforeFilter*) getInstance;

@end
