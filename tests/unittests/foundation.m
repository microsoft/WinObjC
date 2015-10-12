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
#import <mach/mach_time.h>

TEST(Foundation, SanityTest) {
    LOG_INFO("Foundation sanity test: ");

    /*** NSArray ***/
    NSArray* arr1 = [NSArray arrayWithObject: @1];
    NSArray* arr2 = [NSArray arrayWithObject: @1];
    NSArray* arr3 = [NSArray arrayWithObject: @2];

    ASSERT_TRUE_MSG([arr1 isEqual: arr2], "FAILED: arr1 and arr2 should be equal!\n");
    ASSERT_FALSE_MSG([arr1 isEqual: arr3], "FAILED: arr1 and arr2 should not be equal!\n");
    ASSERT_EQ_MSG(arr1[0], arr2[0], "FAILED: arr1[0] and arr2[0] should be equal!\n");
    ASSERT_NE_MSG(arr1[0], arr3[0], "FAILED: arr1[0] and arr3[0] should not be equal!\n");
    
    /*** NSCalendar ***/    
    //  Feb 14, 2012 12:00 GMT (leap year)
    NSDate* startDate = [NSDate dateWithTimeIntervalSince1970: 1329220800.0];    
    //  Apr 1, 2012 12:00 GMT
    NSDate* endDate = [NSDate dateWithTimeIntervalSince1970: 1333281600.0];
    
    NSTimeZone* curTZ = [NSTimeZone timeZoneWithName: @"America/Los_Angeles"];
    
    ASSERT_FALSE_MSG(([curTZ isDaylightSavingTimeForDate: startDate] != NO ||
        [curTZ isDaylightSavingTimeForDate: endDate] != YES), 
        "FAILED: timezone daylight savings time failure: %d %d\n", 
        [curTZ isDaylightSavingTimeForDate: startDate],
        [curTZ isDaylightSavingTimeForDate: endDate] );
    
    NSCalendar* curCal = [NSCalendar currentCalendar];
    [curCal setTimeZone: curTZ];
    
    NSDateComponents* component1 = [curCal components: NSSecondCalendarUnit | NSMinuteCalendarUnit |
                                                       NSHourCalendarUnit | NSDayCalendarUnit | 
                                                       NSMonthCalendarUnit | NSYearCalendarUnit
                                           fromDate: startDate];
    ASSERT_FALSE_MSG( component1.second != 0 ||
        component1.minute != 0 ||
        component1.hour != 4 ||
        component1.day != 14 ||
        component1.month != 2 ||
        component1.year != 2012,
        "FAILED: component1 not accurate: %d %d %d %d %d %d\n", 
        component1.second, 
        component1.minute, 
        component1.hour, 
        component1.day, 
        component1.month, 
        component1.year );
    
    NSDateComponents* comp1 = [curCal components: NSSecondCalendarUnit | NSMinuteCalendarUnit |
                                                  NSHourCalendarUnit | NSDayCalendarUnit | 
                                                  NSMonthCalendarUnit | NSYearCalendarUnit
                                           fromDate: startDate toDate: endDate options: 0];

    ASSERT_FALSE_MSG( comp1.second != 0 || 
        comp1.minute != 0 || 
        comp1.hour != 1 ||
        comp1.day != 18 ||
        comp1.month != 1 ||
        comp1.year != 0,
        "FAILED: component1 not accurate: %d %d %d %d %d %d\n", 
        component1.second, 
        component1.minute, 
        component1.hour, 
        component1.day, 
        component1.month, 
        component1.year);
    
    NSDateComponents* comp2 = [curCal components: NSSecondCalendarUnit
                               fromDate: startDate toDate: endDate options: 0];
    ASSERT_EQ_MSG( comp2.second, 4060800, "FAILED: comp2 not accurate: %d\n", comp2.second);
    
    /*** NSNull ***/
    NSNull* nul1 = [NSNull null], *nul2 = [NSNull alloc], *nul3 = [NSNull new], *nul4 = [nul1 copy];
    ASSERT_FALSE_MSG( nul1 != nul2 || nul2 != nul3 || nul3 != nul4 || ![nul1 isEqual: nul4],
        "FAILED: comp1 not accurate: %d %d %d %d %d %d\n", 
        comp1.second, 
        comp1.minute, 
        comp1.hour, 
        comp1.day, 
        comp1.month, 
        comp1.year);

}

TEST(Foundation, NSUUID) {
    NSUUID* uuidA = [NSUUID UUID];
    NSUUID* uuidB = [NSUUID UUID];
    NSUUID* uuidC = [NSUUID UUID];
    ASSERT_FALSE_MSG([uuidA isEqual:uuidB] || [uuidB isEqual:uuidC],
          "FAILED: NSUUID instances should be unique");

    NSUUID* uuidAClone = [[NSUUID alloc] initWithUUIDString:[uuidA UUIDString]];
    ASSERT_TRUE_MSG([uuidA isEqual:uuidAClone] == YES,
          "FAILED: An NSUUID created from parsing the string format of another UUID should equal it.");

    NSUUID* uuidBad = [[NSUUID alloc] initWithUUIDString:@"HELLOWOR-LDTH-ISIS-ABAD-UUIDSTRING!!"];
    ASSERT_TRUE_MSG(uuidBad == nil,
        "FAILED: NSUUID should have failed to parse this weird string: %s",
        [[uuidBad description] UTF8String]);

    NSUUID* uuidShort = [[NSUUID alloc] initWithUUIDString:@"000000"];
    ASSERT_TRUE_MSG(uuidShort == nil,
        "FAILED: NSUUID should have failed to parse this short string: %s",
        [[uuidShort description] UTF8String]);
}
