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

#import <TestFramework.h>
#import <Foundation/Foundation.h>

#import <thread>
#import <mutex>
#import <condition_variable>
#import <chrono>

TEST(NSOperation, NSOperationDealloc) {
    NSOperationQueue* queue = [[NSOperationQueue alloc] init];
    ASSERT_NO_THROW([queue release]);

    NSOperation* operation = [[NSOperation alloc] init];
    ASSERT_NO_THROW([operation release]);
}

TEST(NSOperation, NSOperation) {
    NSOperationQueue* queue = [[NSOperationQueue new] autorelease];

    NSOperation* operation = [[NSOperation new] autorelease];

    [operation setCompletionBlock:^{
        [operation waitUntilFinished]; // Should not deadlock, but we cannot test this
        ASSERT_TRUE([operation isFinished]);
    }];

    [queue addOperation:operation];

    [operation waitUntilFinished];

    ASSERT_TRUE([operation isFinished]);
    ASSERT_FALSE([operation isExecuting]);
}

TEST(NSOperation, NSOperationCancellation) {
    NSOperationQueue* queue = [[NSOperationQueue new] autorelease];

    NSOperation* cancelledOperation = [[NSOperation new] autorelease];

    [cancelledOperation setCompletionBlock:^{
        [cancelledOperation waitUntilFinished]; // Should not deadlock, but we cannot test this
        ASSERT_TRUE([cancelledOperation isFinished]);
    }];

    [cancelledOperation cancel];

    [queue addOperation:cancelledOperation];

    [cancelledOperation waitUntilFinished];

    ASSERT_FALSE([cancelledOperation isExecuting]);
    ASSERT_TRUE([cancelledOperation isCancelled]);
}

TEST(NSOperation, NSOperationSuspend) {
    NSOperationQueue* queue = [[NSOperationQueue alloc] init];

    NSOperation* suspendOperation = [[NSOperation alloc] init];

    __block NSCondition* suspendCondition = [NSCondition new];
    __block bool shouldBeTrue = false;

    [suspendOperation setCompletionBlock:^{
        [suspendOperation waitUntilFinished]; // Should not deadlock, but we cannot test this
        ASSERT_TRUE([suspendOperation isFinished]);

        [suspendCondition lock];
        ASSERT_TRUE(shouldBeTrue);
        [suspendCondition unlock];
    }];

    [queue setSuspended:YES];
    [queue addOperation:suspendOperation];

    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    [suspendCondition lock];
    shouldBeTrue = true;
    [suspendCondition broadcast];
    [suspendCondition unlock];

    ASSERT_TRUE([queue isSuspended]);
    ASSERT_FALSE([suspendOperation isExecuting]);

    [queue setSuspended:NO];
    ASSERT_FALSE([queue isSuspended]);

    [suspendOperation waitUntilFinished];
}

@interface TestObserver : NSObject
@property BOOL didObserveCompletionBlock;
@property BOOL didObserveDependencies;
@property BOOL didObserveReady;
@property BOOL didObserveCancelled;
@property BOOL didObserveExecuting;
@property BOOL didObserveFinished;
@end

@implementation TestObserver
- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)change context:(void*)context {
    if ([keyPath isEqualToString:@"completionBlock"]) {
        _didObserveCompletionBlock = YES;
    } else if ([keyPath isEqualToString:@"dependencies"]) {
        _didObserveDependencies = YES;
    } else if ([keyPath isEqualToString:@"isReady"]) {
        _didObserveReady = YES;
    } else if ([keyPath isEqualToString:@"isCancelled"]) {
        _didObserveCancelled = YES;
    } else if ([keyPath isEqualToString:@"isExecuting"]) {
        _didObserveExecuting = YES;
    } else if ([keyPath isEqualToString:@"isFinished"]) {
        _didObserveFinished = YES;
    }
}

@end

TEST(NSOperation, NSOperationKVO) {
    NSOperationQueue* queue = [[NSOperationQueue new] autorelease];
    NSOperation* operation = [[NSOperation new] autorelease];
    TestObserver* observer = [[TestObserver new] autorelease];

    [operation addObserver:observer forKeyPath:@"completionBlock" options:0 context:NULL];
    [operation addObserver:observer forKeyPath:@"isCancelled" options:0 context:NULL];
    [operation addObserver:observer forKeyPath:@"isExecuting" options:0 context:NULL];
    [operation addObserver:observer forKeyPath:@"isFinished" options:0 context:NULL];

    [operation setCompletionBlock:^{
        // nothing to do here.
    }];

    ASSERT_TRUE([observer didObserveCompletionBlock]);
    [observer setDidObserveCompletionBlock:NO];

    ASSERT_FALSE([observer didObserveCompletionBlock]);
    ASSERT_FALSE([observer didObserveCancelled]);
    ASSERT_FALSE([observer didObserveExecuting]);
    ASSERT_FALSE([observer didObserveFinished]);

    [queue addOperation:operation];
    [operation waitUntilFinished];

    ASSERT_FALSE([observer didObserveCompletionBlock]);
    ASSERT_FALSE([observer didObserveCancelled]);
    ASSERT_TRUE([observer didObserveExecuting]);
    ASSERT_TRUE([observer didObserveFinished]);

   [operation removeObserver:observer forKeyPath:@"completionBlock" context:NULL];
   [operation removeObserver:observer forKeyPath:@"isCancelled" context:NULL];
   [operation removeObserver:observer forKeyPath:@"isExecuting" context:NULL];
   [operation removeObserver:observer forKeyPath:@"isFinished" context:NULL];
}

// Test asynchronous subclass for NSOperation
@interface MyConcurrentOperation : NSOperation
@property (assign, getter = isExecuting) BOOL executing;
@property (assign, getter = isFinished, readonly) BOOL finished;
@end

@implementation MyConcurrentOperation

@synthesize executing = _executing;
@synthesize finished = _finished;

- (void)setExecuting:(BOOL)executing
{
    [self willChangeValueForKey:@"isExecuting"];
    [self willChangeValueForKey:@"isFinished"];

    _executing = executing;
    _finished = !executing;

    [self didChangeValueForKey:@"isExecuting"];
    [self didChangeValueForKey:@"isFinished"];
}

- (BOOL)isExecuting
{
    return _executing;
}

- (BOOL)isFinished
{
    return _finished;
}

- (void)start
{
    if (self.isCancelled) {
        return;
    }

    self.executing = YES;
    [self doSomething];
}

- (void)doSomething
{
    // Do some async task.
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), ^{

        // Do another async task
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_LOW, 0), ^{
            // Do some async task.
            self.executing = NO;
        });
    });
}

@end

TEST(NSOperation, NSOperationConcurrentSubclass) {
    NSOperationQueue* queue = [[NSOperationQueue new] autorelease];

    NSOperation* operation = [MyConcurrentOperation new];

    [operation setCompletionBlock:^{
        [operation waitUntilFinished]; // Should not deadlock, but we cannot test this
        ASSERT_TRUE([operation isFinished]);
    }];

    [queue addOperation:operation];

    [operation waitUntilFinished];

    ASSERT_TRUE([operation isFinished]);
    ASSERT_FALSE([operation isExecuting]);
    ASSERT_NO_THROW([operation release]);
}

// Test synchronous subclass for NSOperation
@interface MyNonconcurrentOperation : NSOperation
@property BOOL didWork;
@end

@implementation MyNonconcurrentOperation

- (void)main
{
    if (self.isCancelled) {
        return;
    }

    _didWork = YES;
}

@end

TEST(NSOperation, NSOperationNonconcurrentSubclass) {
    NSOperationQueue* queue = [[NSOperationQueue new] autorelease];

    MyNonconcurrentOperation* operation = [MyNonconcurrentOperation new];

    [operation setCompletionBlock:^{
        [operation waitUntilFinished]; // Should not deadlock, but we cannot test this
        ASSERT_TRUE([operation isFinished]);
    }];

    [queue addOperation:operation];
    [operation waitUntilFinished];

    ASSERT_TRUE([operation isFinished]);
    ASSERT_FALSE([operation isExecuting]);
    ASSERT_TRUE([operation didWork]);
    ASSERT_NO_THROW([operation release]);

    MyNonconcurrentOperation* operation2 = [[MyNonconcurrentOperation new] autorelease];
    [operation2 cancel];

    [queue addOperation:operation2];
    [operation2 waitUntilFinished];
    ASSERT_TRUE([operation2 isCancelled]);
    ASSERT_TRUE([operation2 isFinished]);
    ASSERT_FALSE([operation2 isExecuting]);
    ASSERT_FALSE([operation2 didWork]);
}

TEST(NSOperation, NSOperationMultipleWaiters) {
    NSOperationQueue* queue = [[NSOperationQueue new] autorelease];

    NSOperation* operation = [[NSOperation new] autorelease];

    [operation setCompletionBlock:^{
        [operation waitUntilFinished]; // Should not deadlock, but we cannot test this
        ASSERT_TRUE([operation isFinished]);
    }];

    [operation performSelectorInBackground:@selector(waitUntilFinished) withObject:nil];
    [operation performSelectorInBackground:@selector(waitUntilFinished) withObject:nil];
    // Any lingering threads will make the test hang, unfortunately we have no way around this.

    [queue addOperation:operation];

    [operation waitUntilFinished];

    ASSERT_TRUE([operation isFinished]);
}

TEST(NSOperation, NSDependencyRemove) {
    // tests that nothing happens when a dependency is removed that was never added.
    NSOperation* operation = [[NSOperation new] autorelease];
    NSOperation* dependency = [[NSOperation new] autorelease];

    ASSERT_NO_THROW([operation removeDependency:dependency]);
}

TEST(NSOperation, NSOperationIsReady) {
    NSOperationQueue* queue = [[NSOperationQueue new] autorelease];
    TestObserver* observer = [[TestObserver new] autorelease];
    NSOperation* dependency1 = [[NSOperation new] autorelease];
    NSOperation* dependency2 = [[NSOperation new] autorelease];
    NSOperation* dependency3 = [[NSOperation new] autorelease];

    NSOperation* operation = [[NSOperation new] autorelease];
    ASSERT_TRUE([operation isReady]);
    [operation addObserver:observer forKeyPath:@"isReady" options:0 context:NULL];
    ASSERT_FALSE([observer didObserveReady]);

    [operation addDependency:dependency1];
    [operation addDependency:dependency2];

    ASSERT_TRUE([observer didObserveReady]);
    ASSERT_FALSE([operation isReady]);
    [observer setDidObserveReady:NO];

    [queue addOperation:dependency1];
    [dependency1 waitUntilFinished];
    ASSERT_FALSE([observer didObserveReady]);
    ASSERT_FALSE([operation isReady]);

    [queue addOperation:dependency2];
    [dependency2 waitUntilFinished];
    ASSERT_TRUE([observer didObserveReady]);
    ASSERT_TRUE([operation isReady]);
    [observer setDidObserveReady:NO];

    [operation addDependency:dependency3];
    ASSERT_TRUE([observer didObserveReady]);
    ASSERT_FALSE([operation isReady]);
    [observer setDidObserveReady:NO];

    [operation cancel];
    ASSERT_TRUE([observer didObserveReady]);
    ASSERT_TRUE([operation isReady]);

   [operation removeObserver:observer forKeyPath:@"isReady" context:NULL];
}

TEST(NSOperation, NSBlockOperationInQueue) {
    NSOperationQueue* queue = [[NSOperationQueue new] autorelease];


    __block BOOL executedBlock = NO;
    NSOperation* operation = [NSBlockOperation blockOperationWithBlock:^{
        executedBlock = YES;
    }];

    [operation setCompletionBlock:^{
        [operation waitUntilFinished]; // Should not deadlock, but we cannot test this
        ASSERT_TRUE([operation isFinished]);
        ASSERT_TRUE(executedBlock);
    }];

    [queue addOperation:operation];

    [operation waitUntilFinished];

    ASSERT_TRUE([operation isFinished]);
    ASSERT_FALSE([operation isExecuting]);
}