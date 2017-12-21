//:::'###:::::'######:::'######:::'######::
//::'## ##:::'##... ##:'##... ##:'##... ##:
//:'##:. ##:: ##:::..:: ##:::..:: ##:::..::
//'##:::. ##: ##::::::: ##:::::::. ######::
// #########: ##::::::: ##::::::::..... ##:
// ##.... ##: ##::: ##: ##::: ##:'##::: ##:
// ##:::: ##:. ######::. ######::. ######::
//..:::::..:::......::::......::::......:::
//
//  Created by 亿刀 on 15/3/27.
//  Copyright (c) 2015年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>


#define ERROR_UN_KNOW_ERROR                                 7000
#define ERROR_REQUEST_TIME_OUT_ERROR                        7001
#define ERROR_MAKE_REQUEST_ERROR                            7002
#define ERROR_NO_HAVE_CHANNEL_ERROR                         7003
#define ERROR_SEND_FRAME_ERROR                              7004
#define ERROR_ACCS_ERROR_FLAG_TYPE_ERROR                    7005
#define ERROR_NOT_HAVE_NETWORK_ERROR                        7006
#define ERROR_MORE_THAN_THE_NUMBER_OF_RETRIES_ERROR         7007
#define ERROR_COUNT_OF_QUEUE_IS_MAX_ERROR                   7008
#define ERROR_SERVICEID_CAN_NOT_NIL_ERROR                   7009
#define ERROR_ONE_REQUEST_TIME_OUT_ERROR                    70010
#define ERROR_USERID_CAN_NOT_NIL_ERROR                      70011
#define ERROR_SEND_DATA_SIZE_MORE_THAN_MAX_SIZE_ERROR       70013
#define ERROR_CONTEXT_IS_NULL_ERROR                         70014
#define ERROR_EXT_HEADER_MORE_THAN_MAX_ERROR                70015
#define ERROR_APP_KEY_CAN_NOT_NULL_ERROR                    70016
#define ERROR_MAKE_REQUEST_PARAMETERS_CAN_NOT_NIL_ERROR     70017
#define ERROR_JSON_TO_DATA_ERROR                            70018
#define ERROR_SEND_DATA_CAN_NOT_NIL_ERROR                   70019
#define ERROR_HIGH_LEVEL_LIMITING_ERROR                     70021  //服务端高级别限流，客户端在一段时间，不发起任何请求
#define ERROR_LOW_LEVEL_LIMITING_ERROR                      70020  //服务端低级别限流，客户端会每隔几毫秒发一个请求，给服务端减轻压力
#define ERROR_ANTI_BRUSH_ERROR                              70022  //客户端QPS过高，用户需要输入验证码，客户端才可以继续发请求
#define ERROR_RESPONSE_CONTROLER_PAR_ERROR                  70023
#define ERROR_RESPONSE_NOT_FIND_RSPONSE                     70024

#define ERROR_ACCS_NOT_STARTED                              70030
#define ERROR_ACCS_UNBIND_APP                               70031
#define ERROR_ACCS_SERVICE_ID_ERROR                         70032
#define ERROR_ACCS_RECEIVE_CALLBACK_ERROR                   70033
