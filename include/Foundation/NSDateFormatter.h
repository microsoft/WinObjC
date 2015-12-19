/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _NSDATEFORMATTER_H_
#define _NSDATEFORMATTER_H_

#import <Foundation/NSFormatter.h>
#import <Foundation/NSDate.h>
#import <CoreFoundation/CFDateFormatter.h>

typedef enum {
    NSDateFormatterBehaviorDefault = 0,
    NSDateFormatterBehavior10_0 = 1000,
    NSDateFormatterBehavior10_4 = 1040,
} NSDateFormatterBehavior;

typedef enum {
    NSDateFormatterNoStyle = kCFDateFormatterNoStyle,
    NSDateFormatterShortStyle = kCFDateFormatterShortStyle,
    NSDateFormatterMediumStyle = kCFDateFormatterMediumStyle,
    NSDateFormatterLongStyle = kCFDateFormatterLongStyle,
    NSDateFormatterFullStyle = kCFDateFormatterFullStyle
} NSDateFormatterStyle;

@class NSCalendar;

FOUNDATION_EXPORT_CLASS
@interface NSDateFormatter : NSFormatter

+ (NSString*)dateFormatFromTemplate:(NSString*)tmplate options:(NSUInteger)opts locale:(NSLocale*)locale;
+ (NSString*)localizedStringFromDate:(NSDate*)date dateStyle:(NSDateFormatterStyle)dateStyle timeStyle:(NSDateFormatterStyle)timeStyle;

- initWithDateFormat:(NSString*)format allowNaturalLanguage:(BOOL)flag; // shouldn't this be "allows" ?

+ (NSDateFormatterBehavior)defaultFormatterBehavior;
+ (void)setDefaultFormatterBehavior:(NSDateFormatterBehavior)behavior;

// added because NSDateFormatter is the backend for initWithString:calendarFormat:locale
// shouldn't this really exist anyway?
- initWithDateFormat:(NSString*)format allowNaturalLanguage:(BOOL)flag locale:(NSDictionary*)locale;

- (void)setFormatterBehavior:(NSDateFormatterBehavior)value;

- (NSString*)stringFromDate:(NSDate*)date;
- (NSDate*)dateFromString:(NSString*)string;

@property BOOL lenient;
@property BOOL allowsNaturalLanguage;

@property (copy) NSString* dateFormat;

@property (readonly) NSDateFormatterStyle timeStyle;
@property (readonly) NSDateFormatterStyle dateStyle;

@property (copy) NSLocale* locale;
@property (copy) NSCalendar* calendar;
@property (copy) NSTimeZone* timeZone;
@property (copy) NSArray* monthSymbols;
@property (copy) NSArray* standaloneMonthSymbols;
@property (copy) NSArray* weekdaySymbols;
@property (copy) NSArray* shortWeekdaySymbols;
@property (copy) NSArray* shortStandaloneWeekdaySymbols;
@property (copy) NSArray* standaloneWeekdaySymbols;
@property (readonly) NSDateFormatterBehavior formatterBehavior;

@property (copy) NSString* AMSymbol;
@property (copy) NSString* PMSymbol;
@end

#endif /* _NSDATEFORMATTER_H_ */
