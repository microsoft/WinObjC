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
#import <Starboard/SmartTypes.h>

#import "LifetimeCounting.h"

#define _JOIN(x, y) x##y
#define JOIN(x, y) _JOIN(x, y)

TEST(Starboard, JOIN(AutoId_, STARBOARD_TEST_KIND)) {
    __unsafe_unretained LifetimeCounting* lifeCounter = [[LifetimeCounting alloc] init];
    unsigned int releaseCount = 0;
    unsigned int retainCount = 0;

    retainCount = [lifeCounter arcSafeRetainCount];
    releaseCount = [lifeCounter arcSafeReleaseCount];

    { // Test that Assign does not take another refcount.
        AutoId<LifetimeCounting, LifetimeUnsafe> auto1(lifeCounter);
        EXPECT_EQ(0, [auto1 arcSafeRetainCount] - retainCount);
    }

    // Test that ~AutoId<..., Assign> does not release a refcount.
    EXPECT_EQ(releaseCount, [lifeCounter arcSafeReleaseCount]);

    retainCount = [lifeCounter arcSafeRetainCount];
    releaseCount = [lifeCounter arcSafeReleaseCount];

    { // Test that Retain takes a refcount.
        AutoId<LifetimeCounting, LifetimeRetain> auto1(lifeCounter);
        EXPECT_EQ(1, [auto1 arcSafeRetainCount] - retainCount);
    }

    // Test that ~AutoId<..., Retain> releases a refcount.
    EXPECT_EQ(1, [lifeCounter arcSafeReleaseCount] - releaseCount);

    [lifeCounter destroy];
}

TEST(Starboard, JOIN(AutoIDCopying_, STARBOARD_TEST_KIND)) {
    __unsafe_unretained LifetimeCounting* lifeCounter = [[LifetimeCounting alloc] init];
    unsigned int releaseCount = 0;
    unsigned int retainCount = 0;

    retainCount = [lifeCounter arcSafeRetainCount];
    releaseCount = [lifeCounter arcSafeReleaseCount];

    {
        // Assign
        AutoId<LifetimeCounting, LifetimeUnsafe> auto1(lifeCounter);

        // Retain from an assign.
        AutoId<LifetimeCounting, LifetimeRetain> auto2(auto1);
        EXPECT_EQ(1, [auto2 arcSafeRetainCount] - retainCount);

        // Retain from a retain.
        AutoId<LifetimeCounting, LifetimeRetain> auto4(auto2);
        EXPECT_EQ(2, [auto4 arcSafeRetainCount] - retainCount);
    }

    EXPECT_EQ(2, [lifeCounter arcSafeReleaseCount] - releaseCount);

    [lifeCounter destroy];
}

TEST(Starboard, JOIN(AutoIdAssignment_, STARBOARD_TEST_KIND)) {
    __unsafe_unretained LifetimeCounting* lifeCounter = [[LifetimeCounting alloc] init];
    unsigned int releaseCount = 0;
    unsigned int retainCount = 0;

    retainCount = [lifeCounter arcSafeRetainCount];
    releaseCount = [lifeCounter arcSafeReleaseCount];

    {
        AutoId<LifetimeCounting, LifetimeUnsafe> auto1(lifeCounter);
        AutoId<LifetimeCounting, LifetimeRetain> auto2;
        AutoId<LifetimeCounting, LifetimeRetain> auto3;

        // Retain from an assign.
        auto2 = auto1;
        EXPECT_EQ(1, [auto2 arcSafeRetainCount] - retainCount);

        // Retain from a retain.
        auto3 = auto2;
        EXPECT_EQ(2, [auto3 arcSafeRetainCount] - retainCount);

        // Assign from a retain
        auto1 = auto2;
        // expect no delta in retain count.
        EXPECT_EQ(2, [auto1 arcSafeRetainCount] - retainCount);
    }

    EXPECT_EQ(2, [lifeCounter arcSafeReleaseCount] - releaseCount);

    [lifeCounter destroy];
}

TEST(Starboard, JOIN(AutoIdBlockCall_, STARBOARD_TEST_KIND)) {
    {
        __block bool block1Called = false;
        void (^block1)() = ^{
            block1Called = true;
        };

        AutoId<void (^)(), LifetimeRetain> autoBlock1(block1);

        autoBlock1();


        EXPECT_TRUE(block1Called);
    }

    {
        int (^block2)(int) = ^(int input) {
            return input * 10;
        };

        AutoId<int (^)(int), LifetimeRetain> autoBlock2(block2);

        EXPECT_EQ(10240, autoBlock2(1024));
    }
}
