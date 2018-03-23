//
//  ARUPTask.h
//  ARUP
//
//  Created by 亿刀 on 16/1/26.
//  Copyright © 2016年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ARUPResponse;
@class ARUPConfiguration;
@class ARUPTask;
@class ARUPFileInfo;
@protocol ARUPFileHandleDelegate;

typedef enum {
    ARUP_NotReachable = 0,
    ARUP_ReachableViaWiFi,
    ARUP_ReachableVia2G,
    ARUP_ReachableVia3G,
    ARUP_ReachableVia4G
} ARUPNetworkStatus;

/**
 *  上传进度block
 *
 *  @param task     上传任务
 *  @param fileInfo 文件资料
 *  @param progress 进度 ： 1-100
 */
typedef void (^ProgressBlock)(ARUPTask * _Nonnull task, ARUPFileInfo * _Nonnull fileInfo,float progress);

/**
 *  上传失败
 *
 *  @param task     上传任务
 *  @param fileInfo 上传资料
 *  @param error    错误描述
 */
typedef void (^FailureBlock)(ARUPTask * __nonnull task, ARUPFileInfo * _Nonnull fileInfo, NSError * __nonnull error);

/**
 * 上传成功
 *
 *  @param task     上传任务
 *  @param fileInfo 上传资料
 *  @param response 服务端返回信息
 */
typedef void (^SuccessBlock)(ARUPTask * __nonnull task, ARUPFileInfo * _Nonnull fileInfo, ARUPResponse * __nonnull response);

/**
 *  网络变化回调
 *
 *  @param task     上传任务
 *  @param fileInfo 上传资料
 *  @param from     网络原始状态
 *  @param to       网络变更后状态  
 */
typedef void (^NetworkSwitchBlock)(ARUPTask * __nonnull task, ARUPFileInfo * _Nonnull fileInfo, ARUPNetworkStatus from, ARUPNetworkStatus to);

/**
 *  上传任务的上下文
 */
@interface ARUPTask : NSObject

/* 文件信息  */
@property (nonnull, nonatomic, readonly         ) ARUPFileInfo  *fileInfo;

/* 任务标示 */
@property (readonly                             ) NSUInteger    taskIdentifier;

/* 上下问 */
@property (nonatomic, strong, nullable          ) id            userInfo;

/* 进度回调 */
@property (nonatomic, readonly, nonnull, copy   ) ProgressBlock progressBlock;

/* 成功回调 */
@property (nonatomic, readonly, nonnull, copy   ) SuccessBlock  successBlock;

/* 失败回调 */
@property (nonatomic, readonly, nonnull, copy   ) FailureBlock  failureBlock;

/* 网络变化回调 */
@property (nonatomic, readonly, nonnull, copy   ) NetworkSwitchBlock networkSwitch;

/* 业务id */
@property (nonnull, nonatomic, strong, readonly ) NSString      *bizType;


/**
 *  初始化上传任务
 *
 *  @param fileInfo      上传文件信息
 *  @param bizType       业务ID
 *  @param progress      进度回调
 *  @param success       成功回调
 *  @param faile         失败回调
 *  @param networkSwitch 网络变更回调
 *  @param error         错误描述
 *
 *  @return 上传任务对象
 */
- (id _Nonnull)initWithFileInfo:(ARUPFileInfo * _Nonnull)fileInfo
                       bizeType:(NSString *_Nonnull)bizType
                       propress:(ProgressBlock _Nullable )progress
                        success:(SuccessBlock _Nullable )success
                          faile:(FailureBlock _Nullable )faile
                  networkSwitch:(NetworkSwitchBlock _Nullable)networkSwitch
                          error:(NSError *_Nonnull*_Nonnull)error;

/* 暂停 */
- (void)suspend;

/* 继续 */
- (void)resume;

/**
 *  取消上传任务
 *
 *  @param fileInfo 初始化task的FileInfo
 */
- (void)cancelWithFileInfo:(ARUPFileInfo *_Nonnull)fileInfo;

@end

@interface ARUPFileInfo : NSObject

/* 文件名 */
@property (nonatomic, nonnull, strong, readonly) NSString                       *fileName;

/* 文件路径 */
@property (nonatomic, nonnull, strong, readonly) NSString                       *filePath;

/* 扩展头 */
@property (nonatomic, nullable, strong, readonly) NSDictionary                  *xArupMeta;

/* 文件id */
@property (nonatomic, nullable, strong, readonly) NSString                      *fileID;

/* 文件md5 */
@property (nonatomic, nullable, strong, readonly) NSString                      *fileMD5;

/* 文件大小 */
@property (nonatomic, assign, readonly          ) double                        fileSize;

@property (nonatomic, assign,readonly           ) double                        fileMD5ConsumeTime;


/**
 *  初始化文件资料对象
 *
 *  @param filePath     文件路径
 *  @param fileName     文件名字
 *  @param xArupMeta    扩展头，无特殊需要可以忽略
 *  @param xArupCusMeta 扩展头，无特殊需要可以忽略
 *  @param error        错误描述对象
 *
 *  @return 文件资料对象
 */
- (id __nullable)initWithFilePath:(NSString *_Nonnull)filePath
                         fileName:(NSString *_Nonnull)fileName
                        xArupMeta:(NSDictionary *_Nullable)xArupMeta
                            error:(NSError *_Nonnull*_Nonnull)error;

- (id __nullable)initWithFilePath:(NSString *_Nonnull)filePath
                         fileName:(NSString *_Nonnull)fileName
                        xArupMeta:(NSString *_Nullable)xArupMeta
                     xArupCusMeta:(NSString *_Nullable)xArupCusMeta
                            error:(NSError *_Nonnull*_Nonnull)error DEPRECATED_MSG_ATTRIBUTE("此函数已经废弃，请使用上面的函数");;


@end
