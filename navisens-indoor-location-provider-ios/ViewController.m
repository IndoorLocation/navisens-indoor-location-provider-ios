#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController {
    ILMotionDna* motionDnaSdk;
    __weak IBOutlet UILabel *label;
    double lastLocationFloor;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.mapwizePlugin = [[MapwizePlugin alloc] initWith:self.mglMapView options:[[MWZOptions alloc] init]];
    
    self.mapwizePlugin.delegate = self;
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) mapwizePluginDidLoad:(MapwizePlugin *)mapwizePlugin {
    self.sourceProvider = [[ILManualIndoorLocationProvider alloc] init];
    
    
    self.provider = [[ILNavisensIndoorLocationProvider alloc] initWith:self.sourceProvider navisensKey:@"uu6oF6dDdNsIBWBez4pw2GuMwNWGJlLpRjVjsa4c23XrT8wqT7BKnXS7WuWSyPfc"];
    
    self.provider.delegate = self;
    
    [self.mapwizePlugin setIndoorLocationProvider:self.provider];
    
    [self.sourceProvider start];
    
    
    /*motionDnaSdk = [[ILMotionDna alloc] init];
    [motionDnaSdk setCallbackUpdateRateInMs:1000];// after start to override default values
    [motionDnaSdk setPowerMode:PERFORMANCE];// after start to override default values
    [self.provider startWith:motionDnaSdk];*/
    motionDnaSdk = [self.provider retrieveMotionDnaSdk];
    [motionDnaSdk setAverageFloorHeight:4.8];
    
}

- (void) plugin:(MapwizePlugin *)plugin didTapOnMap:(MWZLatLngFloor *)latLngFloor {
    ILIndoorLocation* location = [[ILIndoorLocation alloc] initWithProvider:self.provider latitude:latLngFloor.coordinates.latitude longitude:latLngFloor.coordinates.longitude floor:latLngFloor.floor];
    [self.sourceProvider setIndoorLocation:location];
}

- (void) didChangeLocation:(Location*)location {
    NSString* vmotion;
    if (location == nil) {
        return;
    }
    if (location->verticalMotionStatus == VERTICAL_STATUS_LEVEL_GROUND) {
        vmotion = @"VERTICAL_STATUS_LEVEL_GROUND";
    } else if (location->verticalMotionStatus == VERTICAL_STATUS_ESCALATOR_UP) {
        vmotion = @"VERTICAL_STATUS_ESCALATOR_UP";
    } else if (location->verticalMotionStatus == VERTICAL_STATUS_ESCALATOR_DOWN) {
        vmotion = @"VERTICAL_STATUS_ESCALATOR_DOWN";
    } else if (location->verticalMotionStatus == VERTICAL_STATUS_ELEVATOR_UP) {
        vmotion = @"VERTICAL_STATUS_ELEVATOR_UP";
    } else if (location->verticalMotionStatus == VERTICAL_STATUS_ELEVATOR_DOWN) {
        vmotion = @"VERTICAL_STATUS_ELEVATOR_DOWN";
    } else if (location->verticalMotionStatus == VERTICAL_STATUS_STAIRS_UP) {
        vmotion = @"VERTICAL_STATUS_STAIRS_UP";
    } else if (location->verticalMotionStatus == VERTICAL_STATUS_STAIRS_DOWN) {
        vmotion = @"VERTICAL_STATUS_STAIRS_DOWN";
    } else {
        vmotion = @"NO";
    }
    
    int floor = location->floor;
    float altitude = location->absoluteAltitude;
    dispatch_async(dispatch_get_main_queue(), ^{
        self->label.text = [NSString stringWithFormat:@"floor %d \r motion %@  \r altitude=@%f", floor, vmotion, altitude];
    });
    
    if (lastLocationFloor != location->floor) {
        [self.mapwizePlugin setFloor:[NSNumber numberWithInteger:location->floor]];
    }
    lastLocationFloor = location->floor;
}



@end
