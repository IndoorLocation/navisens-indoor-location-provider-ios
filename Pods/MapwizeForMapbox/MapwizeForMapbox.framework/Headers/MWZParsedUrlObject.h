#import <Foundation/Foundation.h>
#import <IndoorLocation/IndoorLocation.h>

#import "MWZDirectionPoint.h"

@class MWZVenue;
@class MWZPlace;
@class MWZLatLngFloor;
@class MWZDirection;
@class MWZUniverse;

@import Mapbox;

@interface MWZParsedUrlObject : NSObject

@property (nonatomic) MWZVenue* venue;
@property (nonatomic) NSString* accessKey;
@property (nonatomic) ILIndoorLocation* indoorLocation;
@property (nonatomic) NSNumber* floor;
@property (nonatomic) NSNumber* zoom;
@property (nonatomic) NSString* type;
@property (nonatomic) NSString* language;
@property (nonatomic) MGLCoordinateBounds bounds;//
@property (nonatomic) MWZPlace* place;//
@property (nonatomic) id<MWZDirectionPoint> from;
@property (nonatomic) id<MWZDirectionPoint> to;
@property (nonatomic) MWZDirection* direction;
@property (nonatomic) NSNumber* isAccessible;
@property (nonatomic) MWZUniverse* universe;

@end
