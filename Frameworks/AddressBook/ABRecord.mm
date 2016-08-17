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
 @Notes Properties that return a Multi-Value are not yet supported, and a few properties
        (alternate birthday, creation/modification dates, person kind, phonetic middle name)
        don't have direct equivalents.
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
            NSCalendar* calendar = [NSCalendar currentCalendar];
            NSDateComponents* dateComponents = [[NSDateComponents alloc] init];

            // Grab the numerical values of the day/month/year,
            // and create an NSDate to match the same day as their birthday.
            // NSDate is toll-free bridged with CFDate, which is the type
            // the user expects to receive.
            dateComponents.day = [date.day integerValue];
            dateComponents.month = [date.month integerValue];
            dateComponents.year = [date.year integerValue];
            NSDate* resultDate = [calendar dateFromComponents:dateComponents];
            return (__bridge_retained CFTypeRef)resultDate;
        }
    }

    // Case for note-related property.
    if (contactProperty == kABPersonNoteProperty) {
        return (__bridge_retained CFTypeRef)person.contact.notes;
    }

    // The following properties either require the implementation of
    // multi-values, or don't have a good 1-1 mapping between iOS contacts
    // and Windows contacts (alternate birthday, creation/modification dates,
    // phonetic middle name).

    if (contactProperty == kABPersonMiddleNamePhoneticProperty) {
        // CFStringRef
    } else if (contactProperty == kABPersonKindProperty) {
        // CFNumberRef
    } else if (contactProperty == kABPersonAlternateBirthdayProperty) {
        // CFDictionaryRef
    } else if (contactProperty == kABPersonCreationDateProperty) {
        // CFDateRef
    } else if (contactProperty == kABPersonModificationDateProperty) {
        // CFDateRef
    }

    // TODO #678
    // Cases for various multi-value properties.
    if (contactProperty == kABPersonEmailProperty) {
        // ABMultiValueRef of CFStringRef
    } else if (contactProperty == kABPersonAddressProperty) {
        // ABMultiValueRef of CFDictionaryRef
    } else if (contactProperty == kABPersonDateProperty) {
        // ABMultiValueRef of CFDateRef
    } else if (contactProperty == kABPersonPhoneProperty) {
        // ABMultiValueRef of CFStringRef
    } else if (contactProperty == kABPersonInstantMessageProperty) {
        // ABMultiValueRef of CFDictionaryRef
    } else if (contactProperty == kABPersonSocialProfileProperty) {
        // ABMultiValueRef of CFDictionaryRef
    } else if (contactProperty == kABPersonURLProperty) {
        // ABMultiValueRef of CFStringRef
    } else if (contactProperty == kABPersonRelatedNamesProperty) {
        // ABMultiValueRef of CFStringRef
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
