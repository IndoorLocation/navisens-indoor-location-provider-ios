#import <Foundation/Foundation.h>
#import "MWZDirectionPoint.h"
#import "MWZObject.h"

@import Mapbox;

@class MWZTranslation;
@class MWZStyle;
@class MWZLatLngFloor;
@class MWZUniverse;

@interface MWZPlace : NSObject <MWZDirectionPoint, MWZObject>

@property(nonatomic, readonly) NSString* identifier;
@property(nonatomic, readonly) NSString* venueId;
@property(nonatomic, readonly) NSString* name;
@property(nonatomic, readonly) NSString* alias;
@property(nonatomic, readonly) NSString* icon;

@property(nonatomic, readonly) MWZLatLngFloor* marker;
@property(nonatomic, readonly) MWZLatLngFloor* entrance;
@property(nonatomic, readonly) NSDictionary* geometry;

@property(nonatomic, readonly) NSString* fillColor;
@property(nonatomic, readonly) NSString* strokeColor;
@property(nonatomic, readonly) NSNumber* fillOpacity;
@property(nonatomic, readonly) NSNumber* strokeOpacity;
@property(nonatomic, readonly) NSNumber* strokeWidth;

@property(nonatomic, readonly) NSNumber* order;
@property(nonatomic, readonly) NSNumber* floor;

@property(nonatomic, readonly) NSString* placeTypeId;

@property(nonatomic, readonly, assign) BOOL isPublished;
@property(nonatomic, readonly, assign) BOOL isSearchable;
@property(nonatomic, readonly, assign) BOOL isVisible;
@property(nonatomic, readonly, assign) BOOL isClickable;
@property(nonatomic, readonly, assign) BOOL isMarkerDisplay;

@property(nonatomic, readonly) NSArray<MWZUniverse*>* universes;
@property(nonatomic, readonly) NSArray<MWZTranslation*>* translations;
@property(nonatomic) MWZStyle* customStyle;
@property(nonatomic, readonly) NSDictionary* data;

- (instancetype)initWithIdentifier:(NSString*) identifer venueId:(NSString*) venueId name:(NSString*) name alias:(NSString*) alias
                              icon:(NSString*) icon marker:(MWZLatLngFloor*) marker entrance:(MWZLatLngFloor*) entrance geometry:(NSDictionary*) geometry
                         fillColor:(NSString*) fillColor strokeColor:(NSString*) strokeColor fillOpacity:(NSNumber*) fillOpacity strokeOpacity:(NSNumber*) strokeOpacity
                       strokeWidth:(NSNumber*) strokeWidth order:(NSNumber*) order floor:(NSNumber*) floor placeTypeId:(NSString*) placeTypeId isPublished:(BOOL) isPublished
                      isSearchable:(BOOL) isSearchable isVisible:(BOOL) isVisible isClickable:(BOOL) isClickable isMarkerDisplay:(BOOL) isMarkerDisplay
                         universes:(NSArray<MWZUniverse*>*) universes translations:(NSArray<MWZTranslation*>*) translations data:(NSDictionary*) data;

- (NSString*) titleForLanguage:(NSString*) language;
- (NSString*) subtitleForLanguage:(NSString*) language;

- (BOOL) getMarkerDisplay;
- (BOOL) getShapeDisplay;
- (NSString*) getFillColor;
- (NSString*) getFillOpacity;
- (NSString*) getStrokeColor;
- (NSNumber*) getStrokeOpacity;
- (NSString*) getMarkerUrl;

- (MGLCoordinateBounds) bounds;

@end
