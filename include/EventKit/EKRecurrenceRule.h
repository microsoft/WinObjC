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

#import <EventKit/EKObject.h>
#import <EventKit/EventKitExport.h>

#import <Foundation/NSObject.h>

@class EKRecurrenceEnd;
@class NSArray;
@class NSString;

typedef enum {
    EKRecurrenceFrequencyDaily,
    EKRecurrenceFrequencyWeekly,
    EKRecurrenceFrequencyMonthly,
    EKRecurrenceFrequencyYearly
} EKRecurrenceFrequency;

typedef enum { 
    EKSunday = 1, 
    EKMonday, 
    EKTuesday, 
    EKWednesday, 
    EKThursday, 
    EKFriday, 
    EKSaturday, 
} EKWeekday;

EVENTKIT_EXPORT_CLASS
@interface EKRecurrenceRule : EKObject <NSCopying, NSObject>
- (instancetype)initRecurrenceWithFrequency:(EKRecurrenceFrequency)type interval:(NSInteger)interval end:(EKRecurrenceEnd*)end STUB_METHOD;
- (instancetype)initRecurrenceWithFrequency:(EKRecurrenceFrequency)type
                                   interval:(NSInteger)interval
                              daysOfTheWeek:(NSArray*)days
                             daysOfTheMonth:(NSArray*)monthDays
                            monthsOfTheYear:(NSArray*)months
                             weeksOfTheYear:(NSArray*)weeksOfTheYear
                              daysOfTheYear:(NSArray*)daysOfTheYear
                               setPositions:(NSArray*)setPositions
                                        end:(EKRecurrenceEnd*)end STUB_METHOD;
@property (readonly, nonatomic) NSString* calendarIdentifier STUB_PROPERTY;
@property (copy, nonatomic) EKRecurrenceEnd* recurrenceEnd STUB_PROPERTY;
@property (readonly, nonatomic) EKRecurrenceFrequency frequency STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger interval STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger firstDayOfTheWeek STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* daysOfTheWeek STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* daysOfTheMonth STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* daysOfTheYear STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* weeksOfTheYear STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* monthsOfTheYear STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* setPositions STUB_PROPERTY;
@end
