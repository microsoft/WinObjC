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
#include "NSDateComponentsInternal.h"

#include <vector>
#include <functional>

@interface NSCFCalendar : NSCalendar
@end

#pragma region NSCalendarPrototype
@implementation NSCalendarPrototype

PROTOTYPE_CLASS_REQUIRED_IMPLS(NSCFCalendar)

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
static void _individualUnitToDescriptionString(NSCalendarUnit unitFlags, NSCalendarUnit field, char type, std::vector<char>& compDesc) {
    if ((unitFlags & field) != 0) {
        compDesc.push_back(type);
    }
}

// Internal function to convert from bitmask enum into a string of incuded units.
// i.e. (NSCalendarUnitEra | NSCalendarUnitYear_ -> "Gy"
static std::vector<char> _unitFlagsToDescriptionString(NSCalendarUnit unitFlags) {
    std::vector<char> compDesc;
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitEra, 'G', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitYear, 'y', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitQuarter, 'Q', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitMonth, 'M', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitMonth, 'l', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitDay, 'd', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitWeekOfYear, 'w', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitWeekOfMonth, 'W', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitYearForWeekOfYear, 'Y', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitWeekday, 'E', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitWeekdayOrdinal, 'F', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitHour, 'H', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitMinute, 'm', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitSecond, 's', compDesc);
    _individualUnitToDescriptionString(unitFlags, NSCalendarUnitNanosecond, '#', compDesc);
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

@implementation NSCFCalendar

BRIDGED_CLASS_REQUIRED_IMPLS(CFCalendarRef, CFCalendarGetTypeID, NSCalendar, NSCFCalendar)

+ (void)initialize {
    _initAllFlagsComponents();
}

- (NSString*)calendarIdentifier {
    @synchronized(self) {
        return static_cast<NSString*>(CFCalendarGetIdentifier(static_cast<CFCalendarRef>(self)));
    }
}

- (NSUInteger)firstWeekday {
    @synchronized(self) {
        return CFCalendarGetFirstWeekday(static_cast<CFCalendarRef>(self));
    }
}

- (NSUInteger)minimumDaysInFirstWeek {
    @synchronized(self) {
        return CFCalendarGetMinimumDaysInFirstWeek(static_cast<CFCalendarRef>(self));
    }
}

- (NSTimeZone*)timeZone {
    @synchronized(self) {
        return static_cast<NSTimeZone*>(CFAutorelease(CFCalendarCopyTimeZone(static_cast<CFCalendarRef>(self))));
    }
}

- (NSLocale*)locale {
    @synchronized(self) {
        return [static_cast<NSLocale*>(CFCalendarCopyLocale(static_cast<CFCalendarRef>(self))) autorelease];
    }
}

- (void)setFirstWeekday:(NSUInteger)weekday {
    @synchronized(self) {
        CFCalendarSetFirstWeekday(static_cast<CFCalendarRef>(self), weekday);
    }
}

- (void)setMinimumDaysInFirstWeek:(NSUInteger)days {
    @synchronized(self) {
        CFCalendarSetMinimumDaysInFirstWeek(static_cast<CFCalendarRef>(self), days);
    }
}

- (void)setTimeZone:(NSTimeZone*)timeZone {
    @synchronized(self) {
        CFCalendarSetTimeZone(static_cast<CFCalendarRef>(self), static_cast<CFTimeZoneRef>(timeZone));
    }
}

- (void)setLocale:(NSLocale*)locale {
    @synchronized(self) {
        CFCalendarSetLocale(static_cast<CFCalendarRef>(self), static_cast<CFLocaleRef>(locale));
    }
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
    NSDateComponents* weekComponents = [[components copy] autorelease];

    if (weekComponents.week != NSUndefinedDateComponent && weekComponents.weekOfYear == NSUndefinedDateComponent) {
        weekComponents.weekOfYear = weekComponents.week;
    }
    return [NSDate dateWithTimeIntervalSinceReferenceDate:_getAbsoluteTimeFromComponents(self, weekComponents)];
}

- (NSDateComponents*)components:(NSCalendarUnit)unitFlags fromDate:(NSDate*)date {
    THROW_NS_IF_NULL(E_INVALIDARG, date);
    NSDateComponents* allComponents = _getComponentsFromAbsoluteTime(self, [date timeIntervalSinceReferenceDate]);
    NSDateComponents* returnComponents = [[[NSDateComponents alloc] init] autorelease];

    for (int i = 0; i < _countof(s_NSDateComponentsIndividualFlags); i++) {
        if (s_NSDateComponentsIndividualFlags[i] & unitFlags) {
            [returnComponents setValue:[allComponents valueForComponent:s_NSDateComponentsIndividualFlags[i]]
                          forComponent:s_NSDateComponentsIndividualFlags[i]];
        }
    }
    if (unitFlags & NSCalendarUnitMonth) {
        returnComponents.leapMonth = allComponents.isLeapMonth;
    }
    if (unitFlags & NSWeekCalendarUnit) {
        returnComponents.week = allComponents.weekOfYear;
    }

    return returnComponents;
}

- (NSDateComponents*)components:(NSCalendarUnit)unitFlags fromDate:(NSDate*)fromDate toDate:(NSDate*)toDate options:(NSUInteger)options {
    THROW_NS_IF_NULL(E_INVALIDARG, fromDate);
    THROW_NS_IF_NULL(E_INVALIDARG, toDate);
    NSCalendarUnit weekFlags = unitFlags;
    if (weekFlags & NSWeekCalendarUnit) {
        weekFlags |= NSCalendarUnitWeekOfYear;
    }

    std::vector<char> compDesc = _unitFlagsToDescriptionString(weekFlags);

    // _CFCalendarGetComponentDifferenceV requires a bit of a funky compValues layout;
    // It expects an array of int32_t pointers and derefs into that. This is an unneeded
    // level of indirection but play along anyway. Max number of components is 20.
    int32_t intValuesForComponents[20] = {};

    // The values vector will have the descriptor size - 1 spots in it due to the null
    // terminator if its a valid description string.
    std::vector<int32_t*> compValues(compDesc.size() > 1 ? compDesc.size() - 1 : 0);
    for (int i = 0; i < compValues.size(); i++) {
        compValues[i] = &intValuesForComponents[i];
    }

    BOOL res = _CFCalendarGetComponentDifferenceV(static_cast<CFCalendarRef>(self),
                                                  fromDate.timeIntervalSinceReferenceDate,
                                                  toDate.timeIntervalSinceReferenceDate,
                                                  static_cast<CFOptionFlags>(options),
                                                  compDesc.data(),
                                                  compValues.data(),
                                                  compValues.size());
    if (res) {
        NSDateComponents* returnComponents = _descriptionToComponents(self, weekFlags, compValues);
        // Check if week was a part of the original components.
        if (unitFlags & NSWeekCalendarUnit) {
            returnComponents.week = returnComponents.weekOfYear;
            if (!(unitFlags & NSCalendarUnitWeekOfYear)) {
                returnComponents.weekOfYear = NSDateComponentUndefined;
            }
        }
        return returnComponents;
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
    Boolean res = CFCalendarGetTimeRangeOfUnit(static_cast<CFCalendarRef>(self),
                                               static_cast<CFCalendarUnit>(unit),
                                               [date timeIntervalSinceReferenceDate],
                                               &startTime,
                                               timep);
    if (datep != nullptr) {
        *datep = [NSDate dateWithTimeIntervalSinceReferenceDate:startTime];
    }

    return res ? YES : NO;
}

- (NSRange)rangeOfUnit:(NSCalendarUnit)smaller inUnit:(NSCalendarUnit)larger forDate:(NSDate*)date {
    THROW_NS_IF_NULL(E_INVALIDARG, date);
    CFRange range = CFCalendarGetRangeOfUnit(static_cast<CFCalendarRef>(self),
                                             static_cast<CFCalendarUnit>(smaller),
                                             static_cast<CFCalendarUnit>(larger),
                                             date.timeIntervalSinceReferenceDate);

    if (range.location == kCFNotFound) {
        return NSMakeRange(NSNotFound, NSNotFound);
    }

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

static CFAbsoluteTime _getAbsoluteTimeFromComponents(NSCalendar* cal, NSDateComponents* components) {
    THROW_NS_IF_NULL(E_INVALIDARG, components);
    std::vector<int32_t> comps;
    std::vector<char> compDesc;

    _convertComponentsToDescriptionString(components, comps, compDesc);

    NSTimeZone* oldTimeZone = nil;

    // Synchronize on the calendar object so it's never modified multiple times.
    @synchronized(cal) {
        // set the timezone to that of the components if necessary.
        if (components.timeZone) {
            oldTimeZone = cal.timeZone;
            cal.timeZone = components.timeZone;
        }

        CFAbsoluteTime at{};
        BOOL res = _CFCalendarComposeAbsoluteTimeV(static_cast<CFCalendarRef>(cal), &at, compDesc.data(), comps.data(), comps.size());

        // reset the timezone to the old one after forming the date.
        if (components.timeZone) {
            cal.timeZone = oldTimeZone;
        }

        if (res) {
            return at;
        }
    }

    return 0;
}

static std::vector<char> s_compDesc;
static std::vector<int32_t*> s_compValues;
static int32_t s_intValuesForComponents[20] = {};

// Static initializer to create this container just once
static void _initAllFlagsComponents() {
    s_compDesc = _unitFlagsToDescriptionString(s_NSDateComponentsAllFlagOptions);

    // _CFCalendarDecomposeAbsoluteTimeV requires a bit of a funky compValues layout;
    // It expects an array of int32_t pointers and derefs into that. This is an unneeded
    // level of indirection but play along anyway. Max number of components is 20.

    // The values vector will have the descriptor size - 1 spots in it due to the null
    // terminator if its a valid description string.
    static std::vector<int32_t*> tempCompValues(s_compDesc.size() > 1 ? s_compDesc.size() - 1 : 0);
    for (int i = 0; i < tempCompValues.size(); i++) {
        tempCompValues[i] = &s_intValuesForComponents[i];
    }
    s_compValues = std::move(tempCompValues);
}

static NSDateComponents* _getComponentsFromAbsoluteTime(NSCalendar* cal, NSTimeInterval absTime) {
    // Synchronize on the calendar object so as to not stomp any other values here.
    @synchronized(cal) {
        BOOL res = _CFCalendarDecomposeAbsoluteTimeV(static_cast<CFCalendarRef>(cal),
                                                     absTime,
                                                     s_compDesc.data(),
                                                     s_compValues.data(),
                                                     s_compValues.size());

        if (res) {
            return _descriptionToComponents(cal, s_NSDateComponentsAllFlagOptions, s_compValues);
        }
    }

    return nil;
}

// This function is used when the matching components specifies a non mathematical unit to be used.
// For example, if matching components specifies it wants to find the third week of every month, then it does not make sense
// to iterate over dates using the other mathematical units such as hour/day/month.
static NSDate* _validDateInterpretedComponent(NSCalendar* cal,
                                              NSDateComponents* workingComps,
                                              NSDateComponents* matchComps,
                                              BOOL forwardSearch,
                                              NSCalendarUnit interpretiveUnit,
                                              NSCalendarUnit inUnit,
                                              NSCalendarOptions opts) {
    // Create a date object that we will eventually return. This date object handles much of the unit overflow in the CF layer.
    NSDate* workingDate = [cal dateFromComponents:workingComps];
    int sign = forwardSearch ? 1 : -1;

    NSInteger expectedValue = [matchComps valueForComponent:interpretiveUnit];
    NSRange range = [cal rangeOfUnit:interpretiveUnit inUnit:inUnit forDate:workingDate];

    NSDateComponents* updateUnit = [[[NSDateComponents alloc] init] autorelease];
    [updateUnit setValue:sign forComponent:interpretiveUnit];

    // WeekOfMonth has slightly different behavior that will find the first weekday of the weekOfMonth unless otherwise requested.
    // This case will not happen if the original match components is looking for a particular weekday as interpretiveUnit here will never be
    // NSCalendarUnitWeekOfMonth
    if (interpretiveUnit == NSCalendarUnitWeekOfMonth) {
        NSDateComponents* findFirstWeekDay = [[[NSDateComponents alloc] init] autorelease];
        findFirstWeekDay.weekday = 1;
        workingDate = _validDateInterpretedComponent(
            cal, workingComps, findFirstWeekDay, forwardSearch, NSCalendarUnitWeekday, NSWeekCalendarUnit, opts);
        workingComps = [cal components:s_NSDateComponentsAllFlagOptions fromDate:workingDate];

        if ([workingComps valueForComponent:interpretiveUnit] == expectedValue) {
            return workingDate;
        }
    }

    for (int i = 0; i < range.length; i++) {
        workingDate = [cal dateByAddingComponents:updateUnit toDate:workingDate options:opts];

        workingComps = [cal components:s_NSDateComponentsAllFlagOptions fromDate:workingDate];
        if ([workingComps valueForComponent:interpretiveUnit] == expectedValue) {
            return workingDate;
        }
    }

    return workingDate;
}

static NSDate* _validDate(NSCalendar* cal,
                          NSDateComponents* workingComps,
                          NSDateComponents* matchComps,
                          BOOL forwardSearch,
                          NSCalendarUnit currentUnit,
                          NSCalendarUnit interpretiveUnit,
                          NSDate* oldDate,
                          NSCalendarOptions opts) {
    if (interpretiveUnit == 0) {
        return _validDateNormalUnit(cal, workingComps, matchComps, forwardSearch, currentUnit, oldDate, opts);
    } else {
        return _validDateInterpretedComponent(cal, workingComps, matchComps, forwardSearch, interpretiveUnit, currentUnit, opts);
    }
}

static NSDate* _validDateNormalUnit(NSCalendar* cal,
                                    NSDateComponents* workingComps,
                                    NSDateComponents* matchComps,
                                    BOOL forwardSearch,
                                    NSCalendarUnit currentUnit,
                                    NSDate* oldDate,
                                    NSCalendarOptions opts) {
    NSDate* originalDate = [cal dateFromComponents:workingComps];

    int sign = forwardSearch ? 1 : -1;

    NSDateComponents* oldValues = [[[NSDateComponents alloc] init] autorelease];
    for (int i = 0; i < _countof(s_NSDateComponentsIndividualFlags); i++) {
        NSInteger expectedValue = [matchComps valueForComponent:s_NSDateComponentsIndividualFlags[i]];
        NSInteger workingValue = [workingComps valueForComponent:s_NSDateComponentsIndividualFlags[i]];
        if (expectedValue != NSUndefinedDateComponent) {
            [oldValues setValue:workingValue forComponent:s_NSDateComponentsIndividualFlags[i]];
            [workingComps setValue:expectedValue forComponent:s_NSDateComponentsIndividualFlags[i]];
        }
    }

    // Attempt to directly create the matching date using the expected matching components
    if (_isValidDate(cal, workingComps) && ![originalDate isEqualToDate:oldDate]) {
        NSDate* datel = [cal dateFromComponents:workingComps];
        return datel;
    }

    // Otherwise revert to only the original value of the highest unit
    NSInteger oldValue = [oldValues valueForComponent:currentUnit];
    [workingComps setValue:oldValue forComponent:currentUnit];

    // Interesting unit control, the larger unit is always half the smaller.
    // era = year * 2, year = month * 2, month = day * 2, day = hour * 2, hour = minute * 2, minute = second * 2
    NSCalendarUnit unitToUpdate = currentUnit >> 1;
    if (currentUnit == NSCalendarUnitNanosecond) {
        unitToUpdate = NSCalendarUnitSecond;
    }

    NSDate* workingDate = [cal dateFromComponents:workingComps];

    if (unitToUpdate != NSCalendarUnitEra) {
        NSDateComponents* updateUnit = [[[NSDateComponents alloc] init] autorelease];
        [updateUnit setValue:sign forComponent:unitToUpdate];

        workingDate = [cal dateByAddingComponents:updateUnit toDate:workingDate options:opts];
    }

    return workingDate;
}

static NSInteger _boundUnitInUnit(NSCalendarUnit toBind, NSCalendarUnit inUnit, NSInteger value, NSDate* date, NSCalendar* cal) {
    @synchronized(cal) {
        NSRange range = [cal rangeOfUnit:toBind inUnit:inUnit forDate:date];

        if (value < range.location) {
            return range.location;
        } else if (value > NSMaxRange(range) - 1) {
            return NSMaxRange(range) - 1;
        }
        return value;
    }
}

static BOOL _isValidDate(NSCalendar* calendar, NSDateComponents* components) {
    @synchronized(calendar) {
        NSDate* dateThisIs = [calendar dateFromComponents:components];
        NSDateComponents* otherComponents = [calendar components:s_NSDateComponentsAllFlagOptions fromDate:dateThisIs];
        return [components _componentsMatch:otherComponents forUnits:s_NSDateComponentsValidMathematicalFlags];
    }
}

// A system defined retry amount. If a valid date is not found after 55 attempts, avoid spending further resources trying.
// 55 being the number of retries it takes to match correctly to the largest failure combination of interpretted units.
static NSUInteger s_retryAttempts = 55;

- (void)enumerateDatesStartingAfterDate:(NSDate*)start
                     matchingComponents:(NSDateComponents*)comps
                                options:(NSCalendarOptions)opts
                             usingBlock:(void (^)(NSDate*, BOOL, BOOL*))block {
    THROW_NS_IF_NULL(E_INVALIDARG, start);
    THROW_NS_IF_NULL(E_INVALIDARG, comps);
    THROW_NS_IF_FALSE(E_INVALIDARG, (opts != 0));

    BOOL optionsAreInContrast = NO;

    BOOL isOptionsValid = ((opts & NSCalendarMatchPreviousTimePreservingSmallerUnits) != 0);

    if ((opts & NSCalendarMatchNextTimePreservingSmallerUnits) != 0) {
        if (isOptionsValid == NO) {
            isOptionsValid = YES;
        } else {
            optionsAreInContrast = YES;
        }
    }
    if ((opts & NSCalendarMatchNextTime) != 0) {
        if (isOptionsValid == NO) {
            isOptionsValid = YES;
        } else {
            optionsAreInContrast = YES;
        }
    }

    // This is a valid solo option as well as when used in conjunction with the others.
    if (!isOptionsValid) {
        isOptionsValid = ((opts & NSCalendarMatchStrictly) != 0);
    }

    THROW_NS_IF_FALSE_MSG(E_INVALIDARG,
                          (isOptionsValid && !optionsAreInContrast),
                          "Options must specify exactly one of these matching options: NSCalendarMatchPreviousTimePreservingSmallerUnits, "
                          "NSCalendarMatchNextTimePreservingSmallerUnits, NSCalendarMatchNextTime");

    // If the matching components did not specify any particular day when matching for weekOfYear then match the first weekday
    if (comps.weekOfYear != NSUndefinedDateComponent && comps.day == NSUndefinedDateComponent &&
        comps.weekday == NSUndefinedDateComponent) {
        comps = [[comps copy] autorelease];
        [comps setValue:1 forComponent:NSCalendarUnitWeekday];
    }

    NSComparisonResult expectedResult = NSOrderedDescending;
    BOOL searchForwards = !((opts & NSCalendarSearchBackwards));
    if (searchForwards) {
        expectedResult = NSOrderedAscending;
    }

    NSDate* componentDate = [self dateFromComponents:comps];

    // If the matching components contain an invalid date for the direction they're searching
    // then simply don't waste resources searching for something that doesn't exist. The reason
    // this is limited to year is because months/days/minutes/seconds wrap around and can match
    // many different dates no matter which direction a search is made. Year however, is an absolute
    // mathematical time. Searching forward from the year 2000 will never find the year 1950.
    NSComparisonResult isValidYear = [start compare:componentDate];
    if (comps.year != NSUndefinedDateComponent && isValidYear != expectedResult && isValidYear != NSOrderedSame) {
        return;
    }

    BOOL stop = NO;
    NSDate* currentDate = start;
    BOOL lastChance = NO;

    NSCalendarUnit unitFlags = 0;

    // Create components strictly for the numerical representation of a time.
    NSDateComponents* startComps = [self components:s_NSDateComponentsAllFlagOptions fromDate:start];
    NSDateComponents* newComps = [[[NSDateComponents alloc] init] autorelease];
    newComps.day = startComps.day;
    newComps.month = startComps.month;
    newComps.year = startComps.year;
    newComps.era = startComps.era;
    newComps.hour = startComps.hour;
    newComps.minute = startComps.minute;
    newComps.second = startComps.second;
    newComps.nanosecond = startComps.nanosecond;

    NSCalendarUnit mathematicalUnit = 0;
    // Issue 650: NSCalendar Certain Units Need Optimized and Combination of Interpretive Units Match Incorrect Dates
    NSCalendarUnit interpretiveUnit = 0;

    NSDateComponents* smallerComps = [[[NSDateComponents alloc] init] autorelease];
    for (int i = 0; i < _countof(s_NSDateComponentsIndividualFlags); i++) {
        // If a largest unit exists and the matching options does not specify preserving smaller units
        if (mathematicalUnit != 0 && i < NSDateComponentsMathematicalUnitCutoff) {
            if (((opts & NSCalendarMatchPreviousTimePreservingSmallerUnits) || (opts & NSCalendarMatchNextTimePreservingSmallerUnits))) {
                [smallerComps setValue:[startComps valueForComponent:s_NSDateComponentsIndividualFlags[i]]
                          forComponent:s_NSDateComponentsIndividualFlags[i]];
            }
            [newComps setValue:NSUndefinedDateComponent forComponent:s_NSDateComponentsIndividualFlags[i]];
        }

        NSUInteger value = [comps valueForComponent:s_NSDateComponentsIndividualFlags[i]];
        if (value != NSUndefinedDateComponent) {
            NSInteger valToSet = value;

            if (i > 1 && i < NSDateComponentsMathematicalUnitCutoff) {
                valToSet =
                    _boundUnitInUnit(s_NSDateComponentsIndividualFlags[i], s_NSDateComponentsIndividualFlags[i - 1], value, start, self);
            }

            if (i < NSDateComponentsMathematicalUnitCutoff) {
                if (mathematicalUnit == 0) {
                    mathematicalUnit = s_NSDateComponentsIndividualFlags[i];
                }
            } else {
                interpretiveUnit = s_NSDateComponentsIndividualFlags[i];
                switch (interpretiveUnit) {
                    case NSCalendarUnitWeekdayOrdinal:
                        mathematicalUnit = NSCalendarUnitMonth;
                        break;
                    case NSCalendarUnitYearForWeekOfYear:
                        mathematicalUnit = NSCalendarUnitYear;
                        break;
                    case NSCalendarUnitQuarter:
                        mathematicalUnit = NSCalendarUnitMonth;
                        break;
                    case NSCalendarUnitWeekOfYear:
                        mathematicalUnit = NSCalendarUnitYear;
                        break;
                    case NSCalendarUnitWeekOfMonth:
                        mathematicalUnit = NSCalendarUnitMonth;
                        break;
                    case NSCalendarUnitWeekday:
                        mathematicalUnit = NSWeekCalendarUnit;
                        break;
                    default:
                        THROW_NS_HR(E_INVALIDARG);
                }
            }

            [newComps setValue:valToSet forComponent:s_NSDateComponentsIndividualFlags[i]];
            unitFlags |= s_NSDateComponentsIndividualFlags[i];
        }
    }

    NSCalendarUnit currentUnit = mathematicalUnit;
    if (interpretiveUnit != 0) {
        currentUnit = interpretiveUnit;
    }

    // If no component has been set, match based on seconds as default behavior
    if (mathematicalUnit == 0 && interpretiveUnit == 0) {
        mathematicalUnit = NSCalendarUnitSecond;
    }

    // Convert best guess at matching components into an NSTimeInterval
    NSTimeInterval rawtime = _getAbsoluteTimeFromComponents(self, newComps);
    // Create the best guess at a matching date with this time
    NSDate* bestdate = [NSDate dateWithTimeIntervalSinceReferenceDate:rawtime];

    // Recreate the components of this best guessed date as some components may have changed. (Example, day of week)
    newComps = [self components:s_NSDateComponentsAllFlagOptions fromDate:bestdate];

    // Match next time flags stop the matching process on the first best guess
    BOOL stopOnFirstMatch = NO;
    BOOL matchNext = NO;
    if ((opts & NSCalendarMatchNextTime) || (opts & NSCalendarMatchNextTimePreservingSmallerUnits)) {
        matchNext = YES;
        stopOnFirstMatch = YES;
    }
    if (opts & NSCalendarMatchPreviousTimePreservingSmallerUnits) {
        stopOnFirstMatch = YES;
    }
    NSDate* lastdate = start;
    do {
        if ([lastdate compare:bestdate] == expectedResult) {
            lastChance = NO;
            int numIters = 0;
            while (!stopOnFirstMatch && numIters < s_retryAttempts && !([comps _componentsMatch:newComps forUnits:unitFlags])) {
                bestdate = _validDate(self, newComps, comps, searchForwards, mathematicalUnit, interpretiveUnit, lastdate, opts);
                newComps = [self components:s_NSDateComponentsAllFlagOptions fromDate:bestdate];
                numIters++;
            }

            // If stopOnFirstMatch is specified and an exact match is not found after the initial try.
            if (stopOnFirstMatch && !([comps _componentsMatch:newComps forUnits:unitFlags])) {
                // Find the unit that made this match fail.
                NSCalendarUnit highestUnitThatFailed = 0;

                for (int i = 0; i < _countof(s_NSDateComponentsIndividualFlags); i++) {
                    if ((unitFlags & s_NSDateComponentsIndividualFlags[i]) != 0) {
                        NSUInteger val1 = [comps valueForComponent:s_NSDateComponentsIndividualFlags[i]];
                        NSUInteger val2 = [newComps valueForComponent:s_NSDateComponentsIndividualFlags[i]];
                        if (val1 != val2) {
                            highestUnitThatFailed = s_NSDateComponentsIndividualFlags[i];
                            break;
                        }
                    }
                }

                NSDateComponents* oneUnit = [[[NSDateComponents alloc] init] autorelease];

                // If matching does not want the next value then do not update the highest unit.
                [oneUnit setValue:(matchNext ? 1 : 0) forComponent:highestUnitThatFailed];

                if ((opts & NSCalendarMatchPreviousTimePreservingSmallerUnits) || (opts & NSCalendarMatchNextTimePreservingSmallerUnits)) {
                    for (int i = 0; i < _countof(s_NSDateComponentsIndividualFlags); i++) {
                        NSUInteger value = [smallerComps valueForComponent:s_NSDateComponentsIndividualFlags[i]];
                        if (value != NSUndefinedDateComponent) {
                            [oneUnit setValue:value forComponent:s_NSDateComponentsIndividualFlags[i]];
                        }
                    }
                }

                bestdate = [self dateByAddingComponents:oneUnit toDate:bestdate options:opts];
            }

            // If the maximum attempts have been tried and no valid match has been found
            if (numIters == s_retryAttempts || ([lastdate compare:bestdate] != expectedResult)) {
                bestdate = nil;
            }

            // Call the block that was passed in
            block(bestdate, [comps _componentsMatch:newComps forUnits:unitFlags], &stop);

            // Don't continue matching if no valid match was found
            if (bestdate == nil) {
                return;
            }

            lastdate = bestdate;
            bestdate = _validDate(self, newComps, comps, searchForwards, mathematicalUnit, interpretiveUnit, lastdate, opts);
        } else {
            if (lastChance) {
                if (opts & NSCalendarMatchStrictly) {
                    block(nil, NO, &stop);
                }
                return;
            } else {
                lastdate = bestdate;
                bestdate = _validDate(self, newComps, comps, searchForwards, mathematicalUnit, interpretiveUnit, lastdate, opts);
            }
            lastChance = YES;
        }
        if (bestdate == nil) {
            break;
        }
        newComps = [self components:s_NSDateComponentsAllFlagOptions fromDate:bestdate];
    } while (!stop);
}

- (BOOL)nextWeekendStartDate:(NSDate* _Nullable*)datep
                    interval:(NSTimeInterval*)tip
                     options:(NSCalendarOptions)options
                   afterDate:(NSDate*)date {
    _CFCalendarWeekendRange range;
    // Call CF to get next weekend
    if (_CFCalendarGetNextWeekend(static_cast<CFCalendarRef>(self), &range)) {
        NSDateComponents* comp = [[[NSDateComponents alloc] init] autorelease];

        comp.weekday = range.start;
        NSDate* nextStart = [self nextDateAfterDate:date matchingComponents:comp options:(options | NSCalendarMatchNextTime)];

        // Create a date using CF's next weekend time
        NSDate* start = [nextStart dateByAddingTimeInterval:(range.onsetTime)];
        comp.weekday = range.end;

        NSDate* nextEnd = [self nextDateAfterDate:start matchingComponents:comp options:(options | NSCalendarMatchNextTime)];
        NSComparisonResult expectedResult = NSOrderedAscending;
        if ((options & NSCalendarSearchBackwards) != 0) {
            expectedResult = NSOrderedDescending;
        }

        // Ensure that the returned range creates a valid end date
        if ([start compare:nextEnd] == expectedResult) {
            // If we found a valid weekend date then return these values.
            if (datep != nullptr) {
                *datep = start;
            }
            // Time interval should point to the first day after the weekend
            // Use rangeof day to calculate how much time is in the last day of the weekend + range's time interval to the start of the last
            // day in the weekend.
            NSTimeInterval difference = [nextEnd timeIntervalSinceReferenceDate] - [start timeIntervalSinceReferenceDate];
            if (tip != nullptr) {
                *tip = difference + range.ceaseTime;
            }
            return YES;
        }

        if (datep != nullptr) {
            *datep = nil;
        }
        if (tip != nullptr) {
            *tip = 0;
        }
    }
    return NO;
}

- (BOOL)isDateInWeekend:(NSDate*)date {
    // CFCalendarIsWeekend expects that the raw time passed in is in reference to 1970 as ICU uses that as their epoch.
    return _CFCalendarIsWeekend(static_cast<CFCalendarRef>(self), date.timeIntervalSince1970) == true ? YES : NO;
}

@end
#pragma endregion
