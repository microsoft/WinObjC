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

static void assertArrayEqual(unsigned short* a, unsigned short* b, int len) {
    int length = len - 1;
    while (length >= 0) {
        ASSERT_EQ(a[length], b[length]);
        length--;
    }
}

OSX_DISABLED_TEST(NSDecimalNumber, decimalNumberWithMantissa) {
    unsigned short mantissa[] = { 1, 5, 9, 9 };
    NSDecimalNumber* price = [NSDecimalNumber decimalNumberWithMantissa:1599 exponent:-2 isNegative:NO];

    NSDecimal decimal = [price decimalValue];
    ASSERT_EQ(4, decimal._length);
    ASSERT_EQ(-2, decimal._exponent);
    ASSERT_EQ(0, decimal._isNegative);
    assertArrayEqual(mantissa, decimal._mantissa, decimal._length);
    ASSERT_EQ(15.99, [price doubleValue]);

    price = [NSDecimalNumber decimalNumberWithMantissa:159900 exponent:-2 isNegative:NO];
    decimal = [price decimalValue];
    ASSERT_EQ(4, decimal._length);
    ASSERT_EQ(0, decimal._exponent);
    ASSERT_EQ(0, decimal._isNegative);
    assertArrayEqual(mantissa, decimal._mantissa, decimal._length);
    ASSERT_EQ(1599.0, [price doubleValue]);

    price = [NSDecimalNumber decimalNumberWithMantissa:159900 exponent:-2 isNegative:YES];
    decimal = [price decimalValue];
    ASSERT_EQ(4, decimal._length);
    ASSERT_EQ(0, decimal._exponent);
    ASSERT_EQ(1, decimal._isNegative);
    assertArrayEqual(mantissa, decimal._mantissa, decimal._length);
    ASSERT_EQ(-1599.0, [price doubleValue]);
}

TEST(NSDecimalNumber, decimalNumberAddition) {
    NSDecimalNumber* d1 = [NSDecimalNumber decimalNumberWithMantissa:1599 exponent:-2 isNegative:NO];
    ASSERT_EQ(15.99, [d1 doubleValue]);

    NSDecimalNumber* d2 = [NSDecimalNumber decimalNumberWithMantissa:5 exponent:-3 isNegative:NO];
    ASSERT_EQ(0.005, [d2 doubleValue]);

    NSDecimalNumberHandler* roundDown = [NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:NSRoundDown
                                                                                               scale:3
                                                                                    raiseOnExactness:NO
                                                                                     raiseOnOverflow:NO
                                                                                    raiseOnUnderflow:NO
                                                                                 raiseOnDivideByZero:YES];

    NSDecimalNumber* result = [d1 decimalNumberByAdding:d2 withBehavior:roundDown];
    ASSERT_EQ(15.995, [result doubleValue]);

    //
    NSDecimalNumberHandler* roundUp = [NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:NSRoundDown
                                                                                             scale:3
                                                                                  raiseOnExactness:NO
                                                                                   raiseOnOverflow:NO
                                                                                  raiseOnUnderflow:NO
                                                                               raiseOnDivideByZero:YES];

    result = [d1 decimalNumberByAdding:d2 withBehavior:roundUp];
    ASSERT_EQ(15.995, [result doubleValue]);

    //
    roundDown = [NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:NSRoundDown
                                                                       scale:1
                                                            raiseOnExactness:NO
                                                             raiseOnOverflow:NO
                                                            raiseOnUnderflow:NO
                                                         raiseOnDivideByZero:YES];

    result = [d1 decimalNumberByAdding:d2 withBehavior:roundDown];
    ASSERT_EQ(15.9, [result doubleValue]);
}

TEST(NSDecimalNumber, decimalNumberNegativeAddition) {
    NSDecimalNumber* d1 = [NSDecimalNumber decimalNumberWithMantissa:1599 exponent:-2 isNegative:YES];
    ASSERT_EQ(-15.99, [d1 doubleValue]);

    NSDecimalNumber* d2 = [NSDecimalNumber decimalNumberWithMantissa:6 exponent:-3 isNegative:YES];
    ASSERT_EQ(-0.006, [d2 doubleValue]);

    NSDecimalNumberHandler* roundDown = [NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:NSRoundDown
                                                                                               scale:3
                                                                                    raiseOnExactness:NO
                                                                                     raiseOnOverflow:NO
                                                                                    raiseOnUnderflow:NO
                                                                                 raiseOnDivideByZero:YES];

    NSDecimalNumber* result = [d1 decimalNumberByAdding:d2 withBehavior:roundDown];

    ASSERT_EQ(-15.997, [result doubleValue]);
    roundDown = [NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:NSRoundDown
                                                                       scale:2
                                                            raiseOnExactness:NO
                                                             raiseOnOverflow:NO
                                                            raiseOnUnderflow:NO
                                                         raiseOnDivideByZero:YES];

    result = [d1 decimalNumberByAdding:d2 withBehavior:roundDown];
    ASSERT_EQ(-16, [result doubleValue]);
}

TEST(NSDecimalNumber, rounding) {
    NSDecimalNumber* d1 = [NSDecimalNumber decimalNumberWithMantissa:124 exponent:-2 isNegative:NO];
    ASSERT_EQ(1.24, [d1 doubleValue]);

    NSDecimalNumberHandler* roundDown = [NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:NSRoundDown
                                                                                               scale:1
                                                                                    raiseOnExactness:NO
                                                                                     raiseOnOverflow:NO
                                                                                    raiseOnUnderflow:NO
                                                                                 raiseOnDivideByZero:YES];

    NSDecimalNumberHandler* roundUp = [NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:NSRoundUp
                                                                                             scale:1
                                                                                  raiseOnExactness:NO
                                                                                   raiseOnOverflow:NO
                                                                                  raiseOnUnderflow:NO
                                                                               raiseOnDivideByZero:YES];

    NSDecimalNumberHandler* roundPlain = [NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:NSRoundPlain
                                                                                                scale:1
                                                                                     raiseOnExactness:NO
                                                                                      raiseOnOverflow:NO
                                                                                     raiseOnUnderflow:NO
                                                                                  raiseOnDivideByZero:YES];

    NSDecimalNumberHandler* roundBankers = [NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:NSRoundBankers
                                                                                                  scale:1
                                                                                       raiseOnExactness:NO
                                                                                        raiseOnOverflow:NO
                                                                                       raiseOnUnderflow:NO
                                                                                    raiseOnDivideByZero:YES];

    EXPECT_EQ(1.2, [[d1 decimalNumberByRoundingAccordingToBehavior:roundDown] doubleValue]);
    EXPECT_EQ(1.3, [[d1 decimalNumberByRoundingAccordingToBehavior:roundUp] doubleValue]);
    EXPECT_EQ(1.2, [[d1 decimalNumberByRoundingAccordingToBehavior:roundPlain] doubleValue]);
    EXPECT_EQ(1.2, [[d1 decimalNumberByRoundingAccordingToBehavior:roundBankers] doubleValue]);

    d1 = [NSDecimalNumber decimalNumberWithMantissa:126 exponent:-2 isNegative:NO];
    ASSERT_EQ(1.26, [d1 doubleValue]);

    EXPECT_EQ(1.2, [[d1 decimalNumberByRoundingAccordingToBehavior:roundDown] doubleValue]);
    EXPECT_EQ(1.3, [[d1 decimalNumberByRoundingAccordingToBehavior:roundUp] doubleValue]);
    EXPECT_EQ(1.3, [[d1 decimalNumberByRoundingAccordingToBehavior:roundPlain] doubleValue]);
    EXPECT_EQ(1.3, [[d1 decimalNumberByRoundingAccordingToBehavior:roundBankers] doubleValue]);

    d1 = [NSDecimalNumber decimalNumberWithMantissa:125 exponent:-2 isNegative:NO];
    ASSERT_EQ(1.25, [d1 doubleValue]);

    EXPECT_EQ(1.2, [[d1 decimalNumberByRoundingAccordingToBehavior:roundDown] doubleValue]);
    EXPECT_EQ(1.3, [[d1 decimalNumberByRoundingAccordingToBehavior:roundUp] doubleValue]);
    EXPECT_EQ(1.3, [[d1 decimalNumberByRoundingAccordingToBehavior:roundPlain] doubleValue]);
    EXPECT_EQ(1.2, [[d1 decimalNumberByRoundingAccordingToBehavior:roundBankers] doubleValue]);

    d1 = [NSDecimalNumber decimalNumberWithMantissa:135 exponent:-2 isNegative:NO];
    ASSERT_EQ(1.35, [d1 doubleValue]);

    EXPECT_EQ(1.3, [[d1 decimalNumberByRoundingAccordingToBehavior:roundDown] doubleValue]);
    EXPECT_EQ(1.4, [[d1 decimalNumberByRoundingAccordingToBehavior:roundUp] doubleValue]);
    EXPECT_EQ(1.4, [[d1 decimalNumberByRoundingAccordingToBehavior:roundPlain] doubleValue]);
    EXPECT_EQ(1.4, [[d1 decimalNumberByRoundingAccordingToBehavior:roundBankers] doubleValue]);

    d1 = [NSDecimalNumber decimalNumberWithMantissa:135 exponent:-2 isNegative:YES];
    ASSERT_EQ(-1.35, [d1 doubleValue]);

    EXPECT_EQ(-1.4, [[d1 decimalNumberByRoundingAccordingToBehavior:roundDown] doubleValue]);
    EXPECT_EQ(-1.3, [[d1 decimalNumberByRoundingAccordingToBehavior:roundUp] doubleValue]);
    EXPECT_EQ(-1.4, [[d1 decimalNumberByRoundingAccordingToBehavior:roundPlain] doubleValue]);
    EXPECT_EQ(-1.4, [[d1 decimalNumberByRoundingAccordingToBehavior:roundBankers] doubleValue]);
}

static void testSubtract(NSDecimalNumber* x, NSDecimalNumber* y, NSDecimalNumber* expected) {
    NSDecimalNumber* result = [x decimalNumberBySubtracting:y];
    EXPECT_OBJCEQ(expected, result);
}

TEST(NSDecimalNumber, subtraction) {
    // Large-Small
    testSubtract([NSDecimalNumber decimalNumberWithMantissa:105 exponent:-1 isNegative:NO],
                 [NSDecimalNumber decimalNumberWithMantissa:10 exponent:0 isNegative:NO],
                 [NSDecimalNumber decimalNumberWithMantissa:5 exponent:-1 isNegative:NO]);

    // Small-Large
    testSubtract([NSDecimalNumber decimalNumberWithMantissa:105 exponent:-1 isNegative:NO],
                 [NSDecimalNumber decimalNumberWithMantissa:10 exponent:2 isNegative:NO],
                 [NSDecimalNumber decimalNumberWithMantissa:9895 exponent:-1 isNegative:YES]);
    //(-x)-y
    testSubtract([NSDecimalNumber decimalNumberWithMantissa:105 exponent:-1 isNegative:YES],
                 [NSDecimalNumber decimalNumberWithMantissa:10 exponent:0 isNegative:NO],
                 [NSDecimalNumber decimalNumberWithMantissa:205 exponent:-1 isNegative:YES]);

    // x - (-y)
    testSubtract([NSDecimalNumber decimalNumberWithMantissa:105 exponent:-1 isNegative:NO],
                 [NSDecimalNumber decimalNumberWithMantissa:10 exponent:2 isNegative:YES],
                 [NSDecimalNumber decimalNumberWithMantissa:10105 exponent:-1 isNegative:NO]);

    //(-x) - (-y)
    testSubtract([NSDecimalNumber decimalNumberWithMantissa:10123456 exponent:-6 isNegative:YES],
                 [NSDecimalNumber decimalNumberWithMantissa:10 exponent:2 isNegative:YES],
                 [NSDecimalNumber decimalNumberWithMantissa:989876544 exponent:-6 isNegative:NO]);

    //(x) - (-x)
    NSDecimalNumber* d = [NSDecimalNumber decimalNumberWithMantissa:1012345678912345 exponent:-120 isNegative:YES];
    testSubtract(d, d, [NSDecimalNumber zero]);

    //(x) - (-x)
    testSubtract([NSDecimalNumber decimalNumberWithMantissa:10123456789 exponent:-18 isNegative:NO],
                 [NSDecimalNumber decimalNumberWithMantissa:10123456789 exponent:-18 isNegative:YES],
                 [NSDecimalNumber decimalNumberWithMantissa:20246913578 exponent:-18 isNegative:NO]);

    testSubtract([NSDecimalNumber decimalNumberWithMantissa:2 exponent:0 isNegative:NO], [NSDecimalNumber one], [NSDecimalNumber one]);
}

static void testPowerOf10(NSDecimalNumber* x, short power, NSDecimalNumber* expected) {
    NSDecimalNumber* result = [x decimalNumberByMultiplyingByPowerOf10:power];
    EXPECT_OBJCEQ(expected, result);
}

TEST(NSDecimalNumber, powerOf10) {
    testPowerOf10([NSDecimalNumber decimalNumberWithMantissa:105 exponent:-1 isNegative:NO],
                  -4,
                  [NSDecimalNumber decimalNumberWithMantissa:105 exponent:-5 isNegative:NO]);

    testPowerOf10([NSDecimalNumber decimalNumberWithMantissa:1055478961 exponent:-100 isNegative:YES],
                  -20,
                  [NSDecimalNumber decimalNumberWithMantissa:1055478961 exponent:-120 isNegative:YES]);

    testPowerOf10([NSDecimalNumber decimalNumberWithMantissa:99987754 exponent:100 isNegative:YES],
                  20,
                  [NSDecimalNumber decimalNumberWithMantissa:99987754 exponent:120 isNegative:YES]);

    testPowerOf10([NSDecimalNumber decimalNumberWithMantissa:1234567898 exponent:100 isNegative:YES],
                  -20,
                  [NSDecimalNumber decimalNumberWithMantissa:1234567898 exponent:80 isNegative:YES]);

    testPowerOf10([NSDecimalNumber decimalNumberWithMantissa:24861105 exponent:-100 isNegative:NO],
                  -20,
                  [NSDecimalNumber decimalNumberWithMantissa:24861105 exponent:-120 isNegative:NO]);

    testPowerOf10([NSDecimalNumber decimalNumberWithMantissa:1055478961 exponent:100 isNegative:NO],
                  20,
                  [NSDecimalNumber decimalNumberWithMantissa:1055478961 exponent:120 isNegative:NO]);

    testPowerOf10([NSDecimalNumber decimalNumberWithMantissa:90551261 exponent:100 isNegative:NO],
                  -20,
                  [NSDecimalNumber decimalNumberWithMantissa:90551261 exponent:80 isNegative:NO]);
}