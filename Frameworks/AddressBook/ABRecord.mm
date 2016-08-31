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

#import <AddressBook/ABRecord.h>
#import <AddressBook/ABPerson.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

#import "ABAddressBookManagerInternal.h"
#import "ABContactInternal.h"
#import "ABRecordInternal.h"
#import "ABSourceInternal.h"
#import "ABMultiValueInternal.h"
#import "NSDate+AddressBookAdditions.h"

// Verifies that the given value doesn't have a length greater than the given length. If value's length
// is longer, returns false and, if error is not null, creates an error with the given propertyName.
// Otherwise, returns true and does nothing with error.
static bool _checkLength(NSString* value, NSUInteger length, CFErrorRef* error, NSString* propertyName) {
    if ([value length] > length) {
        if (error) {
            NSString* reason = [NSString stringWithFormat:@"The %@ property must not be more than %d characters\n", propertyName, length];
            NSDictionary* userInfo = @{
                NSLocalizedDescriptionKey : NSLocalizedString(@"Error setting record value.\n", nil),
                NSLocalizedFailureReasonErrorKey : NSLocalizedString(reason, nil)
            };
            *error = (__bridge_retained CFErrorRef)[NSError errorWithDomain:(__bridge NSString*)ABAddressBookErrorDomain
                                                                       code:kABOperationNotPermittedByStoreError
                                                                   userInfo:userInfo];
        }

        return false;
    }

    return true;
}

// Ensures that the property type of the multiValue matches the expected ABPropertyType. If they don't
// match, returns false and, if error is not null, creates an error describing the problem.
// Otherwise, returns true and does nothing with error.
static bool _checkType(ABPropertyType expected, _ABMultiValue* multiValue, CFErrorRef* error) {
    if (expected != [multiValue getPropertyType]) {
        if (error) {
            NSDictionary* userInfo = @{
                NSLocalizedDescriptionKey : NSLocalizedString(@"Error setting record value.\n", nil),
                NSLocalizedFailureReasonErrorKey : NSLocalizedString(@"The property type of the multi-value was incorrect!\n", nil)
            };
            *error = (__bridge_retained CFErrorRef)[NSError errorWithDomain:(__bridge NSString*)ABAddressBookErrorDomain
                                                                       code:kABOperationNotPermittedByStoreError
                                                                   userInfo:userInfo];
        }

        return false;
    }

    return true;
}

// Updates the address book manager if a read-write
// contact is modified to ensure changes persist if
// the address book is saved.
static void _updateManager(_ABContact* person) {
    if (person.type == kAddressBookReadWriteContact) {
        [(__bridge _ABAddressBookManager*)person.manager modifyContact:(__bridge ABRecordRef)person];
    }
}

// The maximum allowed String length of various Windows Contacts properties.
// Values obtained from https://msdn.microsoft.com/en-us/library/windows/apps/windows.applicationmodel.contacts.contact
// (click on a given property to see any potential length limitations).
static const NSUInteger kABPersonFirstNameLength = 64;
static const NSUInteger kABPersonLastNameLength = 64;
static const NSUInteger kABPersonMiddleNameLength = 64;
static const NSUInteger kABPersonPrefixLength = 32;
static const NSUInteger kABPersonSuffixLength = 32;
static const NSUInteger kABPersonFirstNamePhoneticLength = 120;
static const NSUInteger kABPersonLastNamePhoneticLength = 120;
static const NSUInteger kABPersonOrganizationLength = 64;
static const NSUInteger kABPersonJobTitleLength = 1024;
static const NSUInteger kABPersonDepartmentLength = 100;
static const NSUInteger kABPersonNoteLength = 4096;
static const NSUInteger kABPersonEmailLength = 321;
static const NSUInteger kABPersonAddressLength = 1024;
static const NSUInteger kABPersonPhoneLength = 50;
static const NSUInteger kABPersonRelatedNamesLength = 256;

/**
 @Status Interoperable
 @Notes
*/
ABRecordID ABRecordGetRecordID(ABRecordRef record) {
    if (record == nullptr) {
        return kABRecordInvalidID;
    }

    ABRecordType recordType = ABRecordGetRecordType(record);
    switch (recordType) {
        case kABPersonType: {
            _ABContact* person = (__bridge _ABContact*)record;
            NSString* fullId = person.contact.id;

            // Windows IDs are in the format {storeid.itemtype.id}
            // Therefore, we trim off the last curly brace and split on periods, giving us:
            // ["{storeid", "itemtype", "id"], which we can then grab id from and convert
            // it to an int.
            NSArray* idComponents = [[fullId substringToIndex:(fullId.length - 1)] componentsSeparatedByString:@"."];
            if ([idComponents count] < 3) {
                return kABRecordInvalidID;
            }

            NSString* idAsString = idComponents[2];
            return [idAsString integerValue];
        }
        case kABSourceType: {
            _ABSource* source = (__bridge _ABSource*)record;
            return source.recordID;
        }
        case kABGroupType:
        // Windows contacts doesn't support Group records, so return an invalid id.
        default:
            return kABRecordInvalidID;
    }
}

/**
 @Status Interoperable
 @Notes
*/
ABRecordType ABRecordGetRecordType(ABRecordRef record) {
    _ABRecord* _record = (__bridge _ABRecord*)record;
    if ([_record isMemberOfClass:[_ABContact class]]) {
        return kABPersonType;
    } else if ([_record isMemberOfClass:[_ABSource class]]) {
        return kABSourceType;
    }

    return kABGroupType;
}

/**
 @Status Caveat
 @Notes Records can only be modified if they are newly created (with ABPersonCreate)
 or are retrieved with ABAddressBookCopyArrayOfAllUserAppPeople -- contacts from
 ABAddressBookCopyArrayOfAllPeople are read-only and cannot have their properties changed.
*/
bool ABRecordSetValue(ABRecordRef record, ABPropertyID contactProperty, CFTypeRef value, CFErrorRef* error) {
    if (record == nullptr) {
        if (error) {
            NSDictionary* userInfo = @{
                NSLocalizedDescriptionKey : NSLocalizedString(@"Error setting record value.\n", nil),
                NSLocalizedFailureReasonErrorKey : NSLocalizedString(@"The record should not be null!\n", nil)
            };
            *error = (__bridge_retained CFErrorRef)[NSError errorWithDomain:(__bridge NSString*)ABAddressBookErrorDomain
                                                                       code:kABOperationNotPermittedByStoreError
                                                                   userInfo:userInfo];
        }

        return false;
    }

    _ABContact* person = (__bridge _ABContact*)record;

    if (person.type == kAddressBookReadOnlyContact) {
        if (error) {
            NSDictionary* userInfo = @{
                NSLocalizedDescriptionKey : NSLocalizedString(@"Error setting record value.\n", nil),
                NSLocalizedFailureReasonErrorKey : NSLocalizedString(@"You can only modify contacts created by your app!\n", nil)
            };
            *error = (__bridge_retained CFErrorRef)[NSError errorWithDomain:(__bridge NSString*)ABAddressBookErrorDomain
                                                                       code:kABOperationNotPermittedByStoreError
                                                                   userInfo:userInfo];
        }

        return false;
    }

    // Cases for various name properties.
    if (contactProperty == kABPersonFirstNameProperty) {
        NSString* firstName = (__bridge NSString*)value;
        if (!_checkLength(firstName, kABPersonFirstNameLength, error, @"first name")) {
            return false;
        }

        person.contact.firstName = firstName;
    } else if (contactProperty == kABPersonLastNameProperty) {
        NSString* lastName = (__bridge NSString*)value;
        if (!_checkLength(lastName, kABPersonLastNameLength, error, @"last name")) {
            return false;
        }

        person.contact.lastName = lastName;
    } else if (contactProperty == kABPersonMiddleNameProperty) {
        NSString* middleName = (__bridge NSString*)value;
        if (!_checkLength(middleName, kABPersonMiddleNameLength, error, @"middle name")) {
            return false;
        }

        person.contact.middleName = middleName;
    } else if (contactProperty == kABPersonPrefixProperty) {
        NSString* prefix = (__bridge NSString*)value;
        if (!_checkLength(prefix, kABPersonPrefixLength, error, @"prefix")) {
            return false;
        }

        person.contact.honorificNamePrefix = prefix;
    } else if (contactProperty == kABPersonSuffixProperty) {
        NSString* suffix = (__bridge NSString*)value;
        if (!_checkLength(suffix, kABPersonSuffixLength, error, @"suffix")) {
            return false;
        }

        person.contact.honorificNameSuffix = suffix;
    } else if (contactProperty == kABPersonNicknameProperty) {
        NSString* nickname = (__bridge NSString*)value;
        person.contact.nickname = nickname;
    } else if (contactProperty == kABPersonFirstNamePhoneticProperty) {
        NSString* phoneticFirstName = (__bridge NSString*)value;
        if (!_checkLength(phoneticFirstName, kABPersonFirstNamePhoneticLength, error, @"first name phonetic")) {
            return false;
        }

        person.contact.yomiGivenName = phoneticFirstName;
    } else if (contactProperty == kABPersonLastNamePhoneticProperty) {
        NSString* phoneticLastName = (__bridge NSString*)value;
        if (!_checkLength(phoneticLastName, kABPersonLastNamePhoneticLength, error, @"last name phonetic")) {
            return false;
        }

        person.contact.yomiFamilyName = phoneticLastName;

        // Cases for job-related properties.
    } else if (contactProperty == kABPersonOrganizationProperty) {
        NSString* organization = (__bridge NSString*)value;
        if (!_checkLength(organization, kABPersonOrganizationLength, error, @"organization")) {
            return false;
        }

        NSMutableArray* jobInfo = person.contact.jobInfo;
        if ([jobInfo count] == 0) {
            [jobInfo addObject:[WACContactJobInfo make]];
        }

        WACContactJobInfo* job = jobInfo[0];
        job.companyName = organization;
    } else if (contactProperty == kABPersonJobTitleProperty) {
        NSString* jobTitle = (__bridge NSString*)value;
        if (!_checkLength(jobTitle, kABPersonJobTitleLength, error, @"job title")) {
            return false;
        }

        NSMutableArray* jobInfo = person.contact.jobInfo;
        if ([jobInfo count] == 0) {
            [jobInfo addObject:[WACContactJobInfo make]];
        }

        WACContactJobInfo* job = jobInfo[0];
        job.title = jobTitle;
    } else if (contactProperty == kABPersonDepartmentProperty) {
        NSString* department = (__bridge NSString*)value;
        if (!_checkLength(department, kABPersonDepartmentLength, error, @"department")) {
            return false;
        }

        NSMutableArray* jobInfo = person.contact.jobInfo;
        if ([jobInfo count] == 0) {
            [jobInfo addObject:[WACContactJobInfo make]];
        }

        WACContactJobInfo* job = jobInfo[0];
        job.department = department;

        // Case for birthday-related property.
    } else if (contactProperty == kABPersonBirthdayProperty) {
        NSMutableArray* dates = person.contact.importantDates;

        // Find the first date in the contact's important dates
        // that is marked as a birthday, since a Windows contact stores
        // all of its important dates in a list under a single property
        // rather than explicitly storing the birthday.
        NSUInteger birthdayIndex = [dates indexOfObjectPassingTest:^BOOL(id obj, NSUInteger idx, BOOL* stop) {
            WACContactDate* date = (WACContactDate*)obj;
            if (date.kind == WACContactDateKindBirthday) {
                *stop = YES;
                return YES;
            } else {
                return NO;
            }
        }];

        // If not birthday was found, create a new date for it --
        // otherwise, just use the existing birthday.
        WACContactDate* date;
        if (birthdayIndex == NSNotFound) {
            date = [WACContactDate make];
            date.kind = WACContactDateKindBirthday;
            [dates addObject:date];
        } else {
            date = dates[birthdayIndex];
        }

        NSDate* birthday = (__bridge NSDate*)value;
        unsigned int units = NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit;
        NSCalendar* calendar = [NSCalendar currentCalendar];
        NSDateComponents* components = [calendar components:units fromDate:birthday];

        date.year = @([components year]);
        date.month = @([components month]);
        date.day = @([components day]);

        // Case for note-related property.
    } else if (contactProperty == kABPersonNoteProperty) {
        NSString* note = (__bridge NSString*)value;
        if (!_checkLength(note, kABPersonNoteLength, error, @"note")) {
            return false;
        }

        person.contact.notes = note;

        // Cases for various multi-value properties.
    } else if (contactProperty == kABPersonEmailProperty) {
        _ABMultiValue* multiValue = (__bridge _ABMultiValue*)value;
        if (!_checkType(kABStringPropertyType, multiValue, error)) {
            return false;
        }

        // Ensure that none of the values violate the allowed length of Windows
        // Contacts properties.
        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            if (!_checkLength(value, kABPersonEmailLength, error, @"email")) {
                return false;
            }
        }

        NSMutableArray* emails = person.contact.emails;
        [emails removeAllObjects];

        NSDictionary* dict = @{
            ((__bridge NSString*)kABHomeLabel) : @(WACContactEmailKindPersonal),
            ((__bridge NSString*)kABWorkLabel) : @(WACContactEmailKindWork),
            ((__bridge NSString*)kABOtherLabel) : @(WACContactEmailKindOther)
        };

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* label = (__bridge_transfer NSString*)[multiValue copyLabelAtIndex:i];
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            WACContactEmail* email = [WACContactEmail make];
            email.address = value;
            email.kind = dict[label] == nil ? WACContactEmailKindOther : [dict[label] integerValue];
            [emails addObject:email];
        }
    } else if (contactProperty == kABPersonAddressProperty) {
        _ABMultiValue* multiValue = (__bridge _ABMultiValue*)value;
        if (!_checkType(kABDictionaryPropertyType, multiValue, error)) {
            return false;
        }

        // Ensure that none of the values violate the allowed length of Windows
        // Contacts properties.
        for (int i = 0; i < [multiValue getCount]; i++) {
            NSDictionary* dict = (__bridge_transfer NSDictionary*)[multiValue copyValueAtIndex:i];
            for (NSString* key in dict) {
                if (!_checkLength(dict[key], kABPersonAddressLength, error, @"address")) {
                    return false;
                }
            }
        }

        NSMutableArray* addresses = person.contact.addresses;
        [addresses removeAllObjects];

        NSDictionary* dict = @{
            ((__bridge NSString*)kABHomeLabel) : @(WACContactAddressKindHome),
            ((__bridge NSString*)kABWorkLabel) : @(WACContactAddressKindWork),
            ((__bridge NSString*)kABOtherLabel) : @(WACContactAddressKindOther)
        };

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* label = (__bridge_transfer NSString*)[multiValue copyLabelAtIndex:i];
            NSDictionary* value = (__bridge_transfer NSDictionary*)[multiValue copyValueAtIndex:i];
            WACContactAddress* address = [WACContactAddress make];
            address.kind = dict[label] == nil ? WACContactAddressKindOther : [dict[label] integerValue];
            address.streetAddress = value[(__bridge NSString*)kABPersonAddressStreetKey];
            address.locality = value[(__bridge NSString*)kABPersonAddressCityKey];
            address.region = value[(__bridge NSString*)kABPersonAddressStateKey];
            address.postalCode = value[(__bridge NSString*)kABPersonAddressZIPKey];
            address.country = value[(__bridge NSString*)kABPersonAddressCountryKey];

            [addresses addObject:address];
        }
    } else if (contactProperty == kABPersonDateProperty) {
        _ABMultiValue* multiValue = (__bridge _ABMultiValue*)value;
        if (!_checkType(kABDateTimePropertyType, multiValue, error)) {
            return false;
        }

        // Filter importantDates so it only contains birthdays (since those should
        // not be removed in this case.)
        NSMutableArray* importantDates = person.contact.importantDates;
        NSPredicate* predicate = [NSPredicate predicateWithBlock:^BOOL(id obj, NSDictionary* bindings) {
            return ((WACContactDate*)obj).kind == WACContactDateKindBirthday;
        }];

        [importantDates filterUsingPredicate:predicate];

        NSDictionary* dict = @{
            ((__bridge NSString*)kABPersonAnniversaryLabel) : @(WACContactDateKindAnniversary),
            ((__bridge NSString*)kABOtherLabel) : @(WACContactDateKindOther)
        };

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* label = (__bridge_transfer NSString*)[multiValue copyLabelAtIndex:i];
            NSDate* value = (__bridge_transfer NSDate*)[multiValue copyValueAtIndex:i];
            WACContactDate* date = [WACContactDate make];
            date.kind = dict[label] == nil ? WACContactDateKindOther : [dict[label] integerValue];

            unsigned int units = NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit;
            NSCalendar* calendar = [NSCalendar currentCalendar];
            NSDateComponents* components = [calendar components:units fromDate:value];

            date.year = @([components year]);
            date.month = @([components month]);
            date.day = @([components day]);

            [importantDates addObject:date];
        }
    } else if (contactProperty == kABPersonPhoneProperty) {
        _ABMultiValue* multiValue = (__bridge _ABMultiValue*)value;
        if (!_checkType(kABStringPropertyType, multiValue, error)) {
            return false;
        }

        // Ensure that none of the values violate the allowed length of Windows
        // Contacts properties.
        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            if (!_checkLength(value, kABPersonPhoneLength, error, @"phone")) {
                return false;
            }
        }

        NSMutableArray* phones = person.contact.phones;
        [phones removeAllObjects];

        NSDictionary* dict = @{
            ((__bridge NSString*)kABHomeLabel) : @(WACContactPhoneKindHome),
            ((__bridge NSString*)kABPersonPhoneMobileLabel) : @(WACContactPhoneKindMobile),
            ((__bridge NSString*)kABWorkLabel) : @(WACContactPhoneKindWork),
            ((__bridge NSString*)kABPersonPhonePagerLabel) : @(WACContactPhoneKindPager),
            ((__bridge NSString*)kABPersonPhoneWorkFAXLabel) : @(WACContactPhoneKindBusinessFax),
            ((__bridge NSString*)kABPersonPhoneHomeFAXLabel) : @(WACContactPhoneKindHomeFax),
            ((__bridge NSString*)kABPersonPhoneCompanyLabel) : @(WACContactPhoneKindCompany),
            ((__bridge NSString*)kABPersonPhoneAssistantLabel) : @(WACContactPhoneKindAssistant),
            ((__bridge NSString*)kABPersonPhoneRadioLabel) : @(WACContactPhoneKindRadio),
            ((__bridge NSString*)kABOtherLabel) : @(WACContactPhoneKindOther)
        };

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* label = (__bridge_transfer NSString*)[multiValue copyLabelAtIndex:i];
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            WACContactPhone* phone = [WACContactPhone make];
            phone.number = value;
            phone.kind = dict[label] == nil ? WACContactPhoneKindOther : [dict[label] integerValue];
            [phones addObject:phone];
        }
    } else if (contactProperty == kABPersonURLProperty) {
        _ABMultiValue* multiValue = (__bridge _ABMultiValue*)value;
        if (!_checkType(kABStringPropertyType, multiValue, error)) {
            return false;
        }

        NSMutableArray* websites = person.contact.websites;
        [websites removeAllObjects];

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            WACContactWebsite* website = [WACContactWebsite make];
            website.rawValue = value;
            [websites addObject:website];
        }
    } else if (contactProperty == kABPersonRelatedNamesProperty) {
        _ABMultiValue* multiValue = (__bridge _ABMultiValue*)value;
        if (!_checkType(kABStringPropertyType, multiValue, error)) {
            return false;
        }

        // Ensure that none of the values violate the allowed length of Windows
        // Contacts properties.
        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            if (!_checkLength(value, kABPersonRelatedNamesLength, error, @"related name")) {
                return false;
            }
        }

        NSMutableArray* significantOthers = person.contact.significantOthers;
        [significantOthers removeAllObjects];

        NSDictionary* dict = @{
            ((__bridge NSString*)kABPersonSpouseLabel) : @(WACContactRelationshipSpouse),
            ((__bridge NSString*)kABPersonPartnerLabel) : @(WACContactRelationshipPartner),
            ((__bridge NSString*)kABPersonSiblingLabel) : @(WACContactRelationshipSibling),
            ((__bridge NSString*)kABPersonParentLabel) : @(WACContactRelationshipParent),
            ((__bridge NSString*)kABPersonChildLabel) : @(WACContactRelationshipChild),
            ((__bridge NSString*)kABOtherLabel) : @(WACContactRelationshipOther)
        };

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* label = (__bridge_transfer NSString*)[multiValue copyLabelAtIndex:i];
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            WACContactSignificantOther* significantOther = [WACContactSignificantOther make];
            significantOther.name = value;
            significantOther.relationship = dict[label] == nil ? WACContactRelationshipOther : [dict[label] integerValue];
            [significantOthers addObject:significantOther];
        }
    } else {
        // No matching property was found.
        if (error) {
            NSDictionary* userInfo = @{
                NSLocalizedDescriptionKey : NSLocalizedString(@"Error setting record value.\n", nil),
                NSLocalizedFailureReasonErrorKey : NSLocalizedString(@"The property id was not recognized or supported!\n", nil)
            };
            *error = (__bridge_retained CFErrorRef)[NSError errorWithDomain:(__bridge NSString*)ABAddressBookErrorDomain
                                                                       code:kABOperationNotPermittedByStoreError
                                                                   userInfo:userInfo];
        }

        return false;
    }

    _updateManager(person);
    return true;
}

/**
 @Status Caveat
 @Notes A few properties (alternate birthday, creation/modification dates, person kind,
        phonetic middle name, address country code and instant message/social profile accounts)
        don't have direct equivalents.

        For kABPersonRelatedNamesProperty, there is a new label, kABPersonSiblingLabel.
        For kABPersonPhoneProperty, there are 3 new labels: kABPersonPhoneCompanyLabel,
        kABPersonPhoneAssistantLabel, and kABPersonPhoneRadioLabel.
*/
CFTypeRef ABRecordCopyValue(ABRecordRef record, ABPropertyID contactProperty) {
    if (record == nullptr) {
        return nullptr;
    }

    _ABContact* person = (__bridge _ABContact*)record;

    // Cases for various name properties.
    if (contactProperty == kABPersonFirstNameProperty) {
        return (__bridge_retained CFTypeRef)person.contact.firstName;
    } else if (contactProperty == kABPersonLastNameProperty) {
        return (__bridge_retained CFTypeRef)person.contact.lastName;
    } else if (contactProperty == kABPersonMiddleNameProperty) {
        return (__bridge_retained CFTypeRef)person.contact.middleName;
    } else if (contactProperty == kABPersonPrefixProperty) {
        return (__bridge_retained CFTypeRef)person.contact.honorificNamePrefix;
    } else if (contactProperty == kABPersonSuffixProperty) {
        return (__bridge_retained CFTypeRef)person.contact.honorificNameSuffix;
    } else if (contactProperty == kABPersonNicknameProperty) {
        return (__bridge_retained CFTypeRef)person.contact.nickname;
    } else if (contactProperty == kABPersonFirstNamePhoneticProperty) {
        return (__bridge_retained CFTypeRef)person.contact.yomiGivenName;
    } else if (contactProperty == kABPersonLastNamePhoneticProperty) {
        return (__bridge_retained CFTypeRef)person.contact.yomiFamilyName;
    }

    // Cases for job-related properties.
    if (contactProperty == kABPersonOrganizationProperty) {
        NSArray* jobInfo = person.contact.jobInfo;
        return [jobInfo count] > 0 ? (__bridge_retained CFTypeRef)((WACContactJobInfo*)jobInfo[0]).companyName : nullptr;
    } else if (contactProperty == kABPersonJobTitleProperty) {
        NSArray* jobInfo = person.contact.jobInfo;
        return [jobInfo count] > 0 ? (__bridge_retained CFTypeRef)((WACContactJobInfo*)jobInfo[0]).title : nullptr;
    } else if (contactProperty == kABPersonDepartmentProperty) {
        NSArray* jobInfo = person.contact.jobInfo;
        return [jobInfo count] > 0 ? (__bridge_retained CFTypeRef)((WACContactJobInfo*)jobInfo[0]).department : nullptr;
    }

    // Case for birthday-related property.
    if (contactProperty == kABPersonBirthdayProperty) {
        NSArray* dates = person.contact.importantDates;

        // Find the first date in the contact's important dates
        // that is marked as a birthday, since a Windows contact stores
        // all of its important dates in a list under a single property
        // rather than explicitly storing the birthday.
        NSUInteger birthdayIndex = [dates indexOfObjectPassingTest:^BOOL(id obj, NSUInteger idx, BOOL* stop) {
            WACContactDate* date = (WACContactDate*)obj;
            if (date.kind == WACContactDateKindBirthday) {
                *stop = YES;
                return YES;
            } else {
                return NO;
            }
        }];

        if (birthdayIndex == NSNotFound) {
            return nullptr;
        } else {
            WACContactDate* date = dates[birthdayIndex];

            // NSDate is toll-free bridged with CFDate, which is the type
            // the user expects to receive.
            NSDate* resultDate = [NSDate dateWithWACContactDate:date];
            return (__bridge_retained CFTypeRef)resultDate;
        }
    }

    // Case for note-related property.
    if (contactProperty == kABPersonNoteProperty) {
        return (__bridge_retained CFTypeRef)person.contact.notes;
    }

    /* The following properties don't have a good 1-1 mapping between iOS contacts
       and Windows contacts (alternate birthday, creation/modification dates,
       phonetic middle name, instant message/social profile). There is currently
       no support planned for them.

        kABPersonMiddleNamePhoneticProperty
        kABPersonKindProperty
        kABPersonAlternateBirthdayProperty
        kABPersonCreationDateProperty
        kABPersonModificationDateProperty
        kABPersonInstantMessageProperty
        kABPersonSocialProfileProperty
    */

    // Cases for various multi-value properties.
    if (contactProperty == kABPersonEmailProperty) {
        _ABMultiValue* emailMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABStringPropertyType];
        NSArray* emails = person.contact.emails;
        [emails enumerateObjectsUsingBlock:^void(id obj, NSUInteger idx, BOOL* stop) {
            WACContactEmail* email = (WACContactEmail*)obj;
            CFStringRef label;
            switch (email.kind) {
                case WACContactEmailKindPersonal:
                    label = kABHomeLabel;
                    break;
                case WACContactEmailKindWork:
                    label = kABWorkLabel;
                    break;
                case WACContactEmailKindOther:
                default:
                    label = kABOtherLabel;
                    break;
            }

            [emailMultiValue appendPairWithLabel:(__bridge NSString*)label andValue:email.address];
        }];

        [emailMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)emailMultiValue;
    }

    if (contactProperty == kABPersonAddressProperty) {
        _ABMultiValue* addressMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABDictionaryPropertyType];
        NSArray* addresses = person.contact.addresses;
        [addresses enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL* stop) {
            WACContactAddress* address = (WACContactAddress*)obj;
            CFStringRef label;
            switch (address.kind) {
                case WACContactAddressKindHome:
                    label = kABHomeLabel;
                    break;
                case WACContactAddressKindWork:
                    label = kABWorkLabel;
                    break;
                case WACContactAddressKindOther:
                default:
                    label = kABOtherLabel;
                    break;
            }

            NSDictionary* dictionary = @{
                ((__bridge NSString*)kABPersonAddressStreetKey) : address.streetAddress,
                ((__bridge NSString*)kABPersonAddressCityKey) : address.locality,
                ((__bridge NSString*)kABPersonAddressStateKey) : address.region,
                ((__bridge NSString*)kABPersonAddressZIPKey) : address.postalCode,
                ((__bridge NSString*)kABPersonAddressCountryKey) : address.country
            };

            [addressMultiValue appendPairWithLabel:(__bridge NSString*)label andValue:dictionary];
        }];

        [addressMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)addressMultiValue;
    }

    if (contactProperty == kABPersonDateProperty) {
        _ABMultiValue* dateMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABDateTimePropertyType];
        NSArray* dates = person.contact.importantDates;
        [dates enumerateObjectsUsingBlock:^void(id obj, NSUInteger idx, BOOL* stop) {
            WACContactDate* date = (WACContactDate*)obj;
            CFStringRef label;
            switch (date.kind) {
                case WACContactDateKindBirthday:
                    // Ignore the contact's birthday, since iOS
                    // has a separate property for the user's birthday.
                    return;
                case WACContactDateKindAnniversary:
                    label = kABPersonAnniversaryLabel;
                    break;
                case WACContactDateKindOther:
                default:
                    label = kABOtherLabel;
                    break;
            }

            NSDate* resultDate = [NSDate dateWithWACContactDate:date];
            [dateMultiValue appendPairWithLabel:(__bridge NSString*)label andValue:resultDate];
        }];

        [dateMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)dateMultiValue;
    }

    if (contactProperty == kABPersonPhoneProperty) {
        _ABMultiValue* phoneMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABStringPropertyType];
        NSArray* phoneNumbers = person.contact.phones;
        [phoneNumbers enumerateObjectsUsingBlock:^void(id obj, NSUInteger idx, BOOL* stop) {
            WACContactPhone* phoneNumber = (WACContactPhone*)obj;
            CFStringRef label;
            switch (phoneNumber.kind) {
                case WACContactPhoneKindHome:
                    label = kABHomeLabel;
                    break;
                case WACContactPhoneKindMobile:
                    label = kABPersonPhoneMobileLabel;
                    break;
                case WACContactPhoneKindWork:
                    label = kABWorkLabel;
                    break;
                case WACContactPhoneKindPager:
                    label = kABPersonPhonePagerLabel;
                    break;
                case WACContactPhoneKindBusinessFax:
                    label = kABPersonPhoneWorkFAXLabel;
                    break;
                case WACContactPhoneKindHomeFax:
                    label = kABPersonPhoneHomeFAXLabel;
                    break;
                case WACContactPhoneKindCompany:
                    label = kABPersonPhoneCompanyLabel;
                    break;
                case WACContactPhoneKindAssistant:
                    label = kABPersonPhoneAssistantLabel;
                    break;
                case WACContactPhoneKindRadio:
                    label = kABPersonPhoneRadioLabel;
                    break;
                case WACContactPhoneKindOther:
                default:
                    label = kABOtherLabel;
                    break;
            }

            [phoneMultiValue appendPairWithLabel:(__bridge NSString*)label andValue:phoneNumber.number];
        }];

        [phoneMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)phoneMultiValue;
    }

    if (contactProperty == kABPersonURLProperty) {
        _ABMultiValue* urlMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABStringPropertyType];
        NSArray* websites = person.contact.websites;
        [websites enumerateObjectsUsingBlock:^void(id obj, NSUInteger idx, BOOL* stop) {
            WACContactWebsite* website = (WACContactWebsite*)obj;
            [urlMultiValue appendPairWithLabel:(__bridge NSString*)kABPersonHomePageLabel andValue:website.rawValue];
        }];

        [urlMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)urlMultiValue;
    }

    if (contactProperty == kABPersonRelatedNamesProperty) {
        _ABMultiValue* relatedNamesMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABStringPropertyType];
        NSArray* significantOthers = person.contact.significantOthers;
        [significantOthers enumerateObjectsUsingBlock:^void(id obj, NSUInteger idx, BOOL* stop) {
            WACContactSignificantOther* significantOther = (WACContactSignificantOther*)obj;
            CFStringRef label;
            switch (significantOther.relationship) {
                case WACContactRelationshipSpouse:
                    label = kABPersonSpouseLabel;
                    break;
                case WACContactRelationshipPartner:
                    label = kABPersonPartnerLabel;
                    break;
                case WACContactRelationshipSibling:
                    label = kABPersonSiblingLabel;
                    break;
                case WACContactRelationshipParent:
                    label = kABPersonParentLabel;
                    break;
                case WACContactRelationshipChild:
                    label = kABPersonChildLabel;
                    break;
                case WACContactRelationshipOther:
                default:
                    label = kABOtherLabel;
                    break;
            }

            [relatedNamesMultiValue appendPairWithLabel:(__bridge NSString*)label andValue:significantOther.name];
        }];

        [relatedNamesMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)relatedNamesMultiValue;
    }

    return nullptr;
}

/**
 @Status Caveat
 @Notes Records can only be modified if they are newly created (with ABPersonCreate)
 or are retrieved with ABAddressBookCopyArrayOfAllUserAppPeople -- contacts from
 ABAddressBookCopyArrayOfAllPeople are read-only and cannot have their properties changed.
*/
bool ABRecordRemoveValue(ABRecordRef record, ABPropertyID property, CFErrorRef* error) {
    return ABRecordSetValue(record, property, nullptr, error);
}

/**
 @Status Interoperable
 @Notes record is treated as a Person record, since the Windows Contacts
        Framework doesn't support Group records.
*/
CFStringRef ABRecordCopyCompositeName(ABRecordRef record) {
    // Behavior on the reference platform is undefined for Source records,
    // and the Windows Contacts Framework doesn't support Group records, so we can assume
    // it is a Person record.
    _ABContact* person = (__bridge _ABContact*)record;
    return (__bridge_retained CFStringRef)person.contact.fullName;
}
