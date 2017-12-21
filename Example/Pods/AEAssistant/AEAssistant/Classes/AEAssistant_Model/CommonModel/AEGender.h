//
//  AEGender.h
//  Pods
//
//  Created by Altair on 05/04/2017.
//
//

#import <Foundation/Foundation.h>

/**
 性别
 */
typedef enum {
    AEBiologicalSexUnknown, //未知
    AEBiologicalSexMale, //男
    AEBiologicalSexFemale, //女
    AEBiologicalSexOther //其他
}AEBiologicalSex;

@interface AEGender : NSObject

@property (nonatomic, assign) AEBiologicalSex biologicalSex;

+ (instancetype)instanceWithBiologicalSex:(AEBiologicalSex)sex;

@end
