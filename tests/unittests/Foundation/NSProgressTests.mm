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
// floating
//******************************************************************************

#import <Foundation/Foundation.h>
#import <TestFramework.h>
#import <thread>

#import "TestUtils.h"

static const double c_errorMargin = 0.000001;

static const uint64_t work1pendingUnitCount = 2;
static const uint64_t work2pendingUnitCount = 30;

// Helper class for responding to selectors, so that work can be done on separate NSThreads
@interface ProgressThreadHelper : NSObject
// Basic work
- (void)work1:(NSProgress*)parent;
- (void)work2:(NSProgress*)parent;

// Creates an NSProgress that becomes current, resigns current, and validates that current is null again
- (void)becomeResignCheckCurrent:(NSObject*)shouldBeNil;
// Same as above, but assigns that NSProgress to be a child
- (void)becomeResignCheckCurrentWithChild:(NSProgress*)parent;
@property BOOL currentIsCorrect;

- (void)addParentTo:(NSProgress*)child;
@property BOOL exceptionWasCaught;
@end

@implementation ProgressThreadHelper

- (void)_workImpl:(NSProgress*)parent pendingUnitCount:(int64_t)pendingUnitCount {
    [parent becomeCurrentWithPendingUnitCount:pendingUnitCount];
    NSProgress* child = [NSProgress progressWithTotalUnitCount:10];
    [child setCompletedUnitCount:10];
    [parent resignCurrent];
}

- (void)work1:(NSProgress*)parent {
    [self _workImpl:parent pendingUnitCount:work1pendingUnitCount];
}

- (void)work2:(NSProgress*)parent {
    [self _workImpl:parent pendingUnitCount:work2pendingUnitCount];
}

- (void)_becomeResignCheckCurrentImpl:(NSProgress*)newProgress {
    // Since stack is thread_local, currentProgress ought to be null at the start of a thread
    if ([NSProgress currentProgress]) {
        return;
    }

    [newProgress becomeCurrentWithPendingUnitCount:[newProgress totalUnitCount]];
    if (![newProgress isEqual:[NSProgress currentProgress]]) {
        return;
    }

    [newProgress setCompletedUnitCount:[newProgress totalUnitCount]];
    // Create a child here so as to not trigger the automatic resignCurrent effect
    [NSProgress progressWithTotalUnitCount:1];
    [newProgress resignCurrent];

    // Ought to have returned to null
    if ([NSProgress currentProgress]) {
        return;
    }

    _currentIsCorrect = YES;
}

- (void)becomeResignCheckCurrent:(NSObject*)shouldBeNil {
    [self _becomeResignCheckCurrentImpl:[NSProgress progressWithTotalUnitCount:10]];
}

- (void)becomeResignCheckCurrentWithChild:(NSProgress*)parent {
    NSProgress* child = [NSProgress progressWithTotalUnitCount:10];
    [parent addChild:child withPendingUnitCount:[parent totalUnitCount]];
    [self _becomeResignCheckCurrentImpl:child];
}

- (void)addParentTo:(NSProgress*)child {
    NSProgress* parent = [NSProgress progressWithTotalUnitCount:25235];
    @try {
        [parent addChild:child withPendingUnitCount:[parent totalUnitCount]];
    } @catch (NSException* exception) {
        _exceptionWasCaught = YES;
    }
}

@end

TEST(NSProgress, UserInfo) {
    // Nil userInfo as param
    NSProgress* nilUserInfo = [[[NSProgress alloc] initWithParent:nil userInfo:nil] autorelease];
    ASSERT_OBJCNE(nil, [nilUserInfo userInfo]);

    [nilUserInfo setUserInfoObject:@"value1" forKey:@"key1"];
    [nilUserInfo setUserInfoObject:@"value2" forKey:@"key2"];
    ASSERT_EQ(2, [[nilUserInfo userInfo] count]);

    // Pass in userInfo
    NSMutableDictionary* mutableDict = [[[NSMutableDictionary alloc] initWithDictionary:@{ @"key1" : @"value1" }] autorelease];
    NSProgress* actualUserInfo = [[[NSProgress alloc] initWithParent:nil userInfo:mutableDict] autorelease];
    ASSERT_OBJCEQ(mutableDict, [actualUserInfo userInfo]);

    // Make sure mutableDict was copied
    [mutableDict setObject:@"value2" forKey:@"key2"];
    ASSERT_EQ(1, [[actualUserInfo userInfo] count]);
}

TEST(NSProgress, FractionCompleted) {
    NSProgress* userInfo = [[[NSProgress alloc] initWithParent:nil userInfo:nil] autorelease];
    ASSERT_EQ(0, [userInfo totalUnitCount]);
    ASSERT_EQ(0, [userInfo completedUnitCount]);

    _NSFoundationTestKVOFacade* kvoListener = [[_NSFoundationTestKVOFacade newWithObservee:userInfo] autorelease];
    [kvoListener observeKeyPath:@"fractionCompleted"
                     withOptions:NSKeyValueObservingOptionNew
                 performingBlock:^(id userInfo) {
                     [userInfo setTotalUnitCount:2];
                     [userInfo setCompletedUnitCount:1];
                 }
        andExpectChangeCallbacks:nil];

    // Depending on OSX version, the implementation differs slightly, and changes the number of hits
    EXPECT_TRUE((kvoListener.hits == 1) || (kvoListener.hits == 2));

    ASSERT_EQ(0.5, [userInfo fractionCompleted]);
}

TEST(NSProgress, IsIndeterminate) {
    NSProgress* progress = [[[NSProgress alloc] initWithParent:nil userInfo:nil] autorelease];
    EXPECT_TRUE([progress isIndeterminate]);

    [progress setTotalUnitCount:5];
    EXPECT_FALSE([progress isIndeterminate]);

    [progress setCompletedUnitCount:5];
    EXPECT_FALSE([progress isIndeterminate]);

    [progress setTotalUnitCount:0];
    EXPECT_FALSE([progress isIndeterminate]);

    [progress setCompletedUnitCount:5];
    [progress setTotalUnitCount:1];
    EXPECT_FALSE([progress isIndeterminate]);

    [progress setCompletedUnitCount:15];
    [progress setTotalUnitCount:0];
    EXPECT_FALSE([progress isIndeterminate]);

    [progress setCompletedUnitCount:0];
    [progress setTotalUnitCount:0];
    EXPECT_TRUE([progress isIndeterminate]);
}

TEST(NSProgress, ChainImplicit) {
    NSProgress* prog1 = [NSProgress progressWithTotalUnitCount:100];
    [prog1 becomeCurrentWithPendingUnitCount:100];
    NSProgress* prog2 = [NSProgress progressWithTotalUnitCount:50];
    [prog2 becomeCurrentWithPendingUnitCount:50];
    NSProgress* prog3 = [NSProgress progressWithTotalUnitCount:10];
    [prog3 setCompletedUnitCount:6];

    ASSERT_EQ(0.6, [prog3 fractionCompleted]);
    ASSERT_EQ(0.6, [prog2 fractionCompleted]);
    ASSERT_EQ(0.6, [prog1 fractionCompleted]);

    ASSERT_EQ(6, [prog3 completedUnitCount]);
    ASSERT_EQ(0, [prog2 completedUnitCount]);
    ASSERT_EQ(0, [prog1 completedUnitCount]);

    [prog3 setCompletedUnitCount:10];

    ASSERT_EQ(1.0, [prog3 fractionCompleted]);
    ASSERT_EQ(1.0, [prog2 fractionCompleted]);
    ASSERT_EQ(1.0, [prog1 fractionCompleted]);

    ASSERT_EQ(10, [prog3 completedUnitCount]);
    ASSERT_EQ(50, [prog2 completedUnitCount]);
    ASSERT_EQ(100, [prog1 completedUnitCount]);

    [prog2 resignCurrent];
    [prog1 resignCurrent];
}

TEST(NSProgress, ChainImplicit_EdgeCases) {
    NSProgress* prog1 = [NSProgress progressWithTotalUnitCount:100];
    [prog1 becomeCurrentWithPendingUnitCount:100];
    NSProgress* prog2 = [NSProgress progressWithTotalUnitCount:120];
    [prog2 becomeCurrentWithPendingUnitCount:20];
    NSProgress* prog3 = [NSProgress progressWithTotalUnitCount:3];

    ASSERT_EQ(0, [prog3 completedUnitCount]);
    ASSERT_EQ(0, [prog2 completedUnitCount]);
    ASSERT_EQ(0, [prog1 completedUnitCount]);

    ASSERT_EQ(0, [prog3 fractionCompleted]);
    ASSERT_EQ(0, [prog2 fractionCompleted]);
    ASSERT_EQ(0, [prog1 fractionCompleted]);

    [prog3 setCompletedUnitCount:1];

    ASSERT_EQ(1, [prog3 completedUnitCount]);
    ASSERT_EQ(0, [prog2 completedUnitCount]);
    ASSERT_EQ(0, [prog1 completedUnitCount]);

    ASSERT_NEAR(1.0f / 3.0f, [prog3 fractionCompleted], c_errorMargin);
    ASSERT_NEAR(1.0f / 18.0f, [prog2 fractionCompleted], c_errorMargin);
    ASSERT_NEAR(1.0f / 18.0f, [prog1 fractionCompleted], c_errorMargin);

    // Manually add 60 to prog2
    [prog2 setCompletedUnitCount:60];

    ASSERT_EQ(1, [prog3 completedUnitCount]);
    ASSERT_EQ(60, [prog2 completedUnitCount]);
    ASSERT_EQ(0, [prog1 completedUnitCount]);

    ASSERT_NEAR(1.0f / 3.0f, [prog3 fractionCompleted], c_errorMargin);
    ASSERT_NEAR(0.5f + (1.0f / 18.0f), [prog2 fractionCompleted], c_errorMargin);
    ASSERT_NEAR(0.5f + (1.0f / 18.0f), [prog1 fractionCompleted], c_errorMargin);

    // Go past-the-end on prog3, should add the 20 pending units to prog2
    [prog3 setCompletedUnitCount:4];

    ASSERT_EQ(4, [prog3 completedUnitCount]);
    ASSERT_EQ(80, [prog2 completedUnitCount]);
    ASSERT_EQ(0, [prog1 completedUnitCount]);

    ASSERT_NEAR(4.0f / 3.0f, [prog3 fractionCompleted], c_errorMargin);
    ASSERT_NEAR(80.0f / 120.0f, [prog2 fractionCompleted], c_errorMargin);
    ASSERT_NEAR(80.0f / 120.0f, [prog1 fractionCompleted], c_errorMargin);

    // Reset prog3 back to 0 (probably shouldn't ever be done in production)
    [prog3 setCompletedUnitCount:0];

    ASSERT_EQ(0, [prog3 completedUnitCount]);
    ASSERT_EQ(80, [prog2 completedUnitCount]); // Stays the same
    ASSERT_EQ(0, [prog1 completedUnitCount]);

    ASSERT_EQ(0, [prog3 fractionCompleted]);
    ASSERT_NEAR((60.0f / 120.0f) - (1.0f / 18.0f),
                [prog2 fractionCompleted],
                c_errorMargin); // Lowers by 4/3 * 20/120, despite completedUnitCount staying the same
    ASSERT_NEAR((60.0f / 120.0f) - (1.0f / 18.0f), [prog1 fractionCompleted], c_errorMargin); // Lowers by 4/3 * 20/120

    // Complete prog3 again (probably shouldn't ever be done in production)
    [prog3 setCompletedUnitCount:3];

    ASSERT_EQ(3, [prog3 completedUnitCount]);
    ASSERT_EQ(100, [prog2 completedUnitCount]); // Increments again
    ASSERT_EQ(0, [prog1 completedUnitCount]);

    ASSERT_EQ(1, [prog3 fractionCompleted]);
    ASSERT_NEAR((80.0f / 120.0f) - (1.0f / 18.0f), [prog2 fractionCompleted], c_errorMargin); // Increases by 20/120
    ASSERT_NEAR((80.0f / 120.0f) - (1.0f / 18.0f), [prog1 fractionCompleted], c_errorMargin); // Increases by 20/120

    // Change prog3's total unit count to 9
    [prog3 setTotalUnitCount:9];

    ASSERT_EQ(3, [prog3 completedUnitCount]);
    ASSERT_EQ(100, [prog2 completedUnitCount]);
    ASSERT_EQ(0, [prog1 completedUnitCount]);

    ASSERT_NEAR(1.0f / 3.0f, [prog3 fractionCompleted], c_errorMargin);
    ASSERT_NEAR(0.5f, [prog2 fractionCompleted], c_errorMargin); // lower by 20/120, increase by 1/3 * 20/120
    ASSERT_NEAR(0.5f, [prog1 fractionCompleted], c_errorMargin); // lower by 20/120, increase by 1/3 * 20/120

    // Reset prog2 to 0 (probably shouldn't ever be done in production)
    [prog2 setCompletedUnitCount:0];

    ASSERT_EQ(3, [prog3 completedUnitCount]);
    ASSERT_EQ(0, [prog2 completedUnitCount]); // Hard resets without taking anything from prog3 into account
    ASSERT_EQ(0, [prog1 completedUnitCount]);

    ASSERT_NEAR(1.0f / 3.0f, [prog3 fractionCompleted], c_errorMargin);
    ASSERT_NEAR(0, [prog2 fractionCompleted], c_errorMargin); // fractionCompleted floors at 0
    ASSERT_NEAR(0, [prog1 fractionCompleted], c_errorMargin);

    [prog2 resignCurrent];
    [prog1 resignCurrent];
}

TEST(NSProgress, TreeImplicit) {
    NSProgress* root = [NSProgress progressWithTotalUnitCount:100];
    ProgressThreadHelper* progressThreadHelper = [[ProgressThreadHelper new] autorelease];

    _NSFoundationTestKVOFacade* kvoListener = [[_NSFoundationTestKVOFacade newWithObservee:root] autorelease];
    [kvoListener observeKeyPath:@"fractionCompleted"
                     withOptions:NSKeyValueObservingOptionNew
                 performingBlock:^(id root) {
                     NSThread* thread1 =
                         [[[NSThread alloc] initWithTarget:progressThreadHelper selector:@selector(work1:) object:root] autorelease];
                     NSThread* thread2 =
                         [[[NSThread alloc] initWithTarget:progressThreadHelper selector:@selector(work2:) object:root] autorelease];

                     [thread1 start];
                     [thread2 start];

                     size_t i = 0;
                     while ((![thread1 isFinished] || ![thread2 isFinished]) && (i++ < 50)) {
                         std::this_thread::sleep_for(std::chrono::milliseconds(10));
                     }

                     ASSERT_EQ(work1pendingUnitCount + work2pendingUnitCount, [root completedUnitCount]);
                 }
        andExpectChangeCallbacks:nil];
    EXPECT_NE(0, kvoListener.hits);
}

// The selector addChild:withPendingUnitCount is only supported in OSX Foundation 10.11,
// therfore the test is being disabled on OSX, since it is not being compiled against Foundation version 10.11
OSX_DISABLED_TEST(NSProgress, TreeExplicit) {
    NSProgress* root = [NSProgress progressWithTotalUnitCount:100];
    // layer 1 children
    NSProgress* child1 = [NSProgress progressWithTotalUnitCount:100];
    NSProgress* child2 = [NSProgress progressWithTotalUnitCount:100];
    [root addChild:child1 withPendingUnitCount:30];
    [root addChild:child2 withPendingUnitCount:50];

    // layer 2 children
    NSProgress* child11 = [NSProgress progressWithTotalUnitCount:100];
    NSProgress* child12 = [NSProgress progressWithTotalUnitCount:100];
    NSProgress* child13 = [NSProgress progressWithTotalUnitCount:100];
    [child1 addChild:child11 withPendingUnitCount:10];
    [child1 addChild:child12 withPendingUnitCount:20];
    [child1 addChild:child13 withPendingUnitCount:70];

    NSProgress* child21 = [NSProgress progressWithTotalUnitCount:100];

    [child2 addChild:child21 withPendingUnitCount:100];

    [child11 setCompletedUnitCount:100];
    [child12 setCompletedUnitCount:100];
    ASSERT_EQ(30, [child1 completedUnitCount]);
    ASSERT_EQ(0, [root completedUnitCount]);

    [child13 setCompletedUnitCount:100];
    ASSERT_EQ(100, [child1 completedUnitCount]);
    ASSERT_EQ(30, [root completedUnitCount]);

    [child21 setCompletedUnitCount:100];
    ASSERT_EQ(100, [child2 completedUnitCount]);
    ASSERT_EQ(80, [root completedUnitCount]);
}

// The selector addChild:withPendingUnitCount is only supported in OSX Foundation 10.11,
// therfore the test is being disabled on OSX, since it is not being compiled against Foundation version 10.11
OSX_DISABLED_TEST(NSProgress, CurrentProgress_ThreadLocal) {
    NSProgress* root = [NSProgress progressWithTotalUnitCount:100];
    [root becomeCurrentWithPendingUnitCount:50];
    ProgressThreadHelper* progressThreadHelper = [[ProgressThreadHelper new] autorelease];
    NSThread* thread1 =
        [[[NSThread alloc] initWithTarget:progressThreadHelper selector:@selector(becomeResignCheckCurrent:) object:nil] autorelease];
    [thread1 start];

    size_t i = 0;
    while ((![thread1 isFinished]) && (i++ < 50)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ASSERT_EQ(YES, [progressThreadHelper currentIsCorrect]);
    ASSERT_EQ(0, [root completedUnitCount]);

    [progressThreadHelper setCurrentIsCorrect:NO];

    NSThread* thread2 =
        [[[NSThread alloc] initWithTarget:progressThreadHelper selector:@selector(becomeResignCheckCurrentWithChild:) object:root]
            autorelease];
    [thread2 start];

    i = 0;
    while ((![thread2 isFinished]) && (i++ < 50)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ASSERT_EQ(YES, [progressThreadHelper currentIsCorrect]);
    ASSERT_EQ(1, [root fractionCompleted]);
    [root resignCurrent];
}

ARM_DISABLED_TEST(NSProgress, SingleParentEvenAcrossThreads) {
#if TARGET_OS_WIN32
    NSProgress* root = [NSProgress progressWithTotalUnitCount:100];
    ProgressThreadHelper* progressThreadHelper = [[ProgressThreadHelper new] autorelease];

    NSThread* thread1 = [[[NSThread alloc] initWithTarget:progressThreadHelper selector:@selector(addParentTo:) object:root] autorelease];
    NSThread* thread2 = [[[NSThread alloc] initWithTarget:progressThreadHelper selector:@selector(addParentTo:) object:root] autorelease];

    [thread1 start];
    [thread2 start];

    size_t i = 0;
    while ((![thread1 isFinished] || ![thread2 isFinished]) && (i++ < 50)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    ASSERT_EQ(YES, [progressThreadHelper exceptionWasCaught]);
#endif
}

// The selector addChild:withPendingUnitCount is only supported in OSX Foundation 10.11,
// therfore the test is being disabled on OSX, since it is not being compiled against Foundation version 10.11
OSX_DISABLED_TEST(NSProgress, ResignCurrentAutomaticBehavior) {
    // Become current and resign current without a child in-between should automatically increment by adding the pending units
    NSProgress* root = [NSProgress progressWithTotalUnitCount:100];
    [root becomeCurrentWithPendingUnitCount:50];
    [root resignCurrent];

    ASSERT_EQ(50, [root completedUnitCount]);

    // Implicitly adding a child in-between should cancel this behavior
    [root becomeCurrentWithPendingUnitCount:50];
    NSProgress* child1 = [NSProgress progressWithTotalUnitCount:30];
    [root resignCurrent];
    ASSERT_EQ(50, [root completedUnitCount]);

    // Explicitly adding a child in-between should still trigger the behavior
    [root becomeCurrentWithPendingUnitCount:50];
    NSProgress* child2 = [NSProgress discreteProgressWithTotalUnitCount:30];
    [root addChild:child2 withPendingUnitCount:1];
    [root resignCurrent];
    ASSERT_EQ(100, [root completedUnitCount]);

    // This constructor is also explicit
    [root becomeCurrentWithPendingUnitCount:50];
    NSProgress* child3 = [NSProgress progressWithTotalUnitCount:10 parent:root pendingUnitCount:50];
    [root resignCurrent];
    ASSERT_EQ(150, [root completedUnitCount]);
}

// The selector addChild:withPendingUnitCount is only supported in OSX Foundation 10.11,
// therfore the test is being disabled on OSX, since it is not being compiled against Foundation version 10.11
OSX_DISABLED_TEST(NSProgress, CancelPauseResume) {
    NSProgress* root = [NSProgress progressWithTotalUnitCount:100];

    // Cancellable/Pausable are documented to not actually affect cancelling/pausing
    [root setCancellable:NO];
    [root setPausable:NO];

    __block BOOL cancelCalled;
    __block BOOL pauseCalled;
    __block BOOL resumeCalled;

    [root setCancellationHandler:^void() {
        cancelCalled = YES;
    }];

    [root setPausingHandler:^void() {
        pauseCalled = YES;
    }];

    [root setResumingHandler:^void() {
        resumeCalled = YES;
    }];

    // Verify that the handlers are called and the bools are set
    _NSFoundationTestKVOFacade* kvoListener = [[_NSFoundationTestKVOFacade newWithObservee:root] autorelease];
    [kvoListener observeKeyPath:@"cancelled"
                     withOptions:NSKeyValueObservingOptionNew
                 performingBlock:^(id root) {
                     [root cancel];
                     ASSERT_EQ(YES, [root isCancelled]);
                     ASSERT_EQ(YES, cancelCalled);
                 }
        andExpectChangeCallbacks:nil];
    EXPECT_EQ(1, kvoListener.hits);

    [kvoListener observeKeyPath:@"paused"
                     withOptions:NSKeyValueObservingOptionNew
                 performingBlock:^(id root) {
                     [root pause];
                     ASSERT_EQ(YES, [root isPaused]);
                     ASSERT_EQ(YES, pauseCalled);
                 }
        andExpectChangeCallbacks:nil];
    EXPECT_EQ(1, kvoListener.hits);

    [kvoListener observeKeyPath:@"paused"
                     withOptions:NSKeyValueObservingOptionNew
                 performingBlock:^(id root) {
                     [root resume];
                     ASSERT_EQ(NO, [root isPaused]);
                     ASSERT_EQ(YES, resumeCalled);
                 }
        andExpectChangeCallbacks:nil];
    EXPECT_EQ(1, kvoListener.hits);
}

TEST(NSProgress, LocalizedDescription) {
    // Testing for exact strings is not very robust here, just validate that the strings change/don't change based on input
    NSProgress* progress = [NSProgress progressWithTotalUnitCount:100];

    // Basic
    NSString* baseLocalizedDescription = [progress localizedDescription];
    NSString* baseLocalizedAdditionalDescription = [progress localizedAdditionalDescription];
    ASSERT_OBJCNE(@"", baseLocalizedDescription);
    ASSERT_OBJCNE(@"", baseLocalizedAdditionalDescription);

    // Set kind
    [progress setKind:NSProgressKindFile];
    ASSERT_OBJCEQ(NSProgressKindFile, [progress kind]);
    [progress setUserInfoObject:NSProgressFileOperationKindDownloading forKey:NSProgressFileOperationKindKey];
    NSString* localizedDescriptionWithKind = [progress localizedDescription];
    NSString* localizedAdditionalDescriptionWithKind = [progress localizedAdditionalDescription];
    ASSERT_OBJCNE(@"", localizedDescriptionWithKind);
#if TARGET_OS_WIN32
    ASSERT_OBJCEQ(@"0 bytes of 100 bytes", localizedAdditionalDescriptionWithKind);
#endif

    ASSERT_OBJCNE(baseLocalizedDescription, localizedDescriptionWithKind);

    // Change kind key
    [progress setUserInfoObject:NSProgressFileOperationKindCopying forKey:NSProgressFileOperationKindKey];
    NSString* localizedDescriptionWithNewKind = [progress localizedDescription];
    ASSERT_OBJCNE(@"", localizedDescriptionWithNewKind);
    ASSERT_OBJCNE(localizedDescriptionWithKind, localizedDescriptionWithNewKind);

    // Other keys
    [progress setUserInfoObject:@23 forKey:NSProgressEstimatedTimeRemainingKey];
    NSString* localizedAdditionalDescriptionWithEstimatedTime = [progress localizedAdditionalDescription];
    ASSERT_OBJCNE(@"", localizedAdditionalDescriptionWithEstimatedTime);
    ASSERT_OBJCNE(localizedAdditionalDescriptionWithKind, localizedAdditionalDescriptionWithEstimatedTime);

    [progress setUserInfoObject:@17 forKey:NSProgressThroughputKey];
    NSString* localizedAdditionalDescriptionWithThroughput = [progress localizedAdditionalDescription];
    ASSERT_OBJCNE(@"", localizedAdditionalDescriptionWithThroughput);
#if TARGET_OS_WIN32
    ASSERT_OBJCNE(localizedAdditionalDescriptionWithEstimatedTime, localizedAdditionalDescriptionWithThroughput);
#endif
    // Manually set
    NSString* userSetLocalizedDescription = @"user-set localizedDescription";
    NSString* userSetLocalizedAdditionalDescription = @"user-set localizedAdditionalDescription";
    [progress setLocalizedDescription:userSetLocalizedDescription];
    [progress setLocalizedAdditionalDescription:userSetLocalizedAdditionalDescription];
    ASSERT_OBJCEQ(userSetLocalizedDescription, [progress localizedDescription]);
    ASSERT_OBJCEQ(userSetLocalizedAdditionalDescription, [progress localizedAdditionalDescription]);

    // Changing other values should not change the descriptions
    [progress setUserInfoObject:NSProgressFileOperationKindReceiving forKey:NSProgressFileOperationKindKey];
    [progress setKind:0];
    ASSERT_OBJCEQ(userSetLocalizedDescription, [progress localizedDescription]);
    ASSERT_OBJCEQ(userSetLocalizedAdditionalDescription, [progress localizedAdditionalDescription]);

    // Ensure copy
    userSetLocalizedDescription = @"foo";
    userSetLocalizedAdditionalDescription = @"foo2";
    ASSERT_OBJCEQ(@"user-set localizedDescription", [progress localizedDescription]);
    ASSERT_OBJCEQ(@"user-set localizedAdditionalDescription", [progress localizedAdditionalDescription]);

    NSString* outLocalizedDescription = [progress localizedDescription];
    NSString* outLocalizedAdditionalDescription = [progress localizedAdditionalDescription];
    [progress setLocalizedDescription:userSetLocalizedDescription];
    [progress setLocalizedAdditionalDescription:userSetLocalizedAdditionalDescription];
    ASSERT_OBJCEQ(@"user-set localizedDescription", outLocalizedDescription);
    ASSERT_OBJCEQ(@"user-set localizedAdditionalDescription", outLocalizedAdditionalDescription);
}

TEST(NSProgress, KVOLocalizedDescription) {
    NSProgress* progress = [NSProgress progressWithTotalUnitCount:100];

    _NSFoundationTestKVOFacade* kvoListener = [[_NSFoundationTestKVOFacade newWithObservee:progress] autorelease];
    [kvoListener observeKeyPath:@"localizedDescription"
                     withOptions:NSKeyValueObservingOptionNew
                 performingBlock:^(id progress) {
                     // Setting NSProgressFileTotalCountKey in User Info should trigger a localized decription change.
                     [progress setUserInfoObject:@(102) forKey:NSProgressFileTotalCountKey];
                 }
        andExpectChangeCallbacks:nil];
    EXPECT_EQ(1, kvoListener.hits);
}

TEST(NSProgress, CurrentProgressLeak) {
    NSProgress* progress = [NSProgress progressWithTotalUnitCount:100];

    std::thread t([&progress]() {
        [progress becomeCurrentWithPendingUnitCount:50];
    });

    t.join();

    // Progress unfinished upon thread exit. Ensure we're not keeping progress alive:
    EXPECT_EQ(1, [progress retainCount]);
}
