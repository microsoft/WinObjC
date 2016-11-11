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

#include <TestFramework.h>
#include <CFCppBase.h>

struct __CFBoringClass : CoreFoundation::CppBase<__CFBoringClass> {};

struct __CFLifetimeCounter : CoreFoundation::CppBase<__CFLifetimeCounter> {
    int& ctorCountReference;
    int& dtorCountReference;

    __CFLifetimeCounter(int& ctorCounter, int& dtorCounter) : ctorCountReference(ctorCounter), dtorCountReference(dtorCounter) {
        ++ctorCountReference;
    }

    ~__CFLifetimeCounter() {
        ++dtorCountReference;
    }
};

struct __CFSubLifetimeCounter : CoreFoundation::CppBase<__CFSubLifetimeCounter, __CFLifetimeCounter> {
    __CFSubLifetimeCounter(int& ctorCounter, int& dtorCounter) : Parent(ctorCounter, dtorCounter) {
        ++ctorCountReference;
    }

    ~__CFSubLifetimeCounter() {
        ++dtorCountReference;
    }
};

TEST(CFCppBase, TypeIDIsStable) {
    CFTypeID baseTypeID = __CFLifetimeCounter::GetTypeID();
    CFTypeID otherBaseTypeID = __CFLifetimeCounter::GetTypeID();
    ASSERT_EQ(baseTypeID, otherBaseTypeID);
}

TEST(CFCppBase, SubclassesGetDifferentTypeIDs) {
    CFTypeID baseTypeID = __CFLifetimeCounter::GetTypeID();
    CFTypeID derivedTypeID = __CFSubLifetimeCounter::GetTypeID();
    ASSERT_NE(baseTypeID, derivedTypeID);
}

TEST(CFCppBase, InstanceHasTypeID) {
    CFTypeRef boringInstance = __CFBoringClass::CreateInstance();
    ASSERT_EQ(__CFBoringClass::GetTypeID(), CFGetTypeID(boringInstance));
    EXPECT_NO_THROW(CFRelease(boringInstance));
}

TEST(CFCppBase, InstanceLifetime) {
    int ctorCount = 0;
    int dtorCount = 0;
    CFTypeRef counter = __CFLifetimeCounter::CreateInstance(kCFAllocatorDefault, ctorCount, dtorCount);

    ASSERT_EQ(1, ctorCount);
    ASSERT_EQ(0, dtorCount);

    EXPECT_NO_THROW(CFRetain(counter));

    ASSERT_EQ(1, ctorCount);
    ASSERT_EQ(0, dtorCount);

    EXPECT_NO_THROW(CFRelease(counter));
    EXPECT_NO_THROW(CFRelease(counter));

    ASSERT_EQ(1, ctorCount);
    ASSERT_EQ(1, dtorCount);
}

TEST(CFCppBase, DerivedInstanceLifetime) {
    int ctorCount = 0;
    int dtorCount = 0;
    CFTypeRef counter = __CFSubLifetimeCounter::CreateInstance(kCFAllocatorDefault, ctorCount, dtorCount);

    ASSERT_EQ(2, ctorCount);
    ASSERT_EQ(0, dtorCount);

    EXPECT_NO_THROW(CFRetain(counter));

    ASSERT_EQ(2, ctorCount);
    ASSERT_EQ(0, dtorCount);

    EXPECT_NO_THROW(CFRelease(counter));
    EXPECT_NO_THROW(CFRelease(counter));

    ASSERT_EQ(2, ctorCount);
    ASSERT_EQ(2, dtorCount);
}