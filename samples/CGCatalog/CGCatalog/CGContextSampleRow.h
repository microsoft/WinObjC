//
//  CGContextSampleRow.h
//  CGCatalog
//
//  Created by Henry Fox on 14/09/2016.
//  Copyright © 2016 Vectorform. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CGContextSampleRow : NSObject

+ (CGContextSampleRow*)row:(NSString*)name class:(Class) class;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) Class class;

@end
