//
//  ALSUAAESService.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 07/03/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    ALSAESOperationEncrypt,
    ALSAESOperationDecrypt
}ALSAESOperation;

@interface ALSUAAESService : NSObject

+ (NSString *)aesOperate:(ALSAESOperation)operation withString:(NSString *)string;

+ (NSString *)businessSideAESOperate:(ALSAESOperation)operation withString:(NSString *)string;

@end
