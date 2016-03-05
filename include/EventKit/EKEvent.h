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

#import <EventKit/EKCalendarItem.h>
#import <EventKit/EventKitExport.h>

#import <Foundation/NSObject.h>

#import <objc\runtime.h>

@class EKEventStore;
@class NSString;
@class NSDate;
@class EKRecurrenceRule;
@class EKParticipant;

typedef enum {
    EKEventAvailabilityNotSupported = -1,
    EKEventAvailabilityBusy = 0,
    EKEventAvailabilityFree,
    EKEventAvailabilityTentative,
    EKEventAvailabilityUnavailable
} EKEventAvailability;

typedef enum {
    EKEventStatusNone = 0,
    EKEventStatusConfirmed,
    EKEventStatusTentative,
    EKEventStatusCanceled,
} EKEventStatus;

EVENTKIT_EXPORT_CLASS
@interface EKEvent : EKCalendarItem <NSObject>
+ (EKEvent*)eventWithEventStore:(EKEventStore*)eventStore STUB_METHOD;
@property (readonly, nonatomic) NSString* eventIdentifier STUB_PROPERTY;
@property (nonatomic) EKEventAvailability availability STUB_PROPERTY;
@property (copy, nonatomic) NSDate* startDate STUB_PROPERTY;
@property (copy, nonatomic) NSDate* endDate STUB_PROPERTY;
@property (getter=isAllDay, nonatomic) BOOL allDay STUB_PROPERTY;
@property (retain, nonatomic) EKRecurrenceRule* recurrenceRule STUB_PROPERTY;
@property (readonly, nonatomic) NSDate* occurrenceDate STUB_PROPERTY;
@property (readonly, nonatomic) BOOL isDetached STUB_PROPERTY;
@property (readonly, nonatomic) EKParticipant* organizer STUB_PROPERTY;
@property (readonly, nonatomic) EKEventStatus status STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger birthdayPersonID STUB_PROPERTY;
- (NSComparisonResult)compareStartDateWithEvent:(EKEvent*)other STUB_METHOD;
- (BOOL)refresh STUB_METHOD;
@end
