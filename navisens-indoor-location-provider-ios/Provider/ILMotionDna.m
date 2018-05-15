#import <Foundation/Foundation.h>
#import <MotionDnaSDK/MotionDna.h>

#import "ILMotionDna.h"
#import "ILNavisensIndoorLocationProvider.h"

@implementation ILMotionDna

- (id) init {
    self = [super init];
    return self;
}

- (void) receiveMotionDna:(MotionDna*)motionDna {
    if (_delegate) {
        [_delegate receiveMotionDna:motionDna];
    }
}

- (void) reportSensorTiming:(double)dt Msg:(NSString *)msg
{
    if (_delegate) {
        [_delegate reportSensorTiming:dt Msg:msg];
    }
}

- (void) reportError:(ErrorCode)error WithMessage:(NSString *)message {
    if (_delegate) {
        [_delegate reportError:error WithMessage:message];
    }
}

- (void) receiveNetworkData:(MotionDna *)motionDna {
    if (_delegate) {
        [_delegate receiveMotionDna:motionDna];
    }
}

@end
