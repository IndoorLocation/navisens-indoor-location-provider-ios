#import <Foundation/Foundation.h>
#import "MWZObject.h"

@import Mapbox;

@class MWZLatLngFloor;
@class MWZTranslation;
@class MWZUniverse;

@interface MWZVenue : NSObject <MWZObject>

@property(nonatomic, readonly) NSString* identifier;
@property(nonatomic, readonly) NSString* name;
@property(nonatomic, readonly) NSString* alias;
@property(nonatomic, readonly) NSString* defaultLanguage;
@property(nonatomic, readonly, assign) MGLCoordinateBounds bounds;
@property(nonatomic, readonly) NSArray<NSString*>* supportedLanguages;
@property(nonatomic, readonly) NSString* icon;
@property(nonatomic, readonly) MWZLatLngFloor* marker;
@property(nonatomic, readonly) NSDictionary* geometry;
@property(nonatomic) NSArray<MWZUniverse*>* universes;
@property(nonatomic, readonly) NSArray<MWZTranslation*>* translations;
@property(nonatomic, readonly, assign) BOOL isPublished;
@property(nonatomic, readonly, assign) BOOL areQrcodesDeployed;
@property(nonatomic, readonly, assign) BOOL areIbeaconsDeployed;
@property(nonatomic, readonly) NSDate* updated;
@property(nonatomic, readonly) NSDictionary* data;
@property(nonatomic, readonly) NSDictionary* indoorLocationProviders;

- (instancetype)initWithIdentifier:(NSString*) identifer name:(NSString*) name alias:(NSString*) alias
                              icon:(NSString*) icon marker:(MWZLatLngFloor*) marker defaultLanguage:(NSString*) defaultLanguage supportedLanguages:(NSArray<NSString*>*) supportedLanguages geometry:(NSDictionary*) geometry universes:(NSArray<MWZUniverse*>*) universes translations:(NSArray<MWZTranslation*>*) translations isPublished:(BOOL) isPublished areQrcodesDeployed:(BOOL) areQrcodesDeployed areIbeaconsDeployed:(BOOL) areIbeaconsDeployed updated:(NSDate*) updated bounds:(MGLCoordinateBounds) bounds data:(NSDictionary*) data indoorLocationProviders:(NSDictionary*) indoorLocationProviders;

- (MWZUniverse*) defaultUniverse;
- (NSString*) defaultLanguage;

- (NSString*) titleForLanguage:(NSString*) language;

@end
