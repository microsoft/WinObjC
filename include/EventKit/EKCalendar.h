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
#import <EventKit/EKSource.h>
#import <EventKit/EventKitExport.h>

#import <CoreGraphics/CGColor.h>

#import <Foundation/NSObject.h>

#import <objc\runtime.h>

@class EKEventStore;
@class NSString;
@class EKSource;

typedef enum {
    EKCalendarTypeLocal,
    EKCalendarTypeCalDAV,
    EKCalendarTypeExchange,
    EKCalendarTypeSubscription,
    EKCalendarTypeBirthday,
} EKCalendarType;

enum {
    EKCalendarEventAvailabilityNone = 0,
    EKCalendarEventAvailabilityBusy = (1 << 0),
    EKCalendarEventAvailabilityFree = (1 << 1),
    EKCalendarEventAvailabilityTentative = (1 << 2),
    EKCalendarEventAvailabilityUnavailable = (1 << 3),
};
typedef NSUInteger EKCalendarEventAvailabilityMask;

EVENTKIT_EXPORT_CLASS
@interface EKCalendar : EKObject <NSObject>
+ (EKCalendar*)calendarWithEventStore:(EKEventStore*)eventStore STUB_METHOD;
+ (EKCalendar*)calendarForEntityType:(EKEntityType)entityType eventStore:(EKEventStore*)eventStore STUB_METHOD;
@property (readonly, nonatomic) BOOL allowsContentModifications STUB_PROPERTY;
@property (nonatomic) CGColorRef CGColor STUB_PROPERTY;
@property (readonly, getter=isImmutable, nonatomic) BOOL immutable STUB_PROPERTY;
@property (copy, nonatomic) NSString* title STUB_PROPERTY;
@property (readonly, nonatomic) EKCalendarType type STUB_PROPERTY;
@property (readonly, nonatomic) EKEntityMask allowedEntityTypes STUB_PROPERTY;
@property (nonatomic, strong) EKSource* source STUB_PROPERTY;
@property (readonly, getter=isSubscribed, nonatomic) BOOL subscribed STUB_PROPERTY;
@property (readonly, nonatomic) EKCalendarEventAvailabilityMask supportedEventAvailabilities STUB_PROPERTY;
@property (readonly, nonatomic) NSString* calendarIdentifier STUB_PROPERTY;
@end
