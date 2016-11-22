//
//  ScrollingView.m
//  CALayerSubclassTour
//
//  Created by Scott Gardner on 4/26/14.
//  Copyright (c) 2014 Optimac, Inc. All rights reserved.
//

#import "ScrollingView.h"

@implementation ScrollingView

+ (Class)layerClass {
    return [CAScrollLayer class];
}

@end
