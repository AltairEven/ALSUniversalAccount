//
//  UTPlugin.h
//  miniUTSDK
//
//  Created by 玄叶 on 15/12/8.
//  Copyright © 2015年 ___SONGJUN___. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol UTPlugin <NSObject>

- (NSSet *)getAttentionEventIds;

- (NSDictionary *)onBeforeEventDispatchWithPage:(NSString *)page
                                        eventId:(NSString *)eventId
                                           arg1:(NSString *)arg1
                                           arg2:(NSString *)arg2
                                           arg3:(NSString *)arg3
                                           args:(NSString *)args;

@end
