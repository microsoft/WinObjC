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
#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFError.h>
#import <CoreFoundation/CFString.h>

typedef CFTypeRef ABAddressBookRef;
typedef void (*ABExternalChangeCallback)(ABAddressBookRef addressBook, CFDictionaryRef info, void* context);
typedef void (^ABAddressBookRequestAccessCompletionHandler)(bool granted, CFErrorRef error);
typedef CF_ENUM(CFIndex, ABAuthorizationStatus) {
    kABAuthorizationStatusNotDetermined = 0,
    kABAuthorizationStatusRestricted,
    kABAuthorizationStatusDenied,
    kABAuthorizationStatusAuthorized
};

ADDRESSBOOK_EXPORT ABAddressBookRef ABAddressBookCreate() STUB_METHOD;
ADDRESSBOOK_EXPORT ABAddressBookRef ABAddressBookCreateWithOptions(CFDictionaryRef options, CFErrorRef* error) STUB_METHOD;
ADDRESSBOOK_EXPORT ABAuthorizationStatus ABAddressBookGetAuthorizationStatus() STUB_METHOD;
ADDRESSBOOK_EXPORT void ABAddressBookRequestAccessWithCompletion(ABAddressBookRef addressBook,
                                                                 ABAddressBookRequestAccessCompletionHandler completion) STUB_METHOD;

ADDRESSBOOK_EXPORT bool ABAddressBookHasUnsavedChanges(ABAddressBookRef addressBook) STUB_METHOD;
ADDRESSBOOK_EXPORT bool ABAddressBookSave(ABAddressBookRef addressBook, CFErrorRef* error) STUB_METHOD;
ADDRESSBOOK_EXPORT void ABAddressBookRevert(ABAddressBookRef addressBook) STUB_METHOD;
ADDRESSBOOK_EXPORT bool ABAddressBookAddRecord(ABAddressBookRef addressBook, ABRecordRef record, CFErrorRef* error) STUB_METHOD;
ADDRESSBOOK_EXPORT bool ABAddressBookRemoveRecord(ABAddressBookRef addressBook, ABRecordRef record, CFErrorRef* error) STUB_METHOD;
ADDRESSBOOK_EXPORT void ABAddressBookRegisterExternalChangeCallback(ABAddressBookRef addressBook,
                                                                    ABExternalChangeCallback callback,
                                                                    void* context) STUB_METHOD;

ADDRESSBOOK_EXPORT void ABAddressBookUnregisterExternalChangeCallback(ABAddressBookRef addressBook,
                                                                      ABExternalChangeCallback callback,
                                                                      void* context) STUB_METHOD;

ADDRESSBOOK_EXPORT CFStringRef ABAddressBookCopyLocalizedLabel(CFStringRef label) STUB_METHOD;
ADDRESSBOOK_EXPORT const CFStringRef ABAddressBookErrorDomain;

enum { kABOperationNotPermittedByStoreError = 0, kABOperationNotPermittedByUserError };