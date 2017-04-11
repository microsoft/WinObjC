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
#import "CppWinRTHelpers.h"

using namespace winrt::Windows::ApplicationModel::Contacts;
namespace WF = winrt::Windows::Foundation;
namespace WFC = winrt::Windows::Foundation::Collections;

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
            NSString* fullId = objcwinrt::string(person.contact.Id());

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

        person.contact.FirstName(objcwinrt::string(firstName));
    } else if (contactProperty == kABPersonLastNameProperty) {
        NSString* lastName = (__bridge NSString*)value;
        if (!_checkLength(lastName, kABPersonLastNameLength, error, @"last name")) {
            return false;
        }

        person.contact.LastName(objcwinrt::string(lastName));
    } else if (contactProperty == kABPersonMiddleNameProperty) {
        NSString* middleName = (__bridge NSString*)value;
        if (!_checkLength(middleName, kABPersonMiddleNameLength, error, @"middle name")) {
            return false;
        }

        person.contact.MiddleName(objcwinrt::string(middleName));
    } else if (contactProperty == kABPersonPrefixProperty) {
        NSString* prefix = (__bridge NSString*)value;
        if (!_checkLength(prefix, kABPersonPrefixLength, error, @"prefix")) {
            return false;
        }

        person.contact.HonorificNamePrefix(objcwinrt::string(prefix));
    } else if (contactProperty == kABPersonSuffixProperty) {
        NSString* suffix = (__bridge NSString*)value;
        if (!_checkLength(suffix, kABPersonSuffixLength, error, @"suffix")) {
            return false;
        }

        person.contact.HonorificNameSuffix(objcwinrt::string(suffix));
    } else if (contactProperty == kABPersonNicknameProperty) {
        NSString* nickname = (__bridge NSString*)value;
        person.contact.Nickname(objcwinrt::string(nickname));
    } else if (contactProperty == kABPersonFirstNamePhoneticProperty) {
        NSString* phoneticFirstName = (__bridge NSString*)value;
        if (!_checkLength(phoneticFirstName, kABPersonFirstNamePhoneticLength, error, @"first name phonetic")) {
            return false;
        }

        person.contact.YomiGivenName(objcwinrt::string(phoneticFirstName));
    } else if (contactProperty == kABPersonLastNamePhoneticProperty) {
        NSString* phoneticLastName = (__bridge NSString*)value;
        if (!_checkLength(phoneticLastName, kABPersonLastNamePhoneticLength, error, @"last name phonetic")) {
            return false;
        }

        person.contact.YomiFamilyName(objcwinrt::string(phoneticLastName));

        // Cases for job-related properties.
    } else if (contactProperty == kABPersonOrganizationProperty) {
        NSString* organization = (__bridge NSString*)value;
        if (!_checkLength(organization, kABPersonOrganizationLength, error, @"organization")) {
            return false;
        }

        WFC::IVector<ContactJobInfo> jobInfo = person.contact.JobInfo();
        if (jobInfo.Size() == 0) {
            jobInfo.Append(ContactJobInfo());
        }

        ContactJobInfo job = jobInfo.GetAt(0);
        job.CompanyName(objcwinrt::string(organization));
    } else if (contactProperty == kABPersonJobTitleProperty) {
        NSString* jobTitle = (__bridge NSString*)value;
        if (!_checkLength(jobTitle, kABPersonJobTitleLength, error, @"job title")) {
            return false;
        }

        WFC::IVector<ContactJobInfo> jobInfo = person.contact.JobInfo();
        if (jobInfo.Size() == 0) {
            jobInfo.Append(ContactJobInfo());
        }

        ContactJobInfo job = jobInfo.GetAt(0);
        job.Title(objcwinrt::string(jobTitle));
    } else if (contactProperty == kABPersonDepartmentProperty) {
        NSString* department = (__bridge NSString*)value;
        if (!_checkLength(department, kABPersonDepartmentLength, error, @"department")) {
            return false;
        }

        WFC::IVector<ContactJobInfo> jobInfo = person.contact.JobInfo();
        if (jobInfo.Size() == 0) {
            jobInfo.Append(ContactJobInfo());
        }

        ContactJobInfo job = jobInfo.GetAt(0);
        job.Department(objcwinrt::string(department));

        // Case for birthday-related property.
    } else if (contactProperty == kABPersonBirthdayProperty) {
        WFC::IVector<ContactDate> dates = person.contact.ImportantDates();
        ContactDate date = nullptr;

        // Find the first date in the contact's important dates
        // that is marked as a birthday, since a Windows contact stores
        // all of its important dates in a list under a single property
        // rather than explicitly storing the birthday.
        for (const ContactDate& d : dates) {
            if (d.Kind() == ContactDateKind::Birthday) {
                date = d;
                break;
            }
        }

        // If no birthday was found, create a new date for it --
        // otherwise, just use the existing birthday.
        if (!date) {
            date = ContactDate();
            date.Kind(ContactDateKind::Birthday);
            dates.Append(date);
        }

        NSDate* birthday = (__bridge NSDate*)value;
        unsigned int units = NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit;
        NSCalendar* calendar = [NSCalendar currentCalendar];
        NSDateComponents* components = [calendar components:units fromDate:birthday];

        date.Year(objcwinrt::optional<int>([components year]));
        date.Month(objcwinrt::optional<unsigned int>([components month]));
        date.Day(objcwinrt::optional<unsigned int>([components day]));

        // Case for note-related property.
    } else if (contactProperty == kABPersonNoteProperty) {
        NSString* note = (__bridge NSString*)value;
        if (!_checkLength(note, kABPersonNoteLength, error, @"note")) {
            return false;
        }

        person.contact.Notes(objcwinrt::string(note));

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

        WFC::IVector<ContactEmail> emails = person.contact.Emails();
        emails.Clear();

        NSDictionary* dict = @{
            ((__bridge NSString*)kABHomeLabel) : @(static_cast<NSInteger>(ContactEmailKind::Personal)),
            ((__bridge NSString*)kABWorkLabel) : @(static_cast<NSInteger>(ContactEmailKind::Work)),
            ((__bridge NSString*)kABOtherLabel) : @(static_cast<NSInteger>(ContactEmailKind::Other))
        };

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* label = (__bridge_transfer NSString*)[multiValue copyLabelAtIndex:i];
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            ContactEmail email;
            email.Address(objcwinrt::string(value));
            email.Kind(dict[label] == nil ? ContactEmailKind::Other : static_cast<ContactEmailKind>([dict[label] integerValue]));
            emails.Append(email);
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

        WFC::IVector<ContactAddress> addresses = person.contact.Addresses();
        addresses.Clear();

        NSDictionary* dict = @{
            ((__bridge NSString*)kABHomeLabel) : @(static_cast<NSInteger>(ContactAddressKind::Home)),
            ((__bridge NSString*)kABWorkLabel) : @(static_cast<NSInteger>(ContactAddressKind::Work)),
            ((__bridge NSString*)kABOtherLabel) : @(static_cast<NSInteger>(ContactAddressKind::Other))
        };

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* label = (__bridge_transfer NSString*)[multiValue copyLabelAtIndex:i];
            NSDictionary<NSString*,NSString*>* value = (__bridge_transfer NSDictionary<NSString*,NSString*>*)[multiValue copyValueAtIndex:i];
            ContactAddress address;
            address.Kind(dict[label] == nil ? ContactAddressKind::Other : static_cast<ContactAddressKind>([dict[label] integerValue]));
            address.StreetAddress(objcwinrt::string(value[(__bridge NSString*)kABPersonAddressStreetKey]));
            address.Locality(objcwinrt::string(value[(__bridge NSString*)kABPersonAddressCityKey]));
            address.Region(objcwinrt::string(value[(__bridge NSString*)kABPersonAddressStateKey]));
            address.PostalCode(objcwinrt::string(value[(__bridge NSString*)kABPersonAddressZIPKey]));
            address.Country(objcwinrt::string(value[(__bridge NSString*)kABPersonAddressCountryKey]));

            addresses.Append(address);
        }
    } else if (contactProperty == kABPersonDateProperty) {
        _ABMultiValue* multiValue = (__bridge _ABMultiValue*)value;
        if (!_checkType(kABDateTimePropertyType, multiValue, error)) {
            return false;
        }

        // Filter importantDates so it only contains birthdays (since those should
        // not be removed in this case.)
        WFC::IVector<ContactDate> importantDates = person.contact.ImportantDates();
        for (unsigned int i = 0; i < importantDates.Size(); ) {
            if (importantDates.GetAt(i).Kind() == ContactDateKind::Birthday) {
                i++;
            } else {
                importantDates.RemoveAt(i);
            }
        }

        NSDictionary* dict = @{
            ((__bridge NSString*)kABPersonAnniversaryLabel) : @(static_cast<NSInteger>(ContactDateKind::Anniversary)),
            ((__bridge NSString*)kABOtherLabel) : @(static_cast<NSInteger>(ContactDateKind::Other))
        };

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* label = (__bridge_transfer NSString*)[multiValue copyLabelAtIndex:i];
            NSDate* value = (__bridge_transfer NSDate*)[multiValue copyValueAtIndex:i];
            ContactDate date;
            date.Kind(dict[label] == nil ? ContactDateKind::Other : static_cast<ContactDateKind>([dict[label] integerValue]));

            unsigned int units = NSYearCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit;
            NSCalendar* calendar = [NSCalendar currentCalendar];
            NSDateComponents* components = [calendar components:units fromDate:value];

            date.Year(objcwinrt::optional<int>([components year]));
            date.Month(objcwinrt::optional<unsigned int>([components month]));
            date.Day(objcwinrt::optional<unsigned int>([components day]));

            importantDates.Append(date);
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

        WFC::IVector<ContactPhone> phones = person.contact.Phones();
        phones.Clear();

        NSDictionary* dict = @{
            ((__bridge NSString*)kABHomeLabel) : @(static_cast<NSInteger>(ContactPhoneKind::Home)),
            ((__bridge NSString*)kABPersonPhoneMobileLabel) : @(static_cast<NSInteger>(ContactPhoneKind::Mobile)),
            ((__bridge NSString*)kABWorkLabel) : @(static_cast<NSInteger>(ContactPhoneKind::Work)),
            ((__bridge NSString*)kABPersonPhonePagerLabel) : @(static_cast<NSInteger>(ContactPhoneKind::Pager)),
            ((__bridge NSString*)kABPersonPhoneWorkFAXLabel) : @(static_cast<NSInteger>(ContactPhoneKind::BusinessFax)),
            ((__bridge NSString*)kABPersonPhoneHomeFAXLabel) : @(static_cast<NSInteger>(ContactPhoneKind::HomeFax)),
            ((__bridge NSString*)kABPersonPhoneCompanyLabel) : @(static_cast<NSInteger>(ContactPhoneKind::Company)),
            ((__bridge NSString*)kABPersonPhoneAssistantLabel) : @(static_cast<NSInteger>(ContactPhoneKind::Assistant)),
            ((__bridge NSString*)kABPersonPhoneRadioLabel) : @(static_cast<NSInteger>(ContactPhoneKind::Radio)),
            ((__bridge NSString*)kABOtherLabel) : @(static_cast<NSInteger>(ContactPhoneKind::Other))
        };

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* label = (__bridge_transfer NSString*)[multiValue copyLabelAtIndex:i];
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            ContactPhone phone;
            phone.Number(objcwinrt::string(value));
            phone.Kind(dict[label] == nil ? ContactPhoneKind::Other : static_cast<ContactPhoneKind>([dict[label] integerValue]));
            phones.Append(phone);
        }
    } else if (contactProperty == kABPersonURLProperty) {
        _ABMultiValue* multiValue = (__bridge _ABMultiValue*)value;
        if (!_checkType(kABStringPropertyType, multiValue, error)) {
            return false;
        }

        WFC::IVector<ContactWebsite> websites = person.contact.Websites();
        websites.Clear();

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            ContactWebsite website;
            website.RawValue(objcwinrt::string(value));
            websites.Append(website);
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

        WFC::IVector<ContactSignificantOther> significantOthers = person.contact.SignificantOthers();
        significantOthers.Clear();

        NSDictionary* dict = @{
            ((__bridge NSString*)kABPersonSpouseLabel) : @(static_cast<NSInteger>(ContactRelationship::Spouse)),
            ((__bridge NSString*)kABPersonPartnerLabel) : @(static_cast<NSInteger>(ContactRelationship::Partner)),
            ((__bridge NSString*)kABPersonSiblingLabel) : @(static_cast<NSInteger>(ContactRelationship::Sibling)),
            ((__bridge NSString*)kABPersonParentLabel) : @(static_cast<NSInteger>(ContactRelationship::Parent)),
            ((__bridge NSString*)kABPersonChildLabel) : @(static_cast<NSInteger>(ContactRelationship::Child)),
            ((__bridge NSString*)kABOtherLabel) : @(static_cast<NSInteger>(ContactRelationship::Other))
        };

        for (int i = 0; i < [multiValue getCount]; i++) {
            NSString* label = (__bridge_transfer NSString*)[multiValue copyLabelAtIndex:i];
            NSString* value = (__bridge_transfer NSString*)[multiValue copyValueAtIndex:i];
            ContactSignificantOther significantOther;
            significantOther.Name(objcwinrt::string(value));
            significantOther.Relationship(dict[label] == nil ? ContactRelationship::Other : static_cast<ContactRelationship>([dict[label] integerValue]));
            significantOthers.Append(significantOther);
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
        return (__bridge_retained CFTypeRef)objcwinrt::string(person.contact.FirstName());
    } else if (contactProperty == kABPersonLastNameProperty) {
        return (__bridge_retained CFTypeRef)objcwinrt::string(person.contact.LastName());
    } else if (contactProperty == kABPersonMiddleNameProperty) {
        return (__bridge_retained CFTypeRef)objcwinrt::string(person.contact.MiddleName());
    } else if (contactProperty == kABPersonPrefixProperty) {
        return (__bridge_retained CFTypeRef)objcwinrt::string(person.contact.HonorificNamePrefix());
    } else if (contactProperty == kABPersonSuffixProperty) {
        return (__bridge_retained CFTypeRef)objcwinrt::string(person.contact.HonorificNameSuffix());
    } else if (contactProperty == kABPersonNicknameProperty) {
        return (__bridge_retained CFTypeRef)objcwinrt::string(person.contact.Nickname());
    } else if (contactProperty == kABPersonFirstNamePhoneticProperty) {
        return (__bridge_retained CFTypeRef)objcwinrt::string(person.contact.YomiGivenName());
    } else if (contactProperty == kABPersonLastNamePhoneticProperty) {
        return (__bridge_retained CFTypeRef)objcwinrt::string(person.contact.YomiFamilyName());
    }

    // Cases for job-related properties.
    if (contactProperty == kABPersonOrganizationProperty) {
        WFC::IVector<ContactJobInfo> jobInfo = person.contact.JobInfo();
        return jobInfo.Size() > 0 ? (__bridge_retained CFTypeRef)objcwinrt::string(jobInfo.GetAt(0).CompanyName()) : nullptr;
    } else if (contactProperty == kABPersonJobTitleProperty) {
        WFC::IVector<ContactJobInfo> jobInfo = person.contact.JobInfo();
        return jobInfo.Size() > 0 ? (__bridge_retained CFTypeRef)objcwinrt::string(jobInfo.GetAt(0).Title()) : nullptr;
    } else if (contactProperty == kABPersonDepartmentProperty) {
        WFC::IVector<ContactJobInfo> jobInfo = person.contact.JobInfo();
        return jobInfo.Size() > 0 ? (__bridge_retained CFTypeRef)objcwinrt::string(jobInfo.GetAt(0).Department()) : nullptr;
    }

    // Case for birthday-related property.
    if (contactProperty == kABPersonBirthdayProperty) {
        WFC::IVector<ContactDate> dates = person.contact.ImportantDates();
        ContactDate date = nullptr;

        // Find the first date in the contact's important dates
        // that is marked as a birthday, since a Windows contact stores
        // all of its important dates in a list under a single property
        // rather than explicitly storing the birthday.
        for (const ContactDate& d : dates) {
            if (d.Kind() == ContactDateKind::Birthday) {
                date = d;
                break;
            }
        }

        if (!date) {
            return nullptr;
        } else {
            // NSDate is toll-free bridged with CFDate, which is the type
            // the user expects to receive.
            NSDate* resultDate = [NSDate dateWithContactDate:date];
            return (__bridge_retained CFTypeRef)resultDate;
        }
    }

    // Case for note-related property.
    if (contactProperty == kABPersonNoteProperty) {
        return (__bridge_retained CFTypeRef)objcwinrt::string(person.contact.Notes());
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
        WFC::IVector<ContactEmail> emails = person.contact.Emails();
        for (const ContactEmail& email : emails) {
            CFStringRef label;
            switch (email.Kind()) {
                case ContactEmailKind::Personal:
                    label = kABHomeLabel;
                    break;
                case ContactEmailKind::Work:
                    label = kABWorkLabel;
                    break;
                case ContactEmailKind::Other:
                default:
                    label = kABOtherLabel;
                    break;
            }

            [emailMultiValue appendPairWithLabel:(__bridge NSString*)label andValue:objcwinrt::string(email.Address())];
        };

        [emailMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)emailMultiValue;
    }

    if (contactProperty == kABPersonAddressProperty) {
        _ABMultiValue* addressMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABDictionaryPropertyType];
        WFC::IVector<ContactAddress> addresses = person.contact.Addresses();

        for (const ContactAddress& address : addresses) {
            CFStringRef label;
            switch (address.Kind()) {
                case ContactAddressKind::Home:
                    label = kABHomeLabel;
                    break;
                case ContactAddressKind::Work:
                    label = kABWorkLabel;
                    break;
                case ContactAddressKind::Other:
                default:
                    label = kABOtherLabel;
                    break;
            }

            NSDictionary* dictionary = @{
                ((__bridge NSString*)kABPersonAddressStreetKey) : objcwinrt::string(address.StreetAddress()),
                ((__bridge NSString*)kABPersonAddressCityKey) : objcwinrt::string(address.Locality()),
                ((__bridge NSString*)kABPersonAddressStateKey) : objcwinrt::string(address.Region()),
                ((__bridge NSString*)kABPersonAddressZIPKey) : objcwinrt::string(address.PostalCode()),
                ((__bridge NSString*)kABPersonAddressCountryKey) : objcwinrt::string(address.Country())
            };

            [addressMultiValue appendPairWithLabel:(__bridge NSString*)label andValue:dictionary];
        };

        [addressMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)addressMultiValue;
    }

    if (contactProperty == kABPersonDateProperty) {
        _ABMultiValue* dateMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABDateTimePropertyType];
        WFC::IVector<ContactDate> dates = person.contact.ImportantDates();
        for (const ContactDate& date : dates) {
            CFStringRef label;
            switch (date.Kind()) {
                case ContactDateKind::Birthday:
                    // Ignore the contact's birthday, since iOS
                    // has a separate property for the user's birthday.
                    continue;
                case ContactDateKind::Anniversary:
                    label = kABPersonAnniversaryLabel;
                    break;
                case ContactDateKind::Other:
                default:
                    label = kABOtherLabel;
                    break;
            }

            NSDate* resultDate = [NSDate dateWithContactDate:date];
            [dateMultiValue appendPairWithLabel:(__bridge NSString*)label andValue:resultDate];
        };

        [dateMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)dateMultiValue;
    }

    if (contactProperty == kABPersonPhoneProperty) {
        _ABMultiValue* phoneMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABStringPropertyType];
        WFC::IVector<ContactPhone> phoneNumbers = person.contact.Phones();
        for (const ContactPhone& phoneNumber : phoneNumbers) {
            CFStringRef label;
            switch (phoneNumber.Kind()) {
                case ContactPhoneKind::Home:
                    label = kABHomeLabel;
                    break;
                case ContactPhoneKind::Mobile:
                    label = kABPersonPhoneMobileLabel;
                    break;
                case ContactPhoneKind::Work:
                    label = kABWorkLabel;
                    break;
                case ContactPhoneKind::Pager:
                    label = kABPersonPhonePagerLabel;
                    break;
                case ContactPhoneKind::BusinessFax:
                    label = kABPersonPhoneWorkFAXLabel;
                    break;
                case ContactPhoneKind::HomeFax:
                    label = kABPersonPhoneHomeFAXLabel;
                    break;
                case ContactPhoneKind::Company:
                    label = kABPersonPhoneCompanyLabel;
                    break;
                case ContactPhoneKind::Assistant:
                    label = kABPersonPhoneAssistantLabel;
                    break;
                case ContactPhoneKind::Radio:
                    label = kABPersonPhoneRadioLabel;
                    break;
                case ContactPhoneKind::Other:
                default:
                    label = kABOtherLabel;
                    break;
            }

            [phoneMultiValue appendPairWithLabel:(__bridge NSString*)label andValue:objcwinrt::string(phoneNumber.Number())];
        };

        [phoneMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)phoneMultiValue;
    }

    if (contactProperty == kABPersonURLProperty) {
        _ABMultiValue* urlMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABStringPropertyType];
        WFC::IVector<ContactWebsite> websites = person.contact.Websites();
        for (const ContactWebsite& website : websites) {
            [urlMultiValue appendPairWithLabel:(__bridge NSString*)kABPersonHomePageLabel
                                      andValue:objcwinrt::string(website.RawValue())];
        };

        [urlMultiValue makeImmutable];
        return (__bridge_retained CFTypeRef)urlMultiValue;
    }

    if (contactProperty == kABPersonRelatedNamesProperty) {
        _ABMultiValue* relatedNamesMultiValue = [[_ABMultiValue alloc] initWithPropertyType:kABStringPropertyType];
        WFC::IVector<ContactSignificantOther> significantOthers = person.contact.SignificantOthers();
        for (const ContactSignificantOther& significantOther : significantOthers) {
            CFStringRef label;
            switch (significantOther.Relationship()) {
                case ContactRelationship::Spouse:
                    label = kABPersonSpouseLabel;
                    break;
                case ContactRelationship::Partner:
                    label = kABPersonPartnerLabel;
                    break;
                case ContactRelationship::Sibling:
                    label = kABPersonSiblingLabel;
                    break;
                case ContactRelationship::Parent:
                    label = kABPersonParentLabel;
                    break;
                case ContactRelationship::Child:
                    label = kABPersonChildLabel;
                    break;
                case ContactRelationship::Other:
                default:
                    label = kABOtherLabel;
                    break;
            }

            [relatedNamesMultiValue appendPairWithLabel:(__bridge NSString*)label
                                               andValue:objcwinrt::string(significantOther.Name())];
        };

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
    return (__bridge_retained CFStringRef)objcwinrt::string(person.contact.FullName());
}
