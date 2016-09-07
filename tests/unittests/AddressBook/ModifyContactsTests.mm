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

#include <TestFramework.h>

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

#import "UWP/WindowsApplicationModelContacts.h"
#import <AddressBook/ABAddressBook.h>
#import <AddressBook/ABRecord.h>
#import <AddressBook/ABPerson.h>
#import <AddressBook/ABMultiValue.h>
#import <AddressBook/ABMutableMultiValue.h>
#import "ABContactInternal.h"

class AddressBookModifyTest : public ::testing::TestWithParam<::testing::tuple<ABPropertyID, NSString*>> {
protected:
    virtual void SetUp() {
        _record = ABPersonCreate();
    }

    virtual void TearDown() {
        CFRelease(_record);
    }

    ABRecordRef _record;
};

TEST_P(AddressBookModifyTest, StringFields) {
    ABPropertyID property = ::testing::get<0>(GetParam());
    NSString* value = ::testing::get<1>(GetParam());
    ASSERT_TRUE_MSG(ABRecordSetValue(_record, property, (__bridge CFTypeRef)value, NULL), "FAILED: Unable to set property!\n");
    CFStringRef recordValue = (CFStringRef)ABRecordCopyValue(_record, property);
    ASSERT_OBJCEQ(value, (__bridge NSString*)recordValue);
    CFRelease(recordValue);
}

INSTANTIATE_TEST_CASE_P(AddressBook,
                        AddressBookModifyTest,
                        ::testing::Values(::testing::make_tuple(kABPersonNoteProperty, @"Test Note!"),
                                          ::testing::make_tuple(kABPersonNicknameProperty, @"Mikey"),
                                          ::testing::make_tuple(kABPersonFirstNamePhoneticProperty, @"Mic"),
                                          ::testing::make_tuple(kABPersonSuffixProperty, @"Jr."),
                                          ::testing::make_tuple(kABPersonLastNamePhoneticProperty, @"Saw-ft"),
                                          ::testing::make_tuple(kABPersonMiddleNameProperty, @"Roe"),
                                          ::testing::make_tuple(kABPersonLastNameProperty, @"Soft"),
                                          ::testing::make_tuple(kABPersonPrefixProperty, @"Mr."),
                                          ::testing::make_tuple(kABPersonFirstNameProperty, @"Mike"),
                                          ::testing::make_tuple(kABPersonJobTitleProperty, @"SDE"),
                                          ::testing::make_tuple(kABPersonDepartmentProperty, @"WDG"),
                                          ::testing::make_tuple(kABPersonOrganizationProperty, @"Microsoft")));

TEST(AddressBookModify, ContactBirthday) {
    ABRecordRef person = ABPersonCreate();

    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* dateComponents = [[NSDateComponents alloc] init];
    dateComponents.day = 4;
    dateComponents.month = 4;
    dateComponents.year = 1975;
    NSDate* date = [calendar dateFromComponents:dateComponents];

    ASSERT_TRUE_MSG(ABRecordSetValue(person, kABPersonBirthdayProperty, (__bridge CFTypeRef)date, NULL),
                    "FAILED: Unable to set property!\n");
    CFDateRef contactBirthday = (CFDateRef)ABRecordCopyValue(person, kABPersonBirthdayProperty);
    ASSERT_TRUE_MSG([[NSCalendar currentCalendar] isDate:(__bridge NSDate*)contactBirthday inSameDayAsDate:date],
                    "FAILED: Dates should be on the same day!\n");
    CFRelease(person);
    CFRelease(contactBirthday);
    [dateComponents release];
}

class AddressBookMultiValueModifyTest : public ::testing::TestWithParam<::testing::tuple<ABPropertyID, NSArray*, NSArray*>> {
protected:
    virtual void SetUp() {
        _record = ABPersonCreate();
    }

    virtual void TearDown() {
        CFRelease(_record);
    }

    ABRecordRef _record;
};

TEST_P(AddressBookMultiValueModifyTest, MultiValueFields) {
    ABMutableMultiValueRef multiValue = ABMultiValueCreateMutable(kABStringPropertyType);
    ABPropertyID property = ::testing::get<0>(GetParam());
    NSArray* labels = ::testing::get<1>(GetParam());
    NSArray* values = ::testing::get<2>(GetParam());
    for (int i = 0; i < [labels count]; i++) {
        ASSERT_TRUE(ABMultiValueAddValueAndLabel(multiValue, (__bridge CFStringRef)values[i], (__bridge CFStringRef)labels[i], NULL));
    }

    CFErrorRef error = NULL;
    ASSERT_TRUE(ABRecordSetValue(_record, property, multiValue, &error));
    ASSERT_TRUE(error == nullptr);
    ABMultiValueRef result = ABRecordCopyValue(_record, property);

    for (int i = 0; i < [labels count]; i++) {
        NSString* expectedLabel = (__bridge NSString*)ABMultiValueCopyLabelAtIndex(multiValue, i);
        NSString* actualLabel = (__bridge NSString*)ABMultiValueCopyLabelAtIndex(result, i);
        NSString* expectedValue = (__bridge NSString*)ABMultiValueCopyValueAtIndex(multiValue, i);
        NSString* actualValue = (__bridge NSString*)ABMultiValueCopyValueAtIndex(result, i);
        EXPECT_OBJCEQ(expectedValue, actualValue);
        EXPECT_OBJCEQ(expectedLabel, actualLabel);
        [expectedLabel release];
        [actualLabel release];
        [expectedValue release];
        [actualValue release];
    }

    CFRelease(multiValue);
    CFRelease(result);
}

INSTANTIATE_TEST_CASE_P(
    AddressBook,
    AddressBookMultiValueModifyTest,
    ::testing::Values(
        ::testing::make_tuple(kABPersonPhoneProperty,
                              [NSArray arrayWithObjects:
                                 (__bridge NSString*)kABHomeLabel,
                                 (__bridge NSString*)kABPersonPhoneMobileLabel,
                                 (__bridge NSString*)kABWorkLabel,
                                 (__bridge NSString*)kABPersonPhonePagerLabel,
                                 (__bridge NSString*)kABPersonPhoneWorkFAXLabel,
                                 (__bridge NSString*)kABPersonPhoneHomeFAXLabel,
                                 (__bridge NSString*)kABPersonPhoneCompanyLabel,
                                 (__bridge NSString*)kABPersonPhoneAssistantLabel,
                                 (__bridge NSString*)kABPersonPhoneRadioLabel,
                                 (__bridge NSString*)kABOtherLabel,
                                 nil
                              ],
                              [NSArray arrayWithObjects:
                                 @"0000000000",
                                 @"1111111111",
                                 @"2222222222",
                                 @"3333333333",
                                 @"4444444444",
                                 @"5555555555",
                                 @"6666666666",
                                 @"7777777777",
                                 @"8888888888",
                                 @"9999999999",
                                 nil
                              ]),
        ::testing::make_tuple(kABPersonURLProperty,
                              [NSArray arrayWithObjects:(__bridge NSString*)kABPersonHomePageLabel, (__bridge NSString*)kABPersonHomePageLabel, nil],
                              [NSArray arrayWithObjects:@"bing.com", @"microsoft.com", nil]),
        ::testing::make_tuple(kABPersonEmailProperty,
                              [NSArray arrayWithObjects:(__bridge NSString*)kABHomeLabel, (__bridge NSString*)kABWorkLabel, (__bridge NSString*)kABOtherLabel, nil],
                              [NSArray arrayWithObjects:@"a@ms.com", @"b@ms.com", @"c@ms.com", nil]),
        ::testing::make_tuple(kABPersonRelatedNamesProperty,
                              [NSArray arrayWithObjects:
                                 (__bridge NSString*)kABOtherLabel,
                                 (__bridge NSString*)kABPersonSpouseLabel,
                                 (__bridge NSString*)kABPersonPartnerLabel,
                                 (__bridge NSString*)kABPersonSiblingLabel,
                                 (__bridge NSString*)kABPersonParentLabel,
                                 (__bridge NSString*)kABPersonChildLabel,
                                 nil
                              ],
                              [NSArray arrayWithObjects:@"Random Name", @"Wife's Name", @"Buzz", @"Link", @"Pops", @"Sun Ray", nil])

            ));

TEST(AddressBookModify, DateMultiValues) {
    ABRecordRef person = ABPersonCreate();

    ABMutableMultiValueRef multiValue = ABMultiValueCreateMutable(kABDateTimePropertyType);

    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* dateComponents1 = [[NSDateComponents alloc] init];
    dateComponents1.day = 4;
    dateComponents1.month = 5;
    dateComponents1.year = 1975;
    NSDate* date1 = [calendar dateFromComponents:dateComponents1];
    NSDateComponents* dateComponents2 = [[NSDateComponents alloc] init];
    dateComponents2.day = 4;
    dateComponents2.month = 6;
    dateComponents2.year = 1935;
    NSDate* date2 = [calendar dateFromComponents:dateComponents2];
    [dateComponents1 release];
    [dateComponents2 release];

    ABMultiValueAddValueAndLabel(multiValue, (__bridge CFDateRef)date1, (__bridge CFStringRef) @"hi", NULL);
    ABMultiValueAddValueAndLabel(multiValue, (__bridge CFDateRef)date2, (__bridge CFStringRef) @"yo", NULL);

    ASSERT_TRUE(ABRecordSetValue(person, kABPersonDateProperty, multiValue, NULL));
    ABMultiValueRef result = ABRecordCopyValue(person, kABPersonDateProperty);

    CFDateRef d1 = (CFDateRef)ABMultiValueCopyValueAtIndex(result, 0);
    CFDateRef d2 = (CFDateRef)ABMultiValueCopyValueAtIndex(result, 1);

    ASSERT_TRUE_MSG([[NSCalendar currentCalendar] isDate:(__bridge NSDate*)date1 inSameDayAsDate:(__bridge NSDate*)d1],
                    "FAILED: Dates should be on the same day!\n");
    ASSERT_TRUE_MSG([[NSCalendar currentCalendar] isDate:(__bridge NSDate*)date2 inSameDayAsDate:(__bridge NSDate*)d2],
                    "FAILED: Dates should be on the same day!\n");

    CFRelease(d1);
    CFRelease(d2);
    CFRelease(multiValue);
    CFRelease(result);
    CFRelease(person);
}

TEST(AddressBookModify, AddressMultiValues) {
    ABRecordRef person = ABPersonCreate();
    NSDictionary* addr = @{

        (__bridge NSString*) kABPersonAddressStreetKey : @"1234 5th Street", (__bridge NSString*)
        kABPersonAddressStateKey : @"WA", (__bridge NSString*)
        kABPersonAddressZIPKey : @"12345", (__bridge NSString*)
        kABPersonAddressCityKey : @"Redmond", (__bridge NSString*)
        kABPersonAddressCountryKey : @"United States of America"

    };

    ABMutableMultiValueRef multiValue = ABMultiValueCreateMutable(kABDictionaryPropertyType);
    ABMultiValueAddValueAndLabel(multiValue, (__bridge CFTypeRef)addr, (__bridge CFStringRef) @"hello", NULL);
    ASSERT_TRUE(ABRecordSetValue(person, kABPersonAddressProperty, multiValue, NULL));
    ABMultiValueRef result = ABRecordCopyValue(person, kABPersonAddressProperty);
    NSDictionary* other = (__bridge NSDictionary*)ABMultiValueCopyValueAtIndex(result, 0);

    ASSERT_OBJCEQ(addr, other);

    [other release];
    CFRelease(result);
    CFRelease(multiValue);
    CFRelease(person);
}

TEST(AddressBookModify, ModifyError) {
    ABRecordRef person = ABPersonCreate();
    CFErrorRef error = NULL;

    // Test case where invalid property id is given.
    ASSERT_FALSE(ABRecordSetValue(person, -1, @"hello", &error));
    ASSERT_FALSE(error == NULL);
    CFRelease(error);

    // Test case where length of String is longer than the allowed length.
    error = NULL;
    ASSERT_FALSE(ABRecordSetValue(person,
                                  kABPersonFirstNameProperty,
                                  @"this is a name that is much longer than the allowed length for a first name!",
                                  &error));
    ASSERT_FALSE(error == NULL);
    CFRelease(error);
    CFRelease(person);
}