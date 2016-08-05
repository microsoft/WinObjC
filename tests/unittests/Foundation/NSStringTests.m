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

#import <TestFramework.h>
#import <Foundation/Foundation.h>

#import <windows.h>

void testUrlCharacterSetEncoding(NSString* decodedString, NSString* encodedString, NSCharacterSet* allowedCharacterSet) {
    NSString* testString = [decodedString stringByAddingPercentEncodingWithAllowedCharacters:allowedCharacterSet];
    ASSERT_OBJCEQ(encodedString, testString);
}

TEST(NSString, NSStringTests) {
    // NSString PercentEncoding methods.
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

TEST(NSString, PositionalFormatSpecifiers) {
    NSString* formattedString1 = [NSString stringWithFormat:@"%2$@ %1$@", @"Hello", @"World"];
    ASSERT_OBJCEQ(@"World Hello", formattedString1);

    NSString* formattedString2 = [NSString stringWithFormat:@"%4$d %3$d %2$d %1$d", 1, 2, 3, 4];
    ASSERT_OBJCEQ(@"4 3 2 1", formattedString2);
}

TEST(NSString, InitWithFormat) {
    NSString* string = [[[NSString alloc] initWithFormat:@"Default value is %d (%.1f)" locale:nil, 1000, 42.0] autorelease];
    ASSERT_OBJCEQ(string, @"Default value is 1000 (42.0)");

    string = [[[NSString alloc] initWithFormat:@"en_GB value is %d (%.1f)"
                                        locale:[NSLocale localeWithLocaleIdentifier:@"en_GB"], 1000, 42.0] autorelease];
    ASSERT_OBJCEQ(string, @"en_GB value is 1,000 (42.0)");

    string = [[[NSString alloc] initWithFormat:@"de_DE value is %d (%.1f)"
                                        locale:[NSLocale localeWithLocaleIdentifier:@"de_DE"], 1000, 42.0] autorelease];
    ASSERT_OBJCEQ(string, @"de_DE value is 1.000 (42,0)");

    string = [[[NSString alloc] initWithFormat:@"Default value is %d (%.1f)" locale:nil, 1000, 42.0] autorelease];
    ASSERT_OBJCEQ(string, @"Default value is 1000 (42.0)");

    UInt8 val = 75;
    string = [[[NSString alloc] initWithFormat:@"%02X" locale:nil, val] autorelease];
    ASSERT_OBJCEQ(string, @"4B");
}

TEST(NSString, LocalizedStandardCompare) {
    NSString* string = @"Abc3";
    ASSERT_EQ(NSOrderedAscending, [string localizedStandardCompare:@"ABC4"]);
}

TEST(NSString, PropertyList) {
    NSString* string = @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" "
                       @"\"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n<plist "
                       @"version=\"1.0\">\n<dict>\n<key>Name</key>\n<string>John "
                       @"Doe</string>\n<key>Phones</key>\n<array>\n<string>408-974-0000</string>\n<string>503-333-5555</string>\n</"
                       @"array>\n</dict>\n</plist>";
    NSDictionary* plistDict;
    ASSERT_NO_THROW({ plistDict = [string propertyList]; });
    ASSERT_NE(nil, plistDict);

    NSDictionary* dict = [[[NSDictionary alloc]
        initWithObjectsAndKeys:@"John Doe", @"Name", @[ @"408-974-0000", @"503-333-5555" ], @"Phones", nil] autorelease];
    ASSERT_NE(nil, dict);
    ASSERT_OBJCEQ(dict, plistDict);
}

TEST(NSString, SubstringWithRangeOfComposedCharacterSequences) {
    NSString* string = @"😀H😀A😀👴🏻👮🏽";
    NSRange result = [string rangeOfComposedCharacterSequenceAtIndex:3];
    ASSERT_EQ(2, result.length);
    ASSERT_EQ(3, result.location);
}

TEST(NSString, RangeOfComposedCharacterSequencesForRange) {
    NSString* string = @"👴🏻👮🏽";
    NSRange result = [string rangeOfComposedCharacterSequencesForRange:NSMakeRange(0, [string length])];
    ASSERT_EQ(8, result.length);
}

TEST(NSString, Accents) {
    NSString* string = @"a\u0301";
    NSRange result = [string rangeOfComposedCharacterSequencesForRange:NSMakeRange(0, 1)];
    ASSERT_EQ(2, result.length);

    result = [string rangeOfComposedCharacterSequencesForRange:NSMakeRange(1, 1)];
    ASSERT_EQ(2, result.length);

    string = @"á";
    result = [string rangeOfComposedCharacterSequencesForRange:NSMakeRange(0, 1)];
    ASSERT_EQ(1, result.length);
}

TEST(NSString, GetParagraphStart) {
    NSString* paragraph = @"The NSString class and its mutable subclass, NSMutableString, provide an extensive set of APIs for working "
                          @"with strings, including methods for comparing, searching, and modifying strings. NSString objects are used "
                          @"extensively throughout Foundation and other Cocoa frameworks, serving as the basis for all textual and "
                          @"linguistic functionality on the platform.\r\nNSString is “toll-free bridged” with its Core Foundation "
                          @"counterpart, CFStringRef. See “Toll-Free Bridging” for more information.";
    NSUInteger startIndex, endIndex;
    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange(0, [paragraph length])];

    ASSERT_EQ('T', [paragraph characterAtIndex:startIndex]);
    ASSERT_EQ([paragraph length], endIndex);
}

TEST(NSString, GetParagraphStart2) {
    NSString* paragraph = @"\n\nThe NSString class and its mutable subclass, NSMutableString, provide an extensive set of APIs for working "
                          @"with strings, including methods for comparing, searching, and modifying strings. NSString objects are used "
                          @"extensively throughout Foundation and other Cocoa frameworks, serving as the basis for all textual and "
                          @"linguistic functionality on the platform.\r\nrNSString is “toll-free bridged” with its Core Foundation "
                          @"counterpart, CFStringRef. See “Toll-Free Bridging” for more information.\n\n";
    NSUInteger startIndex, endIndex;
    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange(1, [paragraph length] - 1)];

    ASSERT_EQ(1, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
}

TEST(NSString, GetParagraphStart3) {
    NSString* paragraph = @"\nThe NSString class and its mutable subclass, NSMutableString, provide an extensive set of APIs for working "
                          @"with strings, including methods for comparing, searching, and modifying strings. NSString objects are used "
                          @"extensively throughout Foundation and other Cocoa frameworks, serving as the basis for all textual and "
                          @"linguistic functionality on the platform.\r\nNSString is “toll-free bridged” with its Core Foundation "
                          @"counterpart, CFStringRef. See “Toll-Free Bridging” for more informat\n\nion.";
    NSUInteger startIndex, endIndex;
    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange(1, [paragraph length] - 1)];

    ASSERT_EQ(1, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
}

TEST(NSString, GetParagraphStart4) {
    NSString* paragraph = @"\n\rThe NSString class and its mutable subclass, NSMutableString, provide an extensive set of APIs for working "
                          @"with strings, including methods for comparing, searching, and modifying strings. NSString objects are used "
                          @"extensively throughout Foundation and other Cocoa frameworks, serving as the basis for all textual and "
                          @"linguistic functionality on the platform.\r\nNSString is “toll-free bridged” with its Core Foundation "
                          @"counterpart, CFStringRef. See “Toll-Free Bridging” for more information.\r\n";
    NSUInteger startIndex, endIndex;
    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange(1, [paragraph length] - 1)];

    ASSERT_EQ(1, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
}

TEST(NSString, GetParagraphStart5) {
    NSString* paragraph = @"\n\rThe NSString class and its mutable subclass, NSMutableString, provide an extensive set of APIs for working "
                          @"with strings, including methods for comparing, searching, and modifying strings. NSString objects are used "
                          @"extensively throughout Foundation and other Cocoa frameworks, serving as the basis for all textual and "
                          @"linguistic functionality on the platform.\r\nNSString is “toll-free bridged” with its Core Foundation "
                          @"counterpart, CFStringRef. See “Toll-Free Bridging” for more information.\r\n";
    NSUInteger startIndex, endIndex;
    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange(1, 0)];

    ASSERT_EQ(1, startIndex);
    ASSERT_EQ(2, endIndex);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange(1, 20)];
    ASSERT_EQ(1, startIndex);
    ASSERT_EQ(362, endIndex);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange(10, 20)];
    ASSERT_EQ(2, startIndex);
    ASSERT_EQ(362, endIndex);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange(365, [paragraph length] - 365)];
    ASSERT_EQ(362, startIndex);
    ASSERT_EQ([paragraph length], endIndex);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange(0, [paragraph length])];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange([paragraph length], 0)];
    ASSERT_EQ([paragraph length], startIndex);
    ASSERT_EQ([paragraph length], endIndex);
}

TEST(NSString, GetParagraphStart6) {
    NSString* paragraph = @"\n\rThe NSString class and its mutable subclass, NSMutableString, provide an extensive set of APIs for working "
                          @"with strings, including methods for comparing, searching, and modifying strings. NSString objects are used "
                          @"extensively throughout Foundation and other Cocoa frameworks, serving as the basis for all textual and "
                          @"linguistic functionality on the platform.\r\nNSString is “toll-free bridged” with its Core Foundation "
                          @"counterpart, CFStringRef. See “Toll-Free Bridging” for more information.";
    NSUInteger startIndex, endIndex;
    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:NULL forRange:NSMakeRange(0, [paragraph length])];

    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
}

TEST(NSString, GetParagraphStart7) {
    NSString* paragraph = @"\r";
    NSUInteger startIndex, endIndex, contentsEnd;
    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, 1)];

    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ(0, contentsEnd);
}

TEST(NSString, GetParagraphStart8) {
    NSString* paragraph = @"\n\rThe NSString class and its mutable subclass, NSMutableString, provide an extensive set of APIs for working "
                          @"with strings, including methods for comparing, searching, and modifying strings. NSString objects are used "
                          @"extensively throughout Foundation and other Cocoa frameworks, serving as the basis for all textual and "
                          @"linguistic functionality on the platform.\r\nNSString is “toll-free bridged” with its Core Foundation "
                          @"counterpart, CFStringRef. See “Toll-Free Bridging” for more information.\r";
    NSUInteger startIndex, endIndex, contentsEnd;
    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, [paragraph length])];

    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 1, contentsEnd);
}

TEST(NSString, GetParagraphStart9) {
    NSString* paragraph = @"\r\nThe NSString class and its mutable subclass, NSMutableString, provide an extensive set of APIs for working "
                          @"with strings, including methods for comparing, searching, and modifying strings. NSString objects are used "
                          @"extensively throughout Foundation and other Cocoa frameworks, serving as the basis for all textual and "
                          @"linguistic functionality on the platform.\r\nNSString is “toll-free bridged” with its Core Foundation "
                          @"counterpart, CFStringRef. See “Toll-Free Bridging” for more information.\r";
    NSUInteger startIndex, endIndex, contentsEnd;

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(1, [paragraph length] - 1)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 1, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(1, 20)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ(362, endIndex);
    ASSERT_EQ(360, contentsEnd);
}

TEST(NSString, GetParagraphStartEmptyString) {
    NSString* paragraph = @"";
    NSUInteger startIndex, endIndex, contentsEnd;

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, 0)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ(0, endIndex);
    ASSERT_EQ(0, contentsEnd);
}

TEST(NSString, GetParagraphStringWithBytes) {
    NSUInteger startIndex, endIndex, contentsEnd;
    UInt8 data[] = { 'H', '\0', 'E', 'L', '0', '\0', 'W', '\n', '\r' };
    NSString* paragraph = [static_cast<NSString*>(CFStringCreateWithBytes(NULL, data, 9, kCFStringEncodingUTF8, true)) autorelease];
    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, [paragraph length])];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 1, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(1, [paragraph length] - 1)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 1, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, 0)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length] - 1, endIndex);
    ASSERT_EQ([paragraph length] - 2, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange([paragraph length], 0)];
    ASSERT_EQ([paragraph length], startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length], contentsEnd);
}

TEST(NSString, GetParagraphStringWithBytes2) {
    NSUInteger startIndex, endIndex, contentsEnd;
    UInt8 data[] = { '\0', '\n', 'H', '\0', 'E', 'L', '0', '\0', 'W', '\r', '\n' };
    NSString* paragraph = [static_cast<NSString*>(CFStringCreateWithBytes(NULL, data, 11, kCFStringEncodingUTF8, true)) autorelease];
    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, [paragraph length])];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 2, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(1, [paragraph length] - 1)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 2, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, 0)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ(2, endIndex);
    ASSERT_EQ(1, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange([paragraph length], 0)];
    ASSERT_EQ([paragraph length], startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length], contentsEnd);
}

TEST(NSString, GetParagraphStringWithBytes3) {
    NSUInteger startIndex, endIndex, contentsEnd;
    UInt8 data[] = { '\n', 'H', '\0', 'E', 'L', '0', '\0', 'W', '\r' };
    NSString* paragraph = [static_cast<NSString*>(CFStringCreateWithBytes(NULL, data, 9, kCFStringEncodingUTF8, true)) autorelease];

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, [paragraph length])];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 1, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(1, [paragraph length] - 1)];
    ASSERT_EQ(1, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 1, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, 0)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ(1, endIndex);
    ASSERT_EQ(0, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange([paragraph length], 0)];
    ASSERT_EQ([paragraph length], startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length], contentsEnd);
}

TEST(NSString, GetParagraphStringWithBytes4) {
    NSUInteger startIndex, endIndex, contentsEnd;
    UInt8 data[] = { '\r', 'H', '\0', 'E', 'L', '0', '\0', 'W', '\r' };
    NSString* paragraph = [static_cast<NSString*>(CFStringCreateWithBytes(NULL, data, 9, kCFStringEncodingUTF8, true)) autorelease];

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, [paragraph length])];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 1, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(1, [paragraph length] - 1)];
    ASSERT_EQ(1, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 1, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, 0)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ(1, endIndex);
    ASSERT_EQ(0, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange([paragraph length], 0)];
    ASSERT_EQ([paragraph length], startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length], contentsEnd);
}

TEST(NSString, GetParagraphStringWithBytes5) {
    NSUInteger startIndex, endIndex, contentsEnd;
    UInt8 data[] = { '\n', '\r', 'H', '\0', 'E', 'L', '0', '\0', 'W', '\r' };
    NSString* paragraph = [static_cast<NSString*>(CFStringCreateWithBytes(NULL, data, 10, kCFStringEncodingUTF8, true)) autorelease];

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, [paragraph length])];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 1, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(1, [paragraph length] - 1)];
    ASSERT_EQ(1, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 1, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, 0)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ(1, endIndex);
    ASSERT_EQ(0, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange([paragraph length], 0)];
    ASSERT_EQ([paragraph length], startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length], contentsEnd);
}

TEST(NSString, GetParagraphStringWithBytes6) {
    NSUInteger startIndex, endIndex, contentsEnd;
    UInt8 data[] = { '\r', '\n', 'H', '\0', 'E', 'L', '0', '\0', 'W', '\r', '\n' };
    NSString* paragraph = [static_cast<NSString*>(CFStringCreateWithBytes(NULL, data, 11, kCFStringEncodingUTF8, true)) autorelease];

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, [paragraph length])];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 2, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(1, [paragraph length] - 1)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length] - 2, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange(0, 0)];
    ASSERT_EQ(0, startIndex);
    ASSERT_EQ(2, endIndex);
    ASSERT_EQ(0, contentsEnd);

    [paragraph getParagraphStart:&startIndex end:&endIndex contentsEnd:&contentsEnd forRange:NSMakeRange([paragraph length], 0)];
    ASSERT_EQ([paragraph length], startIndex);
    ASSERT_EQ([paragraph length], endIndex);
    ASSERT_EQ([paragraph length], contentsEnd);
}

TEST(NSString, PathExtensions) {
    NSString* string = @"";
    ASSERT_TRUE([string.pathExtension isEqualToString:@""]);

    string = @"hello.world";
    ASSERT_TRUE([string.pathExtension isEqualToString:@"world"]);

    string = @"C:\FolderA\file.plist";
    ASSERT_TRUE([string.pathExtension isEqualToString:@"plist"]);

    string = @"/tmp/scratch.tiff";
    ASSERT_TRUE([string.pathExtension isEqualToString:@"tiff"]);

    string = @".scratch.tiff";
    ASSERT_TRUE([string.pathExtension isEqualToString:@"tiff"]);

    string = @"/tmp/scratch";
    ASSERT_TRUE([string.pathExtension isEqualToString:@""]);

    string = @".tiff";
    ASSERT_TRUE([string.pathExtension isEqualToString:@""]);

    string = @".";
    ASSERT_TRUE([string.pathExtension isEqualToString:@""]);

    string = @"foo.";
    ASSERT_TRUE([string.pathExtension isEqualToString:@""]);

    string = @"/tmp/";
    ASSERT_TRUE([string.pathExtension isEqualToString:@""]);

    string = @"/tmp/scratch..tiff";
    ASSERT_TRUE([string.pathExtension isEqualToString:@"tiff"]);

    string = @"/tmp/random.foo.tiff";
    ASSERT_TRUE([string.pathExtension isEqualToString:@"tiff"]);
}

TEST(NSString, Exceptions) {
    NSRange range{ 100, 10 };

    EXPECT_ANY_THROW([@"hello" characterAtIndex:10]);

    unichar buffer[1024];
    EXPECT_ANY_THROW([@"hello" getCharacters:&buffer[0] range:range]);

    EXPECT_ANY_THROW([[[@"hello" mutableCopy] autorelease] replaceCharactersInRange:range withString:@"boom"]);

    EXPECT_ANY_THROW([(NSMutableString*)@"hello" replaceCharactersInRange:range withString:@"boom"]);

    NSString* immutableFormattedString = [NSString stringWithFormat:@"Hello %p", buffer];
    EXPECT_ANY_THROW([(NSMutableString*)immutableFormattedString replaceCharactersInRange:range withString:@"boom"]);
}

class StringsFormatPropertyList : public ::testing::TestWithParam<const wchar_t*> {};

TEST_P(StringsFormatPropertyList, CanDeserialize) {
    const wchar_t* data = GetParam();
    NSString* string = [NSString stringWithCharacters:(const unichar*)data length:wcslen(data)];

    ASSERT_OBJCNE(nil, string);

    NSDictionary* propertyList = [string propertyListFromStringsFileFormat];

    ASSERT_OBJCNE(nil, propertyList);

    ASSERT_OBJCEQ(@"value1", propertyList[@"key1"]);
    ASSERT_OBJCEQ(@"value2", propertyList[@"key2"]);
}

INSTANTIATE_TEST_CASE_P(NSString,
                        StringsFormatPropertyList,
                        ::testing::Values(L"\uFEFFkey1=value1;\n\"key2\"=\"value2\";", // BOM
                                          L"key1=value1;\n\"key2\"=\"value2\";" // No BOM
                                          ));