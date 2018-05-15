#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface MWZDirectionOptions : NSObject

@property (nonatomic, strong) UIImage* endMarkerIcon;
@property (nonatomic, assign) BOOL displayEndMarker;
@property (nonatomic, assign) BOOL centerOnStart;
@property (nonatomic, assign) BOOL setToStartingFloor;

@end
