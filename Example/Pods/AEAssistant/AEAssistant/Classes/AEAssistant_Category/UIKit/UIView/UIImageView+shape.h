//
//  UIImageView+shape.h
//  wesg
//
//  Created by Altair on 8/15/16.
//  Copyright © 2016 AliSports. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImageView (shape)

@property (nonatomic, strong) CALayer *contentLayer;

- (void)shapeWithPath:(CGPathRef)path;

- (void)setShapedImage:(UIImage *)image;

@end
