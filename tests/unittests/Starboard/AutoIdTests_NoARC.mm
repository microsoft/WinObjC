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

#define STARBOARD_TEST_KIND NoARC
#include "StarboardAutoIdTests.inl"

TEST(Starboard, AutoIdAttach_NoARC) {
    __unsafe_unretained LifetimeCounting* lifeCounter = [[LifetimeCounting alloc] init];
    unsigned int releaseCount = 0;
    unsigned int retainCount = 0;

    retainCount = [lifeCounter arcSafeRetainCount];
    releaseCount = [lifeCounter arcSafeReleaseCount];

    { // Test that Assign.attach does not take another refcount.
        AutoId<LifetimeCounting, LifetimeUnsafe> auto1;
        auto1.attach(lifeCounter);
        EXPECT_EQ(0, [auto1 arcSafeRetainCount] - retainCount);
    }

    // Test that ~AutoId<..., Assign> does not release a refcount.
    EXPECT_EQ(releaseCount, [lifeCounter arcSafeReleaseCount]);

    retainCount = [lifeCounter arcSafeRetainCount];
    releaseCount = [lifeCounter arcSafeReleaseCount];

    { // Test that Retain.assign does not take a refcount.
        AutoId<LifetimeCounting, LifetimeRetain> auto1;
        auto1.attach(lifeCounter);
        EXPECT_EQ(0, [auto1 arcSafeRetainCount] - retainCount);
    }

    // Test that ~AutoId<..., Retain> releases a refcount even if it didn't take one.
    EXPECT_EQ(1, [lifeCounter arcSafeReleaseCount] - releaseCount);

    [lifeCounter destroy];
}

TEST(Starboard, AutoIdMoving_NoARC) {
    __unsafe_unretained LifetimeCounting* lifeCounter = [[LifetimeCounting alloc] init];
    unsigned int releaseCount = 0;
    unsigned int retainCount = 0;

    retainCount = [lifeCounter arcSafeRetainCount];
    releaseCount = [lifeCounter arcSafeReleaseCount];

    {
        AutoId<LifetimeCounting, LifetimeRetain> auto1(lifeCounter);
        EXPECT_EQ(1, [auto1 arcSafeRetainCount]);

        // Retain from a retain.
        AutoId<LifetimeCounting, LifetimeRetain> auto2(std::move(auto1));
        EXPECT_EQ(1, [auto2 arcSafeRetainCount]);
    }

    // AutoId is designed to disallow moves across different lifetimes, so we cannot UT them.

    // lifeCounter should only be released once.
    EXPECT_EQ(1, [lifeCounter arcSafeReleaseCount] - releaseCount);

    [lifeCounter destroy];
}
