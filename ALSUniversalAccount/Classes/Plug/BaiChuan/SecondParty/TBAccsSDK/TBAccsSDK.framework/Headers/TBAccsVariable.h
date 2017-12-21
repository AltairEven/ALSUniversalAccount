//:::'###:::::'######:::'######:::'######::
//::'## ##:::'##... ##:'##... ##:'##... ##:
//:'##:. ##:: ##:::..:: ##:::..:: ##:::..::
//'##:::. ##: ##::::::: ##:::::::. ######::
// #########: ##::::::: ##::::::::..... ##:
// ##.... ##: ##::: ##: ##::: ##:'##::: ##:
// ##:::: ##:. ######::. ######::. ######::
//..:::::..:::......::::......::::......:::
//
//  Created by 亿刀 on 15/3/25.
//  Copyright (c) 2015年 亿刀. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSUInteger, TBAccsSDKEnvironmentType)
{
    /**
     *  日常环境
     */
    TBAccsSDKEnvironmentDaily,
    
    /**
     *  预防环境
     */
    TBAccsSDKEnvironmentDebug,
    
    /**
     *  线上环境
     */
    TBAccsSDKEnvironmentRelease,
};

typedef void (^TBAccsManagerResponseBlock)(NSError *error, NSDictionary *resultsDict);

typedef NS_ENUM(NSUInteger, TBAccsRequestLeven)
{
    TBAccsSendDataLevenGeneral,
    
    //    TBAccsSendDataLevenBindUser,
    //
    //    TBAccsSendDataLevenNormal,
    //
    TBAccsSendDataLevenBindServiceId,
    
    TBAccsSendDataLevenBindApp
};

/**
 *  命令号，用来标识哪种类型的操作，目前支持的有绑定,解绑,绑定用户,解绑用户,绑定服务,解绑服务,
 */
typedef NS_ENUM(NSUInteger, TBAccsCommand){
    /**
     *  初始化标识
     */
    AccsCommandNone = 0,
    /**
     *  绑定
     */
    AccsCommandBindApp,
    /**
     *  解绑
     */
    AccsCommandUnbindApp,
    /**
     *  绑定用户
     */
    AccsCommandBindUser,
    /**
     *  解绑用户
     */
    AccsCommandUnbindUser,
    /**
     *  绑定服务
     */
    AccsCommandBindService,
    /**
     *  解绑服务
     */
    AccsCommandUnbindService,
    
    AccsCommandUpDateStatus = 7
};

/**
 *  平台类型，目前显示是iOS
 */
typedef NS_ENUM(NSInteger, TOSType)
{
    /**
     *  android平台标记
     */
    TOSTypeAndroid = 1,
    /**
     *  iOS平台标记
     */
    TOSTypeiOS = 2
};

static const uint8_t k_AccsSDK_Version = 123;       //accs_sdk 版本号
static const uint8_t k_Accs_Agreement_Version = 2;  //accs协议版本号

static const uint8_t k_un_Compress_Type = 0;
static const uint8_t k_Compress_Type = 1;

static const uint16_t max_Send_Data_length = 1024*16;   //发送数据最大限制
static const uint16_t max_Queue_Size = 1000;

typedef NS_ENUM(NSUInteger, AccsDataClass)
{
    //    ：0:内部数据，1:外部数据
    AccsDataClassInternal,
    AccsDataClassExternal
};


/**
 *  数据标识位(2位)
 */
typedef NS_ENUM(NSUInteger, AccsDataFlagType){
    /**
     *  data
     */
    AccsDataFlagTypeData = 0,
    /**
     *  ack
     */
    AccsDataFlagTypeAck,
    /**
     *  请求
     */
    AccsDataFlagTypeReq,
    /**
     *  响应
     */
    AccsDataFlagTypeRes,
};

/**
 *  错误表示位(1位)
 */
typedef NS_ENUM(NSUInteger, AccsErrorFlagType){
    /**
     *  表示数据是正常的ok
     */
    AccsErrorFlagTypeOK = 0,
    /**
     *  表示数据是错误的
     */
    AccsErrorFlagTypeError,
};

/**
 *  响应标识位  (1位)
 */
typedef NS_ENUM(NSUInteger, AccsReturnFlagType){
    /**
     *  表示该响应类型是不需要对方响应的
     */
    AccsReturnFlagTypeNoRes = 0,
    /**
     *  表示该响应类型是需要对方应答的，响应的
     */
    AccsReturnFlagTypeResNeed
};

typedef NS_ENUM(NSUInteger, AccsAppStatusFlagType)
{
    AccsAppStatusFlagTypeFront = 0,
    
    AccsAppStatusFlagTypeBackground
};

typedef NS_ENUM(NSUInteger, AccsFlagAccsType)
{
    AccsFlagAccsTypeProtocol = 0,
    
    AccsFlagAccsTypeBiz
};

typedef NS_ENUM(NSUInteger, AccsFlagNeedAccs)
{
    AccsFlagNeedAccsNO = 0,
    
    AccsFlagNeedAccsYES
};

typedef NS_ENUM(NSUInteger, AccsRequestStatus)
{
    AccsRequestStatusNoRequest = 0,
    
    //    AccsRequestStatusWaiting,
    
    AccsRequestStatusRequesting,
    
    //    AccsRequestStatusTimeOut,
    
    AccsRequestStatusSuccess,
    
    AccsRequestStatusFail
};

typedef NS_ENUM(NSUInteger, AccsCompressType)
{
    AccsCompressTypeNO,
    
    AccsCompressTypeGzip,
    
    AccsCompressTypeZlib
};


/**
 *  Accs 绑定或解绑app,user
 */
typedef NS_ENUM(NSInteger, AccsSDKOperationType) {
    
    AccsSDKOperationTypeUnKnow = -1,
    /**
     *  绑定app成功
     */
    AccsSDKOperationTypeBindAppSuccess = 100,
    /**
     *  绑定app失败
     */
    AccsSDKOperationTypeBindAppFail,
    /**
     *  解绑app通过
     */
    AccsSDKOperationTypeUnbindAppSuccess,
    /**
     *  解绑app失败
     */
    AccsSDKOperationTypeUnbindAppFail,
    /**
     *  绑定user成功
     */
    AccsSDKOperationTypeBindUserSuccess,
    /**
     *  绑定user失败
     */
    AccsSDKOperationTypeBindUserFail,
    /**
     *  解绑user成功
     */
    AccsSDKOperationTypeUnbindUserSuccess,
    /**
     *  解绑user失败
     */
    AccsSDKOperationTypeUnbindUserFail,
    /**
     *  鉴权成功
     */
    AccsSDKOperationTypeAuthSuccess,
    
    /**
     *  鉴权失败
     */
    AccsSDKOperationTypeAuthFailure,
    
    /**
     *  鉴权成功
     */
    AccsSDKOperationTypeAisleSuccess,
    
    /**
     *  鉴权失败
     */
    AccsSDKOperationTypeAisleFailure,
};

/**
 *  上行数据限流级别
 */
typedef NS_ENUM(NSUInteger, AccsRequestLimitLeven)
{
    /**
     *  没有限流
     */
    AccsRequestLimitNOLeven = 20,
    /**
     *  低级别限流
     */
    AccsRequestLimitLowLeven,
    /**
     *  搞级别限流
     */
    AccsRequestLimitHighLeven
};

/**
 *  上行数据限流类型
 */
typedef NS_ENUM(NSUInteger, AccsRequestLimitType)
{
    /**
     *  限流所有请求
     */
    AccsRequestLimitAllType = 10,
    /**
     *  限流当前bizid
     */
    AccsRequestLimitCurrentBizIDType,
    
        AccsRequestLimitCurrentServiceIDType
};

