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

// WindowsPhonePersonalInformation.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
#define OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhonePersonalInformation.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPPContactAddress, WPPContactInformation, WPPContactStore, WPPStoredContact, WPPKnownContactProperties, WPPContactQueryOptions, WPPContactQueryResult, WPPContactChangeRecord;
@protocol WPPIContactAddress, WPPIContactInformation, WPPIContactInformation2, WPPIContactInformationStatics, WPPIStoredContact, WPPIStoredContactFactory, WPPIKnownContactPropertiesStatics, WPPIContactQueryResult, WPPIContactQueryOptions, WPPIContactStore, WPPIContactStore2, WPPIContactStoreStatics, WPPIContactChangeRecord;

// Windows.Phone.PersonalInformation.ContactStoreSystemAccessMode
enum _WPPContactStoreSystemAccessMode {
    WPPContactStoreSystemAccessModeReadOnly = 0,
    WPPContactStoreSystemAccessModeReadWrite = 1,
};
typedef unsigned WPPContactStoreSystemAccessMode;

// Windows.Phone.PersonalInformation.ContactStoreApplicationAccessMode
enum _WPPContactStoreApplicationAccessMode {
    WPPContactStoreApplicationAccessModeLimitedReadOnly = 0,
    WPPContactStoreApplicationAccessModeReadOnly = 1,
};
typedef unsigned WPPContactStoreApplicationAccessMode;

// Windows.Phone.PersonalInformation.ContactChangeType
enum _WPPContactChangeType {
    WPPContactChangeTypeCreated = 0,
    WPPContactChangeTypeModified = 1,
    WPPContactChangeTypeDeleted = 2,
};
typedef unsigned WPPContactChangeType;

// Windows.Phone.PersonalInformation.ContactQueryResultOrdering
enum _WPPContactQueryResultOrdering {
    WPPContactQueryResultOrderingSystemDefault = 0,
    WPPContactQueryResultOrderingGivenNameFamilyName = 1,
    WPPContactQueryResultOrderingFamilyNameGivenName = 2,
};
typedef unsigned WPPContactQueryResultOrdering;

// Windows.Phone.PersonalInformation.VCardFormat
enum _WPPVCardFormat {
    WPPVCardFormatVersion2_1 = 0,
    WPPVCardFormatVersion3 = 1,
};
typedef unsigned WPPVCardFormat;

#include "WindowsStorageStreams.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Phone.PersonalInformation.IContactInformation
#ifndef __WPPIContactInformation_DEFINED__
#define __WPPIContactInformation_DEFINED__

@protocol WPPIContactInformation
@property (retain) NSString * displayName;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* displayPicture;
@property (retain) NSString * familyName;
@property (retain) NSString * givenName;
@property (retain) NSString * honorificPrefix;
@property (retain) NSString * honorificSuffix;
- (void)getDisplayPictureAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)setDisplayPictureAsync:(RTObject<WSSIInputStream>*)stream;
- (void)getPropertiesAsyncWithSuccess:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success failure:(void (^)(NSError*))failure;
- (void)toVcardAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (void)toVcardWithOptionsAsync:(WPPVCardFormat)format success:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
@end

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
@interface WPPIContactInformation : RTObject <WPPIContactInformation>
@end

#endif // __WPPIContactInformation_DEFINED__

// Windows.Phone.PersonalInformation.IContactInformation2
#ifndef __WPPIContactInformation2_DEFINED__
#define __WPPIContactInformation2_DEFINED__

@protocol WPPIContactInformation2
@property (retain) WFDateTime* displayPictureDate;
@end

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
@interface WPPIContactInformation2 : RTObject <WPPIContactInformation2>
@end

#endif // __WPPIContactInformation2_DEFINED__

// Windows.Phone.PersonalInformation.ContactAddress
#ifndef __WPPContactAddress_DEFINED__
#define __WPPContactAddress_DEFINED__

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
@interface WPPContactAddress : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * streetAddress;
@property (retain) NSString * region;
@property (retain) NSString * postalCode;
@property (retain) NSString * locality;
@property (retain) NSString * country;
@end

#endif // __WPPContactAddress_DEFINED__

// Windows.Phone.PersonalInformation.ContactInformation
#ifndef __WPPContactInformation_DEFINED__
#define __WPPContactInformation_DEFINED__

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
@interface WPPContactInformation : RTObject <WPPIContactInformation>
+ (void)parseVcardAsync:(RTObject<WSSIInputStream>*)vcard success:(void (^)(WPPContactInformation*))success failure:(void (^)(NSError*))failure;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * honorificSuffix;
@property (retain) NSString * honorificPrefix;
@property (retain) NSString * givenName;
@property (retain) NSString * familyName;
@property (retain) NSString * displayName;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* displayPicture;
- (void)getDisplayPictureAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)setDisplayPictureAsync:(RTObject<WSSIInputStream>*)stream;
- (void)getPropertiesAsyncWithSuccess:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success failure:(void (^)(NSError*))failure;
- (void)toVcardAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (void)toVcardWithOptionsAsync:(WPPVCardFormat)format success:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WPPContactInformation_DEFINED__

// Windows.Phone.PersonalInformation.ContactStore
#ifndef __WPPContactStore_DEFINED__
#define __WPPContactStore_DEFINED__

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
@interface WPPContactStore : RTObject
+ (void)createOrOpenAsyncWithSuccess:(void (^)(WPPContactStore*))success failure:(void (^)(NSError*))failure;
+ (void)createOrOpenWithOptionsAsync:(WPPContactStoreSystemAccessMode)access sharing:(WPPContactStoreApplicationAccessMode)sharing success:(void (^)(WPPContactStore*))success failure:(void (^)(NSError*))failure;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) uint64_t revisionNumber;
- (void)findContactByRemoteIdAsync:(NSString *)id success:(void (^)(WPPStoredContact*))success failure:(void (^)(NSError*))failure;
- (void)findContactByIdAsync:(NSString *)id success:(void (^)(WPPStoredContact*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)deleteContactAsync:(NSString *)id;
- (WPPContactQueryResult*)createContactQueryDefault;
- (WPPContactQueryResult*)createContactQueryWithOptions:(WPPContactQueryOptions*)options;
- (RTObject<WFIAsyncAction>*)deleteAsync;
- (void)getChangesAsync:(uint64_t)baseRevisionNumber success:(void (^)(NSArray* /* WPPContactChangeRecord* */))success failure:(void (^)(NSError*))failure;
- (void)loadExtendedPropertiesAsyncWithSuccess:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)saveExtendedPropertiesAsync:(NSDictionary* /* NSString *, RTObject* */)data;
- (void)createMeContactAsync:(NSString *)id success:(void (^)(WPPStoredContact*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WPPContactStore_DEFINED__

// Windows.Phone.PersonalInformation.StoredContact
#ifndef __WPPStoredContact_DEFINED__
#define __WPPStoredContact_DEFINED__

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
@interface WPPStoredContact : RTObject <WPPIContactInformation, WPPIContactInformation2>
+ (WPPStoredContact*)makeStoredContact:(WPPContactStore*)store ACTIVATOR;
+ (WPPStoredContact*)makeStoredContactFromInformation:(WPPContactStore*)store contact:(WPPContactInformation*)contact ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * honorificSuffix;
@property (retain) NSString * honorificPrefix;
@property (retain) NSString * givenName;
@property (retain) NSString * familyName;
@property (retain) NSString * displayName;
@property (readonly) RTObject<WSSIRandomAccessStreamReference>* displayPicture;
@property (retain) WFDateTime* displayPictureDate;
@property (retain) NSString * remoteId;
@property (readonly) NSString * id;
@property (readonly) WPPContactStore* store;
- (void)getExtendedPropertiesAsyncWithSuccess:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)saveAsync;
- (RTObject<WFIAsyncAction>*)replaceExistingContactAsync:(NSString *)id;
- (void)getDisplayPictureAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (RTObject<WFIAsyncAction>*)setDisplayPictureAsync:(RTObject<WSSIInputStream>*)stream;
- (void)getPropertiesAsyncWithSuccess:(void (^)(NSMutableDictionary* /* NSString *, RTObject* */))success failure:(void (^)(NSError*))failure;
- (void)toVcardAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
- (void)toVcardWithOptionsAsync:(WPPVCardFormat)format success:(void (^)(RTObject<WSSIRandomAccessStream>*))success failure:(void (^)(NSError*))failure;
@end

#endif // __WPPStoredContact_DEFINED__

// Windows.Phone.PersonalInformation.KnownContactProperties
#ifndef __WPPKnownContactProperties_DEFINED__
#define __WPPKnownContactProperties_DEFINED__

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
@interface WPPKnownContactProperties : RTObject
+ (NSString *)additionalName;
+ (NSString *)address;
+ (NSString *)alternateMobileTelephone;
+ (NSString *)alternateTelephone;
+ (NSString *)alternateWorkTelephone;
+ (NSString *)anniversary;
+ (NSString *)birthdate;
+ (NSString *)children;
+ (NSString *)companyName;
+ (NSString *)companyTelephone;
+ (NSString *)displayName;
+ (NSString *)email;
+ (NSString *)familyName;
+ (NSString *)givenName;
+ (NSString *)homeFax;
+ (NSString *)honorificPrefix;
+ (NSString *)honorificSuffix;
+ (NSString *)jobTitle;
+ (NSString *)manager;
+ (NSString *)mobileTelephone;
+ (NSString *)nickname;
+ (NSString *)notes;
+ (NSString *)officeLocation;
+ (NSString *)otherAddress;
+ (NSString *)otherEmail;
+ (NSString *)significantOther;
+ (NSString *)telephone;
+ (NSString *)url;
+ (NSString *)workAddress;
+ (NSString *)workEmail;
+ (NSString *)workFax;
+ (NSString *)workTelephone;
+ (NSString *)yomiCompanyName;
+ (NSString *)yomiFamilyName;
+ (NSString *)yomiGivenName;
@end

#endif // __WPPKnownContactProperties_DEFINED__

// Windows.Phone.PersonalInformation.ContactQueryOptions
#ifndef __WPPContactQueryOptions_DEFINED__
#define __WPPContactQueryOptions_DEFINED__

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
@interface WPPContactQueryOptions : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WPPContactQueryResultOrdering orderBy;
@property (readonly) NSMutableArray* /* NSString * */ desiredFields;
@end

#endif // __WPPContactQueryOptions_DEFINED__

// Windows.Phone.PersonalInformation.ContactQueryResult
#ifndef __WPPContactQueryResult_DEFINED__
#define __WPPContactQueryResult_DEFINED__

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
@interface WPPContactQueryResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)getContactCountAsyncWithSuccess:(void (^)(unsigned int))success failure:(void (^)(NSError*))failure;
- (void)getContactsAsyncWithSuccess:(void (^)(NSArray* /* WPPStoredContact* */))success failure:(void (^)(NSError*))failure;
- (void)getContactsAsyncInRange:(unsigned int)startIndex maxNumberOfItems:(unsigned int)maxNumberOfItems success:(void (^)(NSArray* /* WPPStoredContact* */))success failure:(void (^)(NSError*))failure;
- (WPPContactQueryOptions*)getCurrentQueryOptions;
@end

#endif // __WPPContactQueryResult_DEFINED__

// Windows.Phone.PersonalInformation.ContactChangeRecord
#ifndef __WPPContactChangeRecord_DEFINED__
#define __WPPContactChangeRecord_DEFINED__

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONEXPORT
@interface WPPContactChangeRecord : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WPPContactChangeType changeType;
@property (readonly) NSString * id;
@property (readonly) NSString * remoteId;
@property (readonly) uint64_t revisionNumber;
@end

#endif // __WPPContactChangeRecord_DEFINED__

