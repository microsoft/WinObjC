//
//  Constants.h
//  CALayerSubclassTour
//
//  Created by Scott Gardner on 5/17/14.
//  Copyright (c) 2014 Optimac, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

@interface Constants : NSObject

extern CGFloat const Quarter;
extern CGFloat const Half;
extern CGFloat const Zero;
extern CGFloat const One;
extern CGFloat const Two;
extern CGFloat const TFF;

extern NSString* const FileName;

#define DEGREES_TO_RADIANS(DEGREES) (DEGREES * M_PI / 180.0f)
#define RADIANS_TO_DEGREES(RADIANS) (RADIANS / M_PI * 180.0f)

@end
