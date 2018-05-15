#import <Foundation/Foundation.h>
@import Mapbox;

@class MWZDirectionWrapper;
@class MWZRoute;

@interface MWZDirection : NSObject

@property(nonatomic, readonly) MWZDirectionWrapper* from;
@property(nonatomic, readonly) MWZDirectionWrapper* to;
@property(nonatomic, readonly, assign) double distance;
@property(nonatomic, readonly) NSArray<MWZRoute*>* routes;
@property(nonatomic, readonly, assign) double traveltime;
@property(nonatomic, readonly, assign) MGLCoordinateBounds bounds;
@property(nonatomic, readonly) NSArray<MWZDirectionWrapper*>* waypoints;
@property(nonatomic, readonly) NSArray<MWZDirection*>* subdirections;

- (instancetype) initWithFrom:(MWZDirectionWrapper*) from to:(MWZDirectionWrapper*) to distance:(double) distance routes:(NSArray<MWZRoute*>*) routes
                   traveltime:(double) traveltime bounds:(MGLCoordinateBounds) bounds waypoints:(NSArray<MWZDirectionWrapper*>*) waypoints subdirections:(NSArray<MWZDirection*>*) subdirections;

@end
