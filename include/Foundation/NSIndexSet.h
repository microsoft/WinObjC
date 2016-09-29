//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// Copyright (c) 2007 Christopher J. W. Lloyd
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>

FOUNDATION_EXPORT_CLASS
@interface NSIndexSet : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>

+ (instancetype)indexSet;
+ (instancetype)indexSetWithIndex:(NSUInteger)index;
+ (instancetype)indexSetWithIndexesInRange:(NSRange)indexRange;
- (instancetype)initWithIndex:(NSUInteger)index;
- (instancetype)initWithIndexesInRange:(NSRange)indexRange;
- (instancetype)initWithIndexSet:(NSIndexSet*)indexSet;
- (BOOL)containsIndex:(NSUInteger)index;
- (BOOL)containsIndexes:(NSIndexSet*)indexSet;
- (BOOL)containsIndexesInRange:(NSRange)indexRange;
- (BOOL)intersectsIndexesInRange:(NSRange)indexRange;
@property (readonly) NSUInteger count;
- (NSUInteger)countOfIndexesInRange:(NSRange)indexRange;
- (NSUInteger)indexPassingTest:(BOOL (^)(NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesPassingTest:(BOOL (^)(NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSUInteger)indexWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesWithOptions:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSUInteger)indexInRange:(NSRange)range options:(NSEnumerationOptions)opts passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate STUB_METHOD;
- (NSIndexSet*)indexesInRange:(NSRange)range
                      options:(NSEnumerationOptions)opts
                  passingTest:(BOOL (^)(NSUInteger, BOOL*))predicate STUB_METHOD;
- (void)enumerateRangesInRange:(NSRange)range options:(NSEnumerationOptions)opts usingBlock:(void (^)(NSRange, BOOL*))block STUB_METHOD;
- (void)enumerateRangesUsingBlock:(void (^)(NSRange, BOOL*))block STUB_METHOD;
- (void)enumerateRangesWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(NSRange, BOOL*))block STUB_METHOD;
- (BOOL)isEqualToIndexSet:(NSIndexSet*)indexSet;
@property (readonly) NSUInteger firstIndex;
@property (readonly) NSUInteger lastIndex;
- (NSUInteger)indexLessThanIndex:(NSUInteger)index;
- (NSUInteger)indexLessThanOrEqualToIndex:(NSUInteger)index;
- (NSUInteger)indexGreaterThanOrEqualToIndex:(NSUInteger)index;
- (NSUInteger)indexGreaterThanIndex:(NSUInteger)index;
- (NSUInteger)getIndexes:(NSUInteger*)indexBuffer maxCount:(NSUInteger)bufferSize inIndexRange:(NSRangePointer)indexRange STUB_METHOD;
- (void)enumerateIndexesUsingBlock:(void (^)(NSUInteger, BOOL*))block;
- (void)enumerateIndexesWithOptions:(NSEnumerationOptions)opts usingBlock:(void (^)(NSUInteger, BOOL*))block;
- (void)enumerateIndexesInRange:(NSRange)range options:(NSEnumerationOptions)opts usingBlock:(void (^)(NSUInteger, BOOL*))block STUB_METHOD;
@end
