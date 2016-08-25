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

#import <Foundation/NSCalendar.h>
@class NSDate;
@class NSCalendar;
@class NSTimeZone;

FOUNDATION_EXPORT_CLASS
@interface NSDateComponents : NSObject <NSCopying, NSSecureCoding>
@property (readonly, copy) NSDate* date;
@property (copy) NSCalendar* calendar;
@property (copy) NSTimeZone* timeZone;
@property (readonly, getter=isValidDate) BOOL validDate;
- (BOOL)isValidDateInCalendar:(NSCalendar*)calendar;
@property NSInteger era;
@property NSInteger year;
@property NSInteger month;
@property NSInteger day;
@property NSInteger hour;
@property NSInteger minute;
@property NSInteger second;
@property NSInteger nanosecond;
@property NSInteger weekday;
@property NSInteger weekdayOrdinal;
@property NSInteger quarter;
@property NSInteger weekOfMonth;
@property NSInteger weekOfYear;
@property NSInteger yearForWeekOfYear;
@property (getter=isLeapMonth) BOOL leapMonth;
- (NSInteger)valueForComponent:(NSCalendarUnit)unit;
- (void)setValue:(NSInteger)value forComponent:(NSCalendarUnit)unit;
- (NSInteger)week;
- (void)setWeek:(NSInteger)v;
@end
