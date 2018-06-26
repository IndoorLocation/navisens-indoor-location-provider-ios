#import <Foundation/Foundation.h>
#import <MotionDnaSDK/MotionDnaSDK.h>
#import <IndoorLocation/IndoorLocation.h>
#import "ILMotionDnaDelegate.h"
#import "ILMotionDna.h"

@class ILMotionDna;
@protocol ILMotionDnaDelegate;

#ifndef ILMotionDnaFloorDelegate_h
#define ILMotionDnaFloorDelegate_h

@protocol ILMotionDnaLocationDelegate <NSObject>

- (void) didChangeLocation:(Location*)location;

@end

#endif


@protocol ILIndoorLocationProviderDelegate;

@interface ILNavisensIndoorLocationProvider: ILIndoorLocationProvider

@property (nonatomic) ILIndoorLocationProvider* sourceProvider;
@property (nonatomic) NSString* navisensKey;
@property (nonatomic) ILIndoorLocation* indoorLocation;
@property (nonatomic) ILMotionDna* motionDnaSDK;
@property (nonatomic) Location* location;
@property (nonatomic, weak) id <ILMotionDnaLocationDelegate> delegate;

- (instancetype) initWith:(ILIndoorLocationProvider*) sourceProvider navisensKey:(NSString*) navisensKey;

- (ILMotionDna*) retrieveMotionDnaSdk;

@end

