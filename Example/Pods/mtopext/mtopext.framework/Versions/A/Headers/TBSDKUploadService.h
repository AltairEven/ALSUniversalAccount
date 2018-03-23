//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//
//  Created by jin.zheng on 14-1-16.
//  Modified by sihai on 14-07-28
//  Copyright (c) 2014年 Taobao.com. All rights reserved.
//


#import <Foundation/Foundation.h>

#import "Constants.h"
#import "TBSDKServerDelegate.h"

// 错误代码
typedef enum {
    
    // 请求成功
    kTBSDKUploadServiceSuccess = 1,
    // 上传文件错误，文件不存在或者读取错误
    kTBSDKUploadServiceFileErrorType,
    // 生成Token错误
    kTBSDKUploadServiceTokenErrorType,
    // 请求参数设置错误
    kTBSDKUploadServiceParamErrorType,
    // status code 返回Error
    kTBSDKUploadServiceStatusCodeErrorType,
    // 服务端返回错误
    kTBSDKUploadServiceXMsgErrorType,
    // 请求超时
    kTBSDKUploadServiceRequestTimedOutErrorType,
    // 请求无法连接，无网络
    kTBSDKUploadServiceConnectionFailureErrorType,
    // 请求Session过期
    kTBSDKUploadServiceSessionExpireErrorType,
    // 其他未知错误
    kTBSDKUploadServiceUnKnowErrorType,
    
} kTBSDKUploadServiceErrorType;

/** 传输类型 */
typedef enum
{
    TBSDKUploadType_Resumable =  1,     /** 断点续传类型 */
    TBSDKUploadType_Normal              /** 一般上传类型 */
} TBSDKUploadType;

typedef void (^TBSDKUploadCompletedBlock)(BOOL success, NSURL *fileURL, NSError *error);

/**
 * 文件上传错误类型
 */
#define ERROR_TYPE_SUCCEED                  @"SUCCEED"                  // 成功
#define ERROR_TYPE_ILLEGAL_FILE_ERROR       @"ILLEGAL_FILE_ERROR"       // 文件错误
#define ERROR_TYPE_NETWORK_ERROR            @"NETWORK_ERROR"            // 网络错误
#define ERROR_TYPE_UPLOAD_CONTENT_ERROR     @"UPLOAD_CONTENT_ERROR"     // 文件内容错误
#define ERROR_TYPE_SESSION_EXPIRE           @"SESSION_EXPIRE"           // Session过期
#define ERROR_TYPE_OTHER_UPLOAD_ERROR       @"OTHER_UPLOAD_ERROR"       // 其他错误
#define ERROR_TYPE_TOKEN_ERROR              @"TOKEN_ERROR"

/**
 *
 */
#define ERROR_CODE_UNSUPPORTED_FILE_TYPE    @"FAIL_BIZ_UNSUPPORTED_FILE_TYPE"
#define ERROR_CODE_UNCERTAIN_FILE_TYPE      @"UNCERTAIN_FILE_TYPE"
#define ERROR_CODE_UNMATCH_FILE_TYPE        @"UNMATCH_FILE_TYPE"
#define ERROR_CODE_WRONG_FILE_SIZE          @"FAIL_BIZ_WRONG_FILE_SIZE"


/**
 * 文件上传sdk级别错误
 */
#define ERROR_FILE_NOT_EXISTS               @"FILE_NOT_EXISTS"
#define ERROR_MSG_FILE_NOT_EXISTS           @"无法读取需要上传的文件"
#define ERROR_FILE_CONTENT_EMTPY            @"FILE_CONTENT_EMPTY"
#define ERROR_MSG_FILE_CONTENT_EMTPY        @"需要上传的文件内容为空"

/**
 * 网络错误
 */
#define ERROR_CODE_NO_NETWORK               @"tbsdk request not network"
#define ERROR_CODE_NETWORK_TIMOUT           @"tbsdk request timeout"
#define ERROR_CODE_NETWORK                  @"NETWORK_ERROR"
#define ERROR_MSG_NETWORK                   @"网络错误"

/**
 * 无效的mtop响应
 */
#define ERROR_INVALID_MTOP_RESPONSE         @"ERROR_INVALID_MTOP_RESPONSE"
#define ERROR_MSG_INVALID_MTOP_RESPONSE     @"无效的mtop响应"

/**
 * 多次重试后失败
 */
#define ERROR_RETRY_EXCEED                  @"ERROR_RETRY_EXCEED"
#define ERROR_MSG_RETRY_EXCEED              @"多次重试失败"

/**
 * 无效的mtop-upload响应
 */
#define ERROR_INVALID_MTOP_UPLOAD_RESPONSE      @"ERROR_INVALID_MTOP_UPLOAD_RESPONSE"
#define ERROR_MSG_INVALID_MTOP_UPLOAD_RESPONSE  @"无效的mtop上传服务响应"

/**
 * 未知错误
 */
#define ERROR_UNKNOWN                       @"ERROR_UNKNOWN"
#define ERROR_MSG_UNKNOWN                   @"未知错误"


typedef void (^TBSDKUploadResultBlock)(NSURL* fileURL);
typedef void (^TBSDKUploadFailureBlock)(NSString* errorMsg);

/**
 * 新版错误回调
 * param errorType      错误类型
 * param errorCode      错误码
 * param errorMsg       错误信息
 */
typedef void (^TBSDKUploadFailureBlockV2) (NSString* errorType, NSString* errorCode, NSString* errorMsg);

typedef void (^TBSDKUploadProgressBlock)(long long bytesWritten, long long bytesTotal);

@interface TBSDKUploadService : NSObject <NSURLConnectionDelegate, TBSDKServerDelegate>

@property (nonatomic, copy) TBSDKUploadResultBlock resultBlock;
@property (nonatomic, copy) TBSDKUploadFailureBlock failureBlock;
@property (nonatomic, copy) TBSDKUploadFailureBlockV2 failureBlockV2;
@property (nonatomic, copy) TBSDKUploadProgressBlock progressBlock;
// 优化新接口回调 龙冥添加
@property (nonatomic, copy) TBSDKUploadCompletedBlock completedBlock;
@property (nonatomic, readonly) NSString *protocolType;

/*!
 ** 通过文件路径上传 （登录后才能成功上传，不然会拉起登录界面）
 *
 *  filePath         文件名
 *  uploadType       传输类型(可选)，值包括：resumable、normal，默认值为 resumable
 *  bizCode          media center分配的业务代码
 *  userNick         图片的owner的nick
 *  privateData      上传业务方的私有数据，透传到后端的Map
 */
-(void)uploadFilePath:(NSString *) filePath
           uploadType:(TBSDKUploadType) uploadType
              bizCode:(NSString *) bizCode
             userNick:(NSString *) userNick
          privateData:(NSDictionary *) privateData;

/*!
 ** 通过内存数据上传（登录后才能成功上传，不然会拉起登录界面）
 *
 *  stream           文件数据
 *  fileName         文件名 （随便构造一个只要后缀名对就OK，只是用来识别文件类型）
 *  uploadType       传输类型(可选)，值包括：resumable、normal，默认值为 resumable
 *  bizCode          media center分配的业务代码
 *  userNick         图片的owner的nick
 *  privateData      上传业务方的私有数据，透传到后端的Map
 */
-(void) uploadFileStream: (NSData *) stream
                fileName: (NSString *) fileName
              uploadType:(TBSDKUploadType) uploadType
                 bizCode:(NSString *) bizCode
                userNick:(NSString *) userNick
             privateData:(NSDictionary *) privateData;


/*!
 ** 登录或非登录状态下通过文件路径上传
 *
 *  filePath         文件名
 *  uploadType       传输类型(可选)，值包括：resumable、normal，默认值为 resumable
 *  bizCode          media center分配的业务代码
 *  userNick         图片的owner的nick
 *  privateData      上传业务方的私有数据，透传到后端的Map
 */
-(void)anonymousUploadFilePath:(NSString *) filePath
                    uploadType:(TBSDKUploadType) uploadType
                       bizCode:(NSString *) bizCode
                      userNick:(NSString *) userNick
                   privateData:(NSDictionary *) privateData;


/*!
 ** 登录或非登录状态下通过内存数据上传
 *
 *  stream           文件数据
 *  fileName         文件名（随便构造一个只要后缀名对就OK，只是用来识别文件类型）
 *  uploadType       传输类型(可选)，值包括：resumable、normal，默认值为 resumable
 *  bizCode          media center分配的业务代码
 *  userNick         图片的owner的nick
 *  privateData      上传业务方的私有数据，透传到后端的Map
 */
-(void) anonymousuploadFileStream: (NSData *) stream
                         fileName: (NSString *) fileName
                       uploadType:(TBSDKUploadType) uploadType
                          bizCode:(NSString *) bizCode
                         userNick:(NSString *) userNick
                      privateData:(NSDictionary *) privateData;


/*
 ** 开始上传 **
 */
- (void) startUpload;

/**
 * 开始上传
 */
- (void) rfus_upload;

/*!
 * 取消上传
 *
 */
- (void) cancel;

/*
 ** 提供给JAE判断该host是否为可信任的上传服务器 **
 *
 * -- 每次从MTOP获取到上传服务器host时即放入白名单列表内
 */
+(BOOL)isTrustHost:(NSString *) host;

// 龙冥 optimize 上传优化初始化接口
- (instancetype)initWithData:(NSData *)fileData
                    fileName:(NSString *)fileName
                  uploadType:(TBSDKUploadType)uploadType
                     bizCode:(NSString *)bizCode
                    userNick:(NSString *)userNick
                 privateData:(NSDictionary *)privateData;

- (void)startUploader;

@end
