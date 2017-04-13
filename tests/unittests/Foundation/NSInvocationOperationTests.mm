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

#import <TestFramework.h>
#import <Foundation/Foundation.h>

static NSString* _NSInvocationOperationTargetException = @"_NSInvocationOperationTargetException";

namespace {
struct _LargeStruct {
    unsigned long long a, b, c, d;
};
}

@interface _NSInvocationOperationTarget : NSObject
@property (nonatomic, readonly) BOOL voidReturnHit;
@end

@implementation _NSInvocationOperationTarget
+ (instancetype)target {
    return [[self new] autorelease];
}

- (void)methodWithOne:(id)one andTwoArguments:(id)two {
}

- (void)methodWithVoidReturn {
    _voidReturnHit = YES;
}

- (id)methodWithObjectReturn {
    return @"Hello";
}

- (id)methodWithObjectReturnAndArgument:(id)argument {
    return argument;
}

- (unsigned long long)methodWithUnsignedLongLongReturn {
    return 0xDEADBEEFCAFECAFEULL;
}

- (void)methodThatThrowsException {
    [NSException raise:_NSInvocationOperationTargetException format:@"I said, \"good day.\""];
}

- (NSString*)methodWithComplexSetOfStructs:(struct _LargeStruct)largeStruct andStrings:(NSString*)string {
    return [string stringByAppendingString:[NSString stringWithFormat:@"-%llu!", largeStruct.a]];
}
@end

TEST(NSInvocationOperation, InvalidInstantiations) {
    _NSInvocationOperationTarget* target = [_NSInvocationOperationTarget target];

    EXPECT_EQ(nil,
              [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodThatDoesNotExist) object:nil] autorelease]);

    // This initializer cannot handle methods with more than one additional argument.
    EXPECT_EQ(nil,
              [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodWithOne:andTwoArguments:) object:nil]
                  autorelease]);
}

TEST(NSInvocationOperation, InvalidStates) {
    _NSInvocationOperationTarget* target = [_NSInvocationOperationTarget target];

    NSInvocationOperation* cancelledOperation = nil;
    ASSERT_NO_THROW(
        cancelledOperation =
            [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodWithObjectReturn) object:nil] autorelease]);
    ASSERT_NE(nil, cancelledOperation);
    [cancelledOperation cancel];
    [cancelledOperation start];
    EXPECT_ANY_THROW([cancelledOperation result]); // Should throw an exception because it was cancelled before it could execute.

    NSInvocationOperation* voidReturnOperation = nil;
    ASSERT_NO_THROW(
        voidReturnOperation =
            [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodWithVoidReturn) object:nil] autorelease]);
    ASSERT_NE(nil, voidReturnOperation);
    [voidReturnOperation start];
    EXPECT_ANY_THROW([voidReturnOperation result]); // Should throw an exception because it has a void return.

    NSInvocationOperation* cancelledVoidReturnOperation = nil;
    ASSERT_NO_THROW(
        cancelledVoidReturnOperation =
            [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodWithVoidReturn) object:nil] autorelease]);
    ASSERT_NE(nil, cancelledVoidReturnOperation);
    [cancelledVoidReturnOperation cancel];
    [cancelledVoidReturnOperation start];
    EXPECT_ANY_THROW(
        [cancelledVoidReturnOperation result]); // Should throw an exception because it was cancelled, but really either exception would do.
}

TEST(NSInvocationOperation, VoidReturnNeverStarted) {
    _NSInvocationOperationTarget* target = [_NSInvocationOperationTarget target];

    NSInvocationOperation* operation = nil;
    ASSERT_NO_THROW(operation = [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodWithVoidReturn) object:nil]
                        autorelease]);
    ASSERT_NE(nil, operation);

    // This should not throw since the operation was never started.
    ASSERT_EQ(nil, [operation result]);
}

TEST(NSInvocationOperation, VoidReturn) {
    _NSInvocationOperationTarget* target = [_NSInvocationOperationTarget target];

    NSInvocationOperation* operation = nil;
    ASSERT_NO_THROW(operation = [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodWithVoidReturn) object:nil]
                        autorelease]);
    ASSERT_NE(nil, operation);

    EXPECT_NO_THROW([operation start]);

    ASSERT_TRUE(target.voidReturnHit);
}

// Objects are returned as objects
TEST(NSInvocationOperation, ObjectReturn) {
    _NSInvocationOperationTarget* target = [_NSInvocationOperationTarget target];

    NSInvocationOperation* operation = nil;
    ASSERT_NO_THROW(operation = [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodWithObjectReturn) object:nil]
                        autorelease]);
    ASSERT_NE(nil, operation);

    EXPECT_NO_THROW([operation start]);

    id result;
    ASSERT_NO_THROW(result = [operation result]);

    EXPECT_OBJCEQ(@"Hello", result);
}

// Objects are passed through unharmed
TEST(NSInvocationOperation, ObjectReturnWithArgument) {
    _NSInvocationOperationTarget* target = [_NSInvocationOperationTarget target];

    id originalObject = [[@"World" mutableCopy] autorelease];
    NSInvocationOperation* operation = nil;
    ASSERT_NO_THROW(operation = [[[NSInvocationOperation alloc] initWithTarget:target
                                                                      selector:@selector(methodWithObjectReturnAndArgument:)
                                                                        object:originalObject] autorelease]);
    ASSERT_NE(nil, operation);

    EXPECT_NO_THROW([operation start]);

    id result;
    ASSERT_NO_THROW(result = [operation result]);

    // pointer equality is important here
    EXPECT_EQ(originalObject, result);
}

// Anything that doesn't return an object returns an NSValue*
TEST(NSInvocationOperation, ValueBoxedReturn) {
    _NSInvocationOperationTarget* target = [_NSInvocationOperationTarget target];

    NSInvocationOperation* operation = nil;
    ASSERT_NO_THROW(
        operation = [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodWithUnsignedLongLongReturn) object:nil]
            autorelease]);
    ASSERT_NE(nil, operation);

    EXPECT_NO_THROW([operation start]);

    id result;
    ASSERT_NO_THROW(result = [operation result]);

    ASSERT_TRUE([result isKindOfClass:[NSValue class]]);

    unsigned long long value = 0;
    ASSERT_NO_THROW([static_cast<NSValue*>(result) getValue:&value]);

    EXPECT_EQ(0xDEADBEEFCAFECAFEULL, value);
}

// TODO #352
ARM_DISABLED_TEST(NSInvocationOperation, MethodThatThrowsException) {
    _NSInvocationOperationTarget* target = [_NSInvocationOperationTarget target];

    NSInvocationOperation* operation = nil;
    ASSERT_NO_THROW(
        operation =
            [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodThatThrowsException) object:nil] autorelease]);
    ASSERT_NE(nil, operation);

    // The exception will be thrown here, but caught and boxed.
    ASSERT_NO_THROW([operation start]);

    bool caughtException = false;
    @try {
        id result = [operation result];
    }
#ifdef _M_ARM // TODO #352 @catch(NSException*) fails on ARM
    @catch (...) {
        caughtException = true;
    }
#else
    @catch (NSException* e) {
        EXPECT_OBJCEQ(_NSInvocationOperationTargetException, e.name);
        caughtException = true;
    }
#endif

    ASSERT_TRUE(caughtException);
}

TEST(NSInvocationOperation, FreeformInvocation) {
    _NSInvocationOperationTarget* target = [_NSInvocationOperationTarget target];

    NSInvocation* invocation = [NSInvocation
        invocationWithMethodSignature:[target methodSignatureForSelector:@selector(methodWithComplexSetOfStructs:andStrings:)]];
    invocation.target = target;
    invocation.selector = @selector(methodWithComplexSetOfStructs:andStrings:);

    struct _LargeStruct arg1 {
        1, 2, 3, 4
    };
    id arg2 = @"Thing";

    // The implementation of this method returns the string second argument plus the first component of the large structure.

    [invocation setArgument:&arg1 atIndex:2];
    [invocation setArgument:&arg2 atIndex:3];

    NSInvocationOperation* operation = nil;
    ASSERT_NO_THROW(operation = [[[NSInvocationOperation alloc] initWithInvocation:invocation] autorelease]);
    ASSERT_NE(nil, operation);

    // The exception will be thrown here, but caught and boxed.
    ASSERT_NO_THROW([operation start]);

    EXPECT_OBJCEQ(@"Thing-1!", [operation result]);
}

TEST(NSInvocationOperation, ScheduledOnQueue) {
    NSOperationQueue* queue = [[NSOperationQueue new] autorelease];

    _NSInvocationOperationTarget* target = [_NSInvocationOperationTarget target];

    NSInvocationOperation* operation = nil;
    ASSERT_NO_THROW(operation = [[[NSInvocationOperation alloc] initWithTarget:target selector:@selector(methodWithObjectReturn) object:nil]
                        autorelease]);
    ASSERT_NE(nil, operation);

    ASSERT_EQ(nil, [operation result]);

    [queue addOperation:operation];

    [operation waitUntilFinished];

    ASSERT_TRUE([operation isFinished]);
    ASSERT_FALSE([operation isExecuting]);

    id result;
    ASSERT_NO_THROW(result = [operation result]);

    EXPECT_OBJCEQ(@"Hello", result);
}
