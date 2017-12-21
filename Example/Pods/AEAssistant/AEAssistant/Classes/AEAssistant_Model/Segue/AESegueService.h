//
//  AESegueService.h
//  wesg
//
//  Created by Altair on 8/18/16.
//  Copyright © 2016 AliSports. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    AESegueTypeAutomatic, //自动，如果fromVC有NavigationController，则为push，否则为modal
    AESegueTypePush, //push，如果fromVC没有NavigationController，则不做任何操作
    AESegueTypeModal, //present
    AESegueTypeModalNavi //先给toVC设置为AENavigationConroller的rootViewController，再present
}AESegueType;

@class AESegueModel;

typedef AESegueModel *(^AESegueModelAnalysis)(NSString *uri);


/****************************************AESegueService******************************************/

@interface AESegueService : NSObject

@property (nonatomic, copy) AESegueModelAnalysis analyzeBlock; //解析用block

@property (nonatomic, strong) Class navigationVCClass;  //导航控制器Class

/**
 *  单例方法
 *
 *  @return AESegueService实例
 */
+ (instancetype)service;

/**
 *  通过model得到目标UIViewController
 *
 *  @param model AESegueModel实例
 *
 *  @return 目标UIViewController实例
 */
- (UIViewController *)destinationViewControllerWithSegueModel:(AESegueModel *)model;

/**
 *  从fromVC跳转至model对应的UIViewcontroller
 *
 *  @param model  AESegueModel实例
 *  @param fromVC 起始UIViewController实例
 *
 *  @return 目标UIViewController实例
 */
+ (UIViewController *)makeSegueWithModel:(AESegueModel *)model fromController:(UIViewController *)fromVC;

/**
 *  从fromVC跳转至model对应的UIViewcontroller，并指定跳转方式
 *
 *  @param model  AESegueModel实例
 *  @param fromVC 起始UIViewController实例
 *  @param type   指定的跳转方式
 *
 *  @return 目标UIViewController实例
 */
+ (UIViewController *)makeSegueWithModel:(AESegueModel *)model fromController:(UIViewController *)fromVC segueType:(AESegueType)type;


/**
 *  从fromVC跳转至toVC，并指定跳转方式
 *
 *  @param fromVC  起始UIViewController实例
 *  @param toVC 目标UIViewController实例
 *  @param type   指定的跳转方式
 *
 *  @return 目标UIViewController实例
 */
+ (UIViewController *)seguefromController:(UIViewController *)fromVC toController:(UIViewController *)toVC segueType:(AESegueType)type animated:(BOOL)animated;

@end





/****************************************AESegueModel******************************************/


/**
 跳转前执行方法后的回调

 @param needSegue 是否需要跳转
 */
typedef void (^AEPreSegueResult)(BOOL needSegue);

/**
 跳转前准备

 @param fromVC 跳转起始VC
 @param toVC 跳转目标VC
 @param segueType 跳转方式
 @param result 是否需要继续跳转，可同步或异步调用
 @return 是否需要继续跳转，同步返回
*/
typedef BOOL (^AEPreSegue)(UIViewController *fromVC, UIViewController *toVC, AESegueType segueType, AEPreSegueResult result);

/**
 跳转用模型
 */
@interface AESegueModel : NSObject

@property (nonatomic, strong) Class destinationVCClass;

@property (nonatomic, strong, readonly) NSString *uri; //跳转URI，格式如scheme://host?param1=value1&param2=value2

@property (nonatomic, strong, readonly) NSURL *openUrl; //如果没有合适的跳转ViewController，则会生成openUrl，否则为nil

@property (nonatomic, copy) AEPreSegue preSegue; //跳转前的准备，可执行同步或异步操作

@property (nonatomic, assign) AESegueType preferSegueType;  //希望实现的跳转方式，默认AESegueTypeAutomatic

@property (nonatomic, assign) BOOL preferSegueAnimation;    //是否需要执行动画，默认YES

/**
 *  AESegueModel实例化方法，需要先设置AESegueService实例的analyzeBlock，否则返回nil
 *
 *  @param sourceData 数据源
 *
 *  @return AESegueModel实例
 */
+ (instancetype)segueModelFromUri:(NSString *)uri;

/**
 *  AESegueModel实例化方法
 *
 *  @param sourceData   数据源
 *  @param analyzeBlock 数据源解析block
 *
 *  @return AESegueModel实例
 */
+ (instancetype)segueModelFromUri:(NSString *)uri withAnalysis:(AESegueModelAnalysis)analyzeBlock;

/**
 *  对象是否有效，目前判断的条件是destinationVCClass是否为nil
 *
 *  @param model AESegueModel实例
 *
 *  @return 是否有效
 */
+ (BOOL)validModel:(AESegueModel *)model;

/**
 *  获取跳转参数
 *
 *  @return 跳转参数字典
 */
- (NSDictionary *)segueParamInfo;

@end





/*******************************AESegueingViewControllerProtocal*******************************/

@protocol AESegueingViewControllerProtocal <NSObject>

@optional

/**
 *  适用于AESegueService的UIViewController初始化方法（必须实现）
 *
 *  @param model AESegueModel
 *
 *  @return UIViewController实例
 */
+ (instancetype)instanceWithSegueModel:(AESegueModel *)model;

@end




