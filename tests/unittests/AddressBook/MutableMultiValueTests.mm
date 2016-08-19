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
#import <AddressBook/ABMultiValue.h>
#import <AddressBook/ABMutableMultiValue.h>
#import "ABContactInternal.h"

void addPhone(WACContact* contact, WACContactPhoneKind kind, NSString* number) {
    WACContactPhone* phone = [WACContactPhone make];
    phone.number = number;
    phone.kind = kind;

    [contact.phones addObject:phone];
    [phone release];
}

ABMultiValueRef createMultiValue() {
    WACContact* contact = [WACContact make];
    addPhone(contact, WACContactPhoneKindHome, @"0000000000");
    addPhone(contact, WACContactPhoneKindMobile, @"1111111111");
    ABRecordRef record = (__bridge_retained ABRecordRef)[[_ABContact alloc] initWithContact:contact];
    [contact release];
    ABMultiValueRef multiValue = (ABMultiValueRef)ABRecordCopyValue(record, kABPersonPhoneProperty);
    CFRelease(record);
    return multiValue;
}

TEST(AddressBook, MutableMultiValueCreateTest) {
    ABMultiValueRef multiValue = createMultiValue();
    ABMutableMultiValueRef mutableMultiValue = ABMultiValueCreateMutableCopy(multiValue);
    ASSERT_EQ_MSG(ABMultiValueGetCount(multiValue),
                  ABMultiValueGetCount(mutableMultiValue),
                  "FAILED: The mutable multi value should have the same count!\n");
    for (int i = 0; i < ABMultiValueGetCount(mutableMultiValue); i++) {
        CFStringRef value = (CFStringRef)ABMultiValueCopyValueAtIndex(multiValue, i);
        CFStringRef valueCopy = (CFStringRef)ABMultiValueCopyValueAtIndex(mutableMultiValue, i);
        ASSERT_OBJCEQ_MSG((__bridge NSString*)value, (__bridge NSString*)valueCopy, "FAILED: Values should be the same!\n");
        CFRelease(value);
        CFRelease(valueCopy);

        CFStringRef label = ABMultiValueCopyLabelAtIndex(multiValue, i);
        CFStringRef labelCopy = ABMultiValueCopyLabelAtIndex(mutableMultiValue, i);
        ASSERT_OBJCEQ_MSG((__bridge NSString*)label, (__bridge NSString*)labelCopy, "FAILED: Labels should be the same!\n");
        CFRelease(label);
        CFRelease(labelCopy);
    }
    CFRelease(mutableMultiValue);
    CFRelease(multiValue);
}

TEST(AddressBook, MutableMultiValueAddAndReplaceTest) {
    // Tests for adding label/value pairs.
    ABMutableMultiValueRef multiValue = ABMultiValueCreateMutable(kABStringPropertyType);
    ASSERT_EQ_MSG(0, ABMultiValueGetCount(multiValue), "FAILED: Count of multivalue should be 0!\n");
    ABMultiValueIdentifier identifier1 = -1;
    ABMultiValueIdentifier identifier2 = -1;
    ASSERT_TRUE_MSG(ABMultiValueAddValueAndLabel(multiValue, @"0000000000", kABHomeLabel, &identifier1),
                    "FAILED: Error adding first value/label pair!\n");
    ASSERT_EQ_MSG(1, ABMultiValueGetCount(multiValue), "FAILED: Count of multivalue should be 1!\n");

    ASSERT_TRUE_MSG(ABMultiValueAddValueAndLabel(multiValue, @"1111111111", kABPersonPhoneMobileLabel, &identifier2),
                    "FAILED: Error adding second value/label pair!\n");
    ASSERT_EQ_MSG(2, ABMultiValueGetCount(multiValue), "FAILED: Count of multivalue should be 2!\n");

    ASSERT_NE_MSG(identifier1, identifier2, "FAILED: Identifiers should be unique!\n");

    CFStringRef value1 = (CFStringRef)ABMultiValueCopyValueAtIndex(multiValue, 0);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)value1, @"0000000000", "FAILED: Values should be the same!\n");
    CFRelease(value1);

    CFStringRef label1 = ABMultiValueCopyLabelAtIndex(multiValue, 0);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)label1, (__bridge NSString*)kABHomeLabel, "FAILED: Labels should be the same!\n");
    CFRelease(label1);

    CFStringRef value2 = (CFStringRef)ABMultiValueCopyValueAtIndex(multiValue, 1);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)value2, @"1111111111", "FAILED: Values should be the same!\n");
    CFRelease(value2);

    CFStringRef label2 = ABMultiValueCopyLabelAtIndex(multiValue, 1);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)label2, (__bridge NSString*)kABPersonPhoneMobileLabel, "FAILED: Labels should be the same!\n");
    CFRelease(label2);

    // Tests for replacing values.
    ASSERT_TRUE_MSG(ABMultiValueReplaceValueAtIndex(multiValue, @"2222222222", 0), "FAILED: Error replacing value!\n");
    CFStringRef value = (CFStringRef)ABMultiValueCopyValueAtIndex(multiValue, 0);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)value, @"2222222222", "FAILED: Replaced value didn't match!\n");
    CFRelease(value);

    // Tests for replacing labels.
    ASSERT_TRUE_MSG(ABMultiValueReplaceLabelAtIndex(multiValue, (__bridge CFStringRef) @"fake label", 1),
                    "FAILED: Error replacing label!\n");
    CFStringRef label = ABMultiValueCopyLabelAtIndex(multiValue, 1);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)label, @"fake label", "FAILED: Replaced label didn't match!\n");
    CFRelease(label);
}

TEST(AddressBook, MutableMultiValueInsertAndRemoveTest) {
    ABMutableMultiValueRef multiValue = ABMultiValueCreateMutable(kABStringPropertyType);
    ASSERT_TRUE_MSG(ABMultiValueAddValueAndLabel(multiValue, @"0000000000", kABHomeLabel, nullptr),
                    "FAILED: Error adding first value/label pair!\n");
    ASSERT_TRUE_MSG(ABMultiValueAddValueAndLabel(multiValue, @"1111111111", kABPersonPhoneMobileLabel, nullptr),
                    "FAILED: Error adding second value/label pair!\n");

    // Test inserting at index.
    ASSERT_TRUE_MSG(ABMultiValueInsertValueAndLabelAtIndex(multiValue, @"2222222222", kABWorkLabel, 1, nullptr),
                    "FAILED: Error inserting at index 1!\n");
    ASSERT_EQ_MSG(3, ABMultiValueGetCount(multiValue), "FAILED: Incorrect count after inserting at index!\n");

    CFStringRef value0 = (CFStringRef)ABMultiValueCopyValueAtIndex(multiValue, 0);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)value0, @"0000000000", "FAILED: Values should be the same!\n");
    CFRelease(value0);

    CFStringRef value1 = (CFStringRef)ABMultiValueCopyValueAtIndex(multiValue, 1);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)value1, @"2222222222", "FAILED: Values should be the same!\n");
    CFRelease(value1);

    CFStringRef value2 = (CFStringRef)ABMultiValueCopyValueAtIndex(multiValue, 2);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)value2, @"1111111111", "FAILED: Values should be the same!\n");
    CFRelease(value2);

    // Test removing at index.
    ASSERT_TRUE_MSG(ABMultiValueRemoveValueAndLabelAtIndex(multiValue, 0), "FAILED: Error removing at index 0!\n");
    ASSERT_EQ_MSG(2, ABMultiValueGetCount(multiValue), "FAILED: Incorrect count after removing at index!\n");

    CFStringRef value0PostDelete = (CFStringRef)ABMultiValueCopyValueAtIndex(multiValue, 0);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)value0PostDelete, @"2222222222", "FAILED: Values should be the same!\n");
    CFRelease(value0PostDelete);

    CFStringRef value1PostDelete = (CFStringRef)ABMultiValueCopyValueAtIndex(multiValue, 1);
    ASSERT_OBJCEQ_MSG((__bridge NSString*)value1PostDelete, @"1111111111", "FAILED: Values should be the same!\n");
    CFRelease(value1PostDelete);
}