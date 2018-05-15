#import "MWZDirectionPoint.h"
#import "MWZLatLngFloor.h"

@interface MWZLatLngFloorInVenue : MWZLatLngFloor <MWZDirectionPoint>

@property (nonatomic, readonly) NSString* venueId;

- (instancetype) initWithLatitude:(double)latitude longitude:(double)longitude floor:(NSNumber*) floor venueId:(NSString*) venueId;

@end
