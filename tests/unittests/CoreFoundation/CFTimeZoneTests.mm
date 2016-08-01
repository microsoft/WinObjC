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

class PropertyTests
    : public ::testing::TestWithParam<
          ::testing::
              tuple<CFStringRef, NSString*, NSString*, NSString*, NSString*, NSString*, NSString*, NSString*, NSString*, CFTimeInterval>> {
public:
    explicit PropertyTests()
        : ::testing::TestWithParam<::testing::tuple<CFStringRef,
                                                    NSString*,
                                                    NSString*,
                                                    NSString*,
                                                    NSString*,
                                                    NSString*,
                                                    NSString*,
                                                    NSString*,
                                                    NSString*,
                                                    CFTimeInterval>>() {
    }

protected:
    virtual void SetUp() {
    }

    virtual void TearDown() {
    }
};

TEST_P(PropertyTests, NameOffset) {
    CFStringRef tzName = ::testing::get<0>(GetParam());
    CFTimeZoneRef tz = CFTimeZoneCreate(kCFAllocatorDefault, tzName, nullptr);

    EXPECT_OBJCEQ(::testing::get<1>(GetParam()), (__bridge NSString*)CFTimeZoneCopyAbbreviation(tz, 0));

    EXPECT_OBJCEQ(::testing::get<2>(GetParam()), (__bridge NSString*)CFTimeZoneGetName(tz));

    EXPECT_OBJCEQ(::testing::get<3>(GetParam()),
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleStandard,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));
    EXPECT_OBJCEQ(::testing::get<4>(GetParam()),
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleShortStandard,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));
    EXPECT_OBJCEQ(::testing::get<5>(GetParam()),
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleDaylightSaving,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));
    EXPECT_OBJCEQ(::testing::get<6>(GetParam()),
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleShortDaylightSaving,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));
    EXPECT_OBJCEQ(::testing::get<7>(GetParam()),
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleGeneric,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));
    EXPECT_OBJCEQ(::testing::get<8>(GetParam()),
                  (__bridge NSString*)CFTimeZoneCopyLocalizedName(tz,
                                                                  kCFTimeZoneNameStyleShortGeneric,
                                                                  (__bridge CFLocaleRef)[NSLocale systemLocale]));

    EXPECT_EQ(::testing::get<9>(GetParam()), CFTimeZoneGetSecondsFromGMT(tz, 0));
}

INSTANTIATE_TEST_CASE_P(
    CFTimeZone,
    PropertyTests,
    ::testing::Values(
        ::testing::make_tuple(
            CFSTR("EST"), @"GMT-5", @"EST", @"GMT-05:00", @"GMT-5", @"GMT-05:00", @"GMT-5", @"GMT-05:00", @"GMT-5", -18000.000000),
        ::testing::make_tuple(CFSTR("America/Argentina/Buenos_Aires"),
                              @"GMT-3",
                              @"America/Argentina/Buenos_Aires",
                              @"GMT-03:00",
                              @"GMT-3",
                              @"GMT-03:00",
                              @"GMT-3",
                              @"Buenos Aires",
                              @"Buenos Aires",
                              -10800.000000),

        // Windows database diverges from OSX database
        ::testing::make_tuple(CFSTR("US/Pacific"),
#ifdef WINOBJC
                              @"GMT-8",
#else
                              @"PST",
#endif
                              @"US/Pacific",
                              @"GMT-08:00",
                              @"GMT-8",
                              @"GMT-07:00",
                              @"GMT-7",
                              @"Los Angeles",
                              @"Los Angeles",
                              -28800.000000)));

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
    EXPECT_OBJCEQ(static_cast<id>(gmtMinusFive),
                  [static_cast<id>(CFTimeZoneCreateWithName(kCFAllocatorDefault, CFSTR("GMT-05"), false)) autorelease]);
    EXPECT_OBJCEQ(static_cast<id>(gmtMinusFive),
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