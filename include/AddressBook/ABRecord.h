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
#pragma once

#import <AddressBook/AddressBookExport.h>

#import <CoreFoundation/CFError.h>
#import <CoreFoundation/CFString.h>

typedef CFTypeRef ABRecordRef;
typedef int32_t ABRecordID;
typedef int32_t ABPropertyID;
typedef uint32_t ABRecordType;
typedef uint16_t ABPropertyType;

ADDRESSBOOK_EXPORT ABRecordID ABRecordGetRecordID(ABRecordRef record);
ADDRESSBOOK_EXPORT ABRecordType ABRecordGetRecordType(ABRecordRef record);
ADDRESSBOOK_EXPORT bool ABRecordSetValue(ABRecordRef record, ABPropertyID property, CFTypeRef value, CFErrorRef* error);
ADDRESSBOOK_EXPORT CFTypeRef ABRecordCopyValue(ABRecordRef record, ABPropertyID property);
ADDRESSBOOK_EXPORT bool ABRecordRemoveValue(ABRecordRef record, ABPropertyID property, CFErrorRef* error);
ADDRESSBOOK_EXPORT CFStringRef ABRecordCopyCompositeName(ABRecordRef record);

enum { kABPersonType = 0, kABGroupType = 1, kABSourceType = 2 };

#define kABMultiValueMask (1 << 8)
enum {
    kABInvalidPropertyType = 0x0,
    kABStringPropertyType = 0x1,
    kABIntegerPropertyType = 0x2,
    kABRealPropertyType = 0x3,
    kABDateTimePropertyType = 0x4,
    kABDictionaryPropertyType = 0x5,
    kABMultiStringPropertyType = kABMultiValueMask | kABStringPropertyType,
    kABMultiIntegerPropertyType = kABMultiValueMask | kABIntegerPropertyType,
    kABMultiRealPropertyType = kABMultiValueMask | kABRealPropertyType,
    kABMultiDateTimePropertyType = kABMultiValueMask | kABDateTimePropertyType,
    kABMultiDictionaryPropertyType = kABMultiValueMask | kABDictionaryPropertyType
};

#define kABRecordInvalidID -1
#define kABPropertyInvalidID -1
