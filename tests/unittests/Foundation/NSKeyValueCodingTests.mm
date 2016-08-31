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

#import <TestFramework.h>
#import <Foundation/Foundation.h>

// Many of the tests in this file are disabled pending a fix for GH#800.
// In short, we have known incompatibilities with aggregate function support vis-a-vis the reference platform.
// Until we've fixed them, we're disabling the tests that are noncompliant.

@interface KVCTestCoin : NSObject
@property (assign) NSInteger coinValue;
@property (retain) NSObject* testObj;
@end

@implementation KVCTestCoin
- (instancetype)initWithValue:(NSInteger)value {
    if (self = [super init]) {
        _coinValue = value;
        _testObj = nil;
    }
    return self;
}

- (void)dealloc {
    [_testObj release];
    [super dealloc];
}
@end

static NSMutableArray* obtainArrayOfCoins(unsigned int start, unsigned int end) {
    NSMutableArray* coins = [NSMutableArray array];
    for (unsigned int i = start; i < end; i++) {
        KVCTestCoin* coin = [[[KVCTestCoin alloc] initWithValue:i] autorelease];
        [coins addObject:coin];
    }
    return coins;
}

static NSMutableSet* obtainSetOfCoins(unsigned int start, unsigned int end) {
    return [NSMutableSet setWithArray:obtainArrayOfCoins(start, end)];
}

TEST(NSKeyValueCoding, AggregateFunctionSum) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(45, [[coins valueForKeyPath:@"@sum.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggregateFunctionCount) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(10, [[coins valueForKeyPath:@"@count"] intValue]);
}

TEST(NSKeyValueCoding, AggregateFunctionMax) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(9, [[coins valueForKeyPath:@"@max.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggregateFunctionMin) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(0, [[coins valueForKeyPath:@"@min.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggregateFunctionAvg) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(4.5, [[coins valueForKeyPath:@"@avg.coinValue"] doubleValue]);
}

TEST(NSKeyValueCoding, AggregateFunctionDistinctUnionOfObjects) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);

    for (int i = 0; i < 5; ++i) {
        [coins addObject:[[[KVCTestCoin alloc] initWithValue:i] autorelease]];
    }
    ASSERT_EQ(15, [coins count]);

    ASSERT_EQ(10, [[coins valueForKeyPath:@"@distinctUnionOfObjects.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggregateFunctionUnionOfObjects) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);

    for (int i = 0; i < 5; ++i) {
        [coins addObject:[[[KVCTestCoin alloc] initWithValue:i] autorelease]];
    }
    ASSERT_EQ(15, [coins count]);

    ASSERT_EQ(15, [[coins valueForKeyPath:@"@unionOfObjects.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggregateFunctionDistinctUnionOfArrays) {
    NSMutableArray* lowValueCoins = obtainArrayOfCoins(0, 10);
    NSMutableArray* highValueCoins = obtainArrayOfCoins(5, 10);

    NSArray* result = @[ lowValueCoins, highValueCoins, lowValueCoins ];

    ASSERT_EQ(10, [[result valueForKeyPath:@"@distinctUnionOfArrays.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggregateFunctionUnionOfArrays) {
    NSMutableArray* lowValueCoins = obtainArrayOfCoins(0, 10);
    NSMutableArray* highValueCoins = obtainArrayOfCoins(5, 10);
    NSArray* result = @[ lowValueCoins, highValueCoins, lowValueCoins ];

    ASSERT_EQ(25, [[result valueForKeyPath:@"@unionOfArrays.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggregateFunctionDistinctUnionOfSets) {
    NSMutableSet* lowValueCoins = obtainSetOfCoins(0, 10);
    NSMutableSet* highValueCoins = obtainSetOfCoins(5, 10);

    NSMutableSet* result = [NSMutableSet set];
    [result addObject:lowValueCoins];
    [result addObject:highValueCoins];

    ASSERT_EQ(10, [[result valueForKeyPath:@"@distinctUnionOfSets.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggregateFunctionSumSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);
    ASSERT_EQ(45, [[coins valueForKeyPath:@"@sum.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggregateFunctionCountSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);
    ASSERT_EQ(10, [[coins valueForKeyPath:@"@count"] intValue]);
}

TEST(NSKeyValueCoding, AggregateFunctionMaxSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);
    ASSERT_EQ(9, [[coins valueForKeyPath:@"@max.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggregateFunctionMinSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);
    ASSERT_EQ(0, [[coins valueForKeyPath:@"@min.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggregateFunctionAvgSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);
    ASSERT_EQ(4.5, [[coins valueForKeyPath:@"@avg.coinValue"] doubleValue]);
}

TEST(NSKeyValueCoding, AggregateFunctionDistinctUnionOfObjectsSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);

    for (int i = 0; i < 5; ++i) {
        [coins addObject:[[[KVCTestCoin alloc] initWithValue:i] autorelease]];
    }
    ASSERT_EQ(15, [coins count]);

    ASSERT_EQ(10, [[coins valueForKeyPath:@"@distinctUnionOfObjects.coinValue"] count]);
}

OSX_DISABLED_TEST(NSKeyValueCoding, AggregateFunctionUnionOfObjectsSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);

    for (int i = 0; i < 5; ++i) {
        [coins addObject:[[[KVCTestCoin alloc] initWithValue:i] autorelease]];
    }
    ASSERT_EQ(15, [coins count]);

    ASSERT_EQ(10, [[coins valueForKeyPath:@"@unionOfObjects.coinValue"] count]);
}

OSX_DISABLED_TEST(NSKeyValueCoding, AggregateFunctionSumDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };
    ASSERT_EQ(16, [[inventory valueForKeyPath:@"@sum.testKey"] intValue]);
}

OSX_DISABLED_TEST(NSKeyValueCoding, AggregateFunctionCountDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };
    ASSERT_EQ(1, [[inventory valueForKeyPath:@"@count"] intValue]);
}

OSX_DISABLED_TEST(NSKeyValueCoding, AggregateFunctionMaxDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };
    ASSERT_EQ(10, [[inventory valueForKeyPath:@"@max.testKey"] intValue]);
}

OSX_DISABLED_TEST(NSKeyValueCoding, AggregateFunctionMinDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };
    ASSERT_EQ(1, [[inventory valueForKeyPath:@"@min.testKey"] intValue]);
}

OSX_DISABLED_TEST(NSKeyValueCoding, AggregateFunctionAvgDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };
    ASSERT_EQ(4, [[inventory valueForKeyPath:@"@avg.testKey"] doubleValue]);
}

OSX_DISABLED_TEST(NSKeyValueCoding, AggregateFunctionDistinctUnionOfObjectsDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @3, @10 ],
    };

    ASSERT_EQ(4, [[inventory valueForKeyPath:@"@distinctUnionOfObjects.testKey"] count]);
}

OSX_DISABLED_TEST(NSKeyValueCoding, AggregateFunctionUnionOfObjectsDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @3, @10 ],
    };

    ASSERT_EQ(5, [[inventory valueForKeyPath:@"@unionOfObjects.testKey"] count]);
}

// The following two tests are disabled because OS X violates the contract set out for these functions in
// https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/KeyValueCoding/Articles/CollectionOperators.html
// > @unionOfArrays
// >   Important: This operator raises an exception if any of the leaf objects is nil.
// Evidence shows that it does, in fact, not raise an exception if any of the leaf objects is nil.
OSX_DISABLED_TEST(NSKeyValueCoding, AggregateFunctionNullLeafUnionArray) {
    NSMutableArray* result = obtainArrayOfCoins(0, 2);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@unionOfArrays.testObj"]);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@unionOfObjects.testObj"]);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@distinctUnionOfObjects.testObj"]);
}

OSX_DISABLED_TEST(NSKeyValueCoding, AggregateFunctionNullLeafUnionSet) {
    NSMutableSet* result = obtainSetOfCoins(0, 2);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@distinctUnionOfSets.testObj"]);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@unionOfObjects.testObj"]);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@distinctUnionOfObjects.testObj"]);
}

TEST(NSKeyValueCoding, AggregateFunctionNullLeaf) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(10, [[coins valueForKeyPath:@"@count.testObj"] intValue]);
    ASSERT_EQ(0, [[coins valueForKeyPath:@"@avg.testObj"] intValue]);
    ASSERT_EQ(0, [[coins valueForKeyPath:@"@sum.testObj"] intValue]);
    ASSERT_EQ(nil, [coins valueForKeyPath:@"@max.testObj"]);
    ASSERT_EQ(nil, [coins valueForKeyPath:@"@min.testObj"]);
}

TEST(NSKeyValueCoding, AggregateFunctionInvalid) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_ANY_THROW([coins valueForKeyPath:@"@foobar.coinValue"]);
}