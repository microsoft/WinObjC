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

const static int s_pacificBias = -28800;
const static int s_mountainBias = -25200;
const static int s_centralBias = -21600;
const static int s_easternBias = -18000;

TEST(NSTimeZone, SystemTimeZoneTests) {
    // Do the [NSTimeZone systemTimeZone] test if we're in a particular locale.
    NSLocale* currentLocale = [NSLocale currentLocale];

    if ([currentLocale.localeIdentifier isEqualToString:@"en_US"]) {
        NSTimeZone* systemTZ = [NSTimeZone systemTimeZone];
        NSTimeZone* expectedTZ = nil;
        NSInteger timeZoneBias = systemTZ.secondsFromGMT;
        if ([systemTZ isDaylightSavingTime]) {
            timeZoneBias -= systemTZ.daylightSavingTimeOffset;
        }

        switch (timeZoneBias) {
            case s_pacificBias:
                expectedTZ = [NSTimeZone timeZoneWithName:@"America/Los_Angeles"];
                break;
            case s_mountainBias:
                expectedTZ = [NSTimeZone timeZoneWithName:@"America/Boise"];
                break;
            case s_centralBias:
                expectedTZ = [NSTimeZone timeZoneWithName:@"America/Chicago"];
                break;
            case s_easternBias:
                expectedTZ = [NSTimeZone timeZoneWithName:@"America/Detroit"];
                break;
            default:
                expectedTZ = [NSTimeZone timeZoneWithName:@"GMT"];
                break;
        }
        ASSERT_OBJCEQ([expectedTZ abbreviation], [systemTZ abbreviation]);
        ASSERT_OBJCEQ([expectedTZ name], [systemTZ name]);
        ASSERT_EQ([expectedTZ secondsFromGMT], [systemTZ secondsFromGMT]);
    } else if ([currentLocale.localeIdentifier isEqualToString:@"es_MX"]) {
        NSTimeZone* systemTZ = [NSTimeZone systemTimeZone];
        NSTimeZone* expectedTZ = nil;
        switch (systemTZ.secondsFromGMT) {
            case s_pacificBias:
                expectedTZ = [NSTimeZone timeZoneWithName:@"America/Ensenada"];
                break;
            case s_mountainBias:
                expectedTZ = [NSTimeZone timeZoneWithName:@"America/Chihuahua"];
                break;
            default:
                expectedTZ = [NSTimeZone timeZoneWithName:@"GMT"];
                break;
        }
        ASSERT_OBJCEQ([expectedTZ abbreviation], [systemTZ abbreviation]);
        ASSERT_OBJCEQ([expectedTZ name], [systemTZ name]);
        ASSERT_EQ([expectedTZ secondsFromGMT], [systemTZ secondsFromGMT]);
    } else {
        LOG_INFO("[NSTimeZone localizedStringFromDate] not tested. Current locale is not covered by test.\n");
    }

    // System time zone should equal local time zone.
    ASSERT_TRUE_MSG([[NSTimeZone localTimeZone] isEqualToTimeZone:[NSTimeZone systemTimeZone]],
                    "FAILED - [localTimeZone isEqualToTimeZone:systemTimeZone] Time zones were not equal.");

    //[NSTimeZone abbreviationDictionary]
    NSDictionary* dictionary = [NSTimeZone abbreviationDictionary];
    ASSERT_EQ_MSG(
        175,
        [dictionary count],
        "FAILED - [[NSTimeZone abbreviationDictionary] count] != 175. There should be exactly 175 time zones in ICU. Was ICU updated?");
    NSString* abbreviation = [[dictionary allKeys] objectAtIndex:0];
    NSTimeZone* zone1 = [NSTimeZone timeZoneWithAbbreviation:abbreviation];
    NSTimeZone* zone2 = [NSTimeZone timeZoneWithName:[dictionary objectForKey:abbreviation]];

    // Set the abbreviation dictionary to nothing
    [NSTimeZone setAbbreviationDictionary:[NSDictionary dictionary]];
    ASSERT_TRUE_MSG([[NSTimeZone abbreviationDictionary] count] == 0,
                    "FAILED - [[NSTimeZone abbreviationDictionary] count] should be zero after replacing dictionary.");

    // initWithName and data
    zone1 = [[NSTimeZone alloc] initWithName:@"GMT"];
    zone2 = [[NSTimeZone alloc] initWithName:@"GMT" data:[zone1 data]];

    // Equals
    ASSERT_TRUE_MSG([zone1 isEqualToTimeZone:zone2], "FAILED - [NSTimeZone isEqualToTimeZone] Time zones were not equal.");
    ASSERT_TRUE_MSG(![zone1 isEqualToTimeZone:[NSTimeZone timeZoneWithName:@"PST"]],
                    "FAILED - [NSTimeZone isEqualToTimeZone] Time zones should not be equal.");

    // KnownTimeZones - Note, this is after the default abbreviationDictionary is replaced.
    NSArray* knownTimeZoneNames = [NSTimeZone knownTimeZoneNames];
    ASSERT_EQ_MSG(175,
                  [knownTimeZoneNames count],
                  "FAILED - [NSTimeZone knownTimeZoneNames] != 175. There should be exactly 175 time zones in ICU. Was ICU updated?");

#ifndef WINOBJC_DISABLE_TESTS
    // TODO 6678996: disabled check for ARM since we use a different version of icu data. Can be re-enabled if we get matching icu data.
    // Test for method timeZoneDataVersion. The value is based on the ICU version.
    NSString* timeZoneDataVersion = [NSTimeZone timeZoneDataVersion];
    ASSERT_OBJCEQ_MSG(@"2016b",
                      timeZoneDataVersion,
                      "FAILED - [NSTimeZone timeZoneDataVersion] != 2016b. The version should be 2016b. Was ICU updated?");
#endif

    // Verify localizedName
    NSTimeZone* aDSTTz = [NSTimeZone timeZoneWithName:@"Pacific/Auckland"];
    NSString* tzNameStandard = [aDSTTz localizedName:NSTimeZoneNameStyleStandard locale:[NSLocale localeWithLocaleIdentifier:@"en-GB"]];
    ASSERT_OBJCEQ_MSG(@"New Zealand Standard Time",
                      tzNameStandard,
                      "FAILED - localizedName of NSTimeZoneNameStyleStandard is not correct.");

    NSString* tzNameShortStandard =
        [aDSTTz localizedName:NSTimeZoneNameStyleShortStandard locale:[NSLocale localeWithLocaleIdentifier:@"en-GB"]];
    ASSERT_OBJCEQ_MSG(@"+1200", tzNameShortStandard, "FAILED - localizedName of NSTimeZoneNameStyleShortStandard is not correct.");

    NSString* tzNameGeneric = [aDSTTz localizedName:NSTimeZoneNameStyleGeneric locale:[NSLocale localeWithLocaleIdentifier:@"en-GB"]];
    ASSERT_OBJCEQ_MSG(@"New Zealand Time", tzNameGeneric, "FAILED - localizedName of NSTimeZoneNameStyleGeneric is not correct.");

    NSString* tzNameShortGeneric =
        [aDSTTz localizedName:NSTimeZoneNameStyleShortGeneric locale:[NSLocale localeWithLocaleIdentifier:@"en-GB"]];
    ASSERT_OBJCEQ_MSG(@"New Zealand Time", tzNameShortGeneric, "FAILED - localizedName of NSTimeZoneNameStyleShortGeneric is not correct.");

    NSString* tzNameDaylight =
        [aDSTTz localizedName:NSTimeZoneNameStyleDaylightSaving locale:[NSLocale localeWithLocaleIdentifier:@"en-GB"]];
    ASSERT_OBJCEQ_MSG(@"New Zealand Daylight Time",
                      tzNameDaylight,
                      "FAILED - localizedName of NSTimeZoneNameStyleDaylightSaving is not correct.");

    NSString* tzNameShortDaylight =
        [aDSTTz localizedName:NSTimeZoneNameStyleShortDaylightSaving locale:[NSLocale localeWithLocaleIdentifier:@"en-GB"]];
    ASSERT_OBJCEQ_MSG(@"+1300", tzNameShortDaylight, "FAILED - localizedName of NSTimeZoneNameStyleShortDaylightSaving is not correct.");
}

TEST(NSTimeZone, ArchivingUnarchiving) {
    NSTimeZone* tz = [NSTimeZone localTimeZone];

    ASSERT_TRUE([tz isEqualToTimeZone:[NSTimeZone systemTimeZone]]);

    NSData* data = [NSKeyedArchiver archivedDataWithRootObject:tz];

    NSTimeZone* tzUnArchived = [NSKeyedUnarchiver unarchiveObjectWithData:data];

    ASSERT_TRUE([tzUnArchived isEqualToTimeZone:[NSTimeZone systemTimeZone]]);
}