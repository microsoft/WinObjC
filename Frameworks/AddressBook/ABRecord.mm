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

#import <AddressBook/ABRecord.h>
#import <AddressBook/ABPerson.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

#import "ABContactInternal.h"
#import "ABRecordInternal.h"
#import "ABSourceInternal.h"
#import "ABMultiValueInternal.h"
#import "NSDate+AddressBookAdditions.h"

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
 @Status Stub
 @Notes
*/
bool ABRecordSetValue(ABRecordRef record, ABPropertyID property, CFTypeRef value, CFErrorRef* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes A few properties (alternate birthday, creation/modification dates, person kind,
        phonetic middle name, and instant message/social profile accounts)
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
 @Status Stub
 @Notes
*/
bool ABRecordRemoveValue(ABRecordRef record, ABPropertyID property, CFErrorRef* error) {
    UNIMPLEMENTED();
    return StubReturn();
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
