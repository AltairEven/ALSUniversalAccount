//
//  ALSUASetPasswordProtocol.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 11/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ALSUASetPasswordProtocol <NSObject>

- (NSString *)viewControllerTitle;

- (NSString *)submitBTTitle;

- (NSString *)passwordFieldPlaceholder;

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

@end
