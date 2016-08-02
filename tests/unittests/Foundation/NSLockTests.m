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

TEST(NSLock, lockAndUnlockWithThreads) {
    NSLock* lock = [[NSLock alloc] init];
    ASSERT_TRUE_MSG(lock != nil, "FAILED: lock should be non-null!");

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
        [lock lock];
        successfullyLocked = true;
        // notify the main thread, so it can move from the wait to spawn a producer.
        consumerCondition.notify_all();
        [lock unlock];
        innerStartLock.unlock();
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
        [lock lock];
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        notified = true;
        std::unique_lock<std::mutex> uniqueLock(waitForProducerMutex);
        consumerCondition.notify_all();
        uniqueLock.unlock();
        [lock unlock];
    });

    consumer.join();
    producer.join();

    ASSERT_EQ_MSG(true, successfullyAwaitedTheProducer, "FAILED: Unable to wait for the producer.");

    [lock release];
}