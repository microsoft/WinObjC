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

#include "TestFramework.h"
#import <Foundation/Foundation.h>

TEST(NSDateComponents, ComponentsTimeZoneTest) {
    LOG_INFO("NSDateComponents components with time zone test: ");

    NSTimeZone* estTimeZone = [NSTimeZone timeZoneWithName:@"EST"];
    NSTimeZone* cstTimeZone = [NSTimeZone timeZoneWithName:@"CST"];

    NSDateComponents* dateComponents = [[NSDateComponents alloc] init];
    [dateComponents setHour:1];
    [dateComponents setDay:1];
    [dateComponents setMonth:4];
    [dateComponents setYear:1999];

    [dateComponents setTimeZone:estTimeZone];
    NSDate* estDate = [[NSCalendar currentCalendar] dateFromComponents:dateComponents];

    [dateComponents setTimeZone:cstTimeZone];
    NSDate* cstDateNonMatching = [[NSCalendar currentCalendar] dateFromComponents:dateComponents];

    [dateComponents setHour:0];
    NSDate* cstDateMatching = [[NSCalendar currentCalendar] dateFromComponents:dateComponents];

    NSTimeInterval secondsBetween = [cstDateNonMatching timeIntervalSinceDate:estDate];

    EXPECT_OBJCEQ_MSG(estDate, cstDateMatching, "FAILED: dates should match");
    EXPECT_OBJCNE_MSG(cstDateNonMatching, cstDateMatching, "FAILED: dates should differ by one hour");
    EXPECT_OBJCNE_MSG(estDate, cstDateNonMatching, "FAILED: dates should differ by one hour");
    EXPECT_EQ_MSG(secondsBetween, 3600, "FAILED: dates should differ by one hour");
    [dateComponents release];
}

TEST(NSDateComponents, CalendarTimeZoneTest) {
    LOG_INFO("NSDateComponents calendar with time zone test: ");

    NSTimeZone* estTimeZone = [NSTimeZone timeZoneWithName:@"EST"];
    NSTimeZone* cstTimeZone = [NSTimeZone timeZoneWithName:@"CST"];

    NSDateComponents* dateComponents = [[NSDateComponents alloc] init];
    [dateComponents setHour:0];
    [dateComponents setDay:1];
    [dateComponents setMonth:4];
    [dateComponents setYear:1999];

    NSCalendar* calendar = [NSCalendar currentCalendar];

    [calendar setTimeZone:estTimeZone];
    NSDate* estDate = [calendar dateFromComponents:dateComponents];

    [dateComponents setTimeZone:cstTimeZone];
    NSDate* cstDate = [calendar dateFromComponents:dateComponents];

    NSTimeInterval secondsBetween = [cstDate timeIntervalSinceDate:estDate];
    EXPECT_EQ_MSG(secondsBetween, 3600, "FAILED: dates should differ by one hour");
    [dateComponents release];
}

TEST(NSDateComponents, IndependentWeekTest) {
    NSDateComponents* dateComponents = [[NSDateComponents alloc] init];
    dateComponents.day = 1;
    dateComponents.month = 1;
    dateComponents.year = 1999;
    EXPECT_EQ_MSG([dateComponents week], NSUndefinedDateComponent, "FAILED: week default value should be NSUndefinedDateComponent");

    dateComponents.calendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    EXPECT_EQ_MSG([dateComponents week], NSUndefinedDateComponent, "FAILED: week value should not change because of calendar");

    dateComponents.weekOfMonth = 1;
    EXPECT_EQ_MSG([dateComponents week], NSUndefinedDateComponent, "FAILED: week value should not depend on weekOfMonth");
    dateComponents.weekOfYear = 1;
    EXPECT_EQ_MSG([dateComponents week], NSUndefinedDateComponent, "FAILED: week value should not depend on weekOfYear");

    [dateComponents setWeek:1];
    EXPECT_EQ_MSG([dateComponents week], 1, "FAILED: week value should change when assigned");
    [dateComponents release];
}
