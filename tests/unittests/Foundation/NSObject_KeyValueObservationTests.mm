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

#import <Foundation/Foundation.h>
#import <Starboard/SmartTypes.h>
#include <TestFramework.h>

#pragma region Helper Classes
#define TEST_PREFIX Foundation_NSObject_KVO_Tests
#define _CONCAT(x, y) x##y
#define CONCAT(x, y) _CONCAT(x, y)
#define TEST_IDENT(x) CONCAT(TEST_PREFIX, _##x)

@interface TEST_IDENT (Observee): NSObject {
    NSMutableArray* _bareArray;
    NSMutableArray* _manualNotificationArray;
    NSMutableArray* _kvcMediatedArray;
    NSMutableArray* _arrayWithHelpers;
}
@end

@implementation TEST_IDENT (Observee)
- (instancetype)init {
    if (self = [super init]) {
        _bareArray = [NSMutableArray new];
        _manualNotificationArray = [NSMutableArray new];
        _kvcMediatedArray = [NSMutableArray new];
        _arrayWithHelpers = [NSMutableArray new];
    }
    return self;
}

- (void)dealloc {
    [_bareArray release];
    [_manualNotificationArray release];
    [_kvcMediatedArray release];
    [_arrayWithHelpers release];
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
@end

@interface TEST_IDENT (Observer): NSObject {
    StrongId<NSArray<void (^)(NSString*, id, NSDictionary*, void*)>> _callbacks;
    NSUInteger _callbackIndex;
}
@property (nonatomic, assign, readonly) NSUInteger hits;
// performBlock:andExpectChangeCallbacks: will call the blocks in 'callbacks', sequentially, giving each one
// a single observation callback.
- (void)performBlock:(void (^)())block andExpectChangeCallbacks:(NSArray<void (^)(NSString*, id, NSDictionary*, void*)>*)callbacks;
@end

@implementation TEST_IDENT (Observer)
- (void)performBlock:(void (^)())block andExpectChangeCallbacks:(NSArray<void (^)(NSString*, id, NSDictionary*, void*)>*)callbacks {
    _hits = 0;
    _callbackIndex = 0;
    _callbacks.attach([callbacks copy]);
    block();
}

- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)change context:(void*)context {
    auto x = [_callbacks objectAtIndex:_callbackIndex];
    if (_callbackIndex++ == [_callbacks count]) {
        _callbackIndex = 0;
    }
    x(keyPath, object, change, context);
    _hits++;
}
@end

@interface TEST_IDENT (Facade): NSObject {
    StrongId<TEST_IDENT(Observee)> _observee;
    StrongId<TEST_IDENT(Observer)> _observer;
}
@property (nonatomic, assign, readonly) NSUInteger hits;
- (void)performBlock:(void (^)(TEST_IDENT(Observee)*, TEST_IDENT(Observer)*))block
    andExpectChangeCallbacks:(NSArray<void (^)(NSString*, id, NSDictionary*, void*)>*)callbacks;
@end

@implementation TEST_IDENT (Facade)
- (instancetype)init {
    if (self = [super init]) {
        _observee.attach([TEST_IDENT(Observee) new]);
        _observer.attach([TEST_IDENT(Observer) new]);
    }
    return self;
}
- (void)performBlock:(void (^)(TEST_IDENT(Observee)*, TEST_IDENT(Observer)*))block
    andExpectChangeCallbacks:(NSArray<void (^)(NSString*, id, NSDictionary*, void*)>*)callbacks {
    @try {
        [_observer performBlock:^{
            block(_observee, _observer);
        }
            andExpectChangeCallbacks:callbacks];
    } @catch (NSException* e) {
        ADD_FAILURE();
    }
}
- (void)observeKeyPath:(NSString*)keyPath
                 withOptions:(NSKeyValueObservingOptions)options
             performingBlock:(void (^)(TEST_IDENT(Observee)*, TEST_IDENT(Observer)*))block
    andExpectChangeCallbacks:(NSArray<void (^)(NSString*, id, NSDictionary*, void*)>*)callbacks {
    [self performBlock:^(TEST_IDENT(Observee) * observee, TEST_IDENT(Observer) * observer) {
        [observee addObserver:observer forKeyPath:keyPath options:options context:nullptr];
        @try {
            block(observee, observer);
        } @finally {
            [observee removeObserver:observer forKeyPath:keyPath];
        }
    }
        andExpectChangeCallbacks:callbacks];
}

- (NSUInteger)hits {
    return [_observer hits];
}
@end

#define PERFORM ^(TEST_IDENT(Observee) * observee, TEST_IDENT(Observer) * observer)
#define CHANGE_CB ^(NSString * keyPath, id object, NSDictionary * change, void* context)
#pragma endregion

TEST(KVO, ToMany_NoNotificationOnBareArray) {
    TEST_IDENT(Facade)* facade = [[TEST_IDENT(Facade) new] autorelease];
    [facade observeKeyPath:@"bareArray"
                     withOptions:0
                 performingBlock:PERFORM { [observee addObjectToBareArray:@"hello"]; }
        andExpectChangeCallbacks:@[
            CHANGE_CB {
                // Any notification here is illegal.
                ADD_FAILURE();
            }
        ]];
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

    TEST_IDENT(Facade)* facade = [[TEST_IDENT(Facade) new] autorelease];
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

    facade = [[TEST_IDENT(Facade) new] autorelease];
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

    TEST_IDENT(Facade)* facade = [[TEST_IDENT(Facade) new] autorelease];
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

    TEST_IDENT(Facade)* facade = [[TEST_IDENT(Facade) new] autorelease];
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

    facade = [[TEST_IDENT(Facade) new] autorelease];
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

    TEST_IDENT(Facade)* facade = [[TEST_IDENT(Facade) new] autorelease];
    [facade observeKeyPath:@"arrayWithHelpers.@count"
                     withOptions:NSKeyValueObservingOptionOld | NSKeyValueObservingOptionNew
                 performingBlock:PERFORM {
                     // This array is assisted by setter functions, and should also dispatch one notification per change.
                     NSMutableArray* mediatedVersionOfArray = [observee mutableArrayValueForKey:@"arrayWithHelpers"];
                     [mediatedVersionOfArray addObject:@"object1"];
                 }
        andExpectChangeCallbacks:@[ insertCallbackPost, illegalChangeNotification ]];
    EXPECT_EQ(1, facade.hits);

    facade = [[TEST_IDENT(Facade) new] autorelease];
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