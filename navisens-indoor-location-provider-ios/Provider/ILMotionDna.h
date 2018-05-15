#import <Foundation/Foundation.h>
#import <MotionDnaSDK/MotionDnaSDK.h>
#import <MotionDnaSDK/MotionDna.h>
#import <IndoorLocation/IndoorLocation.h>

@protocol ILMotionDnaDelegate;

@interface ILMotionDna: MotionDnaSDK

@property (nonatomic, weak) id<ILMotionDnaDelegate> delegate;

@end
