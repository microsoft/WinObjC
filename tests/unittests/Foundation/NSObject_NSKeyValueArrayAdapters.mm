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

#include "gtest-api.h"
#import <Foundation/Foundation.h>

@interface TestArrayAdapterObject : NSObject {
    NSMutableArray* alreadyMutable;
    NSArray* immutable;
    NSObject* notAnArray;

    BOOL fakeMutableInserted;
}
@end

@implementation TestArrayAdapterObject
- (id)init {
    self = [super init];
    alreadyMutable = [[NSMutableArray alloc] init];
    [alreadyMutable addObject:@"testObject"];
    immutable = @[ @"y" ];
    notAnArray = [NSObject new];
    return self;
}

- (NSUInteger)countOfFakeCollection {
    return 10;
}

- (NSObject*)objectInFakeCollectionAtIndex:(NSUInteger)index {
    return @(index);
}

- (NSUInteger)countOfFakeMutableCollection {
    return 10;
}

- (NSObject*)objectInFakeMutableCollectionAtIndex:(NSUInteger)index {
    return @(index);
}

- (void)insertObject:(id)object inFakeMutableCollectionAtIndex:(NSUInteger)index {
    fakeMutableInserted = true;
}

- (BOOL)fakeMutableInserted {
    return fakeMutableInserted;
}
@end

TEST(Foundation, NSObject_KeyPathLookup) {
    NSDictionary* testDictionary = @{@"key": @{@"subkey": @{@"subkey2": @(1)}}};

    EXPECT_OBJCEQ(@(1), [testDictionary valueForKeyPath:@"key.subkey.subkey2"]);
}

TEST(Foundation, NSObject_KVCArrayAdapters) {
    TestArrayAdapterObject* testObject = [[TestArrayAdapterObject alloc] init];

    NSArray* fakeCollection = [testObject valueForKey:@"fakeCollection"];
    EXPECT_OBJCEQ(@(3), [fakeCollection objectAtIndex:3]);

    NSMutableArray* fakeMutableCollection = [testObject mutableArrayValueForKey:@"fakeMutableCollection"];
    EXPECT_NO_THROW([fakeMutableCollection addObject:@(10)]);
    EXPECT_OBJCEQ(@(10), [fakeMutableCollection objectAtIndex:10]);
    EXPECT_TRUE([testObject fakeMutableInserted]);

    id mutableMutable = [testObject mutableArrayValueForKey:@"alreadyMutable"];
    EXPECT_TRUE([mutableMutable isKindOfClass:[NSMutableArray class]]);

    id mutableImmutable = [testObject mutableArrayValueForKey:@"immutable"];
    EXPECT_TRUE([mutableImmutable isKindOfClass:[NSMutableArray class]]);
    EXPECT_NO_THROW([mutableImmutable addObject:@"Whatever"]);

    // The setter should have stomped the original value of immutable, thus mutating it.
    EXPECT_TRUE([[testObject valueForKey:@"immutable"] containsObject:@"Whatever"]);

    id mutableObject = [testObject mutableArrayValueForKey:@"notAnArray"];
    EXPECT_TRUE([mutableObject isKindOfClass:[NSMutableArray class]]);
    EXPECT_ANY_THROW([mutableObject addObject:@"Whatever"]);

    NSDictionary* testDictionary = @{@"key": @{@"subkey": @{@"subkey2": @[@"hello"]}}};
    NSMutableArray* mutableSubArray = [testDictionary mutableArrayValueForKeyPath:@"key.subkey.subkey2"];
    EXPECT_TRUE([mutableSubArray isKindOfClass:[NSMutableArray class]]);
    EXPECT_ANY_THROW([mutableSubArray addObject:@"Invalid"]);
}

TEST(Foundation, NSUserDefaults_KVCArray) {
    [[NSUserDefaults standardUserDefaults] setObject:@[@"User Preference 1"] forKey:@"userPref1"];
    NSMutableArray* mutableSetting = [[NSUserDefaults standardUserDefaults] mutableArrayValueForKeyPath:@"userPref1"];
    EXPECT_OBJCNE(nil, mutableSetting);
    EXPECT_NO_THROW([mutableSetting addObject:@"Another"]);
    EXPECT_TRUE([[[NSUserDefaults standardUserDefaults] objectForKey:@"userPref1"] containsObject:@"Another"]);
    [[NSUserDefaults standardUserDefaults] synchronize];
}