#import "ILManualIndoorLocationProvider.h"

@implementation ILManualIndoorLocationProvider

- (BOOL) supportsFloor {
    return true;
}

- (void) start {
    // Do not require to be started
}

- (void) stop {
    // Do not require to be stopped
}

- (BOOL) isStarted {
    return YES;
}

- (void) setIndoorLocation:(ILIndoorLocation*) indoorLocation {
    [self dispatchDidUpdateLocation:indoorLocation];
}
    
@end
