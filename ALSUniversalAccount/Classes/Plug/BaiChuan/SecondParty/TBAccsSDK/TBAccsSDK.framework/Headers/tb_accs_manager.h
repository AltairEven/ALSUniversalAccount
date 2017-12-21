//
//  tb_accs_manager.h
//  TBAccsSDK
//
//  Created by wuchen.xj on 2017/2/13.
//  Copyright © 2017年 ZhuoLaiQiang. All rights reserved.
//

#ifndef tb_accs_manager_h
#define tb_accs_manager_h

#include <string>


/**
 * 错误消息结构
 */
typedef struct {
    std::string message;
    int ecode;
} CTBAccsError;



/**
 * 环境设置
 */
typedef enum {
    kAccsEnvRelease,    // 线上
    kAccsEnvPrepare,    // 预发
    kAccsEnvDaily       // 日常
} CTBAccsEnvironment;

void tb_accs_set_environment(CTBAccsEnvironment env);


/**
 * 绑定Application回调函数
 *
 * @param is_success 是否成功
 * @param error 若失败，错误信息
 */
typedef void(*CTBAccsBindApplicationCallback)(bool is_success, CTBAccsError& error);


/**
 * 解绑定Application回调函数
 *
 * @param is_success 是否成功
 * @param error 若失败，错误信息
 */
typedef void(*CTBAccsUnbindApplicationCallback)(bool is_success, CTBAccsError& error);


/**
 * 绑定Service回调函数
 *
 * @param is_success 是否成功
 * @param error 若失败，错误信息
 */
typedef void(*CTBAccsBindServiceCallback)(bool is_success, CTBAccsError& error);



/**
 * 解绑定Service回调函数
 *
 * @param is_success 是否成功
 * @param error 若失败，错误信息
 */
typedef void(*CTBAccsUnbindServiceCallback)(bool is_success, CTBAccsError& error);



/**
 * 下行数据回调函数
 *
 * @param service_id 下行消息的service_id
 * @param data_id  下行消息的data_id
 * @param data 下行的数据
 */
typedef void(*CTBAccsNotificationDataCallback)(std::string& service_id, std::string& data_id, std::string& data);



/**
 * 上行数据回调函数
 *
 * @param service_id 发送消息的service_id
 * @param data_id 发送消息的data_id
 * @param response_json 返回的response
 * @param error 错误信息
 */
typedef void(*CTBAccsResponseCallback)(std::string& service_id,
                                        std::string& data_id,
                                        std::string& response_json,
                                        CTBAccsError& error);



/**
 * 启动Accs
 *
 * return =0 表示成功，<0表示失败
 */
int tb_accs_manager_start();


/**
 * 绑定Application
 *
 * @param device_token 设备token, 如果需要用的APNS的话，可以直接使用apple token
 * @param callback 绑定回调
 * return =0 表示成功，<0表示失败
 */
int tb_accs_manager_bind_application(std::string& device_token, CTBAccsBindApplicationCallback callback);


/**
 * 解绑定Application
 *
 * @param callback 回调
 * return =0 表示成功，<0表示失败
 */
int tb_accs_manager_unbind_application(CTBAccsUnbindApplicationCallback callback);


/**
 * 绑定Service
 *
 * @param service_id    业务id
 * @param action_callback 绑定是否成功的回调
 * @param data_callback 收到数据后的回调
 * @param sync 同步还是异步，true 表示同步， false 表示异步
 * return =0 表示成功，<0表示失败
 */
int tb_accs_manager_bind_service(std::string& service_id,
                                 CTBAccsBindServiceCallback action_callback,
                                 CTBAccsNotificationDataCallback data_callback,
                                 bool sync);

/**
 * 解绑定Service
 *
 * @param service_id    业务id
 * @param action_callback 解绑定是否成功的回调
 * return =0 表示成功，<0表示失败
 */
int tb_accs_manager_unbind_service(std::string& service_id, CTBAccsUnbindServiceCallback action_callback);


/**
 * 发送数据, 响应为异步响应，注意：大小限制为16k
 *
 * @param service_id 业务id
 * @param data 需要发送的数据
 * @param length 需要发送的数据的长度
 * @param user_id 用户id,可选，如果没有，填空即可
 * @param timeout 发送数据超时时间
 * @param retry_interval 在没有超时前，重试的间隔
 * @param call_back  请求响应回调
 * 返回data_id，如果返回data_id为空，说明发送失败。但data_id不为空不代表发送成功
 */
std::string tb_accs_manager_send_data(const char* data,
                                      unsigned long length,
                                      std::string& service_id,
                                      std::string& user_id,
                                      double timeout,
                                      double retry_interval,
                                      CTBAccsResponseCallback call_back);


/**
 *  终止一个网络请求，如果这个请求还没有发送成功，这个请求会被终止发送。
 *  如果这个请求已经发送，cancel后，如果收到响应也不再会继续回调
 *
 * @param data_id tb_accs_manager_send_data返回的data_id
 *
 * return =0 表示成功，<0表示失败
 */
int tb_accs_manager_cancel_send(std::string& data_id);


/**
 * 控制日志开关
 *
 * @param flag 1：打开日志； 0:关闭日志
 */
void tb_accs_log_ctrl(int flag);

#endif /* tb_accs_manager_h */
