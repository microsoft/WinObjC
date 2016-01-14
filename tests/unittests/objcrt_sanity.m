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

TEST(NSObjectTest, AllocationSanity) {
    NSObject* obj1 = [NSObject new];
    NSObject* obj2 = [NSObject new];

    // obj1 and obj2 should be distinct pointers!
    EXPECT_NE_MSG(obj1, obj2, "obj1 and obj2 should be distinct pointers!");

    [obj1 release];
    [obj2 release];
}

template <int* destructCounter>
struct cxxDestruct {
    ~cxxDestruct() {
        *destructCounter = *destructCounter + 1;
    }
};

static int destructCounterA = 0;
@interface CxxDestructA : NSObject {
    cxxDestruct<&destructCounterA> member;
}
@end
@implementation CxxDestructA
@end

static int destructCounterB = 0;
@interface CxxDestructB : CxxDestructA {
    cxxDestruct<&destructCounterB> memberB;
}
@end
@implementation CxxDestructB
@end

static int destructCounterLiar = 0;
@interface CxxDestructLiar : CxxDestructA {
    cxxDestruct<&destructCounterLiar> memberLiar;
}
@end
@implementation CxxDestructLiar
- (Class) class {
    return [CxxDestructA class];
} @end

    // A class that is lying about its true identity
    // needs to be destructed in the same manner as one that is not.
    // That is to say: A class that says "I am A" should *NOT* get its destructor skipped.
    TEST(Objcrt, CxxDestructionHierarchy) {
    destructCounterA = destructCounterB = 0;
    [[CxxDestructB alloc] release];
    EXPECT_EQ_MSG(destructCounterA, 1, "An instance of CxxDestructB should have triggered a C++ dtor inside CxxDestructA");
    EXPECT_EQ_MSG(destructCounterA, destructCounterB, "An instance of CxxDestructB should be destructed as many times as its superclass.");

    destructCounterA = destructCounterLiar = 0;
    [[CxxDestructLiar alloc] release];
    EXPECT_EQ_MSG(destructCounterA, 1, "An instance of CxxDestructLiar should have triggered a C++ dtor inside CxxDestructA");
    EXPECT_EQ_MSG(destructCounterA,
                  destructCounterLiar,
                  "An instance of CxxDestructLiar should be destructed as many times as its superclass.");
}

// TODO: Switch to ARC and make sure the object is destructed when
// it goes out of scope