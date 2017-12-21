//
//  ALSUABindMobilePhoneViewController.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 09/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ALSUABindMobilePhoneProtocol.h"


@class ALSUABindMobilePhoneViewController;
@protocol ALSUABindMobilePhoneViewControllerDelegate <NSObject>
    
    @optional
    
- (void)bindMobilePhoneViewDidLoad:(ALSUABindMobilePhoneViewController *) viewController;
    
    
- (void)bindMobilePhoneViewWillAppear:(ALSUABindMobilePhoneViewController *) viewController;
- (void)bindMobilePhoneViewDidAppear:(ALSUABindMobilePhoneViewController *) viewController;
    
- (void)bindMobilePhoneViewWillDisappear:(ALSUABindMobilePhoneViewController *) viewController;
- (void)bindMobilePhoneViewDidDisappear:(ALSUABindMobilePhoneViewController *) viewController;
    
- (void)bindMobilePhoneViewWillLayoutSubviews:(ALSUABindMobilePhoneViewController *) viewController;
- (void)bindMobilePhoneViewDidLayoutSubviews:(ALSUABindMobilePhoneViewController *) viewController;
    
    
    @end

typedef void (^ALSUABindMobilePhoneSuccessCallback)(id currentSession);
typedef void (^ALSUABindMobilePhoneFailedCallback)(NSError *error);

@interface ALSUABindMobilePhoneViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *mobileTextField;
@property (weak, nonatomic) IBOutlet UITextField *codeTextField;
@property (weak, nonatomic) IBOutlet UIButton *submitButton;
@property (weak, nonatomic) IBOutlet UIButton *getSMSCodeBT;
    
@property (nonatomic, copy) NSString *smsCodeButtonFormat;

@property (weak, nonatomic) IBOutlet UIView *bindTipView;
@property (strong, nonatomic) id<ALSUABindMobilePhoneProtocol> customDelegate;
@property (strong, nonatomic) id<ALSUABindMobilePhoneProtocol> defaultDelegate;

@property (copy, nonatomic) ALSUABindMobilePhoneSuccessCallback bindSuccessCallback;
@property (copy, nonatomic) ALSUABindMobilePhoneFailedCallback bindFailedCallback;
    
+ (void)setDelegate:(id<ALSUABindMobilePhoneViewControllerDelegate>)delegate;
    
- (IBAction)submitButtonTapped:(id)sender;

@end
