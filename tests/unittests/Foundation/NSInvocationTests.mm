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

struct TinyAggregate {
    uint8_t m1;
    bool operator==(const TinyAggregate& other) const {
        return m1 == other.m1;
    }
};

struct HighlyAlignedAggregate1 {
    std::max_align_t m1;
    uint8_t m2;
    std::max_align_t m3;
    bool operator==(const HighlyAlignedAggregate1& other) const {
        return m1 == other.m1 && m2 == other.m2 && m3 == other.m3;
    }
};

struct FiveWordStruct {
    uintptr_t m1;
    uintptr_t m2;
    uintptr_t m3;
    uintptr_t m4;
    uintptr_t m5;
};

struct ThreeWordStruct {
    uintptr_t m1;
    uintptr_t m2;
    uintptr_t m3;
};

@protocol _NSIT_InvocationProtocol
@optional
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
@property (nonatomic, assign) TinyAggregate tinyAggregate;
@property (nonatomic, assign) HighlyAlignedAggregate1 highlyAlignedAggregate1;
- (double)addInterleavedFloat:(float)f1 D:(double)d1 F:(float)f2 D:(double)d2 F:(float)f3 D:(double)d3 F:(float)f4 D:(double)d4 F:(float)f5 D:(double)d5 F:(float)f6 D:(double)d6 F:(float)f7 D:(double)d7 F:(float)f8;
- (char)addPackedCharacters:(char)c1:(char)c2:(char)c3:(char)c4:(char)c5:(char)c6:(char)c7:(char)c8;
- (void)structSplitOverRegistersAndStack:(FiveWordStruct)s;
- (void)largeUniformVFPs:(UniformAggregateD4)one
                        :(UniformAggregateD4)two
      consumeVFPAndStack:(double)three
    forcingStructOntoTheStack:(ThreeWordStruct)s;
- (void)interleavedAlignmentsCharMax:(char)c1
                                    :(std::max_align_t)m1
                                    :(char)c2
                                    :(std::max_align_t)m2
                                    :(char)c3
                                    :(std::max_align_t)m3
                                    :(char)c4
                                    :(std::max_align_t)m4
                                    :(char)c5
                                    :(std::max_align_t)m5
                                    :(char)c6
                                    :(std::max_align_t)m6
                                    :(char)c7
                                    :(std::max_align_t)m7
                                    :(unsigned char)c8;
- (void)ARMFirstThreeInRegisters:(uint32_t)third fourthOntoStackToRemainContiguous:(uint64_t)fourth;
- (BOOL)charPointer:(char*)charPointer equalsVoidPointer:(void*)voidPointer;
@end

@interface NSIT_InvocationTestClass : NSObject <_NSIT_InvocationProtocol>
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
@property (nonatomic, assign) TinyAggregate tinyAggregate;
@property (nonatomic, assign) HighlyAlignedAggregate1 highlyAlignedAggregate1;
- (void)takesOneObject:(id)object andOneCharPointer:(char*)charPointer;
@end
@implementation NSIT_InvocationTestClass
// properties synthesized here
- (double)addInterleavedFloat:(float)f1
                            D:(double)d1
                            F:(float)f2
                            D:(double)d2
                            F:(float)f3
                            D:(double)d3
                            F:(float)f4
                            D:(double)d4
                            F:(float)f5
                            D:(double)d5
                            F:(float)f6
                            D:(double)d6
                            F:(float)f7
                            D:(double)d7
                            F:(float)f8 {
    // Test input: powers of 2 in floats
    //             powers of 3 in doubles
    EXPECT_EQ(1.f, f1);
    EXPECT_EQ(2.f, f2);
    EXPECT_EQ(4.f, f3);
    EXPECT_EQ(8.f, f4);
    EXPECT_EQ(16.f, f5);
    EXPECT_EQ(32.f, f6);
    EXPECT_EQ(64.f, f7);
    EXPECT_EQ(128.f, f8);

    EXPECT_EQ(1., d1);
    EXPECT_EQ(3., d2);
    EXPECT_EQ(9., d3);
    EXPECT_EQ(27., d4);
    EXPECT_EQ(81., d5);
    EXPECT_EQ(243., d6);
    EXPECT_EQ(729., d7);

    // 1348
    return f1 + f2 + f3 + f4 + f5 + f6 + f7 + f8 + d1 + d2 + d3 + d4 + d5 + d6 + d7;
}

- (char)addPackedCharacters:(char)c1:(char)c2:(char)c3:(char)c4:(char)c5:(char)c6:(char)c7:(char)c8 {
    EXPECT_EQ(1, c1);
    EXPECT_EQ(2, c2);
    EXPECT_EQ(3, c3);
    EXPECT_EQ(4, c4);
    EXPECT_EQ(5, c5);
    EXPECT_EQ(6, c6);
    EXPECT_EQ(7, c7);
    EXPECT_EQ(8, c8);

    return c1 + c2 + c3 + c4 + c5 + c6 + c7 + c8;
}

- (void)structSplitOverRegistersAndStack:(FiveWordStruct)s {
    EXPECT_EQ(1, s.m1);
    EXPECT_EQ(2, s.m2);
    EXPECT_EQ(3, s.m3);
    EXPECT_EQ(4, s.m4);
    EXPECT_EQ(5, s.m5);
}

- (void)largeUniformVFPs:(UniformAggregateD4)one
                        :(UniformAggregateD4)two
      consumeVFPAndStack:(double)three
    forcingStructOntoTheStack:(ThreeWordStruct)s {
    UniformAggregateD4 val1{ { 1024, 2048 }, { 4096, 8192 } };
    UniformAggregateD4 val2{ { 1000, 2000 }, { 4000, 8000 } };
    EXPECT_EQ(val1, one);
    EXPECT_EQ(val2, two);

    EXPECT_EQ(999.0, three);

    EXPECT_EQ(0xDEADBEEF, s.m1);
    EXPECT_EQ(0xCAFECAFE, s.m2);
    EXPECT_EQ(0xF00DC01D, s.m3);
}

- (void)interleavedAlignmentsCharMax:(char)c1
                                    :(std::max_align_t)m1
                                    :(char)c2
                                    :(std::max_align_t)m2
                                    :(char)c3
                                    :(std::max_align_t)m3
                                    :(char)c4
                                    :(std::max_align_t)m4
                                    :(char)c5
                                    :(std::max_align_t)m5
                                    :(char)c6
                                    :(std::max_align_t)m6
                                    :(char)c7
                                    :(std::max_align_t)m7
                                    :(unsigned char)c8 {
    EXPECT_EQ(1, c1);
    EXPECT_EQ(2, c2);
    EXPECT_EQ(4, c3);
    EXPECT_EQ(8, c4);
    EXPECT_EQ(16, c5);
    EXPECT_EQ(32, c6);
    EXPECT_EQ(64, c7);
    EXPECT_EQ(128, c8);

    EXPECT_EQ(1., m1);
    EXPECT_EQ(3., m2);
    EXPECT_EQ(9., m3);
    EXPECT_EQ(27., m4);
    EXPECT_EQ(81., m5);
    EXPECT_EQ(243., m6);
    EXPECT_EQ(729., m7);
}

- (void)ARMFirstThreeInRegisters:(uint32_t)third fourthOntoStackToRemainContiguous:(uint64_t)fourth {
    EXPECT_EQ(0xABABABABUL, third);
    EXPECT_EQ(0x123409871234ABABULL, fourth);
}

- (void)takesOneObject:(id)object andOneCharPointer:(char*)charPointer {
    // No-op
}

- (BOOL)charPointer:(char*)charPointer equalsVoidPointer:(void*)voidPointer {
    return charPointer == voidPointer;
}
@end

@interface _NSIT_InvocationForwardingFacade : NSObject <_NSIT_InvocationProtocol> {
    NSIT_InvocationTestClass* _destination;
}
@end
@implementation _NSIT_InvocationForwardingFacade
- (instancetype)init {
    if (self = [super init]) {
        _destination = [[NSIT_InvocationTestClass alloc] init];
    }
    return self;
}
- (void)dealloc {
    [_destination release];
    [super dealloc];
}
- (void)forwardInvocation:(NSInvocation*)invocation {
    [invocation invokeWithTarget:_destination];
}
@end

#define SET_AND_GET_VIA_INVOCATION(object, prop, ...)                                       \
    do {                                                                                    \
        object.prop = __VA_ARGS__;                                                          \
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

    EXPECT_EQ_MSG(value, returnedValue, "property %s", sel_getName(selector));
}

TEST(NSInvocation, SimpleReturnValues) {
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

    SET_AND_GET_VIA_INVOCATION(tester, singleFloat, 1024.0f);
    SET_AND_GET_VIA_INVOCATION(tester, singleDouble, 2048.0);

    [tester release];
}

TEST(NSInvocation, AggregateReturnValues) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];
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

    SET_AND_GET_VIA_INVOCATION(tester, tinyAggregate, { 'a' });

    SET_AND_GET_VIA_INVOCATION(tester, highlyAlignedAggregate1, { 10, 20, 30 });

    [tester release];
}

#define SET_VIA_INVOCATION_AND_GET(object, prop, ...)                                       \
    do {                                                                                    \
        decltype(object.prop) expectedVal = __VA_ARGS__;                                    \
        _testSetViaInvocation<decltype(object.prop)>(object, @selector(prop), __VA_ARGS__); \
        \
auto actualVal = object.prop;                                                               \
        EXPECT_EQ(expectedVal, actualVal);                                                  \
                                                                                            \
    } while (0)

template <typename T>
static void _testSetViaInvocation(id object, SEL selector, T value) {
    const char* oldSel = sel_getName(selector);
    NSString* newSelectorName = [NSString stringWithFormat:@"set%c%s:", toupper(oldSel[0]), oldSel + 1];
    selector = NSSelectorFromString(newSelectorName);
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:[object methodSignatureForSelector:selector]];
    invocation.target = object;
    invocation.selector = selector;
    [invocation setArgument:&value atIndex:2];
    [invocation invoke];
}

TEST(NSInvocation, SimpleSingleParam) {
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

    SET_VIA_INVOCATION_AND_GET(tester, singleLongLong, (long long)(1024LL * 1024LL * 1024LL * 1048576LL));
    SET_VIA_INVOCATION_AND_GET(tester, singleLongLong, (long long)(-1LL * (1024LL * 1024LL * 1024LL * 1048576LL)));
    SET_VIA_INVOCATION_AND_GET(tester, singleULongLong, (unsigned long long)0xABCDEF010203ULL);

    SET_VIA_INVOCATION_AND_GET(tester, singleFloat, 1024.0f);
    SET_VIA_INVOCATION_AND_GET(tester, singleDouble, 2048.0);

    SET_VIA_INVOCATION_AND_GET(tester, tinyAggregate, { 'a' });

    SET_VIA_INVOCATION_AND_GET(tester, highlyAlignedAggregate1, { 10, 20, 30 });

    [tester release];
}

TEST(NSInvocation, AggregateSingleParam) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];

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

TEST(NSInvocation, InterleavedFloatArguments) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];

    // BASELINE TEST
    EXPECT_EQ(1348., [tester addInterleavedFloat:1 D:1 F:2 D:3 F:4 D:9 F:8 D:27 F:16 D:81 F:32 D:243 F:64 D:729 F:128]);

    SEL selector = @selector(addInterleavedFloat:D:F:D:F:D:F:D:F:D:F:D:F:D:F:);
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:[tester methodSignatureForSelector:selector]];
    [invocation setTarget:tester];
    [invocation setSelector:selector];

    float floatArgs[] = { 1.f, 2.f, 4.f, 8.f, 16.f, 32.f, 64.f, 128.f };
    double doubleArgs[] = { 1., 3., 9., 27., 81., 243., 729. };

    for (int i = 0; i < 15; ++i) {
        if (i % 2 == 0) {
            // even number args are floats.
            [invocation setArgument:&floatArgs[i / 2] atIndex:2 + i];
        } else {
            [invocation setArgument:&doubleArgs[i / 2] atIndex:2 + i];
        }
    }

    [invocation invoke];
    double returnValue = 1.0;
    [invocation getReturnValue:&returnValue];

    EXPECT_EQ(1348., returnValue);

    [tester release];
}

TEST(NSInvocation, PackedCharacters) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];

    // BASELINE TEST
    EXPECT_EQ(36, [tester addPackedCharacters:1:2:3:4:5:6:7:8]);

    SEL selector = @selector(addPackedCharacters:: :: :: ::);
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:[tester methodSignatureForSelector:selector]];
    [invocation setTarget:tester];
    [invocation setSelector:selector];

    char args[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    for (int i = 0; i < 8; ++i) {
        [invocation setArgument:&args[i] atIndex:2 + i];
    }

    [invocation invoke];

    char returnValue = 0;
    [invocation getReturnValue:&returnValue];

    EXPECT_EQ(36, returnValue);

    [tester release];
}

TEST(NSInvocation, LargeNonFloatStructs) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];

    SEL selector = @selector(structSplitOverRegistersAndStack:);
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:[tester methodSignatureForSelector:selector]];
    [invocation setTarget:tester];
    [invocation setSelector:selector];

    FiveWordStruct arg2{ 1, 2, 3, 4, 5 };
    [invocation setArgument:&arg2 atIndex:2];

    [invocation invoke];

    [tester release];
}

TEST(NSInvocation, HeterogenousArgumentsWithStructs) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];

    SEL selector = @selector(largeUniformVFPs::consumeVFPAndStack:forcingStructOntoTheStack:);
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:[tester methodSignatureForSelector:selector]];
    [invocation setTarget:tester];
    [invocation setSelector:selector];

    UniformAggregateD4 arg2{ { 1024, 2048 }, { 4096, 8192 } };
    UniformAggregateD4 arg3{ { 1000, 2000 }, { 4000, 8000 } };
    double arg4 = 999.0;
    ThreeWordStruct arg5{ 0xDEADBEEF, 0xCAFECAFE, 0xF00DC01D };
    [invocation setArgument:&arg2 atIndex:2];
    [invocation setArgument:&arg3 atIndex:3];
    [invocation setArgument:&arg4 atIndex:4];
    [invocation setArgument:&arg5 atIndex:5];

    [invocation invoke];

    [tester release];
}

// Disabled on OS X: It does not appear to properly allocate these arguments.
OSX_DISABLED_TEST(NSInvocation, ArgumentsOfAlternatingAlignment) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];

    SEL selector = @selector(interleavedAlignmentsCharMax:: :: :: :: :: :: :::);
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:[tester methodSignatureForSelector:selector]];
    [invocation setTarget:tester];
    [invocation setSelector:selector];

    unsigned char charArgs[] = { 1, 2, 4, 8, 16, 32, 64, 128 };
    std::max_align_t maxAlignArgs[] = { 1., 3., 9., 27., 81., 243., 729. };

    for (int i = 0; i < 15; ++i) {
        if (i % 2 == 0) {
            // even number args are floats.
            [invocation setArgument:&charArgs[i / 2] atIndex:2 + i];
        } else {
            [invocation setArgument:&maxAlignArgs[i / 2] atIndex:2 + i];
        }
    }

    [invocation invoke];
    [tester release];
}

TEST(NSInvocation, ARMUInt64sContiguousRegistersOrStack) {
    NSIT_InvocationTestClass* tester = [[NSIT_InvocationTestClass alloc] init];

    SEL selector = @selector(ARMFirstThreeInRegisters:fourthOntoStackToRemainContiguous:);
    NSInvocation* invocation = [NSInvocation invocationWithMethodSignature:[tester methodSignatureForSelector:selector]];
    [invocation setTarget:tester];
    [invocation setSelector:selector];

    uint32_t arg2 = 0xABABABABUL;
    uint64_t arg3 = 0x123409871234ABABULL;
    [invocation setArgument:&arg2 atIndex:2];
    [invocation setArgument:&arg3 atIndex:3];

    [invocation invoke];

    [tester release];
}

#define SET_AND_GET_VIA_FACADE(object, prop, ...)                    \
    do {                                                             \
        decltype(object.prop) expectedVal = __VA_ARGS__;             \
        object.prop = expectedVal;                                   \
        decltype(object.prop) actualVal = object.prop;               \
        EXPECT_EQ_MSG(expectedVal, actualVal, "property %s", #prop); \
    } while (0)

TEST(NSInvocation, ForwardInvocation) {
    _NSIT_InvocationForwardingFacade* facade = [[[_NSIT_InvocationForwardingFacade alloc] init] autorelease];

    EXPECT_EQ(1348., [facade addInterleavedFloat:1 D:1 F:2 D:3 F:4 D:9 F:8 D:27 F:16 D:81 F:32 D:243 F:64 D:729 F:128]);
    EXPECT_EQ(36, [facade addPackedCharacters:1:2:3:4:5:6:7:8]);

    {
        uint32_t arg2 = 0xABABABABUL;
        uint64_t arg3 = 0x123409871234ABABULL;

        [facade ARMFirstThreeInRegisters:arg2 fourthOntoStackToRemainContiguous:arg3];
    }

    {
        UniformAggregateD4 arg2{ { 1024, 2048 }, { 4096, 8192 } };
        UniformAggregateD4 arg3{ { 1000, 2000 }, { 4000, 8000 } };
        double arg4 = 999.0;
        ThreeWordStruct arg5{ 0xDEADBEEF, 0xCAFECAFE, 0xF00DC01D };
        [facade largeUniformVFPs:arg2 :arg3 consumeVFPAndStack:arg4 forcingStructOntoTheStack:arg5];
    }

    {
        SET_AND_GET_VIA_FACADE(facade, uniformAggregateF1, { std::numeric_limits<float>::max() });
        SET_AND_GET_VIA_FACADE(facade, uniformAggregateD1, { std::numeric_limits<double>::max() });

        SET_AND_GET_VIA_FACADE(facade, uniformAggregateF2, { std::numeric_limits<float>::max(), 1024.f });
        SET_AND_GET_VIA_FACADE(facade, uniformAggregateD2, { std::numeric_limits<double>::max(), 2048. });

        SET_AND_GET_VIA_FACADE(facade, uniformAggregateF3, { { std::numeric_limits<float>::max() }, { 1024.f, 8192.f } });
        SET_AND_GET_VIA_FACADE(facade, uniformAggregateD3, { { std::numeric_limits<double>::max() }, { 2048., 16384. } });

        SET_AND_GET_VIA_FACADE(facade, uniformAggregateF4, { { std::numeric_limits<float>::max(), 1.f }, { 1024.f, 8192.f } });
        SET_AND_GET_VIA_FACADE(facade, uniformAggregateD4, { { std::numeric_limits<double>::max(), 2.f }, { 2048., 16384. } });

        SET_AND_GET_VIA_FACADE(facade, disparateAggregateDF, { 1.0, 2.0f });

        SET_AND_GET_VIA_FACADE(facade, largeUniformAggregateF6, { 1.f, 2.f, { { 4.f, 8.f }, { 16.f, 32.f } } });

        const wchar_t hello[] = L"hello";
        SET_AND_GET_VIA_FACADE(facade, largeDisparateAggregate, { 1048576, -1.0, hello });

        SET_AND_GET_VIA_FACADE(facade, smallDisparateAggregate8, { '\x7f', 0xafafafaf });

        SET_AND_GET_VIA_FACADE(facade, smallDisparateAggregate4, { '\x1f', 0xbeef });

        SET_AND_GET_VIA_FACADE(facade, tinyAggregate, { 'a' });

        SET_AND_GET_VIA_FACADE(facade, highlyAlignedAggregate1, { 10, 20, 30 });
    }
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

TEST(NSInvocation, RetainArguments) {
    id arg2 = [NSObject new];
    char* arg3 = "I am a constant string!";

    NSInvocation* invocation =
        [NSInvocation invocationWithMethodSignature:[NSIT_InvocationTestClass
                                                        instanceMethodSignatureForSelector:@selector(takesOneObject:andOneCharPointer:)]];
    ASSERT_OBJCNE(nil, invocation);

    [invocation setSelector:@selector(takesOneObject:andOneCharPointer:)];
    [invocation setArgument:&arg2 atIndex:2];
    [invocation retainArguments];
    [invocation setArgument:&arg3 atIndex:3];
    [arg2 release];

    id readbackArg2 = nil;
    char* readbackArg3 = nullptr;

    [invocation getArgument:&readbackArg2 atIndex:2];
    [invocation getArgument:&readbackArg3 atIndex:3];

    EXPECT_NO_THROW([readbackArg2 self]); // Should have been retained.
    EXPECT_NE(readbackArg3, arg3); // Should have been IwStrDup'd.
}

TEST(NSInvocation, ForwardingDoesNotRetainArguments) {
    char* arg = "I am a constant string!";
    _NSIT_InvocationForwardingFacade* facade = [[[_NSIT_InvocationForwardingFacade alloc] init] autorelease];
    EXPECT_TRUE([facade charPointer:arg equalsVoidPointer:arg]);
}