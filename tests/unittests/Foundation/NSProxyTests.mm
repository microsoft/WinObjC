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

#import <Foundation/Foundation.h>
#import <TestFramework.h>

// Ignore warnings about functions in this test class not having method definitions - they work through forwarding to forwardArray
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wincomplete-implementation"

// A basic NSProxy for testing that forwards to a NSMutableArray without retaining it
@interface _NSTestMutableArrayProxy : NSProxy
- (instancetype)initWithMutableArray:(NSMutableArray*)array;
@end

@interface _NSTestMutableArrayProxy ()
@property (readonly, assign) NSMutableArray* forwardArray; // Not retained

// NSArray functions that are forwarded (Suppresses 'may not respond to' warnings)
- (NSUInteger)count;
- (id)objectAtIndex:(NSUInteger)index;
- (void)addObject:(id)anObject;
- (void)insertObject:(id)anObject atIndex:(NSUInteger)index;
@end

@implementation _NSTestMutableArrayProxy

- (instancetype)initWithMutableArray:(NSMutableArray*)array {
    // NSProxy subclasses do not/should not/cannot call [super init], as NSProxy is an abstract class that does not have an init
    self->_forwardArray = array;
    return self;
}

- (void)forwardInvocation:(NSInvocation*)invocation {
    [invocation invokeWithTarget:_forwardArray];
}

- (NSMethodSignature*)methodSignatureForSelector:(SEL)sel {
    return [_forwardArray methodSignatureForSelector:sel];
}
@end

#pragma clang diagnostic pop

TEST(NSProxy, NSProxy) {
    NSMutableArray* array = [NSMutableArray array];
    @autoreleasepool {
        _NSTestMutableArrayProxy* proxy = [[[_NSTestMutableArrayProxy alloc] initWithMutableArray:array] autorelease];

        ASSERT_NE(nil, proxy);
        ASSERT_TRUE([proxy isProxy]);

        // Check that the proxy correctly reports the functions it responds to (- respondsToSelector: should forward)
        EXPECT_TRUE([proxy respondsToSelector:@selector(count)]);
        EXPECT_FALSE([proxy respondsToSelector:@selector(notAnArrayFunction)]);

        // Undeclared member function in proxy, but should return YES since NSArray supports it
        EXPECT_TRUE([proxy respondsToSelector:@selector(indexOfObjectIdenticalTo:inRange:)]);

        // Check that NSMutableArray member functions are forwarded
        [proxy addObject:@0];
        EXPECT_EQ(1, [proxy count]);
        EXPECT_EQ(1, [array count]);
        EXPECT_OBJCEQ(@0, [proxy objectAtIndex:0]);
        EXPECT_OBJCEQ(@0, [array objectAtIndex:0]);

        [proxy addObject:@2];
        [proxy insertObject:@1 atIndex:1];
        EXPECT_EQ(3, [proxy count]);
        EXPECT_EQ(3, [array count]);

        EXPECT_OBJCEQ(@1, [proxy objectAtIndex:1]);
        EXPECT_OBJCEQ(@1, [array objectAtIndex:1]);
        EXPECT_OBJCEQ(@2, [proxy objectAtIndex:2]);
        EXPECT_OBJCEQ(@2, [array objectAtIndex:2]);

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-method-access"
        // Unknown member functions should throw
        EXPECT_ANY_THROW([proxy notAnArrayFunction]);
#pragma clang diagnostic pop

        // - isKindOfClass:, - isMemberOfClass:, and - conformsToProtocol: should forward
        EXPECT_TRUE([proxy isKindOfClass:[NSArray class]]);
        EXPECT_TRUE([proxy isMemberOfClass:[array class]]);
        EXPECT_TRUE([proxy conformsToProtocol:@protocol(NSFastEnumeration)]);
        EXPECT_FALSE([proxy isKindOfClass:[_NSTestMutableArrayProxy class]]);
        EXPECT_FALSE([proxy isMemberOfClass:[_NSTestMutableArrayProxy class]]);

        // + respondsToSelector: should not forward
        EXPECT_TRUE([_NSTestMutableArrayProxy respondsToSelector:@selector(class)]);
        EXPECT_FALSE([_NSTestMutableArrayProxy respondsToSelector:@selector(count)]);
        EXPECT_FALSE([_NSTestMutableArrayProxy respondsToSelector:@selector(notAnArrayFunction)]);
        EXPECT_FALSE([_NSTestMutableArrayProxy respondsToSelector:@selector(indexOfObjectIdenticalTo:inRange:)]);

        // + class should not forward
        EXPECT_NE([array class], [_NSTestMutableArrayProxy class]);
        EXPECT_NE([NSMutableArray class], [_NSTestMutableArrayProxy class]);
        EXPECT_NE(nil, [_NSTestMutableArrayProxy class]);

        // - class should not forward
        EXPECT_NE([array class], [proxy class]);
        EXPECT_EQ([_NSTestMutableArrayProxy class], [proxy class]);
        EXPECT_NE(nil, [proxy class]);

        // + superclass should not forward
        EXPECT_EQ([NSProxy class], [_NSTestMutableArrayProxy superclass]);
        EXPECT_NE([NSMutableArray class], [_NSTestMutableArrayProxy superclass]);
        EXPECT_NE(nil, [_NSTestMutableArrayProxy superclass]);

        // - superclass should not forward
        EXPECT_EQ([NSProxy class], [proxy superclass]);
        EXPECT_NE([NSMutableArray class], [proxy superclass]);
        EXPECT_NE(nil, [proxy superclass]);

        // - description and - debugDescription should not forward
        EXPECT_NE(nil, [proxy description]);
        EXPECT_NE(nil, [proxy debugDescription]);
        EXPECT_OBJCNE([array description], [proxy description]);
        EXPECT_OBJCNE([array debugDescription], [proxy debugDescription]);

        // - isEqual: should not forward
        NSMutableArray* array2 = [[@[ @0, @1, @2 ] mutableCopy] autorelease];
        EXPECT_OBJCEQ(array, array2);
        EXPECT_OBJCNE(proxy, array2);

        // - hash should not forward
        EXPECT_NE([array hash], [proxy hash]);

        // - self should not forward
        EXPECT_EQ(proxy, [proxy self]);

        // retain should not forward
        NSUInteger arrayRetainCount = [array retainCount];
        NSUInteger proxyRetainCount = [proxy retainCount];
        [proxy retain];
        EXPECT_EQ(arrayRetainCount, [array retainCount]);
        EXPECT_EQ(++proxyRetainCount, [proxy retainCount]);

        // release should not forward
        [proxy release];
        EXPECT_EQ(arrayRetainCount, [array retainCount]);
        EXPECT_EQ(--proxyRetainCount, [proxy retainCount]);
    }

    // autorelease should not forward
    // Autoreleasing the proxy should not dealloc the array
    EXPECT_NE(nil, array);
}