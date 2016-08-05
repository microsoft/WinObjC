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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#import <Foundation/Foundation.h>
#import <TestFramework.h>
#import <windows.h>

// Windows NSTimeZone is based on ICU
#if TARGET_OS_WIN32
#import <unicode/timezone.h>
#endif

TEST(NSTimeZone, Abbreviation) {
    auto tz = [NSTimeZone systemTimeZone];
    auto abbreviation1 = tz.abbreviation;
    auto abbreviation2 = [tz abbreviationForDate:[NSDate date]];
    ASSERT_OBJCEQ_MSG(abbreviation1, abbreviation2, @"%@ should be equal to %@", abbreviation1, abbreviation2);
}

TEST(NSTimeZone, InitializingTimeZoneWithOffset) {
    NSTimeZone* tz = [NSTimeZone timeZoneWithName:@"GMT-0400"];
    ASSERT_OBJCNE(nil, tz);
    auto seconds = [tz secondsFromGMTForDate:[NSDate date]];
    ASSERT_EQ_MSG(seconds, -14400, @"GMT-0400 should be -14400 seconds but got %d instead", seconds);
}

TEST(NSTimeZone, InitializingTimeZoneWithAbbreviation) {
    // Test invalid timezone abbreviation
    NSTimeZone* tz = [NSTimeZone timeZoneWithAbbreviation:@"XXX"];
    ASSERT_OBJCEQ(nil, tz);

    // Test valid timezone abbreviation of "AST" for "America/Halifax"
    tz = [NSTimeZone timeZoneWithAbbreviation:@"AST"];
    auto expectedName = @"America/Halifax";
    ASSERT_OBJCEQ_MSG(tz.name, expectedName, @"expected name \"%@\" is not equal to \"%@\"", expectedName, tz.name);
}

TEST(NSTimeZone, SystemTimeZoneUsesSystemTime) {
// Windows NSTimeZone uses icu, OSX version of this test uses a GNU/BSD only API (struct tm.tm_zone) not available on Windows.
// Because this API is missing on Windows, the Windows path of this test compares against name rather than abbreviation -
// abbreviation is messy to retrieve the value of, and the code would end up identical to the implementation code,
// making the test not very meaningful.
#if TARGET_OS_WIN32
    NSString* zoneName = [[NSTimeZone systemTimeZone] name];

    icu::TimeZone* systemTime = icu::TimeZone::detectHostTimeZone();
    icu::UnicodeString expectedUnicodeName;
    systemTime->getID(expectedUnicodeName);

    NSString* expectedName =
        [NSString stringWithCharacters:(const unichar*)expectedUnicodeName.getBuffer() length:expectedUnicodeName.length()];
#else
    NSString* zoneName = [[NSTimeZone systemTimeZone] abbreviation];

    tzset();
    time_t t = time(nil);
    struct tm lt = tm();
    localtime_r(&t, &lt);

    NSString* expectedName = [NSString stringWithCString:lt.tm_zone encoding:NSASCIIStringEncoding];
#endif

    zoneName = (zoneName == nil) ? @"Invalid Abbreviation" : zoneName;
    expectedName = (expectedName == nil) ? @"Invalid Zone" : expectedName;

    ASSERT_OBJCEQ_MSG(zoneName, expectedName, @"expected name \"%@\" is not equal to \"%@\"", zoneName, expectedName);
}
