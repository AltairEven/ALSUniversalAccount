//
//  AliSecXSafeUtils.h
//  AliSecXSafeUtils
//
//  Created by xingchen on 15/1/30.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

//#define _FULL_VERSION

#define NOT_JAILBREAK 0
//#define NOT_SWIZZLED 34801
#define NOT_SWIZZLED 0

typedef struct _utils{
    
    uint16_t (*isJailbreak)(void);
    
//    uint16_t (*isDebugging)(void);
//    
//    uint16_t (*isSwizzlingClassMethod)(const char* class_name, SEL selector);
//
#ifdef SWIZZLE_SWITCH
    uint16_t (*isSwizzlingInstanceMethod)(const char* class_name, SEL selector, SEL shareSelector);
#endif
    
}SecUtils_t;

#define APSecXSafeUtils [AliSecXSafeUtils sharedUtils]

@interface AliSecXSafeUtils : NSObject

+ (SecUtils_t*)sharedUtils;

@end
