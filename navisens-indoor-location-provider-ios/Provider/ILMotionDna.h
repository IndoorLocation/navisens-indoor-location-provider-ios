#import <Foundation/Foundation.h>
#import <MotionDnaSDK/MotionDnaSDK.h>

@protocol ILMotionDnaDelegate;

@interface ILMotionDna: MotionDnaSDK

@property (nonatomic, weak) id<ILMotionDnaDelegate> delegate;

@end
