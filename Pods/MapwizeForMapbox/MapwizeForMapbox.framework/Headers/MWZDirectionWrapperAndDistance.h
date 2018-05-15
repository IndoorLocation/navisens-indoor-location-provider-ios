#import "MWZDirectionWrapper.h"

@interface MWZDirectionWrapperAndDistance : MWZDirectionWrapper

@property(nonatomic, readonly, assign) double distance;
@property(nonatomic, readonly, assign) double traveltime;

- (instancetype) initWithLatitude:(NSNumber*) latitude longitude:(NSNumber*) longitude floor:(NSNumber*) floor placeId:(NSString*) placeId venueId:(NSString*) venueId placeListId:(NSString*) placeListId distance:(double) distance traveltime:(double) traveltime;

@end
