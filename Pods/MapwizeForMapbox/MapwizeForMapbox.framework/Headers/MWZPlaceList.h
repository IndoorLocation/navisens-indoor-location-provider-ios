#import <Foundation/Foundation.h>
#import "MWZDirectionPoint.h"
#import "MWZObject.h"

@class MWZTranslation;

@interface MWZPlaceList : NSObject <MWZDirectionPoint, MWZObject>

@property(nonatomic, readonly) NSString* identifier;
@property(nonatomic, readonly) NSString* name;
@property(nonatomic, readonly) NSString* alias;
@property(nonatomic, readonly) NSString* venueId;
@property(nonatomic, readonly) NSArray<NSString*>* placeIds;
@property(nonatomic, readonly) NSString* icon;
@property(nonatomic, readonly) NSArray<MWZTranslation*>* translations;
@property(nonatomic, readonly, assign) BOOL isPublished;
@property(nonatomic, readonly, assign) BOOL isSearchable;

- (instancetype) initWithIdentifier:(NSString*) identifier name:(NSString*) name alias:(NSString*) alias venueId:(NSString*) venueId placeIds:(NSArray<NSString*>*) placeIds
                               icon:(NSString*) icon translations:(NSArray<MWZTranslation*>*) translations isPublished:(BOOL) isPublished isSearchable:(BOOL) isSearchable;
                                                                                                                                               

@end
