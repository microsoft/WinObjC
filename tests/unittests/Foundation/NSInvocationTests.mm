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
@property (nonatomic, assign) char singleChar;
@property (nonatomic, assign) short singleShort;
@property (nonatomic, assign) int singleInt;
@property (nonatomic, assign) long long singleLongLong;
@property (nonatomic, assign) unsigned char singleUChar;
@property (nonatomic, assign) unsigned short singleUShort;
@property (nonatomic, assign) unsigned int singleUInt;
@property (nonatomic, assign) unsigned long long singleULongLong;
@property (nonatomic, assign) float singleFloat;
@property (nonatomic, assign) double singleDouble;

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

#define SET_AND_GET_VIA_INVOCATION(object, prop, ...)                                               \
    do {                                                                              \
        object.prop = __VA_ARGS__;                                                    \
        _testGetViaInvocation<decltype(object.prop)>(object, @selector(prop), __VA_ARGS__); \
                                                                                      \
    } while (0)

template <typename T>
static void _testGetViaInvocation(id object, SEL selector, T value) {
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:[object methodSignatureForSelector:selector]];
    invocation.target = object;
    invocation.selector = selector;
    [invocation invoke];

    T returnedValue;
	// To avoid artifacts, stomp the buffer before we read into it.
	memset(&returnedValue, 0xCD, sizeof(T));
    [invocation getReturnValue:&returnedValue];

    EXPECT_EQ_MSG(returnedValue, value, "property %s did not match.", sel_getName(selector));
}

TEST(NSInvocation, AggregateReturn) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];

    SET_AND_GET_VIA_INVOCATION(tester, singleChar, (char)0x3);
    SET_AND_GET_VIA_INVOCATION(tester, singleChar, (char)-12);
    SET_AND_GET_VIA_INVOCATION(tester, singleUChar, (unsigned char)0x3U);

    SET_AND_GET_VIA_INVOCATION(tester, singleShort, (short)0xABAB);
    SET_AND_GET_VIA_INVOCATION(tester, singleShort, (short)-1024);
    SET_AND_GET_VIA_INVOCATION(tester, singleUShort, (unsigned short)0xCDEFU);

    SET_AND_GET_VIA_INVOCATION(tester, singleInt, (int)1048576);
    SET_AND_GET_VIA_INVOCATION(tester, singleInt, (int)-70000);
    SET_AND_GET_VIA_INVOCATION(tester, singleUInt, (unsigned int)0xABCDEFU);

    SET_AND_GET_VIA_INVOCATION(tester, singleLongLong, (long long)(1024LL*1024LL*1024LL*1048576LL));
    SET_AND_GET_VIA_INVOCATION(tester, singleLongLong, (long long)(-1LL*(1024LL*1024LL*1024LL*1048576LL)));
    SET_AND_GET_VIA_INVOCATION(tester, singleULongLong, (unsigned long long)0xABCDEF010203ULL);

	SET_AND_GET_VIA_INVOCATION(tester, singleFloat, 1024.0f);
	SET_AND_GET_VIA_INVOCATION(tester, singleDouble, 2048.0);

    SET_AND_GET_VIA_INVOCATION(tester, uniformAggregateF1, { std::numeric_limits<float>::max() });
    SET_AND_GET_VIA_INVOCATION(tester, uniformAggregateD1, { std::numeric_limits<double>::max() });

    SET_AND_GET_VIA_INVOCATION(tester, uniformAggregateF2, { std::numeric_limits<float>::max(), 1024.f });
    SET_AND_GET_VIA_INVOCATION(tester, uniformAggregateD2, { std::numeric_limits<double>::max(), 2048. });

    SET_AND_GET_VIA_INVOCATION(tester, uniformAggregateF3, { { std::numeric_limits<float>::max() }, { 1024.f, 8192.f } });
    SET_AND_GET_VIA_INVOCATION(tester, uniformAggregateD3, { { std::numeric_limits<double>::max() }, { 2048., 16384. } });

    SET_AND_GET_VIA_INVOCATION(tester, uniformAggregateF4, { { std::numeric_limits<float>::max(), 1.f }, { 1024.f, 8192.f } });
    SET_AND_GET_VIA_INVOCATION(tester, uniformAggregateD4, { { std::numeric_limits<double>::max(), 2.f }, { 2048., 16384. } });

    SET_AND_GET_VIA_INVOCATION(tester, disparateAggregateDF, { 1.0, 2.0f });

    SET_AND_GET_VIA_INVOCATION(tester, largeUniformAggregateF6, { 1.f, 2.f, { { 4.f, 8.f }, { 16.f, 32.f } } });

    const wchar_t hello[] = L"hello";
    SET_AND_GET_VIA_INVOCATION(tester, largeDisparateAggregate, { 1048576, -1.0, hello });

    SET_AND_GET_VIA_INVOCATION(tester, smallDisparateAggregate8, { '\x7f', 0xafafafaf });

    SET_AND_GET_VIA_INVOCATION(tester, smallDisparateAggregate4, { '\x1f', 0xbeef });

    [tester release];
}

#define SET_VIA_INVOCATION_AND_GET(object, prop, ...)                                               \
    do {                                                                              \
		decltype(object.prop) expectedVal = __VA_ARGS__; \
        _testSetViaInvocation<decltype(object.prop)>(object, @selector(prop), __VA_ARGS__); \
auto actualVal = object.prop; \
		EXPECT_EQ(expectedVal, actualVal); \
                                                                                      \
    } while (0)

template <typename T>
static void _testSetViaInvocation(id object, SEL selector, T value) {
	const char* oldSel = sel_getName(selector);
	NSString* newSelectorName = [NSString stringWithFormat:@"set%c%s:", toupper(oldSel[0]), oldSel+1];
	selector = NSSelectorFromString(newSelectorName);
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:[object methodSignatureForSelector:selector]];
    invocation.target = object;
    invocation.selector = selector;
	[invocation setArgument:&value atIndex:2];
    [invocation invoke];
}

TEST(NSInvocation, AggregateFirstParam) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];

    SET_VIA_INVOCATION_AND_GET(tester, singleChar, (char)0x3);
    SET_VIA_INVOCATION_AND_GET(tester, singleChar, (char)-12);
    SET_VIA_INVOCATION_AND_GET(tester, singleUChar, (unsigned char)0x3U);

    SET_VIA_INVOCATION_AND_GET(tester, singleShort, (short)0xABAB);
    SET_VIA_INVOCATION_AND_GET(tester, singleShort, (short)-1024);
    SET_VIA_INVOCATION_AND_GET(tester, singleUShort, (unsigned short)0xCDEFU);

    SET_VIA_INVOCATION_AND_GET(tester, singleInt, (int)1048576);
    SET_VIA_INVOCATION_AND_GET(tester, singleInt, (int)-70000);
    SET_VIA_INVOCATION_AND_GET(tester, singleUInt, (unsigned int)0xABCDEFU);

    SET_VIA_INVOCATION_AND_GET(tester, singleLongLong, (long long)(1024LL*1024LL*1024LL*1048576LL));
    SET_VIA_INVOCATION_AND_GET(tester, singleLongLong, (long long)(-1LL*(1024LL*1024LL*1024LL*1048576LL)));
    SET_VIA_INVOCATION_AND_GET(tester, singleULongLong, (unsigned long long)0xABCDEF010203ULL);

	SET_VIA_INVOCATION_AND_GET(tester, singleFloat, 1024.0f);
	SET_VIA_INVOCATION_AND_GET(tester, singleDouble, 2048.0);

    SET_VIA_INVOCATION_AND_GET(tester, uniformAggregateF1, { std::numeric_limits<float>::max() });
    SET_VIA_INVOCATION_AND_GET(tester, uniformAggregateD1, { std::numeric_limits<double>::max() });

    SET_VIA_INVOCATION_AND_GET(tester, uniformAggregateF2, { std::numeric_limits<float>::max(), 1024.f });
    SET_VIA_INVOCATION_AND_GET(tester, uniformAggregateD2, { std::numeric_limits<double>::max(), 2048. });

    SET_VIA_INVOCATION_AND_GET(tester, uniformAggregateF3, { { std::numeric_limits<float>::max() }, { 1024.f, 8192.f } });
    SET_VIA_INVOCATION_AND_GET(tester, uniformAggregateD3, { { std::numeric_limits<double>::max() }, { 2048., 16384. } });

    SET_VIA_INVOCATION_AND_GET(tester, uniformAggregateF4, { { std::numeric_limits<float>::max(), 1.f }, { 1024.f, 8192.f } });
    SET_VIA_INVOCATION_AND_GET(tester, uniformAggregateD4, { { std::numeric_limits<double>::max(), 2.f }, { 2048., 16384. } });

    SET_VIA_INVOCATION_AND_GET(tester, disparateAggregateDF, { 1.0, 2.0f });

    SET_VIA_INVOCATION_AND_GET(tester, largeUniformAggregateF6, { 1.f, 2.f, { { 4.f, 8.f }, { 16.f, 32.f } } });

    const wchar_t hello[] = L"hello";
    SET_VIA_INVOCATION_AND_GET(tester, largeDisparateAggregate, { 1048576, -1.0, hello });

    SET_VIA_INVOCATION_AND_GET(tester, smallDisparateAggregate8, { '\x7f', 0xafafafaf });

    SET_VIA_INVOCATION_AND_GET(tester, smallDisparateAggregate4, { '\x1f', 0xbeef });

    [tester release];
}

// Disabled on ARM because it requires named exception catch.
ARM_DISABLED_TEST(NSInvocation, ArgumentsAboveLimit) {
    SEL selector = @selector(initWithFormat:locale:);
    NSMethodSignature* sig = [NSString instanceMethodSignatureForSelector:selector];
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];

    BOOL exceptionThrown = NO;
    @try {
        [invocation setArgument:@"foo" atIndex:4];
    } @catch (NSException* exception) {
        exceptionThrown = (([[exception name] isEqual:NSInvalidArgumentException]) ? YES : NO);
    }
    ASSERT_TRUE_MSG(exceptionThrown, "FAILED: NSInvalidArgumentException was not thrown.");
}

// The following test is disabled because OS X allows you to set (and retrieve (!)) arguments at indices below 0,
// but WinObjC does not. With the NSInvocation rewrite from GH#711, our implementation can be brought into compliance.
OSX_DISABLED_TEST(NSInvocation, ArgumentsBelowZero) {
    SEL selector = @selector(initWithFormat:locale:);
    NSMethodSignature* sig = [NSString instanceMethodSignatureForSelector:selector];
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:sig];

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