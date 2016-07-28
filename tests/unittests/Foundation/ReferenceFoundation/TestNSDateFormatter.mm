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
// Copyright (c) 2014 - 2016 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
#import <Foundation/Foundation.h>
#import <TestFramework.h>

static NSString* DEFAULT_TIMEZONE = @"GMT";
static NSString* DEFAULT_LOCALE = @"en_US";

TEST(NSDateFormatter, BasicConstruction) {
    NSDateFormatter* f = [[NSDateFormatter new] autorelease];
    ASSERT_OBJCNE(nil, f);
}

TEST(NSDateFormatter, CustomDateFormat) {
    NSDateFormatter* dateFormatter = [[NSDateFormatter new] autorelease];
    dateFormatter.dateFormat = @"dd-MM-yyyy";
    auto dateStr = [dateFormatter stringFromDate:[NSDate date]];

    LOG_INFO(@"With dateFormat '%@':  '%@'", dateFormatter.dateFormat, dateStr);
}

// ShortStyle
// locale  stringFromDate  example
// ------  --------------  --------
// en_US   M/d/yy       12/25/15
TEST(NSDateFormatter, DateStyleShort) {
    auto timestamps = @{
        @-31536000 : @"1/1/69, 12:00 AM",
        @0.0 : @"1/1/70, 12:00 AM",
        @31536000 : @"1/1/71, 12:00 AM",
        @2145916800 : @"1/1/38, 12:00 AM",
        @1456272000 : @"2/24/16, 12:00 AM",
        @1456358399 : @"2/24/16, 11:59 PM",
        @1452574638 : @"1/12/16, 4:57 AM",
        @1455685038 : @"2/17/16, 4:57 AM",
        @1458622638 : @"3/22/16, 4:57 AM",
        @1459745838 : @"4/4/16, 4:57 AM",
        @1462597038 : @"5/7/16, 4:57 AM",
        @1465534638 : @"6/10/16, 4:57 AM",
        @1469854638 : @"7/30/16, 4:57 AM",
        @1470718638 : @"8/9/16, 4:57 AM",
        @1473915438 : @"9/15/16, 4:57 AM",
        @1477285038 : @"10/24/16, 4:57 AM",
        @1478062638 : @"11/2/16, 4:57 AM",
        @1482641838 : @"12/25/16, 4:57 AM"
    };

    NSDateFormatter* f = [[NSDateFormatter new] autorelease];
    f.dateStyle = NSDateFormatterShortStyle;
    f.timeStyle = NSDateFormatterShortStyle;

    // ensure tests give consistent results by setting specific timeZone and locale
    f.timeZone = [NSTimeZone timeZoneWithName:DEFAULT_TIMEZONE];
    f.locale = [NSLocale localeWithLocaleIdentifier:DEFAULT_LOCALE];

    for (NSNumber* timestamp in timestamps) {
        NSString* stringResult = [timestamps objectForKey:timestamp];
        NSDate* testDate = [NSDate dateWithTimeIntervalSince1970:timestamp.doubleValue];
        auto sf = [f stringFromDate:testDate];

        ASSERT_OBJCEQ(sf, stringResult);
    }
}

// MediumStyle
// locale  stringFromDate  example
// ------  --------------  ------------
// en_US   MMM d, y       Dec 25, 2015
TEST(NSDateFormatter, DateStyleMedium) {
    auto timestamps = @{
        @-31536000 : @"Jan 1, 1969, 12:00:00 AM",
        @0.0 : @"Jan 1, 1970, 12:00:00 AM",
        @31536000 : @"Jan 1, 1971, 12:00:00 AM",
        @2145916800 : @"Jan 1, 2038, 12:00:00 AM",
        @1456272000 : @"Feb 24, 2016, 12:00:00 AM",
        @1456358399 : @"Feb 24, 2016, 11:59:59 PM",
        @1452574638 : @"Jan 12, 2016, 4:57:18 AM",
        @1455685038 : @"Feb 17, 2016, 4:57:18 AM",
        @1458622638 : @"Mar 22, 2016, 4:57:18 AM",
        @1459745838 : @"Apr 4, 2016, 4:57:18 AM",
        @1462597038 : @"May 7, 2016, 4:57:18 AM",
        @1465534638 : @"Jun 10, 2016, 4:57:18 AM",
        @1469854638 : @"Jul 30, 2016, 4:57:18 AM",
        @1470718638 : @"Aug 9, 2016, 4:57:18 AM",
        @1473915438 : @"Sep 15, 2016, 4:57:18 AM",
        @1477285038 : @"Oct 24, 2016, 4:57:18 AM",
        @1478062638 : @"Nov 2, 2016, 4:57:18 AM",
        @1482641838 : @"Dec 25, 2016, 4:57:18 AM"
    };

    NSDateFormatter* f = [[NSDateFormatter new] autorelease];
    f.dateStyle = NSDateFormatterMediumStyle;
    f.timeStyle = NSDateFormatterMediumStyle;
    f.timeZone = [NSTimeZone timeZoneWithName:DEFAULT_TIMEZONE];
    f.locale = [NSLocale localeWithLocaleIdentifier:DEFAULT_LOCALE];

    for (NSNumber* timestamp in timestamps) {
        NSString* stringResult = [timestamps objectForKey:timestamp];
        NSDate* testDate = [NSDate dateWithTimeIntervalSince1970:timestamp.doubleValue];
        auto sf = [f stringFromDate:testDate];

        ASSERT_OBJCEQ(sf, stringResult);
    }
}

// LongStyle
// locale  stringFromDate  example
// ------  --------------  -----------------
// en_US   MMMM d, y       December 25, 2015
TEST(NSDateFormatter, DateStyleLong) {
    auto timestamps = @{
        @-31536000 : @"January 1, 1969 at 12:00:00 AM GMT",
        @0.0 : @"January 1, 1970 at 12:00:00 AM GMT",
        @31536000 : @"January 1, 1971 at 12:00:00 AM GMT",
        @2145916800 : @"January 1, 2038 at 12:00:00 AM GMT",
        @1456272000 : @"February 24, 2016 at 12:00:00 AM GMT",
        @1456358399 : @"February 24, 2016 at 11:59:59 PM GMT",
        @1452574638 : @"January 12, 2016 at 4:57:18 AM GMT",
        @1455685038 : @"February 17, 2016 at 4:57:18 AM GMT",
        @1458622638 : @"March 22, 2016 at 4:57:18 AM GMT",
        @1459745838 : @"April 4, 2016 at 4:57:18 AM GMT",
        @1462597038 : @"May 7, 2016 at 4:57:18 AM GMT",
        @1465534638 : @"June 10, 2016 at 4:57:18 AM GMT",
        @1469854638 : @"July 30, 2016 at 4:57:18 AM GMT",
        @1470718638 : @"August 9, 2016 at 4:57:18 AM GMT",
        @1473915438 : @"September 15, 2016 at 4:57:18 AM GMT",
        @1477285038 : @"October 24, 2016 at 4:57:18 AM GMT",
        @1478062638 : @"November 2, 2016 at 4:57:18 AM GMT",
        @1482641838 : @"December 25, 2016 at 4:57:18 AM GMT"
    };

    NSDateFormatter* f = [[NSDateFormatter new] autorelease];
    f.dateStyle = NSDateFormatterLongStyle;
    f.timeStyle = NSDateFormatterLongStyle;
    f.timeZone = [NSTimeZone timeZoneWithName:DEFAULT_TIMEZONE];
    f.locale = [NSLocale localeWithLocaleIdentifier:DEFAULT_LOCALE];

    for (NSNumber* timestamp in timestamps) {
        NSString* stringResult = [timestamps objectForKey:timestamp];
        NSDate* testDate = [NSDate dateWithTimeIntervalSince1970:timestamp.doubleValue];
        auto sf = [f stringFromDate:testDate];

        ASSERT_OBJCEQ(sf, stringResult);
    }
}

// FullStyle
// locale  stringFromDate  example
// ------  --------------  -------------------------
// en_US   EEEE, MMMM d, y  Friday, December 25, 2015
TEST(NSDateFormatter, DateStyleFull) {
    auto timestamps = @{
        @-31536000 : @"Wednesday, January 1, 1969 at 12:00:00 AM GMT",
        @0.0 : @"Thursday, January 1, 1970 at 12:00:00 AM GMT",
        @31536000 : @"Friday, January 1, 1971 at 12:00:00 AM GMT",
        @2145916800 : @"Friday, January 1, 2038 at 12:00:00 AM GMT",
        @1456272000 : @"Wednesday, February 24, 2016 at 12:00:00 AM GMT",
        @1456358399 : @"Wednesday, February 24, 2016 at 11:59:59 PM GMT",
        @1452574638 : @"Tuesday, January 12, 2016 at 4:57:18 AM GMT",
        @1455685038 : @"Wednesday, February 17, 2016 at 4:57:18 AM GMT",
        @1458622638 : @"Tuesday, March 22, 2016 at 4:57:18 AM GMT",
        @1459745838 : @"Monday, April 4, 2016 at 4:57:18 AM GMT",
        @1462597038 : @"Saturday, May 7, 2016 at 4:57:18 AM GMT",
        @1465534638 : @"Friday, June 10, 2016 at 4:57:18 AM GMT",
        @1469854638 : @"Saturday, July 30, 2016 at 4:57:18 AM GMT",
        @1470718638 : @"Tuesday, August 9, 2016 at 4:57:18 AM GMT",
        @1473915438 : @"Thursday, September 15, 2016 at 4:57:18 AM GMT",
        @1477285038 : @"Monday, October 24, 2016 at 4:57:18 AM GMT",
        @1478062638 : @"Wednesday, November 2, 2016 at 4:57:18 AM GMT",
        @1482641838 : @"Sunday, December 25, 2016 at 4:57:18 AM GMT"
    };

    NSDateFormatter* f = [[NSDateFormatter new] autorelease];
    f.dateStyle = NSDateFormatterFullStyle;
    f.timeStyle = NSDateFormatterFullStyle;
    f.timeZone = [NSTimeZone timeZoneWithName:DEFAULT_TIMEZONE];
    f.locale = [NSLocale localeWithLocaleIdentifier:DEFAULT_LOCALE];

    for (NSNumber* timestamp in timestamps) {
        NSString* stringResult = [timestamps objectForKey:timestamp];
        NSDate* testDate = [NSDate dateWithTimeIntervalSince1970:timestamp.doubleValue];
        auto sf = [f stringFromDate:testDate];

        ASSERT_OBJCEQ(sf, stringResult);
    }
}
