#import <Foundation/Foundation.h>

@import Mapbox;

@class MWZStyleSheet;
@class MWZUniverse;

@interface MWZLayer : NSObject

@property(nonatomic, readonly) NSString* identifier;
@property(nonatomic, readonly) NSString* name;
@property(nonatomic, readonly) NSNumber* floor;
@property(nonatomic, readonly) NSNumber* order;
@property(nonatomic, readonly) NSString* type;
@property(nonatomic, readonly) NSString* tilesUrlTemplate;
@property(nonatomic, readonly) NSString* venueId;
@property(nonatomic, readonly) NSNumber* tilesMaxZoom;
@property(nonatomic, readonly) NSString* features;
@property(nonatomic, readonly) NSString* styleSheetId;
@property(nonatomic, readonly, assign) BOOL isPublished;
@property(nonatomic, readonly) NSArray<MWZUniverse*>* universes;
@property(nonatomic) MWZStyleSheet* styleSheet;
@property(nonatomic, readonly) NSDictionary* geometry;
@property(nonatomic, readonly, assign) MGLCoordinateBounds bounds;

- (instancetype) initWithIdentifier:(NSString*) identifer name:(NSString*) name floor:(NSNumber*) floor order:(NSNumber*) order type:(NSString*) type
                   tilesUrlTemplate:(NSString*) tilesUrlTemplate venueId:(NSString*) venueId tilesMaxZoom:(NSNumber*) tilesMaxZoom
                           features:(NSString*) features styleSheetId:(NSString*) styleSheetId isPublished:(BOOL) isPublished
                          universes:(NSArray<MWZUniverse*>*) univereses geometry:(NSDictionary*) geometry bounds:(MGLCoordinateBounds) bounds;

@end
