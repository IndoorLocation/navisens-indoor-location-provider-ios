#import <UIKit/UIKit.h>
#import <Mapbox/Mapbox.h>
#import <MapwizeForMapbox/MapwizeForMapbox.h>
#import <ManualIndoorLocationProvider/ILManualIndoorLocationProvider.h>
#import "ILNavisensIndoorLocationProvider.h"

@interface ViewController : UIViewController <MWZMapwizePluginDelegate, ILMotionDnaLocationDelegate> //ILMotionDnaLocationDelegate to retrieve each location updates

@property (weak, nonatomic) IBOutlet MGLMapView *mglMapView;
@property (nonatomic, strong) MapwizePlugin* mapwizePlugin;
@property (nonatomic, strong) ILManualIndoorLocationProvider* sourceProvider;
@property (nonatomic, strong) ILNavisensIndoorLocationProvider* provider;

@end

