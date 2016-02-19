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

#import <Contacts/CNContact.h>
#import <StubReturn.h>

NSString* const CNContactPropertyNotFetchedExceptionName = @"CNContactPropertyNotFetchedExceptionName";
NSString* const CNContactIdentifierKey = @"CNContactIdentifierKey";
NSString* const CNContactNamePrefixKey = @"CNContactNamePrefixKey";
NSString* const CNContactGivenNameKey = @"CNContactGivenNameKey";
NSString* const CNContactMiddleNameKey = @"CNContactMiddleNameKey";
NSString* const CNContactFamilyNameKey = @"CNContactFamilyNameKey";
NSString* const CNContactPreviousFamilyNameKey = @"CNContactPreviousFamilyNameKey";
NSString* const CNContactNameSuffixKey = @"CNContactNameSuffixKey";
NSString* const CNContactNicknameKey = @"CNContactNicknameKey";
NSString* const CNContactPhoneticGivenNameKey = @"CNContactPhoneticGivenNameKey";
NSString* const CNContactPhoneticMiddleNameKey = @"CNContactPhoneticMiddleNameKey";
NSString* const CNContactPhoneticFamilyNameKey = @"CNContactPhoneticFamilyNameKey";
NSString* const CNContactOrganizationNameKey = @"CNContactOrganizationNameKey";
NSString* const CNContactDepartmentNameKey = @"CNContactDepartmentNameKey";
NSString* const CNContactJobTitleKey = @"CNContactJobTitleKey";
NSString* const CNContactBirthdayKey = @"CNContactBirthdayKey";
NSString* const CNContactNonGregorianBirthdayKey = @"CNContactNonGregorianBirthdayKey";
NSString* const CNContactNoteKey = @"CNContactNoteKey";
NSString* const CNContactImageDataKey = @"CNContactImageDataKey";
NSString* const CNContactThumbnailImageDataKey = @"CNContactThumbnailImageDataKey";
NSString* const CNContactImageDataAvailableKey = @"CNContactImageDataAvailableKey";
NSString* const CNContactTypeKey = @"CNContactTypeKey";
NSString* const CNContactPhoneNumbersKey = @"CNContactPhoneNumbersKey";
NSString* const CNContactEmailAddressesKey = @"CNContactEmailAddressesKey";
NSString* const CNContactPostalAddressesKey = @"CNContactPostalAddressesKey";
NSString* const CNContactDatesKey = @"CNContactDatesKey";
NSString* const CNContactUrlAddressesKey = @"CNContactUrlAddressesKey";
NSString* const CNContactRelationsKey = @"CNContactRelationsKey";
NSString* const CNContactSocialProfilesKey = @"CNContactSocialProfilesKey";
NSString* const CNContactInstantMessageAddressesKey = @"CNContactInstantMessageAddressesKey";

@implementation CNContact
/**
 @Status Stub
 @Notes
*/
+ (NSString*)localizedStringForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (id<CNKeyDescriptor>)descriptorForAllComparatorKeys {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSComparator)comparatorForNameSortOrder:(CNContactSortOrder)sortOrder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isKeyAvailable:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)areKeysAvailable:(NSArray*)keyDescriptors {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForContactsMatchingName:(NSString*)name {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForContactsWithIdentifiers:(NSArray*)identifiers {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForContactsInGroupWithIdentifier:(NSString*)groupIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSPredicate*)predicateForContactsInContainerWithIdentifier:(NSString*)containerIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)mutableCopyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

@end
