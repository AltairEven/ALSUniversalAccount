//
//  UIImage+GImageExtension.h
//  iphone51buy
//
//  Created by icson apple on 12-7-3.
//  Copyright (c) 2012年 icson. All rights reserved.
//

#import <UIKit/UIKit.h>


CGFloat DegreesToRadians(CGFloat degrees);
CGFloat RadiansToDegrees(CGFloat radians);

@interface UIImage (GImageExtension)

- (UIImage *)imageAtRect:(CGRect)rect;
- (UIImage *)imageByScalingProportionallyToMinimumSize:(CGSize)targetSize;
- (UIImage *)imageByScalingProportionallyToSize:(CGSize)targetSize;
- (UIImage *)imageByScalingToSize:(CGSize)targetSize;
- (UIImage *)imageByScalingToSize:(CGSize)targetSize retinaFit:(BOOL)needFit;
- (UIImage *)imageRotatedByRadians:(CGFloat)radians;
- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees;
+ (UIImage *)imageWithColor:(UIColor *)color;
- (UIImage *)grayImage;
- (UIImage *)imageByCompressToMemorySize:(NSUInteger)byteCount;
- (CGSize)sizeOfMemorySize:(NSUInteger)byteCount;
- (NSUInteger)byteCount;

@end
