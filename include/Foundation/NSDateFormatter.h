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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

#import <Foundation/NSFormatter.h>

@class NSDate;
@class NSString;
@class NSCalendar;
@class NSLocale;
@class NSTimeZone;
@class NSArray;

#import <Foundation/NSError.h>
#import <CoreFoundation/CFDateFormatter.h>
typedef enum {
    NSDateFormatterNoStyle = kCFDateFormatterNoStyle,
    NSDateFormatterShortStyle = kCFDateFormatterShortStyle,
    NSDateFormatterMediumStyle = kCFDateFormatterMediumStyle,
    NSDateFormatterLongStyle = kCFDateFormatterLongStyle,
    NSDateFormatterFullStyle = kCFDateFormatterFullStyle
} NSDateFormatterStyle;
typedef enum {
    NSDateFormatterBehaviorDefault = 0,
    NSDateFormatterBehavior10_0 = 1000,
    NSDateFormatterBehavior10_4 = 1040,
} NSDateFormatterBehavior;

FOUNDATION_EXPORT_CLASS
@interface NSDateFormatter : NSFormatter <NSCoding, NSCopying>
- (NSDate*)dateFromString:(NSString*)string;
- (NSString*)stringFromDate:(NSDate*)date;
+ (NSString*)localizedStringFromDate:(NSDate*)date dateStyle:(NSDateFormatterStyle)dateStyle timeStyle:(NSDateFormatterStyle)timeStyle;
- (BOOL)getObjectValue:(id _Nullable*)obj forString:(NSString*)string range:(NSRange*)rangep error:(NSError* _Nullable*)error STUB_METHOD;
- (NSString*)stringForObjectValue:(id)obj;

@property BOOL generatesCalendarDates;
@property (copy) NSString* dateFormat;
@property NSDateFormatterStyle dateStyle;
@property NSDateFormatterStyle timeStyle;

+ (NSString*)dateFormatFromTemplate:(NSString*)templateObj options:(NSUInteger)opts locale:(NSLocale*)locale;
@property (copy) NSCalendar* calendar;
@property (copy) NSDate* defaultDate;
@property (copy) NSLocale* locale;
@property (copy) NSTimeZone* timeZone;
@property (copy) NSDate* twoDigitStartDate;
@property (copy) NSDate* gregorianStartDate;
@property NSDateFormatterBehavior formatterBehavior;
+ (NSDateFormatterBehavior)defaultFormatterBehavior;
+ (void)setDefaultFormatterBehavior:(NSDateFormatterBehavior)behavior;
@property (getter=isLenient) BOOL lenient;
@property BOOL doesRelativeDateFormatting;
@property (copy) NSString* AMSymbol;
@property (copy) NSString* PMSymbol;
@property (copy) NSArray* weekdaySymbols;
@property (copy) NSArray* shortWeekdaySymbols;
@property (copy) NSArray* veryShortWeekdaySymbols;
@property (copy) NSArray* standaloneWeekdaySymbols;
@property (copy) NSArray* shortStandaloneWeekdaySymbols;
@property (copy) NSArray* veryShortStandaloneWeekdaySymbols;
@property (copy) NSArray* monthSymbols;
@property (copy) NSArray* shortMonthSymbols;
@property (copy) NSArray* veryShortMonthSymbols;
@property (copy) NSArray* standaloneMonthSymbols;
@property (copy) NSArray* shortStandaloneMonthSymbols;
@property (copy) NSArray* veryShortStandaloneMonthSymbols;
@property (copy) NSArray* quarterSymbols;
@property (copy) NSArray* shortQuarterSymbols;
@property (copy) NSArray* standaloneQuarterSymbols;
@property (copy) NSArray* shortStandaloneQuarterSymbols;
@property (copy) NSArray* eraSymbols;
@property (copy) NSArray* longEraSymbols;
@end
