#import <Foundation/Foundation.h>

@interface MWZSearchParams : NSObject

@property (nonatomic) NSString* query;
@property (nonatomic) NSString* venueId;
@property (nonatomic) NSString* organizationId;
@property (nonatomic) NSString* universeId;
@property (nonatomic) NSArray<NSString*>* objectClass;

- (NSDictionary*) toDictionary;

@end
