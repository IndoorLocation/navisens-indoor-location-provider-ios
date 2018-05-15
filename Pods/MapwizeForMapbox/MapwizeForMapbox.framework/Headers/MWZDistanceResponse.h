#import <Foundation/Foundation.h>

@class MWZDirectionWrapper;
@class MWZDirectionWrapperAndDistance;

@interface MWZDistanceResponse : NSObject

@property(nonatomic, readonly) MWZDirectionWrapper* from;
@property(nonatomic, readonly) NSArray<MWZDirectionWrapperAndDistance*>* distances;

- (instancetype) initWith:(MWZDirectionWrapper*) from distances:(NSArray<MWZDirectionWrapperAndDistance*>*) distances;

@end
