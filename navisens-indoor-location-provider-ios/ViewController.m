#import "ViewController.h"

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.mapwizePlugin = [[MapwizePlugin alloc] initWith:self.mglMapView options:[[MWZOptions alloc] init]];
    self.mapwizePlugin.delegate = self;
}

- (void) mapwizePluginDidLoad:(MapwizePlugin *)mapwizePlugin {
    self.manualProvider = [[ILManualIndoorLocationProvider alloc] init];
    [self.manualProvider start];
    
    NSString* navisensKey = @"YOUR_NAVISENS_KEY_HERE";
    
    self.navisensProvider = [[ILNavisensIndoorLocationProvider alloc] initWith:navisensKey sourceProvider:self.manualProvider];
    [self.mapwizePlugin setIndoorLocationProvider:self.navisensProvider];
}

- (void) plugin:(MapwizePlugin *)plugin didTapOnMap:(MWZLatLngFloor *)latLngFloor {
    ILIndoorLocation* location = [[ILIndoorLocation alloc] initWithProvider:self.navisensProvider latitude:latLngFloor.coordinates.latitude longitude:latLngFloor.coordinates.longitude floor:latLngFloor.floor];
    [self.manualProvider setIndoorLocation:location];
}

@end
