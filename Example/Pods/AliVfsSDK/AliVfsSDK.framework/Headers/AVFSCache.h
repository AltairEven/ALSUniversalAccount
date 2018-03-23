//
//  AVFSCache.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/2/18.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AVFSSQLiteCache.h"
#import "AVFSFileCache.h"
#import "AVFSLevelFileCache.h"
#import "AVFSCacheConstants.h"
#import "AVFSStreamCache.h"

@class AVFSMemoryCache;

@interface AVFSCache : NSObject
{
    @public
    AVFSMemoryCache *_memCache;
    AVFSSQLiteCache *_sqliteCache;
    AVFSFileCache *_fileCache;
    AVFSLevelFileCache *_levelFileCache;
    AVFSStreamCache *_streamCache;
}
/**
 *  缓存模块
 */
@property (copy, readonly) NSString *moduleName;

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 *  缓存清理策略
 **/
@property (nonatomic, assign) AVFSCachePolicy cachePolicy;
/**
 *  过期时间
 **/
@property (nonatomic, assign) long long expireDate;
/**
 *  容量大小限制
 **/
@property (nonatomic, assign) long long limitSize;


/**
 *  内存缓存
 *
 *  @return 内存缓存
 */
- (AVFSMemoryCache *)memCache;

/**
 *  KV文件缓存
 *
 *  @return 文件缓存
 */
- (AVFSFileCache *)fileCache;

/**
 *  KV拓展文件缓存，拓展的意思是需要两个key：主key和拓展key两个结合才能拿到唯一数据，否则主key可能对应多条数据。目前是为了满足图片库分级模型需求
 *
 *  @return 拓展文件缓存
 */
- (AVFSLevelFileCache *)levelFileCache;

/**
 *  KV数据库缓存
 *
 *  @return KV数据库缓存
 */
- (AVFSSQLiteCache *)sqliteCache;

/**
 *  流式大文件缓存
 *
 *  @return 流式大文件缓存
 */
- (AVFSStreamCache *)streamCache;

@end
