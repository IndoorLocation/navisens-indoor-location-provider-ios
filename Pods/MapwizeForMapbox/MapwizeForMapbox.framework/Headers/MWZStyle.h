#import <Foundation/Foundation.h>

@interface MWZStyle : NSObject

@property(nonatomic) NSString* markerUrl;
@property(nonatomic) NSString* fillColor;
@property(nonatomic) NSString* strokeColor;
@property(nonatomic) NSNumber* fillOpacity;
@property(nonatomic) NSNumber* strokeOpacity;
@property(nonatomic) NSNumber* strokeWidth;
@property(nonatomic, assign) BOOL isMarkerDisplay;
@property(nonatomic, assign) BOOL isShapeDisplay;

- (instancetype) initWithMarkerUrl:(NSString*) markerUrl fillColor:(NSString*) fillColor strokeColor:(NSString*) strokeColor fillOpacity:(NSNumber*) fillOpacity
                     strokeOpacity:(NSNumber*) strokeOpacity strokeWidth:(NSNumber*) strokeWidth isMarkerDisplay:(BOOL) isMarkerDisplay isShapeDisplay:(BOOL) isShapeDisplay;

@end
