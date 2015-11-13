/* Copyright (c) 2007 Dirk Theisen

   Portions Copyright (c) 2015 Microsoft Corporation. All rights reserved.
   Portions Copyright (c) 2013 Peter Steinberger. All rights reserved.
   
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObject.h>

FOUNDATION_EXPORT_CLASS
@interface NSIndexPath : NSObject <NSCopying, NSCoding> {
    NSUInteger _length;
    NSUInteger* _indexes;
}

+ (NSIndexPath*)indexPathForRow:(unsigned)row inSection:(unsigned)section;
+ (NSIndexPath*)indexPathForItem:(NSInteger)item inSection:(NSInteger)section;

+ (NSIndexPath*)indexPathWithIndex:(NSUInteger)index;
+ (NSIndexPath*)indexPathWithIndexes:(NSUInteger*)indexes length:(NSUInteger)length;

- (id)initWithIndex:(NSUInteger)index;
- (id)initWithIndexes:(NSUInteger*)indexes length:(NSUInteger)length; // designated initializer

- (NSIndexPath*)indexPathByAddingIndex:(NSUInteger)index;
- (NSIndexPath*)indexPathByRemovingLastIndex;

- (NSUInteger)indexAtPosition:(NSUInteger)position;
- (NSUInteger)length;

- (NSUInteger)row;
- (NSUInteger)item;
- (NSUInteger)section;

- (void)getIndexes:(NSUInteger*)indexes;

// comparison support
- (NSComparisonResult)compare:(NSIndexPath*)otherObject; // sorting an array of indexPaths using this comparison results in an array
                                                         // representing nodes in depth-first traversal order

@end
