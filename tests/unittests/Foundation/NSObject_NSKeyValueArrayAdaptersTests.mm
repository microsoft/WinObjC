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

#import <Foundation/Foundation.h>
#include <TestFramework.h>

@interface TestArrayAdapterObject : NSObject {
    NSMutableArray* alreadyMutable;
    NSArray* immutable;
    NSObject* notAnArray;

    BOOL fakeMutableInserted;

    // Named such to hide it from KVC.
    NSArray* _internal_immutableWithAccessors;
    BOOL immutableWithAccessorsSet;
    NSArray* _internal_immutableThroughKVC;
    BOOL immutableThroughKVCSet;

    NSObject* backedByIvar;
}
@end

@implementation TestArrayAdapterObject
- (id)init {
    self = [super init];
    alreadyMutable = [[NSMutableArray alloc] init];
    [alreadyMutable addObject:@"testObject"];
    immutable = @[ @"y" ];
    _internal_immutableWithAccessors = @[ @"y" ];
    _internal_immutableThroughKVC = @[ @"y" ];
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

- (void)removeObjectFromFakeMutableCollectionAtIndex:(NSUInteger)index {
    // no-op: exists only to ensure that this class is KVC-compliant for fakeMutableCollection.
}

- (BOOL)fakeMutableInserted {
    return fakeMutableInserted;
}

- (NSArray*)immutableWithAccessors {
    return _internal_immutableWithAccessors;
}

- (void)setImmutableWithAccessors:(NSArray*)value {
    _internal_immutableWithAccessors = [[value copy] autorelease];
    immutableWithAccessorsSet = YES;
}

- (BOOL)immutableWithAccessorsSet {
    return immutableWithAccessorsSet;
}

- (id)valueForKey:(NSString*)key {
    if ([@"immutableThroughKVC" isEqual:key]) {
        return _internal_immutableThroughKVC;
    }
    return [super valueForKey:key];
}

- (void)setValue:(id)value forKey:(NSString*)key {
    if ([@"immutableThroughKVC" isEqual:key]) {
        _internal_immutableThroughKVC = [[value copy] autorelease];
        immutableThroughKVCSet = YES;
        return;
    }
    return [super setValue:value forKey:key];
}

- (BOOL)immutableThroughKVCSet {
    return immutableThroughKVCSet;
}
@end

TEST(NSObject, KeyPathLookup) {
    NSDictionary* testDictionary = @{ @"key" : @{ @"subkey" : @{ @"subkey2" : @(1) } } };

    EXPECT_OBJCEQ(@(1), [testDictionary valueForKeyPath:@"key.subkey.subkey2"]);
}

TEST(NSObject, KVCArrayAdapters_CompliantIndexedAccessors) {
    TestArrayAdapterObject* testObject = [[[TestArrayAdapterObject alloc] init] autorelease];

    NSArray* fakeCollection = [testObject valueForKey:@"fakeCollection"];
    EXPECT_OBJCEQ(@(3), [fakeCollection objectAtIndex:3]);
}

TEST(NSObject, KVCArrayMutableAdapters_CompliantIndexedAccessors) {
    TestArrayAdapterObject* testObject = [[[TestArrayAdapterObject alloc] init] autorelease];
    NSMutableArray* fakeMutableCollection = [testObject mutableArrayValueForKey:@"fakeMutableCollection"];
    ([fakeMutableCollection addObject:@(10)]);
    EXPECT_OBJCEQ(@(10), [fakeMutableCollection objectAtIndex:10]);
    EXPECT_TRUE([testObject fakeMutableInserted]);
}

TEST(NSObject, KVCArrayMutableAdapters_ImmutableWithBasicAccessors) {
    TestArrayAdapterObject* testObject = [[[TestArrayAdapterObject alloc] init] autorelease];
    id mutableImmutable = [testObject mutableArrayValueForKey:@"immutableWithAccessors"];
    EXPECT_TRUE([mutableImmutable isKindOfClass:[NSMutableArray class]]);
    EXPECT_NO_THROW([mutableImmutable addObject:@"Whatever"]);

    ASSERT_TRUE([testObject immutableWithAccessorsSet]);
    EXPECT_TRUE([[testObject immutableWithAccessors] containsObject:@"Whatever"]);
}

TEST(NSObject, KVCArrayMutableAdapters_ImmutableThroughKVC) {
    TestArrayAdapterObject* testObject = [[[TestArrayAdapterObject alloc] init] autorelease];
    id mutableImmutable = [testObject mutableArrayValueForKey:@"immutableThroughKVC"];
    EXPECT_TRUE([mutableImmutable isKindOfClass:[NSMutableArray class]]);
    EXPECT_NO_THROW([mutableImmutable addObject:@"Whatever"]);

    ASSERT_TRUE([testObject immutableThroughKVCSet]);
    EXPECT_TRUE([[testObject valueForKey:@"immutableThroughKVC"] containsObject:@"Whatever"]);
}

TEST(NSObject, KVCArrayMutableAdapters_MutableArrayIvar) {
    TestArrayAdapterObject* testObject = [[[TestArrayAdapterObject alloc] init] autorelease];
    id mutableMutable = [testObject mutableArrayValueForKey:@"alreadyMutable"];
    EXPECT_TRUE([mutableMutable isKindOfClass:[NSMutableArray class]]);
}

TEST(NSObject, KVCArrayMutableAdapters_ImmutableArrayIvar) {
    TestArrayAdapterObject* testObject = [[[TestArrayAdapterObject alloc] init] autorelease];
    id mutableImmutable = [testObject mutableArrayValueForKey:@"immutable"];
    EXPECT_TRUE([mutableImmutable isKindOfClass:[NSMutableArray class]]);
    EXPECT_ANY_THROW([mutableImmutable addObject:@"Whatever"]);

    // The setter should have not stomped the original value of immutable, since it is an ivar.
    EXPECT_FALSE([[testObject valueForKey:@"immutable"] containsObject:@"Whatever"]);
}

TEST(NSObject, KVCArrayMutableAdapters_NonArrayIvar) {
    TestArrayAdapterObject* testObject = [[[TestArrayAdapterObject alloc] init] autorelease];
    id mutableObject = [testObject mutableArrayValueForKey:@"notAnArray"];
    EXPECT_TRUE([mutableObject isKindOfClass:[NSMutableArray class]]);
    EXPECT_ANY_THROW([mutableObject addObject:@"Whatever"]);
}

TEST(NSObject, KVCArrayMutableAdapters_ImmutableArrayDictionaryLeaf) {
    NSDictionary* testDictionary = @{ @"key" : @{ @"subkey" : @{ @"subkey2" : @[ @"hello" ] } } };
    NSMutableArray* mutableSubArray = [testDictionary mutableArrayValueForKeyPath:@"key.subkey.subkey2"];
    EXPECT_TRUE([mutableSubArray isKindOfClass:[NSMutableArray class]]);
    EXPECT_ANY_THROW([mutableSubArray addObject:@"Invalid"]);
}

TEST(NSObject, KVCArrayMutableAdapters_EmptyIvar) {
    TestArrayAdapterObject* testObject = [[[TestArrayAdapterObject alloc] init] autorelease];
    NSMutableArray* mutableWasNil = [testObject mutableArrayValueForKey:@"backedByIvar"];
    EXPECT_NO_THROW([mutableWasNil addObject:@"Hello"]);
    EXPECT_OBJCEQ(@"Hello", [[testObject valueForKey:@"backedByIvar"] firstObject]);
}

TEST(NSObject, KVCArrayChangePropagation) {
    NSMutableDictionary* dictionary = [NSMutableDictionary dictionary];
    [dictionary setObject:@[ @"1" ] forKey:@"array"];

    NSMutableArray* mutableVersionOfDictionaryArray = [dictionary mutableArrayValueForKeyPath:@"array"];

    EXPECT_OBJCEQ(@"1", [mutableVersionOfDictionaryArray objectAtIndex:0]);

    [dictionary setObject:@[ @"2" ] forKey:@"array"];

    // The value in index 0 should be updated even though we only requested mutableArray* once.
    EXPECT_OBJCEQ(@"2", [mutableVersionOfDictionaryArray objectAtIndex:0]);
}

TEST(NSObject, KVCArrayAutovivification) {
    NSMutableDictionary* dictionary = [NSMutableDictionary dictionary];
    NSMutableArray* nonexistentMutableArray = [dictionary mutableArrayValueForKey:@"new"];
    EXPECT_NO_THROW([nonexistentMutableArray addObject:@"Hello"]);
    EXPECT_EQ(1, [[dictionary objectForKey:@"new"] count]);
    EXPECT_OBJCEQ(@"Hello", [[dictionary objectForKey:@"new"] firstObject]);
}

@interface TestKVCObject : NSObject
@property (nonatomic, retain) id key1;
@property (nonatomic, retain) id key2;
@end

@implementation TestKVCObject
@end

TEST(Foundation, NSObject_KVCSetValuesForKeysWithDictionary) {
    TestKVCObject* testObject = [[[TestKVCObject alloc] init] autorelease];
    testObject.key2 = @"key2Value";
    NSDictionary* dictionary = @{ @"key1" : @"key1Value", @"key2" : [NSNull null] };

    EXPECT_NO_THROW([testObject setValuesForKeysWithDictionary:dictionary]);
    EXPECT_OBJCEQ(@"key1Value", testObject.key1);
    EXPECT_EQ(nil, testObject.key2);
}

TEST(Foundation, NSObject_KVCDictionaryWithValuesForKeys) {
    TestKVCObject* testObject = [[[TestKVCObject alloc] init] autorelease];
    NSDictionary* dictionary = @{ @"key1" : @"key1Value", @"key2" : [NSNull null] };

    EXPECT_NO_THROW([testObject setValuesForKeysWithDictionary:dictionary]);

    NSArray* array = @[ @"key1", @"key2" ];
    NSDictionary* results = [testObject dictionaryWithValuesForKeys:array];

    ASSERT_OBJCEQ(results[@"key1"], @"key1Value");
    ASSERT_OBJCEQ(results[@"key2"], [NSNull null]);
}
