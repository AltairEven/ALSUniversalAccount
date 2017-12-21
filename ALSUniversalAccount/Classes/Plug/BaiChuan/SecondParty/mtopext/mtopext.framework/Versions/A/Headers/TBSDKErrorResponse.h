//    '########'########::'######:'########:'##:::'##:
//    ... ##..::##.... ##'##... ##:##.... ##:##::'##::
//    ::: ##::::##:::: ##:##:::..::##:::: ##:##:'##:::
//    ::: ##::::########:. ######::##:::: ##:#####::::
//    ::: ##::::##.... ##:..... ##:##:::: ##:##. ##:::
//    ::: ##::::##:::: ##'##::: ##:##:::: ##:##:. ##::
//    ::: ##::::########:. ######::########::##::. ##:
//    :::..::::........:::......::........::..::::..::
//
//  Created by 亿刀 on 13-1-31.
//  Copyright (c) 2013年 Taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MtopSDK/TBSDKErrorRule.h>

/** TBSDK的错误描述类
 *
 *  如果此类不满足调用者的要求，调用者可以继承TBSDKError创建自己的错误描述类。
 *
 */
@interface TBSDKErrorResponse : NSObject<TBSDKErrorRule>

//! 服务器返回的错误码
@property (nonatomic, strong) NSString                                          *errorCode;

//! 错误信息
@property (nonatomic, strong) NSString                                          *msg;

//! 子错误代码
@property (nonatomic, strong)  NSString                                         *sub_code;

//! 子错误信息
@property (nonatomic, strong)  NSString                                         *sub_msg;

//! 调用接口时传递的参数
@property (nonatomic, strong)  NSDictionary                                     *args;

//! 原始错误信息
@property (nonatomic, strong)  NSDictionary                                     *raw;

//开发调试使用的参数，用于存放代码出错的位置(__FUNCTION__, __LINE__)
@property (nonatomic, strong) NSString                                          *errorLocation;

@property (nonatomic, strong) NSError                                           *error;

+ (id)modelWithJSON:(NSDictionary *)json;

- (id)initWithDictionary:(NSDictionary *)dict;

- (BOOL)isAuthenticationError;

@end
