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

TEST(NSSet, BasicConstruction) {
    NSSet* set = [NSSet set];
    NSSet* set2 = [NSSet setWithArray:@[ @"foo", @"bar" ]];
    ASSERT_EQ(set.count, 0);
    ASSERT_EQ(set2.count, 2);
}

TEST(NSSet, InitWithSet) {
    auto genres = [NSSet setWithObjects:@"Rock", @"Classical", @"Hip hop", nil];
    NSSet* set1 = [NSSet setWithSet:genres];
    // NSSet* set2 = [[[NSSet alloc] initWithSet:genres copyItems:false] autorelease];
    ASSERT_EQ(set1.count, 3);
    // ASSERT_EQ(set2.count, 3);
    // ASSERT_OBJCEQ(set1, set2);

    // NSSet* set3 = [[[NSSet alloc] initWithSet:genres copyItems:true] autorelease];
    // ASSERT_EQ(set3.count, 3);
    // ASSERT_OBJCEQ(set3, set2);
}

TEST(NSSet, Enumeration) {
    NSSet* set = [NSSet setWithArray:@[ @"foo", @"bar", @"baz" ]];
    auto e = [set objectEnumerator];
    NSMutableSet* result = [NSMutableSet set];
    [result addObject:(NSString*)([e nextObject])];
    [result addObject:(NSString*)([e nextObject])];
    [result addObject:(NSString*)([e nextObject])];
    auto expected = [NSSet setWithObjects:@"foo", @"bar", @"baz", nil];
    ASSERT_OBJCEQ(result, expected);

    auto empty = [[NSSet set] objectEnumerator];
    ASSERT_OBJCEQ([empty nextObject], nil);
    ASSERT_OBJCEQ([empty nextObject], nil);
}

TEST(NSSet, SequenceType) {
    NSSet* set = [NSSet setWithArray:@[ @"foo", @"bar", @"baz" ]];
    NSMutableSet* res = [NSMutableSet set];
    for (id obj in set) {
        [res addObject:(NSString*)(obj)];
    }

    auto expected = [NSSet setWithObjects:@"foo", @"bar", @"baz", nil];
    ASSERT_OBJCEQ(res, expected);
}

TEST(NSSet, SetOperations) {
    NSMutableSet* set = [NSMutableSet setWithArray:@[ @"foo", @"bar" ]];
    [set unionSet:[NSSet setWithObjects:@"bar", @"baz", nil]];
    auto expected = [NSSet setWithObjects:@"foo", @"bar", @"baz", nil];
    ASSERT_TRUE([set isEqualToSet:expected]);
}

TEST(NSSet, Equality) {
    auto inputArray1 = @[ @"this", @"is", @"a", @"test", @"of", @"equality", @"with", @"strings" ];
    auto inputArray2 = @[ @"this", @"is", @"a", @"test", @"of", @"equality", @"with", @"objects" ];
    NSSet* set1 = [NSSet setWithArray:inputArray1];
    NSSet* set2 = [NSSet setWithArray:inputArray1];
    NSSet* set3 = [NSSet setWithArray:inputArray2];

    ASSERT_TRUE([set1 isEqual:set2]);
    ASSERT_TRUE([set1 isEqualToSet:set2]);
    ASSERT_EQ(set1.hash, set2.hash);

    ASSERT_FALSE([set1 isEqual:set3]);
    ASSERT_FALSE([set1 isEqualToSet:set3]);

    ASSERT_FALSE([set1 isEqual:nil]);
    ASSERT_FALSE([set1 isEqual:[[NSObject new] autorelease]]);
}

TEST(NSSet, Copying) {
    auto inputArray = @[ @"this", @"is", @"a", @"test", @"of", @"copy", @"with", @"strings" ];

    NSSet* set = [NSSet setWithArray:inputArray];
    NSSet* setCopy1 = (NSSet*)[set copy];
    ASSERT_OBJCEQ(set, setCopy1);

    NSMutableSet* setMutableCopy = (NSMutableSet*)[set mutableCopy];
    NSSet* setCopy2 = (NSSet*)[setMutableCopy copy];
    // ASSERT_EQ(setCopy2.dynamicType, NSSet.self);
    ASSERT_NE(setMutableCopy, setCopy2);
    for (id entry in setCopy2) {
        ASSERT_TRUE([setMutableCopy.allObjects indexOfObjectIdenticalTo:entry] != NSNotFound);
    }
}

TEST(NSSet, MutableCopying) {
    auto inputArray = @[ @"this", @"is", @"a", @"test", @"of", @"mutableCopy", @"with", @"strings" ];
    NSSet* set = [NSSet setWithArray:inputArray];

    NSMutableSet* setMutableCopy1 = (NSMutableSet*)[set mutableCopy];
    // ASSERT_EQ(setMutableCopy1.dynamicType, NSMutableSet.self);
    ASSERT_NE(set, setMutableCopy1);
    for (id entry in setMutableCopy1) {
        ASSERT_TRUE([set.allObjects indexOfObjectIdenticalTo:entry] != NSNotFound);
    }

    NSMutableSet* setMutableCopy2 = (NSMutableSet*)[setMutableCopy1 mutableCopy];
    // ASSERT_EQ(setMutableCopy2.dynamicType, NSMutableSet.self);
    ASSERT_NE(setMutableCopy2, setMutableCopy1);
    for (id entry in setMutableCopy2) {
        ASSERT_TRUE([setMutableCopy1.allObjects indexOfObjectIdenticalTo:entry] != NSNotFound);
    }
}

TEST(NSSet, CountedSetBasicConstruction) {
    auto v1 = @"v1";
    auto v2 = @"v2";
    auto v3asv1 = @"v1";
    NSCountedSet* set = [NSCountedSet set];
    NSCountedSet* set2 = [NSCountedSet setWithArray:@[ v1, v1, v2, v3asv1 ]];
    NSCountedSet* set3 = [NSCountedSet setWithSet:[NSSet setWithObjects:v1, v1, v2, v3asv1, nil]];
    NSCountedSet* set4 = [NSCountedSet setWithCapacity:4];

    ASSERT_EQ(set.count, 0);
    ASSERT_EQ(set2.count, 2);
    ASSERT_EQ(set3.count, 2);
    ASSERT_EQ(set4.count, 0);
}

TEST(NSSet, CountedSetObjectCount) {
    auto v1 = @"v1";
    auto v2 = @"v2";
    auto v3asv1 = @"v1";
    NSCountedSet* set = [NSCountedSet set];
    NSCountedSet* set2 = [NSCountedSet setWithArray:@[ v1, v1, v2, v3asv1 ]];
    NSCountedSet* set3 = [NSCountedSet setWithSet:[NSSet setWithObjects:v1, v1, v2, v3asv1, nil]];

    ASSERT_EQ([set countForObject:v1], 0);
    ASSERT_EQ([set2 countForObject:v1], 3);
    ASSERT_EQ([set2 countForObject:v2], 1);
    ASSERT_EQ([set2 countForObject:v3asv1], 3);
    ASSERT_EQ([set3 countForObject:v1], 1);
    ASSERT_EQ([set3 countForObject:v2], 1);
    ASSERT_EQ([set3 countForObject:v3asv1], 1);
}

TEST(NSSet, CountedSetAddObject) {
    auto v1 = @"v1";
    auto v2 = @"v2";
    auto v3asv1 = @"v1";
    NSCountedSet* set = [NSCountedSet setWithArray:@[ v1, v1, v2 ]];

    ASSERT_EQ([set countForObject:v1], 2);
    ASSERT_EQ([set countForObject:v2], 1);
    [set addObject:v3asv1];
    ASSERT_EQ([set countForObject:v1], 3);
    [set addObjectsFromArray:@[ v1, v2 ]];
    ASSERT_EQ([set countForObject:v1], 4);
    ASSERT_EQ([set countForObject:v2], 2);
}

TEST(NSSet, CountedSetRemoveObject) {
    auto v1 = @"v1";
    auto v2 = @"v2";
    NSCountedSet* set = [NSCountedSet setWithArray:@[ v1, v1, v2 ]];

    ASSERT_EQ([set countForObject:v1], 2);
    ASSERT_EQ([set countForObject:v2], 1);
    [set removeObject:v2];
    ASSERT_EQ([set countForObject:v2], 0);
    ASSERT_EQ([set countForObject:v1], 2);
    [set removeObject:v2];
    ASSERT_EQ([set countForObject:v2], 0);
    ASSERT_EQ([set countForObject:v1], 2);
    [set removeAllObjects];
    ASSERT_EQ([set countForObject:v2], 0);
    ASSERT_EQ([set countForObject:v1], 0);
}

TEST(NSSet, CountedSetCopying) {
    auto inputArray = @[ @"this", @"is", @"a", @"test", @"of", @"copy", @"with", @"strings" ];

    NSCountedSet* set = [NSCountedSet setWithArray:inputArray];
    NSCountedSet* setCopy = (NSCountedSet*)[set copy];
    ASSERT_NE(set, setCopy);

    NSCountedSet* setMutableCopy = (NSCountedSet*)[set mutableCopy];
    ASSERT_NE(set, setMutableCopy);
    ASSERT_TRUE([setCopy isKindOfClass:[NSCountedSet class]]);
    ASSERT_TRUE([setMutableCopy isKindOfClass:[NSCountedSet class]]);
    for (id entry in setCopy) {
        ASSERT_TRUE([setMutableCopy.allObjects indexOfObjectIdenticalTo:entry] != NSNotFound);
    }
}
