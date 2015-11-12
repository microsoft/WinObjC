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
#include "CFBridgeBase.h"
#include <Foundation/NSAutoreleasePool.h>

namespace {
    const int c_defaultState = 1234;
    bool g_destructorCalled = false;
}

struct CFTester : public CFBridgeBase<CFTester> {
    int _state = c_defaultState;

    CFTester() {
    }

    CFTester(int param) {
        _state = param;
    }

    ~CFTester() {
        g_destructorCalled = true;
    }
};
typedef CFTester *CFTesterRef;

@interface NSTester : NSObject
@end

CFTesterRef CFTesterCreate() {
    return CFTester::alloc([NSTester class]);
}

CFTesterRef CFTesterCreateWithState(int state) {
    return CFTester::alloc([NSTester class], state);
}

int CFTesterGetState(CFTesterRef tester) {
    return tester->_state;
}

@implementation NSTester
+ (instancetype)allocWithZone:(NSZone*)zone {
    return reinterpret_cast<id>(CFTesterCreate());
}

+ (instancetype)testerWithState:(int)state {
    return [reinterpret_cast<id>(CFTesterCreateWithState(state)) autorelease];
}

- (void)dealloc {
    bridgeDealloc(self);
    [super dealloc];
}

- (instancetype)init {
    return self;
}

- (int)state {
    return CFTesterGetState(reinterpret_cast<CFTesterRef>(self));
}
@end

TEST(Foundation, CFBridgeBase_Test) {
    CFTesterRef tester = CFTesterCreate();
    ASSERT_EQ_MSG(tester->_state, c_defaultState, "Default-constructed state incorrect");
    ASSERT_EQ_MSG(CFTesterGetState(tester), [reinterpret_cast<NSTester*>(tester) state], "Toll-free state access inconsistent");

    g_destructorCalled = false;
    CFRelease(tester);
    ASSERT_EQ_MSG(g_destructorCalled, true, "Destructor must be called after releasing");
}

TEST(Foundation, NSBridgeBase_Test) {
    id pool = [NSAutoreleasePool new];

    const int c_stateInitVal = 4321;

    NSTester* tester = [NSTester testerWithState:c_stateInitVal];
    ASSERT_EQ_MSG([tester state], c_stateInitVal, "Default-constructed state incorrect");
    ASSERT_EQ_MSG([tester state], reinterpret_cast<CFTesterRef>(tester)->_state, "Toll-free state access inconsistent");
    ASSERT_EQ_MSG([tester state], CFTesterGetState(reinterpret_cast<CFTesterRef>(tester)), "Toll-free function call result inconsistent");

    g_destructorCalled = false;
    [pool release];
    ASSERT_EQ_MSG(g_destructorCalled, true, "Destructor must be called after releasing");
}

@interface NSBadBridgeTester : NSObject
@end

@implementation NSBadBridgeTester {
    int _hasIvars;
}
@end

TEST(Foundation, NSBridgeBase_WithIvars) {
    ASSERT_ANY_THROW(CFTester::alloc([NSBadBridgeTester class]));
}

TEST(Foundation, NSBridgeBase_NoNSClass) {
    auto tester = CFTester::alloc(nil);
    g_destructorCalled = false;
    CFRelease(tester);

    ASSERT_EQ_MSG(g_destructorCalled, true, "Destructor must be called after releasing");

    tester = CFTester::alloc(nil);
    g_destructorCalled = false;
    [(id)tester release];

    ASSERT_EQ_MSG(g_destructorCalled, true, "Destructor must be called after using -release");
}
