#import "MWZDirectionPoint.h"
#import "MWZLatLng.h"

@class MWZDirectionWrapper;

@interface MWZLatLngFloor : MWZLatLng <MWZDirectionPoint>

@property (nonatomic, readonly) NSNumber* floor;

- (instancetype) initWithLatitude:(double)latitude longitude:(double)longitude floor:(NSNumber*) floor;

@end
