//
//  ARUPClient.h
//  ARUP
//
//  Created by 亿刀 on 16/1/26.
//  Copyright © 2016年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>

/****************************************************
 *                                                  *
 *  arup协议，全称： ali resumable upload protocol    *
 *                                                  *
 ****************************************************/

@protocol ARUPProtocol;

@interface ARUPClient : NSObject

/**
 *  获取工具类
 *
 */
+ (id <ARUPProtocol>_Nonnull)createUploader;

@end
