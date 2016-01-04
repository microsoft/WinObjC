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

#include "gtest-api.h"
#import <Foundation/Foundation.h>

TEST(Foundation, NSDateComponents_ComponentsTimeZoneTest) {
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

    ASSERT_OBJCEQ_MSG(estDate, cstDateMatching, "FAILED: dates should match");
    ASSERT_OBJCNE_MSG(cstDateNonMatching, cstDateMatching, "FAILED: dates should differ by one hour");
    ASSERT_OBJCNE_MSG(estDate, cstDateNonMatching, "FAILED: dates should differ by one hour");
    ASSERT_EQ_MSG(secondsBetween, 3600, "FAILED: dates should differ by one hour");
}

TEST(Foundation, NSDateComponents_CalendarTimeZoneTest) {
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
    ASSERT_EQ_MSG(secondsBetween, 3600, "FAILED: dates should differ by one hour");
}
