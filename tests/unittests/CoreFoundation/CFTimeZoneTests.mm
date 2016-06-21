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
#import <Starboard.h>
#import <Foundation/NSArray.h>
#import <CoreFoundation/CoreFoundation.h>

#import <array>

static void assertCFTimeZoneProperties(CFTimeZoneRef tz, NSDictionary* expectedProperties) {
    ASSERT_OBJCEQ(expectedProperties[@"CFTimeZoneCopyAbbreviation"], (__bridge NSString*)CFTimeZoneCopyAbbreviation(tz, 0));

    ASSERT_OBJCEQ(expectedProperties[@"CFTimeZoneGetName"], (__bridge NSString*)CFTimeZoneGetName(tz));

    ASSERT_OBJCEQ(expectedProperties[@"CFTimeZoneCopyLocalizedName Standard"],
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleStandard,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));
    ASSERT_OBJCEQ(expectedProperties[@"CFTimeZoneCopyLocalizedName ShortStandard"],
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleShortStandard,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));
    ASSERT_OBJCEQ(expectedProperties[@"CFTimeZoneCopyLocalizedName DaylightSaving"],
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleDaylightSaving,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));
    ASSERT_OBJCEQ(expectedProperties[@"CFTimeZoneCopyLocalizedName ShortDaylightSaving"],
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleShortDaylightSaving,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));
    ASSERT_OBJCEQ(expectedProperties[@"CFTimeZoneCopyLocalizedName Generic"],
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleGeneric,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));
    ASSERT_OBJCEQ(expectedProperties[@"CFTimeZoneCopyLocalizedName ShortGeneric"],
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleShortGeneric,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));

    ASSERT_OBJCEQ(expectedProperties[@"CFTimeZoneGetSecondsFromGMT"], [NSNumber numberWithDouble:CFTimeZoneGetSecondsFromGMT(tz, 0)]);
}

TEST(CFTimeZone, Create) {
    NSDictionary* expected = @{
        // @"CFTimeZoneCopyAbbreviation" : @"GMT-5",
        @"CFTimeZoneCopyAbbreviation" : @"EST",
        @"CFTimeZoneGetName" : @"EST",
        @"CFTimeZoneCopyLocalizedName Standard" : @"GMT-05:00",
        // @"CFTimeZoneCopyLocalizedName ShortStandard" : @"GMT-5",
        @"CFTimeZoneCopyLocalizedName ShortStandard" : @"GMT-05:00",
        @"CFTimeZoneCopyLocalizedName DaylightSaving" : @"GMT-05:00",
        // @"CFTimeZoneCopyLocalizedName ShortDaylightSaving" : @"GMT-5",
        @"CFTimeZoneCopyLocalizedName ShortDaylightSaving" : @"GMT-05:00",
        @"CFTimeZoneCopyLocalizedName Generic" : @"GMT-05:00",
        // @"CFTimeZoneCopyLocalizedName ShortGeneric" : @"GMT-5",
        @"CFTimeZoneCopyLocalizedName ShortGeneric" : @"GMT-05:00",
        @"CFTimeZoneGetSecondsFromGMT" : @-18000.000000
    };
    assertCFTimeZoneProperties(CFTimeZoneCreate(kCFAllocatorDefault, CFSTR("EST"), nullptr), expected);

    expected = @{
        // @"CFTimeZoneCopyAbbreviation" : @"GMT-3",
        @"CFTimeZoneCopyAbbreviation" : @"America/Argentina/Buenos_Aires",
        @"CFTimeZoneGetName" : @"America/Argentina/Buenos_Aires",
        @"CFTimeZoneCopyLocalizedName Standard" : @"GMT-03:00",
        // @"CFTimeZoneCopyLocalizedName ShortStandard" : @"GMT-3",
        @"CFTimeZoneCopyLocalizedName ShortStandard" : @"GMT-03:00",
        @"CFTimeZoneCopyLocalizedName DaylightSaving" : @"GMT-03:00",
        // @"CFTimeZoneCopyLocalizedName ShortDaylightSaving" : @"GMT-3",
        @"CFTimeZoneCopyLocalizedName ShortDaylightSaving" : @"GMT-03:00",
        // @"CFTimeZoneCopyLocalizedName Generic" : @"Buenos Aires",
        @"CFTimeZoneCopyLocalizedName Generic" : @"AR (Buenos Aires)",
        // @"CFTimeZoneCopyLocalizedName ShortGeneric" : @"Buenos Aires",
        @"CFTimeZoneCopyLocalizedName ShortGeneric" : @"AR (Buenos Aires)",
        @"CFTimeZoneGetSecondsFromGMT" : @-10800.000000
    };
    assertCFTimeZoneProperties(CFTimeZoneCreate(kCFAllocatorDefault, CFSTR("America/Argentina/Buenos_Aires"), nullptr), expected);

    expected = @{
        // @"CFTimeZoneCopyAbbreviation" : @"PST",
        @"CFTimeZoneCopyAbbreviation" : @"US/Pacific",
        @"CFTimeZoneGetName" : @"US/Pacific",
        @"CFTimeZoneCopyLocalizedName Standard" : @"GMT-08:00",
        // @"CFTimeZoneCopyLocalizedName ShortStandard" : @"GMT-8",
        @"CFTimeZoneCopyLocalizedName ShortStandard" : @"PST",
        @"CFTimeZoneCopyLocalizedName DaylightSaving" : @"GMT-07:00",
        // @"CFTimeZoneCopyLocalizedName ShortDaylightSaving" : @"GMT-7",
        @"CFTimeZoneCopyLocalizedName ShortDaylightSaving" : @"PDT",
        // @"CFTimeZoneCopyLocalizedName Generic" : @"Los Angeles",
        @"CFTimeZoneCopyLocalizedName Generic" : @"US (Los Angeles)",
        // @"CFTimeZoneCopyLocalizedName ShortGeneric" : @"Los Angeles",
        @"CFTimeZoneCopyLocalizedName ShortGeneric" : @"US (Los Angeles)",
        @"CFTimeZoneGetSecondsFromGMT" : @-28800.000000
    };
    assertCFTimeZoneProperties(CFTimeZoneCreate(kCFAllocatorDefault, CFSTR("US/Pacific"), nullptr), expected);
}

TEST(CFTimeZone, Default) {
    CFTimeZoneRef oldDefault = CFTimeZoneCopyDefault();
    CFAutorelease(oldDefault);
    CFTimeZoneRef newDefault = CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("GMT"), false);
    CFAutorelease(newDefault);

    ASSERT_OBJCNE((__bridge NSTimeZone*)oldDefault, (__bridge NSTimeZone*)newDefault);

    CFTimeZoneSetDefault(newDefault);
    ASSERT_OBJCEQ((__bridge NSTimeZone*)newDefault, static_cast<id>(CFAutorelease(CFTimeZoneCopyDefault())));

    CFTimeZoneSetDefault(oldDefault);
}

TEST(CFTimeZone, CreateWithGMTName) {
    CFStringRef invalidNames[22] = { CFSTR("GMT-5"),      CFSTR("GMT-05:"),    CFSTR("GMT-05:0"),   CFSTR("GMT-5"),     CFSTR("GMT-5:0"),
                                     CFSTR("GMT-500"),    CFSTR("GMT-50"),     CFSTR("GMT-5"),      CFSTR("GMT-050"),   CFSTR("GMT+012"),
                                     CFSTR("GMT+012:"),   CFSTR("GMT+012:0"),  CFSTR("GMT+012:00"), CFSTR("GMT+12:"),   CFSTR("GMT+12:0"),
                                     CFSTR("GMT+01200"),  CFSTR("GMT+120"),    CFSTR("GMT+012"),    CFSTR("GMT-5:000"), CFSTR("GMT-05:000"),
                                     CFSTR("GMT+12:000"), CFSTR("GMT+012:000") };

    CFStringRef validNamesMinusFive[5] = { CFSTR("GMT-05"), CFSTR("GMT-05:00"), CFSTR("GMT-5:00"), CFSTR("GMT-0500"), CFSTR("GMT-05") };
    CFStringRef validNamesPlusTwelve[4] = { CFSTR("GMT+12"), CFSTR("GMT+12:00"), CFSTR("GMT+1200"), CFSTR("GMT+12") };

    for (CFStringRef name : invalidNames) {
        ASSERT_OBJCEQ(nil, [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, name, false)) autorelease]);
        ASSERT_OBJCEQ(nil, [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, name, true)) autorelease]);
    }

    NSTimeZone* validTimeZone =
        [(__bridge NSTimeZone*)CFTimeZoneCreateWithName(kCFAllocatorDefault, validNamesMinusFive[0], false) autorelease];
    ASSERT_OBJCNE(nil, validTimeZone);

    for (CFStringRef name : validNamesMinusFive) {
        ASSERT_OBJCEQ(validTimeZone, [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, name, false)) autorelease]);
        ASSERT_OBJCEQ(validTimeZone, [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, name, true)) autorelease]);
    }

    validTimeZone = [(__bridge NSTimeZone*)CFTimeZoneCreateWithName(kCFAllocatorDefault, validNamesPlusTwelve[0], false) autorelease];
    ASSERT_OBJCNE(nil, validTimeZone);

    for (CFStringRef name : validNamesPlusTwelve) {
        ASSERT_OBJCEQ(validTimeZone, [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, name, false)) autorelease]);
        ASSERT_OBJCEQ(validTimeZone, [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, name, true)) autorelease]);
    }

    // GMT+0120 is valid but is parsed as +01:20
    ASSERT_OBJCNE(nil, [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("GMT+0120"), false)) autorelease]);
    ASSERT_OBJCNE(nil, [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("GMT+0120"), true)) autorelease]);
}

TEST(CFTimeZone, InvalidName) {
    ASSERT_OBJCEQ(nil, [(__bridge NSTimeZone*)CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("winobjc"), false) autorelease]);
    ASSERT_OBJCEQ(nil, [(__bridge NSTimeZone*)CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("winobjc"), true) autorelease]);
    ASSERT_OBJCEQ(nil, [(__bridge NSTimeZone*)CFTimeZoneCreate(kCFAllocatorDefault, CFSTR("winobjc"), nullptr) autorelease]);
    ASSERT_OBJCEQ(nil, [(__bridge NSTimeZone*)CFTimeZoneCreate(kCFAllocatorDefault, CFSTR("Etc/Unknown"), nullptr) autorelease]);
}

TEST(CFTimeZone, GMTSecondsWithDST) {
    CFTimeZoneRef monaco = CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("Europe/Monaco"), false);
    CFAutorelease(monaco);

    // Monaco is GMT+1, observes DST from last Sunday of March -> last Sunday of October
    CFTimeInterval oneHour = 1 * 60 * 60;

    // 0 = midnight Jan 1, 2001 GMT
    ASSERT_EQ(oneHour, CFTimeZoneGetSecondsFromGMT(monaco, 0));
    ASSERT_EQ(0, CFTimeZoneGetDaylightSavingTimeOffset(monaco, 0));
    ASSERT_EQ(false, CFTimeZoneIsDaylightSavingTime(monaco, 0));

    // midnight GMT+1, Sunday, March 25, 2001
    // 31 (Jan) + 28 (Feb) + 24 (Mar) days
    CFAbsoluteTime lastSundayMarch2001 = oneHour + (31 + 28 + 24) * 24 * 60 * 60;

    // should be in DST
    ASSERT_EQ(lastSundayMarch2001, CFTimeZoneGetNextDaylightSavingTimeTransition(monaco, 0));
    ASSERT_EQ(2 * oneHour, CFTimeZoneGetSecondsFromGMT(monaco, lastSundayMarch2001));
    ASSERT_EQ(oneHour, CFTimeZoneGetDaylightSavingTimeOffset(monaco, lastSundayMarch2001));
    ASSERT_EQ(true, CFTimeZoneIsDaylightSavingTime(monaco, lastSundayMarch2001));

    // midnight GMT+1, Sunday, October 28, 2001
    CFAbsoluteTime lastSundayOctober2001 = oneHour + (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 27) * 24 * 60 * 60;

    // no longer in DST
    ASSERT_EQ(lastSundayOctober2001, CFTimeZoneGetNextDaylightSavingTimeTransition(monaco, lastSundayMarch2001));
    ASSERT_EQ(oneHour, CFTimeZoneGetSecondsFromGMT(monaco, lastSundayOctober2001));
    ASSERT_EQ(0, CFTimeZoneGetDaylightSavingTimeOffset(monaco, lastSundayOctober2001));
    ASSERT_EQ(false, CFTimeZoneIsDaylightSavingTime(monaco, lastSundayOctober2001));
}

TEST(CFTimeZone, CreateWithTimeIntervalFromGMT) {
    CFTimeZoneRef gmtMinusFive = CFTimeZoneCreateWithTimeIntervalFromGMT(kCFAllocatorDefault, 5 * -3600);
    CFAutorelease(gmtMinusFive);

    ASSERT_OBJCEQ(static_cast<id>(gmtMinusFive),
                  [static_cast<id>(CFTimeZoneCreateWithTimeIntervalFromGMT(kCFAllocatorDefault, 5 * -3600)) autorelease]);
    ASSERT_OBJCEQ(static_cast<id>(gmtMinusFive),
                  [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("GMT-05"), false)) autorelease]);
    ASSERT_OBJCEQ(static_cast<id>(gmtMinusFive),
                  [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("GMT-05:00"), false)) autorelease]);

    // CFTimeZoneRefs created with GMT time interval are different from regional timezones with the same offset
    // The former does not respect DST
    CFTimeZoneRef est = CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("EST"), true);
    CFAutorelease(est);
    ASSERT_OBJCNE(static_cast<id>(est), static_cast<id>(gmtMinusFive));
    ASSERT_EQ(false, CFTimeZoneIsDaylightSavingTime(gmtMinusFive, 180 * 24 * 60 * 60));
    ASSERT_EQ(true, CFTimeZoneIsDaylightSavingTime(est, 180 * 24 * 60 * 60));

    // Interesting edge case where "EST" doesn't show as in DST if abbreviations are not checked for in the constructor
    est = CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("EST"), false);
    CFAutorelease(est);
    ASSERT_EQ(false, CFTimeZoneIsDaylightSavingTime(est, 180 * 24 * 60 * 60));
}