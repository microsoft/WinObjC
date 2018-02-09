//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#ifndef OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
#define OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsConsolidatedNamespace.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WACContactCardDelayedDataLoader, WACContactStore, WACContactAnnotationStore, WACContactCardOptions, WACFullContactCardOptions, WACContactManagerForUser, WACContactAnnotation, WACContactAnnotationList, WACContactChangeTracker, WACContactChangedEventArgs, WACAggregateContactManager, WACContactList, WACContactReader, WACContactQueryOptions, WACContactListSyncManager, WACContactListSyncConstraints, WACContactListLimitedWriteOperations, WACContactChangedDeferral, WACContactChange, WACContactChangeReader, WACContactBatch, WACContactMatchReason, WACContactQueryTextSearch, WACContactStoreNotificationTriggerDetails, WACContactManager, WACContactLaunchActionVerbs, WACContactGroup, WACContactPicker, WACContactPhone, WACContactEmail, WACContactAddress, WACContactConnectedServiceAccount, WACContactDate, WACContactJobInfo, WACContactSignificantOther, WACContactWebsite, WACContact, WACContactField, WACContactLocationField, WACContactInstantMessageField, WACKnownContactField, WACContactInformation, WACContactFieldFactory, WACPinnedContactIdsQueryResult, WACPinnedContactManager, WACContactPanelLaunchFullAppRequestedEventArgs, WACContactPanelClosingEventArgs, WACContactPanel;
@protocol WACIContactCardOptions, WACIContactCardOptions2, WACIFullContactCardOptions, WACIContactCardDelayedDataLoader, WACIContactManagerStatics, WACIContactManagerStatics2, WACIContactManagerStatics3, WACIContactManagerStatics4, WACIContactManagerStatics5, WACIContactManagerForUser, WACIContactManagerForUser2, WACIAggregateContactManager, WACIAggregateContactManager2, WACIContactAnnotationStore, WACIContactAnnotationStore2, WACIContactAnnotationList, WACIContactAnnotation, WACIContactAnnotation2, WACIContactStoreNotificationTriggerDetails, WACIContactStore, WACIContactStore2, WACIContactStore3, WACIContactList, WACIContactList2, WACIContactList3, WACIContactListLimitedWriteOperations, WACIContactListSyncManager, WACIContactListSyncManager2, WACIContactListSyncConstraints, WACIContactChange, WACIContactChangedDeferral, WACIContactChangedEventArgs, WACIContactChangeReader, WACIContactChangeTracker, WACIContactChangeTracker2, WACIContactReader, WACIContactQueryTextSearch, WACIContactQueryOptionsFactory, WACIContactQueryOptions, WACIContactBatch, WACIContactMatchReason, WACIContactLaunchActionVerbsStatics, WACIContactGroup, WACIContactPicker, WACIContactPicker2, WACIContactPicker3, WACIContactPickerStatics, WACIContactConnectedServiceAccount, WACIContactSignificantOther, WACIContactSignificantOther2, WACIContactWebsite, WACIContactWebsite2, WACIContactEmail, WACIContactPhone, WACIContactAddress, WACIContactDate, WACIContactJobInfo, WACIContact, WACIContactField, WACIContactName, WACIContact2, WACIContact3, WACIContactLocationField, WACIContactInstantMessageField, WACIKnownContactFieldStatics, WACIContactInformation, WACIContactFieldFactory, WACIContactLocationFieldFactory, WACIContactInstantMessageFieldFactory, WACIPinnedContactIdsQueryResult, WACIPinnedContactManagerStatics, WACIPinnedContactManager, WACIContactPanelLaunchFullAppRequestedEventArgs, WACIContactPanelClosingEventArgs, WACIContactPanel;

// Windows.ApplicationModel.Contacts.ContactSelectionMode
enum _WACContactSelectionMode {
    WACContactSelectionModeContacts = 0,
    WACContactSelectionModeFields = 1,
};
typedef unsigned WACContactSelectionMode;

// Windows.ApplicationModel.Contacts.ContactChangeType
enum _WACContactChangeType {
    WACContactChangeTypeCreated = 0,
    WACContactChangeTypeModified = 1,
    WACContactChangeTypeDeleted = 2,
    WACContactChangeTypeChangeTrackingLost = 3,
};
typedef unsigned WACContactChangeType;

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
    WACContactListOtherAppReadAccessNone = 3,
};
typedef unsigned WACContactListOtherAppReadAccess;

// Windows.ApplicationModel.Contacts.ContactListOtherAppWriteAccess
enum _WACContactListOtherAppWriteAccess {
    WACContactListOtherAppWriteAccessNone = 0,
    WACContactListOtherAppWriteAccessSystemOnly = 1,
    WACContactListOtherAppWriteAccessLimited = 2,
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
    WACContactAnnotationOperationsShare = 32,
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
    WACContactListSyncStatusManualAccountRemovalRequired = 6,
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
    WACContactCardTabKindOrganizationalHierarchy = 5,
};
typedef unsigned WACContactCardTabKind;

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

// Windows.ApplicationModel.Contacts.ContactFieldCategory
enum _WACContactFieldCategory {
    WACContactFieldCategoryNone = 0,
    WACContactFieldCategoryHome = 1,
    WACContactFieldCategoryWork = 2,
    WACContactFieldCategoryMobile = 3,
    WACContactFieldCategoryOther = 4,
};
typedef unsigned WACContactFieldCategory;

// Windows.ApplicationModel.Contacts.PinnedContactSurface
enum _WACPinnedContactSurface {
    WACPinnedContactSurfaceStartMenu = 0,
    WACPinnedContactSurfaceTaskbar = 1,
};
typedef unsigned WACPinnedContactSurface;

#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsUI.h"
#include "WindowsUIViewManagement.h"
#include "WindowsDataText.h"
#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"
#include "WindowsSystem.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.Contacts.IContactField
#ifndef __WACIContactField_DEFINED__
#define __WACIContactField_DEFINED__

@protocol WACIContactField
@property (readonly) WACContactFieldCategory category;
@property (readonly) NSString * name;
@property (readonly) WACContactFieldType type;
@property (readonly) NSString * value;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACIContactField : RTObject <WACIContactField>
@end

#endif // __WACIContactField_DEFINED__

// Windows.ApplicationModel.Contacts.IContactFieldFactory
#ifndef __WACIContactFieldFactory_DEFINED__
#define __WACIContactFieldFactory_DEFINED__

@protocol WACIContactFieldFactory
- (WACContactField*)createField_Default:(NSString *)value type:(WACContactFieldType)type;
- (WACContactField*)createField_Category:(NSString *)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category;
- (WACContactField*)createField_Custom:(NSString *)name value:(NSString *)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACIContactFieldFactory : RTObject <WACIContactFieldFactory>
@end

#endif // __WACIContactFieldFactory_DEFINED__

// Windows.ApplicationModel.Contacts.IContactLocationFieldFactory
#ifndef __WACIContactLocationFieldFactory_DEFINED__
#define __WACIContactLocationFieldFactory_DEFINED__

@protocol WACIContactLocationFieldFactory
- (WACContactLocationField*)createLocation_Default:(NSString *)unstructuredAddress;
- (WACContactLocationField*)createLocation_Category:(NSString *)unstructuredAddress category:(WACContactFieldCategory)category;
- (WACContactLocationField*)createLocation_All:(NSString *)unstructuredAddress category:(WACContactFieldCategory)category street:(NSString *)street city:(NSString *)city region:(NSString *)region country:(NSString *)country postalCode:(NSString *)postalCode;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACIContactLocationFieldFactory : RTObject <WACIContactLocationFieldFactory>
@end

#endif // __WACIContactLocationFieldFactory_DEFINED__

// Windows.ApplicationModel.Contacts.IContactInstantMessageFieldFactory
#ifndef __WACIContactInstantMessageFieldFactory_DEFINED__
#define __WACIContactInstantMessageFieldFactory_DEFINED__

@protocol WACIContactInstantMessageFieldFactory
- (WACContactInstantMessageField*)createInstantMessage_Default:(NSString *)userName;
- (WACContactInstantMessageField*)createInstantMessage_Category:(NSString *)userName category:(WACContactFieldCategory)category;
- (WACContactInstantMessageField*)createInstantMessage_All:(NSString *)userName category:(WACContactFieldCategory)category service:(NSString *)service displayText:(NSString *)displayText verb:(WFUri*)verb;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACIContactInstantMessageFieldFactory : RTObject <WACIContactInstantMessageFieldFactory>
@end

#endif // __WACIContactInstantMessageFieldFactory_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.ApplicationModel.Contacts.ContactCardDelayedDataLoader
#ifndef __WACContactCardDelayedDataLoader_DEFINED__
#define __WACContactCardDelayedDataLoader_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactCardDelayedDataLoader : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)setData:(WACContact*)contact;
- (void)close;
@end

#endif // __WACContactCardDelayedDataLoader_DEFINED__

// Windows.ApplicationModel.Contacts.ContactStore
#ifndef __WACContactStore_DEFINED__
#define __WACContactStore_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactStore : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WACAggregateContactManager* aggregateContactManager;
@property (readonly) WACContactChangeTracker* changeTracker;
- (EventRegistrationToken)addContactChangedEvent:(void(^)(WACContactStore*, WACContactChangedEventArgs*))del;
- (void)removeContactChangedEvent:(EventRegistrationToken)tok;
- (void)findContactsAsyncWithSuccess:(void (^)(NSArray* /* WACContact* */))success failure:(void (^)(NSError*))failure;
- (void)findContactsWithSearchTextAsync:(NSString *)searchText success:(void (^)(NSArray* /* WACContact* */))success failure:(void (^)(NSError*))failure;
- (void)getContactAsync:(NSString *)contactId success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (void)findContactListsAsyncWithSuccess:(void (^)(NSArray* /* WACContactList* */))success failure:(void (^)(NSError*))failure;
- (void)getContactListAsync:(NSString *)contactListId success:(void (^)(WACContactList*))success failure:(void (^)(NSError*))failure;
- (void)createContactListAsync:(NSString *)displayName success:(void (^)(WACContactList*))success failure:(void (^)(NSError*))failure;
- (void)getMeContactAsyncWithSuccess:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (WACContactReader*)getContactReader;
- (WACContactReader*)getContactReaderWithOptions:(WACContactQueryOptions*)options;
- (void)createContactListInAccountAsync:(NSString *)displayName userDataAccountId:(NSString *)userDataAccountId success:(void (^)(WACContactList*))success failure:(void (^)(NSError*))failure;
- (WACContactChangeTracker*)getChangeTracker:(NSString *)identity;
@end

#endif // __WACContactStore_DEFINED__

// Windows.ApplicationModel.Contacts.ContactAnnotationStore
#ifndef __WACContactAnnotationStore_DEFINED__
#define __WACContactAnnotationStore_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactAnnotationStore : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)findContactIdsByEmailAsync:(NSString *)emailAddress success:(void (^)(NSArray* /* NSString * */))success failure:(void (^)(NSError*))failure;
- (void)findContactIdsByPhoneNumberAsync:(NSString *)phoneNumber success:(void (^)(NSArray* /* NSString * */))success failure:(void (^)(NSError*))failure;
- (void)findAnnotationsForContactAsync:(WACContact*)contact success:(void (^)(NSArray* /* WACContactAnnotation* */))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)disableAnnotationAsync:(WACContactAnnotation*)annotation;
- (void)createAnnotationListAsyncWithSuccess:(void (^)(WACContactAnnotationList*))success failure:(void (^)(NSError*))failure;
- (void)createAnnotationListInAccountAsync:(NSString *)userDataAccountId success:(void (^)(WACContactAnnotationList*))success failure:(void (^)(NSError*))failure;
- (void)getAnnotationListAsync:(NSString *)annotationListId success:(void (^)(WACContactAnnotationList*))success failure:(void (^)(NSError*))failure;
- (void)findAnnotationListsAsyncWithSuccess:(void (^)(NSArray* /* WACContactAnnotationList* */))success failure:(void (^)(NSError*))failure;
- (void)findAnnotationsForContactListAsync:(NSString *)contactListId success:(void (^)(NSArray* /* WACContactAnnotation* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactAnnotationStore_DEFINED__

// Windows.ApplicationModel.Contacts.ContactCardOptions
#ifndef __WACContactCardOptions_DEFINED__
#define __WACContactCardOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactCardOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WACContactCardTabKind initialTabKind;
@property WACContactCardHeaderKind headerKind;
@property (readonly) NSMutableArray* /* NSString * */ serverSearchContactListIds;
@end

#endif // __WACContactCardOptions_DEFINED__

// Windows.ApplicationModel.Contacts.FullContactCardOptions
#ifndef __WACFullContactCardOptions_DEFINED__
#define __WACFullContactCardOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACFullContactCardOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUVViewSizePreference desiredRemainingView;
@end

#endif // __WACFullContactCardOptions_DEFINED__

// Windows.ApplicationModel.Contacts.ContactManagerForUser
#ifndef __WACContactManagerForUser_DEFINED__
#define __WACContactManagerForUser_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactManagerForUser : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WACContactNameOrder systemSortOrder;
@property WACContactNameOrder systemDisplayNameOrder;
@property (readonly) WSUser* user;
- (void)convertContactToVCardAsync:(WACContact*)contact success:(void (^)(WSSRandomAccessStreamReference*))success failure:(void (^)(NSError*))failure;
- (void)convertContactToVCardAsyncWithMaxBytes:(WACContact*)contact maxBytes:(unsigned int)maxBytes success:(void (^)(WSSRandomAccessStreamReference*))success failure:(void (^)(NSError*))failure;
- (void)convertVCardToContactAsync:(RTObject<WSSIRandomAccessStreamReference>*)vCard success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (void)requestStoreAsync:(WACContactStoreAccessType)accessType success:(void (^)(WACContactStore*))success failure:(void (^)(NSError*))failure;
- (void)requestAnnotationStoreAsync:(WACContactAnnotationStoreAccessType)accessType success:(void (^)(WACContactAnnotationStore*))success failure:(void (^)(NSError*))failure;
- (void)showFullContactCard:(WACContact*)contact fullContactCardOptions:(WACFullContactCardOptions*)fullContactCardOptions;
@end

#endif // __WACContactManagerForUser_DEFINED__

// Windows.ApplicationModel.Contacts.ContactAnnotation
#ifndef __WACContactAnnotation_DEFINED__
#define __WACContactAnnotation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactAnnotation : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WACContactAnnotationOperations supportedOperations;
@property (retain) NSString * remoteId;
@property (retain) NSString * contactId;
@property (readonly) NSString * annotationListId;
@property (readonly) NSString * id;
@property (readonly) BOOL isDisabled;
@property (readonly) WFCValueSet* providerProperties;
@property (retain) NSString * contactListId;
@end

#endif // __WACContactAnnotation_DEFINED__

// Windows.ApplicationModel.Contacts.ContactAnnotationList
#ifndef __WACContactAnnotationList_DEFINED__
#define __WACContactAnnotationList_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactAnnotationList : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * id;
@property (readonly) NSString * providerPackageFamilyName;
@property (readonly) NSString * userDataAccountId;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (void)trySaveAnnotationAsync:(WACContactAnnotation*)annotation success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)getAnnotationAsync:(NSString *)annotationId success:(void (^)(WACContactAnnotation*))success failure:(void (^)(NSError*))failure;
- (void)findAnnotationsByRemoteIdAsync:(NSString *)remoteId success:(void (^)(NSArray* /* WACContactAnnotation* */))success failure:(void (^)(NSError*))failure;
- (void)findAnnotationsAsyncWithSuccess:(void (^)(NSArray* /* WACContactAnnotation* */))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)deleteAnnotationAsync:(WACContactAnnotation*)annotation;
@end

#endif // __WACContactAnnotationList_DEFINED__

// Windows.ApplicationModel.Contacts.ContactChangeTracker
#ifndef __WACContactChangeTracker_DEFINED__
#define __WACContactChangeTracker_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactChangeTracker : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isTracking;
- (void)enable;
- (WACContactChangeReader*)getChangeReader;
- (void)reset;
@end

#endif // __WACContactChangeTracker_DEFINED__

// Windows.ApplicationModel.Contacts.ContactChangedEventArgs
#ifndef __WACContactChangedEventArgs_DEFINED__
#define __WACContactChangedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WACContactChangedDeferral*)getDeferral;
@end

#endif // __WACContactChangedEventArgs_DEFINED__

// Windows.ApplicationModel.Contacts.AggregateContactManager
#ifndef __WACAggregateContactManager_DEFINED__
#define __WACAggregateContactManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACAggregateContactManager : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)findRawContactsAsync:(WACContact*)contact success:(void (^)(NSArray* /* WACContact* */))success failure:(void (^)(NSError*))failure;
- (void)tryLinkContactsAsync:(WACContact*)primaryContact secondaryContact:(WACContact*)secondaryContact success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)unlinkRawContactAsync:(WACContact*)contact;
- (void)trySetPreferredSourceForPictureAsync:(WACContact*)aggregateContact rawContact:(WACContact*)rawContact success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)setRemoteIdentificationInformationAsync:(NSString *)contactListId remoteSourceId:(NSString *)remoteSourceId accountId:(NSString *)accountId;
@end

#endif // __WACAggregateContactManager_DEFINED__

// Windows.ApplicationModel.Contacts.ContactList
#ifndef __WACContactList_DEFINED__
#define __WACContactList_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactList : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL supportsServerSearch;
@property BOOL isHidden;
@property WACContactListOtherAppWriteAccess otherAppWriteAccess;
@property (retain) NSString * displayName;
@property WACContactListOtherAppReadAccess otherAppReadAccess;
@property (readonly) WACContactChangeTracker* changeTracker;
@property (readonly) NSString * sourceDisplayName;
@property (readonly) NSString * id;
@property (readonly) WACContactListSyncManager* syncManager;
@property (readonly) NSString * userDataAccountId;
@property (readonly) WACContactListSyncConstraints* syncConstraints;
@property (readonly) WACContactListLimitedWriteOperations* limitedWriteOperations;
- (EventRegistrationToken)addContactChangedEvent:(void(^)(WACContactList*, WACContactChangedEventArgs*))del;
- (void)removeContactChangedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)saveAsync;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (void)getContactFromRemoteIdAsync:(NSString *)remoteId success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (void)getMeContactAsyncWithSuccess:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (WACContactReader*)getContactReader;
- (WACContactReader*)getContactReaderWithOptions:(WACContactQueryOptions*)options;
- (RTObject<WFIAsyncAction>*)saveContactAsync:(WACContact*)contact;
- (RTObject<WFIAsyncAction>*)deleteContactAsync:(WACContact*)contact;
- (void)getContactAsync:(NSString *)contactId success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)registerSyncManagerAsync;
- (WACContactChangeTracker*)getChangeTracker:(NSString *)identity;
@end

#endif // __WACContactList_DEFINED__

// Windows.ApplicationModel.Contacts.ContactReader
#ifndef __WACContactReader_DEFINED__
#define __WACContactReader_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactReader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)readBatchAsyncWithSuccess:(void (^)(WACContactBatch*))success failure:(void (^)(NSError*))failure;
- (NSArray* /* WACContactMatchReason* */)getMatchingPropertiesWithMatchReason:(WACContact*)contact;
@end

#endif // __WACContactReader_DEFINED__

// Windows.ApplicationModel.Contacts.ContactQueryOptions
#ifndef __WACContactQueryOptions_DEFINED__
#define __WACContactQueryOptions_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactQueryOptions : RTObject
+ (WACContactQueryOptions*)makeWithText:(NSString *)text ACTIVATOR;
+ (WACContactQueryOptions*)makeWithTextAndFields:(NSString *)text fields:(WACContactQuerySearchFields)fields ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL includeContactsFromHiddenLists;
@property WACContactAnnotationOperations desiredOperations;
@property WACContactQueryDesiredFields desiredFields;
@property (readonly) NSMutableArray* /* NSString * */ annotationListIds;
@property (readonly) NSMutableArray* /* NSString * */ contactListIds;
@property (readonly) WACContactQueryTextSearch* textSearch;
@end

#endif // __WACContactQueryOptions_DEFINED__

// Windows.ApplicationModel.Contacts.ContactListSyncManager
#ifndef __WACContactListSyncManager_DEFINED__
#define __WACContactListSyncManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactListSyncManager : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WACContactListSyncStatus status;
@property (retain) WFDateTime* lastSuccessfulSyncTime;
@property (retain) WFDateTime* lastAttemptedSyncTime;
- (EventRegistrationToken)addSyncStatusChangedEvent:(void(^)(WACContactListSyncManager*, RTObject*))del;
- (void)removeSyncStatusChangedEvent:(EventRegistrationToken)tok;
- (void)syncAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactListSyncManager_DEFINED__

// Windows.ApplicationModel.Contacts.ContactListSyncConstraints
#ifndef __WACContactListSyncConstraints_DEFINED__
#define __WACContactListSyncConstraints_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactListSyncConstraints : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL canSyncDescriptions;
@property (retain) id /* int */ maxCompanyPhoneNumbers;
@property (retain) id /* int */ maxChildRelationships;
@property (retain) id /* int */ maxBusinessFaxPhoneNumbers;
@property (retain) id /* int */ maxBirthdayDates;
@property (retain) id /* int */ maxAssistantPhoneNumbers;
@property (retain) id /* int */ maxOtherAddresses;
@property (retain) id /* int */ maxAnniversaryDates;
@property (retain) id /* int */ maxHomeAddresses;
@property (retain) id /* int */ maxOtherDates;
@property (retain) id /* int */ maxMobilePhoneNumbers;
@property (retain) id /* int */ maxJobInfo;
@property (retain) id /* int */ maxHomePhoneNumbers;
@property (retain) id /* int */ maxHomeFaxPhoneNumbers;
@property (retain) id /* int */ maxOtherEmailAddresses;
@property (retain) id /* int */ maxPersonalEmailAddresses;
@property (retain) id /* int */ maxPartnerRelationships;
@property (retain) id /* int */ maxParentRelationships;
@property (retain) id /* int */ maxPagerPhoneNumbers;
@property (retain) id /* int */ maxOtherRelationships;
@property (retain) id /* int */ maxOtherPhoneNumbers;
@property (retain) id /* int */ maxRadioPhoneNumbers;
@property (retain) id /* int */ maxWorkPhoneNumbers;
@property (retain) id /* int */ maxWorkEmailAddresses;
@property (retain) id /* int */ maxWorkAddresses;
@property (retain) id /* int */ maxWebsites;
@property (retain) id /* int */ maxSpouseRelationships;
@property (retain) id /* int */ maxSiblingRelationships;
@end

#endif // __WACContactListSyncConstraints_DEFINED__

// Windows.ApplicationModel.Contacts.ContactListLimitedWriteOperations
#ifndef __WACContactListLimitedWriteOperations_DEFINED__
#define __WACContactListLimitedWriteOperations_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactListLimitedWriteOperations : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)tryCreateOrUpdateContactAsync:(WACContact*)contact success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)tryDeleteContactAsync:(NSString *)contactId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactListLimitedWriteOperations_DEFINED__

// Windows.ApplicationModel.Contacts.ContactChangedDeferral
#ifndef __WACContactChangedDeferral_DEFINED__
#define __WACContactChangedDeferral_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactChangedDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WACContactChangedDeferral_DEFINED__

// Windows.ApplicationModel.Contacts.ContactChange
#ifndef __WACContactChange_DEFINED__
#define __WACContactChange_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactChange : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WACContactChangeType changeType;
@property (readonly) WACContact* contact;
@end

#endif // __WACContactChange_DEFINED__

// Windows.ApplicationModel.Contacts.ContactChangeReader
#ifndef __WACContactChangeReader_DEFINED__
#define __WACContactChangeReader_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactChangeReader : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)acceptChanges;
- (void)acceptChangesThrough:(WACContactChange*)lastChangeToAccept;
- (void)readBatchAsyncWithSuccess:(void (^)(NSArray* /* WACContactChange* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactChangeReader_DEFINED__

// Windows.ApplicationModel.Contacts.ContactBatch
#ifndef __WACContactBatch_DEFINED__
#define __WACContactBatch_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactBatch : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WACContact* */ contacts;
@property (readonly) WACContactBatchStatus status;
@end

#endif // __WACContactBatch_DEFINED__

// Windows.ApplicationModel.Contacts.ContactMatchReason
#ifndef __WACContactMatchReason_DEFINED__
#define __WACContactMatchReason_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactMatchReason : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WACContactMatchReasonKind field;
@property (readonly) NSArray* /* WDTTextSegment* */ segments;
@property (readonly) NSString * text;
@end

#endif // __WACContactMatchReason_DEFINED__

// Windows.ApplicationModel.Contacts.ContactQueryTextSearch
#ifndef __WACContactQueryTextSearch_DEFINED__
#define __WACContactQueryTextSearch_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactQueryTextSearch : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * text;
@property WACContactQuerySearchScope searchScope;
@property WACContactQuerySearchFields fields;
@end

#endif // __WACContactQueryTextSearch_DEFINED__

// Windows.ApplicationModel.Contacts.ContactStoreNotificationTriggerDetails
#ifndef __WACContactStoreNotificationTriggerDetails_DEFINED__
#define __WACContactStoreNotificationTriggerDetails_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactStoreNotificationTriggerDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WACContactStoreNotificationTriggerDetails_DEFINED__

// Windows.ApplicationModel.Contacts.ContactManager
#ifndef __WACContactManager_DEFINED__
#define __WACContactManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactManager : RTObject
+ (void)showContactCard:(WACContact*)contact selection:(WFRect*)selection;
+ (void)showContactCardWithPlacement:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
+ (WACContactCardDelayedDataLoader*)showDelayLoadedContactCard:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
+ (void)convertContactToVCardAsync:(WACContact*)contact success:(void (^)(WSSRandomAccessStreamReference*))success failure:(void (^)(NSError*))failure;
+ (void)convertContactToVCardAsyncWithMaxBytes:(WACContact*)contact maxBytes:(unsigned int)maxBytes success:(void (^)(WSSRandomAccessStreamReference*))success failure:(void (^)(NSError*))failure;
+ (void)convertVCardToContactAsync:(RTObject<WSSIRandomAccessStreamReference>*)vCard success:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
+ (void)requestStoreAsyncWithAccessType:(WACContactStoreAccessType)accessType success:(void (^)(WACContactStore*))success failure:(void (^)(NSError*))failure;
+ (void)requestAnnotationStoreAsync:(WACContactAnnotationStoreAccessType)accessType success:(void (^)(WACContactAnnotationStore*))success failure:(void (^)(NSError*))failure;
+ (BOOL)isShowContactCardSupported;
+ (void)showContactCardWithOptions:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement contactCardOptions:(WACContactCardOptions*)contactCardOptions;
+ (BOOL)isShowDelayLoadedContactCardSupported;
+ (WACContactCardDelayedDataLoader*)showDelayLoadedContactCardWithOptions:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement contactCardOptions:(WACContactCardOptions*)contactCardOptions;
+ (void)showFullContactCard:(WACContact*)contact fullContactCardOptions:(WACFullContactCardOptions*)fullContactCardOptions;
+ (void)requestStoreAsyncWithSuccess:(void (^)(WACContactStore*))success failure:(void (^)(NSError*))failure;
+ (void)showContactCard:(WACContact*)contact selection:(WFRect*)selection;
+ (void)showContactCardWithPlacement:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
+ (WACContactCardDelayedDataLoader*)showDelayLoadedContactCard:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
+ (void)isShowFullContactCardSupportedAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (WACContactManagerForUser*)getForUser:(WSUser*)user;
+ (void)requestStoreAsyncWithSuccess:(void (^)(WACContactStore*))success failure:(void (^)(NSError*))failure;
+ (void)showContactCard:(WACContact*)contact selection:(WFRect*)selection;
+ (void)showContactCardWithPlacement:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
+ (WACContactCardDelayedDataLoader*)showDelayLoadedContactCard:(WACContact*)contact selection:(WFRect*)selection preferredPlacement:(WUPPlacement)preferredPlacement;
+ (WACContactNameOrder)systemSortOrder;
+ (void)setSystemSortOrder:(WACContactNameOrder)value;
+ (WACContactNameOrder)systemDisplayNameOrder;
+ (void)setSystemDisplayNameOrder:(WACContactNameOrder)value;
+ (BOOL)includeMiddleNameInSystemDisplayAndSort;
+ (void)setIncludeMiddleNameInSystemDisplayAndSort:(BOOL)value;
@end

#endif // __WACContactManager_DEFINED__

// Windows.ApplicationModel.Contacts.ContactLaunchActionVerbs
#ifndef __WACContactLaunchActionVerbs_DEFINED__
#define __WACContactLaunchActionVerbs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactLaunchActionVerbs : RTObject
+ (NSString *)call;
+ (NSString *)map;
+ (NSString *)message;
+ (NSString *)post;
+ (NSString *)videoCall;
@end

#endif // __WACContactLaunchActionVerbs_DEFINED__

// Windows.ApplicationModel.Contacts.ContactGroup
#ifndef __WACContactGroup_DEFINED__
#define __WACContactGroup_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactGroup : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WACContactGroup_DEFINED__

// Windows.ApplicationModel.Contacts.ContactPicker
#ifndef __WACContactPicker_DEFINED__
#define __WACContactPicker_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactPicker : RTObject
+ (WACContactPicker*)createForUser:(WSUser*)user;
+ (void)isSupportedAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WACContactSelectionMode selectionMode;
@property (retain) NSString * commitButtonText;
@property (readonly) NSMutableArray* /* NSString * */ desiredFields;
@property (readonly) NSMutableArray* /* WACContactFieldType */ desiredFieldsWithContactFieldType;
@property (readonly) WSUser* user;
- (void)pickSingleContactAsyncWithSuccess:(void (^)(WACContactInformation*))success failure:(void (^)(NSError*))failure;
- (void)pickMultipleContactsAsyncWithSuccess:(void (^)(NSArray* /* WACContactInformation* */))success failure:(void (^)(NSError*))failure;
- (void)pickContactAsyncWithSuccess:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (void)pickContactsAsyncWithSuccess:(void (^)(NSMutableArray* /* WACContact* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactPicker_DEFINED__

// Windows.ApplicationModel.Contacts.ContactPhone
#ifndef __WACContactPhone_DEFINED__
#define __WACContactPhone_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactPhone : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * number;
@property WACContactPhoneKind kind;
@property (retain) NSString * Description;
@end

#endif // __WACContactPhone_DEFINED__

// Windows.ApplicationModel.Contacts.ContactEmail
#ifndef __WACContactEmail_DEFINED__
#define __WACContactEmail_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactEmail : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WACContactEmailKind kind;
@property (retain) NSString * Description;
@property (retain) NSString * address;
@end

#endif // __WACContactEmail_DEFINED__

// Windows.ApplicationModel.Contacts.ContactAddress
#ifndef __WACContactAddress_DEFINED__
#define __WACContactAddress_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactAddress : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * streetAddress;
@property (retain) NSString * region;
@property (retain) NSString * postalCode;
@property (retain) NSString * locality;
@property WACContactAddressKind kind;
@property (retain) NSString * Description;
@property (retain) NSString * country;
@end

#endif // __WACContactAddress_DEFINED__

// Windows.ApplicationModel.Contacts.ContactConnectedServiceAccount
#ifndef __WACContactConnectedServiceAccount_DEFINED__
#define __WACContactConnectedServiceAccount_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactConnectedServiceAccount : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * serviceName;
@property (retain) NSString * id;
@end

#endif // __WACContactConnectedServiceAccount_DEFINED__

// Windows.ApplicationModel.Contacts.ContactDate
#ifndef __WACContactDate_DEFINED__
#define __WACContactDate_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactDate : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* int */ year;
@property (retain) id /* unsigned int */ month;
@property WACContactDateKind kind;
@property (retain) NSString * Description;
@property (retain) id /* unsigned int */ day;
@end

#endif // __WACContactDate_DEFINED__

// Windows.ApplicationModel.Contacts.ContactJobInfo
#ifndef __WACContactJobInfo_DEFINED__
#define __WACContactJobInfo_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactJobInfo : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * title;
@property (retain) NSString * office;
@property (retain) NSString * manager;
@property (retain) NSString * Description;
@property (retain) NSString * department;
@property (retain) NSString * companyYomiName;
@property (retain) NSString * companyName;
@property (retain) NSString * companyAddress;
@end

#endif // __WACContactJobInfo_DEFINED__

// Windows.ApplicationModel.Contacts.ContactSignificantOther
#ifndef __WACContactSignificantOther_DEFINED__
#define __WACContactSignificantOther_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactSignificantOther : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * name;
@property (retain) NSString * Description;
@property WACContactRelationship relationship;
@end

#endif // __WACContactSignificantOther_DEFINED__

// Windows.ApplicationModel.Contacts.ContactWebsite
#ifndef __WACContactWebsite_DEFINED__
#define __WACContactWebsite_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactWebsite : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* uri;
@property (retain) NSString * Description;
@property (retain) NSString * rawValue;
@end

#endif // __WACContactWebsite_DEFINED__

// Windows.ApplicationModel.Contacts.Contact
#ifndef __WACContact_DEFINED__
#define __WACContact_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContact : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject<WSSIRandomAccessStreamReference>* thumbnail;
@property (retain) NSString * name;
@property (readonly) NSMutableArray* /* RTObject<WACIContactField>* */ fields;
@property (retain) NSString * id;
@property (retain) NSString * notes;
@property (readonly) NSMutableArray* /* WACContactConnectedServiceAccount* */ connectedServiceAccounts;
@property (readonly) NSMutableArray* /* WACContactEmail* */ emails;
@property (readonly) NSMutableArray* /* WACContactAddress* */ addresses;
@property (readonly) NSMutableArray* /* WACContactDate* */ importantDates;
@property (readonly) NSMutableArray* /* WACContactJobInfo* */ jobInfo;
@property (readonly) NSMutableArray* /* NSString * */ dataSuppliers;
@property (readonly) NSMutableArray* /* WACContactPhone* */ phones;
@property (readonly) RTObject<WFCIPropertySet>* providerProperties;
@property (readonly) NSMutableArray* /* WACContactSignificantOther* */ significantOthers;
@property (readonly) NSMutableArray* /* WACContactWebsite* */ websites;
@property (retain) RTObject<WSSIRandomAccessStreamReference>* sourceDisplayPicture;
@property (retain) NSString * textToneToken;
@property (retain) NSString * displayNameOverride;
@property (retain) WFDateTime* displayPictureUserUpdateTime;
@property (retain) NSString * nickname;
@property (retain) NSString * remoteId;
@property (retain) NSString * ringToneToken;
@property (readonly) NSString * contactListId;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* largeDisplayPicture;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* smallDisplayPicture;
@property (readonly) NSString * sortName;
@property (readonly) NSString * aggregateId;
@property (readonly) NSString * fullName;
@property (readonly) BOOL isAggregate;
@property (readonly) BOOL isDisplayPictureManuallySet;
@property (readonly) BOOL isMe;
@property (retain) NSString * yomiGivenName;
@property (retain) NSString * honorificNameSuffix;
@property (retain) NSString * yomiFamilyName;
@property (retain) NSString * middleName;
@property (retain) NSString * lastName;
@property (retain) NSString * honorificNamePrefix;
@property (retain) NSString * firstName;
@property (readonly) NSString * displayName;
@property (readonly) NSString * yomiDisplayName;
@end

#endif // __WACContact_DEFINED__

// Windows.ApplicationModel.Contacts.ContactField
#ifndef __WACContactField_DEFINED__
#define __WACContactField_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactField : RTObject <WACIContactField>
+ (WACContactField*)makeField_Default:(NSString *)value type:(WACContactFieldType)type ACTIVATOR;
+ (WACContactField*)makeField_Category:(NSString *)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category ACTIVATOR;
+ (WACContactField*)makeField_Custom:(NSString *)name value:(NSString *)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WACContactFieldCategory category;
@property (readonly) NSString * name;
@property (readonly) WACContactFieldType type;
@property (readonly) NSString * value;
@end

#endif // __WACContactField_DEFINED__

// Windows.ApplicationModel.Contacts.ContactLocationField
#ifndef __WACContactLocationField_DEFINED__
#define __WACContactLocationField_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactLocationField : RTObject <WACIContactField>
+ (WACContactLocationField*)makeLocation_Default:(NSString *)unstructuredAddress ACTIVATOR;
+ (WACContactLocationField*)makeLocation_Category:(NSString *)unstructuredAddress category:(WACContactFieldCategory)category ACTIVATOR;
+ (WACContactLocationField*)makeLocation_All:(NSString *)unstructuredAddress category:(WACContactFieldCategory)category street:(NSString *)street city:(NSString *)city region:(NSString *)region country:(NSString *)country postalCode:(NSString *)postalCode ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WACContactFieldCategory category;
@property (readonly) NSString * name;
@property (readonly) WACContactFieldType type;
@property (readonly) NSString * value;
@property (readonly) NSString * city;
@property (readonly) NSString * country;
@property (readonly) NSString * postalCode;
@property (readonly) NSString * region;
@property (readonly) NSString * street;
@property (readonly) NSString * unstructuredAddress;
@end

#endif // __WACContactLocationField_DEFINED__

// Windows.ApplicationModel.Contacts.ContactInstantMessageField
#ifndef __WACContactInstantMessageField_DEFINED__
#define __WACContactInstantMessageField_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactInstantMessageField : RTObject <WACIContactField>
+ (WACContactInstantMessageField*)makeInstantMessage_Default:(NSString *)userName ACTIVATOR;
+ (WACContactInstantMessageField*)makeInstantMessage_Category:(NSString *)userName category:(WACContactFieldCategory)category ACTIVATOR;
+ (WACContactInstantMessageField*)makeInstantMessage_All:(NSString *)userName category:(WACContactFieldCategory)category service:(NSString *)service displayText:(NSString *)displayText verb:(WFUri*)verb ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WACContactFieldCategory category;
@property (readonly) NSString * name;
@property (readonly) WACContactFieldType type;
@property (readonly) NSString * value;
@property (readonly) NSString * displayText;
@property (readonly) WFUri* launchUri;
@property (readonly) NSString * service;
@property (readonly) NSString * userName;
@end

#endif // __WACContactInstantMessageField_DEFINED__

// Windows.ApplicationModel.Contacts.KnownContactField
#ifndef __WACKnownContactField_DEFINED__
#define __WACKnownContactField_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACKnownContactField : RTObject
+ (WACContactFieldType)convertNameToType:(NSString *)name;
+ (NSString *)convertTypeToName:(WACContactFieldType)type;
+ (NSString *)email;
+ (NSString *)instantMessage;
+ (NSString *)location;
+ (NSString *)phoneNumber;
@end

#endif // __WACKnownContactField_DEFINED__

// Windows.ApplicationModel.Contacts.ContactInformation
#ifndef __WACContactInformation_DEFINED__
#define __WACContactInformation_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactInformation : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WACContactField* */ customFields;
@property (readonly) NSArray* /* WACContactField* */ emails;
@property (readonly) NSArray* /* WACContactInstantMessageField* */ instantMessages;
@property (readonly) NSArray* /* WACContactLocationField* */ locations;
@property (readonly) NSString * name;
@property (readonly) NSArray* /* WACContactField* */ phoneNumbers;
- (void)getThumbnailAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success failure:(void (^)(NSError*))failure;
- (NSArray* /* WACContactField* */)queryCustomFields:(NSString *)customName;
@end

#endif // __WACContactInformation_DEFINED__

// Windows.ApplicationModel.Contacts.ContactFieldFactory
#ifndef __WACContactFieldFactory_DEFINED__
#define __WACContactFieldFactory_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactFieldFactory : RTObject <WACIContactFieldFactory, WACIContactLocationFieldFactory, WACIContactInstantMessageFieldFactory>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WACContactField*)createField_Default:(NSString *)value type:(WACContactFieldType)type;
- (WACContactField*)createField_Category:(NSString *)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category;
- (WACContactField*)createField_Custom:(NSString *)name value:(NSString *)value type:(WACContactFieldType)type category:(WACContactFieldCategory)category;
- (WACContactLocationField*)createLocation_Default:(NSString *)unstructuredAddress;
- (WACContactLocationField*)createLocation_Category:(NSString *)unstructuredAddress category:(WACContactFieldCategory)category;
- (WACContactLocationField*)createLocation_All:(NSString *)unstructuredAddress category:(WACContactFieldCategory)category street:(NSString *)street city:(NSString *)city region:(NSString *)region country:(NSString *)country postalCode:(NSString *)postalCode;
- (WACContactInstantMessageField*)createInstantMessage_Default:(NSString *)userName;
- (WACContactInstantMessageField*)createInstantMessage_Category:(NSString *)userName category:(WACContactFieldCategory)category;
- (WACContactInstantMessageField*)createInstantMessage_All:(NSString *)userName category:(WACContactFieldCategory)category service:(NSString *)service displayText:(NSString *)displayText verb:(WFUri*)verb;
@end

#endif // __WACContactFieldFactory_DEFINED__

// Windows.ApplicationModel.Contacts.PinnedContactIdsQueryResult
#ifndef __WACPinnedContactIdsQueryResult_DEFINED__
#define __WACPinnedContactIdsQueryResult_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPinnedContactIdsQueryResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* NSString * */ contactIds;
@end

#endif // __WACPinnedContactIdsQueryResult_DEFINED__

// Windows.ApplicationModel.Contacts.PinnedContactManager
#ifndef __WACPinnedContactManager_DEFINED__
#define __WACPinnedContactManager_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACPinnedContactManager : RTObject
+ (WACPinnedContactManager*)getDefault;
+ (WACPinnedContactManager*)getForUser:(WSUser*)user;
+ (BOOL)isSupported;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSUser* user;
- (BOOL)isPinSurfaceSupported:(WACPinnedContactSurface)surface;
- (BOOL)isContactPinned:(WACContact*)contact surface:(WACPinnedContactSurface)surface;
- (void)requestPinContactAsync:(WACContact*)contact surface:(WACPinnedContactSurface)surface success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestPinContactsAsync:(id<NSFastEnumeration> /* WACContact* */)contacts surface:(WACPinnedContactSurface)surface success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)requestUnpinContactAsync:(WACContact*)contact surface:(WACPinnedContactSurface)surface success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (void)signalContactActivity:(WACContact*)contact;
- (void)getPinnedContactIdsAsyncWithSuccess:(void (^)(WACPinnedContactIdsQueryResult*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACPinnedContactManager_DEFINED__

// Windows.ApplicationModel.Contacts.ContactPanelLaunchFullAppRequestedEventArgs
#ifndef __WACContactPanelLaunchFullAppRequestedEventArgs_DEFINED__
#define __WACContactPanelLaunchFullAppRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactPanelLaunchFullAppRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@end

#endif // __WACContactPanelLaunchFullAppRequestedEventArgs_DEFINED__

// Windows.ApplicationModel.Contacts.ContactPanelClosingEventArgs
#ifndef __WACContactPanelClosingEventArgs_DEFINED__
#define __WACContactPanelClosingEventArgs_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactPanelClosingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WFDeferral*)getDeferral;
@end

#endif // __WACContactPanelClosingEventArgs_DEFINED__

// Windows.ApplicationModel.Contacts.ContactPanel
#ifndef __WACContactPanel_DEFINED__
#define __WACContactPanel_DEFINED__

OBJCUWPWINDOWSCONSOLIDATEDNAMESPACEEXPORT
@interface WACContactPanel : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WUColor* */ headerColor;
- (EventRegistrationToken)addClosingEvent:(void(^)(WACContactPanel*, WACContactPanelClosingEventArgs*))del;
- (void)removeClosingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLaunchFullAppRequestedEvent:(void(^)(WACContactPanel*, WACContactPanelLaunchFullAppRequestedEventArgs*))del;
- (void)removeLaunchFullAppRequestedEvent:(EventRegistrationToken)tok;
- (void)closePanel;
@end

#endif // __WACContactPanel_DEFINED__

