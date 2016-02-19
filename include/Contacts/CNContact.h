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

#import <Contacts/ContactsExport.h>
#import <Foundation/NSObject.h>

@protocol CNKeyDescriptor;
@class NSString;
@class NSDateComponents;
@class NSArray;
@class NSData;
@class NSPredicate;

typedef NS_ENUM(NSInteger, CNContactType) { CNContactTypePerson, CNContactTypeOrganization };

typedef NS_ENUM(NSInteger, CNContactSortOrder) {
    CNContactSortOrderNone,
    CNContactSortOrderUserDefault,
    CNContactSortOrderGivenName,
    CNContactSortOrderFamilyName
};

CONTACTS_EXPORT NSString* const CNContactPropertyNotFetchedExceptionName;
CONTACTS_EXPORT NSString* const CNContactIdentifierKey;
CONTACTS_EXPORT NSString* const CNContactNamePrefixKey;
CONTACTS_EXPORT NSString* const CNContactGivenNameKey;
CONTACTS_EXPORT NSString* const CNContactMiddleNameKey;
CONTACTS_EXPORT NSString* const CNContactFamilyNameKey;
CONTACTS_EXPORT NSString* const CNContactPreviousFamilyNameKey;
CONTACTS_EXPORT NSString* const CNContactNameSuffixKey;
CONTACTS_EXPORT NSString* const CNContactNicknameKey;
CONTACTS_EXPORT NSString* const CNContactPhoneticGivenNameKey;
CONTACTS_EXPORT NSString* const CNContactPhoneticMiddleNameKey;
CONTACTS_EXPORT NSString* const CNContactPhoneticFamilyNameKey;
CONTACTS_EXPORT NSString* const CNContactOrganizationNameKey;
CONTACTS_EXPORT NSString* const CNContactDepartmentNameKey;
CONTACTS_EXPORT NSString* const CNContactJobTitleKey;
CONTACTS_EXPORT NSString* const CNContactBirthdayKey;
CONTACTS_EXPORT NSString* const CNContactNonGregorianBirthdayKey;
CONTACTS_EXPORT NSString* const CNContactNoteKey;
CONTACTS_EXPORT NSString* const CNContactImageDataKey;
CONTACTS_EXPORT NSString* const CNContactThumbnailImageDataKey;
CONTACTS_EXPORT NSString* const CNContactImageDataAvailableKey;
CONTACTS_EXPORT NSString* const CNContactTypeKey;
CONTACTS_EXPORT NSString* const CNContactPhoneNumbersKey;
CONTACTS_EXPORT NSString* const CNContactEmailAddressesKey;
CONTACTS_EXPORT NSString* const CNContactPostalAddressesKey;
CONTACTS_EXPORT NSString* const CNContactDatesKey;
CONTACTS_EXPORT NSString* const CNContactUrlAddressesKey;
CONTACTS_EXPORT NSString* const CNContactRelationsKey;
CONTACTS_EXPORT NSString* const CNContactSocialProfilesKey;
CONTACTS_EXPORT NSString* const CNContactInstantMessageAddressesKey;

CONTACTS_EXPORT_CLASS
@interface CNContact : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>
@property (readonly, copy, nonatomic) NSString* identifier STUB_PROPERTY;
@property (readonly, nonatomic) CNContactType contactType STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSDateComponents* birthday STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSDateComponents* nonGregorianBirthday STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* dates STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* namePrefix STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* givenName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* middleName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* familyName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* previousFamilyName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* nameSuffix STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* nickname STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* phoneticGivenName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* phoneticMiddleName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* phoneticFamilyName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* organizationName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* departmentName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* jobTitle STUB_PROPERTY;
+ (NSString*)localizedStringForKey:(NSString*)key STUB_METHOD;
+ (id<CNKeyDescriptor>)descriptorForAllComparatorKeys STUB_METHOD;
+ (NSComparator)comparatorForNameSortOrder:(CNContactSortOrder)sortOrder STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* socialProfiles STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* phoneNumbers STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* urlAddresses STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* postalAddresses STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* emailAddresses STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* note STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSData* imageData STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSData* thumbnailImageData STUB_PROPERTY;
@property (readonly, nonatomic) BOOL imageDataAvailable STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* contactRelations STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* instantMessageAddresses STUB_PROPERTY;
- (BOOL)isKeyAvailable:(NSString*)key STUB_METHOD;
- (BOOL)areKeysAvailable:(NSArray*)keyDescriptors STUB_METHOD;
+ (NSPredicate*)predicateForContactsMatchingName:(NSString*)name STUB_METHOD;
+ (NSPredicate*)predicateForContactsWithIdentifiers:(NSArray*)identifiers STUB_METHOD;
+ (NSPredicate*)predicateForContactsInGroupWithIdentifier:(NSString*)groupIdentifier STUB_METHOD;
+ (NSPredicate*)predicateForContactsInContainerWithIdentifier:(NSString*)containerIdentifier STUB_METHOD;
@end
