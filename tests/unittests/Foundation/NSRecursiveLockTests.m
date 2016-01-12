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
#import "NSRecursiveLock+Internal.h"

#import <thread>
#import <mutex>
#import <condition_variable>
#import <chrono>

TEST(Foundation, NSRecursiveLock_initWithName) {
    NSString* lockName = @"testLock";
    NSRecursiveLock* lck = [[NSRecursiveLock alloc] init];
    ASSERT_TRUE_MSG(lck != nullptr, "FAILED: lock should be non-null!");
    [lck setName:lockName];
    ASSERT_OBJCEQ_MSG(lockName, [lck name], "FAILED: lock name does not match");
    ASSERT_EQ_MSG(NO, [lck isLocked], "FAILED: the lock should not be locked.");
    [lck release];
}

TEST(Foundation, NSRecursiveLock_lockAndUnLock) {
    NSRecursiveLock* lck = [[NSRecursiveLock alloc] init];
    ASSERT_TRUE_MSG(lck != nullptr, "FAILED: lock should be non-null!");
    [lck lock];
    ASSERT_EQ_MSG(YES, [lck isLocked], "FAILED: the lock should be locked.");
    [lck unlock];
    ASSERT_EQ_MSG(NO, [lck isLocked], "FAILED: the lock should not be locked.");
    [lck release];
}

void foo(NSRecursiveLock* lck) {
    [lck lock];
    int i = 0;
    [lck unlock];
}

TEST(Foundation, NSRecursiveLock_tryLock) {
    NSRecursiveLock* lck = [[NSRecursiveLock alloc] init];
    ASSERT_TRUE_MSG(lck != nullptr, "FAILED: lock should be non-null!");

    ASSERT_EQ_MSG(YES, [lck tryLock], "FAILED: unable to obtain the lock.");
    ASSERT_EQ_MSG(YES, [lck isLocked], "FAILED: the lock should be locked.");
    [lck unlock];

    ASSERT_EQ_MSG(NO, [lck isLocked], "FAILED: the lock should not be locked.");
    [lck release];
}
TEST(Foundation, NSRecursiveLock_lockBeforeDate) {
    NSRecursiveLock* lck = [[NSRecursiveLock alloc] init];
    ASSERT_TRUE_MSG(lck != nullptr, "FAILED: lock should be non-null!");

    ASSERT_EQ_MSG(YES, [lck lockBeforeDate:[NSDate dateWithTimeIntervalSinceNow:4]], "FAILED: unable to obtain the lock.");
    ASSERT_EQ_MSG(YES, [lck isLocked], "FAILED: the lock should be locked.");
    [lck unlock];

    ASSERT_EQ_MSG(NO, [lck isLocked], "FAILED: the lock should not be locked.");
    [lck release];
}

TEST(Foundation, NSRecursiveLock_lockAndUnlockWithThreads) {
    NSRecursiveLock* lck = [[NSRecursiveLock alloc] init];

    std::mutex consumerStartMutex;
    std::mutex waitForProducerMutex;
    std::condition_variable consumerCondition;
    std::unique_lock<std::mutex> consumerStartLock(consumerStartMutex);
    bool successfullyLocked = false;
    bool successfullyAwaitedTheProducer = false;
    bool notified = false;
    std::thread consumer([&]() {
        std::unique_lock<std::mutex> innerStartLock(consumerStartMutex);

        // grab the lock
        [lck lock];
        successfullyLocked = true;
        // notify the main thread, so it can move from the wait to spawn a producer.
        consumerCondition.notify_all();
        innerStartLock.unlock();
        [lck unlock];
        // wait for the producer to come up.
        std::unique_lock<std::mutex> waitForProducerLock(waitForProducerMutex);
        consumerCondition.wait(waitForProducerLock, [&]() { return notified; });
        successfullyAwaitedTheProducer = true;
        waitForProducerLock.unlock();
    });

    // assure consumer grabs the lock first.
    // We want to make sure that the consumer is already waiting for the condition variable
    // broadcast before we spin up the producer.
    consumerCondition.wait(consumerStartLock, [&]() { return successfullyLocked; });

    ASSERT_EQ_MSG(true, successfullyLocked, "FAILED: Unable to succesfully lock.");

    std::thread producer([&]() {
        [lck lock];
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        notified = true;
        std::unique_lock<std::mutex> uniqueLock(waitForProducerMutex);
        consumerCondition.notify_all();
        uniqueLock.unlock();
        [lck unlock];
    });

    consumer.join();
    producer.join();

    ASSERT_EQ_MSG(true, successfullyAwaitedTheProducer, "FAILED: Unable to wait for the producer.");

    [lck release];
}