//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsApplicationModelContacts.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WACContact, WACContactCardDelayedDataLoader, WACContactStore, WACContactAnnotationStore, WACContactCardOptions,
    WACFullContactCardOptions, WACContactAnnotation, WACContactAnnotationList, WACContactChangeTracker, WACContactChangedEventArgs,
    WACAggregateContactManager, WACContactList, WACContactReader, WACContactQueryOptions, WACContactListSyncManager, WACContactPhone,
    WACContactEmail, WACContactAddress, WACContactConnectedServiceAccount, WACContactDate, WACContactJobInfo, WACContactSignificantOther,
    WACContactWebsite, WACContactChangedDeferral, WACContactChange, WACContactChangeReader, WACContactBatch, WACContactMatchReason,
    WACContactQueryTextSearch, WACContactStoreNotificationTriggerDetails, WACContactManager, WACContactLaunchActionVerbs, WACContactField,
    WACContactLocationField, WACContactInstantMessageField, WACKnownContactField, WACContactInformation, WACContactFieldFactory,
    WACContactPicker;
@protocol WACIContactCardOptions
, WACIFullContactCardOptions, WACIContactManagerStatics, WACIContactManagerStatics2, WACIContactManagerStatics3,
    WACIAggregateContactManager, WACIContactAnnotationStore, WACIContactAnnotationList, WACIContactAnnotation,
    WACIContactStoreNotificationTriggerDetails, WACIContactStore, WACIContactStore2, WACIContactList, WACIContactListSyncManager,
    WACIContactConnectedServiceAccount, WACIContactSignificantOther, WACIContactSignificantOther2, WACIContactWebsite, WACIContactWebsite2,
    WACIContactEmail, WACIContactPhone, WACIContactAddress, WACIContactDate, WACIContactJobInfo, WACIContact, WACIContactField,
    WACIContactName, WACIContact2, WACIContact3, WACIContactChange, WACIContactChangedDeferral, WACIContactChangedEventArgs,
    WACIContactChangeReader, WACIContactChangeTracker, WACIContactReader, WACIContactQueryTextSearch, WACIContactQueryOptionsFactory,
    WACIContactQueryOptions, WACIContactBatch, WACIContactMatchReason, WACIContactLaunchActionVerbsStatics, WACIContactLocationField,
    WACIContactInstantMessageField, WACIKnownContactFieldStatics, WACIContactInformation, WACIContactFieldFactory,
    WACIContactLocationFieldFactory, WACIContactInstantMessageFieldFactory, WACIContactPicker, WACIContactPicker2,
    WACIContactCardDelayedDataLoader;

// Windows.ApplicationModel.Contacts.ContactFieldType
enum _WACContactFieldType {
    WACContactFieldTypeEmail = 0,
    WACContactFieldTypePhoneNumber = 1,
    WACContactFieldTypeLocation = 2,
    WACContactFieldTypeInstantMessage = 3,
    WACContactFieldTypeCustom = 4,
    WACContactFieldTypeConnectedServiceAccount = 5,
    WACContactFieldTypeImportantDate = 6,
    WACContactFieldTypeAddress = 7,
    WACContactFieldTypeSignificantOther = 8,
    WACContactFieldTypeNotes = 9,
    WACContactFieldTypeWebsite = 10,
    WACContactFieldTypeJobInfo = 11,
};
typedef unsigned WACContactFieldType;

// Windows.ApplicationModel.Contacts.ContactSelectionMode
enum _WACContactSelectionMode {
    WACContactSelectionModeContacts = 0,
    WACContactSelectionModeFields = 1,
};
typedef unsigned WACContactSelectionMode;

// Windows.ApplicationModel.Contacts.ContactEmailKind
enum _WACContactEmailKind {
    WACContactEmailKindPersonal = 0,
    WACContactEmailKindWork = 1,
    WACContactEmailKindOther = 2,
};
typedef unsigned WACContactEmailKind;

// Windows.ApplicationModel.Contacts.ContactPhoneKind
enum _WACContactPhoneKind {
    WACContactPhoneKindHome = 0,
    WACContactPhoneKindMobile = 1,
    WACContactPhoneKindWork = 2,
    WACContactPhoneKindOther = 3,
    WACContactPhoneKindPager = 4,
    WACContactPhoneKindBusinessFax = 5,
    WACContactPhoneKindHomeFax = 6,
    WACContactPhoneKindCompany = 7,
    WACContactPhoneKindAssistant = 8,
    WACContactPhoneKindRadio = 9,
};
typedef unsigned WACContactPhoneKind;

// Windows.ApplicationModel.Contacts.ContactAddressKind
enum _WACContactAddressKind {
    WACContactAddressKindHome = 0,
    WACContactAddressKindWork = 1,
    WACContactAddressKindOther = 2,
};
typedef unsigned WACContactAddressKind;

// Windows.ApplicationModel.Contacts.ContactDateKind
enum _WACContactDateKind {
    WACContactDateKindBirthday = 0,
    WACContactDateKindAnniversary = 1,
    WACContactDateKindOther = 2,
};
typedef unsigned WACContactDateKind;

// Windows.ApplicationModel.Contacts.ContactChangeType
enum _WACContactChangeType {
    WACContactChangeTypeCreated = 0,
    WACContactChangeTypeModified = 1,
    WACContactChangeTypeDeleted = 2,
    WACContactChangeTypeChangeTrackingLost = 3,
};
typedef unsigned WACContactChangeType;

// Windows.ApplicationModel.Contacts.ContactRelationship
enum _WACContactRelationship {
    WACContactRelationshipOther = 0,
    WACContactRelationshipSpouse = 1,
    WACContactRelationshipPartner = 2,
    WACContactRelationshipSibling = 3,
    WACContactRelationshipParent = 4,
    WACContactRelationshipChild = 5,
};
typedef unsigned WACContactRelationship;

// Windows.ApplicationModel.Contacts.ContactQueryDesiredFields
enum _WACContactQueryDesiredFields {
    WACContactQueryDesiredFieldsNone = 0,
    WACContactQueryDesiredFieldsPhoneNumber = 1,
    WACContactQueryDesiredFieldsEmailAddress = 2,
    WACContactQueryDesiredFieldsPostalAddress = 4,
};
typedef unsigned WACContactQueryDesiredFields;

// Windows.ApplicationModel.Contacts.ContactQuerySearchFields
enum _WACContactQuerySearchFields {
    WACContactQuerySearchFieldsNone = 0,
    WACContactQuerySearchFieldsName = 1,
    WACContactQuerySearchFieldsEmail = 2,
    WACContactQuerySearchFieldsPhone = 4,
    WACContactQuerySearchFieldsAll = -1,
};
typedef unsigned WACContactQuerySearchFields;

// Windows.ApplicationModel.Contacts.ContactQuerySearchScope
enum _WACContactQuerySearchScope {
    WACContactQuerySearchScopeLocal = 0,
    WACContactQuerySearchScopeServer = 1,
};
typedef unsigned WACContactQuerySearchScope;

// Windows.ApplicationModel.Contacts.ContactStoreAccessType
enum _WACContactStoreAccessType {
    WACContactStoreAccessTypeAppContactsReadWrite = 0,
    WACContactStoreAccessTypeAllContactsReadOnly = 1,
    WACContactStoreAccessTypeAllContactsReadWrite = 2,
};
typedef unsigned WACContactStoreAccessType;

// Windows.ApplicationModel.Contacts.ContactAnnotationStoreAccessType
enum _WACContactAnnotationStoreAccessType {
    WACContactAnnotationStoreAccessTypeAppAnnotationsReadWrite = 0,
    WACContactAnnotationStoreAccessTypeAllAnnotationsReadWrite = 1,
};
typedef unsigned WACContactAnnotationStoreAccessType;

// Windows.ApplicationModel.Contacts.ContactListOtherAppReadAccess
enum _WACContactListOtherAppReadAccess {
    WACContactListOtherAppReadAccessSystemOnly = 0,
    WACContactListOtherAppReadAccessLimited = 1,
    WACContactListOtherAppReadAccessFull = 2,
};
typedef unsigned WACContactListOtherAppReadAccess;

// Windows.ApplicationModel.Contacts.ContactListOtherAppWriteAccess
enum _WACContactListOtherAppWriteAccess {
    WACContactListOtherAppWriteAccessNone = 0,
    WACContactListOtherAppWriteAccessSystemOnly = 1,
};
typedef unsigned WACContactListOtherAppWriteAccess;

// Windows.ApplicationModel.Contacts.ContactMatchReasonKind
enum _WACContactMatchReasonKind {
    WACContactMatchReasonKindName = 0,
    WACContactMatchReasonKindEmailAddress = 1,
    WACContactMatchReasonKindPhoneNumber = 2,
    WACContactMatchReasonKindJobInfo = 3,
    WACContactMatchReasonKindYomiName = 4,
    WACContactMatchReasonKindOther = 5,
};
typedef unsigned WACContactMatchReasonKind;

// Windows.ApplicationModel.Contacts.ContactBatchStatus
enum _WACContactBatchStatus {
    WACContactBatchStatusSuccess = 0,
    WACContactBatchStatusServerSearchSyncManagerError = 1,
    WACContactBatchStatusServerSearchUnknownError = 2,
};
typedef unsigned WACContactBatchStatus;

// Windows.ApplicationModel.Contacts.ContactAnnotationOperations
enum _WACContactAnnotationOperations {
    WACContactAnnotationOperationsNone = 0,
    WACContactAnnotationOperationsContactProfile = 1,
    WACContactAnnotationOperationsMessage = 2,
    WACContactAnnotationOperationsAudioCall = 4,
    WACContactAnnotationOperationsVideoCall = 8,
    WACContactAnnotationOperationsSocialFeeds = 16,
};
typedef unsigned WACContactAnnotationOperations;

// Windows.ApplicationModel.Contacts.ContactNameOrder
enum _WACContactNameOrder {
    WACContactNameOrderFirstNameLastName = 0,
    WACContactNameOrderLastNameFirstName = 1,
};
typedef unsigned WACContactNameOrder;

// Windows.ApplicationModel.Contacts.ContactListSyncStatus
enum _WACContactListSyncStatus {
    WACContactListSyncStatusIdle = 0,
    WACContactListSyncStatusSyncing = 1,
    WACContactListSyncStatusUpToDate = 2,
    WACContactListSyncStatusAuthenticationError = 3,
    WACContactListSyncStatusPolicyError = 4,
    WACContactListSyncStatusUnknownError = 5,
};
typedef unsigned WACContactListSyncStatus;

// Windows.ApplicationModel.Contacts.ContactCardHeaderKind
enum _WACContactCardHeaderKind {
    WACContactCardHeaderKindDefault = 0,
    WACContactCardHeaderKindBasic = 1,
    WACContactCardHeaderKindEnterprise = 2,
};
typedef unsigned WACContactCardHeaderKind;

// Windows.ApplicationModel.Contacts.ContactCardTabKind
enum _WACContactCardTabKind {
    WACContactCardTabKindDefault = 0,
    WACContactCardTabKindEmail = 1,
    WACContactCardTabKindMessaging = 2,
    WACContactCardTabKindPhone = 3,
    WACContactCardTabKindVideo = 4,
};
typedef unsigned WACContactCardTabKind;

// Windows.ApplicationModel.Contacts.ContactFieldCategory
enum _WACContactFieldCategory {
    WACContactFieldCategoryNone = 0,
    WACContactFieldCategoryHome = 1,
    WACContactFieldCategoryWork = 2,
    WACContactFieldCategoryMobile = 3,
    WACContactFieldCategoryOther = 4,
};
typedef unsigned WACContactFieldCategory;

#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsUIViewManagement.h"
#include "WindowsDataText.h"
#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Contacts.IContactField
#ifndef __WACIContactField_DEFINED__
#define __WACIContactField_DEFINED__

@protocol WACIContactField
@property (readonly) WACContactFieldCategory category;
@property (readonly) NSString* name;
@property (readonly) WACContactFieldType type;
@property (readonly) NSString* value;
@end

#endif // __WACIContactField_DEFINED__

// Windows.ApplicationModel.Contacts.IContactFieldFactory
#ifndef __WACIContactFieldFactory_DEFINED__
#define __WACIContactFieldFactory_DEFINED__

@protocol WACIContactFieldFactory
- (WACContactField*)createField_Default:(NSString*)value type:(WACContactFieldType)type;
- (WACContactField*)createField_Category:(NSString*)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category;
- (WACContactField*)createField_Custom:(NSString*)name
                                 value:(NSString*)value
                                  type:(WACContactFieldType)type
                              category:(WACContactFieldCategory)category;
@end

#endif // __WACIContactFieldFactory_DEFINED__

// Windows.ApplicationModel.Contacts.IContactLocationFieldFactory
#ifndef __WACIContactLocationFieldFactory_DEFINED__
#define __WACIContactLocationFieldFactory_DEFINED__

@protocol WACIContactLocationFieldFactory
- (WACContactLocationField*)createLocation_Default:(NSString*)unstructuredAddress;
- (WACContactLocationField*)createLocation_Category:(NSString*)unstructuredAddress category:(WACContactFieldCategory)category;
- (WACContactLocationField*)createLocation_All:(NSString*)unstructuredAddress
                                      category:(WACContactFieldCategory)category
                                        street:(NSString*)street
                                          city:(NSString*)city
                                        region:(NSString*)region
                                       country:(NSString*)country
                                    postalCode:(NSString*)postalCode;
@end

#endif // __WACIContactLocationFieldFactory_DEFINED__

// Windows.ApplicationModel.Contacts.IContactInstantMessageFieldFactory
#ifndef __WACIContactInstantMessageFieldFactory_DEFINED__
#define __WACIContactInstantMessageFieldFactory_DEFINED__

@protocol WACIContactInstantMessageFieldFactory
- (WACContactInstantMessageField*)createInstantMessage_Default:(NSString*)userName;
- (WACContactInstantMessageField*)createInstantMessage_Category:(NSString*)userName category:(WACContactFieldCategory)category;
- (WACContactInstantMessageField*)createInstantMessage_All:(NSString*)userName
                                                  category:(WACContactFieldCategory)category
                                                   service:(NSString*)service
                                               displayText:(NSString*)displayText
                                                      verb:(WFUri*)verb;
@end

#endif // __WACIContactInstantMessageFieldFactory_DEFINED__

// Windows.ApplicationModel.Contacts.Contact
#ifndef __WACContact_DEFINED__
#define __WACContact_DEFINED__

WINRT_EXPORT
@interface WACContact : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject<WSSIRandomAccessStreamReference>* thumbnail;
@property (copy) NSString* name;
@property (readonly) NSMutableArray* fields;
@property (copy) NSString* id;
@property (copy) NSString* notes;
@property (readonly) NSMutableArray* connectedServiceAccounts;
@property (readonly) NSMutableArray* emails;
@property (readonly) NSMutableArray* addresses;
@property (readonly) NSMutableArray* importantDates;
@property (readonly) NSMutableArray* jobInfo;
@property (readonly) NSMutableArray* dataSuppliers;
@property (readonly) NSMutableArray* phones;
@property (readonly) RTObject<WFCIPropertySet>* providerProperties;
@property (readonly) NSMutableArray* significantOthers;
@property (readonly) NSMutableArray* websites;
@property (copy) RTObject<WSSIRandomAccessStreamReference>* sourceDisplayPicture;
@property (copy) NSString* textToneToken;
@property (copy) NSString* displayNameOverride;
@property (copy) WFDateTime* displayPictureUserUpdateTime;
@property (copy) NSString* nickname;
@property (copy) NSString* remoteId;
@property (copy) NSString* ringToneToken;
@property (readonly) NSString* contactListId;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* largeDisplayPicture;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* smallDisplayPicture;
@property (readonly) NSString* sortName;
@property (readonly) NSString* aggregateId;
@property (readonly) NSString* fullName;
@property (readonly) BOOL isAggregate;
@property (readonly) BOOL isDisplayPictureManuallySet;
@property (readonly) BOOL isMe;
@property (copy) NSString* yomiGivenName;
@property (copy) NSString* honorificNameSuffix;
@property (copy) NSString* yomiFamilyName;
@property (copy) NSString* middleName;
@property (copy) NSString* lastName;
@property (copy) NSString* honorificNamePrefix;
@property (copy) NSString* firstName;
@property (readonly) NSString* displayName;
@property (readonly) NSString* yomiDisplayName;
@end

#endif // __WACContact_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.ApplicationModel.Contacts.ContactCardDelayedDataLoader
#ifndef __WACContactCardDelayedDataLoader_DEFINED__
#define __WACContactCardDelayedDataLoader_DEFINED__

WINRT_EXPORT
@interface WACContactCardDelayedDataLoader : RTObject <WFIClosable>
- (void)setData:(WACContact*)contact;
- (void)close;
@end

#endif // __WACContactCardDelayedDataLoader_DEFINED__

// Windows.ApplicationModel.Contacts.ContactStore
#ifndef __WACContactStore_DEFINED__
#define __WACContactStore_DEFINED__

WINRT_EXPORT
@interface WACContactStore : RTObject
@property (readonly) WACAggregateContactManager* aggregateContactManager;
@property (readonly) WACContactChangeTracker* changeTracker;
- (EventRegistrationToken)addContactChangedEvent:(void (^)(WACContactStore*, WACContactChangedEventArgs*))del;
- (void)removeContactChangedEvent:(EventRegistrationToken)tok;
- (void)findContactsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)findContactsWithSearchTextAsync:(NSString*)searchText success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)getContactAsync:(NSString*)contactId success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (void)findContactListsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)getContactListAsync:(NSString*)contactListId success:(void (^)(WACContactList*))success failure:(void (^)(NSError*))failure;
- (void)createContactListAsync:(NSString*)displayName success:(void (^)(WACContactList*))success failure:(void (^)(NSError*))failure;
- (void)getMeContactAsyncWithSuccess:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (WACContactReader*)getContactReader;
- (WACContactReader*)getContactReaderWithOptions:(WACContactQueryOptions*)options;
- (void)createContactListInAccountAsync:(NSString*)displayName
                      userDataAccountId:(NSString*)userDataAccountId
                                success:(void (^)(WACContactList*))success
                                failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactStore_DEFINED__

// Windows.ApplicationModel.Contacts.ContactAnnotationStore
#ifndef __WACContactAnnotationStore_DEFINED__
#define __WACContactAnnotationStore_DEFINED__

WINRT_EXPORT
@interface WACContactAnnotationStore : RTObject
- (void)findContactIdsByEmailAsync:(NSString*)emailAddress success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)findContactIdsByPhoneNumberAsync:(NSString*)phoneNumber success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)findAnnotationsForContactAsync:(WACContact*)contact success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)disableAnnotationAsync:(WACContactAnnotation*)annotation;
- (void)createAnnotationListAsyncWithSuccess:(void (^)(WACContactAnnotationList*))success failure:(void (^)(NSError*))failure;
- (void)createAnnotationListInAccountAsync:(NSString*)userDataAccountId
                                   success:(void (^)(WACContactAnnotationList*))success
                                   failure:(void (^)(NSError*))failure;
- (void)getAnnotationListAsync:(NSString*)annotationListId
                       success:(void (^)(WACContactAnnotationList*))success
                       failure:(void (^)(NSError*))failure;
- (void)findAnnotationListsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactAnnotationStore_DEFINED__

// Windows.ApplicationModel.Contacts.ContactCardOptions
#ifndef __WACContactCardOptions_DEFINED__
#define __WACContactCardOptions_DEFINED__

WINRT_EXPORT
@interface WACContactCardOptions : RTObject
+ (instancetype)create ACTIVATOR;
@property WACContactCardTabKind initialTabKind;
@property WACContactCardHeaderKind headerKind;
@end

#endif // __WACContactCardOptions_DEFINED__

// Windows.ApplicationModel.Contacts.FullContactCardOptions
#ifndef __WACFullContactCardOptions_DEFINED__
#define __WACFullContactCardOptions_DEFINED__

WINRT_EXPORT
@interface WACFullContactCardOptions : RTObject
+ (instancetype)create ACTIVATOR;
@property WUVViewSizePreference desiredRemainingView;
@end

#endif // __WACFullContactCardOptions_DEFINED__

// Windows.ApplicationModel.Contacts.ContactAnnotation
#ifndef __WACContactAnnotation_DEFINED__
#define __WACContactAnnotation_DEFINED__

WINRT_EXPORT
@interface WACContactAnnotation : RTObject
+ (instancetype)create ACTIVATOR;
@property WACContactAnnotationOperations supportedOperations;
@property (copy) NSString* remoteId;
@property (copy) NSString* contactId;
@property (readonly) NSString* annotationListId;
@property (readonly) NSString* id;
@property (readonly) BOOL isDisabled;
@property (readonly) WFCValueSet* providerProperties;
@end

#endif // __WACContactAnnotation_DEFINED__

// Windows.ApplicationModel.Contacts.ContactAnnotationList
#ifndef __WACContactAnnotationList_DEFINED__
#define __WACContactAnnotationList_DEFINED__

WINRT_EXPORT
@interface WACContactAnnotationList : RTObject
@property (readonly) NSString* id;
@property (readonly) NSString* providerPackageFamilyName;
@property (readonly) NSString* userDataAccountId;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (void)trySaveAnnotationAsync:(WACContactAnnotation*)annotation success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)getAnnotationAsync:(NSString*)annotationId success:(void (^)(WACContactAnnotation*))success failure:(void (^)(NSError*))failure;
- (void)findAnnotationsByRemoteIdAsync:(NSString*)remoteId success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)findAnnotationsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)deleteAnnotationAsync:(WACContactAnnotation*)annotation;
@end

#endif // __WACContactAnnotationList_DEFINED__

// Windows.ApplicationModel.Contacts.ContactChangeTracker
#ifndef __WACContactChangeTracker_DEFINED__
#define __WACContactChangeTracker_DEFINED__

WINRT_EXPORT
@interface WACContactChangeTracker : RTObject
- (void)enable;
- (WACContactChangeReader*)getChangeReader;
- (void)reset;
@end

#endif // __WACContactChangeTracker_DEFINED__

// Windows.ApplicationModel.Contacts.ContactChangedEventArgs
#ifndef __WACContactChangedEventArgs_DEFINED__
#define __WACContactChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WACContactChangedEventArgs : RTObject
- (WACContactChangedDeferral*)getDeferral;
@end

#endif // __WACContactChangedEventArgs_DEFINED__

// Windows.ApplicationModel.Contacts.AggregateContactManager
#ifndef __WACAggregateContactManager_DEFINED__
#define __WACAggregateContactManager_DEFINED__

WINRT_EXPORT
@interface WACAggregateContactManager : RTObject
- (void)findRawContactsAsync:(WACContact*)contact success:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)tryLinkContactsAsync:(WACContact*)primaryContact
            secondaryContact:(WACContact*)secondaryContact
                     success:(void (^)(WACContact*))success
                     failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)unlinkRawContactAsync:(WACContact*)contact;
- (void)trySetPreferredSourceForPictureAsync:(WACContact*)aggregateContact
                                  rawContact:(WACContact*)rawContact
                                     success:(void (^)(BOOL))success
                                     failure:(void (^)(NSError*))failure;
@end

#endif // __WACAggregateContactManager_DEFINED__

// Windows.ApplicationModel.Contacts.ContactList
#ifndef __WACContactList_DEFINED__
#define __WACContactList_DEFINED__

WINRT_EXPORT
@interface WACContactList : RTObject
@property WACContactListOtherAppWriteAccess otherAppWriteAccess;
@property WACContactListOtherAppReadAccess otherAppReadAccess;
@property BOOL isHidden;
@property (copy) NSString* displayName;
@property (readonly) WACContactChangeTracker* changeTracker;
@property (readonly) NSString* id;
@property (readonly) NSString* sourceDisplayName;
@property (readonly) BOOL supportsServerSearch;
@property (readonly) WACContactListSyncManager* syncManager;
@property (readonly) NSString* userDataAccountId;
- (EventRegistrationToken)addContactChangedEvent:(void (^)(WACContactList*, WACContactChangedEventArgs*))del;
- (void)removeContactChangedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)saveAsync;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (void)getContactFromRemoteIdAsync:(NSString*)remoteId success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (void)getMeContactAsyncWithSuccess:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (WACContactReader*)getContactReader;
- (WACContactReader*)getContactReaderWithOptions:(WACContactQueryOptions*)options;
- (RTObject<WFIAsyncAction>*)saveContactAsync:(WACContact*)contact;
- (RTObject<WFIAsyncAction>*)deleteContactAsync:(WACContact*)contact;
- (void)getContactAsync:(NSString*)contactId success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactList_DEFINED__

// Windows.ApplicationModel.Contacts.ContactReader
#ifndef __WACContactReader_DEFINED__
#define __WACContactReader_DEFINED__

WINRT_EXPORT
@interface WACContactReader : RTObject
- (void)readBatchAsyncWithSuccess:(void (^)(WACContactBatch*))success failure:(void (^)(NSError*))failure;
- (NSArray*)getMatchingPropertiesWithMatchReason:(WACContact*)contact;
@end

#endif // __WACContactReader_DEFINED__

// Windows.ApplicationModel.Contacts.ContactQueryOptions
#ifndef __WACContactQueryOptions_DEFINED__
#define __WACContactQueryOptions_DEFINED__

WINRT_EXPORT
@interface WACContactQueryOptions : RTObject
+ (WACContactQueryOptions*)createWithText:(NSString*)text ACTIVATOR;
+ (WACContactQueryOptions*)createWithTextAndFields:(NSString*)text fields:(WACContactQuerySearchFields)fields ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property BOOL includeContactsFromHiddenLists;
@property WACContactAnnotationOperations desiredOperations;
@property WACContactQueryDesiredFields desiredFields;
@property (readonly) NSMutableArray* annotationListIds;
@property (readonly) NSMutableArray* contactListIds;
@property (readonly) WACContactQueryTextSearch* textSearch;
@end

#endif // __WACContactQueryOptions_DEFINED__

// Windows.ApplicationModel.Contacts.ContactListSyncManager
#ifndef __WACContactListSyncManager_DEFINED__
#define __WACContactListSyncManager_DEFINED__

WINRT_EXPORT
@interface WACContactListSyncManager : RTObject
@property (readonly) WFDateTime* lastAttemptedSyncTime;
@property (readonly) WFDateTime* lastSuccessfulSyncTime;
@property (readonly) WACContactListSyncStatus status;
- (EventRegistrationToken)addSyncStatusChangedEvent:(void (^)(WACContactListSyncManager*, RTObject*))del;
- (void)removeSyncStatusChangedEvent:(EventRegistrationToken)tok;
- (void)syncAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactListSyncManager_DEFINED__

// Windows.ApplicationModel.Contacts.ContactPhone
#ifndef __WACContactPhone_DEFINED__
#define __WACContactPhone_DEFINED__

WINRT_EXPORT
@interface WACContactPhone : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* number;
@property WACContactPhoneKind kind;
@property (copy) NSString* description;
@end

#endif // __WACContactPhone_DEFINED__

// Windows.ApplicationModel.Contacts.ContactEmail
#ifndef __WACContactEmail_DEFINED__
#define __WACContactEmail_DEFINED__

WINRT_EXPORT
@interface WACContactEmail : RTObject
+ (instancetype)create ACTIVATOR;
@property WACContactEmailKind kind;
@property (copy) NSString* description;
@property (copy) NSString* address;
@end

#endif // __WACContactEmail_DEFINED__

// Windows.ApplicationModel.Contacts.ContactAddress
#ifndef __WACContactAddress_DEFINED__
#define __WACContactAddress_DEFINED__

WINRT_EXPORT
@interface WACContactAddress : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* streetAddress;
@property (copy) NSString* region;
@property (copy) NSString* postalCode;
@property (copy) NSString* locality;
@property WACContactAddressKind kind;
@property (copy) NSString* description;
@property (copy) NSString* country;
@end

#endif // __WACContactAddress_DEFINED__

// Windows.ApplicationModel.Contacts.ContactConnectedServiceAccount
#ifndef __WACContactConnectedServiceAccount_DEFINED__
#define __WACContactConnectedServiceAccount_DEFINED__

WINRT_EXPORT
@interface WACContactConnectedServiceAccount : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* serviceName;
@property (copy) NSString* id;
@end

#endif // __WACContactConnectedServiceAccount_DEFINED__

// Windows.ApplicationModel.Contacts.ContactDate
#ifndef __WACContactDate_DEFINED__
#define __WACContactDate_DEFINED__

WINRT_EXPORT
@interface WACContactDate : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) id year;
@property (copy) id month;
@property WACContactDateKind kind;
@property (copy) NSString* description;
@property (copy) id day;
@end

#endif // __WACContactDate_DEFINED__

// Windows.ApplicationModel.Contacts.ContactJobInfo
#ifndef __WACContactJobInfo_DEFINED__
#define __WACContactJobInfo_DEFINED__

WINRT_EXPORT
@interface WACContactJobInfo : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* title;
@property (copy) NSString* office;
@property (copy) NSString* manager;
@property (copy) NSString* description;
@property (copy) NSString* department;
@property (copy) NSString* companyYomiName;
@property (copy) NSString* companyName;
@property (copy) NSString* companyAddress;
@end

#endif // __WACContactJobInfo_DEFINED__

// Windows.ApplicationModel.Contacts.ContactSignificantOther
#ifndef __WACContactSignificantOther_DEFINED__
#define __WACContactSignificantOther_DEFINED__

WINRT_EXPORT
@interface WACContactSignificantOther : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* name;
@property (copy) NSString* description;
@property WACContactRelationship relationship;
@end

#endif // __WACContactSignificantOther_DEFINED__

// Windows.ApplicationModel.Contacts.ContactWebsite
#ifndef __WACContactWebsite_DEFINED__
#define __WACContactWebsite_DEFINED__

WINRT_EXPORT
@interface WACContactWebsite : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* uri;
@property (copy) NSString* description;
@property (copy) NSString* rawValue;
@end

#endif // __WACContactWebsite_DEFINED__

// Windows.ApplicationModel.Contacts.ContactChangedDeferral
#ifndef __WACContactChangedDeferral_DEFINED__
#define __WACContactChangedDeferral_DEFINED__

WINRT_EXPORT
@interface WACContactChangedDeferral : RTObject
- (void)complete;
@end

#endif // __WACContactChangedDeferral_DEFINED__

// Windows.ApplicationModel.Contacts.ContactChange
#ifndef __WACContactChange_DEFINED__
#define __WACContactChange_DEFINED__

WINRT_EXPORT
@interface WACContactChange : RTObject
@property (readonly) WACContactChangeType changeType;
@property (readonly) WACContact* contact;
@end

#endif // __WACContactChange_DEFINED__

// Windows.ApplicationModel.Contacts.ContactChangeReader
#ifndef __WACContactChangeReader_DEFINED__
#define __WACContactChangeReader_DEFINED__

WINRT_EXPORT
@interface WACContactChangeReader : RTObject
- (void)acceptChanges;
- (void)acceptChangesThrough:(WACContactChange*)lastChangeToAccept;
- (void)readBatchAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactChangeReader_DEFINED__

// Windows.ApplicationModel.Contacts.ContactBatch
#ifndef __WACContactBatch_DEFINED__
#define __WACContactBatch_DEFINED__

WINRT_EXPORT
@interface WACContactBatch : RTObject
@property (readonly) NSArray* contacts;
@property (readonly) WACContactBatchStatus status;
@end

#endif // __WACContactBatch_DEFINED__

// Windows.ApplicationModel.Contacts.ContactMatchReason
#ifndef __WACContactMatchReason_DEFINED__
#define __WACContactMatchReason_DEFINED__

WINRT_EXPORT
@interface WACContactMatchReason : RTObject
@property (readonly) WACContactMatchReasonKind field;
@property (readonly) NSArray* segments;
@property (readonly) NSString* text;
@end

#endif // __WACContactMatchReason_DEFINED__

// Windows.ApplicationModel.Contacts.ContactQueryTextSearch
#ifndef __WACContactQueryTextSearch_DEFINED__
#define __WACContactQueryTextSearch_DEFINED__

WINRT_EXPORT
@interface WACContactQueryTextSearch : RTObject
@property (copy) NSString* text;
@property WACContactQuerySearchScope searchScope;
@property WACContactQuerySearchFields fields;
@end

#endif // __WACContactQueryTextSearch_DEFINED__

// Windows.ApplicationModel.Contacts.ContactStoreNotificationTriggerDetails
#ifndef __WACContactStoreNotificationTriggerDetails_DEFINED__
#define __WACContactStoreNotificationTriggerDetails_DEFINED__

WINRT_EXPORT
@interface WACContactStoreNotificationTriggerDetails : RTObject
@end

#endif // __WACContactStoreNotificationTriggerDetails_DEFINED__

// Windows.ApplicationModel.Contacts.ContactManager
#ifndef __WACContactManager_DEFINED__
#define __WACContactManager_DEFINED__

WINRT_EXPORT
@interface WACContactManager : RTObject
+ (void)showContactCard:(WACContact*)contact selection:(WFRect*)selection;
+ (void)showContactCardWithPlacement:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
+ (WACContactCardDelayedDataLoader*)showDelayLoadedContactCard:(WACContact*)contact
                                                     selection:(WFRect*)selection
                                            preferredPlacement:(WUPPlacement)preferredPlacement;
+ (void)requestStoreAsyncWithSuccess:(void (^)(WACContactStore*))success failure:(void (^)(NSError*))failure;
+ (void)showContactCard:(WACContact*)contact selection:(WFRect*)selection;
+ (void)showContactCardWithPlacement:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
+ (WACContactCardDelayedDataLoader*)showDelayLoadedContactCard:(WACContact*)contact
                                                     selection:(WFRect*)selection
                                            preferredPlacement:(WUPPlacement)preferredPlacement;
+ (void)convertContactToVCardAsync:(WACContact*)contact
                           success:(void (^)(WSSRandomAccessStreamReference*))success
                           failure:(void (^)(NSError*))failure;
+ (void)convertContactToVCardAsyncWithMaxBytes:(WACContact*)contact
                                      maxBytes:(unsigned int)maxBytes
                                       success:(void (^)(WSSRandomAccessStreamReference*))success
                                       failure:(void (^)(NSError*))failure;
+ (void)convertVCardToContactAsync:(RTObject<WSSIRandomAccessStreamReference>*)vCard
                           success:(void (^)(WACContact*))success
                           failure:(void (^)(NSError*))failure;
+ (void)requestStoreAsyncWithAccessType:(WACContactStoreAccessType)accessType
                                success:(void (^)(WACContactStore*))success
                                failure:(void (^)(NSError*))failure;
+ (void)requestAnnotationStoreAsync:(WACContactAnnotationStoreAccessType)accessType
                            success:(void (^)(WACContactAnnotationStore*))success
                            failure:(void (^)(NSError*))failure;
+ (BOOL)isShowContactCardSupported;
+ (void)showContactCardWithOptions:(WACContact*)contact
                         selection:(WFRect*)selection
                preferredPlacement:(WUPPlacement)preferredPlacement
                contactCardOptions:(WACContactCardOptions*)contactCardOptions;
+ (BOOL)isShowDelayLoadedContactCardSupported;
+ (WACContactCardDelayedDataLoader*)showDelayLoadedContactCardWithOptions:(WACContact*)contact
                                                                selection:(WFRect*)selection
                                                       preferredPlacement:(WUPPlacement)preferredPlacement
                                                       contactCardOptions:(WACContactCardOptions*)contactCardOptions;
+ (void)showFullContactCard:(WACContact*)contact fullContactCardOptions:(WACFullContactCardOptions*)fullContactCardOptions;
+ (void)requestStoreAsyncWithSuccess:(void (^)(WACContactStore*))success failure:(void (^)(NSError*))failure;
+ (void)showContactCard:(WACContact*)contact selection:(WFRect*)selection;
+ (void)showContactCardWithPlacement:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
+ (WACContactCardDelayedDataLoader*)showDelayLoadedContactCard:(WACContact*)contact
                                                     selection:(WFRect*)selection
                                            preferredPlacement:(WUPPlacement)preferredPlacement;
+ (WACContactNameOrder)systemSortOrder;
+ (void)setSystemSortOrder:(WACContactNameOrder)value;
+ (WACContactNameOrder)systemDisplayNameOrder;
+ (void)setSystemDisplayNameOrder:(WACContactNameOrder)value;
@end

#endif // __WACContactManager_DEFINED__

// Windows.ApplicationModel.Contacts.ContactLaunchActionVerbs
#ifndef __WACContactLaunchActionVerbs_DEFINED__
#define __WACContactLaunchActionVerbs_DEFINED__

WINRT_EXPORT
@interface WACContactLaunchActionVerbs : RTObject
+ (NSString*)call;
+ (NSString*)map;
+ (NSString*)message;
+ (NSString*)post;
+ (NSString*)videoCall;
@end

#endif // __WACContactLaunchActionVerbs_DEFINED__

// Windows.ApplicationModel.Contacts.ContactField
#ifndef __WACContactField_DEFINED__
#define __WACContactField_DEFINED__

WINRT_EXPORT
@interface WACContactField : RTObject <WACIContactField>
+ (WACContactField*)createField_Default:(NSString*)value type:(WACContactFieldType)type ACTIVATOR;
+ (WACContactField*)createField_Category:(NSString*)value
                                    type:(WACContactFieldType)type
                                category:(WACContactFieldCategory)category ACTIVATOR;
+ (WACContactField*)createField_Custom:(NSString*)name
                                 value:(NSString*)value
                                  type:(WACContactFieldType)type
                              category:(WACContactFieldCategory)category ACTIVATOR;
@property (readonly) WACContactFieldCategory category;
@property (readonly) NSString* name;
@property (readonly) WACContactFieldType type;
@property (readonly) NSString* value;
@end

#endif // __WACContactField_DEFINED__

// Windows.ApplicationModel.Contacts.ContactLocationField
#ifndef __WACContactLocationField_DEFINED__
#define __WACContactLocationField_DEFINED__

WINRT_EXPORT
@interface WACContactLocationField : RTObject <WACIContactField>
+ (WACContactLocationField*)createLocation_Default:(NSString*)unstructuredAddress ACTIVATOR;
+ (WACContactLocationField*)createLocation_Category:(NSString*)unstructuredAddress category:(WACContactFieldCategory)category ACTIVATOR;
+ (WACContactLocationField*)createLocation_All:(NSString*)unstructuredAddress
                                      category:(WACContactFieldCategory)category
                                        street:(NSString*)street
                                          city:(NSString*)city
                                        region:(NSString*)region
                                       country:(NSString*)country
                                    postalCode:(NSString*)postalCode ACTIVATOR;
@property (readonly) WACContactFieldCategory category;
@property (readonly) NSString* name;
@property (readonly) WACContactFieldType type;
@property (readonly) NSString* value;
@property (readonly) NSString* city;
@property (readonly) NSString* country;
@property (readonly) NSString* postalCode;
@property (readonly) NSString* region;
@property (readonly) NSString* street;
@property (readonly) NSString* unstructuredAddress;
@end

#endif // __WACContactLocationField_DEFINED__

// Windows.ApplicationModel.Contacts.ContactInstantMessageField
#ifndef __WACContactInstantMessageField_DEFINED__
#define __WACContactInstantMessageField_DEFINED__

WINRT_EXPORT
@interface WACContactInstantMessageField : RTObject <WACIContactField>
+ (WACContactInstantMessageField*)createInstantMessage_Default:(NSString*)userName ACTIVATOR;
+ (WACContactInstantMessageField*)createInstantMessage_Category:(NSString*)userName category:(WACContactFieldCategory)category ACTIVATOR;
+ (WACContactInstantMessageField*)createInstantMessage_All:(NSString*)userName
                                                  category:(WACContactFieldCategory)category
                                                   service:(NSString*)service
                                               displayText:(NSString*)displayText
                                                      verb:(WFUri*)verb ACTIVATOR;
@property (readonly) WACContactFieldCategory category;
@property (readonly) NSString* name;
@property (readonly) WACContactFieldType type;
@property (readonly) NSString* value;
@property (readonly) NSString* displayText;
@property (readonly) WFUri* launchUri;
@property (readonly) NSString* service;
@property (readonly) NSString* userName;
@end

#endif // __WACContactInstantMessageField_DEFINED__

// Windows.ApplicationModel.Contacts.KnownContactField
#ifndef __WACKnownContactField_DEFINED__
#define __WACKnownContactField_DEFINED__

WINRT_EXPORT
@interface WACKnownContactField : RTObject
+ (WACContactFieldType)convertNameToType:(NSString*)name;
+ (NSString*)convertTypeToName:(WACContactFieldType)type;
+ (NSString*)email;
+ (NSString*)instantMessage;
+ (NSString*)location;
+ (NSString*)phoneNumber;
@end

#endif // __WACKnownContactField_DEFINED__

// Windows.ApplicationModel.Contacts.ContactInformation
#ifndef __WACContactInformation_DEFINED__
#define __WACContactInformation_DEFINED__

WINRT_EXPORT
@interface WACContactInformation : RTObject
@property (readonly) NSArray* customFields;
@property (readonly) NSArray* emails;
@property (readonly) NSArray* instantMessages;
@property (readonly) NSArray* locations;
@property (readonly) NSString* name;
@property (readonly) NSArray* phoneNumbers;
- (void)getThumbnailAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success
                             failure:(void (^)(NSError*))failure;
- (NSArray*)queryCustomFields:(NSString*)customName;
@end

#endif // __WACContactInformation_DEFINED__

// Windows.ApplicationModel.Contacts.ContactFieldFactory
#ifndef __WACContactFieldFactory_DEFINED__
#define __WACContactFieldFactory_DEFINED__

WINRT_EXPORT
@interface WACContactFieldFactory
    : RTObject <WACIContactFieldFactory, WACIContactLocationFieldFactory, WACIContactInstantMessageFieldFactory>
+ (instancetype)create ACTIVATOR;
- (WACContactField*)createField_Default:(NSString*)value type:(WACContactFieldType)type;
- (WACContactField*)createField_Category:(NSString*)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category;
- (WACContactField*)createField_Custom:(NSString*)name
                                 value:(NSString*)value
                                  type:(WACContactFieldType)type
                              category:(WACContactFieldCategory)category;
- (WACContactLocationField*)createLocation_Default:(NSString*)unstructuredAddress;
- (WACContactLocationField*)createLocation_Category:(NSString*)unstructuredAddress category:(WACContactFieldCategory)category;
- (WACContactLocationField*)createLocation_All:(NSString*)unstructuredAddress
                                      category:(WACContactFieldCategory)category
                                        street:(NSString*)street
                                          city:(NSString*)city
                                        region:(NSString*)region
                                       country:(NSString*)country
                                    postalCode:(NSString*)postalCode;
- (WACContactInstantMessageField*)createInstantMessage_Default:(NSString*)userName;
- (WACContactInstantMessageField*)createInstantMessage_Category:(NSString*)userName category:(WACContactFieldCategory)category;
- (WACContactInstantMessageField*)createInstantMessage_All:(NSString*)userName
                                                  category:(WACContactFieldCategory)category
                                                   service:(NSString*)service
                                               displayText:(NSString*)displayText
                                                      verb:(WFUri*)verb;
@end

#endif // __WACContactFieldFactory_DEFINED__

// Windows.ApplicationModel.Contacts.ContactPicker
#ifndef __WACContactPicker_DEFINED__
#define __WACContactPicker_DEFINED__

WINRT_EXPORT
@interface WACContactPicker : RTObject
+ (instancetype)create ACTIVATOR;
@property WACContactSelectionMode selectionMode;
@property (copy) NSString* commitButtonText;
@property (readonly) NSMutableArray* desiredFields;
@property (readonly) NSMutableArray* desiredFieldsWithContactFieldType;
- (void)pickSingleContactAsyncWithSuccess:(void (^)(WACContactInformation*))success failure:(void (^)(NSError*))failure;
- (void)pickMultipleContactsAsyncWithSuccess:(void (^)(NSArray*))success failure:(void (^)(NSError*))failure;
- (void)pickContactAsyncWithSuccess:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (void)pickContactsAsyncWithSuccess:(void (^)(NSMutableArray*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactPicker_DEFINED__
