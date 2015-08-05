/* Copyright (c) 2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSINDEXSET_H_
#define _NSINDEXSET_H_

#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>

FOUNDATION_EXPORT_CLASS
@interface NSIndexSet : NSObject <NSCoding, NSCopying, NSMutableCopying> {
@public
    NSRange *_ranges;
    unsigned _length, _maxLength;
}

+ indexSetWithIndexesInRange:(NSRange)range;
+ indexSetWithIndex:(NSUInteger)index;
+ indexSet;

- initWithIndexSet:(NSIndexSet *)other;
- initWithIndexesInRange:(NSRange)range;
- initWithIndex:(NSUInteger)index;
- init;

- (BOOL)isEqualToIndexSet:(NSIndexSet *)other;  

- (NSUInteger)count;
- (NSUInteger)firstIndex;
- (NSUInteger)lastIndex;
- (NSUInteger)getIndexes:(NSUInteger *)buffer maxCount:(NSUInteger)capacity inIndexRange:(NSRange *)range;

- (BOOL)containsIndexesInRange:(NSRange)range;
- (BOOL)containsIndexes:(NSIndexSet *)other;
- (BOOL)containsIndex:(NSUInteger)index;

- (NSUInteger)indexGreaterThanIndex:(NSUInteger)index;
- (NSUInteger)indexGreaterThanOrEqualToIndex:(NSUInteger)index;
- (NSUInteger)indexLessThanIndex:(NSUInteger)index;
- (NSUInteger)indexLessThanOrEqualToIndex:(NSUInteger)index;

- (BOOL)intersectsIndexesInRange:(NSRange)range;

- (void)encodeWithCoder:(NSCoder *)encoder;
- (id)initWithCoder:(NSCoder *)decoder;

- (NSUInteger)countOfIndexesInRange:(NSRange)indexRange;

- (void)enumerateIndexesUsingBlock:(void (^)(NSUInteger idx, BOOL *stop))block;
- (void)enumerateIndexesWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(NSUInteger idx, BOOL *stop))block;
- (NSUInteger)indexPassingTest:(BOOL (^)(NSUInteger idx, BOOL *stop))predicate;
- (NSIndexSet *)indexesPassingTest:(BOOL (^)(NSUInteger idx, BOOL *stop))predicate;

@end

#import <Foundation/NSMutableIndexSet.h>

#endif /* _NSINDEXSET_H_ */