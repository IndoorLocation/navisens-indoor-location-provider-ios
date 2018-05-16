#import "ILNavisensIndoorLocationProvider.h"
#import "ILMotionDnaDelegate.h"
#import "ILMotionDna.h"

@interface ILNavisensIndoorLocationProvider() <ILMotionDnaDelegate, ILIndoorLocationProviderDelegate, CLLocationManagerDelegate>

@end

@implementation ILNavisensIndoorLocationProvider {
    BOOL started;
    ILMotionDna* motionDnaSDK;
    NSNumber* currentFloor;
}


- (instancetype) initWith:(ILIndoorLocationProvider*) sourceProvider navisensKey:(NSString*) navisensKey {
    self = [super init];
    if (self) {
        started = NO;
        _sourceProvider = sourceProvider;
        _navisensKey = navisensKey;
    }
    
    return self;
}

- (void) start {
    if (!started) {
        motionDnaSDK = [[ILMotionDna alloc] init];
        motionDnaSDK.delegate = self;
        [motionDnaSDK setCallbackUpdateRateInMs:1000];
        [motionDnaSDK setPowerMode:PERFORMANCE];
        [motionDnaSDK runMotionDna:_navisensKey];
        
        if (self.sourceProvider) {
            [self.sourceProvider addDelegate:self];
        }
        
        started = YES;
    }
}

- (void) stop {
    if (started) {
        [motionDnaSDK stop];
        motionDnaSDK = nil;
        started = NO;
    }
}

- (BOOL) supportsFloor {
    return true;
}

- (BOOL) isStarted {
    return started;
}

#pragma mark ILLocationProviderDelegate

- (void)provider:(ILIndoorLocationProvider *)provider didFailWithError:(NSError *)error {
    [self dispatchDidFailWithError:error];
}

- (void)provider:(ILIndoorLocationProvider *)provider didUpdateLocation:(ILIndoorLocation *)location {
    currentFloor = location.floor;
    [motionDnaSDK setLocationLatitude:location.latitude Longitude:location.longitude];
    [motionDnaSDK setHeadingMagInDegrees];
    [self dispatchDidUpdateLocation:location];
}

- (void)providerDidStart:(ILIndoorLocationProvider *)provider {
    [self dispatchDidStart];
}

- (void)providerDidStop:(ILIndoorLocationProvider *)provider {
    [self dispatchDidStop];
}

#pragma mark ILMotionDnaDelegate

- (void) receiveMotionDna:(MotionDna*)motionDna {
    
    Location location = [motionDna getLocation];
    
    if (location.globalLocation.latitude == 0 && location.globalLocation.longitude == 0) {
        return;
    }
    
    ILIndoorLocation *indoorLocation = [[ILIndoorLocation alloc] initWithProvider:self latitude:location.globalLocation.latitude longitude:location.globalLocation.longitude floor:self->currentFloor];
    indoorLocation.timestamp = [NSDate date];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self dispatchDidUpdateLocation:indoorLocation];
    });
}

- (void) reportError:(ErrorCode)error WithMessage:(NSString *)message {
    [self dispatchDidFailWithError:[NSError errorWithDomain:message code:0 userInfo:nil]];
}

@end
