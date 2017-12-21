//
//  UILabel+Additions.h
//  iphone51buy
//
//  Created by icson apple on 12-6-23.
//  Copyright (c) 2012年 icson. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UILabel(Additions)

- (CGFloat)sizeToFitWithMaximumNumberOfLines:(NSInteger)lines;
- (CGSize)sizeOfSizeToFitWithMaximumNumberOfLines:(NSInteger)lines;

@end
