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

#import <thread>
#import <mutex>
#import <condition_variable>
#import <chrono>

TEST(NSOperation, NSOperationDealloc) {
    NSOperationQueue* queue = [[NSOperationQueue alloc] init];
    ASSERT_NO_THROW([queue release]);
}

TEST(NSOperation, NSOperation) {
    NSOperationQueue* queue = [[NSOperationQueue alloc] init];

    NSOperation* operation = [[NSOperation alloc] init];

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
    NSOperationQueue* queue = [[NSOperationQueue alloc] init];

    NSOperation* cancelledOperation = [[NSOperation alloc] init];

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
