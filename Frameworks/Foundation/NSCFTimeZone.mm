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
#include "BridgeHelpers.h"
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include "NSCFTimeZone.h"
#include <CoreFoundation/CFTimeZone.h>

#pragma region Factory Class
@implementation NSTimeZonePrototype

- (instancetype)initWithName:(NSString*)name {
    if (!name) {
        [NSException raise:NSInvalidArgumentException format:@"NSTimeZone initWithName: name can't be nil"];
    }

    return reinterpret_cast<NSTimeZonePrototype*>(
        static_cast<NSTimeZone*>(CFTimeZoneCreateWithName(nullptr, static_cast<CFStringRef>(name), true)));
}

- (instancetype)initWithName:(NSString*)name data:(NSData*)data {
    if (!name) {
        [NSException raise:NSInvalidArgumentException format:@"NSTimeZone initWithName: name can't be nil"];
    }

    return reinterpret_cast<NSTimeZonePrototype*>(
        static_cast<NSTimeZone*>(CFTimeZoneCreateWithName(nullptr, static_cast<CFStringRef>(name), true)));
}

@end
#pragma endregion

#pragma region NSCF Bridged Class
@implementation NSCFTimeZone

BRIDGED_CLASS_REQUIRED_IMPLS(CFTimeZoneRef, CFTimeZoneGetTypeID, NSTimeZone, NSCFTimeZone)

- (NSString*)abbreviationForDate:(NSDate*)aDate {
    return [static_cast<NSString*>(CFTimeZoneCopyAbbreviation(static_cast<CFTimeZoneRef>(self), [aDate timeIntervalSinceReferenceDate]))
        autorelease];
}

- (NSString*)name {
    return static_cast<NSString*>(CFTimeZoneGetName(static_cast<CFTimeZoneRef>(self)));
}

- (NSInteger)secondsFromGMTForDate:(NSDate*)aDate {
    return CFTimeZoneGetSecondsFromGMT(static_cast<CFTimeZoneRef>(self), [aDate timeIntervalSinceReferenceDate]);
}

- (NSData*)data {
    return static_cast<NSData*>(CFTimeZoneGetData(static_cast<CFTimeZoneRef>(self)));
}

- (NSString*)localizedName:(NSTimeZoneNameStyle)style locale:(NSLocale*)locale {
    return [static_cast<NSString*>(CFTimeZoneCopyLocalizedName(static_cast<CFTimeZoneRef>(self),
                                                               static_cast<CFTimeZoneNameStyle>(style),
                                                               static_cast<CFLocaleRef>(locale))) autorelease];
}

- (BOOL)isDaylightSavingTimeForDate:(NSDate*)aDate {
    return CFTimeZoneIsDaylightSavingTime(static_cast<CFTimeZoneRef>(self), [aDate timeIntervalSinceReferenceDate]) ? YES : NO;
}

- (NSTimeInterval)daylightSavingTimeOffsetForDate:(NSDate*)aDate {
    return CFTimeZoneGetDaylightSavingTimeOffset(static_cast<CFTimeZoneRef>(self), [aDate timeIntervalSinceReferenceDate]);
}

- (NSDate*)nextDaylightSavingTimeTransitionAfterDate:(NSDate*)aDate {
    return [NSDate
        dateWithTimeIntervalSinceReferenceDate:CFTimeZoneGetNextDaylightSavingTimeTransition(static_cast<CFTimeZoneRef>(self),
                                                                                             [aDate timeIntervalSinceReferenceDate])];
}

@end
#pragma endregion
