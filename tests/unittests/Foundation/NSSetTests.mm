//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#include <Foundation/Foundation.h>
#include <TestFramework.h>

TEST(NSSet, ExpandBeyondCapacity) {
    NSMutableSet* set = [NSMutableSet setWithCapacity:1];

    NSUInteger expectedCount = 10;
    for (NSUInteger i = 0; i < expectedCount; i++) {
        [set addObject:[NSNumber numberWithInt:i]];
    }

    ASSERT_EQ(expectedCount, [set count]);
}

TEST(NSSet, ContainsObject) {
    NSSet* set = [NSSet setWithObjects:@1, @2, @3, nil];
    ASSERT_NE(nil, set);
    ASSERT_FALSE([set containsObject:nil]);
}

TEST(NSSet, SetValueForKey) {
    NSMutableDictionary* dict1 = [[@{} mutableCopy] autorelease];
    NSMutableDictionary* dict2 = [[@{ @"a" : @"1" } mutableCopy] autorelease];
    NSMutableDictionary* dict3 = [[@{ @"b" : @"2" } mutableCopy] autorelease];
    NSSet* set = [NSSet setWithObjects:dict1, dict2, dict3, nil];
    id key = @"key";
    id expected = @"expectedValue";
    [set setValue:expected forKey:key];
    ASSERT_OBJCEQ(expected, [dict1 objectForKey:key]);
    ASSERT_OBJCEQ(expected, [dict2 objectForKey:key]);
    ASSERT_OBJCEQ(expected, [dict3 objectForKey:key]);
}

TEST(NSSet, ObjectsPassingTest) {
    NSSet* set = [NSSet setWithObjects:@1, @2, @3, @4, @5, @6, nil];
    NSSet* expectedEvensLessThanFive = [NSSet setWithObjects:@2, @4, nil];
    NSSet* actual = [set objectsPassingTest:^(id obj, BOOL* stop) {
        if ([obj intValue] < 5) {
            if ([obj intValue] % 2 == 0) {
                return YES;
            }
        }
        return NO;
    }];

    ASSERT_OBJCEQ(expectedEvensLessThanFive, actual);
}

TEST(NSSet, FilterUsingPredicateString) {
    NSSet* americanMakes = [NSSet setWithObjects:@"Chrysler", @"Ford", @"General Motors", nil];
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"SELF BEGINSWITH[c] %@", @"G"];

    NSSet* filteredSet = [americanMakes filteredSetUsingPredicate:predicate];

    ASSERT_NE(nil, filteredSet);
    ASSERT_EQ(1, [filteredSet count]);
    ASSERT_OBJCEQ(@"General Motors", [filteredSet anyObject]);
}

TEST(NSSet, FilterUsingPredicateNumbers) {
    NSSet* numbers = [NSSet setWithObjects:@2, @4, @8, @16, @32, nil];
    NSSet* expected = [NSSet setWithObjects:@4, @8, @16, nil];
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"(SELF >= 4) AND (SELF < 32)"];

    NSSet* filteredSet = [numbers filteredSetUsingPredicate:predicate];

    ASSERT_NE(nil, filteredSet);
    ASSERT_EQ(3, [filteredSet count]);
    ASSERT_OBJCEQ(expected, filteredSet);
}

TEST(NSSet, FilterUsingPredicateNumbersAlwaysFalse) {
    NSSet* numbers = [NSSet setWithObjects:@2, @4, @8, @16, @32, nil];
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"SELF <= 0"];

    NSSet* filteredSet = [numbers filteredSetUsingPredicate:predicate];

    ASSERT_NE(nil, filteredSet);
    ASSERT_EQ(0, [filteredSet count]);
}

TEST(NSSet, FilterUsingPredicateNumbersAlwaysTrue) {
    NSSet* numbers = [NSSet setWithObjects:@2, @4, @8, @16, @32, nil];
    NSPredicate* predicate = [NSPredicate predicateWithFormat:@"SELF >= 0"];

    NSSet* filteredSet = [numbers filteredSetUsingPredicate:predicate];

    ASSERT_NE(nil, filteredSet);
    ASSERT_EQ([numbers count], [filteredSet count]);
    ASSERT_OBJCEQ(numbers, filteredSet);
}

TEST(NSSet, setByAddingObjectsFromArray) {
    NSArray* testArray = @[ @"Mercedes-Benz", @"BMW", @"Porsche", @"Opel", @"Volkswagen", @"Audi" ];
    NSSet* set = [NSSet set];
    NSSet* setFromArray = [set setByAddingObjectsFromArray:testArray];
    ASSERT_EQ(6, [setFromArray count]);
    for (id curObj in testArray) {
        ASSERT_TRUE([setFromArray containsObject:curObj]);
    }
}

TEST(NSSet, setByAddingObjectsFromArrayEmpty) {
    NSArray* emptyArray = @[];
    NSSet* set = [NSSet set];
    NSSet* setFromEmptyArray = [set setByAddingObjectsFromArray:emptyArray];
    ASSERT_TRUE([setFromEmptyArray count] == 0);
}

TEST(NSSet, setByAddingObjectsFromArrayDuplicate) {
    NSArray* dupArray = @[ @"Mercedes-Benz", @"Audi", @"BMW", @"Porsche", @"BMW", @"Opel", @"Volkswagen", @"Audi" ];
    NSSet* set = [NSSet set];
    NSSet* setFromDupArray = [set setByAddingObjectsFromArray:dupArray];
    ASSERT_EQ([setFromDupArray count], 6);
}

TEST(NSSet, MutableInstanceArchivesAsMutable) {
    NSMutableSet* input = [NSMutableSet setWithObject:@"hello"];

    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:input];
    ASSERT_OBJCNE(nil, data);

    NSMutableSet* output = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_OBJCNE(nil, output);

    EXPECT_NO_THROW([output addObject:@"world"]);

    EXPECT_OBJCNE(input, output);
}

TEST(NSMutableSet, ShouldThrowWhenTryingToInsertNil) {
    NSMutableSet* set = [NSMutableSet set];
    EXPECT_ANY_THROW([set addObject:nil]);
    EXPECT_EQ(0, [set count]);
}

// Cannot be certain of order of elements so cannot compare directly with reference platform
// The reference platform also has some unexpected behaviours when nesting collections, so we have opted for consistency
OSX_DISABLED_TEST(NSSet, Description) {
    NSSet* emptySet = [NSSet set];
    EXPECT_OBJCEQ(@"{(\n)}", emptySet.description);
    NSSet* nestedSet = [NSSet setWithObjects:[NSSet setWithObjects:@1, @[ @2, @"3", [NSSet setWithObject:@4] ], @5, nil], @"6", nil];
    NSString* expected = @"{(\n"
                          "        {(\n"
                          "                (\n"
                          "            2,\n"
                          "            3,\n"
                          "                        {(\n"
                          "                4\n"
                          "            )}\n"
                          "        ),\n"
                          "        1,\n"
                          "        5\n"
                          "    )},\n"
                          "    6\n"
                          ")}";
    EXPECT_OBJCEQ(expected, nestedSet.description);
}

TEST(NSSet, MakeObjectsPerformSelector) {
    NSSet* set = [NSSet setWithObjects:@[ @1, @2, @3 ], [NSSet setWithObjects:@4, @5, nil], @[ @6 ], nil];
    __block NSMutableSet* otherSet = [NSMutableSet set];
    [set makeObjectsPerformSelector:@selector(enumerateObjectsUsingBlock:)
                         withObject:^(id obj, BOOL* stop) {
                             [otherSet addObject:obj];
                         }];

    EXPECT_EQ(6, otherSet.count);
    EXPECT_TRUE([otherSet containsObject:@1]);
    EXPECT_TRUE([otherSet containsObject:@2]);
    EXPECT_TRUE([otherSet containsObject:@3]);
    EXPECT_TRUE([otherSet containsObject:@4]);
    EXPECT_TRUE([otherSet containsObject:@5]);
    EXPECT_TRUE([otherSet containsObject:@6]);
}

TEST(NSSet, ObjectsWithOptionsPassingTest) {
    NSSet* set = [NSSet setWithObjects:@1, @2, @3, @4, @5, nil];

    // Verify that the NSEnumerationConcurrent option executes the blocks concurrently
    __block NSCondition* condition = [[NSCondition new] autorelease];
    __block unsigned waitingCount = 0;
    NSSet* matchingForward = [set objectsWithOptions:NSEnumerationConcurrent
                                         passingTest:^BOOL(id obj, BOOL* stop) {
                                             [condition lock];
                                             waitingCount++;
                                             if (waitingCount == 5) {
                                                 waitingCount--;
                                                 [condition signal];
                                                 [condition unlock];
                                                 return [obj unsignedIntegerValue] % 2 == 0 ? YES : NO;
                                             }

                                             [condition wait];
                                             waitingCount--;
                                             [condition signal];
                                             [condition unlock];
                                             return [obj unsignedIntegerValue] % 2 == 0 ? YES : NO;
                                         }];

    ASSERT_EQ(0, waitingCount);

    NSSet* matchingReverse = [set objectsWithOptions:(NSEnumerationConcurrent | NSEnumerationReverse)
                                         passingTest:^BOOL(id obj, BOOL* stop) {
                                             [condition lock];
                                             waitingCount++;
                                             if (waitingCount == 5) {
                                                 waitingCount--;
                                                 [condition signal];
                                                 [condition unlock];
                                                 return [obj unsignedIntegerValue] % 2 == 0 ? YES : NO;
                                             }

                                             [condition wait];
                                             waitingCount--;
                                             [condition signal];
                                             [condition unlock];
                                             return [obj unsignedIntegerValue] % 2 == 0 ? YES : NO;
                                         }];

    ASSERT_EQ(0, waitingCount);

    EXPECT_EQ(2, matchingForward.count);
    EXPECT_TRUE([matchingForward containsObject:@2]);
    EXPECT_TRUE([matchingForward containsObject:@4]);

    // Effect of NSEnumerationReverse is undefined, so simply verify that the correct values are added to the set
    EXPECT_OBJCEQ(matchingForward, matchingReverse);
}
