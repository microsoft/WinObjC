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

#import <AddressBook/ABAddressBook.h>

#import "AssertARCEnabled.h"
#import <StubReturn.h>
#import <Starboard/SmartTypes.h>

#import "ABAddressBookManagerInternal.h"
#import "CppWinRTHelpers.h"

#import "initguid.h"

#include "COMIncludes.h"
#import <winrt/Windows.Devices.Enumeration.h>
#include "COMIncludes_End.h"

using namespace winrt::Windows::Devices::Enumeration;

// GUID to check Windows Contacts permissions.
DEFINE_GUID(_ABAddressBookContactsGUID, 0x7D7E8402, 0x7C54, 0x4821, 0xA3, 0x4E, 0xAE, 0xEF, 0xD6, 0x2D, 0xED, 0x93);

const CFStringRef ABAddressBookErrorDomain = static_cast<const CFStringRef>(@"ABAddressBookErrorDomain");

// Wrapper around WDE::DeviceAccessInformation, whose implementation can be
// replaced in test scenarios
@interface _ABAddressBookDevice : NSObject
- (instancetype)initWithDeviceClassId:(GUID)classId;
- (DeviceAccessStatus)currentStatus;
@end

@implementation _ABAddressBookDevice {
    TrivialDefaultConstructor<DeviceAccessInformation> _deviceInfo;
}

- (instancetype)initWithDeviceClassId:(GUID)classId {
    if (self = [super init]) {
        _deviceInfo = DeviceAccessInformation::CreateFromDeviceClassId(classId);
    }

    return self;
}

- (DeviceAccessStatus)currentStatus {
    return _deviceInfo.CurrentStatus();
}
@end

/**
 @Status Interoperable
 @Notes
*/
ABAddressBookRef ABAddressBookCreate() {
    return ABAddressBookCreateWithOptions(NULL, NULL);
}

/**
 @Status Interoperable
 @Notes
*/
ABAddressBookRef ABAddressBookCreateWithOptions(CFDictionaryRef options, CFErrorRef* error) {
    _ABAddressBookManager* addressBook = [[_ABAddressBookManager alloc] init];
    if (addressBook == nil) {
        // There was an error setting up the backing
        // contact store, so just return NULL to signify
        // the error.
        if (error != nullptr) {
            // In this case, the caller is responsible to release error.
            *error = CFErrorCreate(NULL, ABAddressBookErrorDomain, kABOperationNotPermittedByUserError, NULL);
        }
        return NULL;
    } else {
        return (__bridge_retained ABAddressBookRef)addressBook;
    }
}

/**
 @Status Interoperable
 @Notes
*/
ABAuthorizationStatus ABAddressBookGetAuthorizationStatus() {
    _ABAddressBookDevice* deviceInfo = [[_ABAddressBookDevice alloc] initWithDeviceClassId:_ABAddressBookContactsGUID];

    switch ([deviceInfo currentStatus]) {
        case DeviceAccessStatus::Allowed:
            return kABAuthorizationStatusAuthorized;
        case DeviceAccessStatus::DeniedBySystem:
            return kABAuthorizationStatusRestricted;
        case DeviceAccessStatus::DeniedByUser:
            return kABAuthorizationStatusDenied;
        default: // DeviceAccessStatus::Unspecified:
            return kABAuthorizationStatusNotDetermined;
    }
}

/**
 @Status Caveat
 @Notes Requesting access should be done by declaring Contacts capabilities in the app's package manifest -- it cannot be granted at
 runtime.
*/
void ABAddressBookRequestAccessWithCompletion(ABAddressBookRef addressBook, ABAddressBookRequestAccessCompletionHandler completion) {
    CFErrorRef error = nullptr;
    bool accessGranted = ABAddressBookGetAuthorizationStatus() == kABAuthorizationStatusAuthorized;
    if (!accessGranted) {
        error = CFErrorCreate(NULL, ABAddressBookErrorDomain, kABOperationNotPermittedByUserError, NULL);
    }

    // Since we can't request access at runtime (Contacts capabilities must be declared
    // in the app's package manifest), immediately call the completion handler with the current
    // authorization status. Dispatch it async to match the reference platform.
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0),
                   ^(void) {
                       woc::unique_cf<CFErrorRef> strongError;
                       strongError.reset(error);
                       completion(accessGranted, strongError.get());
                   });
}

/**
 @Status Interoperable
 @Notes
*/
bool ABAddressBookHasUnsavedChanges(ABAddressBookRef addressBook) {
    return [(__bridge _ABAddressBookManager*)addressBook hasUnsavedChanges];
}

/**
 @Status Interoperable
 @Notes
*/
bool ABAddressBookSave(ABAddressBookRef addressBook, CFErrorRef* error) {
    bool result = [(__bridge _ABAddressBookManager*)addressBook save];
    if ((!result) && error) {
        NSDictionary* userInfo = @{
            NSLocalizedDescriptionKey : NSLocalizedString(@"Error saving AddressBook.\n", nil),
        };
        *error = (__bridge_retained CFErrorRef)[NSError errorWithDomain:(__bridge NSString*)ABAddressBookErrorDomain
                                                                   code:kABOperationNotPermittedByStoreError
                                                               userInfo:userInfo];
    }
    return result;
}

/**
 @Status Interoperable
 @Notes
*/
void ABAddressBookRevert(ABAddressBookRef addressBook) {
    [(__bridge _ABAddressBookManager*)addressBook revert];
}

/**
 @Status Interoperable
 @Notes
*/
bool ABAddressBookAddRecord(ABAddressBookRef addressBook, ABRecordRef record, CFErrorRef* error) {
    return [(__bridge _ABAddressBookManager*)addressBook addContact:record error:error];
}

/**
 @Status Caveat
 @Notes Records can only be removed if they are retrieved with ABAddressBookCopyArrayOfAllUserAppPeople
 -- contacts from ABAddressBookCopyArrayOfAllPeople are read-only and cannot be removed.
*/
bool ABAddressBookRemoveRecord(ABAddressBookRef addressBook, ABRecordRef record, CFErrorRef* error) {
    return [(__bridge _ABAddressBookManager*)addressBook removeContact:record error:error];
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
