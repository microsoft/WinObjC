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
@class NSURL;

typedef enum {
    EKParticipantRoleUnknown,
    EKParticipantRoleRequired,
    EKParticipantRoleOptional,
    EKParticipantRoleChair,
    EKParticipantRoleNonParticipant
} EKParticipantRole;

typedef enum {
    EKParticipantStatusUnknown,
    EKParticipantStatusPending,
    EKParticipantStatusAccepted,
    EKParticipantStatusDeclined,
    EKParticipantStatusTentative,
    EKParticipantStatusDelegated,
    EKParticipantStatusCompleted,
    EKParticipantStatusInProcess
} EKParticipantStatus;

typedef enum {
    EKParticipantTypeUnknown,
    EKParticipantTypePerson,
    EKParticipantTypeRoom,
    EKParticipantTypeResource,
    EKParticipantTypeGroup
} EKParticipantType;

typedef CFTypeRef ABAddressBookRef;
typedef CFTypeRef ABRecordRef;

EVENTKIT_EXPORT_CLASS
@interface EKParticipant : EKObject <NSCopying, NSObject>
@property (readonly, nonatomic) BOOL isCurrentUser STUB_PROPERTY;
@property (readonly, nonatomic) NSString* name STUB_PROPERTY;
@property (readonly, nonatomic) EKParticipantRole participantRole STUB_PROPERTY;
@property (readonly, nonatomic) EKParticipantStatus participantStatus STUB_PROPERTY;
@property (readonly, nonatomic) EKParticipantType participantType STUB_PROPERTY;
@property (readonly, nonatomic) NSURL* URL STUB_PROPERTY;
- (ABRecordRef)ABRecordWithAddressBook:(ABAddressBookRef)addressBook STUB_METHOD;
@end
