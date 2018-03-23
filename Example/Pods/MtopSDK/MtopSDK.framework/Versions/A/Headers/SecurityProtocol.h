//
//  SecurityProtocol.h
//  mtopsdk
//
//  安全保镖遵守的协议
//
//  Created by sihai on 10/9/14.
//  Copyright (c) 2014 mtop. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol SecurityProtocol <NSObject>

/**
 *  获取SecurityGuardManager全局单例对象
 *
 *  @return SecurityGuardManager全局对象
 */
+ (id) getInstance;

/**
 *  获取SecurityBodyComp全局单例对象
 *
 *  @return SecurityBodyComp全局对象
 */
- (id) getSecurityBodyComp;

/**
 *  初始化人机识别模块
 *
 *  @param appKey 接入应用使用的appkey
 *
 *  @return 初始化结果
 */
- (BOOL) initSecurityBody: (NSString*) appKey;

/**
 *  获取人机识别参数
 *
 *  @param timeStamp 时间戳，要与携带人机识别参数的请求中的timestamp对应
 *
 *  @return 人机识别参数，失败时返回nil
 */
- (NSString*) getSecurityBodyData: (NSString*) timeStamp;

/**
 *  获取人机识别参数
 *
 *  @param timeStamp 时间戳，要与携带人机识别参数的请求中的timestamp对应
 *
 *  @return 人机识别参数，失败时返回nil
 */
- (NSString*) getSecurityBodyData: (NSString*) timeStamp appKey: (NSString *) appKey;

/**
 *  获取人机识别参数
 *
 *  @param timeStamp 时间戳，要与携带人机识别参数的请求中的timestamp对应
 *
 *  @param appkey 计算人机识别参数时对应的appkey（可以与初始化时的appkey不一致）
 *
 *  @param flag 控制人机识别获取到的具体数据内容，当flag为0时，行为与getSecurityBodyData接口一致,
 当flag值为1时，会采集gps信息和手机小区信息
 *
 *  @return 人机识别参数，失败时返回nil
 */
- (NSString*) getSecurityBodyDataEx: (NSString*) timeStamp appKey: (NSString*) appKey flag: (int)flag;

/**
 *  向人机识别模块写入人机识别数据
 *
 *  @param utRecord 人机识别记录，长度必须大于0
 *
 *  @return 写入结果
 */
- (BOOL) putUserTrackRecord: (NSString*) utRecord;


/**
 *  写入useraction 打点数据
 *
 *  @param pageName    打点的页面名称
 *  @param ctrlName    打点的控件名称
 *  @param xCoordinate 事件的x坐标
 *  @param yCoordinate 事件的y坐标
 *
 *  @return 写入结果
 */
- (BOOL) putUserActionRecord: (NSString*) pageName
                    ctrlName: (NSString*) ctrlName
                 xCoordinate: (float) xCoordinate
                 yCoordinate: (float) yCoordinate;

@end
