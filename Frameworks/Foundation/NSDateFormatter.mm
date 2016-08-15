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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#include "Starboard.h"
#include "StubReturn.h"

#import <CoreFoundation/CFDateFormatter.h>
#import <Foundation/Foundation.h>
#import <NSLocaleInternal.h>

#include <functional>
#include <string>
#include <array>
#include "LoggingNative.h"
#include "StringHelpers.h"

void _copyPropertiesToFormatter(CFDateFormatterRef source, CFDateFormatterRef destination) {
    static std::array<CFStringRef, 29> properties{ kCFDateFormatterIsLenient,
                                                   kCFDateFormatterTimeZone,
                                                   kCFDateFormatterCalendarName,
                                                   kCFDateFormatterDefaultFormat,
                                                   kCFDateFormatterTwoDigitStartDate,
                                                   kCFDateFormatterDefaultDate,
                                                   kCFDateFormatterCalendar,
                                                   kCFDateFormatterEraSymbols,
                                                   kCFDateFormatterMonthSymbols,
                                                   kCFDateFormatterShortMonthSymbols,
                                                   kCFDateFormatterWeekdaySymbols,
                                                   kCFDateFormatterShortWeekdaySymbols,
                                                   kCFDateFormatterAMSymbol,
                                                   kCFDateFormatterPMSymbol,
                                                   kCFDateFormatterLongEraSymbols,
                                                   kCFDateFormatterVeryShortMonthSymbols,
                                                   kCFDateFormatterStandaloneMonthSymbols,
                                                   kCFDateFormatterShortStandaloneMonthSymbols,
                                                   kCFDateFormatterVeryShortStandaloneMonthSymbols,
                                                   kCFDateFormatterVeryShortWeekdaySymbols,
                                                   kCFDateFormatterStandaloneWeekdaySymbols,
                                                   kCFDateFormatterShortStandaloneWeekdaySymbols,
                                                   kCFDateFormatterVeryShortStandaloneWeekdaySymbols,
                                                   kCFDateFormatterQuarterSymbols,
                                                   kCFDateFormatterShortQuarterSymbols,
                                                   kCFDateFormatterStandaloneQuarterSymbols,
                                                   kCFDateFormatterShortStandaloneQuarterSymbols,
                                                   kCFDateFormatterGregorianStartDate,
                                                   kCFDateFormatterDoesRelativeDateFormattingKey };

    for (const auto& property : properties) {
        CFTypeRef value = CFAutorelease(CFDateFormatterCopyProperty(source, property));

        if (value) {
            CFDateFormatterSetProperty(destination, property, value);
        }
    }
}

@implementation NSDateFormatter {
    woc::unique_cf<CFDateFormatterRef> _cfDateFormatter;
}

/**
 @Status Interoperable
*/
+ (NSString*)dateFormatFromTemplate:(NSString*)dateTemplate options:(NSUInteger)options locale:(NSLocale*)locale {
    return static_cast<NSString*>(CFAutorelease(CFDateFormatterCreateDateFormatFromTemplate(kCFAllocatorSystemDefault,
                                                                                            static_cast<CFStringRef>(dateTemplate),
                                                                                            options,
                                                                                            static_cast<CFLocaleRef>(locale))));
}

static NSDateFormatterBehavior s_defaultFormatterBehavior = NSDateFormatterBehaviorDefault;

/**
 @Status Interoperable
*/
+ (NSDateFormatterBehavior)defaultFormatterBehavior {
    return s_defaultFormatterBehavior;
}

/**
 @Status Caveat
 @Notes Setting this does not affect NSDateFormatter in the current implementation.
*/
+ (void)setDefaultFormatterBehavior:(NSDateFormatterBehavior)behavior {
    s_defaultFormatterBehavior = behavior;
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    return [self initWithDateFormat:@"" allowNaturalLanguage:NO];
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    NSDateFormatter* copy = [super copyWithZone:zone];

    woc::unique_cf<CFDateFormatterRef> formatterCopy(CFDateFormatterCreate(nullptr,
                                                                           CFDateFormatterGetLocale(_cfDateFormatter.get()),
                                                                           CFDateFormatterGetDateStyle(_cfDateFormatter.get()),
                                                                           CFDateFormatterGetTimeStyle(_cfDateFormatter.get())));
    _copyPropertiesToFormatter(_cfDateFormatter.get(), formatterCopy.get());
    copy->_cfDateFormatter.reset(formatterCopy.release());

    return copy;
}

/**
 @Status Caveat
 @Notes allowNaturalLanguage parameter not supported
*/
- (instancetype)initWithDateFormat:(NSString*)format allowNaturalLanguage:(BOOL)flag {
    return [self initWithDateFormat:format allowNaturalLanguage:flag locale:[NSLocale currentLocale]];
}

/**
 @Status Caveat
 @Notes allowNaturalLanguage parameter not supported
*/
- (instancetype)initWithDateFormat:(NSString*)format allowNaturalLanguage:(BOOL)flag locale:(NSLocale*)locale {
    if (flag == YES) {
        [self release];
        UNIMPLEMENTED_WITH_MSG("allowNaturalLanguage is unimplemented for initWithDateFormat");
        return nil;
    }

    if (self = [super init]) {
        _cfDateFormatter.reset(
            CFDateFormatterCreate(nullptr, static_cast<CFLocaleRef>(locale), kCFDateFormatterNoStyle, kCFDateFormatterNoStyle));
        CFDateFormatterSetFormat(_cfDateFormatter.get(), static_cast<CFStringRef>(format));
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)setCalendar:(NSCalendar*)cal {
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterCalendar, reinterpret_cast<CFTypeRef>(cal));
}

/**
 @Status Interoperable
*/
- (NSCalendar*)calendar {
    return (NSCalendar*)(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterCalendar)));
}

/**
 @Status Interoperable
*/
- (void)setTimeZone:(NSTimeZone*)zone {
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterTimeZone, reinterpret_cast<CFTypeRef>(zone));
}

/**
 @Status Interoperable
*/
- (NSTimeZone*)timeZone {
    return (NSTimeZone*)(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterTimeZone)));
}

/**
 @Status Interoperable
*/
- (void)setLocale:(NSLocale*)locale {
    woc::unique_cf<CFDateFormatterRef> formatterCopy(CFDateFormatterCreate(nullptr,
                                                                           static_cast<CFLocaleRef>(locale),
                                                                           CFDateFormatterGetDateStyle(_cfDateFormatter.get()),
                                                                           CFDateFormatterGetTimeStyle(_cfDateFormatter.get())));
    _copyPropertiesToFormatter(_cfDateFormatter.get(), formatterCopy.get());
    _cfDateFormatter.reset(formatterCopy.release());
}

/**
 @Status Interoperable
*/
- (NSLocale*)locale {
    return static_cast<NSLocale*>(CFDateFormatterGetLocale(_cfDateFormatter.get()));
}

/**
 @Status Interoperable
*/
- (void)setLenient:(BOOL)lenient {
    CFBooleanRef isLenient = lenient ? kCFBooleanTrue : kCFBooleanFalse;
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterIsLenient, reinterpret_cast<CFTypeRef>(isLenient));
}

/**
 @Status Interoperable
*/
- (BOOL)isLenient {
    return CFBooleanGetValue(
        reinterpret_cast<CFBooleanRef>(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterIsLenient))));
}

/**
 @Status Interoperable
*/
- (void)setDateFormat:(NSString*)format {
    CFDateFormatterSetFormat(_cfDateFormatter.get(), static_cast<CFStringRef>(format));
}

/**
 @Status Interoperable
*/
- (NSString*)dateFormat {
    return static_cast<NSString*>(CFDateFormatterGetFormat(_cfDateFormatter.get()));
}

/**
 @Status Interoperable
*/
- (void)setDateStyle:(NSDateFormatterStyle)style {
    woc::unique_cf<CFDateFormatterRef> formatterCopy(CFDateFormatterCreate(nullptr,
                                                                           CFDateFormatterGetLocale(_cfDateFormatter.get()),
                                                                           static_cast<CFDateFormatterStyle>(style),
                                                                           CFDateFormatterGetTimeStyle(_cfDateFormatter.get())));
    _copyPropertiesToFormatter(_cfDateFormatter.get(), formatterCopy.get());
    _cfDateFormatter.reset(formatterCopy.release());
}

/**
 @Status Interoperable
*/
- (NSDateFormatterStyle)dateStyle {
    return static_cast<NSDateFormatterStyle>(CFDateFormatterGetDateStyle(_cfDateFormatter.get()));
}

/**
 @Status Interoperable
*/
- (void)setTimeStyle:(NSDateFormatterStyle)style {
    woc::unique_cf<CFDateFormatterRef> formatterCopy(CFDateFormatterCreate(nullptr,
                                                                           CFDateFormatterGetLocale(_cfDateFormatter.get()),
                                                                           CFDateFormatterGetDateStyle(_cfDateFormatter.get()),
                                                                           static_cast<CFDateFormatterStyle>(style)));
    _copyPropertiesToFormatter(_cfDateFormatter.get(), formatterCopy.get());
    _cfDateFormatter.reset(formatterCopy.release());
}

/**
 @Status Interoperable
*/
- (NSDateFormatterStyle)timeStyle {
    return static_cast<NSDateFormatterStyle>(CFDateFormatterGetTimeStyle(_cfDateFormatter.get()));
}

/**
 @Status Interoperable
*/
- (NSString*)stringFromDate:(NSDate*)date {
    return static_cast<NSString*>(
        CFAutorelease(CFDateFormatterCreateStringWithDate(nullptr, _cfDateFormatter.get(), static_cast<CFDateRef>(date))));
}

/**
 @Status Interoperable
 */
+ (NSString*)localizedStringFromDate:(NSDate*)date dateStyle:(NSDateFormatterStyle)dateStyle timeStyle:(NSDateFormatterStyle)timeStyle {
    woc::unique_cf<CFDateFormatterRef> cfFormatter(CFDateFormatterCreate(nullptr,
                                                                         static_cast<CFLocaleRef>(CFAutorelease(CFLocaleCopyCurrent())),
                                                                         static_cast<CFDateFormatterStyle>(dateStyle),
                                                                         static_cast<CFDateFormatterStyle>(timeStyle)));
    return static_cast<NSString*>(
        CFAutorelease(CFDateFormatterCreateStringWithDate(nullptr, cfFormatter.get(), static_cast<CFDateRef>(date))));
}

/**
 @Status Interoperable
*/
- (NSDate*)dateFromString:(NSString*)str {
    CFRange range = CFRange{ 0, [str length] };
    return static_cast<NSDate*>(
        CFAutorelease(CFDateFormatterCreateDateFromString(nullptr, _cfDateFormatter.get(), static_cast<CFStringRef>(str), &range)));
}

/**
 @Status Interoperable
*/
- (BOOL)getObjectValue:(out id _Nullable*)outObj forString:(id)str errorDescription:(out NSString* _Nullable*)err {
    if (err) {
        *err = nil;
    }

    if (outObj) {
        *outObj = [self dateFromString:str];
    }

    return TRUE;
}

/**
 @Status Interoperable
*/
- (NSString*)stringForObjectValue:(NSObject*)object {
    if ([object isKindOfClass:[NSDate class]]) {
        return [self stringFromDate:(NSDate*)object];
    } else {
        return nil;
    }
}

/**
 @Status Interoperable
*/
- (void)setAMSymbol:(NSString*)symbol {
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterAMSymbol, reinterpret_cast<CFTypeRef>(symbol));
}

/**
 @Status Interoperable
*/
- (NSString*)AMSymbol {
    return (NSString*)(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterAMSymbol)));
}

/**
 @Status Interoperable
*/
- (void)setPMSymbol:(NSString*)symbol {
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterPMSymbol, reinterpret_cast<CFTypeRef>(symbol));
}

/**
 @Status Interoperable
*/
- (NSString*)PMSymbol {
    return (NSString*)(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterPMSymbol)));
}

/**
 @Status Interoperable
*/
- (void)setShortStandaloneWeekdaySymbols:(NSArray*)symbols {
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterShortStandaloneWeekdaySymbols, reinterpret_cast<CFTypeRef>(symbols));
}

/**
 @Status Interoperable
*/
- (NSArray*)shortStandaloneWeekdaySymbols {
    return (NSArray*)(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterShortStandaloneWeekdaySymbols)));
}

/**
 @Status Interoperable
*/
- (void)setWeekdaySymbols:(NSArray*)symbols {
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterWeekdaySymbols, reinterpret_cast<CFTypeRef>(symbols));
}

/**
 @Status Interoperable
*/
- (NSArray*)weekdaySymbols {
    return (NSArray*)(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterWeekdaySymbols)));
}

/**
 @Status Interoperable
*/
- (void)setShortWeekdaySymbols:(NSArray*)symbols {
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterShortWeekdaySymbols, reinterpret_cast<CFTypeRef>(symbols));
}

/**
 @Status Interoperable
*/
- (NSArray*)shortWeekdaySymbols {
    return (NSArray*)(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterShortWeekdaySymbols)));
}

/**
 @Status Interoperable
*/
- (void)setStandaloneWeekdaySymbols:(NSArray*)symbols {
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterStandaloneWeekdaySymbols, reinterpret_cast<CFTypeRef>(symbols));
}

/**
 @Status Interoperable
*/
- (NSArray*)standaloneWeekdaySymbols {
    return (NSArray*)(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterStandaloneWeekdaySymbols)));
}

/**
 @Status Interoperable
*/
- (void)setStandaloneMonthSymbols:(NSArray*)symbols {
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterStandaloneMonthSymbols, reinterpret_cast<CFTypeRef>(symbols));
}

/**
 @Status Interoperable
*/
- (NSArray*)standaloneMonthSymbols {
    return (NSArray*)(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterStandaloneMonthSymbols)));
}

/**
 @Status Interoperable
*/
- (void)setMonthSymbols:(NSArray*)symbols {
    CFDateFormatterSetProperty(_cfDateFormatter.get(), kCFDateFormatterMonthSymbols, reinterpret_cast<CFTypeRef>(symbols));
}

/**
 @Status Interoperable
*/
- (NSArray*)monthSymbols {
    return (NSArray*)(CFAutorelease(CFDateFormatterCopyProperty(_cfDateFormatter.get(), kCFDateFormatterMonthSymbols)));
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)getObjectValue:(id _Nullable*)obj forString:(NSString*)string range:(NSRange*)rangep error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
