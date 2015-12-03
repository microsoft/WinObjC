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
#include "Foundation/NSData.h"
#include "Foundation/NSString.h"
#include "Foundation/NSArray.h"
#include "Etc.h"
#include "Foundation/NSTimeZone.h"
#include "NSTimeZoneInternal.h"

#include <unicode/gregocal.h>
#include <windows.h>

#import <vector>

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

static NSTimeZone* s_defaultTimeZone;
static StrongId<NSDictionary> s_abbreviationDictionary;
static StrongId<NSTimeZone> s_systemTimeZone;
static NSArray* s_KnownTimeZoneNames;

// This value is negative as TIME_ZONE_INFORMATION has an opposite sign for bias than icu.

const static int c_minutesToMilliseconds = -60000;

@implementation NSTimeZone {
    icu::TimeZone* _icuTZ;
}

+ (void)initialize {
    [self _setDefaultAbbreviationDictionary];
    s_KnownTimeZoneNames = [[self abbreviationDictionary] allValues];
}

+ (void)_setTimeZoneToSystemSettings:(NSTimeZone*)timeZone {
    s_systemTimeZone = timeZone;
}

+ (NSTimeZone*)_getSystemTZ {
    @synchronized(self) {
        if (!s_systemTimeZone) {
            // Get current locale.
            NSLocale* currentLocale = [NSLocale currentLocale];
            NSString* countryCode = [currentLocale getNSLocaleCountryCode];

            // Get time zone info from system.
            TIME_ZONE_INFORMATION timeZoneInfo;
            GetTimeZoneInformation(&timeZoneInfo);

            // TIME_ZONE_INFORMATION offset is in minutes, icu needs milliseconds
            int milliseconds = timeZoneInfo.Bias * c_minutesToMilliseconds;

            UErrorCode status = U_ZERO_ERROR;
            icu::StringEnumeration* timeZoneIds =
                icu::TimeZone::createTimeZoneIDEnumeration(UCAL_ZONE_TYPE_ANY, [countryCode UTF8String], &milliseconds, status);

            NSTimeZone* systemTimeZone = [[NSTimeZone alloc] init];

            // Did we find a suitable time zone?
            if (timeZoneIds->count(status) > 0) {
                const UnicodeString* zoneId = timeZoneIds->snext(status);

                systemTimeZone->_icuTZ = icu_48::TimeZone::createTimeZone(*zoneId);
            } else {
                // Try again without country code.
                icu::StringEnumeration* timeZoneIds =
                    icu::TimeZone::createTimeZoneIDEnumeration(UCAL_ZONE_TYPE_ANY, NULL, &milliseconds, status);

                if (timeZoneIds->count(status) > 0) {
                    const UnicodeString* zoneId = timeZoneIds->snext(status);

                    systemTimeZone->_icuTZ = icu_48::TimeZone::createTimeZone(*zoneId);
                } else {
                    // There are no predefined time zones that match the system settings + language

                    systemTimeZone = [NSTimeZone timeZoneWithName:@"GMT"];
                }
            }

            [self _setTimeZoneToSystemSettings:systemTimeZone];
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
    return s_KnownTimeZoneNames;
}

- (icu::TimeZone*)_createICUTimeZone {
    return _icuTZ->clone();
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

+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        // Can't encode/decode ICU object. Potentially recreate system TZ?
        _description = [[coder decodeObjectForKey:@"description"] retain];
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

- (void)encodeWithCoder:(NSCoder*)coder {
    // Can't encode/decode ICU object. Potentially recreate system TZ?
    [coder encodeObject:_description forKey:@"description"];
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
    UNIMPLEMENTED();
    return nil;
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
    _icuTZ->getDisplayName(n);
    return NSStringFromICU(n);
}

/**
 @Status Interoperable
*/
- (NSString*)abbreviation {
    icu_48::UnicodeString n;
    _icuTZ->getID(n);
    return NSStringFromICU(n);
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    icu_48::UnicodeString n;
    _icuTZ->getDisplayName(n);
    return NSStringFromICU(n);
}

/**
 @Status Stub
*/
- (NSString*)localizedName:(NSTimeZoneNameStyle)name locale:(NSLocale*)locale {
    UNIMPLEMENTED();
    return [self description];
}

/**
 @Status Interoperable
*/
- (NSInteger)secondsFromGMT {
    return _icuTZ->getRawOffset() / 1000;
}

/**
 @Status Stub
*/
- (NSInteger)secondsFromGMTForDate:(NSDate*)date {
    UNIMPLEMENTED();
    assert(0);
    return 0;
}

- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (BOOL)isDaylightSavingTimeForDate:(NSDate*)date {
    UErrorCode status = U_ZERO_ERROR;

    return _icuTZ->inDaylightTime([date timeIntervalSince1970] * 1000.0, status);
}

/**
 @Status Interoperable
*/
- (BOOL)isDaylightSavingTime {
    return [self isDaylightSavingTimeForDate:[NSDate date]];
}

- (void)dealloc {
    delete _icuTZ;
    [super dealloc];
}

@end
