//
//  AEValidator.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "AEValidator.h"
#import "RegexKitLite.h"

@implementation AEValidator

+ (BOOL)checkZipCode:(NSString *)zipCode
{
    if (!zipCode) {
        return YES;
    }
    
    if (![zipCode stringByMatching: @"^\\d{6}$"]) {
        return NO;
    }
    
    return YES;
}
+ (BOOL)checkMobilePhone:(NSString *)mobile
{
    if (!mobile) {
        return YES;
    }
    
    if (![mobile stringByMatching: @"^((\\(\\d{3}\\))|(\\d{3}\\-))?1\\d{10}$"]) {
        return NO;
    }
    
    return YES;
}

+ (BOOL)checkTel:(NSString *)tel
{
    if (!tel) {
        return YES;
    }
    
    if (![tel stringByMatching: @"^([0-9]{3}|0[0-9]{3})-[1-9][0-9]{6,7}(-[0-9]{1,6})?$"]) {
        return NO;
    }
    
    return YES;
}

+ (BOOL)checkChars:(NSString *)string charType:(AECHAR_TYPE)charType
{
    if (!string) {
        return YES;
    }
    
    if (!charType) {
        charType = AECHAR_TYPE_CHN | AECHAR_TYPE_EN | AECHAR_TYPE_NUM;
    }
    
    if (!(charType & AECHAR_TYPE_CHN) && !(charType & AECHAR_TYPE_EN) && !(charType & AECHAR_TYPE_NUM)) {
        return NO;
    }
    
    NSString *regx = [NSString stringWithFormat: @"^[%@%@%@]*$",
                      (charType & AECHAR_TYPE_CHN) ? @"\u4E00-\u9FA5" : @"",
                      (charType & AECHAR_TYPE_EN) ? @"a-zA-Z" : @"",
                      (charType & AECHAR_TYPE_NUM) ? @"0-9" : @""];
    if(![string stringByMatching: regx]){
        return NO;
    }
    
    return YES;
}

@end
