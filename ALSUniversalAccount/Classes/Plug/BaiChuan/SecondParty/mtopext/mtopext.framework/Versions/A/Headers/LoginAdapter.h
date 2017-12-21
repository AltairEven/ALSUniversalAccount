//
//  LoginAdapter.h
//  mtopext
//
//  Created by sihai on 17/11/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LoginProtocol.h"
#import "MtopExtRequest.h"

/*!
 * 尝试登录的结果
 */
typedef enum {
    ERROR,                              //
    PENDINGED,                          // 登录已经被其他线程唤起, 所以只是把该请求pending起来了
    INVOKED_LOGIN_AND_PENDINGED,        // 自己唤起了登录, 然后把该请求pending起来了
    LOGINED                             // 其他线程已经登录成功, 所以，神马也没做
} TRY_LOGIN_RESULT;

@interface LoginAdapter : NSObject<LoginProtocol>

/*!
 * 设置自定义的登录模块
 * @param module
 * @return
 *              返回原来的登录模块，可能是系统默认的(SSO)
 */
- (id<LoginProtocol>) setCustomLoginModule: (id<LoginProtocol>) module;

/*!
 * 尝试登录, 如果当前正在登录, 则直接将请求pending起来, 等待该登录完成后重放或失败
 * @param request
 * @return
 *                  参见 TRY_LOGIN_RESULT
 *
 */
- (TRY_LOGIN_RESULT) tryLogin: (MtopExtRequest*) request;

/*!
 * 尝试登录, 如果当前正在登录, 则直接将请求pending起来, 等待该登录完成后重放或失败
 * @param request
 * @param isForce
 * @return
 *                  参见 TRY_LOGIN_RESULT
 *
 */
- (TRY_LOGIN_RESULT) tryLogin: (MtopExtRequest*) request isForce: (BOOL) isForce;

@end
