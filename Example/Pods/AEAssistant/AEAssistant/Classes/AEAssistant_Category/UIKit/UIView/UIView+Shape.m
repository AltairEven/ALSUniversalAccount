//
//  UIView+Shape.m
//  wesg
//
//  Created by Altair on 8/15/16.
//  Copyright © 2016 AliSports. All rights reserved.
//

#import "UIView+Shape.h"

@implementation UIView (Shape)

- (void)shapeWithPath:(CGPathRef)path {
    CAShapeLayer *maskLayer = [CAShapeLayer layer];
    maskLayer.frame = self.bounds;
    maskLayer.path = path;
    
    [self.layer addSublayer:maskLayer];
    self.layer.mask = maskLayer;
    self.layer.masksToBounds = YES;
}

@end
