//
// SecurityGuardSDK version 2.3.0
//

#import <Foundation/Foundation.h>

@protocol ISecurityBodyComponent <NSObject>

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
 *  @param appkey 计算人机识别参数时对应的appkey（可以与初始化时的appkey不一致）
 *
 *  @return 人机识别参数，失败时返回nil
 */
- (NSString*) getSecurityBodyData: (NSString*) timeStamp appKey: (NSString*) appKey;



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

/**
 *  设置人机识别配置服务器，注意，此接口只有在人机识别其他接口被调用之前调用才有效果
 *
 *  @param serverConfig 0代表连接国内服务器；1代表连接美国服务器；默认为0
 */
- (void) setSecurityBodyServer: (NSInteger) serverConfig;

@end
