#ifndef ILMotionDnaDelegate_h
#define ILMotionDnaDelegate_h

@protocol ILMotionDnaDelegate <NSObject>

- (void) receiveMotionDna:(MotionDna*)motionDna;

- (void) reportError:(ErrorCode)error WithMessage:(NSString *)message;

@end


#endif
