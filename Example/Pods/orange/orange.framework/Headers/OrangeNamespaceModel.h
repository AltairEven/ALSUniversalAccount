//
//  OrangeNamespaceModel.h
//  orange
//
//  Created by shiting.lst on 15/9/1.
//  Copyright (c) 2015年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OrangeIndexNamespaceModel;
@class OrangeIPStrategy;

@interface OrangeNamespaceModel : NSObject <NSCopying>

/** appKey */
@property (nonatomic,copy) NSString *appKey;

/** 客户端版本 */
@property (nonatomic,copy) NSString *appVersion;

/** namespace id */
@property (nonatomic,copy) NSString *namespaceId;

/** 名称 */
@property (nonatomic,copy) NSString *name;

/** 资源id */
@property (nonatomic,copy) NSString *resourceId;

/** 类型 */
@property (nonatomic,copy) NSString *type;

/** 类型 */
@property (nonatomic,copy) NSString *loadLevel;

/** 版本 */
@property (nonatomic,copy) NSString *version;

/** 配置更新成功时间(客户端时间) */
@property (nonatomic,copy) NSString *updateTime;

/** 配置数据 */
@property (nonatomic,strong) id content;

/** 是否为候选配置 */
@property (nonatomic,assign) BOOL isCandidate;

//@property (nonatomic,strong) NSDictionary *dict;

/** 初始化方法
 *
 *  @param  dict
 */
-(id)initWithDict:(NSDictionary *)dict;

@end



@interface OrangeNamespaceRequest : NSObject

@property (nonatomic, assign) BOOL requesting;

@property (nonatomic, assign) int cdnReqeustTime;

@property (nonatomic, assign) int apiServerReqeustTime;

@property (nonatomic, assign) int cdnMaxRetry;

@property (nonatomic, assign) int apiServerMaxRetry;

@property (nonatomic, strong) OrangeIPStrategy *ipStrategy;

@property (nonatomic, strong) NSString *url;

@property (nonatomic, copy) NSString *protocol;

@property (nonatomic, strong) OrangeIndexNamespaceModel *indexNamespaceModel;

@end
