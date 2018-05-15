#import <Foundation/Foundation.h>

@interface MWZUniverse : NSObject

@property(nonatomic, readonly) NSString* identifier;
@property(nonatomic, readonly) NSString* name;

- (instancetype)initWithIdentifier:(NSString*) identifier name:(NSString*) name;

@end
