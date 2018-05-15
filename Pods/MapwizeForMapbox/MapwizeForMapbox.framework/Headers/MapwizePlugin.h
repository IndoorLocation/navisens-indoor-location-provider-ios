#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <IndoorLocation/IndoorLocation.h>
#import "MWZFollowUserModeEnum.h"

@protocol MWZMapwizePluginDelegate;
@protocol MWZVenueStateDelegate;

@class MWZOptions;
@class MWZFollowUserButton;
@class MWZPlace;
@class MWZPlaceList;
@class MWZStyle;
@class MWZDirection;
@class MWZMapwizeAnnotation;
@class MWZVenue;
@class MWZUniverse;
@class MWZLatLngFloor;
@class MWZUISettings;
@class MWZDirectionOptions;

@import Mapbox;

@interface MapwizePlugin : NSObject <MGLMapViewDelegate, UIGestureRecognizerDelegate, CLLocationManagerDelegate, UIGestureRecognizerDelegate>

@property (nonatomic, weak) id<MGLMapViewDelegate> mapboxDelegate;
@property (nonatomic, weak) id<MWZMapwizePluginDelegate> delegate;

@property (nonatomic) MWZFollowUserButton* followButton;


@property (nonatomic) UIView* bottomLayoutView;
@property (nonatomic) UIView* topLayoutView;

@property (nonatomic, readonly) ILIndoorLocation* userLocation;
@property (nonatomic, readonly) NSNumber* userHeading;

- (instancetype) initWith:(MGLMapView*) mglMapView options:(MWZOptions*) options;
- (instancetype) initWith:(MGLMapView*) mglMapView options:(MWZOptions*) options uiSettings:(MWZUISettings*) settings;

- (void) refreshWithCompletionHandler:(void (^)(void)) handler;
- (void) grantAccess:(NSString*) accessKey success:(void (^)(void)) success failure:(void (^)(NSError* error)) failure;

- (MWZVenue*) getVenue;

- (void) setFloor:(NSNumber*) floor;
- (void) setFloor:(NSNumber*) floor forVenue:(MWZVenue*) venue;
- (NSNumber*) getFloor;
- (NSArray<NSNumber*>*) getFloors;

- (void) centerOnVenue:(MWZVenue*) venue forceEntering:(BOOL) force;
- (void) centerOnPlace:(MWZPlace*) place;
- (void) centerOnUser;

- (void) setPreferredLanguage:(NSString*) language;
- (NSString*) getPreferredLanguage;
- (void) setLanguage:(NSString*) language;
- (void) setLanguage:(NSString*) language forVenue:(MWZVenue*) venue;
- (NSString*) getLanguageForVenue:(MWZVenue*) venue;
- (NSString*) getLanguage;


- (void) setUniverse:(MWZUniverse*) universe;
- (void) setUniverse:(MWZUniverse*) universe forVenue:(MWZVenue*) venue;
- (MWZUniverse*) getUniverseForVenue:(MWZVenue*) venue;
- (MWZUniverse*) getUniverse;

- (NSArray<MWZPlace*>*) getPromotedPlacesForVenue:(MWZVenue*) venue;
- (void) setPromotedPlaces:(NSArray<MWZPlace*>*) places forVenue:(MWZVenue*) venue;
- (void) addPromotedPlace:(MWZPlace*) place;
- (void) addPromotedPlaces:(NSArray<MWZPlace*>*) places;
- (void) removePromotedPlace:(MWZPlace*) place;
- (void) removePromotedPlaces:(NSArray<MWZPlace*>*) places;
- (void) removePromotedPlacesForVenue:(MWZVenue*) venue;
    
- (void) setStyle:(MWZStyle*) style forPlace:(MWZPlace*) place;

- (void) setDirection:(MWZDirection *)direction  options:(MWZDirectionOptions*) options;
- (void) setDirection:(MWZDirection*) direction;
- (MWZDirection*) getDirection;

- (void) setFollowUserMode:(FollowUserMode)followUserMode;
- (FollowUserMode) getFollowUserMode;

- (void) setIndoorLocationProvider:(ILIndoorLocationProvider*) locationProvider;

- (MWZMapwizeAnnotation*) addMarker:(MWZLatLngFloor*) latLngFloor;
- (MWZMapwizeAnnotation*) addMarker:(MWZLatLngFloor*) latLngFloor image:(UIImage*) image;
- (MWZMapwizeAnnotation*) addMarkerOnPlace:(MWZPlace*) place;
- (MWZMapwizeAnnotation*) addMarkerOnPlace:(MWZPlace*) place image:(UIImage*) image;
- (NSArray<MWZMapwizeAnnotation*>*) addMarkersOnPlaceList:(MWZPlaceList*) placeList;
- (NSArray<MWZMapwizeAnnotation*>*) addMarkersOnPlaceList:(MWZPlaceList*) placeList image:(UIImage*) image;
- (void) removeMarker:(MWZMapwizeAnnotation*) marker;
- (void) removeMarkers;

- (void) setBottomPadding:(CGFloat) bottomPadding;
- (void) setTopPadding:(CGFloat) topPadding;
- (void) setBottomPadding:(CGFloat) bottomPadding animationDuration:(CGFloat) duration;
- (void) setTopPadding:(CGFloat) topPadding animationDuration:(CGFloat) duration;

@end
