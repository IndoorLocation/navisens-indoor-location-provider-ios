@import Mapbox;

@protocol MWZMapwizeAnnotationDelegate;

@interface MWZMapwizeAnnotation : MGLPointAnnotation

@property (nonatomic) NSNumber* floor;
@property (nonatomic) UIImage* image;
@property (nonatomic, weak) id<MWZMapwizeAnnotationDelegate> delegate;

@end
