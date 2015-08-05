/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

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

FOUNDATION_EXPORT_CLASS
@interface NSDateFormatter : NSFormatter

+ (void)setDefaultFormatterBehavior:(NSDateFormatterBehavior)behavior;
+ (NSString *)dateFormatFromTemplate:(NSString *)tmplate options:(NSUInteger)opts locale:(NSLocale *)locale;

- initWithDateFormat:(NSString *)format allowNaturalLanguage:(BOOL)flag; // shouldn't this be "allows" ?

// added because NSDateFormatter is the backend for initWithString:calendarFormat:locale
// shouldn't this really exist anyway?
- initWithDateFormat:(NSString *)format allowNaturalLanguage:(BOOL)flag locale:(NSDictionary *)locale;

- (NSString *)dateFormat;
- (BOOL)allowsNaturalLanguage;
- (NSDateFormatterBehavior)formatterBehavior;

- (NSDictionary *)locale;

- (void)setDateFormat:(NSString *)format;

- (NSString *)stringFromDate:(NSDate *)date;
- (NSArray *)shortStandaloneWeekdaySymbols;
- (NSArray *)standaloneWeekdaySymbols;

- (void)setLenient:(BOOL)value;
- (void)setFormatterBehavior:(NSDateFormatterBehavior)value;

- (NSDate *)dateFromString:(NSString *)string;
- (NSDateFormatterStyle)dateStyle;
- (void)setDateStyle:(NSDateFormatterStyle)style;
- (void)setLocale:(NSLocale *)locale;

- (NSCalendar *)calendar;
- (void)setCalendar:(NSCalendar *)calendar;
- (void)setTimeStyle:(NSDateFormatterStyle)style;

- (NSTimeZone *)timeZone;
- (void)setTimeZone:(NSTimeZone *)tz;

- (NSArray *)monthSymbols;

@end

#endif /* _NSDATEFORMATTER_H_ */
