//
//  SmthLoginCustomDelegate.h
//  SmoothSSO
//
//  Created by moxuan on 16/11/10.
//  Copyright © 2016年 taobao. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol  SmthLoginComponentCustomDelegate <NSObject>
@optional
- (UIButton*) taobaoLoginBt;
- (UIButton*) alipayLoginBt;
- (UIButton*) closeBt;
- (UIButton*) pwdLoginBt;
- (UIImageView*) logoImgView;
- (UIView*) contentView;

@end



@protocol  SmthLoginCustomDelegate <NSObject>
@optional
- (UIImage*) appearanceOfLogoImage;
- (UIImage*) appearanceOfTaotaoLoginBtImage;
- (UIImage*) appearanceOfAlipayLoginBtImage;
- (UIImage*) appearanceOfPwdLoginBtImage;
- (UIImage*) appearanceOfBackgroudImage;
- (UIImage*) appearanceOfCloseButtonImage;
- (CGFloat) logoToButtonPadding;
- (BOOL) isShowNavBar;
- (BOOL) isCloseAnimation;
- (void)appearanceOfLoginPage: (id<SmthLoginComponentCustomDelegate>)componentDelegate;

@end
