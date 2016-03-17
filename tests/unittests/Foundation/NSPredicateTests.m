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
#import "NSBooleanPredicate.h"

TEST(NSPredicate, Init) {
    NSPredicate* predicate = [[NSPredicate alloc] init];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");
    [predicate release];
}

TEST(NSPredicate, NSBooleanPredicateYES) {
    NSBooleanPredicate* predicate = [[NSBooleanPredicate alloc] initWithValue:YES];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");
    ASSERT_TRUE_MSG([predicate value], "FAILED: predicate should be YES.");
    [predicate release];
}

TEST(NSPredicate, NSBooleanPredicateNO) {
    NSBooleanPredicate* predicate = [[NSBooleanPredicate alloc] initWithValue:NO];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");
    ASSERT_TRUE_MSG(![predicate value], "FAILED: predicate should be NO.");
    [predicate release];
}

TEST(NSPredicate, predicateWithValue) {
    NSPredicate* predicateTrue = [NSPredicate predicateWithValue:YES];
    ASSERT_TRUE_MSG(predicateTrue != nil, "FAILED: predicateTrue should be non-null!");

    NSPredicate* predicateFalse = [NSPredicate predicateWithValue:NO];
    ASSERT_TRUE_MSG(predicateFalse != nil, "FAILED: predicateFalse should be non-null!");

    ASSERT_TRUE_MSG([predicateTrue evaluateWithObject:nil], "FAILED: predicate should be YES.");
	ASSERT_TRUE_MSG(![predicateFalse evaluateWithObject:nil], "FAILED: predicate should be NO.");
    [predicateFalse release];
	[predicateTrue release];
}

TEST(NSPredicate, NSBooleanPredicate_ArchiveAndUnarchiveObject) {
    NSBooleanPredicate* predicate = [[NSBooleanPredicate alloc] initWithValue:NO];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");

    // archive the object
    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:predicate];
    ASSERT_TRUE_MSG(data != nil, "FAILED: archived data should be non-null!");

    NSPredicate* unArchivedPredicate = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_TRUE_MSG(unArchivedPredicate != nil, "FAILED: unArchivedPredicate should be non-null!");

    [predicate release];
}

TEST(NSPredicate, PredicateWithBlock) {
    NSArray* array = @[ @1, @2, @3, @7, @8, @11, @14, @19, @20 ];

    NSPredicate* evenNumbersPredicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* number = (NSNumber*)evaluatedObject;
        return [number integerValue] % 2 == 0;
    }];

    ASSERT_TRUE_MSG(evenNumbersPredicate != nil, "FAILED: evenNumbersPredicate should be non-null!");

    NSArray* filteredArray = [array filteredArrayUsingPredicate:evenNumbersPredicate];
    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");
    for (id object in array) {
        if (!([object integerValue] % 2)) {
            ASSERT_EQ_MSG(YES, [filteredArray containsObject:object], "FAILED: even filter did not work as expected, value not found.");
        }
    }

    [evenNumbersPredicate release];
    [filteredArray release];
    [array release];
}

// Used for testing keys and custom block.
@interface Coin : NSObject
@property (assign) NSInteger coinValue;
@end

@implementation Coin
- (instancetype)initWithValue:(NSInteger)value {
    if (self == [super init]) {
        _coinValue = value;
    }
    return self;
}
@end

TEST(NSPredicate, PredicateWithBlockSub) {
    NSMutableArray* array = [[NSMutableArray alloc] init];

    int specialValue = 10;
    int size = 10;

    NSDictionary* bindings = [NSDictionary dictionaryWithObject:[NSNumber numberWithInt:specialValue] forKey:@"rareCoinValue"];
    NSPredicate* specialCoinPredicate = [NSPredicate predicateWithBlock:^BOOL(id evaluatedObject, NSDictionary* bindings) {
        NSNumber* rareCoinValue = [bindings valueForKey:@"rareCoinValue"];
        return ([evaluatedObject coinValue] == [rareCoinValue integerValue]);
    }];

    ASSERT_TRUE_MSG(specialCoinPredicate != nil, "FAILED: specialCoinPredicate should be non-null!");

    for (int i = 0; i < size; ++i) {
        Coin* obj = [[[Coin alloc] initWithValue:(i * 10)] autorelease];
        [array addObject:obj];
    }

    NSMutableArray* filteredArray = [[NSMutableArray alloc] init];

    for (int i = 0; i < size; ++i) {
        id obj = [array objectAtIndex:i];
        if ([specialCoinPredicate evaluateWithObject:obj substitutionVariables:bindings]) {
            [filteredArray addObject:obj];
        }
    }

    ASSERT_TRUE_MSG(filteredArray != nil, "FAILED: filteredArray should be non-null!");
    ASSERT_EQ_MSG(1, [filteredArray count], "FAILED: failed to filter the coins.");
    ASSERT_EQ_MSG(specialValue, [[filteredArray firstObject] coinValue], "FAILED: Unable to obtain the correct coin value.");

    [specialCoinPredicate release];
    [filteredArray release];
    [array release];
}

TEST(NSPredicate, ArchiveAndUnarchiveObject) {
    NSPredicate* predicate = [[NSPredicate alloc] init];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");

    // archive the object
    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:predicate];
    ASSERT_TRUE_MSG(data != nil, "FAILED: archived data should be non-null!");

    NSPredicate* unArchivedPredicate = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_TRUE_MSG(unArchivedPredicate != nil, "FAILED: unArchivedPredicate should be non-null!");

    [predicate release];
}

TEST(NSPredicate, copy) {
    NSPredicate* predicate = [[NSPredicate alloc] init];
    ASSERT_TRUE_MSG(predicate != nil, "FAILED: predicate should be non-null!");

    NSPredicate* copyObj = [predicate copy];
    ASSERT_TRUE_MSG(copyObj != nil, "FAILED: copyObj should be non-null!");

    ASSERT_OBJCEQ_MSG(predicate, copyObj, "FAILED: objects do not match.");

    [copyObj release];
    [predicate release];
}