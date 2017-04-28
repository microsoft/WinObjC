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

#import <objc/message.h>
#import <cmath>
#import <limits>

static const double c_floatingPtTolerance = 0.00001;

// Helper template function that calls a scan_______ function specified by the selector and does the necessary casts
template <typename T>
static BOOL performScan(NSScanner* scanner, SEL sel, T* resultPtr) {
    return ((BOOL(*)(NSScanner*, SEL, T*))objc_msgSend)(scanner, sel, resultPtr);
}

TEST(NSScanner, CharactersToBeSkipped) {
    NSScanner* scanner = [NSScanner scannerWithString:@"::::__*123 :::*_:abc"];
    scanner.charactersToBeSkipped = [NSCharacterSet characterSetWithCharactersInString:@":*_ "];
    NSUInteger expectedScanLocation = 0;
    int result;

    // Should be able to skip past the punctuation characters
    ASSERT_TRUE([scanner scanInt:&result]);
    EXPECT_EQ(123, result);
    EXPECT_EQ(expectedScanLocation += 10, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Failing to scan does not advance the scanLocation
    ASSERT_FALSE([scanner scanInt:&result]);
    EXPECT_EQ(expectedScanLocation, scanner.scanLocation);
}

TEST(NSScanner, ScanCharactersFromSet) {
    NSScanner* scanner = [NSScanner scannerWithString:@"abcd123efgh456"];
    NSUInteger expectedScanLocation = 0;
    NSString* result;

    ASSERT_TRUE([scanner scanCharactersFromSet:[NSCharacterSet letterCharacterSet] intoString:&result]);
    EXPECT_OBJCEQ(@"abcd", result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Fails to scan as 123 are not in letter character set
    ASSERT_FALSE([scanner scanCharactersFromSet:[NSCharacterSet letterCharacterSet] intoString:&result]);
    EXPECT_EQ(expectedScanLocation, scanner.scanLocation);

    // Set them to be skipped
    scanner.charactersToBeSkipped = [NSCharacterSet decimalDigitCharacterSet];

    // Can proceed now, considered to have reached the end
    ASSERT_TRUE([scanner scanCharactersFromSet:[NSCharacterSet letterCharacterSet] intoString:&result]);
    EXPECT_OBJCEQ(@"efgh", result);
    EXPECT_EQ(expectedScanLocation += 7, scanner.scanLocation);
    EXPECT_TRUE(scanner.atEnd);

    // Should fail to scan as the scanner is at the end
    ASSERT_FALSE([scanner scanCharactersFromSet:[NSCharacterSet letterCharacterSet] intoString:&result]);
}

TEST(NSScanner, ScanString) {
    NSScanner* scanner = [NSScanner scannerWithString:@"abcd123efgh456"];
    NSUInteger expectedScanLocation = 0;
    NSString* result;

    // Should fail to scan the empty string
    ASSERT_FALSE([scanner scanString:@"" intoString:&result]);

    ASSERT_TRUE([scanner scanString:@"abcd" intoString:&result]);
    EXPECT_OBJCEQ(@"abcd", result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Fails to scan as the next string is not abcd
    ASSERT_FALSE([scanner scanString:@"abcd" intoString:&result]);
    EXPECT_EQ(expectedScanLocation, scanner.scanLocation);

    // Set them to be skipped
    scanner.charactersToBeSkipped = [NSCharacterSet decimalDigitCharacterSet];

    // Can proceed now, considered to have reached the end
    ASSERT_TRUE([scanner scanString:@"efgh" intoString:&result]);
    EXPECT_OBJCEQ(@"efgh", result);
    EXPECT_EQ(expectedScanLocation += 7, scanner.scanLocation);
    EXPECT_TRUE(scanner.atEnd);

    // Should fail to scan as the scanner is at the end
    ASSERT_FALSE([scanner scanCharactersFromSet:[NSCharacterSet letterCharacterSet] intoString:&result]);

    // Should fail to scan the empty string, still
    ASSERT_FALSE([scanner scanString:@"" intoString:&result]);
}

TEST(NSScanner, ScanUpToCharactersFromSet) {
    NSScanner* scanner = [NSScanner scannerWithString:@"abcd123efgh456 ijk"];
    NSUInteger expectedScanLocation = 0;
    NSString* result;

    ASSERT_TRUE([scanner scanUpToCharactersFromSet:[NSCharacterSet decimalDigitCharacterSet] intoString:&result]);
    EXPECT_OBJCEQ(@"abcd", result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Fails to scan as 123 are in the scanUpTo set
    ASSERT_FALSE([scanner scanUpToCharactersFromSet:[NSCharacterSet decimalDigitCharacterSet] intoString:&result]);
    EXPECT_EQ(expectedScanLocation, scanner.scanLocation);

    // Scan up to letters instead
    ASSERT_TRUE([scanner scanUpToCharactersFromSet:[NSCharacterSet letterCharacterSet] intoString:&result]);
    EXPECT_OBJCEQ(@"123", result);
    EXPECT_EQ(expectedScanLocation += 3, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Scan up to something not in the string
    ASSERT_TRUE([scanner scanUpToCharactersFromSet:[NSCharacterSet uppercaseLetterCharacterSet] intoString:&result]);
    EXPECT_OBJCEQ(@"efgh456 ijk", result);
    EXPECT_EQ(expectedScanLocation += 11, scanner.scanLocation);
    EXPECT_TRUE(scanner.atEnd);
}

TEST(NSScanner, ScanUpToString) {
    NSScanner* scanner = [NSScanner scannerWithString:@"abcd123efgh456 ijk"];
    NSUInteger expectedScanLocation = 0;
    NSString* result;

    // Scanning up to the empty string should return the whole string
    ASSERT_TRUE([scanner scanUpToString:@"" intoString:&result]);
    EXPECT_OBJCEQ(@"abcd123efgh456 ijk", result);
    EXPECT_EQ(18, scanner.scanLocation);
    EXPECT_TRUE(scanner.atEnd);

    // Reset back to the beginning and scan again
    scanner.scanLocation = 0;
    ASSERT_TRUE([scanner scanUpToString:@"cd" intoString:&result]);
    EXPECT_OBJCEQ(@"ab", result);
    EXPECT_EQ(expectedScanLocation += 2, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Fails to scan as cd is next set of characters in the string
    ASSERT_FALSE([scanner scanUpToString:@"cd" intoString:&result]);
    EXPECT_EQ(expectedScanLocation, scanner.scanLocation);

    // Scan up to efgh instead
    ASSERT_TRUE([scanner scanUpToString:@"efgh" intoString:&result]);
    EXPECT_OBJCEQ(@"cd123", result);
    EXPECT_EQ(expectedScanLocation += 5, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Scanning up to something not in the string just returns the rest of the string
    ASSERT_TRUE([scanner scanUpToString:@"z" intoString:&result]);
    EXPECT_OBJCEQ(@"efgh456 ijk", result);
    EXPECT_EQ(expectedScanLocation += 11, scanner.scanLocation);
    EXPECT_TRUE(scanner.atEnd);

    // Should fail to scan the empty string now that it's at the end
    ASSERT_FALSE([scanner scanUpToString:@"" intoString:&result]);
}

TEST(NSScanner, ScanString_DifferentRepresentations) {
    NSString* stringLiteral = @"Hello";
    const unsigned char stringUTF8[] = { 'H', 'e', 'l', 'l', 'o', 0 };
    const unsigned char stringUTF16[] = { 'H', 0, 'e', 0, 'l', 0, 'l', 0, 'o', 0, 0, 0 };
    NSString* stringUTF8String = [NSMutableString stringWithUTF8String:reinterpret_cast<const char*>(stringUTF8)];
    NSString* stringUTF16String = [NSMutableString stringWithCharacters:reinterpret_cast<const unichar*>(stringUTF16) length:5];

    NSArray* strings = @[ stringLiteral, stringUTF8String, stringUTF16String ];

    NSScanner* scanner = [NSScanner scannerWithString:stringLiteral];
    NSString* result;

    for (NSString* string in strings) {
        scanner.scanLocation = 0;
        ASSERT_TRUE([scanner scanString:string intoString:&result]);
        EXPECT_OBJCEQ(string, result);
        EXPECT_EQ(5, scanner.scanLocation);
        EXPECT_TRUE(scanner.atEnd);

        scanner.scanLocation = 0;
        ASSERT_TRUE([scanner scanUpToString:@"ello" intoString:&result]);
        EXPECT_OBJCEQ(@"H", result);
        EXPECT_EQ(1, scanner.scanLocation);
        EXPECT_FALSE(scanner.atEnd);

        NSScanner* scannerWithStringRepresentation = [NSScanner scannerWithString:string];
        ASSERT_TRUE([scannerWithStringRepresentation scanString:@"Hello" intoString:&result]);
        EXPECT_OBJCEQ(@"Hello", result);
        EXPECT_EQ(5, scannerWithStringRepresentation.scanLocation);
        EXPECT_TRUE(scannerWithStringRepresentation.atEnd);

        scannerWithStringRepresentation.scanLocation = 0;
        ASSERT_TRUE([scannerWithStringRepresentation scanUpToString:@"ello" intoString:&result]);
        EXPECT_OBJCEQ(@"H", result);
        EXPECT_EQ(1, scannerWithStringRepresentation.scanLocation);
        EXPECT_FALSE(scannerWithStringRepresentation.atEnd);
    }
}

// Shared test logic for ScanDouble; ScanFloat, and ScanDecimal
template <typename TFloatingPoint>
static void testScanFloatingPoint(SEL sel, void (*expectFunc)(const double, const TFloatingPoint)) {
    NSScanner* scanner = [NSScanner scannerWithString:@":123 123,456.789 0.123 .123 123,456.789"];
    scanner.charactersToBeSkipped = [NSCharacterSet characterSetWithCharactersInString:@":"];
    NSUInteger expectedScanLocation = 0;
    TFloatingPoint result;

    ASSERT_TRUE(performScan(scanner, sel, &result));
    expectFunc(123, result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Should be unable to progress since spaces are no longer in the set of characters to skip
    ASSERT_FALSE(performScan(scanner, sel, &result));
    scanner.charactersToBeSkipped = [NSCharacterSet characterSetWithCharactersInString:@": "];

    // Commas are not factored in
    ASSERT_TRUE(performScan(scanner, sel, &result));
    expectFunc(123, result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Comma blocks scanning, in fact
    ASSERT_FALSE(performScan(scanner, sel, &result));

    scanner.scanLocation = scanner.scanLocation + 1;
    ASSERT_TRUE(performScan(scanner, sel, &result));
    expectFunc(456.789, result);
    EXPECT_EQ(expectedScanLocation += 8, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // 0.123 should be scannable
    ASSERT_TRUE(performScan(scanner, sel, &result));
    expectFunc(0.123, result);
    EXPECT_EQ(expectedScanLocation += 6, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // .123 should be scannable
    ASSERT_TRUE(performScan(scanner, sel, &result));
    expectFunc(0.123, result);
    EXPECT_EQ(expectedScanLocation += 5, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Changing to a locale with a different decimal separator should work, and begin ignoring '.' as the decimal separator
    scanner.locale = [[[NSLocale alloc] initWithLocaleIdentifier:@"fr_FR"] autorelease];
    ASSERT_TRUE(performScan(scanner, sel, &result));
    expectFunc(123.456, result);
    EXPECT_EQ(expectedScanLocation += 8, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    ASSERT_FALSE(performScan(scanner, sel, &result));
}

TEST(NSScanner, ScanDouble) {
    testScanFloatingPoint<double>(@selector(scanDouble:),
                                  [](const double expected, const double result) { EXPECT_NEAR(expected, result, c_floatingPtTolerance); });
}

TEST(NSScanner, ScanFloat) {
    testScanFloatingPoint<float>(@selector(scanFloat:), [](const double expected, const float result) {
        EXPECT_NEAR(static_cast<float>(expected), result, c_floatingPtTolerance);
    });
}

TEST(NSScanner, ScanDecimal) {
    testScanFloatingPoint<NSDecimal>(@selector(scanDecimal:), [](const double expected, const NSDecimal result) {
        NSDecimalNumber* difference = [[NSDecimalNumber decimalNumberWithDecimal:result]
            decimalNumberBySubtracting:static_cast<NSDecimalNumber*>([NSDecimalNumber numberWithDouble:expected])];

        EXPECT_EQ(NSOrderedAscending, [difference compare:[NSDecimalNumber numberWithDouble:c_floatingPtTolerance]]);
        EXPECT_EQ(NSOrderedDescending, [difference compare:[NSDecimalNumber numberWithDouble:-c_floatingPtTolerance]]);
    });
}

template <typename TFloatingPoint>
static void testScanHexFloatingPoint(SEL sel) {
    NSScanner* scanner = [NSScanner
        scannerWithString:
            @"::badinput :0x1p-10 0X1p-10 0x 0x3 0x33 0x00 0xp-10 ::1p-10 0xp-10 0x1.fffP+20 0x1.fffP20 0x1...fffP+20 -0x1.cafeP-100 "
            @"--0x1.cafeP-100 +0x1.cafeP-100 0x1.cafeP-2047 -0x1.cafeP+2048 0x1.cafeP+2048 0x1.cafeP+1000 0x1.23456789aabbccddeeffp+3"];
    scanner.charactersToBeSkipped = [NSCharacterSet characterSetWithCharactersInString:@": "];
    NSUInteger expectedScanLocation = 0;
    TFloatingPoint result;

    // Obvious bad input should fail
    ASSERT_FALSE(performScan(scanner, sel, &result));
    EXPECT_EQ(expectedScanLocation, scanner.scanLocation);
    scanner.scanLocation = scanner.scanLocation + 10;

    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0x1p-10, result);
    EXPECT_EQ(expectedScanLocation += 19, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Case shouldn't matter
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0x1p-10, result);
    EXPECT_EQ(expectedScanLocation += 8, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // '0x' by itself is invalid
    ASSERT_FALSE(performScan(scanner, sel, &result));
    EXPECT_EQ(expectedScanLocation, scanner.scanLocation);
    scanner.scanLocation = scanner.scanLocation + 3;

    // '1.' should not be required
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0x3, result);
    EXPECT_EQ(expectedScanLocation += 7, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0x33, result);
    EXPECT_EQ(expectedScanLocation += 5, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // 0x00 should be valid
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0, result);
    EXPECT_EQ(expectedScanLocation += 5, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // 0xp-10 shouldn't be valid
    ASSERT_FALSE(performScan(scanner, sel, &result));
    EXPECT_EQ(expectedScanLocation, scanner.scanLocation);
    scanner.scanLocation = scanner.scanLocation + 7;

    // Unlike scanInt/Integer et al, 0x is required
    ASSERT_FALSE(performScan(scanner, sel, &result));
    EXPECT_EQ(expectedScanLocation += 7, scanner.scanLocation);
    scanner.scanLocation = scanner.scanLocation + 8;

    // At least a single digit for the fraction/mantissa is required
    ASSERT_FALSE(performScan(scanner, sel, &result));
    EXPECT_EQ(expectedScanLocation += 8, scanner.scanLocation);
    scanner.scanLocation = scanner.scanLocation + 7;

    // Periods and positive exponents should be accepted
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0x1.fffp+20, result);
    EXPECT_EQ(expectedScanLocation += 19, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // If no + or - is provided for the exponent, + should be assumed
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0x1.fffp+20, result);
    EXPECT_EQ(expectedScanLocation += 11, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Multiple periods should be considered the end of the number
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0x1, result);
    EXPECT_EQ(expectedScanLocation += 5, scanner.scanLocation); // Note that the first period is scanned
    EXPECT_FALSE(scanner.atEnd);
    scanner.scanLocation = scanner.scanLocation + 9;

    // - before the number should be scanned as the sign bit
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(-0x1.cafep-100, result);
    EXPECT_EQ(expectedScanLocation += 24, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Multiple -s before the should be invalid
    ASSERT_FALSE(performScan(scanner, sel, &result));
    EXPECT_EQ(expectedScanLocation, scanner.scanLocation);
    scanner.scanLocation = scanner.scanLocation + 16;

    // + before the number should be scanned as the sign bit
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0x1.cafep-100, result);
    EXPECT_EQ(expectedScanLocation += 31, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Underflow should resolve to 0
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0, result);
    EXPECT_EQ(expectedScanLocation += 15, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Overflow should resolve to +/-HUGE_VAL
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(-HUGE_VAL, result);
    EXPECT_EQ(expectedScanLocation += 16, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(HUGE_VAL, result);
    EXPECT_EQ(expectedScanLocation += 15, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Should only overflow on float but not double
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ((sizeof(TFloatingPoint) > 4) ? 0x1.cafeP+1000 : HUGE_VAL, result);
    EXPECT_EQ(expectedScanLocation += 15, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // If the mantissa has too many bits to be represented, scanning should cut off the latter bits
    float expectedFloat = 0x1.234567p+3; // Declare as float here so it doesn't get instantiated as a double

    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ((sizeof(TFloatingPoint) > 4) ? 0x1.23456789aabbccp+3 : expectedFloat, result);
    EXPECT_TRUE(scanner.atEnd);
}

TEST(NSScanner, ScanHexDouble) {
    testScanHexFloatingPoint<double>(@selector(scanHexDouble:));
}

TEST(NSScanner, ScanHexFloat) {
    testScanHexFloatingPoint<float>(@selector(scanHexFloat:));
}

template <typename TIntegral>
static void testScanHexIntegral(SEL sel) {
    NSScanner* scanner =
        [NSScanner scannerWithString:@":123 :DEADBEEF 0xDEADBEEF 0Xdeadbeef 0xEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE 0xEEEEEEEEEE"];
    scanner.charactersToBeSkipped = [NSCharacterSet characterSetWithCharactersInString:@": "];
    NSUInteger expectedScanLocation = 0;
    TIntegral result;

    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0x123, result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0xDEADBEEF, result);
    EXPECT_EQ(expectedScanLocation += 10, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Capitalization shouldn't matter
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0xDEADBEEF, result);
    EXPECT_EQ(expectedScanLocation += 11, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0xDEADBEEF, result);
    EXPECT_EQ(expectedScanLocation += 11, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Overflow should be valid and return the maximum representable value
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(std::numeric_limits<TIntegral>::max(), result);
    EXPECT_EQ(expectedScanLocation += 40, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Should not overflow on >32 bit type
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(sizeof(TIntegral) > 4 ? 0xEEEEEEEEEE : std::numeric_limits<TIntegral>::max(), result);
    EXPECT_EQ(expectedScanLocation += 13, scanner.scanLocation);
    EXPECT_TRUE(scanner.atEnd);
}

TEST(NSScanner, ScanHexInt) {
    testScanHexIntegral<unsigned int>(@selector(scanHexInt:));
}

TEST(NSScanner, ScanHexLongLong) {
    testScanHexIntegral<unsigned long long>(@selector(scanHexLongLong:));
}

template <typename TSignedIntegral>
static void testScanSignedIntegral(SEL sel) {
    NSScanner* scanner =
        [NSScanner scannerWithString:@":123 :-123 +123 123-124 0xDEADBEEF 20000000000000000000 -20000000000000000000  2147483700"];
    scanner.charactersToBeSkipped = [NSCharacterSet characterSetWithCharactersInString:@": "];
    NSUInteger expectedScanLocation = 0;
    TSignedIntegral result;

    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(123, result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Negative number should still get scanned
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(-123, result);
    EXPECT_EQ(expectedScanLocation += 6, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // + should also be accepted
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(123, result);
    EXPECT_EQ(expectedScanLocation += 5, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // - should be interpreted as the start of a new number
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(123, result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(-124, result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Hex numbers should not be scanned properly
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(0, result);
    EXPECT_EQ(expectedScanLocation + 2, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    scanner.scanLocation = scanner.scanLocation - 2;
    ASSERT_TRUE([scanner scanHexInt:nullptr]);
    EXPECT_EQ(expectedScanLocation += 11, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Overflow should be valid and return the maximum representable value
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(std::numeric_limits<TSignedIntegral>::max(), result);
    EXPECT_EQ(expectedScanLocation += 21, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Underflow should also be valid
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ(std::numeric_limits<TSignedIntegral>::min(), result);
    EXPECT_EQ(expectedScanLocation += 22, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Should not overflow on the >32 bit types
    ASSERT_TRUE(performScan(scanner, sel, &result));
    EXPECT_EQ((sizeof(TSignedIntegral) > 4) ? 2147483700LL : std::numeric_limits<TSignedIntegral>::max(), result);
    EXPECT_EQ(expectedScanLocation += 12, scanner.scanLocation);
    EXPECT_TRUE(scanner.atEnd);
}

TEST(NSScanner, ScanInt) {
    testScanSignedIntegral<int>(@selector(scanInt:));
}

TEST(NSScanner, ScanInteger) {
    testScanSignedIntegral<NSInteger>(@selector(scanInteger:));
}

TEST(NSScanner, ScanLongLong) {
    testScanSignedIntegral<long long>(@selector(scanLongLong:));
}

TEST(NSScanner, ScanUnsignedLongLong) {
    NSScanner* scanner = [NSScanner scannerWithString:@":123 :-123 +123 123-124 0xDEADBEEF 20000000000000000000"];
    scanner.charactersToBeSkipped = [NSCharacterSet characterSetWithCharactersInString:@": "];
    NSUInteger expectedScanLocation = 0;
    unsigned long long result;

    ASSERT_TRUE([scanner scanUnsignedLongLong:&result]);
    EXPECT_EQ(123, result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // Negative number should be invalid
    ASSERT_FALSE([scanner scanUnsignedLongLong:&result]);
    EXPECT_EQ(expectedScanLocation, scanner.scanLocation);
    scanner.scanLocation = scanner.scanLocation + 6;

    // + should be accepted
    ASSERT_TRUE([scanner scanUnsignedLongLong:&result]);
    EXPECT_EQ(123, result);
    EXPECT_EQ(expectedScanLocation += 11, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);

    // - should be interpreted as the start of a new number
    ASSERT_TRUE([scanner scanUnsignedLongLong:&result]);
    EXPECT_EQ(123, result);
    EXPECT_EQ(expectedScanLocation += 4, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);
    scanner.scanLocation = scanner.scanLocation + 4;

    // Hex numbers should not be scanned properly
    ASSERT_TRUE([scanner scanUnsignedLongLong:&result]);
    EXPECT_EQ(0, result);
    EXPECT_EQ(expectedScanLocation += 6, scanner.scanLocation);
    EXPECT_FALSE(scanner.atEnd);
    scanner.scanLocation = scanner.scanLocation + 9;

    // Overflow should be valid and return the maximum representable value
    ASSERT_TRUE([scanner scanUnsignedLongLong:&result]);
    EXPECT_EQ(std::numeric_limits<unsigned long long>::max(), result);
    EXPECT_EQ(expectedScanLocation += 30, scanner.scanLocation);
    EXPECT_TRUE(scanner.atEnd);
}

TEST(NSScanner, Copy) {
    NSScanner* scanner = [NSScanner scannerWithString:@"123 456 789"];
    scanner.caseSensitive = YES;
    scanner.charactersToBeSkipped = [NSCharacterSet lowercaseLetterCharacterSet];
    scanner.locale = [[[NSLocale alloc] initWithLocaleIdentifier:@"fr_FR"] autorelease];

    int scannedInt;
    ASSERT_TRUE([scanner scanInt:&scannedInt]);
    ASSERT_EQ(123, scannedInt);
    ASSERT_EQ(3, scanner.scanLocation);

    NSScanner* copiedScanner = [scanner copy];
    EXPECT_OBJCEQ(scanner.string, copiedScanner.string);
    EXPECT_EQ(scanner.scanLocation, copiedScanner.scanLocation);
    EXPECT_EQ(scanner.caseSensitive, copiedScanner.caseSensitive);
    EXPECT_OBJCEQ(scanner.charactersToBeSkipped, copiedScanner.charactersToBeSkipped);
    EXPECT_OBJCEQ(scanner.locale, copiedScanner.locale);
}