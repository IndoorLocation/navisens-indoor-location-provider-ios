#import <UIKit/UIKit.h>
#import "MWZFollowUserModeEnum.h"

@protocol MWZFollowUserModeDelegate;

@interface MWZFollowUserButton : UIButton

@property (nonatomic, weak) id<MWZFollowUserModeDelegate> delegate;

- (void) setMode:(FollowUserMode) mode;

@end
