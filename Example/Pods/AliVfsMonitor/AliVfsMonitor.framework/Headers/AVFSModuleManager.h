//
//  AVFSModuleManager.h
//  AliVfsMonitor
//
//  Created by 宋龙彪 on 2017/12/25.
//  Copyright © 2017年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVFSModuleConfig.h"
@interface AVFSModuleManager : NSObject
@property (nonatomic ,strong) NSMutableArray *configArr;/**< module配置数组 */
/**
 * 获取单例对象
 * @return 单例对象
 **/
+ (AVFSModuleManager *)sharedManager;

/**
 * 获取单例对象
 * @return 单例对象
 **/
- (AVFSModuleConfig *)checkModuleWithFile:(NSString *)file andPah:(NSString *)Path;
@end
