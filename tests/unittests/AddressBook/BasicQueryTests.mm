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

#import "UWP/WindowsApplicationModelContacts.h"
#import <AddressBook/ABAddressBook.h>
#import <AddressBook/ABRecord.h>
#import <AddressBook/ABPerson.h>
#import "ABContactInternal.h"

class AddressBookQueryTest : public ::testing::TestWithParam<::testing::tuple<ABPropertyID, NSString*>> {
protected:
    virtual void SetUp() {
        WACContact* contact = [WACContact make];
        contact.notes = @"Test Note!";
        contact.nickname = @"Mikey";
        contact.yomiGivenName = @"Mic";
        contact.honorificNameSuffix = @"Jr.";
        contact.yomiFamilyName = @"Saw-ft";
        contact.middleName = @"Roe";
        contact.lastName = @"Soft";
        contact.honorificNamePrefix = @"Mr.";
        contact.firstName = @"Mike";

        WACContactJobInfo* job = [WACContactJobInfo make];
        job.title = @"SDE";
        job.office = @"Redmond";
        job.manager = @"Satya";
        job.Description = @"I develop good code.";
        job.department = @"WDG";
        job.companyYomiName = @"Mike Roe Soft";
        job.companyName = @"Microsoft";
        job.companyAddress = @"Redmond, WA";

        [contact.jobInfo addObject:job];
        [job release];
        _record = (__bridge_retained ABRecordRef)[[_ABContact alloc] initWithContact:contact andType:kAddressBookNewContact];
        [contact release];
    }

    virtual void TearDown() {
        CFRelease(_record);
    }

    ABRecordRef _record;
};

TEST_P(AddressBookQueryTest, BasicContactQuery) {
    ABPropertyID property = ::testing::get<0>(GetParam());
    CFStringRef recordValue = (CFStringRef)ABRecordCopyValue(_record, property);
    ASSERT_OBJCEQ_MSG(::testing::get<1>(GetParam()), (__bridge NSString*)recordValue, "FAILED: Incorrect property copied!\n");
    CFRelease(recordValue);
}

INSTANTIATE_TEST_CASE_P(AddressBook,
                        AddressBookQueryTest,
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
                                          ::testing::make_tuple(kABPersonOrganizationProperty, @"Microsoft"),
                                          ::testing::make_tuple(-1, nil)));

TEST(AddressBook, QueryContactBirthday) {
    WACContact* contact = [WACContact make];
    WACContactDate* birthday = [WACContactDate make];
    birthday.year = @1975;
    birthday.month = @4;
    birthday.day = @4;
    birthday.kind = WACContactDateKindBirthday;

    [contact.importantDates addObject:birthday];
    ABRecordRef record = (__bridge_retained ABRecordRef)[[_ABContact alloc] initWithContact:contact andType:kAddressBookNewContact];

    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* dateComponents = [[NSDateComponents alloc] init];
    dateComponents.day = 4;
    dateComponents.month = 4;
    dateComponents.year = 1975;
    NSDate* date = [calendar dateFromComponents:dateComponents];
    CFDateRef contactBirthday = (CFDateRef)ABRecordCopyValue(record, kABPersonBirthdayProperty);
    ASSERT_TRUE_MSG([[NSCalendar currentCalendar] isDate:(__bridge NSDate*)contactBirthday inSameDayAsDate:date],
                    "FAILED: Dates should be on the same day!\n");
    CFRelease(record);
    CFRelease(contactBirthday);
    [dateComponents release];
    [contact release];
    [birthday release];
}

TEST(AddressBook, GetRecordTypeAndID) {
    ASSERT_EQ_MSG(kABRecordInvalidID, ABRecordGetRecordID(nullptr), "FAILED: null record should have an invalid ID!\n");
    ABRecordRef record =
        (__bridge_retained ABRecordRef)[[_ABContact alloc] initWithContact:[WACContact make] andType:kAddressBookNewContact];
    ASSERT_EQ_MSG(kABPersonType, ABRecordGetRecordType(record), "FAILED: Person record should have a person type!\n");
    CFRelease(record);
}