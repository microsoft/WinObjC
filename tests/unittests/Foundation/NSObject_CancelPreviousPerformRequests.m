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

@interface TestObject : NSObject

@property (nonatomic) int foo;
@property (nonatomic) int bar;

- (void)incrementFoo;
- (void)incrementBar:(NSNumber*)amount;

@end

@implementation TestObject

- (void)incrementFoo {
    self.foo += 1;
}

- (void)incrementBar:(NSNumber*)amount {
    self.bar += [amount intValue];
}

@end

TEST(Foundation, NSObject_PerformSelectorAfterDelaySanity) {
    TestObject* testObject = [[TestObject alloc] init];

    [testObject performSelector:@selector(incrementFoo) withObject:nil afterDelay:1];
    [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:1.5]];

    ASSERT_EQ_MSG(testObject.foo, 1, "FAILED: selector not fired");
}

TEST(Foundation, NSObject_CancelPreviousPerformRequestsWithTarget) {
    TestObject* testObject = [[TestObject alloc] init];

    [testObject performSelector:@selector(incrementFoo) withObject:nil afterDelay:1];
    [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.5]];

    [NSObject cancelPreviousPerformRequestsWithTarget:testObject];
    [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:1]];

    ASSERT_EQ_MSG(testObject.foo, 0, "FAILED: perform request not cancelled");
}

TEST(Foundation, NSObject_CancelPreviousPerformRequestsWithTargetSelectorObject) {
    TestObject* testObject = [[TestObject alloc] init];
    NSNumber* amount = @(5);

    [testObject performSelector:@selector(incrementFoo) withObject:nil afterDelay:1];
    [testObject performSelector:@selector(incrementBar:) withObject:amount afterDelay:1];

    [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.5]];
    [NSObject cancelPreviousPerformRequestsWithTarget:testObject selector:@selector(incrementBar:) object:amount];
    [[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:1]];

    ASSERT_EQ_MSG(testObject.foo, 1, "FAILED: selector not fired");
    ASSERT_EQ_MSG(testObject.bar, 0, "FAILED: perform request not cancelled");
}

