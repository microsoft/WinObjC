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

#import <EventKit/EKEventStore.h>
#import <StubReturn.h>

@implementation EKEventStore
/**
 @Status Stub
 @Notes
*/
- (void)requestAccessToEntityType:(EKEntityType)entityType completion:(EKEventStoreRequestAccessCompletionHandler)completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
+ (EKAuthorizationStatus)authorizationStatusForEntityType:(EKEntityType)entityType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (EKCalendar*)defaultCalendarForNewReminders {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (EKCalendar*)calendarWithIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)calendarsForEntityType:(EKEntityType)entityType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)saveCalendar:(EKCalendar*)calendar commit:(BOOL)commit error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)removeCalendar:(EKCalendar*)calendar commit:(BOOL)commit error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (EKEvent*)eventWithIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)eventsMatchingPredicate:(NSPredicate*)predicate {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)enumerateEventsMatchingPredicate:(NSPredicate*)predicate usingBlock:(EKEventSearchCallback)block {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSPredicate*)predicateForEventsWithStartDate:(NSDate*)startDate endDate:(NSDate*)endDate calendars:(NSArray*)calendars {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)saveEvent:(EKEvent*)event span:(EKSpan)span error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)saveEvent:(EKEvent*)event span:(EKSpan)span commit:(BOOL)commit error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)removeEvent:(EKEvent*)event span:(EKSpan)span error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)removeEvent:(EKEvent*)event span:(EKSpan)span commit:(BOOL)commit error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)fetchRemindersMatchingPredicate:(NSPredicate*)predicate completion:(void (^)(NSArray*))completion {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSPredicate*)predicateForRemindersInCalendars:(NSArray*)calendars {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSPredicate*)predicateForIncompleteRemindersWithDueDateStarting:(NSDate*)startDate
                                                            ending:(NSDate*)endDate
                                                         calendars:(NSArray*)calendars {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSPredicate*)predicateForCompletedRemindersWithCompletionDateStarting:(NSDate*)startDate
                                                                  ending:(NSDate*)endDate
                                                               calendars:(NSArray*)calendars {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)cancelFetchRequest:(id)fetchIdentifier {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)saveReminder:(EKReminder*)reminder commit:(BOOL)commit error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)removeReminder:(EKReminder*)reminder commit:(BOOL)commit error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (EKCalendarItem*)calendarItemWithIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)calendarItemsWithExternalIdentifier:(NSString*)externalIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (EKSource*)sourceWithIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)commit:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)reset {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)refreshSourcesIfNecessary {
    UNIMPLEMENTED();
}

@end
