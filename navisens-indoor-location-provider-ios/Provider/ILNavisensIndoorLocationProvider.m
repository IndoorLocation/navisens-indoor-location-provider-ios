#import "ILNavisensIndoorLocationProvider.h"

@interface ILNavisensIndoorLocationProvider() <ILMotionDnaDelegate, ILIndoorLocationProviderDelegate>

@property (nonatomic, assign) BOOL started;
@property (nonatomic) NSNumber* currentFloor;

@end

@implementation ILNavisensIndoorLocationProvider

- (instancetype) initWith:(NSString*) navisensKey {
    self = [super init];
    if (self) {
        _started = NO;
        _navisensKey = navisensKey;
        self.motionDnaSDK = [[ILMotionDna alloc] init];
        self.motionDnaSDK.delegate = self;
    }
    return self;
}

- (instancetype) initWith:(NSString*) navisensKey sourceProvider:(ILIndoorLocationProvider*) sourceProvider {
    self = [super init];
    if (self) {
        _started = NO;
        _sourceProvider = sourceProvider;
        [_sourceProvider addDelegate:self];
        _navisensKey = navisensKey;
        self.motionDnaSDK = [[ILMotionDna alloc] init];
        self.motionDnaSDK.delegate = self;
    }
    return self;
}

- (void) start {
    if (!self.started) {
        [self.motionDnaSDK runMotionDna:_navisensKey];
        [self.motionDnaSDK setCallbackUpdateRateInMs:1000];
        [self.motionDnaSDK setPowerMode:PERFORMANCE];
        self.started = YES;
    }
}

- (void) stop {
    if (self.started) {
        [self.motionDnaSDK stop];
        self.started = NO;
    }
}

- (BOOL) supportsFloor {
    return true;
}

- (BOOL) isStarted {
    return self.started;
}

- (void) setIndoorLocation:(ILIndoorLocation*) indoorLocation {
    self.currentFloor = indoorLocation.floor;
    if (indoorLocation.floor) {
        [self.motionDnaSDK setFloorNumber:indoorLocation.floor.intValue];
    }
    [self.motionDnaSDK setLocationLatitude:indoorLocation.latitude Longitude:indoorLocation.longitude];
    [self.motionDnaSDK setHeadingMagInDegrees];
    [self dispatchDidUpdateLocation:indoorLocation];
}

#pragma mark ILLocationProviderDelegate

- (void)provider:(ILIndoorLocationProvider*) provider didFailWithError:(NSError*) error {
    [self dispatchDidFailWithError:error];
}

- (void)provider:(ILIndoorLocationProvider*) provider didUpdateLocation:(ILIndoorLocation*) location {
    [self setIndoorLocation:location];
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
    self.currentFloor = [NSNumber numberWithInteger: location.floor];
    
    ILIndoorLocation* indoorLocation = [[ILIndoorLocation alloc] initWithProvider: self latitude: location.globalLocation.latitude longitude: location.globalLocation.longitude floor: self.currentFloor];
    indoorLocation.timestamp = [NSDate date];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self dispatchDidUpdateLocation:indoorLocation];
    });
}

- (void) reportError:(ErrorCode) error WithMessage:(NSString *) message {
    [self dispatchDidFailWithError:[NSError errorWithDomain: message code: 0 userInfo: nil]];
}

@end
