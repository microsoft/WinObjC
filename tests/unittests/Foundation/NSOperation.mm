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

TEST(Foundation, NSOperation) {
    NSOperationQueue* queue = [[NSOperationQueue alloc] init];

    NSOperation* operation = [[NSOperation alloc] init];
    __block bool completed = false;

    [operation setCompletionBlock:^{
        [operation waitUntilFinished]; // Should not deadlock, but we cannot test this
        completed = [operation isFinished];
    }];

    [queue addOperation:operation];

    [operation waitUntilFinished];

    ASSERT_TRUE(completed);
    ASSERT_EQ(completed, [operation isFinished]);
    ASSERT_FALSE([operation isExecuting]);
}

TEST(Foundation, NSOperationCancellation) {
    NSOperationQueue* queue = [[NSOperationQueue alloc] init];

    NSOperation* cancelledOperation = [[NSOperation alloc] init];
    __block bool cancelledOperationCompleted = false;

    [cancelledOperation setCompletionBlock:^{
        [cancelledOperation waitUntilFinished]; // Should not deadlock, but we cannot test this
        cancelledOperationCompleted = [cancelledOperation isFinished];
    }];

    [cancelledOperation cancel];

    [queue addOperation:cancelledOperation];

    [cancelledOperation waitUntilFinished];

    ASSERT_TRUE(cancelledOperationCompleted);
    ASSERT_FALSE([cancelledOperation isExecuting]);
    ASSERT_TRUE([cancelledOperation isCancelled]);
}
