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

TEST(NSDictionary, BasicConstruction) {
    NSDictionary* dict = [NSDictionary dictionary];
    NSDictionary* dict2 = @{ @"foo" : @"bar" };
    ASSERT_EQ(dict.count, 0);
    ASSERT_EQ(dict2.count, 1);
}

// The below tests are intentionally commented out, in line with the Swift tests
TEST(NSDictionary, Description) {
    // Disabled due to [SR-251]
    // Assertion disabled since it fails on linux targets due to heterogenious collection conversion failure
    /*
    NSDictionary* d1 = @{ @"foo": @"bar", @"baz": @"qux"};
    ASSERT_OBJCEQ(d1.description, @"{\n    baz = qux;\n    foo = bar;\n}");
    NSDictionary* d2 = @{@"1" : @{@"1" : @{@"1" : @"1"}}};
    ASSERT_OBJCEQ(d2.description, @"{\n    1 =     {\n        1 =         {\n            1 = 1;\n        };\n    };\n}");
    */
}

TEST(NSDictionary, HeterogeneousConstruction) {
    //        NSDictionary* dict2 = @{
    //            @"foo": @"bar",
    //            @1 : @2
    //        };
    //        ASSERT_EQ(dict2.count, 2);
    //        ASSERT_EQ(([dict2[@"foo"] isKindOfClass:[NSString class]] ? (NSString*)dict2[@"foo"] : nil), [NSString
    //        stringWithUTF8String:@"bar"]);
    //        ASSERT_EQ(([dict2[@1] isKindOfClass:[NSNumber class]] ? (NSNumber*)dict2[@1] : nil), [NSNumber numberWithInt:2]);
}

TEST(NSDictionary, ArrayConstruction) {
    //        auto objects = @[@"foo", @"bar", @"baz"];
    //        auto keys = @[@"foo", @"bar", @"baz"];
    //        NSDictionary* dict = [NSDictionary dictionaryWithObjects:objects, forKeys: keys as [NSObject]];
    //        ASSERT_EQ(dict.count, 3)
}

TEST(NSDictionary, ObjectForKey) {
    // NSDictionary* dict = @{
    //     @"foo" : @"bar"
    // };
}

TEST(NSDictionary, Enumeration) {
    NSDictionary* dict = @{ @"foo" : @"bar", @"whiz" : @"bang", @"toil" : @"trouble" };
    auto e = [dict keyEnumerator];
    auto keys = [[NSMutableArray new] autorelease];
    [keys addObject:(NSString*)[e nextObject]];
    [keys addObject:(NSString*)[e nextObject]];
    [keys addObject:(NSString*)[e nextObject]];
    ASSERT_OBJCEQ([e nextObject], nil);
    ASSERT_OBJCEQ([e nextObject], nil);
    NSArray* expected = @[ @"foo", @"whiz", @"toil" ];
    ASSERT_OBJCEQ(keys, expected);

    auto o = [dict objectEnumerator];
    auto objs = [[NSMutableArray new] autorelease];
    [objs addObject:(NSString*)[o nextObject]];
    [objs addObject:(NSString*)[o nextObject]];
    [objs addObject:(NSString*)[o nextObject]];
    ASSERT_OBJCEQ([o nextObject], nil);
    ASSERT_OBJCEQ([o nextObject], nil);
    NSArray* expected2 = @[ @"bar", @"bang", @"trouble" ];
    ASSERT_OBJCEQ(objs, expected2);
}

TEST(NSDictionary, SequenceType) {
    NSDictionary* dict = @{ @"foo" : @"bar", @"whiz" : @"bang", @"toil" : @"trouble" };
    NSMutableDictionary* result = [NSMutableDictionary dictionary];
    [dict enumerateKeysAndObjectsUsingBlock:^(id key, id value, BOOL* stop) {
        result[key] = value;
    }];
    NSDictionary* expected = @{ @"foo" : @"bar", @"whiz" : @"bang", @"toil" : @"trouble" };
    ASSERT_OBJCEQ(result, expected);
}

TEST(NSDictionary, Equality) {
    auto keys = @[ @"foo", @"whiz", @"toil" ];
    auto objects1 = @[ @"bar", @"bang", @"trouble" ];
    auto objects2 = @[ @"bar", @"bang", @"troubl" ];
    NSDictionary* dict1 = [NSDictionary dictionaryWithObjects:objects1 forKeys:keys];
    NSDictionary* dict2 = [NSDictionary dictionaryWithObjects:objects1 forKeys:keys];
    NSDictionary* dict3 = [NSDictionary dictionaryWithObjects:objects2 forKeys:keys];

    ASSERT_TRUE([dict1 isEqual:dict2]);
    ASSERT_TRUE([dict1 isEqualToDictionary:dict2]);
    ASSERT_EQ(dict1.hash, dict2.hash);

    ASSERT_FALSE([dict1 isEqual:dict3]);
    ASSERT_FALSE([dict1 isEqualToDictionary:dict3]);

    ASSERT_FALSE([dict1 isEqual:nil]);
    ASSERT_FALSE([dict1 isEqual:[[NSObject new] autorelease]]);
}

TEST(NSDictionary, Copying) {
    NSDictionary* inputDictionary = @{ @"foo" : @"bar", @"whiz" : @"bang", @"toil" : @"trouble" };

    NSDictionary* copy = (NSDictionary*)[inputDictionary copy];
    ASSERT_OBJCEQ(inputDictionary, copy);

    NSMutableDictionary* dictMutableCopy = (NSMutableDictionary*)[inputDictionary mutableCopy];
    NSDictionary* dictCopy2 = (NSDictionary*)[dictMutableCopy copy];
    ASSERT_TRUE([dictCopy2 isKindOfClass:[NSDictionary class]]);
    ASSERT_NE(dictMutableCopy, dictCopy2);
    ASSERT_OBJCEQ(dictMutableCopy, dictCopy2);
}

TEST(NSDictionary, MutableCopying) {
    NSDictionary* inputDictionary = @{ @"foo" : @"bar", @"whiz" : @"bang", @"toil" : @"trouble" };

    NSMutableDictionary* dictMutableCopy1 = (NSMutableDictionary*)[inputDictionary mutableCopy];
    ASSERT_TRUE([dictMutableCopy1 isKindOfClass:[NSMutableDictionary class]]);
    ASSERT_NE(inputDictionary, dictMutableCopy1);
    ASSERT_OBJCEQ(inputDictionary, dictMutableCopy1);

    NSMutableDictionary* dictMutableCopy2 = (NSMutableDictionary*)[dictMutableCopy1 mutableCopy];
    ASSERT_TRUE([dictMutableCopy2 isKindOfClass:[NSMutableDictionary class]]);
    ASSERT_NE(dictMutableCopy2, dictMutableCopy1);
    ASSERT_OBJCEQ(dictMutableCopy2, dictMutableCopy1);
}
