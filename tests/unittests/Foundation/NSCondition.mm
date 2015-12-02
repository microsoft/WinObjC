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

#import "gtest-api.h"
#import <Foundation/Foundation.h>

#import <thread>
#import <mutex>
#import <condition_variable>
#import <chrono>

// This tests NSCondition against std::mutex and std::condition_variable.
TEST(Foundation, NSCondition) {
    NSCondition* condition = [[NSCondition alloc] init];

    std::mutex consumerStartMutex;
    std::condition_variable consumerCondition;
    std::unique_lock<std::mutex> consumerStartLock(consumerStartMutex);
    bool successfullyLocked = false;

    bool successfullyAcquiredCondition = false;
    std::thread consumer([&]() {
        std::unique_lock<std::mutex> innerStartLock(consumerStartMutex);

        [condition lock];

        successfullyLocked = true;
        consumerCondition.notify_all();
        innerStartLock.unlock();

        @try {
            successfullyAcquiredCondition = [condition waitUntilDate:[NSDate dateWithTimeIntervalSinceNow:1]];
        } @catch (NSException* exception) {
            LOG_INFO("Caught %@ while waiting on condition variable.", exception);
        }
        [condition unlock];
    });

    // We want to make sure that the consumer is already waiting for the condition variable
    // broadcast before we spin up the producer.
    consumerCondition.wait(consumerStartLock, [&]() { return successfullyLocked; });

    ASSERT_TRUE(successfullyLocked);

    std::thread producer([&]() {
        [condition lock];
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        [condition broadcast];
        [condition unlock];
    });

    consumer.join();
    producer.join();

    [condition release];

    ASSERT_TRUE(successfullyAcquiredCondition);
}
