//
//  ALBBOpenAccountCheckCodeViewController.h
//  Pods
//
//  Created by yixiao on 16/6/13.
//
//

#import "ALBBOpenAccountBaseController.h"

@interface ALBBOpenAccountCheckCodeViewController : ALBBOpenAccountBaseController

-(instancetype)initWithMobile:(NSString *)mobile locationCode:(NSString *)locationCode;


@property (strong,nonatomic)IBOutletCollection(NSObject) NSArray *outletCollection;

@property (weak, nonatomic) IBOutlet UILabel *phoneLabel;

@property (strong, nonatomic) IBOutletCollection(UITextField) NSArray *checkCodeTextFields;


@property (weak, nonatomic) IBOutlet UIButton *checkCodeButton;
- (IBAction)getCheckCode:(id)sender;


@end
