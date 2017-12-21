//
//  ErrorHandler.h
//  mtopext
//
//  错误码处理接口
//
//  Created by sihai on 17/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MtopExtResponse.h"

/*!
 *
 */
typedef enum : uint16_t {
    ACTION_RETURN                  = 0,
    ACTION_REDO                    = 1,
    ACTION_LOGIN_THEN_REDO         = 2,
    ACTION_FORCE_LOGIN_THEN_REDO   = 3,
    ACTION_CLEAR_CACHE             = 4,
} ACTION;

@protocol ErrorHandler <NSObject>

/*!
 * 处理错误
 * @param response
 */
- (ACTION) handle: (MtopExtResponse*) response;

@end
