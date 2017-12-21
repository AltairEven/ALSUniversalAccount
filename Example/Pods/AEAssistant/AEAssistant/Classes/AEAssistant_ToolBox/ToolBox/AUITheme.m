//
//  AUITheme.m
//  KidsTC
//
//  Created by 钱烨 on 10/13/15.
//  Copyright © 2015 KidsTC. All rights reserved.
//

#import "AUITheme.h"
#import "AEMacro.h"

NSString *const kAUIThemeTabItemKeyFirst = @"kAUIThemeTabItemKeyFirst";
NSString *const kAUIThemeTabItemKeySecond = @"kAUIThemeTabItemKeySecond";
NSString *const kAUIThemeTabItemKeyThird = @"kAUIThemeTabItemKeyThird";
NSString *const kAUIThemeTabItemKeyFourth = @"kAUIThemeTabItemKeyFourth";

@interface AUITheme ()

@end

@implementation AUITheme

+ (instancetype)defaultTheme {
    AUITheme *theme = [[AUITheme alloc] init];
    theme.globalThemeColor = RGBA(254, 118, 59, 1);
    theme.globalBGColor = RGBA(246, 246, 246, 1);
    theme.globalCellBGColor = RGBA(255, 255, 255, 1);
    theme.darkTextColor = RGBA(85, 85, 85, 1);
    theme.lightTextColor = RGBA(170, 170, 170, 1);
    theme.highlightTextColor = RGBA(103, 216, 244, 1);
    theme.buttonBGColor_Normal = RGBA(254, 118, 59, 1);
    theme.buttonBGColor_Highlight = RGBA(230, 100, 40, 1);
    theme.buttonBGColor_Disable = RGBA(200, 200, 200, 1);
    theme.navibarBGColor = RGBA(254, 118, 59, 1);
    theme.navibarTitleColor_Normal = RGBA(255, 255, 255, 1);
    theme.navibarTitleColor_Highlight = RGBA(230, 230, 230, 1);
    theme.naviBackImage_Normal = [UIImage imageNamed:@"navigation_back_n"];
    theme.naviBackImage_Highlight = [UIImage imageNamed:@"navigation_back_h"];
    theme.tabbarBGColor = RGBA(252, 248, 245, 1);
    
    AUITabbarItemElement *element1 = [[AUITabbarItemElement alloc] init];
    element1.type = AUITabbarItemTypeFirst;
    element1.tabbarItemTitle = @"赛事";
    element1.tabbarTitleColor_Normal = RGBA(175, 158, 139, 1);
    element1.tabbarTitleColor_Highlight = RGBA(254, 118, 59, 1);
    element1.tabbarItemImage_Normal = [UIImage imageNamed:@"tabbar_home_n"];
    element1.tabbarItemImage_Highlight = [UIImage imageNamed:@"tabbar_home_h"];
    
    AUITabbarItemElement *element2 = [[AUITabbarItemElement alloc] init];
    element2.type = AUITabbarItemTypeSecond;
    element2.tabbarItemTitle = @"认证";
    element2.tabbarTitleColor_Normal = RGBA(175, 158, 139, 1);
    element2.tabbarTitleColor_Highlight = RGBA(254, 118, 59, 1);
    element2.tabbarItemImage_Normal = [UIImage imageNamed:@"tabbar_discovery_n"];
    element2.tabbarItemImage_Highlight = [UIImage imageNamed:@"tabbar_discovery_h"];
    
    AUITabbarItemElement *element3 = [[AUITabbarItemElement alloc] init];
    element3.type = AUITabbarItemTypeThird;
    element3.tabbarItemTitle = @"发现";
    element3.tabbarTitleColor_Normal = RGBA(175, 158, 139, 1);
    element3.tabbarTitleColor_Highlight = RGBA(254, 118, 59, 1);
    element3.tabbarItemImage_Normal = [UIImage imageNamed:@"tabbar_parantingStrategy_n"];
    element3.tabbarItemImage_Highlight = [UIImage imageNamed:@"tabbar_parantingStrategy_h"];
    
    AUITabbarItemElement *element4 = [[AUITabbarItemElement alloc] init];
    element4.type = AUITabbarItemTypeFourth;
    element4.tabbarItemTitle = @"我";
    element4.tabbarTitleColor_Normal = RGBA(175, 158, 139, 1);
    element4.tabbarTitleColor_Highlight = RGBA(254, 118, 59, 1);
    element4.tabbarItemImage_Normal = [UIImage imageNamed:@"tabbar_userCenter_n"];
    element4.tabbarItemImage_Highlight = [UIImage imageNamed:@"tabbar_userCenter_h"];
    
    theme.tabbarItemElements = [NSArray arrayWithObjects:element1, element2, element3, element4, nil];
    return theme;
}

- (id)copyWithZone:(NSZone *)zone {
    AUITheme *theme = [[AUITheme allocWithZone:zone] init];
    theme.globalThemeColor = [self.globalThemeColor copy];
    theme.globalBGColor = [self.globalBGColor copy];
    theme.globalCellBGColor = [self.globalCellBGColor copy];
    theme.darkTextColor = [self.darkTextColor copy];
    theme.lightTextColor = [self.lightTextColor copy];
    theme.highlightTextColor = [self.highlightTextColor copy];
    theme.buttonBGColor_Normal = [self.buttonBGColor_Normal copy];
    theme.buttonBGColor_Highlight = [self.buttonBGColor_Highlight copy];
    theme.buttonBGColor_Disable = [self.buttonBGColor_Disable copy];
    theme.navibarBGColor = [self.navibarBGColor copy];
    theme.navibarTitleColor_Normal = [self.navibarTitleColor_Normal copy];
    theme.navibarTitleColor_Highlight = [self.navibarTitleColor_Highlight copy];
    theme.naviBackImage_Normal = [UIImage imageWithCGImage:self.naviBackImage_Normal.CGImage];
    theme.naviBackImage_Highlight = [UIImage imageWithCGImage:self.naviBackImage_Highlight.CGImage];
    theme.tabbarBGColor = [self.tabbarBGColor copy];
    theme.tabbarItemElements = [self.tabbarItemElements copy];
    
    return theme;
}

@end


@implementation AUITabbarItemElement

- (id)copyWithZone:(NSZone *)zone {
    AUITabbarItemElement *element = [[AUITabbarItemElement allocWithZone:zone] init];
    element.tabbarItemTitle = self.tabbarItemTitle;
    element.tabbarItemImage_Normal = [UIImage imageWithCGImage:self.tabbarItemImage_Normal.CGImage];
    element.tabbarItemImage_Highlight = [UIImage imageWithCGImage:self.tabbarItemImage_Highlight.CGImage];
    element.tabbarTitleColor_Normal = [self.tabbarTitleColor_Normal copy];
    element.tabbarTitleColor_Highlight = [self.tabbarTitleColor_Highlight copy];
    
    return element;
}

@end
