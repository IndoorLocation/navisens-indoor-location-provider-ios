#import <Foundation/Foundation.h>
#import <MotionDnaSDK/MotionDnaSDK.h>
#import <IndoorLocation/IndoorLocation.h>

@class ILMotionDna;
@protocol ILMotionDnaDelegate;
@protocol ILIndoorLocationProviderDelegate;

@interface ILNavisensIndoorLocationProvider: ILIndoorLocationProvider

@property (nonatomic) ILIndoorLocationProvider* sourceProvider;
@property (nonatomic) NSString* navisensKey;
@property (nonatomic, weak) ILIndoorLocation* indoorLocation;

- (instancetype) initWith:(ILIndoorLocationProvider*) sourceProvider navisensKey:(NSString*) navisensKey;


@end
