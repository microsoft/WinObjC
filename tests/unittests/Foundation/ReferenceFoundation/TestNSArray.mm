//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#import <Foundation/Foundation.h>
#import <TestFramework.h>

static NSComparisonResult (^compareIntNSNumber)(id, id) = ^NSComparisonResult(id lhs, id rhs) {
    NSInteger lhsInt = ((NSNumber*)lhs).integerValue;
    NSInteger rhsInt = ((NSNumber*)rhs).integerValue;
    if (lhsInt == rhsInt) {
        return NSOrderedSame;
    }
    if (lhsInt < rhsInt) {
        return NSOrderedAscending;
    }

    return NSOrderedDescending;
};

static int objectIndexInArray(NSArray* array, int value, int startingFrom, int length, NSBinarySearchingOptions options = 0) {
    return [array indexOfObject:[NSNumber numberWithInteger:value]
                  inSortedRange:NSMakeRange(startingFrom, length)
                        options:options
                usingComparator:compareIntNSNumber];
}

TEST(NSArray, BasicConstruction) {
    NSArray* array = [NSArray array];
    NSArray* array2 = @[ @"foo", @"bar" ];
    ASSERT_EQ(array.count, 0);
    ASSERT_EQ(array2.count, 2);
}

TEST(NSArray, Enumeration) {
    NSArray* array = @[ @"foo", @"bar", @"baz" ];
    auto e = [array objectEnumerator];
    ASSERT_OBJCEQ((NSString*)([e nextObject]), @"foo");
    ASSERT_OBJCEQ((NSString*)([e nextObject]), @"bar");
    ASSERT_OBJCEQ((NSString*)([e nextObject]), @"baz");
    ASSERT_OBJCEQ([e nextObject], nil);
    ASSERT_OBJCEQ([e nextObject], nil);

    auto r = [array reverseObjectEnumerator];
    ASSERT_OBJCEQ((NSString*)([r nextObject]), @"baz");
    ASSERT_OBJCEQ((NSString*)([r nextObject]), @"bar");
    ASSERT_OBJCEQ((NSString*)([r nextObject]), @"foo");
    ASSERT_OBJCEQ([r nextObject], nil);
    ASSERT_OBJCEQ([r nextObject], nil);

    auto empty = [[NSArray array] objectEnumerator];
    ASSERT_OBJCEQ([empty nextObject], nil);
    ASSERT_OBJCEQ([empty nextObject], nil);

    auto reverseEmpty = [[NSArray array] reverseObjectEnumerator];
    ASSERT_OBJCEQ([reverseEmpty nextObject], nil);
    ASSERT_OBJCEQ([reverseEmpty nextObject], nil);
}

TEST(NSArray, SequenceType) {
    NSArray* array = @[ @"foo", @"bar", @"baz" ];
    NSMutableString* res = [[NSMutableString new] autorelease];

    for (id obj in array) {
        [res appendString:(NSString*)obj];
    }

    ASSERT_OBJCEQ(res, @"foobarbaz");
}

TEST(NSArray, GetObjects) {
    NSArray* array = @[
        @"foo",
        @"bar",
        @"baz",
        @"foo1",
        @"bar2",
        @"baz3",
    ];
    id objects[3];
    [array getObjects:objects range:NSMakeRange(1, 3)];
    auto fetched = @[
        ((NSString*)objects[0]),
        ((NSString*)objects[1]),
        ((NSString*)objects[2]),
    ];

    NSArray* expected = @[ @"bar", @"baz", @"foo1" ];
    ASSERT_OBJCEQ(fetched, expected);
}

TEST(NSArray, ObjectAtIndex) {
    NSArray* array = @[ @"foo", @"bar" ];
    NSString* foo = (NSString*)[array objectAtIndex:0];
    ASSERT_OBJCEQ(foo, @"foo");

    NSString* bar = (NSString*)[array objectAtIndex:1];
    ASSERT_OBJCEQ(bar, @"bar");
}

TEST(NSArray, BinarySearch) {
    NSArray* array = @[
        [NSNumber numberWithInt:0],
        [NSNumber numberWithInt:1],
        [NSNumber numberWithInt:2],
        [NSNumber numberWithInt:2],
        [NSNumber numberWithInt:3],
        [NSNumber numberWithInt:4],
        [NSNumber numberWithInt:4],
        [NSNumber numberWithInt:6],
        [NSNumber numberWithInt:7],
        [NSNumber numberWithInt:7],
        [NSNumber numberWithInt:7],
        [NSNumber numberWithInt:8],
        [NSNumber numberWithInt:9],
        [NSNumber numberWithInt:9]
    ];

    // The below block is intentionally commented out, matching Swift tests

    // Not sure how to test fatal errors.

    //        NSArray throws NSInvalidArgument if range exceeds bounds of the array.
    //        NSRange* rangeOutOfArray = [NSRange rangeWithLocation:5, length: 15]
    //        auto _ = [array indexOfObject:[NSNumber numberWithInteger:9] inSortedRange: rangeOutOfArray options:
    //        @[NSBinarySearchingInsertionIndex,
    //        NSBinarySearchingFirstEqual] usingComparator: compareIntNSNumber]

    //        NSArray throws NSInvalidArgument if both NSBinarySearchingFirstEqual and .LastEqaul are specified
    //        NSBinarySearchingOptions* searchForBoth = NSBinarySearchingFirstEqual | NSBinarySearchingLastEqual
    //        auto _ = objectIndexInArray(array, 9, 0, 13, searchForBoth)

    auto notFound = objectIndexInArray(array, 11, 0, 13);
    ASSERT_EQ_MSG(notFound, NSNotFound, @"NSArray return NSNotFound if object is not found.");

    auto notFoundInRange = objectIndexInArray(array, 7, 0, 5);
    ASSERT_EQ_MSG(notFoundInRange, NSNotFound, @"NSArray return NSNotFound if object is not found.");

    auto indexOfAnySeven = objectIndexInArray(array, 7, 0, 13);
    ASSERT_TRUE_MSG((indexOfAnySeven >= 8) && (indexOfAnySeven <= 10),
                    @"If no options provided NSArray returns an arbitrary matching object's index.");

    auto indexOfFirstNine = objectIndexInArray(array, 9, 7, 6, NSBinarySearchingFirstEqual);
    ASSERT_TRUE_MSG(indexOfFirstNine == 12, @"If NSBinarySearchingFirstEqual is set NSArray returns the lowest index of equal objects.");

    auto indexOfLastTwo = objectIndexInArray(array, 2, 1, 7, NSBinarySearchingLastEqual);
    ASSERT_TRUE_MSG(indexOfLastTwo == 3, @"If NSBinarySearchingLastEqual is set NSArray returns the highest index of equal objects.");

    auto anyIndexToInsertNine = objectIndexInArray(array, 9, 0, 13, NSBinarySearchingInsertionIndex);
    ASSERT_TRUE_MSG(
        (anyIndexToInsertNine >= 12) && (anyIndexToInsertNine <= 14),
        @"If NSBinarySearchingInsertionIndex is specified and no other options provided NSArray returns any equal or one larger "
        @"index than any matching object’s index.");

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
    auto rangeLength = 13;
    auto endOfArray = objectIndexInArray(array, 10, rangeStart, rangeLength, NSBinarySearchingInsertionIndex | NSBinarySearchingLastEqual);
    ASSERT_TRUE_MSG(endOfArray == (rangeStart + rangeLength),
                    @"...or the index at the end of the array if the object is larger than all other elements.");

    NSArray* arrayOfTwo = @[ [NSNumber numberWithInt:0], [NSNumber numberWithInt:2] ];
    auto indexInMiddle = objectIndexInArray(arrayOfTwo, 1, 0, 2, NSBinarySearchingInsertionIndex | NSBinarySearchingFirstEqual);
    ASSERT_EQ_MSG(indexInMiddle, 1, @"If no match found item should be inserted before least greater object");
    auto indexInMiddle2 = objectIndexInArray(arrayOfTwo, 1, 0, 2, NSBinarySearchingInsertionIndex | NSBinarySearchingLastEqual);
    ASSERT_EQ_MSG(indexInMiddle2, 1, @"If no match found item should be inserted before least greater object");
    auto indexInMiddle3 = objectIndexInArray(arrayOfTwo, 1, 0, 2, NSBinarySearchingInsertionIndex);
    ASSERT_EQ_MSG(indexInMiddle3, 1, @"If no match found item should be inserted before least greater object");
}

TEST(NSArray, ArrayReplacement) {
    NSMutableArray* array = [NSMutableArray arrayWithArray:@[
        [NSNumber numberWithInt:0],
        [NSNumber numberWithInt:1],
        [NSNumber numberWithInt:2],
        [NSNumber numberWithInt:3],
        [NSNumber numberWithInt:4],
        [NSNumber numberWithInt:5],
        [NSNumber numberWithInt:7]
    ]];
    [array replaceObjectsInRange:NSMakeRange(0, 2) withObjectsFromArray:@[ [NSNumber numberWithInt:8], [NSNumber numberWithInt:9] ]];
    ASSERT_TRUE(((NSNumber*)array[0]).integerValue == 8);
    ASSERT_TRUE(((NSNumber*)array[1]).integerValue == 9);
    ASSERT_TRUE(((NSNumber*)array[2]).integerValue == 2);
}

TEST(NSArray, ArrayReplaceObjectsInRangeFromRange) {
    NSMutableArray* array = [NSMutableArray arrayWithArray:@[
        [NSNumber numberWithInt:0],
        [NSNumber numberWithInt:1],
        [NSNumber numberWithInt:2],
        [NSNumber numberWithInt:3],
        [NSNumber numberWithInt:4],
        [NSNumber numberWithInt:5],
        [NSNumber numberWithInt:7]
    ]];
    [array replaceObjectsInRange:NSMakeRange(0, 2)
            withObjectsFromArray:@[ [NSNumber numberWithInt:8], [NSNumber numberWithInt:9], [NSNumber numberWithInt:10] ]
                           range:NSMakeRange(1, 2)];
    ASSERT_TRUE(((NSNumber*)array[0]).integerValue == 9);
    ASSERT_TRUE(((NSNumber*)array[1]).integerValue == 10);
    ASSERT_TRUE(((NSNumber*)array[2]).integerValue == 2);
}

TEST(NSArray, ReplaceObjectAtIndex) {
    NSMutableArray* array = [NSMutableArray arrayWithArray:@[
        [NSNumber numberWithInt:0],
        [NSNumber numberWithInt:1],
        [NSNumber numberWithInt:2],
        [NSNumber numberWithInt:3],
        [NSNumber numberWithInt:4],
        [NSNumber numberWithInt:5],
        [NSNumber numberWithInt:7]
    ]];

    // 1. Check replacement in the middle of the array
    [array replaceObjectAtIndex:3 withObject:[NSNumber numberWithInt:8]];
    ASSERT_EQ(array.count, 7);
    ASSERT_EQ(((NSNumber*)array[3]).integerValue, 8);

    // 2. Check replacement of the first element
    [array replaceObjectAtIndex:0 withObject:[NSNumber numberWithInt:7]];
    ASSERT_EQ(array.count, 7);
    ASSERT_EQ(((NSNumber*)array[0]).integerValue, 7);

    // 3. Check replacement of the last element
    [array replaceObjectAtIndex:6 withObject:[NSNumber numberWithInt:6]];
    ASSERT_EQ(array.count, 7);
    ASSERT_EQ(((NSNumber*)array[6]).integerValue, 6);
}

TEST(NSArray, RemoveObjectsInArray) {
    NSMutableArray* array = [NSMutableArray arrayWithArray:@[
        [NSNumber numberWithInt:0],
        [NSNumber numberWithInt:1],
        [NSNumber numberWithInt:2],
        [NSNumber numberWithInt:3],
        [NSNumber numberWithInt:4],
        [NSNumber numberWithInt:5],
        [NSNumber numberWithInt:7]
    ]];
    NSArray* objectsToRemove =
        @[ [NSNumber numberWithInt:1], [NSNumber numberWithInt:22], [NSNumber numberWithInt:7], [NSNumber numberWithInt:5] ];
    [array removeObjectsInArray:objectsToRemove];
    ASSERT_EQ(array.count, 4);
    ASSERT_EQ(((NSNumber*)array[0]).integerValue, 0);
    ASSERT_EQ(((NSNumber*)array[1]).integerValue, 2);
    ASSERT_EQ(((NSNumber*)array[2]).integerValue, 3);
    ASSERT_EQ(((NSNumber*)array[3]).integerValue, 4);
}

TEST(NSArray, BinarySearchFringeCases) {
    NSArray* array = @[
        [NSNumber numberWithInt:0],
        [NSNumber numberWithInt:1],
        [NSNumber numberWithInt:2],
        [NSNumber numberWithInt:2],
        [NSNumber numberWithInt:3],
        [NSNumber numberWithInt:4],
        [NSNumber numberWithInt:4],
        [NSNumber numberWithInt:6],
        [NSNumber numberWithInt:7],
        [NSNumber numberWithInt:7],
        [NSNumber numberWithInt:7],
        [NSNumber numberWithInt:8],
        [NSNumber numberWithInt:9],
        [NSNumber numberWithInt:9]
    ];

    NSArray* emptyArray = [NSArray array];
    //        Same as for non empty NSArray but error message ends with 'bounds for empty array'.
    //        auto _ = objectIndexInArray(emptyArray, 0, 0, 1)

    auto notFoundInEmptyArray = objectIndexInArray(emptyArray, 9, 0, 0);
    ASSERT_EQ_MSG(notFoundInEmptyArray, NSNotFound, @"Empty NSArray return NSNotFound for any valid arguments.");

    auto startIndex = objectIndexInArray(emptyArray, 7, 0, 0, NSBinarySearchingInsertionIndex);
    ASSERT_TRUE_MSG(startIndex == 0, @"For Empty NSArray any objects should be inserted at start.");

    auto rangeStart = 0;
    auto rangeLength = 13;

    auto leastSearch = objectIndexInArray(array, -1, rangeStart, rangeLength);
    ASSERT_TRUE_MSG(leastSearch == NSNotFound,
                    @"If object is less than least object in the range then there is no change it could be found.");

    auto greatestSearch = objectIndexInArray(array, 15, rangeStart, rangeLength);
    ASSERT_TRUE_MSG(greatestSearch == NSNotFound,
                    @"If object is greater than greatest object in the range then there is no change it could be found.");

    auto leastInsert = objectIndexInArray(array, -1, rangeStart, rangeLength, NSBinarySearchingInsertionIndex);
    ASSERT_TRUE_MSG(leastInsert == rangeStart,
                    @"If object is less than least object in the range it should be inserted at range' location.");

    auto greatestInsert = objectIndexInArray(array, 15, rangeStart, rangeLength, NSBinarySearchingInsertionIndex);
    ASSERT_TRUE_MSG(greatestInsert == (rangeStart + rangeLength),
                    @"If object is greater than greatest object in the range it should be inserted at range' end.");
}

TEST(NSArray, ReplaceObjectsInRange_withObjectsFromArray) {
    NSMutableArray* array1 = [NSMutableArray arrayWithArray:@[ @"foo1", @"bar1", @"baz1" ]];

    NSArray* array2 = @[ @"foo2", @"bar2", @"baz2" ];

    [array1 replaceObjectsInRange:NSMakeRange(0, 2) withObjectsFromArray:array2];

    ASSERT_OBJCEQ_MSG(([array1[0] isKindOfClass:[NSString class]] ? (NSString*)array1[0] : nil),
                      @"foo2",
                      @"Expected foo2 but was \(array1[0])");
    ASSERT_OBJCEQ_MSG(([array1[1] isKindOfClass:[NSString class]] ? (NSString*)array1[1] : nil),
                      @"bar2",
                      @"Expected bar2 but was \(array1[1])");
    ASSERT_OBJCEQ_MSG(([array1[2] isKindOfClass:[NSString class]] ? (NSString*)array1[2] : nil),
                      @"baz2",
                      @"Expected baz2 but was \(array1[2])");
    ASSERT_OBJCEQ_MSG(([array1[3] isKindOfClass:[NSString class]] ? (NSString*)array1[3] : nil),
                      @"baz1",
                      @"Expected baz1 but was \(array1[3])");
}

TEST(NSArray, ReplaceObjectsInRange_withObjectsFromArray_range) {
    NSMutableArray* array1 = [NSMutableArray arrayWithArray:@[ @"foo1", @"bar1", @"baz1" ]];

    NSArray* array2 = @[ @"foo2", @"bar2", @"baz2" ];

    [array1 replaceObjectsInRange:NSMakeRange(1, 1) withObjectsFromArray:array2 range:NSMakeRange(1, 2)];

    ASSERT_OBJCEQ_MSG(([array1[0] isKindOfClass:[NSString class]] ? (NSString*)array1[0] : nil),
                      @"foo1",
                      @"Expected foo1 but was \(array1[0])");
    ASSERT_OBJCEQ_MSG(([array1[1] isKindOfClass:[NSString class]] ? (NSString*)array1[1] : nil),
                      @"bar2",
                      @"Expected bar2 but was \(array1[1])");
    ASSERT_OBJCEQ_MSG(([array1[2] isKindOfClass:[NSString class]] ? (NSString*)array1[2] : nil),
                      @"baz2",
                      @"Expected baz2 but was \(array1[2])");
    ASSERT_OBJCEQ_MSG(([array1[3] isKindOfClass:[NSString class]] ? (NSString*)array1[3] : nil),
                      @"baz1",
                      @"Expected baz1 but was \(array1[3])");
}

TEST(NSArray, SortedArrayUsingComparator) {
    // sort with localized caseInsensitive compare
    auto input = @[ @"this", @"is", @"a", @"test", @"of", @"sort", @"with", @"strings" ];
    auto expectedResult = @[ @"a", @"is", @"of", @"sort", @"strings", @"test", @"this", @"with" ];
    auto result = [input sortedArrayUsingComparator:^NSComparisonResult(id left, id right) {
        NSString* l = (NSString*)left;
        NSString* r = (NSString*)right;
        return [l localizedCaseInsensitiveCompare:r];
    }];
    ASSERT_OBJCEQ(result, expectedResult);

    // sort empty array
    auto emptyArray = [[NSArray array] sortedArrayUsingComparator:^NSComparisonResult(id left, id right) {
        return NSOrderedSame;
    }];
    ASSERT_EQ(emptyArray.count, 0);

    // sort numbers
    auto inputNumbers = @[ @0, @10, @25, @100, @21, @22 ];
    auto expectedNumbers = @[ @0, @10, @21, @22, @25, @100 ];
    auto resultNumbers = [inputNumbers sortedArrayUsingComparator:^NSComparisonResult(id left, id right) {
        NSInteger l = ((NSNumber*)left).integerValue;
        NSInteger r = ((NSNumber*)right).integerValue;
        return l < r ? NSOrderedAscending : (l > r ? NSOrderedDescending : NSOrderedSame);
    }];
    ASSERT_OBJCEQ(resultNumbers, expectedNumbers);
}

TEST(NSArray, SortedArrayWithOptionsUsingComparator) {
    // check that sortedArrayWithOptions:comparator: works in the way sortedArrayUsingComparator does
    auto input = @[ @"this", @"is", @"a", @"test", @"of", @"sort", @"with", @"strings" ];
    auto comparator = ^NSComparisonResult(id left, id right) {
        NSString* l = (NSString*)left;
        NSString* r = (NSString*)right;
        return [l localizedCaseInsensitiveCompare:r];
    };

    auto result1 = [input sortedArrayUsingComparator:comparator];
    auto result2 = [input sortedArrayWithOptions:0 usingComparator:comparator];

    ASSERT_TRUE([result1 isEqualToArray:result2]);

    // sort empty array
    auto emptyArray = [[NSArray array] sortedArrayWithOptions:0 usingComparator:comparator];
    ASSERT_EQ(emptyArray.count, 0);
}

static NSInteger sortUsingFunction_compare(id left, id right, void* context) {
    NSInteger l = ((NSNumber*)left).integerValue;
    NSInteger r = ((NSNumber*)right).integerValue;
    return l < r ? NSOrderedAscending : (l > r ? NSOrderedDescending : NSOrderedSame);
}

TEST(NSArray, SortUsingFunction) {
    auto inputNumbers = @[ @11, @120, @215, @11, @1, @-22, @35, @-89, @65 ];
    NSMutableArray* mutableInput = (NSMutableArray*)[inputNumbers mutableCopy];
    auto expectedNumbers = @[ @-89, @-22, @1, @11, @11, @35, @65, @120, @215 ];

    [mutableInput sortUsingFunction:sortUsingFunction_compare context:nil];
    ASSERT_OBJCEQ(mutableInput, expectedNumbers);
}

TEST(NSArray, SortUsingComparator) {
    // check behaviour with Array's sort method
    auto inputNumbers = @[ @11, @120, @215, @11, @1, @-22, @35, @-89, @65 ];
    NSMutableArray* mutableInput = (NSMutableArray*)[inputNumbers mutableCopy];
    auto expectedNumbers = @[ @-89, @-22, @1, @11, @11, @35, @65, @120, @215 ];

    [mutableInput sortUsingComparator:^NSComparisonResult(id left, id right) {
        NSInteger l = ((NSNumber*)left).integerValue;
        NSInteger r = ((NSNumber*)right).integerValue;
        return l < r ? NSOrderedAscending : (l > r ? NSOrderedDescending : NSOrderedSame);
    }];

    ASSERT_OBJCEQ(mutableInput, expectedNumbers);

    // check that it works in the way [self sortWithOptions:[] usingComparator: cmptr] does
    auto inputStrings = @[ @"this", @"is", @"a", @"test", @"of", @"sort", @"with", @"strings" ];
    NSMutableArray* mutableStringsInput1 = (NSMutableArray*)[inputStrings mutableCopy];
    NSMutableArray* mutableStringsInput2 = (NSMutableArray*)[inputStrings mutableCopy];
    auto comparator = ^NSComparisonResult(id left, id right) {
        NSString* l = (NSString*)left;
        NSString* r = (NSString*)right;
        return [l localizedCaseInsensitiveCompare:r];
    };
    [mutableStringsInput1 sortUsingComparator:comparator];
    [mutableStringsInput2 sortWithOptions:0 usingComparator:comparator];
    ASSERT_TRUE([mutableStringsInput1 isEqualToArray:mutableStringsInput2]);
}

TEST(NSArray, Equality) {
    auto array1 = @[ @"this", @"is", @"a", @"test", @"of", @"equal", @"with", @"strings" ];
    auto array2 = @[ @"this", @"is", @"a", @"test", @"of", @"equal", @"with", @"strings" ];
    auto array3 = @[ @"this", @"is", @"a", @"test", @"of", @"equal", @"with", @"objects" ];

    ASSERT_TRUE([array1 isEqual:array2]);
    ASSERT_TRUE([array1 isEqualToArray:array2]);
    // if 2 arrays are equal, hashes should be equal as well. But not vise versa
    ASSERT_EQ(array1.hash, array2.hash);

    ASSERT_FALSE([array1 isEqual:array3]);
    ASSERT_FALSE([array1 isEqualToArray:array3]);

    ASSERT_FALSE([array1 isEqual:nil]);
    ASSERT_FALSE([array1 isEqual:[[NSObject new] autorelease]]);
}

TEST(NSArray, Copying) {
    auto array = @[ @"this", @"is", @"a", @"test", @"of", @"copy", @"with", @"strings" ];

    NSArray* arrayCopy1 = (NSArray*)[array copy];
    ASSERT_EQ(array, arrayCopy1);

    NSMutableArray* arrayMutableCopy = (NSMutableArray*)[array mutableCopy];
    NSArray* arrayCopy2 = (NSArray*)[arrayMutableCopy copy];
    ASSERT_TRUE([arrayCopy2 isKindOfClass:[NSArray class]]);
    ASSERT_NE(arrayMutableCopy, arrayCopy2);
    for (id entry in arrayCopy2) {
        ASSERT_TRUE([array indexOfObjectIdenticalTo:entry] != NSNotFound);
    }
}

TEST(NSArray, MutableCopying) {
    auto array = @[ @"this", @"is", @"a", @"test", @"of", @"mutableCopy", @"with", @"strings" ];

    NSMutableArray* arrayMutableCopy1 = (NSMutableArray*)[array mutableCopy];
    ASSERT_TRUE([arrayMutableCopy1 isKindOfClass:[NSMutableArray class]]);
    ASSERT_NE(array, arrayMutableCopy1);
    for (id entry in arrayMutableCopy1) {
        ASSERT_TRUE([array indexOfObjectIdenticalTo:entry] != NSNotFound);
    }

    ASSERT_NO_THROW([arrayMutableCopy1 addObject:@"testStringPleaseIgnore"]);

    NSMutableArray* arrayMutableCopy2 = (NSMutableArray*)[arrayMutableCopy1 mutableCopy];
    ASSERT_TRUE([arrayMutableCopy2 isKindOfClass:[NSMutableArray class]]);
    ASSERT_NE(arrayMutableCopy2, arrayMutableCopy1);
    for (id entry in arrayMutableCopy2) {
        ASSERT_TRUE([arrayMutableCopy1 indexOfObjectIdenticalTo:entry] != NSNotFound);
    }
}
