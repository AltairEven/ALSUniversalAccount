//
//  IUATrace.h
//  SecurityGuardSDK
//
//  Created by yangzhao.zy on 15/4/22.
//  Copyright (c) 2015年 Li Fengzhong. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@protocol IUATraceComponent <NSObject>

/**
 *  页面初始化接口
 *
 *  @param pageName 当前页面所对应的页面名。
 *
 *  @return 无返回值
 */
- (void) onNewPage: (NSString*)pageName;

/**
 *  获取当前页面所对应控件的点击情况
 *
 *  @param pageName 当前页面所对应的页面名。
 *
 *  @param ctrlName 当前页面所对应控件的控件名。
 *
 *  @return 无返回值
 */
- (void) onControlClick: (NSString*)pageName
                  ctrl: (NSString*)ctrlName;


/**
 *  获取当前页面所对应的按键信息
 *
 *  @param pageName 当前页面所对应的页面名。
 *
 *  @param ctrlName 当前页面所对应控件的控件名。
 *
 *  @param keyValue 获取到的输入的信息
 *
 *  @return 无返回值
 */
- (void) onKeyDown: (NSString*)pageName
             ctrl: (NSString*)ctrlName
          KeyCode:(NSString*)keyValue;

/**
 *  获取当前页面所对应密码框的按键信息
 *
 *  @param pageName 当前页面所对应的页面名。
 *
 *  @param ctrlName 当前页面所对应控件的控件名。
 *
 *  @return 无返回值
 */
- (void) onPwdKeyDown: (NSString*)pageName
              ctrl: (NSString*)ctrlName;

/**
 *  获取当前页面所对应的焦点信息
 *
 *  @param pageName 当前页面所对应的页面名。
 *
 *  @param ctrlName 当前页面所对应控件的控件名。
 *
 *  @param hasFocus 当前页面所对应控件焦点的得到或失去。
 *
 *  @return 无返回值
 */
- (void) onFocusChange: (NSString*)pageName
                 ctrl: (NSString*)ctrlName
            GetorLost:(bool)hasFocus;


/**
 *  获取当前页面所对应的触屏信息
 *
 *  @param pageName 当前页面所对应的页面名。
 *
 *  @param ctrlName 当前页面所对应控件的控件名。
 *
 *  @param pt 表示触屏事件触发的坐标信息。
 *
 *  @return 无返回值
 */
- (void) onTouchScreen: (NSString*) pageName
                 ctrl: (NSString*)ctrlName
      touchEventPoint:(CGPoint*) pt;

/**
 *  获取当前页面所对应的传感器信息
 *
 *  @param sensorName 当前传感器的名字。
 *
 *  @param x,y,z 传感器对应的x, y, z坐标信息，对于特殊传感器不需要用到的参数传0。
 *
 *  @return 无返回值
 */
- (void) onSensorChanged: (NSString *)sensorName
             xCoordinate: (float)x
             yCoordinate: (float)y
             zCoordinate: (float)z;

/**
 *  获取当前页面的行为数据
 *
 *  @return 长度不为0的字符串，失败时返回nil
 */
-(NSString*) getTraceData;

@end

