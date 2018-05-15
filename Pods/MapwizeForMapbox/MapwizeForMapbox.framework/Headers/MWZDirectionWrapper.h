#import <Foundation/Foundation.h>

@interface MWZDirectionWrapper : NSObject

@property(nonatomic) NSNumber* latitude;
@property(nonatomic) NSNumber* longitude;
@property(nonatomic) NSNumber* floor;
@property(nonatomic) NSString* placeId;
@property(nonatomic) NSString* venueId;
@property(nonatomic) NSString* placeListId;

- (instancetype) init;

- (instancetype) initWithLatitude:(NSNumber*) latitude longitude:(NSNumber*) longitude floor:(NSNumber*) floor placeId:(NSString*) placeId venueId:(NSString*) venueId placeListId:(NSString*) placeListId;

- (NSDictionary*) toDictionary;

@end
