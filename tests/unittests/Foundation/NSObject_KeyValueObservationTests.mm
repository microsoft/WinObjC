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

#import <Foundation/Foundation.h>
#import <Starboard/SmartTypes.h>
#include <TestFramework.h>

#import "TestUtils.h"

#pragma region Helper Classes
#define TEST_PREFIX Foundation_NSObject_KVO_Tests
#define TEST_IDENT(x) CONCAT(TEST_PREFIX, _##x)

@interface TEST_IDENT (Observee): NSObject {
    NSMutableArray* _bareArray;
    NSMutableArray* _manualNotificationArray;
    NSMutableArray* _kvcMediatedArray;
    NSMutableArray* _arrayWithHelpers;
    NSMutableSet* _setWithHelpers;
    NSMutableSet* _kvcMediatedSet;
    NSMutableSet* _manualNotificationSet;
}
@end

@implementation TEST_IDENT (Observee)
+ (instancetype)observee {
    return [[[self alloc] init] autorelease];
}

- (instancetype)init {
    if (self = [super init]) {
        _bareArray = [NSMutableArray new];
        _manualNotificationArray = [NSMutableArray new];
        _kvcMediatedArray = [NSMutableArray new];
        _arrayWithHelpers = [NSMutableArray new];
        _setWithHelpers = [NSMutableSet new];
        _kvcMediatedSet = [NSMutableSet new];
        _manualNotificationSet = [NSMutableSet new];
    }
    return self;
}

- (void)dealloc {
    [_bareArray release];
    [_manualNotificationArray release];
    [_kvcMediatedArray release];
    [_arrayWithHelpers release];
    [_setWithHelpers release];
    [_kvcMediatedSet release];
    [_manualNotificationSet release];
    [super dealloc];
}

- (void)addObjectToBareArray:(NSObject*)object {
    [_bareArray addObject:object];
}

- (void)addObjectToManualArray:(NSObject*)object {
    NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:[_manualNotificationArray count]];
    [self willChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:@"manualNotificationArray"];
    [_manualNotificationArray addObject:object];
    [self didChange:NSKeyValueChangeInsertion valuesAtIndexes:indexes forKey:@"manualNotificationArray"];
}

- (void)removeObjectFromManualArrayIndex:(NSUInteger)index {
    NSIndexSet* indexes = [NSIndexSet indexSetWithIndex:index];
    [self willChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:@"manualNotificationArray"];
    [_manualNotificationArray removeObjectAtIndex:index];
    [self didChange:NSKeyValueChangeRemoval valuesAtIndexes:indexes forKey:@"manualNotificationArray"];
}

- (void)insertObject:(NSObject*)object inArrayWithHelpersAtIndex:(NSUInteger)index {
    [_arrayWithHelpers insertObject:object atIndex:index];
}

- (void)removeObjectFromArrayWithHelpersAtIndex:(NSUInteger)index {
    [_arrayWithHelpers removeObjectAtIndex:index];
}

- (void)addSetWithHelpersObject:(id)obj {
    [_setWithHelpers addObject:obj];
}

- (void)removeSetWithHelpersObject:(id)obj {
    [_setWithHelpers removeObject:obj];
}

- (void)addSetWithHelpers:(NSSet*)set {
    [_setWithHelpers unionSet:set];
}

- (void)removeSetWithHelpers:(NSSet*)set {
    [_setWithHelpers minusSet:set];
}

- (void)intersectSetWithHelpers:(NSSet*)set {
    [_setWithHelpers intersectSet:set];
}

- (void)setSetWithHelpers:(NSSet*)set {
    [_setWithHelpers setSet:set];
}

- (void)manualSetAddObject:(id)obj {
    NSSet* set = [NSSet setWithObject:obj];
    [self willChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueUnionSetMutation usingObjects:set];
    [_manualNotificationSet addObject:obj];
    [self didChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueUnionSetMutation usingObjects:set];
}

- (void)manualSetRemoveObject:(id)obj {
    NSSet* set = [NSSet setWithObject:obj];
    [self willChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueMinusSetMutation usingObjects:set];
    [_manualNotificationSet removeObject:obj];
    [self didChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueMinusSetMutation usingObjects:set];
}

- (void)manualUnionSet:(NSSet*)set {
    [self willChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueUnionSetMutation usingObjects:set];
    [_manualNotificationSet unionSet:set];
    [self didChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueUnionSetMutation usingObjects:set];
}

- (void)manualMinusSet:(NSSet*)set {
    [self willChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueMinusSetMutation usingObjects:set];
    [_manualNotificationSet minusSet:set];
    [self didChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueMinusSetMutation usingObjects:set];
}

- (void)manualIntersectSet:(NSSet*)set {
    [self willChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueIntersectSetMutation usingObjects:set];
    [_manualNotificationSet intersectSet:set];
    [self didChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueIntersectSetMutation usingObjects:set];
}

- (void)manualSetSet:(NSSet*)set {
    [self willChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueSetSetMutation usingObjects:set];
    [_manualNotificationSet setSet:set];
    [self didChangeValueForKey:@"manualNotificationSet" withSetMutation:NSKeyValueSetSetMutation usingObjects:set];
}

@end

@interface _NSFoundationTestKVOObserver () {
    StrongId<NSArray<void (^)(NSString*, id, NSDictionary*, void*)>> _callbacks;
    NSUInteger _callbackIndex;
}
@end

@implementation _NSFoundationTestKVOObserver
- (void)performBlock:(void (^)())block andExpectChangeCallbacks:(NSArray<void (^)(NSString*, id, NSDictionary*, void*)>*)callbacks {
    _hits = 0;
    _callbackIndex = 0;
    _callbacks.attach([callbacks copy]);
    block();
}

- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)change context:(void*)context {
    if ([_callbacks count] > 0) {
        auto x = [_callbacks objectAtIndex:_callbackIndex];
        if (_callbackIndex++ == [_callbacks count]) {
            _callbackIndex = 0;
        }
        x(keyPath, object, change, context);
    }
    _hits++;
}
@end

@interface _NSFoundationTestKVOFacade () {
    StrongId<NSObject> _observee;
    StrongId<_NSFoundationTestKVOObserver> _observer;
}
@end

@implementation _NSFoundationTestKVOFacade
+ (instancetype)newWithObservee:(id)observee {
    return [[self alloc] initWithObservee:observee];
}

- (instancetype)initWithObservee:(id)observee {
    if (self = [super init]) {
        _observee = observee;
        _observer.attach([_NSFoundationTestKVOObserver new]);
    }
    return self;
}

- (id)observer {
    return _observer;
}

- (void)performBlock:(void (^)(id))block andExpectChangeCallbacks:(NSArray<void (^)(NSString*, id, NSDictionary*, void*)>*)callbacks {
    @try {
        [_observer performBlock:^{
            block(_observee);
        }
            andExpectChangeCallbacks:callbacks];
    } @catch (NSException* e) {
        ADD_FAILURE();
    }
}

- (void)observeKeyPath:(NSString*)keyPath
                 withOptions:(NSKeyValueObservingOptions)options
             performingBlock:(void (^)(id))block
    andExpectChangeCallbacks:(NSArray<void (^)(NSString*, id, NSDictionary*, void*)>*)callbacks {
    [self performBlock:^(TEST_IDENT(Observee) * observee) {
        [observee addObserver:_observer forKeyPath:keyPath options:options context:nullptr];
        @try {
            block(observee);
        } @finally {
            [observee removeObserver:_observer forKeyPath:keyPath];
        }
    }
        andExpectChangeCallbacks:callbacks];
}

- (NSUInteger)hits {
    return [_observer hits];
}
@end

#define PERFORM ^(TEST_IDENT(Observee) * observee)
#define CHANGE_CB ^(NSString * keyPath, id object, NSDictionary * change, void* context)
#pragma endregion

TEST(KVO, ToMany_NoNotificationOnBareArray) {
    _NSFoundationTestKVOFacade* facade = [[_NSFoundationTestKVOFacade newWithObservee:[TEST_IDENT(Observee) observee]] autorelease];
    [facade observeKeyPath:@"bareArray"
                     withOptions:0
                 performingBlock:PERFORM { [observee addObjectToBareArray:@"hello"]; }
        andExpectChangeCallbacks:@[ CHANGE_CB {
            // Any notification here is illegal.
            ADD_FAILURE();
        } ]];
    EXPECT_EQ(0, facade.hits);
}

TEST(KVO, ToMany_ManuallyNotifyingArray) {
    auto firstInsertCallback = CHANGE_CB {
        // We should get an add on index 0 of "object1"
        EXPECT_OBJCEQ(@(NSKeyValueChangeInsertion), change[NSKeyValueChangeKindKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCNE(nil, indexes);
        EXPECT_EQ(0, [indexes firstIndex]);
        if (![change[NSKeyValueChangeNotificationIsPriorKey] boolValue]) {
            EXPECT_OBJCEQ(@"object1", [change[NSKeyValueChangeNewKey] objectAtIndex:0]);
        }
    };
    auto secondInsertCallback = CHANGE_CB {
        // We should get an add on index 1 of "object2"
        EXPECT_OBJCEQ(@(NSKeyValueChangeInsertion), change[NSKeyValueChangeKindKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCNE(nil, indexes);
        EXPECT_EQ(1, [indexes firstIndex]);
        if (![change[NSKeyValueChangeNotificationIsPriorKey] boolValue]) {
            EXPECT_OBJCEQ(@"object2", [change[NSKeyValueChangeNewKey] objectAtIndex:0]);
        }
    };
    auto removalCallback = CHANGE_CB {
        // Expect that we get a removal on index 0 of object "object1".
        EXPECT_OBJCEQ(@(NSKeyValueChangeRemoval), change[NSKeyValueChangeKindKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCNE(nil, indexes);
        EXPECT_EQ(0, [indexes firstIndex]);
        if ([change[NSKeyValueChangeNotificationIsPriorKey] boolValue]) {
            EXPECT_OBJCEQ(@"object1", [change[NSKeyValueChangeOldKey] objectAtIndex:0]);
        }
    };
    auto illegalChangeNotification = CHANGE_CB {
        ADD_FAILURE();
    };

    _NSFoundationTestKVOFacade* facade = [[_NSFoundationTestKVOFacade newWithObservee:[TEST_IDENT(Observee) observee]] autorelease];
    // This test expects one change for each key; any more than that is a failure.
    [facade observeKeyPath:@"manualNotificationArray"
                     withOptions:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew
                 performingBlock:PERFORM {
                     [observee addObjectToManualArray:@"object1"];
                     [observee addObjectToManualArray:@"object2"];
                     [observee removeObjectFromManualArrayIndex:0];
                 }
        andExpectChangeCallbacks:@[ firstInsertCallback, secondInsertCallback, removalCallback, illegalChangeNotification ]];
    EXPECT_EQ(3, facade.hits);

    facade = [[_NSFoundationTestKVOFacade newWithObservee:[TEST_IDENT(Observee) observee]] autorelease];
    // This test expects two change notifications for each key; any more than that is a failure.
    [facade observeKeyPath:@"manualNotificationArray"
                     withOptions:NSKeyValueObservingOptionPrior | NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew
                 performingBlock:PERFORM {
                     [observee addObjectToManualArray:@"object1"];
                     [observee addObjectToManualArray:@"object2"];
                     [observee removeObjectFromManualArrayIndex:0];
                 }
        andExpectChangeCallbacks:@[
            firstInsertCallback,
            firstInsertCallback,
            secondInsertCallback,
            secondInsertCallback,
            removalCallback,
            removalCallback,
            illegalChangeNotification
        ]];
    EXPECT_EQ(6, facade.hits);

    // This test expects one change notification: the initial one. Any more than that is a failure.
    [facade observeKeyPath:@"manualNotificationArray"
                     withOptions:NSKeyValueObservingOptionInitial | NSKeyValueObservingOptionNew
                 performingBlock:PERFORM {}
        andExpectChangeCallbacks:@[
            CHANGE_CB {
                // Based on the previous test, we expect only object2 to remain.
                NSArray* expectedArray = @[ @"object2" ];
                EXPECT_OBJCEQ(expectedArray, change[NSKeyValueChangeNewKey]);
            },
            illegalChangeNotification
        ]];
    EXPECT_EQ(1, facade.hits);
}

TEST(KVO, ToMany_KVCMediatedMutableArray) {
    auto firstInsertCallback = CHANGE_CB {
        // We should get an add on index 0 of "object1"
        EXPECT_OBJCEQ(@(NSKeyValueChangeInsertion), change[NSKeyValueChangeKindKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCNE(nil, indexes);
        EXPECT_EQ(0, [indexes firstIndex]);
        if (![change[NSKeyValueChangeNotificationIsPriorKey] boolValue]) {
            EXPECT_OBJCEQ(@"object1", [change[NSKeyValueChangeNewKey] objectAtIndex:0]);
        }
    };
    auto secondInsertCallback = CHANGE_CB {
        // We should get an add on index 1 of "object2"
        EXPECT_OBJCEQ(@(NSKeyValueChangeInsertion), change[NSKeyValueChangeKindKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCNE(nil, indexes);
        EXPECT_EQ(1, [indexes firstIndex]);
        if (![change[NSKeyValueChangeNotificationIsPriorKey] boolValue]) {
            EXPECT_OBJCEQ(@"object2", [change[NSKeyValueChangeNewKey] objectAtIndex:0]);
        }
    };
    auto removalCallback = CHANGE_CB {
        // Expect that we get a removal on index 0 of object "object1".
        EXPECT_OBJCEQ(@(NSKeyValueChangeRemoval), change[NSKeyValueChangeKindKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCNE(nil, indexes);
        EXPECT_EQ(0, [indexes firstIndex]);
        if ([change[NSKeyValueChangeNotificationIsPriorKey] boolValue]) {
            EXPECT_OBJCEQ(@"object1", [change[NSKeyValueChangeOldKey] objectAtIndex:0]);
        }
    };
    auto illegalChangeNotification = CHANGE_CB {
        ADD_FAILURE();
    };

    _NSFoundationTestKVOFacade* facade = [[_NSFoundationTestKVOFacade newWithObservee:[TEST_IDENT(Observee) observee]] autorelease];
    // This test expects one change for each key; any more than that is a failure.
    [facade observeKeyPath:@"kvcMediatedArray"
                     withOptions:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew
                 performingBlock:PERFORM {
                     // This array is not assisted with setter functions and should go through the get/mutate/set codepath.
                     NSMutableArray* mediatedVersionOfArray = [observee mutableArrayValueForKey:@"kvcMediatedArray"];
                     [mediatedVersionOfArray addObject:@"object1"];
                     [mediatedVersionOfArray addObject:@"object2"];
                     [mediatedVersionOfArray removeObjectAtIndex:0];
                 }
        andExpectChangeCallbacks:@[ firstInsertCallback, secondInsertCallback, removalCallback, illegalChangeNotification ]];
    EXPECT_EQ(3, facade.hits);
}

TEST(KVO, ToMany_KVCMediatedArrayWithHelpers) {
    auto firstInsertCallback = CHANGE_CB {
        // We should get an add on index 0 of "object1"
        EXPECT_OBJCEQ(@(NSKeyValueChangeInsertion), change[NSKeyValueChangeKindKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCNE(nil, indexes);
        EXPECT_EQ(0, [indexes firstIndex]);
        if (![change[NSKeyValueChangeNotificationIsPriorKey] boolValue]) {
            EXPECT_OBJCEQ(@"object1", [change[NSKeyValueChangeNewKey] objectAtIndex:0]);
        }
    };
    auto secondInsertCallback = CHANGE_CB {
        // We should get an add on index 1 of "object2"
        EXPECT_OBJCEQ(@(NSKeyValueChangeInsertion), change[NSKeyValueChangeKindKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCNE(nil, indexes);
        EXPECT_EQ(1, [indexes firstIndex]);
        if (![change[NSKeyValueChangeNotificationIsPriorKey] boolValue]) {
            EXPECT_OBJCEQ(@"object2", [change[NSKeyValueChangeNewKey] objectAtIndex:0]);
        }
    };
    auto removalCallback = CHANGE_CB {
        // Expect that we get a removal on index 0 of object "object1".
        EXPECT_OBJCEQ(@(NSKeyValueChangeRemoval), change[NSKeyValueChangeKindKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCNE(nil, indexes);
        EXPECT_EQ(0, [indexes firstIndex]);
        if ([change[NSKeyValueChangeNotificationIsPriorKey] boolValue]) {
            EXPECT_OBJCEQ(@"object1", [change[NSKeyValueChangeOldKey] objectAtIndex:0]);
        }
    };
    auto illegalChangeNotification = CHANGE_CB {
        ADD_FAILURE();
    };

    _NSFoundationTestKVOFacade* facade = [[_NSFoundationTestKVOFacade newWithObservee:[TEST_IDENT(Observee) observee]] autorelease];
    [facade observeKeyPath:@"arrayWithHelpers"
                     withOptions:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew
                 performingBlock:PERFORM {
                     // This array is assisted by setter functions, and should also dispatch one notification per change.
                     NSMutableArray* mediatedVersionOfArray = [observee mutableArrayValueForKey:@"arrayWithHelpers"];
                     [mediatedVersionOfArray addObject:@"object1"];
                     [mediatedVersionOfArray addObject:@"object2"];
                     [mediatedVersionOfArray removeObjectAtIndex:0];
                 }
        andExpectChangeCallbacks:@[ firstInsertCallback, secondInsertCallback, removalCallback, illegalChangeNotification ]];
    EXPECT_EQ(3, facade.hits);

    facade = [[_NSFoundationTestKVOFacade newWithObservee:[TEST_IDENT(Observee) observee]] autorelease];
    // In this test, we use the same arrayWithHelpers as above, but interact with it manually.
    [facade observeKeyPath:@"arrayWithHelpers"
                     withOptions:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew
                 performingBlock:PERFORM {
                     // This array is assisted by setter functions, and should also dispatch one notification per change.
                     [observee insertObject:@"object1" inArrayWithHelpersAtIndex:0];
                     [observee insertObject:@"object2" inArrayWithHelpersAtIndex:1];
                     [observee removeObjectFromArrayWithHelpersAtIndex:0];
                 }
        andExpectChangeCallbacks:@[ firstInsertCallback, secondInsertCallback, removalCallback, illegalChangeNotification ]];
    EXPECT_EQ(3, facade.hits);
}

TEST(KVO, ToMany_KVCMediatedArrayWithHelpers_AggregateFunction) {
    auto insertCallbackPost = CHANGE_CB {
        EXPECT_OBJCEQ(nil, change[NSKeyValueChangeNotificationIsPriorKey]);
        EXPECT_OBJCEQ(@(NSKeyValueChangeSetting), change[NSKeyValueChangeKindKey]);
        EXPECT_OBJCEQ(@(0), change[NSKeyValueChangeOldKey]);
        EXPECT_OBJCEQ(@(1), change[NSKeyValueChangeNewKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCEQ(nil, indexes);
    };
    auto illegalChangeNotification = CHANGE_CB {
        ADD_FAILURE();
    };

    _NSFoundationTestKVOFacade* facade = [[_NSFoundationTestKVOFacade newWithObservee:[TEST_IDENT(Observee) observee]] autorelease];
    [facade observeKeyPath:@"arrayWithHelpers.@count"
                     withOptions:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew
                 performingBlock:PERFORM {
                     // This array is assisted by setter functions, and should also dispatch one notification per change.
                     NSMutableArray* mediatedVersionOfArray = [observee mutableArrayValueForKey:@"arrayWithHelpers"];
                     [mediatedVersionOfArray addObject:@"object1"];
                 }
        andExpectChangeCallbacks:@[ insertCallbackPost, illegalChangeNotification ]];
    EXPECT_EQ(1, facade.hits);

    facade = [[_NSFoundationTestKVOFacade newWithObservee:[TEST_IDENT(Observee) observee]] autorelease];
    // In this test, we use the same arrayWithHelpers as above, but interact with it manually.
    [facade observeKeyPath:@"arrayWithHelpers.@count"
                     withOptions:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew
                 performingBlock:PERFORM {
                     // This array is assisted by setter functions, and should also dispatch one notification per change.
                     [observee insertObject:@"object1" inArrayWithHelpersAtIndex:0];
                 }
        andExpectChangeCallbacks:@[ insertCallbackPost, illegalChangeNotification ]];
    EXPECT_EQ(1, facade.hits);
}

@interface DummyObject : NSObject
@property (nonatomic, copy) NSString* name;
@property (nonatomic, retain) DummyObject* sub;
@end

@implementation DummyObject
+ (instancetype)makeDummy {
    DummyObject* ret = [[DummyObject new] autorelease];
    ret.name = @"Value";
    return ret;
}

- (void)dealloc {
    [_name release];
    [_sub release];
    [super dealloc];
}

@end

// Reference platform adds observers slightly differently so this test will not pass
OSX_DISABLED_TEST(KVO, ToMany_ToOne_ShouldDowngradeForOrderedObservation) {
    TEST_IDENT(Observee)* observee = [TEST_IDENT(Observee) observee];
    [observee insertObject:[DummyObject makeDummy] inArrayWithHelpersAtIndex:0];

    auto insertCallbackPost = CHANGE_CB {
        EXPECT_OBJCEQ(nil, change[NSKeyValueChangeNotificationIsPriorKey]);
        EXPECT_OBJCEQ(@(NSKeyValueChangeSetting), change[NSKeyValueChangeKindKey]);
        NSArray* expectedOld = @[ @"Value" ];
        EXPECT_OBJCEQ(expectedOld, change[NSKeyValueChangeOldKey]);
        NSArray* expectedNew = @[ @"Value", @"Value" ];
        EXPECT_OBJCEQ(expectedNew, change[NSKeyValueChangeNewKey]);
        NSIndexSet* indexes = change[NSKeyValueChangeIndexesKey];
        EXPECT_OBJCEQ(nil, indexes);
    };
    auto illegalChangeNotification = CHANGE_CB {
        ADD_FAILURE();
    };

    _NSFoundationTestKVOFacade* facade = [[_NSFoundationTestKVOFacade newWithObservee:observee] autorelease];
    // In this test, we use the same arrayWithHelpers as above, but interact with it manually.
    [facade observeKeyPath:@"arrayWithHelpers.name"
                     withOptions:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew
                 performingBlock:PERFORM {
                     // This array is assisted by setter functions, and should also dispatch one notification per change.
                     [observee insertObject:[DummyObject makeDummy] inArrayWithHelpersAtIndex:0];
                 }
        andExpectChangeCallbacks:@[ insertCallbackPost, illegalChangeNotification ]];
    EXPECT_EQ(1, facade.hits);
}

TEST(KVO, ObserverInformationShouldNotLeak) {
    auto onlyNewCallback = CHANGE_CB {
        EXPECT_NE(nil, change[NSKeyValueChangeNewKey]);
        EXPECT_EQ(nil, change[NSKeyValueChangeOldKey]);
    };

    auto illegalChangeNotification = CHANGE_CB {
        ADD_FAILURE();
    };

    TEST_IDENT(Observee)* observee = [TEST_IDENT(Observee) observee];
    _NSFoundationTestKVOFacade* firstFacade = [[_NSFoundationTestKVOFacade newWithObservee:observee] autorelease];
    [observee addObserver:firstFacade.observer
               forKeyPath:@"manualNotificationArray"
                  options:(NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew)
                  context:nullptr];
    _NSFoundationTestKVOFacade* facade = [[_NSFoundationTestKVOFacade newWithObservee:observee] autorelease];
    [facade observeKeyPath:@"manualNotificationArray"
                     withOptions:NSKeyValueObservingOptionNew
                 performingBlock:PERFORM { [observee addObjectToManualArray:@"object1"]; }
        andExpectChangeCallbacks:@[ onlyNewCallback, illegalChangeNotification ]];
    [observee removeObserver:firstFacade.observer forKeyPath:@"manualNotificationArray"];

    EXPECT_EQ(1, facade.hits);
}

TEST(KVO, NSArrayShouldNotBeObservable) {
    NSArray* test = @[ @1, @2, @3 ];
    _NSFoundationTestKVOObserver* observer = [[_NSFoundationTestKVOObserver new] autorelease];
    EXPECT_ANY_THROW([test addObserver:observer forKeyPath:@"count" options:0 context:nullptr]);

    // These would throw anyways because there should be no observer for the key path, but test anyways
    EXPECT_ANY_THROW([test removeObserver:observer forKeyPath:@"count"]);
    EXPECT_ANY_THROW([test removeObserver:observer forKeyPath:@"count" context:nullptr]);
}

TEST(KVO, NSArrayShouldThrowWhenTryingToObserveIndexesOutOfRange) {
    NSArray* test = @[ [[TEST_IDENT(Observee) new] autorelease], [[TEST_IDENT(Observee) new] autorelease] ];
    _NSFoundationTestKVOObserver* observer = [[_NSFoundationTestKVOObserver new] autorelease];
    EXPECT_ANY_THROW(
        [test addObserver:observer toObjectsAtIndexes:[NSIndexSet indexSetWithIndex:4] forKeyPath:@"bareArray" options:0 context:nullptr]);
}

TEST(KVO, NSArrayObserveElements) {
    NSArray* observeeArray =
        @[ [[TEST_IDENT(Observee) new] autorelease], [[TEST_IDENT(Observee) new] autorelease], [[TEST_IDENT(Observee) new] autorelease] ];
    _NSFoundationTestKVOObserver* observer = [[_NSFoundationTestKVOObserver new] autorelease];
    EXPECT_NO_THROW([observeeArray addObserver:observer
                            toObjectsAtIndexes:[NSIndexSet indexSetWithIndexesInRange:NSMakeRange(0, 2)]
                                    forKeyPath:@"manualNotificationArray"
                                       options:(NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew)
                                       context:nullptr]);

    // First two elements in range for observation so observer will receive changes
    [observeeArray[0] addObjectToManualArray:@"object1"];
    [observeeArray[0] addObjectToManualArray:@"object2"];
    EXPECT_EQ(2, observer.hits);

    [observeeArray[1] addObjectToManualArray:@"object1"];
    EXPECT_EQ(3, observer.hits);

    // But the third element is not so observer will not receive changes
    [observeeArray[2] addObjectToManualArray:@"object1"];
    EXPECT_EQ(3, observer.hits);

    EXPECT_NO_THROW([observeeArray removeObserver:observer
                             fromObjectsAtIndexes:[NSIndexSet indexSetWithIndexesInRange:NSMakeRange(0, 1)]
                                       forKeyPath:@"manualNotificationArray"]);

    // Removed observer from first element, so modifying it will not report a change
    [observeeArray[0] addObjectToManualArray:@"object3"];
    EXPECT_EQ(3, observer.hits);

    // But the second element is still being observed
    [observeeArray[1] addObjectToManualArray:@"object2"];
    EXPECT_EQ(4, observer.hits);

    EXPECT_NO_THROW([observeeArray removeObserver:observer
                             fromObjectsAtIndexes:[NSIndexSet indexSetWithIndexesInRange:NSMakeRange(1, 1)]
                                       forKeyPath:@"manualNotificationArray"]);

    [observeeArray[1] addObjectToManualArray:@"object3"];
    EXPECT_EQ(4, observer.hits);
}

TEST(KVO, NSSetShouldNotBeObservable) {
    NSSet* test = [NSSet setWithObjects:@1, @2, @3, nil];
    _NSFoundationTestKVOObserver* observer = [[_NSFoundationTestKVOObserver new] autorelease];
    EXPECT_ANY_THROW([test addObserver:observer forKeyPath:@"count" options:0 context:nullptr]);

    // These would throw anyways because there should be no observer for the key path, but test anyways
    EXPECT_ANY_THROW([test removeObserver:observer forKeyPath:@"count"]);
    EXPECT_ANY_THROW([test removeObserver:observer forKeyPath:@"count" context:nullptr]);
}

static void __testSetMutationMethods(NSString* keypath, bool setSetChanged, void (^callback)(id)) {
    auto unionCallback = CHANGE_CB {
        // Union with @({@1, @2, @3}) to get @({@1, @2, @3})
        EXPECT_OBJCEQ(@(NSKeyValueChangeInsertion), change[NSKeyValueChangeKindKey]);
        NSSet* expected = [NSSet setWithObjects:@1, @2, @3, nil];
        EXPECT_OBJCEQ(expected, change[NSKeyValueChangeNewKey]);
        EXPECT_EQ(nil, change[NSKeyValueChangeOldKey]);
    };

    auto minusCallback = CHANGE_CB {
        // Minus with @({@1}) to get @({@2, @3})
        EXPECT_OBJCEQ(@(NSKeyValueChangeRemoval), change[NSKeyValueChangeKindKey]);
        EXPECT_OBJCEQ([NSSet setWithObject:@1], change[NSKeyValueChangeOldKey]);
        EXPECT_EQ(nil, change[NSKeyValueChangeNewKey]);
    };

    auto addCallback = CHANGE_CB {
        // Add @1 to @({@2, @3}) to get @({@1, @2, @3})
        EXPECT_OBJCEQ(@(NSKeyValueChangeInsertion), change[NSKeyValueChangeKindKey]);
        EXPECT_OBJCEQ([NSSet setWithObject:@1], change[NSKeyValueChangeNewKey]);
        EXPECT_EQ(nil, change[NSKeyValueChangeOldKey]);
    };

    auto removeCallback = CHANGE_CB {
        // Remove @1 from @({@1, @2, @3}) to get @({@2, @3})
        EXPECT_OBJCEQ(@(NSKeyValueChangeRemoval), change[NSKeyValueChangeKindKey]);
        EXPECT_OBJCEQ([NSSet setWithObject:@1], change[NSKeyValueChangeOldKey]);
        EXPECT_EQ(nil, change[NSKeyValueChangeNewKey]);
    };

    auto intersectCallback = CHANGE_CB {
        // Intersect with @({@2}) to get @({2})
        EXPECT_OBJCEQ(@(NSKeyValueChangeRemoval), change[NSKeyValueChangeKindKey]);
        NSSet* expected = [NSSet setWithObject:@3];
        EXPECT_OBJCEQ(expected, change[NSKeyValueChangeOldKey]);
        EXPECT_EQ(nil, change[NSKeyValueChangeNewKey]);
    };

    auto setCallback = CHANGE_CB {
        // Set with @({@3}) to get @({@3})
        if (setSetChanged) {
            EXPECT_OBJCEQ(@(NSKeyValueChangeReplacement), change[NSKeyValueChangeKindKey]);
            EXPECT_OBJCEQ([NSSet setWithObject:@2], change[NSKeyValueChangeOldKey]);
            EXPECT_OBJCEQ([NSSet setWithObject:@3], change[NSKeyValueChangeNewKey]);
        } else {
            // setXxx method is not automatically swizzled for observation
            EXPECT_OBJCEQ(@(NSKeyValueChangeSetting), change[NSKeyValueChangeKindKey]);
            EXPECT_OBJCEQ([NSSet setWithObject:@3], change[NSKeyValueChangeOldKey]);
            EXPECT_OBJCEQ([NSSet setWithObject:@3], change[NSKeyValueChangeNewKey]);
        }
    };

    auto illegalChangeNotification = CHANGE_CB {
        ADD_FAILURE();
    };

    _NSFoundationTestKVOFacade* facade = [[_NSFoundationTestKVOFacade newWithObservee:[TEST_IDENT(Observee) observee]] autorelease];
    [facade observeKeyPath:keypath
                     withOptions:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld
                 performingBlock:callback
        andExpectChangeCallbacks:
            @[ unionCallback, minusCallback, addCallback, removeCallback, intersectCallback, setCallback, illegalChangeNotification ]];
    EXPECT_EQ(6, facade.hits);
}

// Reference platform does not perform as expected with set mutation methods so we've opted for consistency
// The following two tests are disabled on reference platform but ensure no regressions in the future
TEST(KVO, SetMutationMethods_Helpers) {
    __testSetMutationMethods(@"setWithHelpers", false, PERFORM {
        // This set is assisted by setter functions, and should also dispatch one notification per change.
        [observee addSetWithHelpers:[NSSet setWithObjects:@1, @2, @3, nil]];
        [observee removeSetWithHelpers:[NSSet setWithObject:@1]];
        [observee addSetWithHelpersObject:@1];
        [observee removeSetWithHelpersObject:@1];
        [observee intersectSetWithHelpers:[NSSet setWithObject:@2]];
        [observee setSetWithHelpers:[NSSet setWithObject:@3]];
    });
}

TEST(KVO, SetMutationMethods_Proxy) {
    __testSetMutationMethods(@"kvcMediatedSet", true, PERFORM {
        // Proxy mutable set should dispatch one notification per change
        NSMutableSet* proxySet = [observee mutableSetValueForKey:@"kvcMediatedSet"];
        [proxySet unionSet:[NSSet setWithObjects:@1, @2, @3, nil]];
        [proxySet minusSet:[NSSet setWithObject:@1]];
        [proxySet addObject:@1];
        [proxySet removeObject:@1];
        [proxySet intersectSet:[NSSet setWithObject:@2]];
        [proxySet setSet:[NSSet setWithObject:@3]];
    });
}

TEST(KVO, SetMutationMethods_Manual) {
    __testSetMutationMethods(@"manualNotificationSet", true, PERFORM {
        // Manually should dispatch one notification per change
        [observee manualUnionSet:[NSSet setWithObjects:@1, @2, @3, nil]];
        [observee manualMinusSet:[NSSet setWithObject:@1]];
        [observee manualSetAddObject:@1];
        [observee manualSetRemoveObject:@1];
        [observee manualIntersectSet:[NSSet setWithObject:@2]];
        [observee manualSetSet:[NSSet setWithObject:@3]];
    });
}
