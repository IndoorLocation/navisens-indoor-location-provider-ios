#import "ILNavisensIndoorLocationProvider.h"

@implementation ILNavisensIndoorLocationProvider {
    BOOL started;
    ILMotionDna* motionDnaSDK;
    CLLocationManager* locationManager;
    CLLocationDirection userHeading;
    NSString* mKey;
    NSNumber* currentFloor;
}


- (id) initWithSourceProvider:(ILIndoorLocationProvider*) sourceProvider navisensDevKey:(NSString*) key {
    self = [super init];
    if (self) {
        started = NO;
        
        self.sourceProvider = sourceProvider;
        mKey = key;
    }
    
    return self;
}

- (void) start {
    if (!started) {
        NSLog(@"Starting NavisensProvider.");
        
        motionDnaSDK = [[ILMotionDna alloc] init];
        motionDnaSDK.delegate = self;
        
        [motionDnaSDK runMotionDna:mKey];
        
        
        [motionDnaSDK setCallbackUpdateRateInMs:1000];
        [motionDnaSDK setPowerMode:PERFORMANCE];
        
        
        if (self.sourceProvider)
            [self.sourceProvider addDelegate:self];
        
        locationManager = [[CLLocationManager alloc] init];
        locationManager.delegate = self;
        [locationManager startUpdatingHeading];
        started = YES;
    }
}

- (void) stop {
    if (started) {
        
        NSLog(@"Stopping NavisensProvider.");
        
        [locationManager stopUpdatingHeading];
        [motionDnaSDK stop];
        started = NO;
    }
}

- (BOOL) supportsFloor {
    return true;
}

- (BOOL) isStarted {
    return started;
}

- (void) receiveMotionDna:(MotionDna*)motionDna {
    dispatch_async(dispatch_get_main_queue(), ^{
        Location location = [motionDna getLocation];
        
        if (location.globalLocation.latitude == 0 && location.globalLocation.longitude == 0)
            return;
        
        
        ILIndoorLocation *indoorLocation = [[ILIndoorLocation alloc] initWithProvider:self latitude:location.globalLocation.latitude longitude:location.globalLocation.longitude floor:self->currentFloor];
        
        [self dispatchDidUpdateLocation:indoorLocation];
    });
}

- (void) locationManager:(CLLocationManager*)manager didUpdateHeading:(CLHeading*)newHeading {
    userHeading = newHeading.trueHeading;
}



// Delegates source provider

- (void)provider:(ILIndoorLocationProvider *)provider didFailWithError:(NSError *)error {
    [self dispatchDidFailWithError:error];
}

- (void)provider:(ILIndoorLocationProvider *)provider didUpdateLocation:(ILIndoorLocation *)location {
    [motionDnaSDK setLocationLatitude:location.latitude Longitude:location.longitude];
    [motionDnaSDK setHeadingMagInDegrees];

    [self dispatchDidUpdateLocation:location];
    
    
    currentFloor = location.floor;
    
}

- (void)providerDidStart:(ILIndoorLocationProvider *)provider {
    NSLog(@"providerDidStart");
}

- (void)providerDidStop:(ILIndoorLocationProvider *)provider {
    NSLog(@"providerDidStop");
}



// Delegates MotionDNA

- (void) reportSensorTiming:(double)dt Msg:(NSString *)msg {
    NSLog(@"%.9f %@\n", dt, msg);
}

- (void) reportError:(ErrorCode)error WithMessage:(NSString *)message {
    NSLog(@"reportError");
}

- (void) receiveNetworkData:(MotionDna *)motionDna {
    NSLog(@"receiveNetworkData");
}


@end
