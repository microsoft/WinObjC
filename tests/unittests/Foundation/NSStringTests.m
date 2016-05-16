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

void testUrlCharacterSetEncoding(NSString* decodedString, NSString* encodedString, NSCharacterSet* allowedCharacterSet) {
    NSString* testString = [decodedString stringByAddingPercentEncodingWithAllowedCharacters:allowedCharacterSet];
    ASSERT_OBJCEQ(encodedString, testString);
}

TEST(NSString, NSStringTests) {
    // NSString* PercentEncoding methods.
    NSString* decodedString = @"Space "
                              @"DoubleQuotes\"Hash#Percent%LessThan<GreaterThan>OpeningBracket[Backslash\\ClosingBracket]Caret^"
                              @"GraveAccent`OpeningBrace{VerticalBar|ClosingBrace}";
    NSString* encodedString = @"Space%20DoubleQuotes%22Hash%23Percent%25LessThan%3CGreaterThan%3EOpeningBracket%5BBackslash%"
                              @"5CClosingBracket%5DCaret%5EGraveAccent%60OpeningBrace%7BVerticalBar%7CClosingBrace%7D";

    NSString* testString = [decodedString stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    ASSERT_OBJCEQ(encodedString, testString);

    testString = [encodedString stringByReplacingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
    ASSERT_OBJCEQ(decodedString, testString);

    testString = [encodedString stringByRemovingPercentEncoding];
    ASSERT_OBJCEQ(decodedString, testString);

    NSString* urlDecodedString = @"https://www.microsoft.com/en-us/!@#$%^&*()_";
    NSString* urlEncodedString = @"https://www.microsoft.com/en-us/!@%23$%25%5E&*()_";
    NSCharacterSet* allowedCharacterSet = [NSCharacterSet URLFragmentAllowedCharacterSet];

    testUrlCharacterSetEncoding(urlDecodedString, urlEncodedString, allowedCharacterSet);

    urlDecodedString = @"Only alphabetic characters should be allowed and not encoded. !@#$%^&*()_+-=";
    urlEncodedString =
        @"Only%20alphabetic%20characters%20should%20be%20allowed%20and%20not%20encoded%2E%20%21%40%23%24%25%5E%26%2A%28%29%5F%2B%2D%3D";
    allowedCharacterSet = [NSCharacterSet alphanumericCharacterSet];

    testUrlCharacterSetEncoding(urlDecodedString, urlEncodedString, allowedCharacterSet);

    urlDecodedString = @"All alphabetic characters should be encoded. Symbols should not be: !@#$%^&*()_+-=";
    urlEncodedString = @"%41%6C%6C %61%6C%70%68%61%62%65%74%69%63 %63%68%61%72%61%63%74%65%72%73 %73%68%6F%75%6C%64 %62%65 "
                       @"%65%6E%63%6F%64%65%64. %53%79%6D%62%6F%6C%73 %73%68%6F%75%6C%64 %6E%6F%74 %62%65: !@#$%^&*()_+-=";
    allowedCharacterSet = [[NSCharacterSet alphanumericCharacterSet] invertedSet];

    testUrlCharacterSetEncoding(urlDecodedString, urlEncodedString, allowedCharacterSet);

    urlDecodedString = @"Here are some Emojis: \U0001F601 \U0001F602 \U0001F638 Emojis done."; // Multibyte encoded characters
    urlEncodedString = @"Here%20are%20some%20Emojis:%20%F0%9F%98%81%20%F0%9F%98%82%20%F0%9F%98%B8%20Emojis%20done.";
    allowedCharacterSet = [NSCharacterSet URLFragmentAllowedCharacterSet];

    testUrlCharacterSetEncoding(urlDecodedString, urlEncodedString, allowedCharacterSet);

    urlDecodedString = @"\1";
    urlEncodedString = @"%01";
    allowedCharacterSet = [NSCharacterSet alphanumericCharacterSet];

    testUrlCharacterSetEncoding(urlDecodedString, urlEncodedString, allowedCharacterSet);

    NSString* stringWillDie = [NSMutableString stringWithString:@"EntirelyAllowedCharacters"];
    urlEncodedString = @"EntirelyAllowedCharacters";
    allowedCharacterSet = [NSCharacterSet alphanumericCharacterSet];

    testString = [stringWillDie stringByAddingPercentEncodingWithAllowedCharacters:allowedCharacterSet];
    ASSERT_OBJCEQ(urlEncodedString, testString);

    // stringByAppendingFormat test
    NSString* testString2 = @"Numbers: ";
    NSString* expectedString = @"Numbers: 1, 2";
    NSString* actualString = [testString2 stringByAppendingFormat:@"%d, %@", 1, @"2"];
    ASSERT_OBJCEQ(expectedString, actualString);

    // stringWithFormat tests
    actualString = [NSString stringWithFormat:@"%x %d %u %.1f %o %c", 10, 11, 12, 13.0f, 14, 'a'];
    ASSERT_OBJCEQ(@"a 11 12 13.0 16 a", actualString);

    // %i is undocumented, but apps use it
    actualString = [NSString stringWithFormat:@"%i", -1];
    ASSERT_OBJCEQ(@"-1", actualString);

    actualString = [NSString stringWithFormat:@"%hhd %hd %ld %llX", (char)1, (short)2, 3L, -1ULL];
    ASSERT_OBJCEQ(@"1 2 3 FFFFFFFFFFFFFFFF", actualString);

    actualString = [NSString stringWithFormat:@"%zx %zd", SIZE_MAX, INT_MIN];
    ASSERT_OBJCEQ(@"ffffffff -2147483648", actualString);

    actualString = [NSString stringWithFormat:@"%tx %td", PTRDIFF_MAX, PTRDIFF_MIN];
    ASSERT_OBJCEQ(@"7fffffff -2147483648", actualString);

    actualString = [NSString stringWithFormat:@"%jx %jd", UINTMAX_MAX, INTMAX_MIN];
    ASSERT_OBJCEQ(@"ffffffffffffffff -9223372036854775808", actualString);

    actualString = [NSString stringWithFormat:@"%qx %qd", ULLONG_MAX, LLONG_MIN];
    ASSERT_OBJCEQ(@"ffffffffffffffff -9223372036854775808", actualString);

    // Formatting with %g looks like it's printing the wrong number of digits, but it matches
    // the reference platform
    actualString = [NSString stringWithFormat:@"%.1e %.1E %.1g %.1G", 1e10, 1e0, 1e10, 1e0];
    ASSERT_OBJCEQ(@"1.0e+10 1.0E+00 1e+10 1", actualString);

    // rangeOfCharactersFromSet test
    NSString* testString3 = @"Alpha Bravo Charlie";
    NSCharacterSet* charSet = [NSCharacterSet whitespaceAndNewlineCharacterSet];
    NSRange range;

    range = [testString3 rangeOfCharacterFromSet:charSet options:0];
    ASSERT_EQ(5, range.location);
    range = [testString3 rangeOfCharacterFromSet:charSet options:NSBackwardsSearch];
    ASSERT_EQ(11, range.location);
}

TEST(NSString, NSString_FastestEncoding) {
    NSString* asciiStr = @"ObjectiveC";
    NSString* extendedAsciiStr = @"ObjectiveC éééé";
    NSString* chineseStr = @"中文";

    ASSERT_EQ(NSASCIIStringEncoding, [asciiStr fastestEncoding]);
    ASSERT_EQ(NSUnicodeStringEncoding, [extendedAsciiStr fastestEncoding]);
    ASSERT_EQ(NSUnicodeStringEncoding, [chineseStr fastestEncoding]);

    ASSERT_EQ(kCFStringEncodingASCII, CFStringGetFastestEncoding(reinterpret_cast<CFStringRef>(asciiStr)));
    ASSERT_EQ(kCFStringEncodingUnicode, CFStringGetFastestEncoding(reinterpret_cast<CFStringRef>(extendedAsciiStr)));
    ASSERT_EQ(kCFStringEncodingUnicode, CFStringGetFastestEncoding(reinterpret_cast<CFStringRef>(chineseStr)));
}

TEST(NSString, UnownedDeepCopy) {
    char* buffer = _strdup("Hello World");
    NSString* firstString =
        [[[NSString alloc] initWithBytesNoCopy:buffer length:11 encoding:NSUTF8StringEncoding freeWhenDone:NO] autorelease];
    NSString* secondString = [[firstString copy] autorelease];

    EXPECT_OBJCEQ(firstString, secondString);

    buffer[0] = '\'';
    EXPECT_OBJCNE(firstString, secondString);
    free(buffer);
}

TEST(NSString, SubstringFromIndex) {
    NSString* asciiStr = @"ObjectiveC";
    NSString* extendedAsciiStr = @"ObjectiveC éééé";
    NSString* chineseStr = @"中文";
    ASSERT_OBJCEQ(@"tiveC", [asciiStr substringFromIndex:5]);
    ASSERT_OBJCEQ(@"C éééé", [extendedAsciiStr substringFromIndex:9]);
    ASSERT_OBJCEQ(@"文", [chineseStr substringFromIndex:1]);
}