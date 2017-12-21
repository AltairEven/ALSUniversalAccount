//
//  AESegueService.m
//  wesg
//
//  Created by Altair on 8/18/16.
//  Copyright © 2016 AliSports. All rights reserved.
//

#import "AESegueService.h"
#import "AEMacro.h"
#import "NSString+UrlEncode.h"

#pragma mark AESegueService

@interface AESegueService ()

+ (BOOL)prepareForSegueWithModel:(AESegueModel *)model fromController:(UIViewController *)fromVC toController:(UIViewController *)toVC segueType:(AESegueType)type;

@end

@implementation AESegueService

+ (instancetype)service {
    static AESegueService *sharedService = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedService = [[AESegueService alloc] init];
    });
    return sharedService;
}


- (UIViewController *)destinationViewControllerWithSegueModel:(AESegueModel *)model {
    if (![AESegueModel validModel:model]) {
        return nil;
    }
    UIViewController *destController = [model.destinationVCClass instanceWithSegueModel:model];
    if (!destController || ![destController isKindOfClass:[UIViewController class]]) {
        return nil;
    }
    return destController;
}


+ (UIViewController *)makeSegueWithModel:(AESegueModel *)model fromController:(UIViewController *)fromVC {
    AESegueType segueType = AESegueTypePush;
    if (!fromVC.navigationController) {
        segueType = AESegueTypeModal;
    }
    if (model.preferSegueType != AESegueTypeAutomatic) {
        segueType = model.preferSegueType;
    }
    return [AESegueService makeSegueWithModel:model fromController:fromVC segueType:segueType];
}


+ (UIViewController *)makeSegueWithModel:(AESegueModel *)model fromController:(UIViewController *)fromVC segueType:(AESegueType)type {
    //validation
    if (![AESegueModel validModel:model]) {
        return nil;
    }
    
    //openUrl
    if (model.openUrl && [[UIApplication sharedApplication] canOpenURL:model.openUrl]) {
        [[UIApplication sharedApplication] openURL:model.openUrl];
        return nil;
    }
    
    UIViewController *toVC = [[AESegueService service] destinationViewControllerWithSegueModel:model];
    //need prepare?
    BOOL needSegue = [AESegueService prepareForSegueWithModel:model fromController:fromVC toController:toVC segueType:type];
    if (needSegue) {
        //continue segue
        return [AESegueService seguefromController:fromVC toController:toVC segueType:type animated:model.preferSegueAnimation];
    }
    return toVC;
}


+ (UIViewController *)seguefromController:(UIViewController *)fromVC toController:(UIViewController *)toVC segueType:(AESegueType)type animated:(BOOL)animated {
    if (!fromVC || ![fromVC isKindOfClass:[UIViewController class]]) {
        return nil;
    }
    if (!toVC || ![toVC isKindOfClass:[UIViewController class]]) {
        return nil;
    }
    switch (type) {
        case AESegueTypePush:
        {
            [toVC setHidesBottomBarWhenPushed:YES];
            [fromVC.navigationController pushViewController:toVC animated:animated];
        }
            break;
        case AESegueTypeAutomatic:
        case AESegueTypeModal:
        {
            [fromVC presentViewController:toVC animated:animated completion:nil];
        }
            break;
        case AESegueTypeModalNavi:
        {
            UINavigationController *navi = nil;
            if ([AESegueService service].navigationVCClass) {
                navi = [[[AESegueService service].navigationVCClass alloc] initWithRootViewController:toVC];
            } else {
                navi = [[UINavigationController alloc] initWithRootViewController:toVC];
            }
            
            if (navi) {
                [fromVC presentViewController:navi animated:animated completion:nil];
            }
        }
            break;
        default:
            break;
    }
    //Statistics
    
    return toVC;
}

#pragma mark Private methods

+ (BOOL)prepareForSegueWithModel:(AESegueModel *)model fromController:(UIViewController *)fromVC toController:(UIViewController *)toVC segueType:(AESegueType)type {
    if (model.preSegue) {
        //preSegue
        WeakObject(fromVC, weakFrom);
        WeakObject(toVC, weakTo);
        BOOL animated = model.preferSegueAnimation;
        BOOL needSegue = model.preSegue(weakFrom, weakTo, type, ^(BOOL need) {
            //同步或异步回调
            if (need) {
                [AESegueService seguefromController:weakFrom toController:weakTo segueType:type animated:animated];
            }
        });
        //同步返回
        return needSegue;
    }
    return YES;
}

@end





#pragma mark AESegueModel- ----

@implementation AESegueModel
@synthesize openUrl = _openUrl;

- (instancetype)init {
    self = [super init];
    if (self) {
        self.preferSegueType = AESegueTypeAutomatic;
        self.preferSegueAnimation = YES;
    }
    return self;
}

- (void)setUri:(NSString *)uri {
    if (![uri isKindOfClass:[NSString class]]) {
        _uri = nil;
    } else {
        _uri = uri;
    }
}

- (NSURL *)openUrl {
    if (self.uri && !self.destinationVCClass) {
        _openUrl = [NSURL URLWithString:self.uri];
        return _openUrl;
    }
    return nil;
}


+ (instancetype)segueModelFromUri:(NSString *)uri {
    
    if (![AESegueService service].analyzeBlock) {
        return nil;
    }
    AESegueModel *model = [AESegueService service].analyzeBlock(uri);
    [model setUri:uri];
    return model;
}

+ (instancetype)segueModelFromUri:(NSString *)uri withAnalysis:(AESegueModelAnalysis)analyzeBlock {
    if (!analyzeBlock) {
        return nil;
    }
    AESegueModel *model = analyzeBlock(uri);
    [model setUri:uri];
    return model;
}

+  (BOOL)validModel:(AESegueModel *)model {
    if (model.openUrl) {
        if ([model.openUrl isKindOfClass:[NSURL class]]) {
            return YES;
        }
        return NO;
    }
    if (!model || !model.destinationVCClass) {
        return NO;
    }
    if (![model.destinationVCClass respondsToSelector:@selector(instanceWithSegueModel:)]) {
        return NO;
    }
    return YES;
}

- (NSDictionary *)segueParamInfo {
    if (!self.uri) {
        return nil;
    }
    NSURL *url = [NSURL URLWithString:self.uri];
    if (!url) {
        return nil;
    }
    NSString *queryString = [url query];
    return [queryString queryParameters];
}

@end


