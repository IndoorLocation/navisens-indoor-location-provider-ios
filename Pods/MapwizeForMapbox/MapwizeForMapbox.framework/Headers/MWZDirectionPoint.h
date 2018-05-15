#ifndef DirectionPoint_h
#define DirectionPoint_h

#import <Foundation/Foundation.h>

@class MWZDirectionWrapper;

@protocol MWZDirectionPoint <NSObject>

- (MWZDirectionWrapper*) toDirectionWrapper;

@end
#endif
