//
//  UIView+Nib.h
//  wesg
//
//  Created by HG on 16/8/9.
//  Copyright © 2016年 AliSports. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (Nib)

+ (UINib *)nib;

+ (UINib *)nibWithName:(NSString *)name;

+ (NSString *)reuseId;

@end
