//
//  AEGender.m
//  Pods
//
//  Created by Altair on 05/04/2017.
//
//

#import "AEGender.h"

@implementation AEGender

+ (instancetype)instanceWithBiologicalSex:(AEBiologicalSex)sex {
    AEGender *sexObj = [[AEGender alloc] init];
    sexObj.biologicalSex = sex;
    return sexObj;
}

- (NSString *)description {
    NSString *des = @"未知";
    switch (self.biologicalSex) {
        case AEBiologicalSexMale:
        {
            des = @"男";
        }
            break;
        case AEBiologicalSexFemale:
        {
            des = @"女";
        }
            break;
        case AEBiologicalSexOther:
        {
            des = @"其他";
        }
            break;
        default:
            break;
    }
    return des;
}

@end
