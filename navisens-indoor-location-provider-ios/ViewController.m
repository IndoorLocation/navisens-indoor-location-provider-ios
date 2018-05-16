#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

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
    
    self.provider = [[ILNavisensIndoorLocationProvider alloc] initWith:self.sourceProvider navisensKey:@"YOUR NAVISENS DEV KEY"];
    
    [self.mapwizePlugin setIndoorLocationProvider:self.provider];
    
    [self.sourceProvider start];
    
}

- (void) plugin:(MapwizePlugin *)plugin didTapOnMap:(MWZLatLngFloor *)latLngFloor {
    NSLog(@"Tap on map");
    ILIndoorLocation* location = [[ILIndoorLocation alloc] initWithProvider:self.provider latitude:latLngFloor.coordinates.latitude longitude:latLngFloor.coordinates.longitude floor:latLngFloor.floor];
    [self.sourceProvider setIndoorLocation:location];
}

@end
