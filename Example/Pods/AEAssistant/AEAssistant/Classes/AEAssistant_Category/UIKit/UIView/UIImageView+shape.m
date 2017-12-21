//
//  UIImageView+shape.m
//  wesg
//
//  Created by Altair on 8/15/16.
//  Copyright © 2016 AliSports. All rights reserved.
//

#import "UIImageView+shape.h"
#import <objc/runtime.h>

@implementation UIImageView (shape)

- (void)setContentLayer:(CALayer *)contentLayer {
    objc_setAssociatedObject(self, @"kContentLayerKey", contentLayer, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (CALayer *)contentLayer {
    return objc_getAssociatedObject(self, @"kContentLayerKey");
}

- (void)shapeWithPath:(CGPathRef)path {
    CAShapeLayer *maskLayer = [CAShapeLayer layer];
    maskLayer.frame = self.bounds;
    maskLayer.path = path;
    maskLayer.fillColor = [UIColor blackColor].CGColor;
    maskLayer.strokeColor = [UIColor clearColor].CGColor;
    maskLayer.frame = self.bounds;
    maskLayer.contentsCenter = CGRectMake(0.5, 0.5, 0.1, 0.1);
    maskLayer.contentsScale = [UIScreen mainScreen].scale;
    
    self.contentLayer = [CALayer layer];
    self.contentLayer.mask = maskLayer;
    self.contentLayer.frame = self.bounds;
    [self.layer addSublayer:self.contentLayer];
}

- (void)setShapedImage:(UIImage *)image {
    self.contentLayer.contents = (id)image.CGImage;
}

@end
