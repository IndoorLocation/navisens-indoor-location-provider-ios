#import <Foundation/Foundation.h>

@interface MWZTranslation : NSObject

@property(nonatomic, readonly) NSString* identifier;
@property(nonatomic, readonly) NSString* title;
@property(nonatomic, readonly) NSString* subtitle;
@property(nonatomic, readonly) NSString* details;
@property(nonatomic, readonly) NSString* language;

- (instancetype) initWithIdentifer:(NSString*) identifer title:(NSString*) title subtitle:(NSString*) subtitle details:(NSString*) details language:(NSString*) language;

@end
