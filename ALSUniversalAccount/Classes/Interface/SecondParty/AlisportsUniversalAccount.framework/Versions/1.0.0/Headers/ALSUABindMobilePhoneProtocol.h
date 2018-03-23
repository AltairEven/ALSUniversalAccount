//
//  ALSUABindMobilePhoneProtocol.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 09/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^ALSUABindMobilePhoneSubmitBock)(NSError *, NSDictionary *);

@protocol ALSUABindMobilePhoneProtocol <NSObject>

- (NSString *)viewControllerTitle;

- (NSString *)submitBTTitle;

@optional

/**
 默认处理之前
 @param viewtag view的标示
 @return 是否继续默认处理
 */
- (BOOL)prepareActionWithTag:(NSInteger)viewtag;


/**
 默认处理之前
 @param viewtag view的标示
 */
- (void)finishActionWithTag:(NSInteger)viewtag;

/**
 是否显示提示信息

 @return 是否显示，默认NO
 */
- (BOOL)isbindTipViewShow;

@end
