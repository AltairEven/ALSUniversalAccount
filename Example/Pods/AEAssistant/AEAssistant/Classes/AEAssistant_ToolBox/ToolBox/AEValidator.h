//
//  AEValidator.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    AECHAR_TYPE_CHN = 1 << 0,
    AECHAR_TYPE_EN = 1 << 1,
    AECHAR_TYPE_NUM = 1 << 2,
} AECHAR_TYPE;

@interface AEValidator : NSObject

+ (BOOL)checkZipCode:(NSString *)zipCode;

+ (BOOL)checkMobilePhone:(NSString *)mobile;

+ (BOOL)checkTel:(NSString *)tel;

+ (BOOL)checkChars:(NSString *)string charType:(AECHAR_TYPE)charType;

@end
