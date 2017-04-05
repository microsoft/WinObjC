//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#import <Starboard/SmartTypes.h>
#import <Foundation/Foundation.h>

// Avoid "property access result unused" warnings by _consume-ing the value of a property accessor.
template <typename... T>
static inline void _consume(T&&...) {
}

TEST(NSNotification, CanCreate) {
    EXPECT_OBJCNE(nil, [NSNotification notificationWithName:@"name" object:nil userInfo:nil]);
}

@interface BadNSNotificationSubclass : NSNotification
@end
@implementation BadNSNotificationSubclass
- (id)init {
    // NSNotification subclasses are barred from calling [super init].
    return self;
}
@end

TEST(NSNotification, InvalidSubclassThrows) {
    EXPECT_ANY_THROW([BadNSNotificationSubclass notificationWithName:@"name" object:nil userInfo:nil]);

    BadNSNotificationSubclass* bad = [[BadNSNotificationSubclass alloc] init];
    EXPECT_ANY_THROW(_consume(bad.name));
    EXPECT_ANY_THROW(_consume(bad.userInfo));
    EXPECT_ANY_THROW(_consume(bad.object));

    [bad release];
}

TEST(NSNotification, CanEncodeAndDecode) {
    NSNotification* notification = [NSNotification notificationWithName:@"Name1" object:@"Object1" userInfo:@{ @"Key1" : @"Value1" }];
    NSData* data = nil;
    ASSERT_NO_THROW(data = [NSKeyedArchiver archivedDataWithRootObject:notification]);

    NSNotification* newNotification = nil;
    ASSERT_NO_THROW(newNotification = [NSKeyedUnarchiver unarchiveObjectWithData:data]);

    EXPECT_NE(notification,
              newNotification); // pointer comparison: notifications cannot be compared with isEqual:, and this should be a new instance.

    EXPECT_OBJCEQ(notification.name, newNotification.name);
    EXPECT_OBJCEQ(notification.object, newNotification.object);
    EXPECT_OBJCEQ(notification.userInfo, newNotification.userInfo);
}

@interface TestObjectA : NSObject
@end

@implementation TestObjectA
- (void)dealloc {
    [[NSNotificationCenter defaultCenter] postNotificationName:@"MOOSENOTIFICATION" object:self];
    [super dealloc];
}

@end

TEST(NSNotificationCenter, PostNotificationFromDealloc) {
    TestObjectA* obj = [[TestObjectA new] autorelease];
}
