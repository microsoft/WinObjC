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
#include <objc/runtime.h>
#include <exception>

#define ASSERT_BLOCK(msg, ...)         \
    {                                  \
        auto block = __VA_ARGS__;      \
        ASSERT_TRUE_MSG(block(), msg); \
    }
#define ASSERT_BLOCK_FAIL(msg, ...)     \
    {                                   \
        auto block = __VA_ARGS__;       \
        ASSERT_FALSE_MSG(block(), msg); \
    }

@interface RetainCounting : NSObject {
    unsigned rc;
}
- (unsigned)retainCount;
@end
@implementation RetainCounting
- (id)retain {
    rc++;
    return [super retain];
}
- (oneway void)release {
    rc--;
    [super release];
}
- (unsigned)retainCount {
    return rc;
}
@end

@interface DeallocNotifying : NSObject {
    void (^block)();
}
+ (id)withBlock:(void (^)())block;
@end
@implementation DeallocNotifying
+ (id)withBlock:(void (^)())block {
    DeallocNotifying* n = [[self alloc] init];
    n->block = [block copy];
    return n;
}
- (void)dealloc {
    block();
    [super dealloc];
}
@end

@interface Copyable : NSObject <NSCopying>
@end
@implementation Copyable
- (id)copyWithZone:(NSZone*)zone {
    return [[[self class] allocWithZone:zone] init];
}
@end

TEST(Objcrt, AssociatedObjects) {
    // Associated object keys are bare pointers, so we use the addresses of these three static variables
    // to ensure key stability within this file.
    static char associatedObjectKeyA;
    static char associatedObjectKeyB;
    static char associatedObjectKeyC;

    ASSERT_BLOCK("can associate and retrieve an object (assign)",
                 ^bool {
                     NSObject* instance = [NSObject alloc];
                     NSObject* associatedObject = [NSObject alloc];
                     objc_setAssociatedObject(instance, &associatedObjectKeyA, associatedObject, OBJC_ASSOCIATION_ASSIGN);
                     return objc_getAssociatedObject(instance, &associatedObjectKeyA) == associatedObject;
                 });
    ASSERT_BLOCK("can associate objects w/ multiple keys and not stomp them",
                 ^bool {
                     NSObject* instance = [NSObject alloc];
                     NSObject* associatedObject = [NSObject alloc];
                     NSObject* associatedObject2 = [NSObject alloc];
                     objc_setAssociatedObject(instance, &associatedObjectKeyA, associatedObject, OBJC_ASSOCIATION_ASSIGN);
                     objc_setAssociatedObject(instance, &associatedObjectKeyB, associatedObject2, OBJC_ASSOCIATION_ASSIGN);
                     return objc_getAssociatedObject(instance, &associatedObjectKeyA) == associatedObject &&
                            objc_getAssociatedObject(instance, &associatedObjectKeyB) == associatedObject2;
                 });
    ASSERT_BLOCK("can associate and retrieve an object (retain)",
                 ^bool {
                     NSObject* instance = [NSObject alloc];
                     NSObject* associatedObject = [NSObject alloc];
                     objc_setAssociatedObject(instance, &associatedObjectKeyA, associatedObject, OBJC_ASSOCIATION_RETAIN);
                     return objc_getAssociatedObject(instance, &associatedObjectKeyA) == associatedObject;
                 });
    ASSERT_BLOCK("an assigned associated object has a the same retain count",
                 ^bool {
                     NSObject* instance = [NSObject alloc];
                     RetainCounting* associatedObject = [RetainCounting alloc];
                     int rc = [associatedObject retainCount];
                     objc_setAssociatedObject(instance, &associatedObjectKeyA, associatedObject, OBJC_ASSOCIATION_ASSIGN);
                     return [associatedObject retainCount] == rc;
                 });
    ASSERT_BLOCK("a retained associated object has a different retain count",
                 ^bool {
                     NSObject* instance = [NSObject alloc];
                     RetainCounting* associatedObject = [RetainCounting alloc];
                     int rc = [associatedObject retainCount];
                     objc_setAssociatedObject(instance, &associatedObjectKeyA, associatedObject, OBJC_ASSOCIATION_RETAIN);
                     return [associatedObject retainCount] != rc;
                 });
    ASSERT_BLOCK("assigning with copy actually yields a copy",
                 ^bool {
                     NSObject* instance = [NSObject alloc];
                     NSObject* associatedObject = [Copyable new];
                     objc_setAssociatedObject(instance, &associatedObjectKeyA, associatedObject, OBJC_ASSOCIATION_COPY);
                     return objc_getAssociatedObject(instance, &associatedObjectKeyA) != associatedObject;
                 });
    ASSERT_BLOCK("assigning over a retained object results in its destruction",
                 ^bool {
                     NSObject* instance = [NSObject alloc];
                     __block bool dealloced = false;
                     NSObject* associatedObject = [DeallocNotifying withBlock:^{
                         dealloced = true;
                     }];
                     objc_setAssociatedObject(instance, &associatedObjectKeyA, associatedObject, OBJC_ASSOCIATION_RETAIN);
                     [associatedObject release]; // Kill our reference to it so the next assign releases it.
                     if (dealloced)
                         return false;

                     objc_setAssociatedObject(instance, &associatedObjectKeyA, nil, OBJC_ASSOCIATION_ASSIGN);
                     return dealloced;
                 });
    ASSERT_BLOCK("releasing an object with retained associates destroys them all",
                 ^bool {
                     NSObject* instance = [NSObject alloc];
                     __block bool dealloced0 = false, dealloced1 = false, dealloced2 = false;
                     NSObject* associatedObject0 = [DeallocNotifying withBlock:^{
                         dealloced0 = true;
                     }];
                     NSObject* associatedObject1 = [DeallocNotifying withBlock:^{
                         dealloced1 = true;
                     }];
                     NSObject* associatedObject2 = [DeallocNotifying withBlock:^{
                         dealloced2 = true;
                     }];
                     objc_setAssociatedObject(instance, &associatedObjectKeyA, associatedObject0, OBJC_ASSOCIATION_RETAIN);
                     objc_setAssociatedObject(instance, &associatedObjectKeyB, associatedObject1, OBJC_ASSOCIATION_RETAIN);
                     objc_setAssociatedObject(instance, &associatedObjectKeyC, associatedObject2, OBJC_ASSOCIATION_RETAIN);
                     [associatedObject0 release];
                     [associatedObject1 release];
                     [associatedObject2 release];
                     if (dealloced0 || dealloced1 || dealloced2)
                         return false;

                     [instance release];
                     return dealloced0 && dealloced1 && dealloced2;
                 });
}
