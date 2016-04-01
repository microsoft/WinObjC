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

#import <AddressBook/ABAddressBook.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

const CFStringRef ABAddressBookErrorDomain = static_cast<const CFStringRef>(@"ABAddressBookErrorDomain");

/**
 @Status Stub
 @Notes
*/
ABAddressBookRef ABAddressBookCreate() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
ABAddressBookRef ABAddressBookCreateWithOptions(CFDictionaryRef options, CFErrorRef* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
ABAuthorizationStatus ABAddressBookGetAuthorizationStatus() {
    UNIMPLEMENTED();
    return kABAuthorizationStatusNotDetermined;
}

/**
 @Status Stub
 @Notes
*/
void ABAddressBookRequestAccessWithCompletion(ABAddressBookRef addressBook, ABAddressBookRequestAccessCompletionHandler completion) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
bool ABAddressBookHasUnsavedChanges(ABAddressBookRef addressBook) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool ABAddressBookSave(ABAddressBookRef addressBook, CFErrorRef* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void ABAddressBookRevert(ABAddressBookRef addressBook) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
bool ABAddressBookAddRecord(ABAddressBookRef addressBook, ABRecordRef record, CFErrorRef* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool ABAddressBookRemoveRecord(ABAddressBookRef addressBook, ABRecordRef record, CFErrorRef* error) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void ABAddressBookRegisterExternalChangeCallback(ABAddressBookRef addressBook, ABExternalChangeCallback callback, void* context) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void ABAddressBookUnregisterExternalChangeCallback(ABAddressBookRef addressBook, ABExternalChangeCallback callback, void* context) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef ABAddressBookCopyLocalizedLabel(CFStringRef label) {
    UNIMPLEMENTED();
    return StubReturn();
}
