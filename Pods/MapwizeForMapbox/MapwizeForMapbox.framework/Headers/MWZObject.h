#ifndef MWZObject_h
#define MWZObject_h

#import "MWZTranslation.h"

@protocol MWZObject <NSObject>

- (NSString*) name;
- (NSString*) alias;
- (NSString*) identifier;
- (NSString*) icon;
- (NSArray<MWZTranslation*>*) translations;
- (NSString*) titleForLanguage:(NSString*) language;
- (NSString*) subtitleForLanguage:(NSString*) language;
- (NSString*) detailsForLanguage:(NSString*) language;

@end

#endif
