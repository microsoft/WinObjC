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

#import <CoreFoundation/CoreFoundation.h>

TEST(NSCalendar, GettingDatesOnGregorianCalendar) {
    NSDate* date = [NSDate dateWithTimeIntervalSince1970:1449332351];

    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierGregorian];
    calendar.timeZone = [NSTimeZone timeZoneWithName:@"UTC"];

    NSDateComponents* components = [calendar components:(NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay) fromDate:date];
    ASSERT_TRUE_MSG(components != nil, @"Could not get date from the calendar");
    ASSERT_EQ(components.year, 2015);
    ASSERT_EQ(components.month, 12);
    ASSERT_EQ(components.day, 5);
}

TEST(NSCalendar, GettingDatesOnHebrewCalendar) {
    NSDate* date = [NSDate dateWithTimeIntervalSince1970:1552580351];

    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierHebrew];
    calendar.timeZone = [NSTimeZone timeZoneWithName:@"UTC"];
    NSDateComponents* components = [calendar components:(NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay) fromDate:date];
    ASSERT_TRUE_MSG(components != nil, @"Could not get date from the calendar");
    ASSERT_EQ(components.year, 5779);
    ASSERT_EQ(components.month, 7);
    ASSERT_EQ(components.day, 7);
    ASSERT_FALSE(components.leapMonth);
}

TEST(NSCalendar, GettingDatesOnChineseCalendar) {
    NSDate* date = [NSDate dateWithTimeIntervalSince1970:1591460351.0];

    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:NSCalendarIdentifierChinese];
    calendar.timeZone = [NSTimeZone timeZoneWithName:@"UTC"];
    NSDateComponents* components = [calendar components:(NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay) fromDate:date];
    ASSERT_TRUE_MSG(components != nil, @"Could not get date from the calendar");
    ASSERT_EQ(components.year, 37);
    ASSERT_EQ(components.month, 4);
    ASSERT_EQ(components.day, 15);
    ASSERT_TRUE(components.leapMonth);
}

TEST(NSCalendar, InitializingWithInvalidIdentifier) {
    NSCalendar* calendar = [NSCalendar calendarWithIdentifier:@"nonexistant_calendar"];
    ASSERT_OBJCEQ(calendar, nil);
}

TEST(NSCalendar, CurrentCalendarRRstability) {
    NSMutableArray* AMSymbols = [NSMutableArray array];
    for (int i = 0; i < 10; i++) {
        NSCalendar* cal = [NSCalendar currentCalendar];
        [AMSymbols addObject:[cal AMSymbol]];
    }

    ASSERT_EQ_MSG(AMSymbols.count, 10, @"Accessing current calendar should work over multiple callouts");
}
