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

// keys: [[NSLocale localeIdentifier] stringByAppendingFormat:@"%d", timezone.secondsFromGMT]
// eg "en_US-28800" or "en_GB0"
static NSDictionary* supportedTestCases;

static NSString* defaultTestCase = @"en_GB0";
static NSString* appendNumber = @"%d";

// Add supported time zones here
static const int c_westernTimeZoneOffset = -28800;
static const int c_GMTTimeZoneOffset = 0;

void testSpecificFormat(int formatterStyle, NSString* formatted, NSString* testCaseKey) {
    NSArray* expectedValues = [supportedTestCases objectForKey:testCaseKey];
    ASSERT_OBJCEQ([expectedValues objectAtIndex:(int)formatterStyle], formatted);
}

bool isSupportedLocaleAndTimeZone(NSLocale* locale, NSTimeZone* timezone) {
    // Create any expected test cases here, must be in the order of NoStyle to FullStyle
    NSArray* expectedValuesWesternUS = @[
        @"",
        @"1/1/70 12:00 AM",
        @"Jan 1, 1970 12:00:00 AM",
        @"January 1, 1970 12:00:00 AM PST",
        @"Thursday, January 1, 1970 12:00:00 AM Pacific Standard Time"
    ];

    NSArray* expectedValuesGMT =
        @[ @"", @"01/01/1970 00:00", @"1 Jan 1970 00:00:00", @"1 January 1970 00:00:00 GMT", @"Thursday, 1 January 1970 00:00:00 GMT" ];

    supportedTestCases = @{
        [@"en_US" stringByAppendingFormat:appendNumber, c_westernTimeZoneOffset] : expectedValuesWesternUS,
        [@"en_GB" stringByAppendingFormat:appendNumber, c_GMTTimeZoneOffset] : expectedValuesGMT
    };

    // If the requested time zone and locale are supported then run the test for that locale.
    bool supportedTestCase = [supportedTestCases.allKeys
        containsObject:[[locale localeIdentifier] stringByAppendingFormat:appendNumber, [timezone secondsFromGMT]]];

    return supportedTestCase;
}

TEST(Foundation, NSDateFormatter) {
    NSLocale* currentLocale = [NSLocale currentLocale];
    NSTimeZone* systemTimeZone = [NSTimeZone systemTimeZone];

    NSLocale* localeToTest;
    NSTimeZone* timeZoneToTest;
    NSString* testCase;

    if (isSupportedLocaleAndTimeZone(currentLocale, systemTimeZone)) {
        localeToTest = currentLocale;
        timeZoneToTest = systemTimeZone;
        testCase = [[currentLocale localeIdentifier] stringByAppendingFormat:appendNumber, systemTimeZone.secondsFromGMT];
    } else {
        NSLog(@"System locale unverified. Running test with GMT's expected values.");
        localeToTest = [NSLocale localeWithLocaleIdentifier:@"en_GB"];
        timeZoneToTest = [NSTimeZone timeZoneWithName:@"GMT"];
        testCase = defaultTestCase;
    }

    // Need to offset the expected constant date by our system time offset.
    // A constant date should be used. 1970-01-01 00:00:00 +0000, This should never change.
    NSDate* someConstantDate = [NSDate dateWithTimeIntervalSince1970:(-1 * [timeZoneToTest secondsFromGMT])];

    NSString* formattedDateString;
    for (int i = 0; i < 5; i++) {
        formattedDateString = [NSDateFormatter _formatDateForLocale:someConstantDate
                                                             locale:localeToTest
                                                          dateStyle:((NSDateFormatterStyle)i)
                                                          timeStyle:((NSDateFormatterStyle)i)
                                                           timeZone:timeZoneToTest];

        testSpecificFormat(i, formattedDateString, testCase);
    }

    // Try some simple formatting
    NSDateFormatter* dateFormatter = [[[NSDateFormatter alloc] init] autorelease];

    // Create an NSDate from string with dateFormatter
    [dateFormatter setDateFormat:@"yyyy-MM-dd"];
    NSDate* date = [dateFormatter dateFromString:@"2009-03-18"];

    // Create an NSString from NSDate with new format
    [dateFormatter setDateFormat:@"dd-MM-yyyy"];
    NSString* strMyDate = [dateFormatter stringFromDate:date];

    ASSERT_OBJCEQ(@"18-03-2009", strMyDate);
}