//
//  TBAutoLoginService.h
//  TBLogin
//
//  Created by 寻弦 on 14/11/19.
//
//

#import <Foundation/Foundation.h>
#import <mtopext/LoginProtocol.h>


@interface TBAutoLoginService : NSObject

@property(atomic, assign) BOOL needHavanaSsoToken;

/**
 *  自动登陆接口
 *
 *  @param completionHandler 登陆结果回调block
 */
- (void)autologinWithCompletionHandler:(LOGIN_COMPLETION_HANDLER)completionHandler;

- (void)autologinWithTimeout:(int)timeout completionHandler:(LOGIN_COMPLETION_HANDLER)completionHandler;

- (void)cancelAutoLoginIfDoing;

@end
