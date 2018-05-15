#import <Foundation/Foundation.h>
#import <AFNetworking/AFNetworking.h>

#import "MWZDirectionPoint.h"
#import "MWZObject.h"

@class MWZVenue;
@class MWZPlace;
@class MWZPlaceList;
@class MWZConnectorPlace;
@class MWZLayer;
@class MWZApiFilter;
@class MWZStyleSheet;
@class MWZIconImage;
@class MWZParsedUrlObject;
@class MWZDirection;
@class MWZSearchParams;
@class MWZUniverse;
@class MWZDistanceResponse;

@interface MWZApi : NSObject

/*
 Access request
 */
+ (NSURLSessionDataTask*)getAccess:(NSString*) accessKey success:(void (^)(void)) success failure:(void (^)(NSError* error)) failure;

/*
 Places requests
 */
+ (NSURLSessionDataTask*)getPlaceWithId:(NSString*) identifier success:(void (^)(MWZPlace* place)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getPlacesWithName:(NSString*) name venue:(MWZVenue*) venue success:(void (^)(MWZPlace* place)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getPlacesWithAlias:(NSString*) alias venue:(MWZVenue*) venue success:(void (^)(MWZPlace* place)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getPlacesWithFilter:(MWZApiFilter*) filter success:(void (^)(NSArray<MWZPlace*>* places)) success failure:(void (^)(NSError* error)) failure;

/*
 ConnectorPlaces requests
 */
+ (NSURLSessionDataTask*)getConnectorPlaceWithId:(NSString*) identifier success:(void (^)(MWZConnectorPlace* connectorPlace)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getConnectorPlacesWithName:(NSString*) name venue:(MWZVenue*) venue success:(void (^)(MWZConnectorPlace* connectorPlace)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getConnectorPlacesWithAlias:(NSString*) alias venue:(MWZVenue*) venue success:(void (^)(MWZConnectorPlace* connectorPlace)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getConnectorPlacesWithFilter:(MWZApiFilter*) filter success:(void (^)(NSArray<MWZConnectorPlace*>* connectors)) success failure:(void (^)(NSError* error)) failure;

/*
 PlaceLists requests
 */
+ (NSURLSessionDataTask*)getPlaceListWithId:(NSString*) identifier success:(void (^)(MWZPlaceList* placeList)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getPlaceListsWithName:(NSString*) name venue:(MWZVenue*) venue success:(void (^)(MWZPlaceList* placeList)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getPlaceListsWithAlias:(NSString*) alias venue:(MWZVenue*) venue success:(void (^)(MWZPlaceList* placeList)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getPlaceListsWithFilter:(MWZApiFilter*) filter success:(void (^)(NSArray<MWZPlaceList*>* placeLists)) success failure:(void (^)(NSError* error)) failure;

/*
 Venues requests
 */
+ (NSURLSessionDataTask*)getVenueWithId:(NSString*) identifier success:(void (^)(MWZVenue* venue)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getVenuesWithFilter:(MWZApiFilter*) filter success:(void (^)(NSArray<MWZVenue*>* venues))success failure:(void (^)(NSError *error))failure;
+ (NSURLSessionDataTask*)getVenueWithName:(NSString*) name success:(void (^)(MWZVenue* venue)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getVenueWithAlias:(NSString*) alias success:(void (^)(MWZVenue* venue)) success failure:(void (^)(NSError* error)) failure;
/*
 Layers requests
 */
+ (NSURLSessionDataTask*)getLayerWithId:(NSString*) identifier success:(void (^)(MWZLayer* layer)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getLayerWithName:(NSString*) name venue:(MWZVenue*) venue success:(void (^)(MWZLayer* layer)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getLayerWithAlias:(NSString*) alias venue:(MWZVenue*) venue success:(void (^)(MWZLayer* layer)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getLayersWithFilter:(MWZApiFilter*) filter success:(void (^)(NSArray<MWZLayer*>* layers)) success failure:(void (^)(NSError* error)) failure;

+ (NSURLSessionDataTask*)getStyleSheet:(NSString*) identifier success:(void (^)(MWZStyleSheet* styleSheet)) success failure:(void (^)(NSError* error)) failure;

/*
 Universes requests
 */
+ (NSURLSessionDataTask*)getUniverseWithId:(NSString*) identifier success:(void (^)(MWZUniverse* universe)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getUniversesWithFilter:(MWZApiFilter*) filter success:(void (^)(NSArray<MWZUniverse*>* universes)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getAccessibleUniversesWithVenue:(MWZVenue*) venue success:(void (^)(NSArray<MWZUniverse*>* universes)) success failure:(void (^)(NSError* error)) failure;

/*
 Directions requests
 */
+ (NSURLSessionDataTask*)getDirectionWithFrom:(id<MWZDirectionPoint>) from to:(id<MWZDirectionPoint>) to isAccessible:(BOOL) isAccessible success:(void (^)(MWZDirection* direction))success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getDirectionWithFrom:(id<MWZDirectionPoint>) from tos:(NSArray<id<MWZDirectionPoint>>*) tos isAccessible:(BOOL) isAccessible success:(void (^)(MWZDirection* direction))success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getDirectionWithFrom:(id<MWZDirectionPoint>) from to:(id<MWZDirectionPoint>) to waypoints:(NSArray<id<MWZDirectionPoint>>*) waypoints isAccessible:(BOOL) isAccessible success:(void (^)(MWZDirection* direction))success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getDirectionWithFrom:(id<MWZDirectionPoint>) from tos:(NSArray<id<MWZDirectionPoint>>*) tos waypoints:(NSArray<id<MWZDirectionPoint>>*) waypoints isAccessible:(BOOL) isAccessible success:(void (^)(MWZDirection* direction))success failure:(void (^)(NSError* error)) failure;

+ (NSURLSessionDataTask*)getDistanceWithFrom:(id<MWZDirectionPoint>) from tos:(NSArray<id<MWZDirectionPoint>>*) tos isAccessible:(BOOL) isAccessible sortByTravelTime:(BOOL) sort success:(void (^)(MWZDistanceResponse* distance))success failure:(void (^)(NSError* error)) failure;
/*
 Search requests
 */
+ (NSURLSessionDataTask*)searchWithParams:(MWZSearchParams*) searchParams success:(void (^)(NSArray<id<MWZObject>>* searchResponse)) success failure:(void (^)(NSError* error)) failure;

/*
 LoadUrl request
 */
+ (NSURLSessionDataTask*)getParsedUrlObject:(NSString*) url success:(void (^)(MWZParsedUrlObject* parsedObject)) success failure:(void (^)(NSError* error)) failure;

/*
 Main searches and main froms
 */
+ (NSURLSessionDataTask*)getMainFromsWithVenue:(MWZVenue*) venue success:(void (^)(NSArray<MWZPlace*>* places)) success failure:(void (^)(NSError* error)) failure;
+ (NSURLSessionDataTask*)getMainSearchesWithVenue:(MWZVenue*) venue success:(void (^)(NSArray<id<MWZObject>>* mainSearches)) success failure:(void (^)(NSError* error)) failure;


/*
 IconImages requests
 */
+ (NSURLSessionDataTask*)getImageWithUrl:(NSString*) url success:(void (^)(MWZIconImage *iconImage)) success failure:(void (^)(NSError *error)) failure;
@end
