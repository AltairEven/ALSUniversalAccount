//
//  AVFSObjectContext.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/8/17.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AVFSObject;

@interface AVFSObjectContext : NSObject

/**
 *  添加对象到上下文
 *
 *  @param anObject 元对象
 */
- (void)insertObject:(AVFSObject*)anObject;

/**
 *  从上下文删除对象
 *
 *  @param anObject 元对象
 */
- (void)deleteObject:(AVFSObject*)anObject;

/**
 *  判断上下文是否包含对象
 *
 *  @param anObject 元对象
 *
 *  @return 是否包含
 */
- (BOOL)containsObject:(AVFSObject*)anObject;

/**
 *  提交事务上下文
 *
 *  @return 是否成功，不成功则回滚事务
 */
- (BOOL)commit;

@end
