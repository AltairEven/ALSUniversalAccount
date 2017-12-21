//
//  ALSUASetPasswordViewController.h
//  AlisportsUniversalAccount
//
//  Created by Altair on 11/05/2017.
//  Copyright © 2017 Alisports. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ALSUASetPasswordProtocol.h"


@class ALSUASetPasswordViewController;
@protocol ALSUASetPasswordViewControllerDelegate <NSObject>

@optional
    
- (void)setPasswordViewDidLoad:(ALSUASetPasswordViewController *) viewController;
    
    
- (void)setPasswordViewWillAppear:(ALSUASetPasswordViewController *) viewController;
- (void)setPasswordViewDidAppear:(ALSUASetPasswordViewController *) viewController;
    
- (void)setPasswordViewWillDisappear:(ALSUASetPasswordViewController *) viewController;
- (void)setPasswordViewDidDisappear:(ALSUASetPasswordViewController *) viewController;
    
- (void)setPasswordViewWillLayoutSubviews:(ALSUASetPasswordViewController *) viewController;
- (void)setPasswordViewDidLayoutSubviews:(ALSUASetPasswordViewController *) viewController;
    
    
@end

typedef void (^ALSUASetPasswordSuccessCallback)(id currentSession);
typedef void (^ALSUASetPasswordFailedCallback)(NSError *error);

@interface ALSUASetPasswordViewController : UIViewController

@property (weak, nonatomic) IBOutlet UITextField *phoneTextField;
@property (weak, nonatomic) IBOutlet UITextField *codeTextField;
@property (weak, nonatomic) IBOutlet UITextField *passwordTextField;
@property (weak, nonatomic) IBOutlet UIButton *getSMSCodeBT;
@property (weak, nonatomic) IBOutlet UIButton *visibleButton;
@property (weak, nonatomic) IBOutlet UIButton *submitButton;
    
@property (nonatomic, copy) NSString *smsCodeButtonFormat;

@property (strong, nonatomic) id<ALSUASetPasswordProtocol> customDelegate;
@property (strong, nonatomic) id<ALSUASetPasswordProtocol> defaultDelegate;

@property (copy, nonatomic) ALSUASetPasswordSuccessCallback setSuccessCallback;
@property (copy, nonatomic) ALSUASetPasswordFailedCallback setFailedCallback;
    
+ (void)setDelegate:(id<ALSUASetPasswordViewControllerDelegate>)delegate;
    
- (IBAction)submit:(id)sender;

@end
