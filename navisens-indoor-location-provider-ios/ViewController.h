#import <UIKit/UIKit.h>
#import <Mapbox/Mapbox.h>
#import <MapwizeForMapbox/MapwizeForMapbox.h>
#import <ManualIndoorLocationProvider/ILManualIndoorLocationProvider.h>
#import "ILNavisensIndoorLocationProvider.h"

@interface ViewController : UIViewController <MWZMapwizePluginDelegate>

@property (weak, nonatomic) IBOutlet MGLMapView *mglMapView;
@property (nonatomic) MapwizePlugin* mapwizePlugin;
@property (nonatomic) ILManualIndoorLocationProvider* manualProvider;
@property (nonatomic) ILNavisensIndoorLocationProvider* navisensProvider;

@end

