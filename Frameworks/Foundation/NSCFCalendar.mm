//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2016 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#include "Starboard.h"
#include "CFHelpers.h"
#include "CFFoundationInternal.h"
#include <CoreFoundation/CFCalendar.h>
#include "NSCFCalendar.h"
#include "BridgeHelpers.h"
#include "ForFoundationOnly.h"

#include <vector>
#include <functional>

#pragma region NSCalendarPrototype
@implementation NSCalendarPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS

- (instancetype)initWithCalendarIdentifier:(NSString*)identifier {
    return reinterpret_cast<NSCalendarPrototype*>(
        static_cast<NSCalendar*>(CFCalendarCreateWithIdentifier(kCFAllocatorDefault, static_cast<CFStringRef>(identifier))));
}

@end

#pragma endregion

#pragma region NSCFCalendar

// Internal function to convert from NSDateComponents's strongly typed (i.e. .era = 1) int values into a description string of what
// components are indluded (i.e. 'E' for era). This helper adds a single value to the
static void _convertComponentsToDescriptionString(int32_t component,
                                                  char type,
                                                  std::vector<int32_t>& compValues,
                                                  std::vector<char>& compDesc) {
    if (component != NSDateComponentUndefined) {
        compValues.push_back(component);
        compDesc.push_back(type);
    }
}

// Internal function to convert from NSDateComponents's strongly typed (i.e. .era = 1) int values into a description string + value array of
// what components are included (i.e. string.push_back('E') and values.push_back(1) for era).
static void _convertComponentsToDescriptionString(NSDateComponents* comps, std::vector<int32_t>& compValues, std::vector<char>& compDesc) {
    _convertComponentsToDescriptionString(comps.era, 'E', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.year, 'y', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.quarter, 'Q', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.weekOfYear, 'w', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.weekOfMonth, 'W', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.yearForWeekOfYear, 'Y', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.weekday, 'E', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.weekdayOrdinal, 'F', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.month, 'M', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.leapMonth ? 1 : 0, 'L', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.day, 'd', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.hour, 'H', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.minute, 'm', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.second, 's', compValues, compDesc);
    _convertComponentsToDescriptionString(comps.nanosecond, '#', compValues, compDesc);

    compDesc.push_back('\0');

    return;
}

// Internal function to convert from bitmask enum into a string of incuded units.
// i.e. (NSCalendarUnitEra | NSCalendarUnitYear_ -> "Gy". This helpers adds sigle unit.
static void _unitFlagsToDescriptionString(NSCalendarUnit unitFlags, NSCalendarUnit field, char type, std::vector<char>& compDesc) {
    if ((unitFlags & field) != 0) {
        compDesc.push_back(type);
    }
}

// Internal function to convert from bitmask enum into a string of incuded units.
// i.e. (NSCalendarUnitEra | NSCalendarUnitYear_ -> "Gy"
static std::vector<char> _unitFlagsToDescriptionString(NSCalendarUnit unitFlags) {
    std::vector<char> compDesc;
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitEra, 'G', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitYear, 'y', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitQuarter, 'Q', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitMonth, 'M', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitMonth, 'l', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitDay, 'd', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitWeekOfYear, 'w', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitWeekOfMonth, 'W', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitYearForWeekOfYear, 'Y', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitWeekday, 'E', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitWeekdayOrdinal, 'F', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitHour, 'H', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitMinute, 'm', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitSecond, 's', compDesc);
    _unitFlagsToDescriptionString(unitFlags, NSCalendarUnitNanosecond, '#', compDesc);
    compDesc.push_back('\0');
    return compDesc;
}

// Internal function to convert from a unit bitmask into a NSDateComponents.
// This function sets single date component item.
static void _setComp(NSCalendarUnit unitFlags,
                     NSCalendarUnit field,
                     const std::vector<int32_t*>& compValues,
                     int& compIndex,
                     std::function<void(int32_t)> setter) {
    if ((unitFlags & field) != 0) {
        setter(*compValues[compIndex]);
        compIndex += 1;
    }
}

// Internal function to convert from a unit bitmask into a NSDateComponents. Note that the order here *must* match that of
// _unitFlagsToDescriptionString as this function is used to reverse the process of the above and assumes that the value array
// is in the order of the above created description string.
static NSDateComponents* _descriptionToComponents(NSCalendar* self, NSCalendarUnit unitFlags, const std::vector<int32_t*>& compValues) {
    int compIdx = 0;
    NSDateComponents* comps = [[NSDateComponents new] autorelease];

    _setComp(unitFlags, NSCalendarUnitEra, compValues, compIdx, [comps](int32_t value) { comps.era = value; });
    _setComp(unitFlags, NSCalendarUnitYear, compValues, compIdx, [comps](int32_t value) { comps.year = value; });
    _setComp(unitFlags, NSCalendarUnitQuarter, compValues, compIdx, [comps](int32_t value) { comps.quarter = value; });
    _setComp(unitFlags, NSCalendarUnitMonth, compValues, compIdx, [comps](int32_t value) { comps.month = value; });
    _setComp(unitFlags, NSCalendarUnitMonth, compValues, compIdx, [comps](int32_t value) { comps.leapMonth = (value != 0); });
    _setComp(unitFlags, NSCalendarUnitDay, compValues, compIdx, [comps](int32_t value) { comps.day = value; });
    _setComp(unitFlags, NSCalendarUnitWeekOfYear, compValues, compIdx, [comps](int32_t value) { comps.weekOfYear = value; });
    _setComp(unitFlags, NSCalendarUnitWeekOfMonth, compValues, compIdx, [comps](int32_t value) { comps.weekOfMonth = value; });
    _setComp(unitFlags, NSCalendarUnitYearForWeekOfYear, compValues, compIdx, [comps](int32_t value) { comps.yearForWeekOfYear = value; });
    _setComp(unitFlags, NSCalendarUnitWeekday, compValues, compIdx, [comps](int32_t value) { comps.weekday = value; });
    _setComp(unitFlags, NSCalendarUnitWeekdayOrdinal, compValues, compIdx, [comps](int32_t value) { comps.weekdayOrdinal = value; });
    _setComp(unitFlags, NSCalendarUnitHour, compValues, compIdx, [comps](int32_t value) { comps.hour = value; });
    _setComp(unitFlags, NSCalendarUnitMinute, compValues, compIdx, [comps](int32_t value) { comps.minute = value; });
    _setComp(unitFlags, NSCalendarUnitSecond, compValues, compIdx, [comps](int32_t value) { comps.second = value; });
    _setComp(unitFlags, NSCalendarUnitNanosecond, compValues, compIdx, [comps](int32_t value) { comps.nanosecond = value; });

    // Units are not actually in CF. Handle separately.
    if ((unitFlags & NSCalendarUnitCalendar) != 0) {
        comps.calendar = self;
    }

    if ((unitFlags & NSCalendarUnitTimeZone) != 0) {
        comps.timeZone = self.timeZone;
    }

    return comps;
}

@interface NSCFCalendar : NSCalendar
@end

@implementation NSCFCalendar

BRIDGED_CLASS_REQUIRED_IMPLS(CFCalendarRef, CFCalendarGetTypeID, NSCalendar, NSCFCalendar)

- (NSString*)calendarIdentifier {
    return static_cast<NSString*>(CFCalendarGetIdentifier(static_cast<CFCalendarRef>(self)));
}

- (NSUInteger)firstWeekday {
    return CFCalendarGetFirstWeekday(static_cast<CFCalendarRef>(self));
}

- (NSUInteger)minimumDaysInFirstWeek {
    return CFCalendarGetMinimumDaysInFirstWeek(static_cast<CFCalendarRef>(self));
}

- (NSTimeZone*)timeZone {
    return static_cast<NSTimeZone*>(CFAutorelease(CFCalendarCopyTimeZone(static_cast<CFCalendarRef>(self))));
}

- (NSLocale*)locale {
    return [static_cast<NSLocale*>(CFCalendarCopyLocale(static_cast<CFCalendarRef>(self))) autorelease];
}

- (void)setFirstWeekday:(NSUInteger)weekday {
    CFCalendarSetFirstWeekday(static_cast<CFCalendarRef>(self), weekday);
}

- (void)setMinimumDaysInFirstWeek:(NSUInteger)days {
    CFCalendarSetMinimumDaysInFirstWeek(static_cast<CFCalendarRef>(self), days);
}

- (void)setTimeZone:(NSTimeZone*)timeZone {
    CFCalendarSetTimeZone(static_cast<CFCalendarRef>(self), static_cast<CFTimeZoneRef>(timeZone));
}

- (void)setLocale:(NSLocale*)locale {
    CFCalendarSetLocale(static_cast<CFCalendarRef>(self), static_cast<CFLocaleRef>(locale));
}

- (NSDate*)dateByAddingComponents:(NSDateComponents*)components toDate:(NSDate*)toDate options:(NSUInteger)options {
    THROW_NS_IF_NULL(E_INVALIDARG, components);
    THROW_NS_IF_NULL(E_INVALIDARG, toDate);

    CFAbsoluteTime at = [toDate timeIntervalSinceReferenceDate];

    std::vector<int32_t> comps;
    std::vector<char> compDesc;

    _convertComponentsToDescriptionString(components, comps, compDesc);

    BOOL res = _CFCalendarAddComponentsV(static_cast<CFCalendarRef>(self),
                                         &at,
                                         static_cast<CFOptionFlags>(options),
                                         compDesc.data(),
                                         comps.data(),
                                         comps.size());

    if (res) {
        return [NSDate dateWithTimeIntervalSinceReferenceDate:at];
    }

    return nil;
}

- (NSDate*)dateFromComponents:(NSDateComponents*)components {
    THROW_NS_IF_NULL(E_INVALIDARG, components);

    std::vector<int32_t> comps;
    std::vector<char> compDesc;

    _convertComponentsToDescriptionString(components, comps, compDesc);

    NSTimeZone* oldTimeZone = nil;

    // set the timezone to that of the components if necessary.
    if (components.timeZone) {
        oldTimeZone = self.timeZone;
        self.timeZone = components.timeZone;
    }

    CFAbsoluteTime at{};
    BOOL res = _CFCalendarComposeAbsoluteTimeV(static_cast<CFCalendarRef>(self), &at, compDesc.data(), comps.data(), comps.size());

    // reset the timezone to the old one after forming the date.
    if (components.timeZone) {
        self.timeZone = oldTimeZone;
    }

    if (res) {
        return [NSDate dateWithTimeIntervalSinceReferenceDate:at];
    }

    return nil;
}

- (NSDateComponents*)components:(NSUInteger)unitFlags fromDate:(NSDate*)date {
    THROW_NS_IF_NULL(E_INVALIDARG, date);

    std::vector<char> compDesc = _unitFlagsToDescriptionString(unitFlags);

    // _CFCalendarDecomposeAbsoluteTimeV requires a bit of a funky compValues layout;
    // It expects an array of int32_t pointers and derefs into that. This is an unneeded
    // level of indirection but play along anyway. Max number of components is 20.
    int32_t ints[20] = {};

    // The values vector will have the descriptor size - 1 spots in it due to the null
    // terminator if its a valid description string.
    std::vector<int32_t*> compValues(compDesc.size() > 1 ? compDesc.size() - 1 : 0);
    for (int i = 0; i < compValues.size(); i++) {
        compValues[i] = &ints[i];
    }

    BOOL res = _CFCalendarDecomposeAbsoluteTimeV(static_cast<CFCalendarRef>(self),
                                                 [date timeIntervalSinceReferenceDate],
                                                 compDesc.data(),
                                                 compValues.data(),
                                                 compValues.size());

    if (res) {
        return _descriptionToComponents(self, unitFlags, compValues);
    }

    return nil;
}

- (NSDateComponents*)components:(NSUInteger)unitFlags fromDate:(NSDate*)fromDate toDate:(NSDate*)toDate options:(NSUInteger)options {
    THROW_NS_IF_NULL(E_INVALIDARG, fromDate);
    THROW_NS_IF_NULL(E_INVALIDARG, toDate);

    std::vector<char> compDesc = _unitFlagsToDescriptionString(unitFlags);

    // _CFCalendarGetComponentDifferenceV requires a bit of a funky compValues layout;
    // It expects an array of int32_t pointers and derefs into that. This is an unneeded
    // level of indirection but play along anyway. Max number of components is 20.
    int32_t ints[20] = {};

    // The values vector will have the descriptor size - 1 spots in it due to the null
    // terminator if its a valid description string.
    std::vector<int32_t*> compValues(compDesc.size() > 1 ? compDesc.size() - 1 : 0);
    for (int i = 0; i < compValues.size(); i++) {
        compValues[i] = &ints[i];
    }

    BOOL res = _CFCalendarGetComponentDifferenceV(static_cast<CFCalendarRef>(self),
                                                  fromDate.timeIntervalSinceReferenceDate,
                                                  toDate.timeIntervalSinceReferenceDate,
                                                  static_cast<CFOptionFlags>(options),
                                                  compDesc.data(),
                                                  compValues.data(),
                                                  compValues.size());
    if (res) {
        return _descriptionToComponents(self, unitFlags, compValues);
    }

    return nil;
}

- (NSUInteger)ordinalityOfUnit:(NSCalendarUnit)inUnit inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date {
    THROW_NS_IF_NULL(E_INVALIDARG, date);

    return CFCalendarGetOrdinalityOfUnit(static_cast<CFCalendarRef>(self),
                                         static_cast<CFCalendarUnit>(inUnit),
                                         static_cast<CFCalendarUnit>(larger),
                                         [date timeIntervalSinceReferenceDate]);
}

- (BOOL)rangeOfUnit:(NSCalendarUnit)unit startDate:(NSDate* _Nullable*)datep interval:(NSTimeInterval*)timep forDate:(NSDate*)date {
    THROW_NS_IF_NULL(E_INVALIDARG, date);

    CFAbsoluteTime startTime{};
    if (datep) {
        startTime = [*datep timeIntervalSinceReferenceDate];
    }

    Boolean res = CFCalendarGetTimeRangeOfUnit(static_cast<CFCalendarRef>(self),
                                               static_cast<CFCalendarUnit>(unit),
                                               [date timeIntervalSinceReferenceDate],
                                               datep ? &startTime : nullptr,
                                               timep);

    return res ? YES : NO;
}

- (NSRange)rangeOfUnit:(NSCalendarUnit)smaller inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date {
    THROW_NS_IF_NULL(E_INVALIDARG, date);

    CFRange range = CFCalendarGetRangeOfUnit(static_cast<CFCalendarRef>(self),
                                             static_cast<CFCalendarUnit>(smaller),
                                             static_cast<CFCalendarUnit>(larger),
                                             [date timeIntervalSinceReferenceDate]);
    return NSMakeRange(range.location, range.length);
}

- (NSRange)maximumRangeOfUnit:(NSCalendarUnit)unit {
    CFRange range = CFCalendarGetMaximumRangeOfUnit(static_cast<CFCalendarRef>(self), static_cast<CFCalendarUnit>(unit));
    return NSMakeRange(range.location, range.length);
}

- (NSRange)minimumRangeOfUnit:(NSCalendarUnit)unit {
    CFRange range = CFCalendarGetMinimumRangeOfUnit(static_cast<CFCalendarRef>(self), static_cast<CFCalendarUnit>(unit));
    return NSMakeRange(range.location, range.length);
}

@end
#pragma endregion
