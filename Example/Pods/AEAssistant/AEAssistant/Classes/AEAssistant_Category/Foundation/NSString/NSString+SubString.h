//
//  NSString+SubString.h
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (SubString)

- (NSArray<NSString *> *)rangeStringsOfSubString:(NSString *)subString;

- (NSString *)trimmedString;

@end
