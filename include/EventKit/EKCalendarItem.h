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

#import <objc\runtime.h>

@class NSString;
@class EKCalendar;
@class NSDate;
@class NSTimeZone;
@class NSURL;
@class NSArray;
@class EKAlarm;
@class EKRecurrenceRule;

EVENTKIT_EXPORT_CLASS
@interface EKCalendarItem : EKObject <NSObject>
@property (readonly, nonatomic) NSString* calendarItemIdentifier STUB_PROPERTY;
@property (readonly, nonatomic) NSString* calendarItemExternalIdentifier STUB_PROPERTY;
@property (readonly, nonatomic) NSString* UUID STUB_PROPERTY;
@property (nonatomic, strong) EKCalendar* calendar STUB_PROPERTY;
@property (copy, nonatomic) NSString* title STUB_PROPERTY;
@property (copy, nonatomic) NSString* location STUB_PROPERTY;
@property (readonly, nonatomic) NSDate* creationDate STUB_PROPERTY;
@property (readonly, nonatomic) NSDate* lastModifiedDate STUB_PROPERTY;
@property (copy, nonatomic) NSTimeZone* timeZone STUB_PROPERTY;
@property (copy, nonatomic) NSURL* URL STUB_PROPERTY;
@property (readonly, nonatomic) BOOL hasNotes STUB_PROPERTY;
@property (copy, nonatomic) NSString* notes STUB_PROPERTY;
@property (readonly, nonatomic) BOOL hasAttendees STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* attendees STUB_PROPERTY;
@property (readonly, nonatomic) BOOL hasAlarms STUB_PROPERTY;
- (void)addAlarm:(EKAlarm*)alarm STUB_METHOD;
- (void)removeAlarm:(EKAlarm*)alarm STUB_METHOD;
@property (copy, nonatomic) NSArray* alarms STUB_PROPERTY;
@property (readonly, nonatomic) BOOL hasRecurrenceRules STUB_PROPERTY;
- (void)addRecurrenceRule:(EKRecurrenceRule*)rule STUB_METHOD;
- (void)removeRecurrenceRule:(EKRecurrenceRule*)rule STUB_METHOD;
@property (copy, nonatomic) NSArray* recurrenceRules STUB_PROPERTY;
@end
