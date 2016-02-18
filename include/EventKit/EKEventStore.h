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

#import <EventKit/EKSource.h>
#import <EventKit/EventKitExport.h>

#import <Foundation/NSObject.h>

#import <objc\runtime.h>

@class NSError;
@class EKEvent;
@class NSString;
@class NSArray;
@class EKCalendar;
@class NSPredicate;
@class NSDate;
@class EKReminder;
@class EKCalendarItem;
@class EKSource;

typedef void (^EKEventStoreRequestAccessCompletionHandler)(BOOL granted, NSError* error);
typedef void (^EKEventSearchCallback)(EKEvent* event, BOOL* stop);

typedef enum { 
    EKSpanThisEvent, 
    EKSpanFutureEvents, 
} EKSpan;

typedef enum {
    EKAuthorizationStatusNotDetermined = 0,
    EKAuthorizationStatusRestricted,
    EKAuthorizationStatusDenied,
    EKAuthorizationStatusAuthorized,
} EKAuthorizationStatus;

// Missing declaration of //apple_ref/c/data/EKEventStoreChangedNotification

EVENTKIT_EXPORT_CLASS
@interface EKEventStore : NSObject <NSObject>
- (void)requestAccessToEntityType:(EKEntityType)entityType completion:(EKEventStoreRequestAccessCompletionHandler)completion STUB_METHOD;
+ (EKAuthorizationStatus)authorizationStatusForEntityType:(EKEntityType)entityType STUB_METHOD;
@property (readonly, nonatomic) NSString* eventStoreIdentifier STUB_PROPERTY;
@property (readonly, nonatomic) NSArray* calendars STUB_PROPERTY;
@property (readonly, nonatomic) EKCalendar* defaultCalendarForNewEvents STUB_PROPERTY;
- (EKCalendar*)defaultCalendarForNewReminders STUB_METHOD;
- (EKCalendar*)calendarWithIdentifier:(NSString*)identifier STUB_METHOD;
- (NSArray*)calendarsForEntityType:(EKEntityType)entityType STUB_METHOD;
- (BOOL)saveCalendar:(EKCalendar*)calendar commit:(BOOL)commit error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)removeCalendar:(EKCalendar*)calendar commit:(BOOL)commit error:(NSError* _Nullable*)error STUB_METHOD;
- (EKEvent*)eventWithIdentifier:(NSString*)identifier STUB_METHOD;
- (NSArray*)eventsMatchingPredicate:(NSPredicate*)predicate STUB_METHOD;
- (void)enumerateEventsMatchingPredicate:(NSPredicate*)predicate usingBlock:(EKEventSearchCallback)block STUB_METHOD;
- (NSPredicate*)predicateForEventsWithStartDate:(NSDate*)startDate endDate:(NSDate*)endDate calendars:(NSArray*)calendars STUB_METHOD;
- (BOOL)saveEvent:(EKEvent*)event span:(EKSpan)span error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)saveEvent:(EKEvent*)event span:(EKSpan)span commit:(BOOL)commit error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)removeEvent:(EKEvent*)event span:(EKSpan)span error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)removeEvent:(EKEvent*)event span:(EKSpan)span commit:(BOOL)commit error:(NSError* _Nullable*)error STUB_METHOD;
- (id)fetchRemindersMatchingPredicate:(NSPredicate*)predicate completion:(void (^)(NSArray*))completion STUB_METHOD;
- (NSPredicate*)predicateForRemindersInCalendars:(NSArray*)calendars STUB_METHOD;
- (NSPredicate*)predicateForIncompleteRemindersWithDueDateStarting:(NSDate*)startDate
                                                            ending:(NSDate*)endDate
                                                         calendars:(NSArray*)calendars STUB_METHOD;
- (NSPredicate*)predicateForCompletedRemindersWithCompletionDateStarting:(NSDate*)startDate
                                                                  ending:(NSDate*)endDate
                                                               calendars:(NSArray*)calendars STUB_METHOD;
- (void)cancelFetchRequest:(id)fetchIdentifier STUB_METHOD;
- (BOOL)saveReminder:(EKReminder*)reminder commit:(BOOL)commit error:(NSError* _Nullable*)error STUB_METHOD;
- (BOOL)removeReminder:(EKReminder*)reminder commit:(BOOL)commit error:(NSError* _Nullable*)error STUB_METHOD;
- (EKCalendarItem*)calendarItemWithIdentifier:(NSString*)identifier STUB_METHOD;
- (NSArray*)calendarItemsWithExternalIdentifier:(NSString*)externalIdentifier STUB_METHOD;
@property (readonly, nonatomic) NSArray* sources STUB_PROPERTY;
- (EKSource*)sourceWithIdentifier:(NSString*)identifier STUB_METHOD;
- (BOOL)commit:(NSError* _Nullable*)error STUB_METHOD;
- (void)reset STUB_METHOD;
- (void)refreshSourcesIfNecessary STUB_METHOD;
@end
