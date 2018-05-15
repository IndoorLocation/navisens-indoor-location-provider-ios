#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "ILIndoorLocation.h"
#import "ILIndoorLocationProvider.h"
#import "ILIndoorLocationProviderDelegate.h"
#import "IndoorLocation.h"

FOUNDATION_EXPORT double IndoorLocationVersionNumber;
FOUNDATION_EXPORT const unsigned char IndoorLocationVersionString[];

