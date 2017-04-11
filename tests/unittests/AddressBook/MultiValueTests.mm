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

#include <TestFramework.h>

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

#import <AddressBook/ABAddressBook.h>
#import <AddressBook/ABRecord.h>
#import <AddressBook/ABPerson.h>
#import <AddressBook/ABMultiValue.h>
#import "NSDate+AddressBookAdditions.h"
#import "ABContactInternal.h"
#import "CppWinRTHelpers.h"

using namespace winrt::Windows::ApplicationModel::Contacts;

class AddressBookMultiValueQueryTest
    : public ::testing::TestWithParam<::testing::tuple<ABPropertyID, CFStringRef, CFIndex, NSString*, CFIndex>> {
protected:
    virtual void SetUp() {
        Contact contact;

        addPhone(contact, ContactPhoneKind::Home, L"0000000000");
        addPhone(contact, ContactPhoneKind::Mobile, L"1111111111");
        addPhone(contact, ContactPhoneKind::Work, L"2222222222");
        addPhone(contact, ContactPhoneKind::Pager, L"3333333333");
        addPhone(contact, ContactPhoneKind::BusinessFax, L"4444444444");
        addPhone(contact, ContactPhoneKind::HomeFax, L"5555555555");
        addPhone(contact, ContactPhoneKind::Company, L"6666666666");
        addPhone(contact, ContactPhoneKind::Assistant, L"7777777777");
        addPhone(contact, ContactPhoneKind::Radio, L"8888888888");
        addPhone(contact, ContactPhoneKind::Other, L"9999999999");

        addEmail(contact, ContactEmailKind::Personal, L"a@ms.com");
        addEmail(contact, ContactEmailKind::Work, L"b@ms.com");
        addEmail(contact, ContactEmailKind::Other, L"c@ms.com");

        addURL(contact, L"bing.com");
        addURL(contact, L"microsoft.com");

        addSO(contact, ContactRelationship::Other, L"Random Name");
        addSO(contact, ContactRelationship::Spouse, L"Wife's Name");
        addSO(contact, ContactRelationship::Partner, L"Buzz");
        addSO(contact, ContactRelationship::Sibling, L"Link");
        addSO(contact, ContactRelationship::Parent, L"Pops");
        addSO(contact, ContactRelationship::Child, L"Sun Ray");

        _record = (__bridge_retained ABRecordRef)[[_ABContact alloc] initWithContact:contact andType:kAddressBookNewContact];
    }

    virtual void TearDown() {
        CFRelease(_record);
    }

    void addPhone(const Contact& contact, ContactPhoneKind kind, const wchar_t* number) {
        ContactPhone phone;
        phone.Number(number);
        phone.Kind(kind);

        contact.Phones().Append(phone);
    }

    void addEmail(const Contact& contact, ContactEmailKind kind, const wchar_t* address) {
        ContactEmail email;
        email.Address(address);
        email.Kind(kind);

        contact.Emails().Append(email);
    }

    void addURL(const Contact& contact, const wchar_t* value) {
        ContactWebsite website;
        website.RawValue(value);

        contact.Websites().Append(website);
    }

    void addSO(const Contact& contact, ContactRelationship kind, const wchar_t* name) {
        ContactSignificantOther person;
        person.Name(name);
        person.Relationship(kind);

        contact.SignificantOthers().Append(person);
    }

    ABRecordRef _record;
};

TEST_P(AddressBookMultiValueQueryTest, MultiValueStringQuery) {
    ABPropertyID property = ::testing::get<0>(GetParam());
    CFStringRef label = ::testing::get<1>(GetParam());
    CFIndex index = ::testing::get<2>(GetParam());
    NSString* value = ::testing::get<3>(GetParam());
    CFIndex count = ::testing::get<4>(GetParam());
    ABMultiValueRef multiValue = (ABMultiValueRef)ABRecordCopyValue(_record, property);
    CFStringRef actualValue = (CFStringRef)ABMultiValueCopyValueAtIndex(multiValue, index);
    CFStringRef actualLabel = ABMultiValueCopyLabelAtIndex(multiValue, index);
    CFIndex actualCount = ABMultiValueGetCount(multiValue);
    ABPropertyType propertyType = ABMultiValueGetPropertyType(multiValue);

    EXPECT_OBJCEQ_MSG((__bridge NSString*)actualValue, value, "FAILED: Incorrect value at specified index!\n");
    EXPECT_OBJCEQ_MSG((__bridge NSString*)actualLabel, (__bridge NSString*)label, "FAILED: Incorrect label at specified index!\n");
    EXPECT_EQ_MSG(actualCount, count, "FAILED: Incorrect count of MultiValue!\n");
    EXPECT_EQ_MSG(propertyType, kABStringPropertyType, "FAILED: Incorrect property type!\n");

    CFRelease(actualLabel);
    CFRelease(actualValue);
    CFRelease(multiValue);
}

INSTANTIATE_TEST_CASE_P(AddressBook,
                        AddressBookMultiValueQueryTest,
                        ::testing::Values(::testing::make_tuple(kABPersonPhoneProperty, kABHomeLabel, 0, @"0000000000", 10),
                                          ::testing::make_tuple(kABPersonPhoneProperty, kABPersonPhoneMobileLabel, 1, @"1111111111", 10),
                                          ::testing::make_tuple(kABPersonPhoneProperty, kABWorkLabel, 2, @"2222222222", 10),
                                          ::testing::make_tuple(kABPersonPhoneProperty, kABPersonPhonePagerLabel, 3, @"3333333333", 10),
                                          ::testing::make_tuple(kABPersonPhoneProperty, kABPersonPhoneWorkFAXLabel, 4, @"4444444444", 10),
                                          ::testing::make_tuple(kABPersonPhoneProperty, kABPersonPhoneHomeFAXLabel, 5, @"5555555555", 10),
                                          ::testing::make_tuple(kABPersonPhoneProperty, kABPersonPhoneCompanyLabel, 6, @"6666666666", 10),
                                          ::testing::make_tuple(kABPersonPhoneProperty, kABPersonPhoneAssistantLabel, 7, @"7777777777", 10),
                                          ::testing::make_tuple(kABPersonPhoneProperty, kABPersonPhoneRadioLabel, 8, @"8888888888", 10),
                                          ::testing::make_tuple(kABPersonPhoneProperty, kABOtherLabel, 9, @"9999999999", 10),
                                          ::testing::make_tuple(kABPersonEmailProperty, kABHomeLabel, 0, @"a@ms.com", 3),
                                          ::testing::make_tuple(kABPersonEmailProperty, kABWorkLabel, 1, @"b@ms.com", 3),
                                          ::testing::make_tuple(kABPersonEmailProperty, kABOtherLabel, 2, @"c@ms.com", 3),
                                          ::testing::make_tuple(kABPersonURLProperty, kABPersonHomePageLabel, 0, @"bing.com", 2),
                                          ::testing::make_tuple(kABPersonURLProperty, kABPersonHomePageLabel, 1, @"microsoft.com", 2),
                                          ::testing::make_tuple(kABPersonRelatedNamesProperty, kABOtherLabel, 0, @"Random Name", 6),
                                          ::testing::make_tuple(kABPersonRelatedNamesProperty, kABPersonSpouseLabel, 1, @"Wife's Name", 6),
                                          ::testing::make_tuple(kABPersonRelatedNamesProperty, kABPersonPartnerLabel, 2, @"Buzz", 6),
                                          ::testing::make_tuple(kABPersonRelatedNamesProperty, kABPersonSiblingLabel, 3, @"Link", 6),
                                          ::testing::make_tuple(kABPersonRelatedNamesProperty, kABPersonParentLabel, 4, @"Pops", 6),
                                          ::testing::make_tuple(kABPersonRelatedNamesProperty, kABPersonChildLabel, 5, @"Sun Ray", 6)));

TEST(AddressBook, QueryContactDates) {
    Contact contact;

    ContactDate anniversary;
    anniversary.Year(objcwinrt::optional(1975));
    anniversary.Month(objcwinrt::optional(4u));
    anniversary.Day(objcwinrt::optional(5u));
    anniversary.Kind(ContactDateKind::Anniversary);

    contact.ImportantDates().Append(anniversary);
    NSDate* realAnniversary = [NSDate dateWithContactDate:anniversary];

    ContactDate other;
    other.Year(objcwinrt::optional(1975));
    other.Month(objcwinrt::optional(4u));
    other.Day(objcwinrt::optional(6u));
    other.Kind(ContactDateKind::Other);

    contact.ImportantDates().Append(other);
    NSDate* realOther = [NSDate dateWithContactDate:other];

    ABRecordRef record = (__bridge_retained ABRecordRef)[[_ABContact alloc] initWithContact:contact andType:kAddressBookNewContact];
    ABMultiValueRef multiValue = (ABMultiValueRef)ABRecordCopyValue(record, kABPersonDateProperty);

    CFArrayRef dates = ABMultiValueCopyArrayOfAllValues(multiValue);
    NSArray* dateArray = (__bridge NSArray*)dates;

    ASSERT_TRUE_MSG([[NSCalendar currentCalendar] isDate:(__bridge NSDate*)dateArray[0] inSameDayAsDate:realAnniversary],
                    "FAILED: Anniversary dates should be on the same day!\n");
    ASSERT_TRUE_MSG([[NSCalendar currentCalendar] isDate:(__bridge NSDate*)dateArray[1] inSameDayAsDate:realOther],
                    "FAILED: Other dates should be on the same day!\n");
    ASSERT_NE_MSG(ABMultiValueGetIdentifierAtIndex(multiValue, 0),
                  ABMultiValueGetIdentifierAtIndex(multiValue, 1),
                  "FAILED: Identifier should be unique!\n");

    ABMultiValueIdentifier identifier = ABMultiValueGetIdentifierAtIndex(multiValue, 1);
    CFIndex index = ABMultiValueGetIndexForIdentifier(multiValue, identifier);
    ASSERT_EQ_MSG(1, index, "FAILED: Wrong index given for identifier!\n");
    CFTypeRef value = ABMultiValueCopyValueAtIndex(multiValue, 1);
    ASSERT_EQ_MSG(1, ABMultiValueGetFirstIndexOfValue(multiValue, value), "FAILED: Wrong index given for value!\n");

    CFRelease(value);
    CFRelease(dates);
    CFRelease(multiValue);
    CFRelease(record);
}

TEST(AddressBook, QueryContactAddress) {
    Contact contact;

    ContactAddress address;
    address.Kind(ContactAddressKind::Home);
    address.StreetAddress(L"1234 5th Street");
    address.Region(L"WA");
    address.PostalCode(L"12345");
    address.Locality(L"Redmond");
    address.Country(L"United States of America");

    contact.Addresses().Append(address);

    ABRecordRef record = (__bridge_retained ABRecordRef)[[_ABContact alloc] initWithContact:contact andType:kAddressBookNewContact];
    ABMultiValueRef multiValue = (ABMultiValueRef)ABRecordCopyValue(record, kABPersonAddressProperty);
    CFDictionaryRef dict = (CFDictionaryRef)ABMultiValueCopyValueAtIndex(multiValue, 0);
    NSDictionary* addressInfo = (__bridge NSDictionary*)dict;

    ASSERT_OBJCEQ_MSG(addressInfo[(__bridge NSString*)kABPersonAddressStreetKey], @"1234 5th Street", "FAILED: Street is wrong!\n");
    ASSERT_OBJCEQ_MSG(addressInfo[(__bridge NSString*)kABPersonAddressStateKey], @"WA", "FAILED: State is wrong!\n");
    ASSERT_OBJCEQ_MSG(addressInfo[(__bridge NSString*)kABPersonAddressZIPKey], @"12345", "FAILED: ZIP is wrong!\n");
    ASSERT_OBJCEQ_MSG(addressInfo[(__bridge NSString*)kABPersonAddressCityKey], @"Redmond", "FAILED: City is wrong!\n");
    ASSERT_OBJCEQ_MSG(addressInfo[(__bridge NSString*)kABPersonAddressCountryKey],
                      @"United States of America",
                      "FAILED: Country is wrong!\n");

    CFRelease(dict);
    CFRelease(multiValue);
    CFRelease(record);
}