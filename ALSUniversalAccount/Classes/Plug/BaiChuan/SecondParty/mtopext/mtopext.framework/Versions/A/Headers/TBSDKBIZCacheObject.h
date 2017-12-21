//
//  TBSDKBIZCacheObject.h
//  MtopSDK
//
//  Created by Roger.Mu on 11/26/14.
//  Copyright (c) 2014 Taobao.com. All rights reserved.
//


@interface TBSDKBIZCacheObject : NSObject


-(id) initWithBlock: (NSString *) blockName
           withSize:(int) size
       withCompress:(BOOL) compress
        withEncrypt:(BOOL) encrypt
      withRemovable:(BOOL) removable;

@property (nonatomic, strong) NSString              *blockName;
@property (nonatomic)         int                   size;
@property (nonatomic)         BOOL                  compress;
@property (nonatomic)         BOOL                  encrypt;
@property (nonatomic)         BOOL                  removable;

// cache apis config list
@property (nonatomic, strong) NSMutableArray        *apis;

@end

#pragma mark -- biz inner class of api cache information

@interface ApiCacheInfo : NSObject

@property (nonatomic, strong) NSString              *api;
@property (nonatomic, strong) NSString              *v;
@property (nonatomic, strong) NSString              *scope;
@property (nonatomic)         BOOL                  offline;
@property (nonatomic)         BOOL                  cache;
@property (nonatomic)         BOOL                  push;
@property (nonatomic, strong) NSMutableArray        *excKeyList;

-(id) initWithApiName:(NSString *) api
          withVersion:(NSString *) v
            withScope:(NSString *) scope
        withOfflineOp:(BOOL)       isOffline
            withCache:(BOOL)       isCache
             withPush:(BOOL)       isPush
 withExcludeQueryList:(NSArray *)  excKeyList;

@end
