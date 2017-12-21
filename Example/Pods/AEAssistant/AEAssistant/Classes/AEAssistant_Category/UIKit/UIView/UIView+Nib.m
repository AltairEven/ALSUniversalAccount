//
//  UIView+Nib.m
//  wesg
//
//  Created by HG on 16/8/9.
//  Copyright © 2016年 AliSports. All rights reserved.
//

#import "UIView+Nib.h"

@implementation UIView (Nib)

+ (UINib *)nib{
    NSString *nibName = NSStringFromClass([self class]);
    return [self nibWithName:nibName];
}

+ (UINib *)nibWithName:(NSString *)name{
    UINib *nib = [UINib nibWithNibName:name bundle:nil];
    return nib;
}

+ (NSString *)reuseId{
    return NSStringFromClass([self class]);
}

@end
