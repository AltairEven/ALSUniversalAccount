//
//  AVFSModuleConfig.h
//  AliVfsMonitor
//
//  Created by 宋龙彪 on 2017/12/25.
//  Copyright © 2017年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef BOOL(^ModuleMachingBlock)(NSString *file,NSString *path);

@interface AVFSModuleConfig : NSObject
@property (nonatomic, strong) NSString *moduleName;
@property (nonatomic, strong) NSString *modulePath;
@property (nonatomic, strong) NSString *moduleFileName;
@property (nonatomic, strong) NSString *modulePredicate;
@property (nonatomic, assign) BOOL isRemove;
@property (nonatomic, copy) ModuleMachingBlock moduleMachingBlock;
/**
 * 初始化方法
 * @param data  :   JSON数据
 * @return 对象实例
 **/
- (instancetype)initWithData:(NSDictionary *)data;

- (BOOL)machingModuleWithFile:(NSString *)file andPah:(NSString *)Path;

@end
