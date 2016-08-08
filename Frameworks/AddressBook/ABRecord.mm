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
            NSString* idAsString = [[fullId substringToIndex:(fullId.length - 1)] componentsSeparatedByString:@"."][2];
            return [idAsString integerValue];
        }
        case kABSourceType: {
            _ABSource* source = (__bridge _ABSource*)record;
            return source.recordID;
        }
        case kABGroupType:
            // Windows contacts doesn't support Group records, so return an invalid id.
            return kABRecordInvalidID;
    }

    return kABRecordInvalidID;
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
    } else {
        return kABGroupType;
    }
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
CFTypeRef ABRecordCopyValue(ABRecordRef record, ABPropertyID property) {
    if (record == nullptr) {
        return nullptr;
    }

    _ABContact* person = (__bridge _ABContact*)record;

    if (property == kABPersonFirstNameProperty) {
        return (__bridge_retained CFTypeRef)person.contact.firstName;
    } else if (property == kABPersonLastNameProperty) {
        return (__bridge_retained CFTypeRef)person.contact.lastName;
    } else if (property == kABPersonMiddleNameProperty) {
        return (__bridge_retained CFTypeRef)person.contact.middleName;
    } else if (property == kABPersonPrefixProperty) {
        return (__bridge_retained CFTypeRef)person.contact.honorificNamePrefix;
    } else if (property == kABPersonSuffixProperty) {
        return (__bridge_retained CFTypeRef)person.contact.honorificNameSuffix;
    } else if (property == kABPersonNicknameProperty) {
        return (__bridge_retained CFTypeRef)person.contact.nickname;
    } else if (property == kABPersonFirstNamePhoneticProperty) {
        return (__bridge_retained CFTypeRef)person.contact.yomiGivenName;
    } else if (property == kABPersonLastNamePhoneticProperty) {
        return (__bridge_retained CFTypeRef)person.contact.yomiFamilyName;
    } else if (property == kABPersonOrganizationProperty) {
        NSArray* jobInfo = person.contact.jobInfo;
        if ([jobInfo count] > 0) {
            return (__bridge_retained CFTypeRef)((WACContactJobInfo*)jobInfo[0]).companyName;
        } else {
            return nullptr;
        }
    } else if (property == kABPersonJobTitleProperty) {
        NSArray* jobInfo = person.contact.jobInfo;
        if ([jobInfo count] > 0) {
            return (__bridge_retained CFTypeRef)((WACContactJobInfo*)jobInfo[0]).title;
        } else {
            return nullptr;
        }
    } else if (property == kABPersonDepartmentProperty) {
        NSArray* jobInfo = person.contact.jobInfo;
        if ([jobInfo count] > 0) {
            return (__bridge_retained CFTypeRef)((WACContactJobInfo*)jobInfo[0]).department;
        } else {
            return nullptr;
        }
    } else if (property == kABPersonBirthdayProperty) {
        NSArray* dates = person.contact.importantDates;
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
            dateComponents.day = [date.day integerValue];
            dateComponents.month = [date.month integerValue];
            dateComponents.year = [date.year integerValue];
            NSDate* resultDate = [calendar dateFromComponents:dateComponents];
            return (__bridge_retained CFTypeRef)resultDate;
        }
    } else if (property == kABPersonNoteProperty) {
        return (__bridge_retained CFTypeRef)person.contact.notes;

        // The following properties either require the implementation of
        // multi-values, or don't have a good 1-1 mapping between iOS contacts
        // and Windows contacts (alternate birthday, creation/modification dates,
        // phonetic middle name).
    } else if (property == kABPersonMiddleNamePhoneticProperty) {
        // CFStringRef
    } else if (property == kABPersonKindProperty) {
        // CFNumberRef
    } else if (property == kABPersonAlternateBirthdayProperty) {
        // CFDictionaryRef
    } else if (property == kABPersonCreationDateProperty) {
        // CFDateRef
    } else if (property == kABPersonModificationDateProperty) {
        // CFDateRef
    } else if (property == kABPersonEmailProperty) {
        // ABMultiValueRef of CFStringRef
    } else if (property == kABPersonAddressProperty) {
        // ABMultiValueRef of CFDictionaryRef
    } else if (property == kABPersonDateProperty) {
        // ABMultiValueRef of CFDateRef
    } else if (property == kABPersonPhoneProperty) {
        // ABMultiValueRef of CFStringRef
    } else if (property == kABPersonInstantMessageProperty) {
        // ABMultiValueRef of CFDictionaryRef
    } else if (property == kABPersonSocialProfileProperty) {
        // ABMultiValueRef of CFDictionaryRef
    } else if (property == kABPersonURLProperty) {
        // ABMultiValueRef of CFStringRef
    } else if (property == kABPersonRelatedNamesProperty) {
        // ABMultiValueRef of CFStringRef
    } else {
        return nullptr;
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
 @Notes
*/
CFStringRef ABRecordCopyCompositeName(ABRecordRef record) {
    // Behavior on the reference platform is undefined for Source records,
    // and Windows Contacts doesn't support Group records, so we can assume
    // it is a Person record.
    _ABContact* person = (__bridge _ABContact*)record;
    return (__bridge_retained CFStringRef)person.contact.fullName;
}
