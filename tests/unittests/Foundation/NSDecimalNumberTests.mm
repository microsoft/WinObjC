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
#import <cmath>

#define EXPECT_ARRAY_EQUAL(a, b)                     \
    do {                                             \
        for (int i = 0; i < NSDecimalMaxSize; ++i) { \
            EXPECT_EQ(a[i], b[i]);                   \
        }                                            \
    } while (0, 0)

#define TEST_SUBTRACT(x, y, expected)                               \
    do {                                                            \
        NSDecimalNumber* result = [x decimalNumberBySubtracting:y]; \
        EXPECT_OBJCEQ(expected, result);                            \
    } while (0, 0)

#define TEST_ADDITION(x, y, expected)                          \
    do {                                                       \
        NSDecimalNumber* result = [x decimalNumberByAdding:y]; \
        EXPECT_OBJCEQ(expected, result);                       \
    } while (0, 0)

#define VALIDATE(decimal, len, exp, isNegative, mantissa) \
    EXPECT_EQ(len, decimal._length);                      \
    EXPECT_EQ(exp, decimal._exponent);                    \
    EXPECT_EQ(isNegative, decimal._isNegative);           \
    EXPECT_ARRAY_EQUAL(mantissa, decimal._mantissa);

TEST(NSDecimalNumber, Limits) {
    // SCHAR_MIN
    unsigned short mantissaSCHAR_MIN[] = { 128, 0, 0, 0, 0, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithShort:SCHAR_MIN] autorelease];
    NSDecimal decimal = [dNumber decimalValue];
    VALIDATE(decimal, 1, 0, 1, mantissaSCHAR_MIN);

    // SCHAR_MAX
    unsigned short mantissaSCHAR_MAX[] = { 127, 0, 0, 0, 0, 0, 0, 0, 0 };
    dNumber = [[[NSDecimalNumber alloc] initWithShort:SCHAR_MAX] autorelease];
    decimal = [dNumber decimalValue];
    VALIDATE(decimal, 1, 0, 0, mantissaSCHAR_MAX);

    // LLONG_MIN
    unsigned short mantissaLLMin[] = { 0, 0, 0, 32768, 0, 0, 0, 0, 0 };
    dNumber = [[[NSDecimalNumber alloc] initWithLongLong:LLONG_MIN] autorelease];
    decimal = [dNumber decimalValue];
    VALIDATE(decimal, 4, 0, 1, mantissaLLMin);

    // LLONG_MAX
    unsigned short mantissaLLMax[] = { 65535, 65535, 65535, 32767, 0, 0, 0, 0, 0 };
    dNumber = [[[NSDecimalNumber alloc] initWithLongLong:LLONG_MAX] autorelease];
    decimal = [dNumber decimalValue];
    VALIDATE(decimal, 4, 0, 0, mantissaLLMax);

    // DBL_MIN
    unsigned short mantissaDBLMin[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    dNumber = [[[NSDecimalNumber alloc] initWithDouble:DBL_MIN] autorelease];
    decimal = [dNumber decimalValue];
    VALIDATE(decimal, 0, 0, 0, mantissaDBLMin);

    // DBL_MAX
    unsigned short mantissaDBLMax[] = { 65535, 65535, 65535, 65535, 0, 0, 0, 0, 0 };
    dNumber = [[[NSDecimalNumber alloc] initWithDouble:DBL_MAX] autorelease];
    decimal = [dNumber decimalValue];
    VALIDATE(decimal, 4, 127, 0, mantissaDBLMax);

    // ULLONG_MAX
    unsigned short mantissaULLLongMax[] = { 65535, 65535, 65535, 65535, 0, 0, 0, 0, 0 };
    dNumber = [[[NSDecimalNumber alloc] initWithUnsignedLongLong:ULLONG_MAX] autorelease];
    decimal = [dNumber decimalValue];
    VALIDATE(decimal, 4, 0, 0, mantissaULLLongMax);
}

TEST(NSDecimalNumber, InitWithLongLong) {
    unsigned short mantissa[] = { 21495, 42467, 50331, 32, 0, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithLongLong:9223372036854775] autorelease];

    NSDecimal decimal = [dNumber decimalValue];
    EXPECT_EQ(4, decimal._length);
    EXPECT_EQ(0, decimal._exponent);
    EXPECT_EQ(0, decimal._isNegative);

    EXPECT_ARRAY_EQUAL(mantissa, decimal._mantissa);

    dNumber = [[[NSDecimalNumber alloc] initWithLongLong:-9223372036854775] autorelease];
    decimal = [dNumber decimalValue];

    EXPECT_EQ(4, decimal._length);
    EXPECT_EQ(0, decimal._exponent);
    EXPECT_EQ(1, decimal._isNegative);

    EXPECT_ARRAY_EQUAL(mantissa, decimal._mantissa);
}

TEST(NSDecimalNumber, InitWithUnsignedLongLong) {
    unsigned short mantissa[] = { 62556, 31703, 2147, 0, 0, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithUnsignedLongLong:9223372534876] autorelease];
    NSDecimal decimal = [dNumber decimalValue];

    EXPECT_EQ(3, decimal._length);
    EXPECT_EQ(0, decimal._exponent);
    EXPECT_EQ(0, decimal._isNegative);

    EXPECT_ARRAY_EQUAL(mantissa, decimal._mantissa);
}

TEST(NSDecimalNumber, InitWithDouble) {
    unsigned short mantissa[] = { 53248, 62560, 115, 32768, 0, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithDouble:9223372534876e24] autorelease];
    NSDecimal decimal = [dNumber decimalValue];

    EXPECT_EQ(4, decimal._length);
    EXPECT_EQ(18, decimal._exponent);
    EXPECT_EQ(0, decimal._isNegative);

    EXPECT_ARRAY_EQUAL(mantissa, decimal._mantissa);

    //
    dNumber = [[[NSDecimalNumber alloc] initWithDouble:9223372534876e-24] autorelease];
    decimal = [dNumber decimalValue];
    EXPECT_EQ(4, decimal._length);
    EXPECT_EQ(-30, decimal._exponent);
    EXPECT_EQ(0, decimal._isNegative);

    EXPECT_ARRAY_EQUAL(mantissa, decimal._mantissa);

    //
    unsigned short ma[] = { 63488, 50716, 31416, 35167, 0, 0, 0, 0, 0 };
    dNumber = [[[NSDecimalNumber alloc] initWithDouble:989876544e-6] autorelease];
    decimal = [dNumber decimalValue];

    EXPECT_EQ(4, decimal._length);
    EXPECT_EQ(-16, decimal._exponent);
    EXPECT_EQ(0, decimal._isNegative);

    EXPECT_ARRAY_EQUAL(ma, decimal._mantissa);
}

TEST(NSDecimalNumber, DecimalNotANumber) {
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithMantissa:0 exponent:0 isNegative:YES] autorelease];
    NSDecimal decimal = [dNumber decimalValue];

    EXPECT_TRUE(NSDecimalIsNotANumber(&decimal));
}

TEST(NSDecimalNumber, DecimalCompact) {
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithLongLong:10000] autorelease];
    NSDecimal decimal = [dNumber decimalValue];
    NSDecimalCompact(&decimal);

    EXPECT_EQ(1, decimal._length);
    EXPECT_EQ(4, decimal._exponent);
    EXPECT_EQ(0, decimal._isNegative);
}

TEST(NSDecimalNumber, Subtraction1) {
    unsigned short mantissa[NSDecimalMaxSize] = { 24475, 10763, 48184, 32, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithUnsignedLongLong:9223372534876] autorelease];
    NSDecimal left = [dNumber decimalValue];

    dNumber = [[[NSDecimalNumber alloc] initWithLongLong:9223372036854775] autorelease];

    NSDecimal right = [dNumber decimalValue];

    NSDecimal result = {};

    NSDecimalSubtract(&result, &left, &right, NSRoundPlain);
    EXPECT_ARRAY_EQUAL(mantissa, result._mantissa);
    EXPECT_EQ(4, result._length);
    EXPECT_EQ(1, result._isNegative);
    EXPECT_EQ(0, result._exponent);

    NSDecimalSubtract(&result, &right, &left, NSRoundPlain);
    EXPECT_ARRAY_EQUAL(mantissa, result._mantissa);
    EXPECT_EQ(4, result._length);
    EXPECT_EQ(0, result._isNegative);
    EXPECT_EQ(0, result._exponent);
}

TEST(NSDecimalNumber, Subtraction2) {
    NSDecimal left = [[[[NSDecimalNumber alloc] initWithInteger:5] autorelease] decimalValue];
    NSDecimal right = [[[[NSDecimalNumber alloc] initWithUnsignedLongLong:3] autorelease] decimalValue];

    NSDecimal result = {};

    NSDecimalSubtract(&result, &left, &right, NSRoundPlain);
    EXPECT_EQ(2, result._mantissa[0]);
    EXPECT_EQ(1, result._length);
    EXPECT_EQ(0, result._exponent);
    EXPECT_EQ(0, result._isNegative);

    NSDecimalSubtract(&result, &right, &left, NSRoundPlain);
    EXPECT_EQ(2, result._mantissa[0]);
    EXPECT_EQ(1, result._length);
    EXPECT_EQ(0, result._exponent);
    EXPECT_EQ(1, result._isNegative);

    //
    left = [[[[NSDecimalNumber alloc] initWithInteger:100000] autorelease] decimalValue];
    right = [[[[NSDecimalNumber alloc] initWithDouble:1e5] autorelease] decimalValue];

    NSDecimalSubtract(&result, &left, &right, NSRoundPlain);
    EXPECT_EQ(0, result._length);
    EXPECT_EQ(0, result._isNegative);
    //
    left = [[[[NSDecimalNumber alloc] initWithUnsignedLongLong:9223372534876] autorelease] decimalValue];
    right = [[[[NSDecimalNumber alloc] initWithDouble:0] autorelease] decimalValue];

    NSDecimalSubtract(&result, &left, &right, NSRoundPlain);
    EXPECT_EQ(NSOrderedSame, NSDecimalCompare(&result, &left));

    //
    unsigned short mantissa[NSDecimalMaxSize] = { 2048, 25428, 61485, 43339, 53, 0, 0, 0 };
    result = {};
    left = [[[[NSDecimalNumber alloc] initWithDouble:-10123456e-6] autorelease] decimalValue];
    right = [[[[NSDecimalNumber alloc] initWithDouble:-1e3] autorelease] decimalValue];

    NSDecimalSubtract(&result, &left, &right, NSRoundPlain);
    EXPECT_ARRAY_EQUAL(mantissa, result._mantissa);
    EXPECT_EQ(5, result._length);
    EXPECT_EQ(0, result._isNegative);
    EXPECT_EQ(-18, result._exponent);

    //
    TEST_SUBTRACT([[[NSDecimalNumber alloc] initWithDouble:10.5] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:10] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:0.5] autorelease]);

    TEST_SUBTRACT([[[NSDecimalNumber alloc] initWithDouble:10.5] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:1000] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:-989.5] autorelease]);

    TEST_SUBTRACT([[[NSDecimalNumber alloc] initWithDouble:-10.5] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:10] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:-20.5] autorelease]);

    TEST_SUBTRACT([[[NSDecimalNumber alloc] initWithDouble:10.5] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:-1e3] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:1010.5] autorelease]);

    NSDecimalNumber* d = [[[NSDecimalNumber alloc] initWithDouble:1012345678912345e-120] autorelease];
    TEST_SUBTRACT(d, d, [NSDecimalNumber zero]);

    TEST_SUBTRACT([[[NSDecimalNumber alloc] initWithInteger:2] autorelease], [NSDecimalNumber one], [NSDecimalNumber one]);

    TEST_SUBTRACT([[[NSDecimalNumber alloc] initWithInt:(2 * USHRT_MAX)] autorelease],
                  [[[NSDecimalNumber alloc] initWithInt:USHRT_MAX] autorelease],
                  [[[NSDecimalNumber alloc] initWithInt:USHRT_MAX] autorelease]);

    TEST_SUBTRACT([[[NSDecimalNumber alloc] initWithDouble:1186805866786] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:212169414290] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:974636452496] autorelease]);

    TEST_SUBTRACT([[[NSDecimalNumber alloc] initWithDouble:8589869055] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:65537] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:8589803518] autorelease]);

    TEST_SUBTRACT([[[NSDecimalNumber alloc] initWithDouble:11453246122] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:3166485692] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:8286760430] autorelease]);
}

TEST(NSDecimalNumber, addition) {
    // Note: Subtraction tests addition, since NSDecimalSubtract gets converted to NSDecimalAdd
    unsigned short mantissa[NSDecimalMaxSize] = { 5272, 10, 0, 0, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithLongLong:6560451.0] autorelease];
    NSDecimal decimal1 = [dNumber decimalValue];

    dNumber = [[[NSDecimalNumber alloc] initWithDouble:45869] autorelease];
    double maxx = DBL_MAX;
    NSDecimal decimal2 = [dNumber decimalValue];

    NSDecimal result = {};

    NSDecimalAdd(&result, &decimal1, &decimal2, NSRoundPlain);

    EXPECT_EQ(2, result._length);
    EXPECT_EQ(1, result._exponent);
    EXPECT_EQ(0, result._isNegative);

    EXPECT_ARRAY_EQUAL(mantissa, result._mantissa);

    TEST_ADDITION([[[NSDecimalNumber alloc] initWithDouble:19605] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:6536] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:26141] autorelease]);

    TEST_ADDITION([[[NSDecimalNumber alloc] initWithDouble:10.5] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:-1e3] autorelease],
                  [[[NSDecimalNumber alloc] initWithDouble:-989.5] autorelease]);
}

TEST(NSDecimalNumber, NSDecimalCompare) {
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithUnsignedLongLong:9223372534876] autorelease];
    NSDecimal right = [dNumber decimalValue];

    NSDecimal left = {};
    unsigned long long value = 10;
    memcpy(&left._mantissa, &value, NSDecimalMaxSize * sizeof(unsigned short));
    left._exponent = 4;
    left._length = 1;
    EXPECT_EQ(NSOrderedAscending, NSDecimalCompare(&left, &right));

    //
    right = [[[[NSDecimalNumber alloc] initWithUnsignedLongLong:9223372534876] autorelease] decimalValue];
    NSDecimal right2 = [[NSDecimalNumber numberWithUnsignedLongLong:9223372534876] decimalValue];

    left = [[[[NSDecimalNumber alloc] initWithInteger:-1] autorelease] decimalValue];

    EXPECT_EQ(NSOrderedAscending, NSDecimalCompare(&left, &right));
    EXPECT_EQ(NSOrderedSame, NSDecimalCompare(&right, &right));
    EXPECT_EQ(NSOrderedSame, NSDecimalCompare(&right, &right2));
    EXPECT_EQ(NSOrderedSame, NSDecimalCompare(&left, &left));

    //
    right = [[[[NSDecimalNumber alloc] initWithInteger:-50] autorelease] decimalValue];

    left = [[[[NSDecimalNumber alloc] initWithInteger:-1] autorelease] decimalValue];

    EXPECT_EQ(NSOrderedDescending, NSDecimalCompare(&left, &right));

    //
    right = [[[[NSDecimalNumber alloc] initWithInteger:-6595] autorelease] decimalValue];

    left = [[[[NSDecimalNumber alloc] initWithInteger:-6596] autorelease] decimalValue];

    EXPECT_EQ(NSOrderedAscending, NSDecimalCompare(&left, &right));

    //

    left = [[[[NSDecimalNumber alloc] initWithInteger:-5] autorelease] decimalValue];
    right = [[[[NSDecimalNumber alloc] initWithLongLong:3] autorelease] decimalValue];
    EXPECT_EQ(NSOrderedAscending, NSDecimalCompare(&left, &right));
    EXPECT_EQ(NSOrderedDescending, NSDecimalCompare(&right, &left));

    left = [[[[NSDecimalNumber alloc] initWithDouble:(2 * DBL_MAX)] autorelease] decimalValue];
    right = [[[[NSDecimalNumber alloc] initWithDouble:5] autorelease] decimalValue];
    EXPECT_EQ(NSOrderedDescending, NSDecimalCompare(&left, &right));

    //
    left = [[[[NSDecimalNumber alloc] initWithDouble:9223372534876] autorelease] decimalValue];
    right = [[[[NSDecimalNumber alloc] initWithDouble:10] autorelease] decimalValue];
    EXPECT_EQ(NSOrderedDescending, NSDecimalCompare(&left, &right));
}

TEST(NSDecimalNumber, NSNumberCompare) {
    EXPECT_OBJCEQ([NSNumber numberWithDouble:55.0], [NSDecimalNumber numberWithDouble:55.0]);

    //
    EXPECT_OBJCEQ([[[NSDecimalNumber alloc] initWithMantissa:0 exponent:0 isNegative:YES] autorelease],
                  [[[NSDecimalNumber alloc] initWithMantissa:0 exponent:0 isNegative:YES] autorelease]);

    //
    EXPECT_EQ(NSOrderedAscending,
              [[[[NSDecimalNumber alloc] initWithMantissa:0 exponent:0 isNegative:YES] autorelease]
                  compare:[NSNumber numberWithDouble:55.0]]);

    //
    EXPECT_EQ(NSOrderedDescending,
              [[NSNumber numberWithDouble:55.0]
                  compare:[[[NSDecimalNumber alloc] initWithMantissa:0 exponent:0 isNegative:YES] autorelease]]);
}