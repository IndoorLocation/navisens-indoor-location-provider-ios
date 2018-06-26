#import <Foundation/Foundation.h>

@import Mapbox;
@class MWZLatLng;

@interface MWZRoute : NSObject

@property(nonatomic, readonly) NSNumber* floor;
@property(nonatomic, readonly) NSNumber* fromFloor;
@property(nonatomic, readonly) NSNumber* toFloor;
@property(nonatomic, readonly, assign) BOOL isStart;
@property(nonatomic, readonly, assign) BOOL isEnd;
@property(nonatomic, readonly, assign) double traveltime;
@property(nonatomic, readonly, assign) double timeToEnd;
@property(nonatomic, readonly, assign) MGLCoordinateBounds bounds;
@property(nonatomic, readonly, assign) double distance;
@property(nonatomic, readonly) NSString* connectorTypeTo;
@property(nonatomic, readonly) NSString* connectorTypeFrom;
@property(nonatomic, readonly) NSArray<MWZLatLng*>* path;
@property(nonatomic, readonly) NSString* uniqId;

- (instancetype) initWithFloor:(NSNumber*) floor fromFloor:(NSNumber*) fromFloor toFloor:(NSNumber*) toFloor isStart:(BOOL) isStart isEnd:(BOOL) isEnd
                    traveltime:(double) traveltime timeToEnd:(double) timeToEnd bounds:(struct MGLCoordinateBounds) bounds distance:(double) distance
               connectorTypeTo:(NSString*) connectorTypeTo connectorTypeFrom:(NSString*) connectorTypeFrom path:(NSArray<MWZLatLng*>*) path;


@end
