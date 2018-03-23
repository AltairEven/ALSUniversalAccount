//
//  ALSUASecondPartyBaiChuanPlug.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 04/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import "ALSUAOperationPlug.h"
#import <AlisportsUniversalAccountPublic/AlisportsUniversalAccountPublic.h>

@interface ALSUASecondPartyBaiChuanPlug : ALSUAOperationPlug

+ (BOOL)internalStartAccountOperation:(ALSUAOperationMode *)mode;

@end
