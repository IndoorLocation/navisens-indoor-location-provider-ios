#import <Foundation/Foundation.h>
#import "ILMotionDna.h"
#import "ILMotionDnaDelegate.h"

@implementation ILMotionDna

- (void) receiveMotionDna:(MotionDna*)motionDna {
    if (_delegate) {
        [_delegate receiveMotionDna:motionDna];
    }
}

- (void) reportSensorTiming:(double)dt Msg:(NSString *)msg {
    
}

- (void) reportError:(ErrorCode)error WithMessage:(NSString *)message {
    if (_delegate) {
        [_delegate reportError:error WithMessage:message];
    }
}

- (void) receiveNetworkData:(MotionDna *)motionDna {
    
}

@end
