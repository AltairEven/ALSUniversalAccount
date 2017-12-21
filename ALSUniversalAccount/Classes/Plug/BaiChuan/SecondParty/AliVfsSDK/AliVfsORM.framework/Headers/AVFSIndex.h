//
//  AVFSIndex.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/8/16.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import "AVFSObject.h"
#import "AVFSQuery.h"

@interface AVFSIndex : NSObject

@property (nonatomic, copy) NSString *property;
@property (nonatomic, assign) AVFSSortOrder order;

/**
 *  生成索引
 *
 *  @param property 要索引的属性
 *  @param order    排序方式
 *
 *  @return 索引
 */
+ (AVFSIndex *)indexForProperty:(NSString *)property withOrder:(AVFSSortOrder)order;

@end
