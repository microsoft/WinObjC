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

// Windows-only:
//      NSLock _lockCount

// TODO: Issue #688 NSLock/NSRecursiveLockTests can be non-WindowsOnly

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import "NSLock+Internal.h"

TEST(NSLock, initWithName) {
    NSString* lockName = @"testLock";
    NSLock* lock = [[NSLock alloc] init];
    ASSERT_TRUE_MSG(lock != nil, "FAILED: lock should be non-null!");
    [lock setName:lockName];
    ASSERT_OBJCEQ_MSG(lockName, [lock name], "FAILED: lock name does not match");
    ASSERT_EQ_MSG(0, [lock _lockCount], "FAILED: the lock should not be locked.");
    [lock release];
    [lockName release];
}

TEST(NSLock, lockAndUnLock) {
    NSLock* lock = [[NSLock alloc] init];
    ASSERT_TRUE_MSG(lock != nil, "FAILED: lock should be non-null!");
    [lock lock];
    ASSERT_EQ_MSG(1, [lock _lockCount], "FAILED: the lock should be locked.");
    [lock unlock];
    ASSERT_EQ_MSG(0, [lock _lockCount], "FAILED: the lock should not be locked.");
    [lock release];
}

TEST(NSLock, lockAndUnLockSanity) {
    NSLock* lock = [[NSLock alloc] init];
    ASSERT_TRUE_MSG(lock != nil, "FAILED: lock should be non-null!");
    int limit = 20;
    for (int i = 0; i < limit; ++i) {
        [lock lock];
        ASSERT_EQ_MSG(1, [lock _lockCount], "FAILED: the lock should be locked.");
        [lock unlock];
        ASSERT_EQ_MSG(0, [lock _lockCount], "FAILED: the lock should not be locked.");
    }

    [lock release];
}

TEST(NSLock, tryLock) {
    NSLock* lock = [[NSLock alloc] init];
    ASSERT_TRUE_MSG(lock != nil, "FAILED: lock should be non-null!");

    ASSERT_EQ_MSG(YES, [lock tryLock], "FAILED: unable to obtain the lock.");
    ASSERT_EQ_MSG(1, [lock _lockCount], "FAILED: the lock should be locked.");
    [lock unlock];

    ASSERT_EQ_MSG(0, [lock _lockCount], "FAILED: the lock should not be locked.");
    [lock release];
}

TEST(NSLock, lockBeforeDate) {
    NSLock* lock = [[NSLock alloc] init];
    ASSERT_TRUE_MSG(lock != nil, "FAILED: lock should be non-null!");

    ASSERT_EQ_MSG(YES, [lock lockBeforeDate:[NSDate dateWithTimeIntervalSinceNow:4]], "FAILED: unable to obtain the lock.");
    ASSERT_EQ_MSG(1, [lock _lockCount], "FAILED: the lock should be locked.");
    [lock unlock];

    ASSERT_EQ_MSG(0, [lock _lockCount], "FAILED: the lock should not be locked.");
    [lock release];
}