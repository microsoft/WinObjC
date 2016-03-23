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

void verifyIndexSetEqualsArray(NSArray* expected, NSIndexSet* actual) {
    __block unsigned int callCount = 0;

    [actual enumerateIndexesUsingBlock:^(NSUInteger index, BOOL* stop) {
        ASSERT_OBJCEQ([expected objectAtIndex:callCount++], [NSNumber numberWithUnsignedInt:index]);
    }];

    ASSERT_EQ([expected count], callCount);
}

TEST(NSIndexSet, AddIndexesInRange) {
    NSMutableIndexSet* indexSet = [NSMutableIndexSet new];

    LOG_INFO("Basic addIndexesInRange operation tests of NSIndexSet");

    // set up the indexSet with a few non overlapping indices.
    [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [indexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]
    [indexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]

    // make sure life is ok.
    NSArray* expected = @[ @2, @3, @4, @5, @7, @8, @11, @12, @13, @14, @15 ];
    verifyIndexSetEqualsArray(expected, indexSet);

    // add in a left overlap.
    LOG_INFO("Left overlap addIndexesInRange operation tests of NSIndexSet");
    [indexSet addIndexesInRange:NSMakeRange(1, 2)]; // [1-2]
    expected = @[ @1, @2, @3, @4, @5, @7, @8, @11, @12, @13, @14, @15 ];
    verifyIndexSetEqualsArray(expected, indexSet);

    // add in a right overlap.
    LOG_INFO("Right overlap addIndexesInRange operation tests of NSIndexSet");
    [indexSet addIndexesInRange:NSMakeRange(4, 3)]; // [4-6]
    expected = @[ @1, @2, @3, @4, @5, @6, @7, @8, @11, @12, @13, @14, @15 ];
    verifyIndexSetEqualsArray(expected, indexSet);

    // add in a subset
    LOG_INFO("Subset addIndexesInRange operation tests of NSIndexSet");
    [indexSet addIndexesInRange:NSMakeRange(12, 2)]; // [12-13]
    expected = @[ @1, @2, @3, @4, @5, @6, @7, @8, @11, @12, @13, @14, @15 ];
    verifyIndexSetEqualsArray(expected, indexSet);

    // add in a candidate that spans multiple ranges. (super set of [1-8] and left overlap of [11-15])
    LOG_INFO("Superset addIndexesInRange operation tests of NSIndexSet");
    [indexSet addIndexesInRange:NSMakeRange(0, 13)]; // [0-12]
    expected = @[ @0, @1, @2, @3, @4, @5, @6, @7, @8, @9, @10, @11, @12, @13, @14, @15 ];
    verifyIndexSetEqualsArray(expected, indexSet);

    // add in an adjacent candidate.
    LOG_INFO("Adjacent addIndexesInRange operation tests of NSIndexSet");
    [indexSet addIndexesInRange:NSMakeRange(16, 2)]; // [16-17]
    expected = @[ @0, @1, @2, @3, @4, @5, @6, @7, @8, @9, @10, @11, @12, @13, @14, @15, @16, @17 ];
    verifyIndexSetEqualsArray(expected, indexSet);
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

TEST(NSIndexSet, addIndex) {
    NSMutableIndexSet* indexSet = [NSMutableIndexSet new];

    // Test addIndex
    [indexSet addIndex:2];

    // Verify that the set contains 2 and no other indices.
    NSArray* expected = @[ @2 ];
    verifyIndexSetEqualsArray(expected, indexSet);

    // set up the indexSet with a few non overlapping indices.
    [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [indexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]
    [indexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]

    // Test addIndexes
    NSMutableIndexSet* addSet = [NSMutableIndexSet new];
    [addSet addIndexesInRange:NSMakeRange(0, 3)]; // [0-2]
    [addSet addIndexesInRange:NSMakeRange(8, 2)]; // [8-9]
    [addSet addIndexesInRange:NSMakeRange(11, 7)]; // [11-17]
    [indexSet addIndexes:addSet];

    // Verify that the set equals the expected result
    expected = @[ @0, @1, @2, @3, @4, @5, @7, @8, @9, @11, @12, @13, @14, @15, @16, @17 ];
    verifyIndexSetEqualsArray(expected, indexSet);
    [indexSet release];
}

TEST(NSIndexSet, removeIndex) {
    NSMutableIndexSet* indexSet = [NSMutableIndexSet new];

    // set up the indexSet with a few non overlapping indices.
    [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [indexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]
    [indexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]

    [indexSet removeIndex:8];

    // Remove an index that doesn't exist
    ASSERT_NO_THROW([indexSet removeIndex:9]);

    verifyIndexSetEqualsArray(@[ @2, @3, @4, @5, @7, @11, @12, @13, @14, @15 ], indexSet);
    [indexSet release];
}

TEST(NSIndexSet, shiftIndexes) {
    NSMutableIndexSet* indexSet = [NSMutableIndexSet new];

    // set up the indexSet with a few non overlapping indices.
    [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [indexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]
    [indexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]

    // Test shiftIndexes
    [indexSet shiftIndexesStartingAtIndex:6 by:1];

    // Verify that the set equals the expected result
    NSArray* expected = @[ @2, @3, @4, @5, @8, @9, @12, @13, @14, @15, @16 ];
    verifyIndexSetEqualsArray(expected, indexSet);

    // Test shiftIndexes with negative delta
    [indexSet shiftIndexesStartingAtIndex:12 by:-3];
    expected = @[ @2, @3, @4, @5, @8, @9, @10, @11, @12, @13 ];
    verifyIndexSetEqualsArray(expected, indexSet);

    [indexSet release];
}
