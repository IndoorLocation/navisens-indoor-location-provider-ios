#import <Foundation/Foundation.h>

@interface MWZApiFilter : NSObject

@property (nonatomic) NSString* venueId;
@property (nonatomic) NSString* universeId;
@property (nonatomic) NSNumber* isVisible;
@property (nonatomic) NSString* organizationId;
@property (nonatomic) NSString* alias;
@property (nonatomic) NSString* name;
@property (nonatomic) NSNumber* latitudeMin;
@property (nonatomic) NSNumber* latitudeMax;
@property (nonatomic) NSNumber* longitudeMin;
@property (nonatomic) NSNumber* longitudeMax;

- (NSMutableDictionary*) toDictionary;

@end
