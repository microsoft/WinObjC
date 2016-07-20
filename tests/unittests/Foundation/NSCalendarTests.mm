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

#import <Foundation/Foundation.h>
#import <TestFramework.h>

TEST(NSCalendar, GetDates) {
    // Test enumeration block, block expects to find 50 dates referencing the leap year dates, Feb, 29th every ~4years
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];

    __block NSDateFormatter* dateFormatter = [[[NSDateFormatter alloc] init] autorelease];
    dateFormatter.dateStyle = NSDateFormatterMediumStyle;
    dateFormatter.timeStyle = NSDateFormatterMediumStyle;
    dateFormatter.locale = [NSLocale localeWithLocaleIdentifier:@"en_US"];

    NSDateComponents* leapYearComponents = [[[NSDateComponents alloc] init] autorelease];
    leapYearComponents.month = 2;
    leapYearComponents.day = 29;

    __block int dateCount = 0;

    // Find all leap days going forwards
    [calendar enumerateDatesStartingAfterDate:[NSDate dateWithTimeIntervalSinceReferenceDate:0]
                           matchingComponents:leapYearComponents
                                      options:NSCalendarMatchStrictly
                                   usingBlock:^(NSDate* date, BOOL exactMatch, BOOL* stop) {
                                       NSString* result = [dateFormatter stringFromDate:date];
                                       ASSERT_OBJCEQ([result substringWithRange:NSMakeRange(0, 6)], @"Feb 29");
                                       if (++dateCount == 50) {
                                           *stop = YES;
                                       }
                                   }];

    // Find all leap days going backwards
    dateCount = 0;
    [calendar enumerateDatesStartingAfterDate:[NSDate dateWithTimeIntervalSinceReferenceDate:0]
                           matchingComponents:leapYearComponents
                                      options:NSCalendarSearchBackwards
                                   usingBlock:^(NSDate* date, BOOL exactMatch, BOOL* stop) {
                                       NSString* result = [dateFormatter stringFromDate:date];
                                       ASSERT_OBJCEQ([result substringWithRange:NSMakeRange(0, 6)], @"Feb 29");
                                       if (++dateCount == 50) {
                                           *stop = YES;
                                       }
                                   }];

    // Find all mondays after a certain date
    NSDateComponents* mondayComponents = [[[NSDateComponents alloc] init] autorelease];
    mondayComponents.weekday = 2;
    dateFormatter.dateStyle = NSDateFormatterFullStyle;

    dateCount = 0;
    [calendar enumerateDatesStartingAfterDate:[NSDate dateWithTimeIntervalSinceReferenceDate:0]
                           matchingComponents:mondayComponents
                                      options:NSCalendarMatchStrictly
                                   usingBlock:^(NSDate* date, BOOL exactMatch, BOOL* stop) {
                                       NSString* result = [dateFormatter stringFromDate:date];
                                       ASSERT_OBJCEQ([result substringWithRange:NSMakeRange(0, 6)], @"Monday");
                                       if (++dateCount == 50) {
                                           *stop = YES;
                                       }
                                   }];

    // Try to enumerate to a time before the 2001 epoch while still searching forward.
    NSDateComponents* olderDateComponents = [[[NSDateComponents alloc] init] autorelease];
    olderDateComponents.year = 1999;
    [calendar enumerateDatesStartingAfterDate:[NSDate dateWithTimeIntervalSinceReferenceDate:0]
                           matchingComponents:olderDateComponents
                                      options:NSCalendarMatchStrictly
                                   usingBlock:^(NSDate* date, BOOL exactMatch, BOOL* stop) {
                                       *stop = YES;
                                       ASSERT_EQ_MSG(YES, NO, @"Block should not be called when enumerating to an invalid match component");
                                   }];
}

TEST(NSCalendar, DateBySettingUnit) {
    // Test for NSDateComponent manipulation

    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
    // January 1st, 2010, 00:00:00
    NSDate* constantDate = [calendar dateWithEra:1 year:2010 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];

    // Supposed to be January 1st, 2018, 00:00:00
    NSDate* date = [calendar dateBySettingUnit:NSCalendarUnitYear value:2018 ofDate:constantDate options:0];

    // January 1st, 2018, 00:00:00
    NSDate* correctDate = [calendar dateWithEra:1 year:2018 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(correctDate, date);

    // January 1st, 2018, 03:45:10
    correctDate = [calendar dateWithEra:1 year:2018 month:1 day:1 hour:3 minute:45 second:10 nanosecond:0];

    date = [calendar dateBySettingHour:3 minute:45 second:10 ofDate:date options:0];

    ASSERT_OBJCEQ(correctDate, date);
}

TEST(NSCalendar, GetWeekends) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
    NSDate* weekendStart = [[[NSDate alloc] initWithTimeIntervalSinceReferenceDate:0] autorelease];
    // Jan 1st, 2010, 00:00:00, which is a friday
    NSDate* constantDate = [calendar dateWithEra:1 year:2010 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];

    // The starting weekend day, Jan 2nd, 2010
    NSDate* correctDate = [calendar dateWithEra:1 year:2010 month:1 day:2 hour:0 minute:0 second:0 nanosecond:0];
    NSTimeInterval tip;

    BOOL success = [calendar nextWeekendStartDate:&weekendStart interval:&tip options:0 afterDate:constantDate];
    ASSERT_EQ(success, YES);
    ASSERT_OBJCEQ(correctDate, weekendStart);
    ASSERT_TRUE([calendar isDateInWeekend:weekendStart]);
    ASSERT_EQ(tip, 172800);

    NSDate* datep = nil;
    tip = 0;

    // Approximately one day into the weekend that was found earlier
    NSDate* midWeekend = [weekendStart dateByAddingTimeInterval:86400];
    [calendar rangeOfWeekendStartDate:&datep interval:&tip containingDate:midWeekend];

    ASSERT_OBJCEQ(weekendStart, datep);
}

TEST(NSCalendar, GetNextDate) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];

    // January 1st 2010
    NSDate* constantDate = [calendar dateWithEra:1 year:2010 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];
    // January 2nd 2010
    NSDate* expectedNextDay = [calendar dateWithEra:1 year:2010 month:1 day:2 hour:0 minute:0 second:0 nanosecond:0];

    NSDateComponents* comps = [[NSDateComponents alloc] init];
    comps.day = 2;
    NSDate* date = [calendar nextDateAfterDate:constantDate matchingComponents:comps options:NSCalendarMatchNextTime];

    ASSERT_OBJCEQ(expectedNextDay, date);

    // February 1st 2010
    expectedNextDay = [calendar dateWithEra:1 year:2010 month:2 day:1 hour:0 minute:0 second:0 nanosecond:0];

    comps = [[NSDateComponents alloc] init];
    comps.month = 2;

    date = [calendar nextDateAfterDate:constantDate matchingComponents:comps options:NSCalendarMatchNextTime];

    ASSERT_OBJCEQ(expectedNextDay, date);

    comps.day = 30;
    ASSERT_EQ([comps isValidDateInCalendar:calendar], NO);
    ASSERT_EQ(comps.validDate, NO);
    comps.calendar = calendar;
    ASSERT_EQ(comps.validDate, NO);
    comps.day = 20;

    ASSERT_EQ([comps isValidDateInCalendar:calendar], YES);
    ASSERT_EQ(comps.validDate, YES);

    // February 20th 2001, 7:34:29
    constantDate = [calendar dateWithEra:1 year:2001 month:2 day:20 hour:7 minute:34 second:29 nanosecond:0];
    NSDateComponents* comps2 = [[[NSDateComponents alloc] init] autorelease];
    comps2.day = 31;
    date = constantDate;

    // 30 seconds past the epoch, seconds should be dropped in result
    constantDate = [calendar dateWithEra:1 year:2001 month:1 day:1 hour:0 minute:0 second:30 nanosecond:0];
    comps2 = [[[NSDateComponents alloc] init] autorelease];
    comps2.minute = 45;
    NSDate* nextDate = [calendar dateWithEra:1 year:2001 month:1 day:1 hour:0 minute:45 second:0 nanosecond:0];
    date = [calendar nextDateAfterDate:constantDate matchingComponents:comps2 options:NSCalendarMatchNextTime];

    ASSERT_OBJCEQ(nextDate, date);
}

TEST(NSCalendar, CompareDates) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];

    // January 1st 2010
    NSDate* date1 = [calendar dateWithEra:1 year:2010 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];
    // January 2nd 2010
    NSDate* date2 = [calendar dateWithEra:1 year:2010 month:1 day:2 hour:0 minute:0 second:0 nanosecond:0];
    ASSERT_TRUE([calendar isDateInWeekend:date2]);

    ASSERT_EQ([calendar compareDate:date1 toDate:date2 toUnitGranularity:NSCalendarUnitDay], NSOrderedAscending);

    // February 1st, 2010
    date2 = [calendar dateWithEra:1 year:2010 month:2 day:1 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_EQ([calendar compareDate:date1 toDate:date2 toUnitGranularity:NSCalendarUnitMonth], NSOrderedAscending);

    NSDateComponents* oneDay = [[[NSDateComponents alloc] init] autorelease];
    oneDay.day = -1;
    NSDate* yesterday = [calendar dateByAddingComponents:oneDay toDate:[NSDate date] options:0];
    ASSERT_TRUE([calendar isDateInYesterday:yesterday]);

    oneDay.day = 1;
    NSDate* tomorrow = [calendar dateByAddingComponents:oneDay toDate:[NSDate date] options:0];
    ASSERT_TRUE([calendar isDateInTomorrow:tomorrow]);

    ASSERT_TRUE([calendar isDateInToday:[NSDate date]]);

    // 1 second before January 2nd 2010. (January 1st, 2010, 23:59:59)
    date2 = [calendar dateWithEra:1 year:2010 month:1 day:1 hour:23 minute:59 second:59 nanosecond:0];
    ASSERT_TRUE([calendar isDate:date1 inSameDayAsDate:date2]);

    // January 7th, 2010. Thursday. January 1st being a friday.
    date2 = [calendar dateWithEra:1 year:2010 month:1 day:7 hour:0 minute:0 second:0 nanosecond:0];

    // January 7th is in the second week of January, ascending from the 1st week.
    ASSERT_EQ([calendar compareDate:date1 toDate:date2 toUnitGranularity:NSCalendarUnitWeekOfMonth], NSOrderedAscending);
    ASSERT_EQ([calendar compareDate:date2 toDate:date1 toUnitGranularity:NSCalendarUnitWeekOfMonth], NSOrderedDescending);

    // January 6th 2010 is a wednesday.
    date1 = [calendar dateWithEra:1 year:2010 month:1 day:6 hour:0 minute:0 second:0 nanosecond:0];

    // Wednesday is before Thursday, descending order
    ASSERT_EQ([calendar compareDate:date1 toDate:date2 toUnitGranularity:NSCalendarUnitWeekday], NSOrderedAscending);
    ASSERT_EQ([calendar compareDate:date2 toDate:date1 toUnitGranularity:NSCalendarUnitWeekday], NSOrderedDescending);

    date1 = [NSDate dateWithTimeIntervalSinceReferenceDate:1.5];
    date2 = [NSDate dateWithTimeIntervalSinceReferenceDate:2.5];
    ASSERT_EQ([calendar compareDate:date1 toDate:date2 toUnitGranularity:NSCalendarUnitNanosecond], NSOrderedAscending);
    ASSERT_EQ([calendar compareDate:date2 toDate:date1 toUnitGranularity:NSCalendarUnitNanosecond], NSOrderedDescending);

    date1 = [NSDate dateWithTimeIntervalSinceReferenceDate:.1];
    date2 = [NSDate dateWithTimeIntervalSinceReferenceDate:.9];
    ASSERT_EQ([calendar compareDate:date1 toDate:date2 toUnitGranularity:NSCalendarUnitNanosecond], NSOrderedAscending);
    ASSERT_EQ([calendar compareDate:date2 toDate:date1 toUnitGranularity:NSCalendarUnitNanosecond], NSOrderedDescending);

    date2 = [NSDate dateWithTimeIntervalSinceReferenceDate:.1];
    ASSERT_EQ([calendar compareDate:date2 toDate:date1 toUnitGranularity:NSCalendarUnitNanosecond], NSOrderedSame);

    date1 = [NSDate dateWithTimeIntervalSinceReferenceDate:1];
    date2 = [NSDate dateWithTimeIntervalSinceReferenceDate:2];
    ASSERT_EQ([calendar compareDate:date1 toDate:date2 toUnitGranularity:NSCalendarUnitSecond], NSOrderedAscending);
    ASSERT_EQ([calendar compareDate:date2 toDate:date1 toUnitGranularity:NSCalendarUnitSecond], NSOrderedDescending);
    ASSERT_EQ([calendar compareDate:date1 toDate:date2 toUnitGranularity:NSCalendarUnitMinute], NSOrderedSame);
    ASSERT_EQ([calendar compareDate:date2 toDate:date1 toUnitGranularity:NSCalendarUnitMinute], NSOrderedSame);
}

TEST(NSCalendar, UnitComparison) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];

    // January 1st 2010
    NSDate* date1 = [calendar dateWithEra:1 year:2010 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];

    // February 17th 2010
    NSDate* date2 = [calendar dateWithEra:1 year:2010 month:2 day:17 hour:0 minute:0 second:0 nanosecond:0];

    NSCalendarUnit unitFlags = NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitYear;

    NSDateComponents* difference = [calendar components:unitFlags fromDate:date1 toDate:date2 options:0];

    ASSERT_EQ(difference.day, 16);
    ASSERT_EQ(difference.month, 1);

    date2 = [calendar dateWithEra:1 year:2016 month:11 day:25 hour:0 minute:0 second:0 nanosecond:0];

    difference = [calendar components:unitFlags fromDate:date1 toDate:date2 options:0];

    ASSERT_EQ(difference.day, 24);
    ASSERT_EQ(difference.month, 10);
    ASSERT_EQ(difference.year, 6);
}

TEST(NSCalendar, ArchivingUnarchiving) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];

    // Repeat an old test before and after archiving
    // January 1st 2010
    NSDate* date1 = [calendar dateWithEra:1 year:2010 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];

    NSDate* date2 = [calendar dateWithEra:1 year:2010 month:2 day:1 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_EQ([calendar compareDate:date1 toDate:date2 toUnitGranularity:NSCalendarUnitMonth], NSOrderedAscending);

    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:calendar];

    NSCalendar* calendarUnarchived = [NSKeyedUnarchiver unarchiveObjectWithData:data];

    ASSERT_EQ([calendarUnarchived compareDate:date1 toDate:date2 toUnitGranularity:NSCalendarUnitMonth], NSOrderedAscending);
}

TEST(NSCalendar, PreserveSmallerUnitsMatching) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];

    // 20th of February 2010
    NSDate* date = [calendar dateWithEra:1 year:2010 month:2 day:20 hour:3 minute:4 second:5 nanosecond:0];

    NSDateComponents* components = [[[NSDateComponents alloc] init] autorelease];
    components.day = 31;

    // Should be March 31st
    NSDate* actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchStrictly];
    NSDate* expectedDate = [calendar dateWithEra:1 year:2010 month:3 day:31 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    // Should be March 1st
    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchNextTime];
    expectedDate = [calendar dateWithEra:1 year:2010 month:3 day:1 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    // Should be March 1st with smaller units in tact
    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchNextTimePreservingSmallerUnits];
    expectedDate = [calendar dateWithEra:1 year:2010 month:3 day:1 hour:3 minute:4 second:5 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    // Should be Feb 28th with smaller units in tact
    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchPreviousTimePreservingSmallerUnits];
    expectedDate = [calendar dateWithEra:1 year:2010 month:2 day:28 hour:3 minute:4 second:5 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    date = [calendar dateWithEra:1 year:2012 month:2 day:20 hour:3 minute:4 second:5 nanosecond:0];
    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchPreviousTimePreservingSmallerUnits];
    expectedDate = [calendar dateWithEra:1 year:2012 month:2 day:29 hour:3 minute:4 second:5 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchNextTimePreservingSmallerUnits];
    expectedDate = [calendar dateWithEra:1 year:2012 month:3 day:1 hour:3 minute:4 second:5 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    components.day = 29;
    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchNextTimePreservingSmallerUnits];
    expectedDate = [calendar dateWithEra:1 year:2012 month:2 day:29 hour:3 minute:4 second:5 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    date = [calendar dateWithEra:1 year:1999 month:5 day:1 hour:0 minute:0 second:0 nanosecond:0];
    components.day = 1;
    components.month = 5;
    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchNextTimePreservingSmallerUnits];
    expectedDate = [calendar dateWithEra:1 year:2000 month:5 day:1 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    date = [calendar dateWithEra:1 year:2000 month:5 day:1 hour:0 minute:0 second:0 nanosecond:0];
    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchNextTimePreservingSmallerUnits];
    expectedDate = [calendar dateWithEra:1 year:2001 month:5 day:1 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);
}

TEST(NSCalendar, weekOfUnitMatching) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];

    // Test week of year enumeration.
    NSDateComponents* components = [[[NSDateComponents alloc] init] autorelease];
    components.weekOfYear = 3;
    components.weekday = 2;
    components.hour = 5;

    NSDate* date = [calendar dateWithEra:1 year:2000 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];
    NSDate* actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchStrictly];

    NSDate* expectedDate = [calendar dateWithEra:1 year:2000 month:1 day:10 hour:5 minute:0 second:0 nanosecond:0];
    ASSERT_OBJCEQ(expectedDate, actualDate);

    actualDate = [calendar nextDateAfterDate:expectedDate matchingComponents:components options:NSCalendarMatchStrictly];
    expectedDate = [calendar dateWithEra:1 year:2001 month:1 day:15 hour:5 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    components = [[[NSDateComponents alloc] init] autorelease];
    components.day = 29;
    components.month = 2;

    date = [calendar dateWithEra:1 year:2004 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];
    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchNextTime];
    expectedDate = [calendar dateWithEra:1 year:2004 month:2 day:29 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    // Match next time should resolve to March 1st as Febuary 29th, 2005 does not exist.
    actualDate = [calendar nextDateAfterDate:expectedDate matchingComponents:components options:NSCalendarMatchNextTime];
    expectedDate = [calendar dateWithEra:1 year:2005 month:3 day:1 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    components = [[[NSDateComponents alloc] init] autorelease];
    components.weekOfYear = 6;

    date = [calendar dateWithEra:1 year:2000 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];
    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchStrictly];
    expectedDate = [calendar dateWithEra:1 year:2000 month:2 day:5 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    actualDate = [calendar nextDateAfterDate:expectedDate matchingComponents:components options:NSCalendarMatchStrictly];
    expectedDate = [calendar dateWithEra:1 year:2001 month:2 day:10 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    components = [[[NSDateComponents alloc] init] autorelease];
    components.weekOfMonth = 6;

    date = [calendar dateWithEra:1 year:2000 month:1 day:1 hour:0 minute:0 second:0 nanosecond:0];
    actualDate = [calendar nextDateAfterDate:date matchingComponents:components options:NSCalendarMatchStrictly];
    expectedDate = [calendar dateWithEra:1 year:2000 month:1 day:30 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    actualDate = [calendar nextDateAfterDate:expectedDate matchingComponents:components options:NSCalendarMatchStrictly];
    expectedDate = [calendar dateWithEra:1 year:2000 month:4 day:30 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);

    components.weekday = 2;

    actualDate = [calendar nextDateAfterDate:expectedDate matchingComponents:components options:NSCalendarMatchStrictly];
    expectedDate = [calendar dateWithEra:1 year:2000 month:7 day:31 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, actualDate);
}

TEST(NSCalendar, GetComponents) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];

    NSCalendarUnit unitFlags = NSCalendarUnitDay | NSCalendarUnitHour | NSCalendarUnitMinute;

    NSDate* date = [calendar dateWithEra:1 year:2000 month:5 day:1 hour:10 minute:0 second:30 nanosecond:0];

    NSDateComponents* components = [calendar components:unitFlags fromDate:date];

    // Only units that were requested
    ASSERT_EQ(components.day, 1);
    ASSERT_EQ(components.hour, 10);
    ASSERT_EQ(components.minute, 0);

    // Units that were not requested should be undefined.
    ASSERT_EQ(components.era, NSUndefinedDateComponent);
    ASSERT_EQ(components.year, NSUndefinedDateComponent);
    ASSERT_EQ(components.month, NSUndefinedDateComponent);
    ASSERT_EQ(components.second, NSUndefinedDateComponent);
    ASSERT_EQ(components.nanosecond, NSUndefinedDateComponent);
    ASSERT_EQ(components.week, NSUndefinedDateComponent);
    ASSERT_EQ(components.weekday, NSUndefinedDateComponent);
    ASSERT_EQ(components.weekdayOrdinal, NSUndefinedDateComponent);
    ASSERT_EQ(components.quarter, NSUndefinedDateComponent);
    ASSERT_EQ(components.weekOfMonth, NSUndefinedDateComponent);
    ASSERT_EQ(components.weekOfYear, NSUndefinedDateComponent);
    ASSERT_EQ(components.yearForWeekOfYear, NSUndefinedDateComponent);
}

TEST(NSCalendar, DeprecatedWeekTests) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
    NSDateComponents* components = [[[NSDateComponents alloc] init] autorelease];
    components.year = 2000;
    components.week = 3;

    NSDate* date = [calendar dateFromComponents:components];

    NSDate* expectedDate = [calendar dateWithEra:1 year:2000 month:1 day:9 hour:0 minute:0 second:0 nanosecond:0];

    ASSERT_OBJCEQ(expectedDate, date);

    NSDateComponents* weekComponents = [calendar components:NSWeekCalendarUnit fromDate:date];

    ASSERT_EQ(3, weekComponents.week);
}

TEST(NSCalendar, NSRangeValidation) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
    NSDate* expectedDate = [calendar dateWithEra:1 year:2010 month:3 day:31 hour:0 minute:0 second:0 nanosecond:0];

    NSRange range = [calendar rangeOfUnit:NSCalendarUnitWeekOfMonth inUnit:NSCalendarUnitYear forDate:expectedDate];
    ASSERT_EQ(range.location, 1);
    ASSERT_EQ(range.length, 5);

    range = [calendar rangeOfUnit:NSCalendarUnitWeekOfYear inUnit:NSCalendarUnitMonth forDate:expectedDate];
    ASSERT_EQ(range.location, 10);
    ASSERT_EQ(range.length, 5);

    range = [calendar rangeOfUnit:NSCalendarUnitHour inUnit:NSCalendarUnitWeekOfMonth forDate:expectedDate];
    ASSERT_EQ(range.location, 0);
    ASSERT_EQ(range.length, 24);
}