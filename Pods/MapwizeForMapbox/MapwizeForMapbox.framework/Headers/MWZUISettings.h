#import <Foundation/Foundation.h>

@interface MWZUISettings : NSObject

@property (nonatomic, assign) BOOL logoEnabled;
@property (nonatomic, assign) BOOL mapwizeCompassEnabled;
@property (nonatomic, assign) BOOL showUserPositionControl;
@property (nonatomic, assign) BOOL showFloorControl;

- (instancetype) init;

@end
