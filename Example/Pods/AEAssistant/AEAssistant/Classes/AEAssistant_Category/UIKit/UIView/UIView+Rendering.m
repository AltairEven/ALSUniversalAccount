//
//  UIView+Rendering.m
//  AEAssistant
//
//  Created by Qian Ye on 16/4/21.
//  Copyright © 2016年 StarDust. All rights reserved.
//

#import "UIView+Rendering.h"

@implementation UIView (Rendering)

- (void)drawLineWithStartPoint:(CGPoint)start endPoint:(CGPoint)end lineWidth:(CGFloat)width gap:(CGFloat)gap sectionLength:(CGFloat)length color:(UIColor *)color isVirtual:(BOOL)isVirtual {
    CAShapeLayer *shapeLayer = [CAShapeLayer layer];
    [shapeLayer setBounds:self.bounds];
    [shapeLayer setPosition:self.center];
    [shapeLayer setFillColor:[[UIColor clearColor] CGColor]];
    // 设置虚线颜色
    [shapeLayer setStrokeColor:color.CGColor];
    // 设置虚线的宽度
    [shapeLayer setLineWidth:width];
    [shapeLayer setLineJoin:kCALineJoinRound];
    if (isVirtual) {
        // 线段的长度和每条线的间距
        [shapeLayer setLineDashPattern: [NSArray arrayWithObjects:[NSNumber numberWithFloat:length], [NSNumber numberWithFloat:gap], nil]];
    }
    // Setup the path
    CGMutablePathRef path = CGPathCreateMutable();
    CGPathMoveToPoint(path, NULL, start.x, start.y);
    CGPathAddLineToPoint(path, NULL, end.x, end.y);
    
    [shapeLayer setPath:path];
    CGPathRelease(path);
    
    [self.layer addSublayer:shapeLayer];
}

- (void)renderGradientWithDisplayFrame:(CGRect)frame startPoint:(CGPoint)start endPoint:(CGPoint)end colors:(NSArray<UIColor *> *)colors locations:(NSArray<NSNumber *> *)locations {
    CAGradientLayer *gradient = [CAGradientLayer layer];
    gradient.frame = frame;
    gradient.startPoint = start;
    gradient.endPoint = end;
    if (colors) {
        NSMutableArray *temp = [[NSMutableArray alloc] init];
        for (UIColor *color in colors) {
            [temp addObject:(id)(color.CGColor)];
        }
        gradient.colors = temp;
    }
    gradient.locations = locations;
    [self.layer insertSublayer:gradient atIndex:0];
}

@end
