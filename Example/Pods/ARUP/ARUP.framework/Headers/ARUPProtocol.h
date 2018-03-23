//
//  ARUPProtocol.h
//  ARUP
//
//  Created by 亿刀 on 16/1/26.
//  Copyright © 2016年 亿刀. All rights reserved.
//

@class ARUPTask;

@protocol ARUPProtocol <NSObject>

/**
 *  开始上传文件
 *
 *  @param task 上传文件的上下文
 */
+ (void)uploadDataByTask:(ARUPTask * __nonnull)task;

@end