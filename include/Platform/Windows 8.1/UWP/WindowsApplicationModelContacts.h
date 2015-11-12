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
@class WACContactCardDelayedDataLoader, WACContactManager, WACContactLaunchActionVerbs, WACContactField, WACContactLocationField,
    WACContactInstantMessageField, WACKnownContactField, WACContactInformation, WACContact, WACContactPicker, WACContactFieldFactory,
    WACContactSignificantOther, WACContactWebsite, WACContactEmail, WACContactPhone, WACContactAddress, WACContactConnectedServiceAccount,
    WACContactDate, WACContactJobInfo;
@protocol WACIContactManagerStatics
, WACIContactLaunchActionVerbsStatics, WACIContactField, WACIContactLocationField, WACIContactInstantMessageField,
    WACIKnownContactFieldStatics, WACIContactInformation, WACIContactPicker, WACIContactPicker2, WACIContactFieldFactory,
    WACIContactLocationFieldFactory, WACIContactInstantMessageFieldFactory, WACIContactSignificantOther, WACIContactWebsite,
    WACIContactEmail, WACIContactPhone, WACIContactAddress, WACIContactConnectedServiceAccount, WACIContactDate, WACIContactName,
    WACIContactJobInfo, WACIContact, WACIContact2, WACIContactCardDelayedDataLoader;

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

// Windows.ApplicationModel.Contacts.ContactFieldCategory
enum _WACContactFieldCategory {
    WACContactFieldCategoryNone = 0,
    WACContactFieldCategoryHome = 1,
    WACContactFieldCategoryWork = 2,
    WACContactFieldCategoryMobile = 3,
    WACContactFieldCategoryOther = 4,
};
typedef unsigned WACContactFieldCategory;

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

#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsUIPopups.h"
#include "WindowsFoundation.h"

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
@property (readonly) NSString* displayText;
@property (readonly) WFUri* launchUri;
@property (readonly) NSString* service;
@property (readonly) NSString* userName;
@property (readonly) WACContactFieldCategory category;
@property (readonly) NSString* name;
@property (readonly) WACContactFieldType type;
@property (readonly) NSString* value;
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
@property (readonly) id<NSFastEnumeration> /*WACContactField*/ customFields;
@property (readonly) id<NSFastEnumeration> /*WACContactField*/ emails;
@property (readonly) id<NSFastEnumeration> /*WACContactInstantMessageField*/ instantMessages;
@property (readonly) id<NSFastEnumeration> /*WACContactLocationField*/ locations;
@property (readonly) NSString* name;
@property (readonly) id<NSFastEnumeration> /*WACContactField*/ phoneNumbers;
- (void)getThumbnailAsyncWithSuccess:(void (^)(RTObject<WSSIRandomAccessStreamWithContentType>*))success
                             failure:(void (^)(NSError*))failure;
- (id<NSFastEnumeration> /*WACContactField*/)queryCustomFields:(NSString*)customName;
@end

#endif // __WACContactInformation_DEFINED__

// Windows.ApplicationModel.Contacts.Contact
#ifndef __WACContact_DEFINED__
#define __WACContact_DEFINED__

WINRT_EXPORT
@interface WACContact : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject<WSSIRandomAccessStreamReference>* thumbnail;
@property (copy) NSString* name;
@property (readonly) id<NSFastEnumeration> /*WACIContactField*/ fields;
@property (copy) NSString* honorificNamePrefix;
@property (copy) NSString* yomiFamilyName;
@property (copy) NSString* lastName;
@property (copy) NSString* honorificNameSuffix;
@property (copy) NSString* yomiGivenName;
@property (copy) NSString* firstName;
@property (copy) NSString* middleName;
@property (readonly) NSString* displayName;
@property (readonly) NSString* yomiDisplayName;
@property (copy) NSString* notes;
@property (copy) NSString* id;
@property (readonly) id<NSFastEnumeration> /*WACContactWebsite*/ websites;
@property (readonly) id<NSFastEnumeration> /*WACContactAddress*/ addresses;
@property (readonly) id<NSFastEnumeration> /*WACContactConnectedServiceAccount*/ connectedServiceAccounts;
@property (readonly) id<NSFastEnumeration> /*String*/ dataSuppliers;
@property (readonly) id<NSFastEnumeration> /*WACContactEmail*/ emails;
@property (readonly) id<NSFastEnumeration> /*WACContactDate*/ importantDates;
@property (readonly) id<NSFastEnumeration> /*WACContactJobInfo*/ jobInfo;
@property (readonly) id<NSFastEnumeration> /*WACContactPhone*/ phones;
@property (readonly) RTObject<WFCIPropertySet>* providerProperties;
@property (readonly) id<NSFastEnumeration> /*WACContactSignificantOther*/ significantOthers;
@end

#endif // __WACContact_DEFINED__

// Windows.ApplicationModel.Contacts.ContactPicker
#ifndef __WACContactPicker_DEFINED__
#define __WACContactPicker_DEFINED__

WINRT_EXPORT
@interface WACContactPicker : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) id<NSFastEnumeration> /*WACContactFieldType*/ desiredFieldsWithContactFieldType;
@property WACContactSelectionMode selectionMode;
@property (copy) NSString* commitButtonText;
@property (readonly) id<NSFastEnumeration> /*String*/ desiredFields;
- (void)pickSingleContactAsyncWithSuccess:(void (^)(WACContactInformation*))success failure:(void (^)(NSError*))failure;
- (void)pickMultipleContactsAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*WACContactInformation*/))success
                                     failure:(void (^)(NSError*))failure;
- (void)pickContactAsyncWithSuccess:(void (^)(WACContact*))success failure:(void (^)(NSError*))failure;
- (void)pickContactsAsyncWithSuccess:(void (^)(id<NSFastEnumeration> /*WACContact*/))success failure:(void (^)(NSError*))failure;
@end

#endif // __WACContactPicker_DEFINED__

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

// Windows.ApplicationModel.Contacts.ContactSignificantOther
#ifndef __WACContactSignificantOther_DEFINED__
#define __WACContactSignificantOther_DEFINED__

WINRT_EXPORT
@interface WACContactSignificantOther : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* name;
@property (copy) NSString* description;
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
@end

#endif // __WACContactWebsite_DEFINED__

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
@property (copy) NSNumber* year;
@property (copy) NSNumber* month;
@property WACContactDateKind kind;
@property (copy) NSString* description;
@property (copy) NSNumber* day;
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
