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

#import "TestFramework.h"
#import <Foundation/Foundation.h>
#import <memory>
#import <type_traits>

struct UniformAggregateF1 {
    float m1;
    bool operator==(const UniformAggregateF1& other) const {
        return m1 == other.m1;
    }
};

struct UniformAggregateD1 {
    double m1;
    bool operator==(const UniformAggregateD1& other) const {
        return m1 == other.m1;
    }
};

struct UniformAggregateF2 {
    float m1;
    float m2;
    bool operator==(const UniformAggregateF2& other) const {
        return m1 == other.m1 && m2 == other.m2;
    }
};

struct UniformAggregateD2 {
    double m1;
    double m2;
    bool operator==(const UniformAggregateD2& other) const {
        return m1 == other.m1 && m2 == other.m2;
    }
};

struct UniformAggregateF3 {
    UniformAggregateF1 m1;
    UniformAggregateF2 m2;
    bool operator==(const UniformAggregateF3& other) const {
        return m1 == other.m1 && m2 == other.m2;
    }
};

struct UniformAggregateD3 {
    UniformAggregateD1 m1;
    UniformAggregateD2 m2;
    bool operator==(const UniformAggregateD3& other) const {
        return m1 == other.m1 && m2 == other.m2;
    }
};

struct UniformAggregateF4 {
    UniformAggregateF2 m1;
    UniformAggregateF2 m2;
    bool operator==(const UniformAggregateF4& other) const {
        return m1 == other.m1 && m2 == other.m2;
    }
};

struct UniformAggregateD4 {
    UniformAggregateD2 m1;
    UniformAggregateD2 m2;
    bool operator==(const UniformAggregateD4& other) const {
        return m1 == other.m1 && m2 == other.m2;
    }
};

struct DisparateAggregateDF {
    double m1;
    float m2;
    bool operator==(const DisparateAggregateDF& other) const {
        return m1 == other.m1 && m2 == other.m2;
    }
};

struct LargeUniformAggregateF6 {
    float m1;
    float m2;
    UniformAggregateF4 m3;
    bool operator==(const LargeUniformAggregateF6& other) const {
        return m1 == other.m1 && m2 == other.m2 && m3 == other.m3;
    }
};

struct LargeDisparateAggregate {
    int m1;
    double m2;
    const wchar_t* m3;
    bool operator==(const LargeDisparateAggregate& other) const {
        return m1 == other.m1 && m2 == other.m2 && m3 == other.m3;
    }
};

struct SmallDisparateAggregate8 { // on x86 only, this will be returned in registers.
    uint8_t m1;
    uint32_t m2;
    bool operator==(const SmallDisparateAggregate8& other) const {
        return m1 == other.m1 && m2 == other.m2;
    }
};

struct SmallDisparateAggregate4 { // on x86 and ARM, this will be returned in registers.
    uint8_t m1;
    uint16_t m2;
    bool operator==(const SmallDisparateAggregate4& other) const {
        return m1 == other.m1 && m2 == other.m2;
    }
};

@interface NSIT_InvocationTestClass : NSObject
@property (nonatomic, assign) UniformAggregateF1 uniformAggregateF1;
@property (nonatomic, assign) UniformAggregateD1 uniformAggregateD1;
@property (nonatomic, assign) UniformAggregateF2 uniformAggregateF2;
@property (nonatomic, assign) UniformAggregateD2 uniformAggregateD2;
@property (nonatomic, assign) UniformAggregateF3 uniformAggregateF3;
@property (nonatomic, assign) UniformAggregateD3 uniformAggregateD3;
@property (nonatomic, assign) UniformAggregateF4 uniformAggregateF4;
@property (nonatomic, assign) UniformAggregateD4 uniformAggregateD4;
@property (nonatomic, assign) DisparateAggregateDF disparateAggregateDF;
@property (nonatomic, assign) LargeUniformAggregateF6 largeUniformAggregateF6;
@property (nonatomic, assign) LargeDisparateAggregate largeDisparateAggregate;
@property (nonatomic, assign) SmallDisparateAggregate8 smallDisparateAggregate8;
@property (nonatomic, assign) SmallDisparateAggregate4 smallDisparateAggregate4;
@end
@implementation NSIT_InvocationTestClass
// properties synthesized here
@end

#define SET_AND_TEST(object, prop, ...)                                               \
    do {                                                                              \
        object.prop = __VA_ARGS__;                                                    \
        _testInvocation<decltype(object.prop)>(object, @selector(prop), __VA_ARGS__); \
                                                                                      \
    } while (0)

template <typename T>
static void _testInvocation(id object, SEL selector, T value) {
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:[object methodSignatureForSelector:selector]];
    invocation.target = object;
    invocation.selector = selector;
    [invocation invoke];

    T returnedValue;
    [invocation getReturnValue:&returnedValue];

    EXPECT_EQ_MSG(returnedValue, value, "property %s did not match.", sel_getName(selector));
}

TEST(NSInvocation, AggregateReturn) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];

    SET_AND_TEST(tester, uniformAggregateF1, { std::numeric_limits<float>::max() });
    SET_AND_TEST(tester, uniformAggregateD1, { std::numeric_limits<double>::max() });

    SET_AND_TEST(tester, uniformAggregateF2, { std::numeric_limits<float>::max(), 1024.f });
    SET_AND_TEST(tester, uniformAggregateD2, { std::numeric_limits<double>::max(), 2048. });

    SET_AND_TEST(tester, uniformAggregateF3, { { std::numeric_limits<float>::max() }, { 1024.f, 8192.f } });
    SET_AND_TEST(tester, uniformAggregateD3, { { std::numeric_limits<double>::max() }, { 2048., 16384. } });

    SET_AND_TEST(tester, uniformAggregateF4, { { std::numeric_limits<float>::max(), 1.f }, { 1024.f, 8192.f } });
    SET_AND_TEST(tester, uniformAggregateD4, { { std::numeric_limits<double>::max(), 2.f }, { 2048., 16384. } });

    SET_AND_TEST(tester, disparateAggregateDF, { 1.0, 2.0f });

    SET_AND_TEST(tester, largeUniformAggregateF6, { 1.f, 2.f, { { 4.f, 8.f }, { 16.f, 32.f } } });

    const wchar_t hello[] = L"hello";
    SET_AND_TEST(tester, largeDisparateAggregate, { 1048576, -1.0, hello });

    SET_AND_TEST(tester, smallDisparateAggregate8, { '\x7f', 0xafafafaf });

    SET_AND_TEST(tester, smallDisparateAggregate4, { '\x1f', 0xbeef });

    [tester release];
}

ARM_DISABLED_TEST(NSInvocation, ArgumentLimit) {
    SEL selector = @selector(initWithFormat:locale:);
    NSString* s = [[NSString alloc] initWithString:@"hello"];
    NSString* format = @"%@";
    NSMethodSignature* sig = [s methodSignatureForSelector:selector];
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];
    [invocation setSelector:selector];
    [invocation setTarget:s];

    BOOL exceptionThrown = NO;
    [invocation setArgument:format atIndex:2];
    @try {
        [invocation setArgument:@"foo" atIndex:4];
    } @catch (NSException* exception) {
        exceptionThrown = (([[exception name] isEqual:NSInvalidArgumentException]) ? YES : NO);
    }
    ASSERT_TRUE_MSG(exceptionThrown, "FAILED: NSInvalidArgumentException was not thrown.");

    ASSERT_ANY_THROW([invocation setArgument:@"foo" atIndex:-1]);
}

ARM_DISABLED_TEST(NSInvocation, PropertyMethod) {
    SEL selector = @selector(length);
    NSString* st = @"hello";
    NSMethodSignature* sig = [st methodSignatureForSelector:selector];
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];
    [invocation setSelector:selector];
    [invocation setTarget:st];

    BOOL exceptionThrown = NO;

    @try {
        [invocation setArgument:@"test" atIndex:2];
    } @catch (NSException* exception) {
        exceptionThrown = (([[exception name] isEqual:NSInvalidArgumentException]) ? YES : NO);
    }
    ASSERT_TRUE_MSG(exceptionThrown, "FAILED: NSInvalidArgumentException was not thrown.");
}