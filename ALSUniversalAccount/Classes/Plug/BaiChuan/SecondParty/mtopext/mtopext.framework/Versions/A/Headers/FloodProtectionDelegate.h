//
//  FloodProtectionDelegate.h
//  mtopext
//
//  防刷delegate
//
//  Created by sihai on 2/12/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MtopExtResponse.h"

@protocol FloodProtectionDelegate <NSObject>

/*!
 * 回调
 * @param response
 */
- (void) callback: (MtopExtResponse*) response;

@end
