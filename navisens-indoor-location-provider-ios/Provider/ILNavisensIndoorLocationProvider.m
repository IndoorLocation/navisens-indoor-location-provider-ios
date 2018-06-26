#import "ILNavisensIndoorLocationProvider.h"


@interface ILNavisensIndoorLocationProvider() <ILMotionDnaDelegate, ILIndoorLocationProviderDelegate>

@end

@implementation ILNavisensIndoorLocationProvider {
    BOOL started;
    int currentFloor;
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
        NSLog(@"startNavisens");
        self.motionDnaSDK = [[ILMotionDna alloc] init];
        self.motionDnaSDK.delegate = self;
        [self.motionDnaSDK runMotionDna:_navisensKey];
        [self.motionDnaSDK setCallbackUpdateRateInMs:1000];
        [self.motionDnaSDK setPowerMode:PERFORMANCE];
        
        if (self.sourceProvider) {
            [self.sourceProvider addDelegate:self];
        }
        
        started = YES;
    }
}

- (void) startWith:(ILMotionDna*) motionDnaSdk {
    if (!started) {
        self.motionDnaSDK = motionDnaSdk;
        self.motionDnaSDK.delegate = self;
        [self.motionDnaSDK runMotionDna:_navisensKey];
        
        if (self.sourceProvider) {
            [self.sourceProvider addDelegate:self];
        }
        
        started = YES;
    }
}

- (void) stop {
    if (started) {
        [self.motionDnaSDK stop];
        self.motionDnaSDK = nil;
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
    currentFloor = location.floor.intValue;
    [self.motionDnaSDK setFloorNumber:location.floor.intValue];
    [self.motionDnaSDK setLocationLatitude:location.latitude Longitude:location.longitude];
    [self.motionDnaSDK setHeadingMagInDegrees];
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

    self.location = &(location);
    [_delegate didChangeLocation:&(location)];

    NSLog(@"floor: %d", location.floor);
    
    if (location.floor != currentFloor) {
        currentFloor = location.floor;
        [_indoorLocation setFloor:[NSNumber numberWithInteger:currentFloor]];
    }
    
    ILIndoorLocation *indoorLocation = [[ILIndoorLocation alloc] initWithProvider:self latitude:location.globalLocation.latitude longitude:location.globalLocation.longitude floor:[NSNumber numberWithInteger:location.floor]];
    indoorLocation.timestamp = [NSDate date];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self dispatchDidUpdateLocation:indoorLocation];
    });
}

- (void) reportError:(ErrorCode)error WithMessage:(NSString *)message {
    [self dispatchDidFailWithError:[NSError errorWithDomain:message code:0 userInfo:nil]];
}

- (ILMotionDna*) retrieveMotionDnaSdk {
    return _motionDnaSDK;
}

- (Location*) getLocation {
    return self.location;
}

@end
