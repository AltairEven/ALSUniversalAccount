//
//  TBSDKSecurity.h
//  mtopsdk
//
//  Created by sihai on 10/9/14.
//  Copyright (c) 2014 mtop. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBSDKSecurity : NSObject

/**
 * 获取共享的单例
 *
 */
+ (TBSDKSecurity*) instance;

/**
 * @param timestamp             时间戳
 * @param pageName              页面名称
 * @param ctrlName              点击控件名称
 * @param xCoordinate           点击事件X坐标
 * @param yCoordinate           点击事件Y坐标
 * @param appkey                appkey
 *
 */
- (NSString*) wua: (NSString*) timestamp
         pageName: (NSString*) pageName
         ctrlName: (NSString*) ctrlName
      xCoordinate: (float) xCoordinate
      yCoordinate: (float) yCoordinate
           appkey: (NSString*) appkey
             flag: (int)flag;

/**
 * security type for hmac-sha1
 *
 * @param text                secret context
 * @param secret              secret key
 */
+ (NSString *)hmacsha1:(NSString *)text key:(NSString *)secret;
@end
