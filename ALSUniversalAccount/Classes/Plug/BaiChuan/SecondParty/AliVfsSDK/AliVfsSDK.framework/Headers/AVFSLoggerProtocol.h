//
//  AVFSLoggerProtocol.h
//  AliVfsSDK
//
//  Created by Dafeng Jin on 16/3/14.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AVFSLoggerProtocol <NSObject>

/**
 *  记录业务操作成功接口
 *
 *  @param page   页面名称,安卓iOS要相同. 命名规范:若之前埋点有页面名,则用原来的; 否则用"业务名_页面名"(无页面则"业务名"); 采用首字母大写驼峰方式. 如Shop_Detail, Shop_List
 *  @param monitorPoint 监控点名称,安卓iOS要相同,从@雷曼 获取
 *  @arg 附加参数，用于做横向扩展
 */
+ (void)commitSuccessWithPage:(NSString *)page monitorPoint:(NSString *)monitorPoint arg:(NSString *)arg;

/**
 *  记录业务操作失败接口
 *
 *  @param page   页面名称,安卓iOS要相同. 命名规范:若之前埋点有页面名,则用原来的; 否则用"业务名_页面名"(无页面则"业务名"); 采用首字母大写驼峰方式. 如Shop_Detail, Shop_List
 *  @param monitorPoint 监控点名称,安卓iOS要相同,从@雷曼 获取
 *  @param errorCode 错误码，若为MTOP请求则传MTOP的错误码,否则请业务方对错误进行分类编码,方便统计错误类型占比
 *  @param errorMsg  错误信息，若位MTOP请求则传MTOP的错误信息, 否则请业务方自己描述错误, 方便自己查找原因
 *  @arg 附加参数，用于做横向扩展
 */
+ (void)commitFailWithPage:(NSString *)page monitorPoint:(NSString *)monitorPoint errorCode:(NSString *)errorCode errorMsg:(NSString *)errorMsg arg:(NSString *)arg;

/**
 * 注册性能埋点
 * @param module 模块
 * @param monitorPoint 监控点
 * @param measures 多指标
 * @param dimemsions 多维度
 */
+ (void)registerWithModule:(NSString *)module monitorPoint:(NSString *)monitorPoint measureSet:(NSArray*)measures dimensionSet:(NSArray*)dimensions;

/**
 * 提交多维度，多指标
 * @param module 监控模块
 * @param monitorPoint 监控点名称 Page+monitorPoint必须唯一
 * @param dimensionValues 维度值集合
 * @param measureValues 指标值集合
 */
+ (void)commitWithModule:(NSString*) module monitorPoint:(NSString *)monitorPoint dimensionValueSet:(NSDictionary*)dimensionValues measureValueSet:(NSDictionary*)measureValues;

@end
