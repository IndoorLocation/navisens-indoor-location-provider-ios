#ifndef ILMotionDnaDelegate_h
#define ILMotionDnaDelegate_h

@protocol ILMotionDnaDelegate <NSObject>

- (void) receiveMotionDna:(MotionDna*)motionDna;

- (void) reportSensorTiming:(double)dt Msg:(NSString *)msg;

- (void) reportError:(ErrorCode)error WithMessage:(NSString *)message;

- (void) receiveNetworkData:(MotionDna *)motionDna;

@end


#endif
