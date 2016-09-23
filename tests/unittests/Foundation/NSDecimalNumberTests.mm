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

#define ASSERT_ARRAY_EQUAL(a, b)                     \
    do {                                             \
        for (int i = 0; i < NSDecimalMaxSize; ++i) { \
            ASSERT_EQ(a[i], b[i]);                   \
        }                                            \
    } while (0, 0)

static void testSubtract(NSDecimalNumber* x, NSDecimalNumber* y, NSDecimalNumber* expected) {
    NSDecimalNumber* result = [x decimalNumberBySubtracting:y];
    EXPECT_OBJCEQ(expected, result);
}

static void testAddition(NSDecimalNumber* x, NSDecimalNumber* y, NSDecimalNumber* expected) {
    NSDecimalNumber* result = [x decimalNumberByAdding:y];
    EXPECT_OBJCEQ(expected, result);
}

TEST(NSDecimalNumber, InitWithLongLong) {
    unsigned short mantissa[] = { 21495, 42467, 50331, 32, 0, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithLongLong:9223372036854775] autorelease];

    NSDecimal decimal = [dNumber decimalValue];
    ASSERT_EQ(4, decimal._length);
    ASSERT_EQ(0, decimal._exponent);
    ASSERT_EQ(0, decimal._isNegative);

    ASSERT_ARRAY_EQUAL(mantissa, decimal._mantissa);

    dNumber = [[[NSDecimalNumber alloc] initWithLongLong:-9223372036854775] autorelease];
    decimal = [dNumber decimalValue];

    ASSERT_EQ(4, decimal._length);
    ASSERT_EQ(0, decimal._exponent);
    ASSERT_EQ(1, decimal._isNegative);

    ASSERT_ARRAY_EQUAL(mantissa, decimal._mantissa);
}

TEST(NSDecimalNumber, InitWithUnsignedLongLong) {
    unsigned short mantissa[] = { 62556, 31703, 2147, 0, 0, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithUnsignedLongLong:9223372534876] autorelease];
    NSDecimal decimal = [dNumber decimalValue];

    ASSERT_EQ(3, decimal._length);
    ASSERT_EQ(0, decimal._exponent);
    ASSERT_EQ(0, decimal._isNegative);

    ASSERT_ARRAY_EQUAL(mantissa, decimal._mantissa);
}

TEST(NSDecimalNumber, InitWithDouble) {
    unsigned short mantissa[] = { 53248, 62560, 115, 32768, 0, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithDouble:9223372534876e24] autorelease];
    NSDecimal decimal = [dNumber decimalValue];

    EXPECT_EQ(4, decimal._length);
    EXPECT_EQ(18, decimal._exponent);
    EXPECT_EQ(0, decimal._isNegative);

    ASSERT_ARRAY_EQUAL(mantissa, decimal._mantissa);

    //
    dNumber = [[[NSDecimalNumber alloc] initWithDouble:9223372534876e-24] autorelease];
    decimal = [dNumber decimalValue];
    EXPECT_EQ(4, decimal._length);
    EXPECT_EQ(-30, decimal._exponent);
    EXPECT_EQ(0, decimal._isNegative);

    ASSERT_ARRAY_EQUAL(mantissa, decimal._mantissa);

    //
    unsigned short ma[] = { 63488, 50716, 31416, 35167, 0, 0, 0, 0, 0 };
    dNumber = [[[NSDecimalNumber alloc] initWithDouble:989876544e-6] autorelease];
    decimal = [dNumber decimalValue];

    EXPECT_EQ(4, decimal._length);
    EXPECT_EQ(-16, decimal._exponent);
    EXPECT_EQ(0, decimal._isNegative);

    ASSERT_ARRAY_EQUAL(ma, decimal._mantissa);
}

TEST(NSDecimalNumber, DecimalNotANumber) {
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithMantissa:0 exponent:0 isNegative:YES] autorelease];
    NSDecimal decimal = [dNumber decimalValue];

    ASSERT_TRUE(NSDecimalIsNotANumber(&decimal));
}

TEST(NSDecimalNumber, DecimalCompact) {
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithLongLong:10000] autorelease];
    NSDecimal decimal = [dNumber decimalValue];
    NSDecimalCompact(&decimal);

    ASSERT_EQ(1, decimal._length);
    ASSERT_EQ(4, decimal._exponent);
    ASSERT_EQ(0, decimal._isNegative);
}

TEST(NSDecimalNumber, Subtraction1) {
    unsigned short mantissa[NSDecimalMaxSize] = { 24475, 10763, 48184, 32, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithUnsignedLongLong:9223372534876] autorelease];
    NSDecimal left = [dNumber decimalValue];

    dNumber = [[[NSDecimalNumber alloc] initWithLongLong:9223372036854775] autorelease];

    NSDecimal right = [dNumber decimalValue];

    NSDecimal result = { 0 };

    NSDecimalSubtract(&result, &left, &right, 0);
    ASSERT_ARRAY_EQUAL(mantissa, result._mantissa);
    EXPECT_EQ(4, result._length);
    EXPECT_EQ(1, result._isNegative);
    EXPECT_EQ(0, result._exponent);

    NSDecimalSubtract(&result, &right, &left, 0);
}

TEST(NSDecimalNumber, Subtraction2) {
    NSDecimal left = [[[[NSDecimalNumber alloc] initWithInteger:5] autorelease] decimalValue];
    NSDecimal right = [[[[NSDecimalNumber alloc] initWithUnsignedLongLong:3] autorelease] decimalValue];

    NSDecimal result = { 0 };

    NSDecimalSubtract(&result, &left, &right, 0);
    EXPECT_EQ(2, result._mantissa[0]);
    EXPECT_EQ(1, result._length);
    EXPECT_EQ(0, result._exponent);
    EXPECT_EQ(0, result._isNegative);

    NSDecimalSubtract(&result, &right, &left, 0);
    EXPECT_EQ(2, result._mantissa[0]);
    EXPECT_EQ(1, result._length);
    EXPECT_EQ(0, result._exponent);
    EXPECT_EQ(1, result._isNegative);

    //
    left = [[[[NSDecimalNumber alloc] initWithInteger:100000] autorelease] decimalValue];
    right = [[[[NSDecimalNumber alloc] initWithDouble:1e5] autorelease] decimalValue];

    NSDecimalSubtract(&result, &left, &right, 0);
    EXPECT_EQ(0, result._length);
    EXPECT_EQ(0, result._isNegative);
    //
    left = [[[[NSDecimalNumber alloc] initWithUnsignedLongLong:9223372534876] autorelease] decimalValue];
    right = [[[[NSDecimalNumber alloc] initWithDouble:0] autorelease] decimalValue];

    NSDecimalSubtract(&result, &left, &right, 0);
    EXPECT_EQ(NSOrderedSame, NSDecimalCompare(&result, &left));

    //
    unsigned short mantissa[NSDecimalMaxSize] = { 2048, 25428, 61485, 43339, 53, 0, 0, 0 };
    result = { 0 };
    left = [[[[NSDecimalNumber alloc] initWithDouble:-10123456e-6] autorelease] decimalValue];
    right = [[[[NSDecimalNumber alloc] initWithDouble:-1e3] autorelease] decimalValue];

    NSDecimalSubtract(&result, &left, &right, 0);
    ASSERT_ARRAY_EQUAL(mantissa, result._mantissa);
    EXPECT_EQ(5, result._length);
    EXPECT_EQ(0, result._isNegative);
    EXPECT_EQ(-18, result._exponent);

    //
    testSubtract([[[NSDecimalNumber alloc] initWithDouble:10.5] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:10] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:0.5] autorelease]);

    testSubtract([[[NSDecimalNumber alloc] initWithDouble:10.5] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:1000] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:-989.5] autorelease]);

    testSubtract([[[NSDecimalNumber alloc] initWithDouble:-10.5] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:10] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:-20.5] autorelease]);

    testSubtract([[[NSDecimalNumber alloc] initWithDouble:10.5] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:-1e3] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:1010.5] autorelease]);

    NSDecimalNumber* d = [[[NSDecimalNumber alloc] initWithDouble:1012345678912345e-120] autorelease];
    testSubtract(d, d, [NSDecimalNumber zero]);

    testSubtract([[[NSDecimalNumber alloc] initWithInteger:2] autorelease], [NSDecimalNumber one], [NSDecimalNumber one]);
}

TEST(NSDecimalNumber, addition) {
    // Note: Since Subtraction tests addition, since NSDecimalSubtract gets converted to NSDecimalAdd
    unsigned short mantissa[NSDecimalMaxSize] = { 5272, 10, 0, 0, 0, 0, 0, 0 };
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithLongLong:6560451.0] autorelease];
    NSDecimal decimal1 = [dNumber decimalValue];

    dNumber = [[[NSDecimalNumber alloc] initWithDouble:45869] autorelease];
    double maxx = DBL_MAX;
    NSDecimal decimal2 = [dNumber decimalValue];

    NSDecimal result = { 0 };

    NSDecimalAdd(&result, &decimal1, &decimal2, 0);

    ASSERT_EQ(2, result._length);
    ASSERT_EQ(1, result._exponent);
    ASSERT_EQ(0, result._isNegative);

    ASSERT_ARRAY_EQUAL(mantissa, result._mantissa);

    testAddition([[[NSDecimalNumber alloc] initWithDouble:19605] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:6536] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:26141] autorelease]);

    testAddition([[[NSDecimalNumber alloc] initWithDouble:10.5] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:-1e3] autorelease],
                 [[[NSDecimalNumber alloc] initWithDouble:-989.5] autorelease]);
}

TEST(NSDecimalNumber, NSDecimalCompare) {
    NSDecimalNumber* dNumber = [[[NSDecimalNumber alloc] initWithUnsignedLongLong:9223372534876] autorelease];
    NSDecimal right = [dNumber decimalValue];

    NSDecimal left = { 0 };
    unsigned long long value = 10;
    memcpy(&left._mantissa, &value, NSDecimalMaxSize * sizeof(short));
    left._exponent = 4;
    left._length = 1;
    EXPECT_EQ(NSOrderedAscending, NSDecimalCompare(&left, &right));

    //
    right = [[[[NSDecimalNumber alloc] initWithUnsignedLongLong:9223372534876] autorelease] decimalValue];

    left = [[[[NSDecimalNumber alloc] initWithInteger:-1] autorelease] decimalValue];

    EXPECT_EQ(NSOrderedAscending, NSDecimalCompare(&left, &right));
    EXPECT_EQ(NSOrderedSame, NSDecimalCompare(&right, &right));
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
}
