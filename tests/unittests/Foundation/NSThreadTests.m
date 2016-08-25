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
#import <future>
#include <pthread.h>

static int counter = 0;

@interface ThreadTestController : NSObject
@property (atomic) BOOL stop;
@end

@implementation ThreadTestController : NSObject
- (void)countingloop {
    while (!self.stop) {
        counter++;
    }
}

@end

static const double sOriginalHighThreadPriority = .8;
static const double sOriginalLowThreadPriority = 0;
static const double sOriginalMidThreadPriority = .5;

static const double sExpectedHighThreadPriority = .87;
static const double sExpectedLowThreadPriority = 0;
static const double sExpectedMidThreadPriority = .5;

// A thread never has a set priority. The system can always change it, in fact it will most likely change the priority.
// Even still, the thread priority should be close enough to the actual requested value so we need to make sure it's sufficiently close.
// The largest difference between thread priorities in Windows should be .07 units in difference as Windows pigeon holes priorities into
// certain values.
static const double sMarginOfError = .07;

TEST(NSThread, Priority) {
    ThreadTestController* testController = [[[ThreadTestController alloc] init] autorelease];
    testController.stop = NO;

    // Create thread 1 with high priority
    NSThread* myThread = [[[NSThread alloc] initWithTarget:testController selector:@selector(countingloop) object:nil] autorelease];
    [myThread setThreadPriority:sOriginalHighThreadPriority];
    [myThread start]; // Actually create the thread

    // Thread Priority will change to the actual windows thread Priority.
    // For example, .8 maps to pthread priority 80 which is then mapped to windows priority THREAD_PRIORITY_ABOVE_NORMAL
    // Returning from this value gives .87 which is a value between 75 and 100 which are the cutoffs for
    // THREAD_PRIORITY_HIGHEST and THREAD_PRIORITY_TIME_CRITICAL. Setting priority to half way between these makes it clear
    // what the priority is when conveyed back to the user.

    EXPECT_NEAR([myThread threadPriority], sExpectedHighThreadPriority, sMarginOfError);

    // Change priority again.
    [myThread setThreadPriority:sOriginalLowThreadPriority];
    EXPECT_NEAR([myThread threadPriority], sExpectedLowThreadPriority, sMarginOfError);

    // Once more.
    [myThread setThreadPriority:sOriginalMidThreadPriority];
    EXPECT_NEAR([myThread threadPriority], sExpectedMidThreadPriority, sMarginOfError);

    // Let the thread die.
    testController.stop = YES;
}

TEST(pthread, StaticInitializer) {
    pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    EXPECT_EQ(0, pthread_mutex_lock(&mutex));
    auto tryLockAsync = std::async(std::launch::async, [&mutex]() { return pthread_mutex_trylock(&mutex); });

    // Try to access locked mutex. 0 means success, we don't want that.
    EXPECT_NE(0, tryLockAsync.get());

    pthread_mutex_unlock(&mutex);
    EXPECT_EQ(0, pthread_mutex_destroy(&mutex));
}