//
//  ALBBOpenAccountLoginNoPwdViewController.h
//  Pods
//
//  Created by yixiao on 15/7/10.
//
//

#import "ALBBOpenAccountBaseController.h"
#import "ALBBOpenAccountWrapperView.h"

@interface ALBBOpenAccountLoginNoPwdViewController : ALBBOpenAccountBaseController

//预留的外挂引用
@property (nonatomic, strong) IBOutletCollection(NSObject)  NSArray *outletCollection;

// wrapper
@property (weak, nonatomic) IBOutlet ALBBOpenAccountWrapperView *wrapperView;
// form
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *heightOfFormView;

@property (weak, nonatomic) IBOutlet UILabel *prefixLabel;
@property (weak, nonatomic) IBOutlet UIButton *prefixIcon;

// username
@property (weak, nonatomic) IBOutlet UILabel *usernameLabel;
@property (weak, nonatomic) IBOutlet UITextField *usernameField;


// smscode
@property (weak, nonatomic) IBOutlet UILabel *smscodeLabel;
@property (weak, nonatomic) IBOutlet UITextField *smscodeField;
@property (weak, nonatomic) IBOutlet UIButton *sendButton;


// control
@property (weak, nonatomic) IBOutlet UIButton *submitButton;


- (IBAction)submitLogin;
// 前往国家列表
- (IBAction)prefixNumberChoose:(id)sender;

// sso
- (IBAction)taobaoSSO:(id)sender;
- (IBAction)weChatSSO:(id)sender;
- (IBAction)weiBoSSO:(id)sender;
- (IBAction)qqSSO:(id)sender;


//图片验证码（已废弃）
@property (weak, nonatomic) IBOutlet UIView *checkcodeView;
@property (weak, nonatomic) IBOutlet UILabel *checkcodeLabel;
@property (weak, nonatomic) IBOutlet UITextField *checkcodeField;
@property (weak, nonatomic) IBOutlet UIImageView *checkcodeImageView;
@property (weak, nonatomic) IBOutlet UIButton *refreshButton;


@end
