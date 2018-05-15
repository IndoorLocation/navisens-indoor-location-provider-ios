#ifndef MWZMapwizePluginDelegate_h
#define MWZMapwizePluginDelegate_h

@import Mapbox;
#import "MWZVenue.h"
#import "MWZFollowUserModeEnum.h"
@class MapwizePlugin;
@class MWZPlace;

@protocol MWZMapwizePluginDelegate <NSObject>

@optional

- (void) mapwizePluginDidLoad:(MapwizePlugin*) mapwizePlugin;

- (void) plugin:(MapwizePlugin*) plugin didChangeFollowUserMode:(FollowUserMode) followUserMode;

- (void) plugin:(MapwizePlugin*) plugin didTapOnVenue:(MWZVenue*) venue;
- (void) plugin:(MapwizePlugin*) plugin willEnterVenue:(MWZVenue*) venue;
- (void) plugin:(MapwizePlugin*) plugin didEnterVenue:(MWZVenue*) venue;
- (void) plugin:(MapwizePlugin*) plugin didExitVenue:(MWZVenue*) venue;

- (void) plugin:(MapwizePlugin*) plugin didTapOnPlace:(MWZPlace*) place;

- (void) plugin:(MapwizePlugin*) plugin didTapOnMap:(MWZLatLngFloor*) latLngFloor;

- (void) plugin:(MapwizePlugin*) plugin didChangeFloor:(NSNumber*) floor;
- (void) plugin:(MapwizePlugin*) plugin didChangeFloors:(NSArray<NSNumber*>*) floors;

@end

#endif
