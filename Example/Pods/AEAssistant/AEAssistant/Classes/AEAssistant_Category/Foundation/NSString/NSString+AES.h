//
//  NSString+AES.h
//  AEAssistant_Category
//
//  Created by Qian Ye on 16/6/14.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    AESOperationEncrypt,
    AESOperationDecrypt
}AESOperation;

typedef enum {
    AEOptionCBCMode        = 0x0000,
    AEOptionPKCS7Padding   = 0x0001,
    AEOptionECBMode        = 0x0002
}AEOptions;

@interface NSString (AES)

- (NSString *)AES128Operation:(AESOperation)operation withKey:(NSString *)key vector:(NSString *)vector mode:(AEOptions)options;   //AES128加解密

- (NSString *)AES256Operation:(AESOperation)operation withKey:(NSString *)key mode:(AEOptions)options;   //AES256加解密

@end
