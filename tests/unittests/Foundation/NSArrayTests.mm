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
#include <Foundation/Foundation.h>

void assertArrayContents(NSArray* array, NSObject* first, ...) {
    va_list args;
    va_start(args, first);

    id curVal = first;

    size_t i = 0;
    while (curVal != nil) {
        ASSERT_OBJCEQ(curVal, [array objectAtIndex:i++]);
        curVal = va_arg(args, id);
    }

    va_end(args);

    ASSERT_EQ(i, [array count]);
}

TEST(NSArray, ArrayWithObjects) {
    // Empty list
    assertArrayContents([NSArray arrayWithObjects:nil], nil);

    // Single element
    assertArrayContents([NSArray arrayWithObjects:@1, nil], @1, nil);

    // Multiple elements
    assertArrayContents([NSArray arrayWithObjects:@1, @2, @3, nil], @1, @2, @3, nil);
}

TEST(NSArray, InitWithObjects) {
    // Empty list
    assertArrayContents([[NSArray alloc] initWithObjects:nil], nil);

    // Single element
    assertArrayContents([[NSArray alloc] initWithObjects:@1, nil], @1, nil);

    // Multiple elements
    assertArrayContents([[NSArray alloc] initWithObjects:@1, @2, @3, nil], @1, @2, @3, nil);
}

@interface NSTestArray : NSArray
@end

@implementation NSTestArray
- (NSUInteger)count {
    return 5;
}

- (id)objectAtIndex:(NSUInteger)index {
    return @2;
}
@end

TEST(NSArray, Subclassable) {
    NSArray* testArray = [NSTestArray new];
    ASSERT_EQ(@2, testArray[0]);
    int sum = 0;
    for (id val in testArray) {
        sum += [(NSNumber*)val integerValue];
    }
    ASSERT_EQ(10, sum);

    NSArray* testArray2 = @[ @2, @2, @2, @2, @2 ];

    ASSERT_OBJCEQ(testArray, testArray2);
}

NS_OPTIONS(NSUInteger, NSMutableTestArrayCalls){ countCalled,     objectAtIndexCalled,       insertObjectCalled,
                                                 addObjectCalled, removeObjectAtIndexCalled, replaceObjectAtIndexCalled };

@interface NSMutableTestArray : NSMutableArray
@property unsigned int calledMethods;
@end

@implementation NSMutableTestArray
- (NSUInteger)count {
    _calledMethods |= countCalled;
    return 5;
}

- (id)objectAtIndex:(NSUInteger)index {
    _calledMethods |= objectAtIndexCalled;
    return @2;
}

- (void)insertObject:(id)object atIndex:(NSUInteger)index {
    _calledMethods |= insertObjectCalled;
}

- (void)addObject:(id)anObject {
    _calledMethods |= addObjectCalled;
}

- (void)removeLastObject {
    // No test/flags for removeLastObject because it isn't called from any CF methods.
}

- (void)removeObjectAtIndex:(NSUInteger)index {
    _calledMethods |= removeObjectAtIndexCalled;
}
- (void)replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject {
    _calledMethods |= replaceObjectAtIndexCalled;
}

- (void)verifyAndResetFlags:(unsigned int)expectedCalls {
    ASSERT_EQ(expectedCalls & countCalled, _calledMethods & countCalled);
    ASSERT_EQ(expectedCalls & objectAtIndexCalled, _calledMethods & objectAtIndexCalled);
    ASSERT_EQ(expectedCalls & insertObjectCalled, _calledMethods & insertObjectCalled);
    ASSERT_EQ(expectedCalls & addObjectCalled, _calledMethods & addObjectCalled);
    ASSERT_EQ(expectedCalls & removeObjectAtIndexCalled, _calledMethods & removeObjectAtIndexCalled);
    ASSERT_EQ(expectedCalls & replaceObjectAtIndexCalled, _calledMethods & replaceObjectAtIndexCalled);
    _calledMethods = 0;
}
@end

TEST(NSArray, NSMutableArray_Subclassable) {
    NSMutableTestArray* testArray = [NSMutableTestArray new];
    CFMutableArrayRef test = (CFMutableArrayRef)testArray;

    CFArrayGetCount(test);
    [testArray verifyAndResetFlags:countCalled];

    CFArrayGetValueAtIndex(test, 2);
    [testArray verifyAndResetFlags:objectAtIndexCalled];

    CFArrayInsertValueAtIndex(test, 2, @2);
    [testArray verifyAndResetFlags:insertObjectCalled];

    CFArrayAppendValue(test, @2);
    [testArray verifyAndResetFlags:addObjectCalled];

    CFArrayRemoveValueAtIndex(test, 5);
    [testArray verifyAndResetFlags:removeObjectAtIndexCalled];

    CFArraySetValueAtIndex(test, 4, @3);
    [testArray verifyAndResetFlags:replaceObjectAtIndexCalled];
}

TEST(NSArray, NSArray_initWithContentsOfFile) {
    NSArray* expectedArray = @[ @1, @2, @3, @4, @5 ];

    NSArray* cachesPaths = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSAllDomainsMask, YES);
    ASSERT_NE(0, [cachesPaths count]);
    NSString* path = cachesPaths[0];
    NSString* file = [path stringByAppendingPathComponent:@"array.data"];
    [[NSFileManager defaultManager] createDirectoryAtPath:path withIntermediateDirectories:YES attributes:nil error:nil];
    [expectedArray writeToFile:file atomically:NO];
    NSArray* actualArray = [[NSArray alloc] initWithContentsOfFile:file];
    ASSERT_OBJCEQ(expectedArray, actualArray);
    [[NSFileManager defaultManager] removeItemAtPath:file error:nil];
}

TEST(NSArray, Enumerate) {
    __block NSArray* testArray = @[ @0, @1, @2, @3 ];

    [testArray enumerateObjectsWithOptions:0
                                usingBlock:^(id object, NSUInteger index, BOOL* stop) {
                                    ASSERT_EQ((unsigned)[(NSNumber*)[testArray objectAtIndex:index] integerValue], (unsigned)index);
                                }];

    __block unsigned expectedIndex = 3;
    // Verify that the NSReverseEnumeration option iterates in reverse
    [testArray enumerateObjectsWithOptions:NSEnumerationReverse
                                usingBlock:^(id object, NSUInteger index, BOOL* stop) {
                                    ASSERT_EQ(expectedIndex, index);
                                    ASSERT_EQ((unsigned)[(NSNumber*)[testArray objectAtIndex:index] integerValue], (unsigned)index);
                                    expectedIndex--;
                                }];

    // Verify that the NSEnumerationConcurrent option executes the blocks concurrently
    __block NSCondition* condition = [NSCondition new];
    __block unsigned waitingCount = 0;
    [testArray enumerateObjectsWithOptions:NSEnumerationConcurrent
                                usingBlock:^(id object, NSUInteger index, BOOL* stop) {
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

TEST(NSArray, RemoveObjectsAtIndexes) {
    NSMutableIndexSet* indexSet = [[NSMutableIndexSet new] autorelease];
    [indexSet addIndexesInRange:NSMakeRange(2, 4)]; // [2-5]
    [indexSet addIndexesInRange:NSMakeRange(7, 2)]; // [7-8]

    NSMutableArray* testArray = [[NSMutableArray new] autorelease];
    for (NSUInteger i = 0; i < 10; i++) {
        [testArray addObject:@(i)];
    }

    [testArray removeObjectsAtIndexes:indexSet];

    NSArray* expectedArray = @[ @0, @1, @6, @9 ];

    ASSERT_OBJCEQ(testArray, expectedArray);
}

TEST(NSArray, Description) {
    NSArray* testArray = @[ @1, @2, @3 ];
    ASSERT_OBJCEQ(@"(1, 2, 3)", [testArray description]);

    NSArray* testArray2 = [[NSArray new] autorelease];
    ASSERT_OBJCEQ(@"()", [testArray2 description]);

    NSArray* testArray3 = @[ @1 ];
    ASSERT_OBJCEQ(@"(1)", [testArray3 description]);
}

TEST(NSArray, Autorelease) {
    NSArray* array;
    NSObject* object = [NSObject new];
    ASSERT_EQ(1, [object retainCount]);
    {
        NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
        array = [NSArray arrayWithObject:object];
        [pool release];
    }

    ASSERT_EQ(1, [object retainCount]);
}

TEST(NSArray, ExpandBeyondCapacity) {
    NSMutableArray* array = [NSMutableArray arrayWithCapacity:1];

    NSUInteger expectedCount = 10;
    for (NSUInteger i = 0; i < expectedCount; i++) {
        [array addObject:[NSNumber numberWithInt:i]];
    }

    ASSERT_EQ(expectedCount, [array count]);
}

TEST(NSArray, AddingObjects) {
    assertArrayContents([@[ @1, @2 ] arrayByAddingObjectsFromArray:@[ @3, @4 ]], @1, @2, @3, @4, nil);
}

static int objectIndexInArray(NSArray* array, int value, int startingFrom, int length, NSBinarySearchingOptions options = 0) {
    return [array indexOfObject:[NSNumber numberWithInteger:value]
                  inSortedRange:NSMakeRange(startingFrom, length)
                        options:options
                usingComparator:^(NSNumber* a, NSNumber* b) {
                    return [a compare:b];
                }];
}

TEST(NSArray, BinarySearchInsertionIndex) {
    NSArray* array = @[ @0, @1, @2, @2, @3, @4, @4, @6, @7, @7, @7, @8, @9, @9 ];

    ASSERT_TRUE_MSG(objectIndexInArray(array, 11, 0, array.count, 0) == NSNotFound, @"NSArray return NSNotFound if object is not found.");

    ASSERT_TRUE_MSG(objectIndexInArray(array, 11, 0, array.count, NSBinarySearchingFirstEqual) == NSNotFound,
                    @"NSArray return NSNotFound if object is not found.");

    ASSERT_TRUE_MSG(objectIndexInArray(array, 11, 0, array.count, NSBinarySearchingLastEqual) == NSNotFound,
                    @"NSArray return NSNotFound if object is not found.");

    auto notFoundInRange = objectIndexInArray(array, 7, 0, 5);
    ASSERT_TRUE_MSG(notFoundInRange == NSNotFound, @"NSArray return NSNotFound if object is not found.");

    auto indexOfAnySeven = objectIndexInArray(array, 7, 0, array.count);
    ASSERT_TRUE_MSG((indexOfAnySeven >= 8) && (indexOfAnySeven <= 10),
                    @"If no options provided NSArray returns an arbitrary matching object's index.");

    auto indexOfFirstNine = objectIndexInArray(array, 9, 7, array.count - 7, NSBinarySearchingFirstEqual);
    ASSERT_TRUE_MSG(indexOfFirstNine == 12, @"If NSBinarySearchingFirstEqual is set NSArray returns the lowest index of equal objects.");

    auto indexOfLastTwo = objectIndexInArray(array, 2, 1, 7, NSBinarySearchingLastEqual);
    ASSERT_TRUE_MSG(indexOfLastTwo == 3, @"If NSBinarySearchingLastEqual is set NSArray returns the highest index of equal objects.");

    auto anyIndexToInsertNine = objectIndexInArray(array, 9, 0, array.count, NSBinarySearchingInsertionIndex);
    ASSERT_TRUE_MSG(
        (anyIndexToInsertNine >= 12) && (anyIndexToInsertNine <= 14),
        @"If NSBinarySearchingInsertionIndex is specified and no other options provided NSArray returns any equal or one larger "
        @"index than any matching object’s index.");

    auto anyIndexToInsertNineteen = objectIndexInArray(array, 19, 0, array.count, NSBinarySearchingInsertionIndex);
    ASSERT_TRUE_MSG(
        anyIndexToInsertNineteen == array.count,
        @"If NSBinarySearchingInsertionIndex is specified and the value is greater than any objects of the array, the returned insertion "
        @"index is at the end of the array.");

    auto lowestIndexToInsertTwo = objectIndexInArray(array, 2, 0, 5, NSBinarySearchingInsertionIndex | NSBinarySearchingFirstEqual);
    ASSERT_TRUE_MSG(lowestIndexToInsertTwo == 2,
                    @"If both NSBinarySearchingInsertionIndex and NSBinarySearchingFirstEqual are specified "
                    @"NSArray returns the lowest index of equal objects.");

    auto highestIndexToInsertNine = objectIndexInArray(array, 9, 7, 6, NSBinarySearchingInsertionIndex | NSBinarySearchingLastEqual);
    ASSERT_TRUE_MSG(highestIndexToInsertNine == 13,
                    @"If both NSBinarySearchingInsertionIndex and NSBinarySearchingLastEqual are specified "
                    @"NSArray returns the index of the least greater object...");

    auto indexOfLeastGreaterObjectThanFive =
        objectIndexInArray(array, 5, 0, 10, NSBinarySearchingInsertionIndex | NSBinarySearchingLastEqual);
    ASSERT_TRUE_MSG(indexOfLeastGreaterObjectThanFive == 7,
                    @"If both NSBinarySearchingInsertionIndex and NSBinarySearchingLastEqual are "
                    @"specified NSArray returns the index of the least greater object...");

    auto rangeStart = 0;
    auto rangeLength = array.count;
    auto endOfArray = objectIndexInArray(array, 10, rangeStart, rangeLength, NSBinarySearchingInsertionIndex | NSBinarySearchingLastEqual);
    ASSERT_TRUE_MSG(endOfArray == (rangeStart + rangeLength),
                    @"...or the index at the end of the array if the object is larger than all other elements.");

    NSArray* arrayOfTwo = @[ @0, @2 ];
    auto indexInMiddle = objectIndexInArray(arrayOfTwo, 1, 0, 2, NSBinarySearchingInsertionIndex | NSBinarySearchingFirstEqual);
    ASSERT_EQ_MSG(indexInMiddle, 1, @"If no match found item should be inserted before least greater object");
    auto indexInMiddle2 = objectIndexInArray(arrayOfTwo, 1, 0, 2, NSBinarySearchingInsertionIndex | NSBinarySearchingLastEqual);
    ASSERT_EQ_MSG(indexInMiddle2, 1, @"If no match found item should be inserted before least greater object");
    auto indexInMiddle3 = objectIndexInArray(arrayOfTwo, 1, 0, 2, NSBinarySearchingInsertionIndex);
    ASSERT_EQ_MSG(indexInMiddle3, 1, @"If no match found item should be inserted before least greater object");
}

TEST(NSArray, MutateDuringEnumeration) {
    __block NSMutableArray* array = [NSMutableArray arrayWithObjects:@"A", @"B", @"C", nil];
    void (^enumerate)() = ^{
        for (id object in array) {
            [array addObject:@"<sound effects reminiscent of explosions>"];
        }
    };

    ASSERT_ANY_THROW(enumerate());
}

TEST(NSArray, SortedArrayWithOptions) {
    NSArray* unsortedArray = @[@3, @11, @2, @12, @1, @13];

    NSArray* expectedSortedArray = @[@1, @2, @3, @11, @12, @13];
    NSArray* actualSortedArray = [unsortedArray sortedArrayWithOptions:0 usingComparator:^NSComparisonResult(id obj1, id obj2) {
        int val1 = [obj1 intValue];
        int val2 = [obj2 intValue];

        if (val1 == val2) {
            return NSOrderedSame;
        }

        return (val1 > val2) ? NSOrderedDescending : NSOrderedAscending;
    }];

    ASSERT_OBJCEQ(expectedSortedArray, actualSortedArray);

    // For our stable sort test, we compare using a comparator that treats 1, 2, and 3 as equal and 11, 12, and 13 as equal. Therefore
    // 3, 2, and 1 should be in original order.
    NSArray* expectedStableSort = @[@3, @2, @1, @11, @12, @13];
    NSArray* actualStableSort = [unsortedArray sortedArrayWithOptions:NSSortStable usingComparator:^NSComparisonResult(id obj1, id obj2) {
        int val1 = [obj1 intValue];
        int val2 = [obj2 intValue];

        if (val1 < 10 && val2 < 10) {
            return NSOrderedSame;
        }

        if (val1 > 10 && val2 > 10) {
            return NSOrderedSame;
        }

        return (val1 > val2) ? NSOrderedDescending : NSOrderedAscending;
    }];

    ASSERT_OBJCEQ(expectedStableSort, actualStableSort);
}
