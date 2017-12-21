//
//  NSDate+CommonDate.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (CommonDate)
/**
 *  当前GMT时间
 *
 *  @return 当前GMT时间
 */
+ (NSDate *)GMTNow;
/**
 *  当前时间戳
 *
 *  @return 当前时间戳
 */
+ (NSTimeInterval)nowTimeStamp;

@end
