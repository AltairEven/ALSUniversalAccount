//
//  TextSegueModel.h
//  KidsTC
//
//  Created by Altair on 1/16/16.
//  Copyright © 2016 KidsTC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AESegueService.h"

@interface TextSegueModel : NSObject

@property (nonatomic, copy, readonly) NSString *linkWords;

@property (nonatomic, copy, readonly) NSString *wholeString;

@property (nonatomic, readonly) NSRange linkRange;

@property (nonatomic, readonly) NSArray<NSString *> *linkRangeStrings;

@property (nonatomic, strong) UIColor *linkColor;

@property (nonatomic, strong) NSDictionary *userInfo;

- (instancetype)initWithLinkWords:(NSString *)linkWords wholeString:(NSString *)wholeString;

@end
