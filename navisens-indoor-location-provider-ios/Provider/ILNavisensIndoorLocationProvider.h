#import <Foundation/Foundation.h>
#import <MotionDnaSDK/MotionDnaSDK.h>
#import <IndoorLocation/IndoorLocation.h>
#import "ILMotionDnaDelegate.h"
#import "ILMotionDna.h"

@class ILMotionDna;
@protocol ILMotionDnaDelegate;
@protocol ILIndoorLocationProviderDelegate;

@interface ILNavisensIndoorLocationProvider: ILIndoorLocationProvider

@property (nonatomic) NSString* navisensKey;
@property (nonatomic) ILIndoorLocationProvider* sourceProvider;
@property (nonatomic) ILMotionDna* motionDnaSDK;

- (instancetype) initWith:(NSString*) navisensKey;
- (instancetype) initWith:(NSString*) navisensKey sourceProvider:(ILIndoorLocationProvider*) sourceProvider;

@end

