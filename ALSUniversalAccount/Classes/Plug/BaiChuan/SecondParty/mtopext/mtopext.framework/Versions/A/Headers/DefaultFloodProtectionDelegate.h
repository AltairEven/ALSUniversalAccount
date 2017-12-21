//
//  DefaultFloodProtectionDelegate.h
//  mtopext
//
//  Created by sihai on 2/12/14.
//  Copyright (c) 2014 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FloodProtectionDelegate.h"

@interface DefaultFloodProtectionDelegate : NSObject<FloodProtectionDelegate>

/*!
 * 初始化单例
 * @return DefaultFloodProtectionDelegate
 */
+(DefaultFloodProtectionDelegate*) getInstance;

@end
