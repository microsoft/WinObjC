//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSIndexSet, AddIndexesInRange) {
    NSMutableIndexSet* indexSet = [NSMutableIndexSet new];

    LOG_INFO("Basic addIndexesInRange operation tests of NSIndexSet");

    // set up the indexSet with a few non overlapping indices.
    [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [indexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]
    [indexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]

    // make sure life is ok.
    unsigned int __block callCount = 0;
    NSArray* expected = @[ @2, @3, @4, @5, @7, @8, @11, @12, @13, @14, @15 ];

    [indexSet enumerateIndexesUsingBlock:^(NSUInteger index, BOOL* stop) {
        ASSERT_OBJCEQ([NSNumber numberWithUnsignedInt:index], [expected objectAtIndex:callCount++]);
    }];

    ASSERT_EQ(callCount, [expected count]);
    [expected release];

    // add in a left overlap.
    LOG_INFO("Left overlap addIndexesInRange operation tests of NSIndexSet");
    callCount = 0;
    [indexSet addIndexesInRange:NSMakeRange(1, 2)]; // [1-2]
    expected = @[ @1, @2, @3, @4, @5, @7, @8, @11, @12, @13, @14, @15 ];

    [indexSet enumerateIndexesUsingBlock:^(NSUInteger index, BOOL* stop) {
        ASSERT_OBJCEQ([NSNumber numberWithUnsignedInt:index], [expected objectAtIndex:callCount++]);
    }];

    ASSERT_EQ(callCount, [expected count]);
    [expected release];

    // add in a right overlap.
    LOG_INFO("Right overlap addIndexesInRange operation tests of NSIndexSet");
    callCount = 0;
    [indexSet addIndexesInRange:NSMakeRange(4, 3)]; // [4-6]
    expected = @[ @1, @2, @3, @4, @5, @6, @7, @8, @11, @12, @13, @14, @15 ];

    [indexSet enumerateIndexesUsingBlock:^(NSUInteger index, BOOL* stop) {
        ASSERT_OBJCEQ([NSNumber numberWithUnsignedInt:index], [expected objectAtIndex:callCount++]);
    }];

    ASSERT_EQ(callCount, [expected count]);
    [expected release];

    // add in a subset
    LOG_INFO("Subset addIndexesInRange operation tests of NSIndexSet");
    callCount = 0;
    [indexSet addIndexesInRange:NSMakeRange(12, 2)]; // [12-13]
    expected = @[ @1, @2, @3, @4, @5, @6, @7, @8, @11, @12, @13, @14, @15 ];

    [indexSet enumerateIndexesUsingBlock:^(NSUInteger index, BOOL* stop) {
        ASSERT_OBJCEQ([NSNumber numberWithUnsignedInt:index], [expected objectAtIndex:callCount++]);
    }];

    ASSERT_EQ(callCount, [expected count]);
    [expected release];

    // add in a candidate that spans multiple ranges. (super set of [1-8] and left overlap of [11-15])
    LOG_INFO("Superset addIndexesInRange operation tests of NSIndexSet");
    callCount = 0;
    [indexSet addIndexesInRange:NSMakeRange(0, 13)]; // [0-12]
    expected = @[ @0, @1, @2, @3, @4, @5, @6, @7, @8, @9, @10, @11, @12, @13, @14, @15 ];

    [indexSet enumerateIndexesUsingBlock:^(NSUInteger index, BOOL* stop) {
        ASSERT_OBJCEQ([NSNumber numberWithUnsignedInt:index], [expected objectAtIndex:callCount++]);
    }];

    ASSERT_EQ(callCount, [expected count]);
    [expected release];

    // add in an adjacent candidate.
    LOG_INFO("Adjacent addIndexesInRange operation tests of NSIndexSet");
    callCount = 0;
    [indexSet addIndexesInRange:NSMakeRange(16, 2)]; // [16-17]
    expected = @[ @0, @1, @2, @3, @4, @5, @6, @7, @8, @9, @10, @11, @12, @13, @14, @15, @16, @17 ];

    [indexSet enumerateIndexesUsingBlock:^(NSUInteger index, BOOL* stop) {
        ASSERT_OBJCEQ([NSNumber numberWithUnsignedInt:index], [expected objectAtIndex:callCount++]);
    }];

    ASSERT_EQ(callCount, [expected count]);
    [expected release];
    [indexSet release];
}

TEST(NSIndexSet, Init) {
    NSIndexSet* testSet = [[[NSIndexSet alloc] initWithIndex:2] autorelease];
    ASSERT_EQ(1, [testSet count]);

    testSet = [[[NSIndexSet alloc] initWithIndexesInRange:(NSRange){ 2, 0 }] autorelease];
    ASSERT_EQ(0, [testSet count]);

    ASSERT_ANY_THROW(([[NSIndexSet alloc] initWithIndexesInRange:(NSRange){ NSNotFound - 1, 2 }]));
}

TEST(NSIndexSet, EnumerateConcurrent) {
    __block NSCondition* condition = [NSCondition new];
    __block unsigned waitingCount = 0;

    // Validates that the block is executed on all indices concurrently by waiting on a condition until the count gets to 4.
    NSIndexSet* testSet = [[[NSIndexSet alloc] initWithIndexesInRange:(NSRange){ 2, 4 }] autorelease];
    [testSet enumerateIndexesWithOptions:NSEnumerationConcurrent
                              usingBlock:^(NSUInteger index, BOOL* stop) {
                                  [condition lock];
                                  waitingCount++;
                                  if (waitingCount == 4) {
                                      waitingCount--;
                                      [condition signal];
                                      [condition unlock];
                                      return;
                                  }
                                  [condition wait];
                                  waitingCount--;
                                  [condition signal];
                                  [condition unlock];
                              }];

    ASSERT_EQ(0, waitingCount);
}