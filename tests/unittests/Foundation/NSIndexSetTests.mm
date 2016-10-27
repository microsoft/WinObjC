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
    NSMutableIndexSet* expectedIndexSet = [NSMutableIndexSet indexSet];

    [actual enumerateIndexesUsingBlock:^(NSUInteger index, BOOL* stop) {
        ASSERT_OBJCEQ([expected objectAtIndex:callCount++], [NSNumber numberWithUnsignedInt:index]);
        [expectedIndexSet addIndex:index];
    }];

    ASSERT_EQ([expected count], callCount);
    ASSERT_OBJCEQ(expectedIndexSet, actual);
}

TEST(NSIndexSet, AddIndexesInRange) {
    NSMutableIndexSet* indexSet = [NSMutableIndexSet indexSet];
    NSMutableIndexSet* expectedIndexSet = [NSMutableIndexSet indexSet];

    LOG_INFO("Basic addIndexesInRange operation tests of NSIndexSet");

    // set up the indexSet with a few non overlapping indices.
    [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [indexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]
    [indexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]
    // The resulting set should contain ranges - [2-5], [7-8] and [11-15].

    // make sure life is ok.
    NSArray* expected = @[ @2, @3, @4, @5, @7, @8, @11, @12, @13, @14, @15 ];
    verifyIndexSetEqualsArray(expected, indexSet);

    // add in a left overlap.
    LOG_INFO("Left overlap addIndexesInRange operation tests of NSIndexSet");
    [indexSet addIndexesInRange:NSMakeRange(1, 2)]; // [1-2]
    // The resulting set should contain ranges - [1-5], [7-8] and [11-15].
    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(1, 5)]; // [1-5]
    [expectedIndexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]
    [expectedIndexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]
    ASSERT_TRUE([indexSet isEqualToIndexSet:expectedIndexSet]);

    // add in a right overlap.
    LOG_INFO("Right overlap addIndexesInRange operation tests of NSIndexSet");
    [indexSet addIndexesInRange:NSMakeRange(4, 3)]; // [4-6]
    // The resulting set should contain ranges - [1-8] and [11-15].
    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(1, 8)]; // [1-8]
    [expectedIndexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]
    ASSERT_TRUE([indexSet isEqualToIndexSet:expectedIndexSet]);

    // add in a subset
    LOG_INFO("Subset addIndexesInRange operation tests of NSIndexSet");
    [indexSet addIndexesInRange:NSMakeRange(12, 2)]; // [12-13]
    // The resulting set should contain ranges - [1-8] and [11-15].
    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(1, 8)]; // [1-8]
    [expectedIndexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]
    ASSERT_TRUE([indexSet isEqualToIndexSet:expectedIndexSet]);

    // add in a candidate that spans multiple ranges. (super set of [1-8] and left overlap of [11-15])
    LOG_INFO("Superset addIndexesInRange operation tests of NSIndexSet");
    [indexSet addIndexesInRange:NSMakeRange(0, 13)]; // [0-12]
    // The resulting should contain ranges - [0-15].
    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(0, 16)]; // [0-15]
    ASSERT_TRUE([indexSet isEqualToIndexSet:expectedIndexSet]);

    // add in an adjacent candidate.
    LOG_INFO("Adjacent addIndexesInRange operation tests of NSIndexSet");
    [indexSet addIndexesInRange:NSMakeRange(16, 2)]; // [16-17]
    // The resulting should contain ranges - [0-17].
    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(0, 18)]; // [0-17]
    ASSERT_TRUE([indexSet isEqualToIndexSet:expectedIndexSet]);
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
    NSMutableIndexSet* indexSet = [[NSMutableIndexSet new] autorelease];
    NSMutableIndexSet* expectedIndexSet = [[NSMutableIndexSet new] autorelease];

    // Test addIndex
    [indexSet addIndex:2];
    // The resulting set should contain range - [2].

    // Verify that the set contains 2 and no other indices.
    NSArray* expected = @[ @2 ];
    verifyIndexSetEqualsArray(expected, indexSet);
    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(2, 1)]; // [2]
    ASSERT_TRUE([indexSet isEqualToIndexSet:expectedIndexSet]);

    // set up the indexSet with a few non overlapping indices.
    [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [indexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]
    [indexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]
    // The resulting set should contain ranges - [2-5], [7-8] and [11-15].

    // Test addIndexes
    NSMutableIndexSet* addSet = [NSMutableIndexSet new];
    [addSet addIndexesInRange:NSMakeRange(0, 3)]; // [0-2]
    [addSet addIndexesInRange:NSMakeRange(8, 2)]; // [8-9]
    [addSet addIndexesInRange:NSMakeRange(11, 7)]; // [11-17]
    [indexSet addIndexes:addSet];
    // The resulting set should contain ranges - [0-5], [7-9] and [11-17].

    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(0, 6)]; // [0-5]
    [expectedIndexSet addIndexesInRange:NSMakeRange(7, 3)]; // [7-9]
    [expectedIndexSet addIndexesInRange:NSMakeRange(11, 7)]; // [11-17]
    ASSERT_TRUE([indexSet isEqualToIndexSet:expectedIndexSet]);
}

TEST(NSIndexSet, removeIndex) {
    NSMutableIndexSet* indexSet = [[NSMutableIndexSet new] autorelease];
    NSMutableIndexSet* expectedIndexSet = [[NSMutableIndexSet new] autorelease];

    // set up the indexSet with a few non overlapping indices.
    [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [indexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]
    [indexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]
    // The resulting set should contain ranges - [2-5], [7-8] and [11-15].

    // Remove an index that doesn't exist
    ASSERT_NO_THROW([indexSet removeIndex:9]);

    [indexSet removeIndex:8];
    // The resulting set should contain ranges - [2-5], [7] and [11-15].

    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [expectedIndexSet addIndexesInRange:NSMakeRange(7, 1)]; // [7]
    [expectedIndexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]
    ASSERT_TRUE([indexSet isEqualToIndexSet:expectedIndexSet]);
}

// Note: There seems to be a bug in iOS with shiftIndexesStartingAtIndex:
//  [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
//  [indexSet addIndexesInRange:NSMakeRange(8, 2)]; // [8-9]
//  [indexSet addIndexesInRange:NSMakeRange(12, 5)]; // [12-16]
//
//  should result in a set with ranges [2-5], [8-9] and [12-16]
//
//  [indexSet shiftIndexesStartingAtIndex:12 by:-3];
//
//  should then result in a set ranges [2-5] and [8-13] but on iOS it returns [2-5], [8] and [9-13]
//  This cannot be correct as there is no way such a set can be created using any method from NSMutableIndexSet.
//  Also verified this behavior is not consistent. i.e. on iOS with the resulting set above ([2-5], [8] and [9-13]),
//  perform - [indexSet addIndexesInRange:NSMakeRange(17, 2)]; // [17-18]
//
//  the new set will be [2-5], [8], [9-13] and [17,18]
//
//  [indexSet shiftIndexesStartingAtIndex:17 by:-3];
//
//  should have returned a set [2-5], [8], [9-13] and [14,18] as per the previous behavior of this method but the
//  set returned is [2-5], [8] and [9-18]. i.e. adjacent ranges get merged.
//
//  There is no clear explanation on this inconsistent behaviour, hence disabling this test on OSX
//
OSX_DISABLED_TEST(NSIndexSet, shiftIndexes) {
    NSMutableIndexSet* indexSet = [[NSMutableIndexSet new] autorelease];
    NSMutableIndexSet* expectedIndexSet = [[NSMutableIndexSet new] autorelease];

    // set up the indexSet with a few non overlapping indices.
    [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [indexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]
    [indexSet addIndexesInRange:NSMakeRange(11, 5)]; // [11-15]
    // The resulting set should contain ranges - [2-5], [7-8] and [11-15].

    // Test shiftIndexes
    [indexSet shiftIndexesStartingAtIndex:6 by:1];
    // The resulting set should contain ranges - [2-5], [8-9] and [12-16].

    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [expectedIndexSet addIndexesInRange:NSMakeRange(8, 2)]; // [8-9]
    [expectedIndexSet addIndexesInRange:NSMakeRange(12, 5)]; // [12-16]
    ASSERT_OBJCEQ(expectedIndexSet, indexSet);

    // Test shiftIndexes with negative delta
    [indexSet shiftIndexesStartingAtIndex:12 by:-3];
    // The resulting set should contain ranges - [2-5] and [8-13].
    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [expectedIndexSet addIndexesInRange:NSMakeRange(8, 6)]; // [8-13]
    ASSERT_OBJCEQ(expectedIndexSet, indexSet);

    // Test shiftIndexes with adjacent range
    [indexSet addIndexesInRange:NSMakeRange(17, 2)]; // [17-18]
    // The resulting set should contain ranges - [2-5], [8-15] and [17-18].
    [indexSet shiftIndexesStartingAtIndex:17 by:-3];
    // The resulting set should contain ranges - [2-5] and [8-15].
    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [expectedIndexSet addIndexesInRange:NSMakeRange(8, 8)]; // [8-15]
    ASSERT_OBJCEQ(expectedIndexSet, indexSet);

    [indexSet removeAllIndexes];
    [indexSet addIndexesInRange:NSMakeRange(1, 2)];
    // The resulting set should contain range - [1-2].
    [indexSet shiftIndexesStartingAtIndex:2 by:-1];
    // The resulting set should contain range - [1].
    NSArray* expected = @[ @1 ];
    verifyIndexSetEqualsArray(expected, indexSet);
    // verify the ranges in the set.
    [expectedIndexSet removeAllIndexes];
    [expectedIndexSet addIndexesInRange:NSMakeRange(1, 1)]; // [1]
    ASSERT_OBJCEQ(expectedIndexSet, indexSet);
}

TEST(NSIndexSet, IndexLessThanIndex) {
    NSMutableIndexSet* set = [[NSMutableIndexSet alloc] initWithIndexesInRange:NSMakeRange(1, 5)];
    [set addIndexesInRange:NSMakeRange(10, 5)];
    EXPECT_EQ(NSNotFound, [set indexLessThanIndex:1]);
    EXPECT_EQ(1, [set indexLessThanIndex:2]);
    EXPECT_EQ(5, [set indexLessThanIndex:9]);
    EXPECT_EQ(14, [set indexLessThanIndex:525600]);
}

TEST(NSIndexSet, IndexLessThanOrEqualToIndex) {
    NSMutableIndexSet* set = [[NSMutableIndexSet alloc] initWithIndexesInRange:NSMakeRange(1, 5)];
    [set addIndexesInRange:NSMakeRange(10, 5)];
    EXPECT_EQ(NSNotFound, [set indexLessThanOrEqualToIndex:0]);
    EXPECT_EQ(1, [set indexLessThanOrEqualToIndex:1]);
    EXPECT_EQ(5, [set indexLessThanOrEqualToIndex:9]);
    EXPECT_EQ(14, [set indexLessThanOrEqualToIndex:525600]);
}

TEST(NSIndexSet, IndexGreaterThanIndex) {
    NSMutableIndexSet* set = [[NSMutableIndexSet alloc] initWithIndexesInRange:NSMakeRange(1, 5)];
    [set addIndexesInRange:NSMakeRange(10, 5)];
    EXPECT_EQ(1, [set indexGreaterThanIndex:0]);
    EXPECT_EQ(2, [set indexGreaterThanIndex:1]);
    EXPECT_EQ(10, [set indexGreaterThanIndex:9]);
    EXPECT_EQ(NSNotFound, [set indexGreaterThanIndex:15]);
}

TEST(NSIndexSet, IndexGreaterThanOrEqualToIndex) {
    NSMutableIndexSet* set = [[NSMutableIndexSet alloc] initWithIndexesInRange:NSMakeRange(1, 5)];
    [set addIndexesInRange:NSMakeRange(10, 5)];
    EXPECT_EQ(1, [set indexGreaterThanOrEqualToIndex:0]);
    EXPECT_EQ(1, [set indexGreaterThanOrEqualToIndex:1]);
    EXPECT_EQ(10, [set indexGreaterThanOrEqualToIndex:9]);
    EXPECT_EQ(NSNotFound, [set indexGreaterThanOrEqualToIndex:15]);
}

TEST(NSIndexSet, NSCodingEmptySet) {
    NSIndexSet* emptySet = [NSIndexSet new];
    NSMutableData* data = [NSMutableData new];
    NSKeyedArchiver* coder = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    [emptySet encodeWithCoder:coder];
    [coder finishEncoding];
    NSKeyedUnarchiver* decoder = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    NSIndexSet* decodedSet = [[NSIndexSet alloc] initWithCoder:decoder];
    EXPECT_OBJCEQ(emptySet, decodedSet);
}

TEST(NSIndexSet, NSCodingNonemptySet) {
    NSMutableIndexSet* set = [[NSMutableIndexSet alloc] initWithIndexesInRange:NSMakeRange(1, 5)];
    [set addIndexesInRange:NSMakeRange(10, 5)];
    NSMutableData* data = [NSMutableData new];
    NSKeyedArchiver* coder = [[NSKeyedArchiver alloc] initForWritingWithMutableData:data];
    [set encodeWithCoder:coder];
    [coder finishEncoding];

    NSKeyedUnarchiver* decoder = [[NSKeyedUnarchiver alloc] initForReadingWithData:data];
    NSMutableIndexSet* decodedSet = [[NSMutableIndexSet alloc] initWithCoder:decoder];
    EXPECT_OBJCEQ(set, decodedSet);
}