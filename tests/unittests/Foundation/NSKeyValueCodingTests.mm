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
    return  [NSMutableSet setWithArray:obtainArrayOfCoins(start,end)];
}

TEST(NSKeyValueCoding, AggerateFunctionSum) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(45, [[coins valueForKeyPath:@"@sum.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionCount) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(10, [[coins valueForKeyPath:@"@count"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionMax) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(9, [[coins valueForKeyPath:@"@max.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionMin) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(0, [[coins valueForKeyPath:@"@min.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionAvg) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(4.5, [[coins valueForKeyPath:@"@avg.coinValue"] doubleValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionDistinctUnionOfObjects) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);

    for (int i = 0; i < 5; ++i) {
        [coins addObject:[[[KVCTestCoin alloc] initWithValue:i] autorelease]];
    }
    ASSERT_EQ(15, [coins count]);

    ASSERT_EQ(10, [[coins valueForKeyPath:@"@distinctUnionOfObjects.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggerateFunctionUnionOfObjects) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);

    for (int i = 0; i < 5; ++i) {
        [coins addObject:[[[KVCTestCoin alloc] initWithValue:i] autorelease]];
    }
    ASSERT_EQ(15, [coins count]);

    ASSERT_EQ(15, [[coins valueForKeyPath:@"@unionOfObjects.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggerateFunctionDistinctUnionOfArrays) {
    NSMutableArray* lowValueCoins = obtainArrayOfCoins(0, 10);
    NSMutableArray* highValueCoins = obtainArrayOfCoins(5, 10);

    NSArray* result = @[ lowValueCoins, highValueCoins, lowValueCoins ];

    ASSERT_EQ(10, [[result valueForKeyPath:@"@distinctUnionOfArrays.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggerateFunctionUnionOfArrays) {
    NSMutableArray* lowValueCoins = obtainArrayOfCoins(0, 10);
    NSMutableArray* highValueCoins = obtainArrayOfCoins(5, 10);
    NSArray* result = @[ lowValueCoins, highValueCoins, lowValueCoins ];

    ASSERT_EQ(25, [[result valueForKeyPath:@"@unionOfArrays.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggerateFunctionDistinctUnionOfSets) {
    NSMutableSet* lowValueCoins = obtainSetOfCoins(0, 10);
    NSMutableSet* highValueCoins = obtainSetOfCoins(5, 10);

    NSMutableSet* result = [NSMutableSet set];
    [result addObject:lowValueCoins];
    [result addObject:highValueCoins];

    ASSERT_EQ(10, [[result valueForKeyPath:@"@distinctUnionOfSets.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggerateFunctionSumSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);
    ASSERT_EQ(45, [[coins valueForKeyPath:@"@sum.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionCountSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);
    ASSERT_EQ(10, [[coins valueForKeyPath:@"@count"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionMaxSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);
    ASSERT_EQ(9, [[coins valueForKeyPath:@"@max.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionMinSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);
    ASSERT_EQ(0, [[coins valueForKeyPath:@"@min.coinValue"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionAvgSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);
    ASSERT_EQ(4.5, [[coins valueForKeyPath:@"@avg.coinValue"] doubleValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionDistinctUnionOfObjectsSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);

    for (int i = 0; i < 5; ++i) {
        [coins addObject:[[[KVCTestCoin alloc] initWithValue:i] autorelease]];
    }
    ASSERT_EQ(15, [coins count]);

    ASSERT_EQ(10, [[coins valueForKeyPath:@"@distinctUnionOfObjects.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggerateFunctionUnionOfObjectsSet) {
    NSMutableSet* coins = obtainSetOfCoins(0, 10);

    for (int i = 0; i < 5; ++i) {
        [coins addObject:[[[KVCTestCoin alloc] initWithValue:i] autorelease]];
    }
    ASSERT_EQ(15, [coins count]);

    ASSERT_EQ(10, [[coins valueForKeyPath:@"@unionOfObjects.coinValue"] count]);
}

TEST(NSKeyValueCoding, AggerateFunctionSumDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };
    ASSERT_EQ(16, [[inventory valueForKeyPath:@"@sum.testKey"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionCountDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };
    ASSERT_EQ(1, [[inventory valueForKeyPath:@"@count"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionMaxDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };
    ASSERT_EQ(10, [[inventory valueForKeyPath:@"@max.testKey"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionMinDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };
    ASSERT_EQ(1, [[inventory valueForKeyPath:@"@min.testKey"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionAvgDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };
    ASSERT_EQ(4, [[inventory valueForKeyPath:@"@avg.testKey"] doubleValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionDistinctUnionOfObjectsDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };

    ASSERT_EQ(4, [[inventory valueForKeyPath:@"@distinctUnionOfObjects.testKey"] count]);
}

TEST(NSKeyValueCoding, AggerateFunctionUnionOfObjectsDict) {
    NSDictionary* inventory = @{
        @"testKey" : @[ @1, @2, @3, @10 ],
    };

    ASSERT_EQ(1, [[inventory valueForKeyPath:@"@count"] intValue]);
}

TEST(NSKeyValueCoding, AggerateFunctionNullLeafArray) {
    NSMutableArray* result = obtainArrayOfCoins(0, 2);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@unionOfArrays.testObj"]);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@unionOfObjects.testObj"]);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@distinctUnionOfObjects.testObj"]);
}

TEST(NSKeyValueCoding, AggerateFunctionNullLeafSet) {
    NSMutableSet* result = obtainSetOfCoins(0, 2);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@distinctUnionOfSets.testObj"]);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@unionOfObjects.testObj"]);
    ASSERT_ANY_THROW([result valueForKeyPath:@"@distinctUnionOfObjects.testObj"]);
}

TEST(NSKeyValueCoding, AggerateFunctionNullLeafSet2) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_EQ(10, [[coins valueForKeyPath:@"@count.testObj"] intValue]);
    ASSERT_EQ(0, [[coins valueForKeyPath:@"@avg.testObj"] intValue]);
    ASSERT_EQ(0, [[coins valueForKeyPath:@"@sum.testObj"] intValue]);
	ASSERT_EQ(nil, [coins valueForKeyPath:@"@max.testObj"]);
	ASSERT_EQ(nil, [coins valueForKeyPath:@"@min.testObj"]);
}

TEST(NSKeyValueCoding, AggerateFunctionInvalid) {
    NSMutableArray* coins = obtainArrayOfCoins(0, 10);
    ASSERT_ANY_THROW([coins valueForKeyPath:@"@foobar.coinValue"]);
}