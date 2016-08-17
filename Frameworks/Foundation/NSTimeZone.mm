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

#import <Starboard.h>
#import <StubReturn.h>
#import <Foundation/NSData.h>
#import <Foundation/NSString.h>
#import <Foundation/NSArray.h>
#import "Etc.h"
#import "BridgeHelpers.h"
#import "NSCFTimeZone.h"
#import "NSRaise.h"
#import <CoreFoundation/CFTimeZone.h>
#import <Foundation/NSTimeZone.h>
#import <unicode/gregocal.h>

static const wchar_t* TAG = L"NSTimeZone";

@implementation NSTimeZone

+ ALLOC_PROTOTYPE_SUBCLASS_WITH_ZONE(NSTimeZone, NSTimeZonePrototype);

/**
 @Status Interoperable
*/
+ (instancetype)systemTimeZone {
    return [static_cast<NSTimeZone*>(CFTimeZoneCopySystem()) autorelease];
}

/**
 @Status Interoperable
*/
+ (void)resetSystemTimeZone {
    CFTimeZoneResetSystem();
}

/**
 @Status Interoperable
*/
+ (instancetype)defaultTimeZone {
    return [static_cast<NSTimeZone*>(CFTimeZoneCopyDefault()) autorelease];
}

/**
 @Status Interoperable
*/
+ (void)setDefaultTimeZone:(NSTimeZone*)zone {
    CFTimeZoneSetDefault(static_cast<CFTimeZoneRef>(zone));
}

/**
 @Status Interoperable
*/
+ (NSArray*)knownTimeZoneNames {
    return [static_cast<NSArray*>(CFTimeZoneCopyKnownNames()) autorelease];
}

/**
 @Status Interoperable
 @Notes Get the time zone data version from ICU. The return value is NSString and based on ICU version.
*/
+ (NSString*)timeZoneDataVersion {
    UErrorCode errorCode = U_ZERO_ERROR;
    const char* tzDataVersion = icu::TimeZone::getTZDataVersion(errorCode);

    if (!U_SUCCESS(errorCode)) {
        TraceError(TAG, L"Error fetching the time zone data version.");
    }

    return [NSString stringWithUTF8String:tzDataVersion];
}

/**
 @Status Interoperable
*/
+ (instancetype)timeZoneForSecondsFromGMT:(NSInteger)seconds {
    return [static_cast<NSTimeZone*>(CFTimeZoneCreateWithTimeIntervalFromGMT(nullptr, seconds)) autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)localTimeZone {
    NSTimeZone* toReturn = [self defaultTimeZone];
    if (toReturn != nil) {
        return toReturn;
    }

    return [self systemTimeZone];
}

/**
 @Status Interoperable
*/
+ (instancetype)timeZoneWithName:(NSString*)name {
    return [[[self alloc] initWithName:name] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)timeZoneWithAbbreviation:(NSString*)abbreviation {
    return [NSTimeZone timeZoneWithName:[[self abbreviationDictionary] objectForKey:abbreviation]];
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
    NSString* name = [coder decodeObjectForKey:@"NS.name"];
    NSData* data = [coder decodeObjectOfClass:[NSData class] forKey:@"NS.data"];

    return [self initWithName:name data:data];
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    // Can't encode/decode ICU object. Potentially recreate system TZ?
    [coder encodeObject:[self name] forKey:@"NS.name"];
    [coder encodeObject:[self data] forKey:@"NS.data"];
}

/**
 @Status Interoperable
*/
+ (void)setAbbreviationDictionary:(NSDictionary*)dict {
    CFTimeZoneSetAbbreviationDictionary(static_cast<CFDictionaryRef>(dict));
}

/**
 @Status Interoperable
*/
+ (NSDictionary*)abbreviationDictionary {
    return [static_cast<NSDictionary*>(CFTimeZoneCopyAbbreviationDictionary()) autorelease];
}

/**
 @Status Interoperable
 @Notes Data is unused currently. Data is "The data from the time-zone files located at /usr/share/zoneinfo."
*/
+ (NSTimeZone*)timeZoneWithName:(NSString*)name data:(NSData*)data {
    @try {
        return [[[self alloc] initWithName:name data:data] autorelease];
    } @catch (NSException* e) {
        return nil;
    }
}

/**
 @Status Interoperable
*/
- (instancetype)initWithName:(NSString*)name {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithName:(NSString*)name data:(NSData*)data {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if ([other isKindOfClass:[NSTimeZone class]]) {
        return [self isEqualToTimeZone:other];
    }
    return NO;
}

/**
 @Status Interoperable
*/
- (BOOL)isEqualToTimeZone:(NSTimeZone*)timeZone {
    if ([[self name] isEqualToString:[timeZone name]]) {
        return (self.data == timeZone.data || [self.data isEqual:timeZone.data]);
    }
    return NO;
}

/**
 @Status Interoperable
*/
- (NSData*)data {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)abbreviationForDate:(NSDate*)date {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSTimeInterval)daylightSavingTimeOffsetForDate:(NSDate*)date {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSTimeInterval)daylightSavingTimeOffset {
    return [self daylightSavingTimeOffsetForDate:[NSDate date]];
}

/**
 @Status Interoperable
*/
- (NSDate*)nextDaylightSavingTimeTransitionAfterDate:(NSDate*)date {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)name {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)abbreviation {
    return [self abbreviationForDate:[NSDate date]];
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
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSInteger)secondsFromGMT {
    return [self secondsFromGMTForDate:[NSDate date]];
}

/**
 @Status Interoperable
*/
- (NSInteger)secondsFromGMTForDate:(NSDate*)date {
    return NSInvalidAbstractInvocationReturn();
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
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (BOOL)isDaylightSavingTime {
    return [self isDaylightSavingTimeForDate:[NSDate date]];
}

@end
