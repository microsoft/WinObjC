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

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import <dispatch/dispatch.h>
#import <libkern/OSAtomic.h>

static OSSpinLock lock1;
static OSSpinLock lock2;
static OSSpinLock lock3;
static int spinValue;

TEST(OSSpinLock, SpinLockTests) {
    dispatch_queue_t queue = dispatch_queue_create("queue", nullptr);

    lock1 = OS_SPINLOCK_INIT;
    lock2 = OS_SPINLOCK_INIT;
    lock3 = OS_SPINLOCK_INIT;

    spinValue = 0;
    OSSpinLockLock(&lock1);
    OSSpinLockLock(&lock2);
    OSSpinLockLock(&lock3);

    dispatch_async(queue, ^{
        ASSERT_EQ(false, OSSpinLockTry(&lock1));
        ASSERT_EQ(0, spinValue);
        spinValue++;
        ASSERT_EQ(1, spinValue);
        OSSpinLockUnlock(&lock2);
    });

    dispatch_async(queue, ^{
        OSSpinLockLock(&lock2);
        ASSERT_EQ(false, OSSpinLockTry(&lock1));
        ASSERT_EQ(1, spinValue);
        spinValue++;
        ASSERT_EQ(2, spinValue);
        OSSpinLockUnlock(&lock1);
        OSSpinLockUnlock(&lock2);
        OSSpinLockUnlock(&lock3);
    });

    OSSpinLockLock(&lock3);
    OSSpinLockUnlock(&lock3);
}