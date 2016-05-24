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

#include "Starboard.h"
#include "StubReturn.h"
#include "Foundation/NSData.h"
#include "Foundation/NSString.h"
#include "Foundation/NSArray.h"
#include "Etc.h"
#include "Foundation/NSTimeZone.h"
#include "NSTimeZoneInternal.h"

#include <unicode/gregocal.h>
#include <windows.h>

#import <vector>
#import <string>

@interface NSTimeZone ()
@property (nonatomic, readwrite, copy) NSString* description;
@property (nonatomic, readwrite, copy) NSDate* nextDaylightSavingTimeTransition;
@property (nonatomic, readwrite, copy) NSString* abbreviation;
@property (nonatomic, readwrite, copy) NSString* name;
@property (nonatomic, readwrite, copy) NSData* data;
@property (nonatomic, readwrite) NSTimeInterval daylightSavingTimeOffset;
@property (nonatomic, readwrite) BOOL isDaylightSavingTime;
@property (nonatomic, readwrite) NSInteger secondsFromGMT;
@end

static const wchar_t* TAG = L"NSTimeZone";

static NSTimeZone* s_defaultTimeZone;
static StrongId<NSDictionary> s_abbreviationDictionary;
static StrongId<NSTimeZone> s_systemTimeZone;
static StrongId<NSArray> s_knownTimeZoneNames;

// This value is negative as TIME_ZONE_INFORMATION has an opposite sign for bias than icu.

const static int c_minutesToMillisecondsBias = -60000;

// Convert NSTimeZoneNameStyle to ICU EDisplayType.
icu::TimeZone::EDisplayType _convertNSTimeZoneNameStyleToICUEDisplayType(NSTimeZoneNameStyle* style, UBool& isDaylight) {
    switch (*style) {
        case NSTimeZoneNameStyleStandard:
            isDaylight = FALSE;
            return icu::TimeZone::EDisplayType::LONG;
        case NSTimeZoneNameStyleShortStandard:
            isDaylight = FALSE;
            return icu::TimeZone::EDisplayType::SHORT_GMT;
        case NSTimeZoneNameStyleDaylightSaving:
            isDaylight = TRUE;
            return icu::TimeZone::EDisplayType::LONG;
        case NSTimeZoneNameStyleShortDaylightSaving:
            isDaylight = TRUE;
            return icu::TimeZone::EDisplayType::SHORT_GMT;
        case NSTimeZoneNameStyleGeneric:
            isDaylight = FALSE;
            return icu::TimeZone::EDisplayType::LONG_GENERIC;
        case NSTimeZoneNameStyleShortGeneric:
            isDaylight = FALSE;
            // Use LONG_GENERIC instead of SHORT_GENERIC here to get consistent result with IOS
            return icu::TimeZone::EDisplayType::LONG_GENERIC;
        default:
            isDaylight = FALSE;
            return icu::TimeZone::EDisplayType::SHORT_COMMONLY_USED;
    }
}

@implementation NSTimeZone {
    icu::TimeZone* _icuTZ;
}

/**
 @Status Interoperable
*/
+ (void)initialize {
    [self _setDefaultAbbreviationDictionary];
    s_knownTimeZoneNames = [[self abbreviationDictionary] allValues];
}

+ (void)_setTimeZoneToSystemSettings:(NSTimeZone*)timeZone {
    @synchronized(self) {
        s_systemTimeZone = timeZone;
        [s_systemTimeZone setDaylightSavingTimeOffset:[timeZone daylightSavingTimeOffsetForDate:[NSDate date]]];
    }
}

+ (NSTimeZone*)_getSystemTZ {
    @synchronized(self) {
        if (!s_systemTimeZone) {
            // Get current locale.
            NSString* countryCode = [[NSLocale currentLocale] objectForKey:NSLocaleCountryCode];

            // Get time zone info from system.
            DYNAMIC_TIME_ZONE_INFORMATION dtz;
            int daylightSavings = GetDynamicTimeZoneInformation(&dtz);

            NSTimeZone* systemTimeZone = [[NSTimeZone alloc] init];

            if (daylightSavings == TIME_ZONE_ID_INVALID) {
                systemTimeZone = [NSTimeZone timeZoneWithName:@"GMT"];
                TraceError(TAG, L"Could not retrieve Dynamic Time Zone Information : %d.", GetLastError());
                [self _setTimeZoneToSystemSettings:systemTimeZone];
            } else {
                int windowsBias = 0;
                int millisecondsBias = 0;
                if (daylightSavings == TIME_ZONE_ID_DAYLIGHT) {
                    windowsBias = (dtz.Bias + dtz.DaylightBias);
                } else {
                    windowsBias = (dtz.Bias + dtz.StandardBias);
                }

                millisecondsBias = (dtz.Bias + dtz.StandardBias) * c_minutesToMillisecondsBias;

                UErrorCode status = U_ZERO_ERROR;

                icu::StringEnumeration* timeZoneIds =
                    icu::TimeZone::createTimeZoneIDEnumeration(UCAL_ZONE_TYPE_ANY, [countryCode UTF8String], &millisecondsBias, status);

                NSTimeZone* systemTimeZone = [[NSTimeZone alloc] init];

                BOOL gotICUTimeZone = NO;

                // Did we find a suitable time zone?
                if (!U_FAILURE(status) && timeZoneIds->count(status) > 0) {
                    if (!U_FAILURE(status)) {
                        const UnicodeString* zoneId = timeZoneIds->snext(status);
                        if (!U_FAILURE(status)) {
                            systemTimeZone->_icuTZ = icu_48::TimeZone::createTimeZone(*zoneId);
                            gotICUTimeZone = YES;
                        }
                    }
                }
                if (!gotICUTimeZone) {
                    if (U_FAILURE(status)) {
                        TraceError(TAG,
                                   L"ICU could not create proper time zone. Creating generic time zone. ICU Error code : %hs.",
                                   u_errorName(status));
                    }

                    // The user's region settings do not match the time zone set. The best we can do is get a generic time zone
                    // that matches the system time zone.
                    int hourOffset = -windowsBias / 60;
                    int minuteOffset = -windowsBias % 60;

                    NSString* genericTimeZone = [NSString stringWithFormat:@"GMT%+d:%02d", hourOffset, minuteOffset];
                    systemTimeZone = [NSTimeZone timeZoneWithName:genericTimeZone];
                }

                [self _setTimeZoneToSystemSettings:systemTimeZone];
            }
        }
        return s_systemTimeZone;
    }
}

/**
 @Status Caveat
 @Notes Uses language to determine region for time zone. Only picks first of possible time zones in region.
*/
+ (instancetype)systemTimeZone {
    return [self _getSystemTZ];
}

/**
 @Status Interoperable
*/
+ (void)resetSystemTimeZone {
    s_systemTimeZone = nil;
}

/**
 @Status Interoperable
*/
+ (instancetype)defaultTimeZone {
    NSTimeZone* ret;

    if (s_defaultTimeZone != nil) {
        ret = s_defaultTimeZone;
    } else {
        ret = [self systemTimeZone];
    }
    return [[ret copy] autorelease];
}

/**
 @Status Interoperable
*/
+ (void)setDefaultTimeZone:(NSTimeZone*)zone {
    zone = [zone retain];
    [s_defaultTimeZone release];
    s_defaultTimeZone = zone;
}

/**
 @Status Interoperable
*/
+ (NSArray*)knownTimeZoneNames {
    return s_knownTimeZoneNames;
}

- (icu::TimeZone*)_createICUTimeZone {
    return _icuTZ->clone();
}

/**
 @Status Interoperable
 @Get the time zone data version from ICU. The return value is NSString and based on ICU version.
*/
+ (NSString*)timeZoneDataVersion {
    UErrorCode errorCode = U_ZERO_ERROR;
    const char* tzDataVersion = icu::TimeZone::getTZDataVersion(errorCode);
    NSString* ret = [NSString stringWithUTF8String:tzDataVersion];
    return ret;
}

/**
 @Status Interoperable
*/
+ (instancetype)timeZoneForSecondsFromGMT:(NSInteger)seconds {
    NSTimeZone* ret = [self alloc];
    ret->_icuTZ = icu_48::TimeZone::createTimeZone(icu_48::UnicodeString("GMT"));
    ret->_icuTZ->setRawOffset(seconds * 1000);
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)localTimeZone {
    if (s_defaultTimeZone != nil) {
        return [[s_defaultTimeZone retain] autorelease];
    }
    return [self systemTimeZone];
}

+ (instancetype)_gmtTimeZone {
    NSTimeZone* ret = [self alloc];
    ret->_icuTZ = icu_48::TimeZone::getGMT()->clone();
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)timeZoneWithName:(NSString*)name {
    NSTimeZone* ret = [self alloc];
    ret->_icuTZ = icu_48::TimeZone::createTimeZone(icu_48::UnicodeString([name UTF8String]));
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)timeZoneWithAbbreviation:(NSString*)abbreviation {
    return [self timeZoneWithName:[s_abbreviationDictionary objectForKey:abbreviation]];
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super init]) {
        // Can't encode/decode ICU object. Potentially recreate system TZ?
        _nextDaylightSavingTimeTransition = [[coder decodeObjectOfClass:[NSDate class] forKey:@"nextDaylightSavingTimeTransition"] retain];
        _abbreviation = [[coder decodeObjectForKey:@"abbreviation"] retain];
        _name = [[coder decodeObjectForKey:@"name"] retain];
        _data = [[coder decodeObjectOfClass:[NSData class] forKey:@"data"] retain];
        _daylightSavingTimeOffset = [coder decodeDoubleForKey:@"daylightSavingTimeOffset"];
        _isDaylightSavingTime = [coder decodeBoolForKey:@"isDaylightSavingTime"];
        _secondsFromGMT = [coder decodeInt64ForKey:@"secondsFromGMT"];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    // Can't encode/decode ICU object. Potentially recreate system TZ?
    [coder encodeObject:[self description] forKey:@"description"];
    [coder encodeObject:_nextDaylightSavingTimeTransition forKey:@"nextDaylightSavingTimeTransition"];
    [coder encodeObject:_abbreviation forKey:@"abbreviation"];
    [coder encodeObject:_name forKey:@"name"];
    [coder encodeObject:_data forKey:@"data"];
    [coder encodeDouble:_daylightSavingTimeOffset forKey:@"daylightSavingTimeOffset"];
    [coder encodeBool:_isDaylightSavingTime forKey:@"isDaylightSavingTime"];
    [coder encodeInt64:_secondsFromGMT forKey:@"secondsFromGMT"];
}

/**
 @Status Interoperable
*/
+ (void)setAbbreviationDictionary:(NSDictionary*)dict {
    @synchronized(self) {
        s_abbreviationDictionary = dict;
    }
}

/**
 @Status Interoperable
*/
+ (NSDictionary*)abbreviationDictionary {
    @synchronized(self) {
        return s_abbreviationDictionary;
    }
}

+ (void)_setDefaultAbbreviationDictionary {
    UErrorCode status = U_ZERO_ERROR;
    icu::StringEnumeration* abbreviations = icu::TimeZone::createTimeZoneIDEnumeration(UCAL_ZONE_TYPE_ANY, NULL, NULL, status);

    if (abbreviations->count(status) > 0 && status == U_ZERO_ERROR) {
        NSMutableDictionary* defaultDictionary = [NSMutableDictionary dictionary];

        const UnicodeString* abbreviation = abbreviations->snext(status);

        while (abbreviation != NULL && status == U_ZERO_ERROR) {
            icu::TimeZone* timeZone = icu::TimeZone::createTimeZone(*abbreviation);
            icu_48::UnicodeString name;
            icu_48::UnicodeString id;

            timeZone->getDisplayName(name);
            timeZone->getID(id);

            std::vector<UChar> tempName(name.length());
            std::vector<UChar> tempId(id.length());

            UErrorCode status = U_ZERO_ERROR;
            int length = name.extract(tempName.data(), tempName.size(), status);

            int length2 = id.extract(tempId.data(), tempId.size(), status);

            NSString* nsName = [[NSString alloc] initWithCharacters:(unichar*)tempName.data() length:length];
            NSString* nsId = [[NSString alloc] initWithCharacters:(unichar*)tempId.data() length:length2];

            [defaultDictionary setObject:nsId forKey:nsName];

            abbreviation = abbreviations->snext(status);
        }

        [self setAbbreviationDictionary:defaultDictionary];
    }
}

/**
 @Status Caveat
 @Notes Data is unused currently. Data is "The data from the time-zone files located at /usr/share/zoneinfo."
*/
+ (NSTimeZone*)timeZoneWithName:(NSString*)name data:(NSData*)data {
    NSTimeZone* ret = [NSTimeZone timeZoneWithName:name];
    ret.data = data;
    return ret;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithName:(NSString*)name {
    if (self = [self init]) {
        self->_icuTZ = icu_48::TimeZone::createTimeZone(icu_48::UnicodeString([name UTF8String]));
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithName:(NSString*)name data:(NSData*)data {
    if (self = [self initWithName:name]) {
        self.data = data;
    }
    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToTimeZone:(NSTimeZone*)timeZone {
    if ([[self name] isEqualToString:[timeZone name]]) {
        return (self.data == timeZone.data || [self.data isEqual:timeZone.data]);
    }
    return false;
}

/**
 @Status Stub
*/
- (NSString*)abbreviationForDate:(NSDate*)date {
    UNIMPLEMENTED();
    return @"";
}

/**
 @Status Stub
*/
- (NSTimeInterval)daylightSavingTimeOffsetForDate:(NSDate*)date {
    UErrorCode status = U_ZERO_ERROR;
    int32_t stOffset;
    int32_t dtOffset;
    _icuTZ->getOffset([date timeIntervalSince1970] * 1000.0, FALSE, stOffset, dtOffset, status);
    return (NSTimeInterval)dtOffset / 1000;
}

/**
 @Status Stub
*/
- (NSDate*)nextDaylightSavingTimeTransitionAfterDate:(NSDate*)date {
    UNIMPLEMENTED();
    return _nextDaylightSavingTimeTransition;
}

/**
 @Status Interoperable
*/
- (NSString*)name {
    icu_48::UnicodeString n;
    _icuTZ->getID(n);
    std::string realStr;
    n.toUTF8String(realStr);
    return [NSString stringWithUTF8String:realStr.c_str()];
}

/**
 @Status Caveat
 @Notes Displays correct abbreviation but with slightly incorrect formatting on the offset. GMT-07:00 vs GMT-7
*/
- (NSString*)abbreviation {
    icu_48::UnicodeString n;
    UBool useDaylight = [self isDaylightSavingTime];
    _icuTZ->getDisplayName(useDaylight, icu::TimeZone::EDisplayType::SHORT, n);
    std::string realStr;
    n.toUTF8String(realStr);
    return [NSString stringWithUTF8String:realStr.c_str()];
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    return [NSString stringWithFormat:@"%@ (%@) %ld", [self name], [self abbreviation], (long)[self secondsFromGMT]];
}

/**
 @Status Stub
*/
- (NSString*)localizedName:(NSTimeZoneNameStyle)style locale:(NSLocale*)locale {
    UBool daylight = TRUE;
    icu::TimeZone::EDisplayType type = _convertNSTimeZoneNameStyleToICUEDisplayType(&style, daylight);

    NSString* identifier = [locale localeIdentifier];
    icu::Locale icuLocale = icu::Locale::createFromName([identifier UTF8String]);

    icu_48::UnicodeString ret;

    _icuTZ->getDisplayName(daylight, type, icuLocale, ret);

    std::string realStr;
    ret.toUTF8String(realStr);
    return [NSString stringWithUTF8String:realStr.c_str()];
}

/**
 @Status Interoperable
*/
- (NSInteger)secondsFromGMT {
    UBool useDaylight = [self isDaylightSavingTime];
    if (useDaylight) {
        return (_icuTZ->getRawOffset() + _icuTZ->getDSTSavings()) / 1000;
    }
    return _icuTZ->getRawOffset() / 1000;
}

/**
 @Status Stub
*/
- (NSInteger)secondsFromGMTForDate:(NSDate*)date {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (BOOL)isDaylightSavingTimeForDate:(NSDate*)date {
    UErrorCode status = U_ZERO_ERROR;
    BOOL isDaylight = _icuTZ->inDaylightTime([date timeIntervalSince1970] * 1000.0, status) && _icuTZ->useDaylightTime();
    if (U_FAILURE(status)) {
        TraceError(TAG, L"ICU Status Error. Error Code : %hs.", u_errorName(status));
        return NO;
    }

    return isDaylight;
}

/**
 @Status Interoperable
*/
- (BOOL)isDaylightSavingTime {
    return [self isDaylightSavingTimeForDate:[NSDate date]];
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    delete _icuTZ;
    [super dealloc];
}

@end
