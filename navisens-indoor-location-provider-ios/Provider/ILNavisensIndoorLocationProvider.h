#import <Foundation/Foundation.h>
#import <MotionDnaSDK/MotionDnaSDK.h>
#import <IndoorLocation/IndoorLocation.h>
#import <MapwizeForMapbox/MapwizeForMapbox.h>


#import "ILMotionDnaDelegate.h"
#import "ILMotionDna.h"

@class ILIndoorLocationProviderDelegate;

@interface ILNavisensIndoorLocationProvider: ILIndoorLocationProvider <ILMotionDnaDelegate, ILIndoorLocationProviderDelegate, CLLocationManagerDelegate>

@property (nonatomic, strong) ILIndoorLocationProvider* sourceProvider;

@property (nonatomic, weak) ILIndoorLocation* indoorLocation;

- (id) initWithSourceProvider:(ILIndoorLocationProvider*) sourceProvider navisensDevKey:(NSString*) key;


@end
