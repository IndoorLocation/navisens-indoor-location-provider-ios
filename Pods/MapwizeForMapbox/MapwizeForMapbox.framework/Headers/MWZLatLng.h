#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface MWZLatLng : NSObject

@property(nonatomic, readonly, assign) CLLocationCoordinate2D coordinates;

- (instancetype) initWithLatitude:(double) latitude longitude:(double) longitude;

@end
