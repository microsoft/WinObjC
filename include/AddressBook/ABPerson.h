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

#import <AddressBook/AddressBookExport.h>
#import <AddressBook/ABRecord.h>
#import <CoreFoundation/CFString.h>
#import <CoreFoundation/CFData.h>
#import <CoreFoundation/CFError.h>
#import <AddressBook/ABAddressBook.h>
#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFNumber.h>

typedef uint32_t ABPersonSortOrdering;
typedef uint32_t ABPersonCompositeNameFormat;
typedef enum { kABPersonImageFormatThumbnail = 0, kABPersonImageFormatOriginalSize = 2 } ABPersonImageFormat;

ADDRESSBOOK_EXPORT ABRecordRef ABPersonCreate() STUB_METHOD;
ADDRESSBOOK_EXPORT ABRecordRef ABPersonCreateInSource(ABRecordRef source) STUB_METHOD;
ADDRESSBOOK_EXPORT CFComparisonResult ABPersonComparePeopleByName(ABRecordRef person1,
                                                                  ABRecordRef person2,
                                                                  ABPersonSortOrdering ordering) STUB_METHOD;

ADDRESSBOOK_EXPORT ABPropertyType ABPersonGetTypeOfProperty(ABPropertyID property) STUB_METHOD;
ADDRESSBOOK_EXPORT CFStringRef ABPersonCopyLocalizedPropertyName(ABPropertyID property) STUB_METHOD;
ADDRESSBOOK_EXPORT bool ABPersonSetImageData(ABRecordRef person, CFDataRef imageData, CFErrorRef* error) STUB_METHOD;
ADDRESSBOOK_EXPORT CFDataRef ABPersonCopyImageData(ABRecordRef person) STUB_METHOD;
ADDRESSBOOK_EXPORT CFDataRef ABPersonCopyImageDataWithFormat(ABRecordRef person, ABPersonImageFormat format) STUB_METHOD;
ADDRESSBOOK_EXPORT bool ABPersonHasImageData(ABRecordRef person) STUB_METHOD;
ADDRESSBOOK_EXPORT bool ABPersonRemoveImageData(ABRecordRef person, CFErrorRef* error) STUB_METHOD;
ADDRESSBOOK_EXPORT CFIndex ABAddressBookGetPersonCount(ABAddressBookRef addressBook);
ADDRESSBOOK_EXPORT ABRecordRef ABAddressBookGetPersonWithRecordID(ABAddressBookRef addressBook, ABRecordID recordID);
ADDRESSBOOK_EXPORT CFArrayRef ABAddressBookCopyArrayOfAllPeople(ABAddressBookRef addressBook);
ADDRESSBOOK_EXPORT CFArrayRef ABAddressBookCopyArrayOfAllPeopleInSource(ABAddressBookRef addressBook, ABRecordRef source) STUB_METHOD;
ADDRESSBOOK_EXPORT CFArrayRef ABAddressBookCopyArrayOfAllPeopleInSourceWithSortOrdering(ABAddressBookRef addressBook,
                                                                                        ABRecordRef source,
                                                                                        ABPersonSortOrdering sortOrdering) STUB_METHOD;

ADDRESSBOOK_EXPORT CFArrayRef ABAddressBookCopyPeopleWithName(ABAddressBookRef addressBook, CFStringRef name) STUB_METHOD;
ADDRESSBOOK_EXPORT CFArrayRef ABPersonCopyArrayOfAllLinkedPeople(ABRecordRef person) STUB_METHOD;
ADDRESSBOOK_EXPORT ABRecordRef ABPersonCopySource(ABRecordRef person) STUB_METHOD;
ADDRESSBOOK_EXPORT CFStringRef ABPersonCopyCompositeNameDelimiterForRecord(ABRecordRef record) STUB_METHOD;
ADDRESSBOOK_EXPORT ABPersonSortOrdering ABPersonGetSortOrdering() STUB_METHOD;
ADDRESSBOOK_EXPORT ABPersonCompositeNameFormat ABPersonGetCompositeNameFormat() STUB_METHOD;
ADDRESSBOOK_EXPORT ABPersonCompositeNameFormat ABPersonGetCompositeNameFormatForRecord(ABRecordRef record) STUB_METHOD;
ADDRESSBOOK_EXPORT CFArrayRef ABPersonCreatePeopleInSourceWithVCardRepresentation(ABRecordRef source, CFDataRef vCardData) STUB_METHOD;
ADDRESSBOOK_EXPORT CFDataRef ABPersonCreateVCardRepresentationWithPeople(CFArrayRef people) STUB_METHOD;

enum { kABPersonSortByFirstName = 0, kABPersonSortByLastName = 1 };
enum { kABPersonCompositeNameFormatFirstNameFirst = 0, kABPersonCompositeNameFormatLastNameFirst = 1 };

ADDRESSBOOK_EXPORT const ABPropertyID kABPersonFirstNameProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonLastNameProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonMiddleNameProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonPrefixProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonSuffixProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonNicknameProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonFirstNamePhoneticProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonLastNamePhoneticProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonMiddleNamePhoneticProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonOrganizationProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonJobTitleProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonDepartmentProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonEmailProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonBirthdayProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonNoteProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonCreationDateProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonModificationDateProperty;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonAddressProperty;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAddressStreetKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAddressCityKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAddressStateKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAddressZIPKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAddressCountryKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAddressCountryCodeKey;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonDateProperty;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAnniversaryLabel;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonKindProperty;
ADDRESSBOOK_EXPORT const CFNumberRef kABPersonKindPerson;
ADDRESSBOOK_EXPORT const CFNumberRef kABPersonKindOrganization;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonPhoneProperty;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPhoneMobileLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPhoneIPhoneLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPhoneMainLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPhoneHomeFAXLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPhoneWorkFAXLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPhoneOtherFAXLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPhonePagerLabel;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonInstantMessageProperty;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageUsernameKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceYahoo;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceJabber;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceMSN;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceICQ;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceAIM;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceQQ;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceGoogleTalk;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceSkype;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceFacebook;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonInstantMessageServiceGaduGadu;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonSocialProfileProperty;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileURLKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileServiceKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileUsernameKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileUserIdentifierKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileServiceTwitter;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileServiceSinaWeibo;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileServiceGameCenter;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileServiceFacebook;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileServiceMyspace;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileServiceLinkedIn;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSocialProfileServiceFlickr;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonURLProperty;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonHomePageLabel;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonRelatedNamesProperty;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonMotherLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonFatherLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonParentLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSisterLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonBrotherLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonChildLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonFriendLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSpouseLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPartnerLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonManagerLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAssistantLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABWorkLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABHomeLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABOtherLabel;
ADDRESSBOOK_EXPORT const ABPropertyID kABPersonAlternateBirthdayProperty;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAlternateBirthdayCalendarIdentifierKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAlternateBirthdayEraKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAlternateBirthdayYearKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAlternateBirthdayMonthKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAlternateBirthdayIsLeapMonthKey;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonAlternateBirthdayDayKey;
// CFNumberRef - kCFNumberNSIntegerType
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPhoneCompanyLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPhoneAssistantLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonPhoneRadioLabel;
ADDRESSBOOK_EXPORT const CFStringRef kABPersonSiblingLabel;