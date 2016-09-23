//
//  CGContextSampleRow.m
//  CGCatalog
//
//  Created by Henry Fox on 14/09/2016.
//  Copyright © 2016 Vectorform. All rights reserved.
//

#import "CGContextSampleRow.h"

@implementation CGContextSampleRow

+ (CGContextSampleRow*)row:(NSString*)name class:(Class) class {
    CGContextSampleRow* row = [CGContextSampleRow new];
    row.name = name;
    row.class = class;
    return row;
}

@end
