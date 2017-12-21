//
//  NSString+AES.m
//  AEAssistant_Category
//
//  Created by Qian Ye on 16/6/14.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "NSString+AES.h"
#import <CommonCrypto/CommonCryptor.h>
#import "GTMBase64.h"

@implementation NSString (AES)

- (NSString *)AES256Operation:(AESOperation)operation withKey:(NSString *)key mode:(AEOptions)options {
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    if (!data) {
        return nil;
    }
    char keyPtr[kCCKeySizeAES256+1];
    bzero(keyPtr, sizeof(keyPtr));
    [key getCString:keyPtr maxLength:sizeof(keyPtr) encoding:NSUTF8StringEncoding];
    NSUInteger dataLength = [self length];
    size_t bufferSize = dataLength + kCCBlockSizeAES128;
    void *buffer = malloc(bufferSize);
    size_t numBytesEncrypted = 0;
    CCCryptorStatus cryptStatus = CCCrypt(operation,
                                          kCCAlgorithmAES128,
                                          options,
                                          keyPtr,
                                          kCCBlockSizeAES128,
                                          NULL,
                                          [data bytes],
                                          dataLength,
                                          buffer,
                                          bufferSize,
                                          &numBytesEncrypted);
    if (cryptStatus == kCCSuccess) {
        NSData *encryptedData = [NSData dataWithBytesNoCopy:buffer length:numBytesEncrypted];
        return [encryptedData base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength];
    }
    free(buffer);
    return nil;
}

- (NSString *)AES128Operation:(AESOperation)operation withKey:(NSString *)key vector:(NSString *)vector mode:(AEOptions)options {
    NSData *dataIn = [self dataUsingEncoding:NSUTF8StringEncoding];
    if (operation == AESOperationDecrypt) {
        dataIn = [GTMBase64 decodeData:dataIn];
    }
    NSData *keyData = [key dataUsingEncoding:NSUTF8StringEncoding];
    NSData *ivData = [vector dataUsingEncoding:NSUTF8StringEncoding];
    
    CCCryptorStatus ccStatus   = kCCSuccess;
    size_t          cryptBytes = 0;
    NSMutableData  *dataOut    = [NSMutableData dataWithLength:dataIn.length + kCCBlockSizeAES128];
    
    ccStatus = CCCrypt(operation,
                       kCCAlgorithmAES128,
                       options,
                       keyData.bytes,
                       kCCKeySizeAES128,
                       ivData.bytes,
                       dataIn.bytes,
                       dataIn.length,
                       dataOut.mutableBytes,
                       dataOut.length,
                       &cryptBytes);
    
    if (ccStatus == kCCSuccess) {
        dataOut.length = cryptBytes;
    }
    else {
        dataOut = nil;
    }
    
    switch (operation) {
        case AESOperationEncrypt:
        {
            return [dataOut base64EncodedStringWithOptions:NSDataBase64Encoding64CharacterLineLength];
        }
            break;
        case AESOperationDecrypt:
        {
            return [[NSString alloc] initWithData:dataOut encoding:NSUTF8StringEncoding];
        }
        default:
            break;
    }
    return nil;
}

@end
