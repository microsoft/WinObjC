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

#import <COMIncludes.h>
#import "MockClass.h"
#include <windows.devices.enumeration.h>
#include <windows.foundation.h>
#import <COMIncludes_End.h>

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>

#import <AddressBook/ABAddressBook.h>
#import "UWP/WindowsDevicesEnumeration.h"

using namespace ABI::Windows::Devices::Enumeration;
using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;

// Status to be returned by mocked version of get_CurrentStatus.
static WDEDeviceAccessStatus statusToMock;

// Mocked version of WDEDeviceAccessInformation.
MOCK_CLASS(MockDeviceAccessInformation, public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDeviceAccessInformation> {
    InspectableClass(RuntimeClass_Windows_Devices_Enumeration_DeviceAccessInformation, BaseTrust);

public:
    MOCK_STDCALL_METHOD_2(add_AccessChanged);
    MOCK_STDCALL_METHOD_1(remove_AccessChanged);
    MOCK_STDCALL_METHOD_1(get_CurrentStatus);
});

@interface __ABAddressBook_Swizzle : NSObject

/**
 * Swizzles WDEDeviceAccessInformation's createFromDeviceClassId: to return a
 * mocked version of WDEDeviceAccessInformation, and returns the original
 * implementation of createFromDeviceClassId:.
 */
+ (IMP)setupMock;

/**
 * Swizzles the given implementation to WDEDeviceAccessInformation's
 * createFromDeviceClassId: (the passed in implementation should be the
 * value returend from setupMock).
 */
+ (void)tearDownMock:(IMP)implementation;

/**
 * Returns a mocked version of WDEDeviceAccessInformation.
 */
+ (WDEDeviceAccessInformation*)mockCreateFromDeviceClassId:(WFGUID*)deviceClassId;

@end

@implementation __ABAddressBook_Swizzle

+ (IMP)setupMock {
    SEL originalSelector = @selector(createFromDeviceClassId:);
    SEL swizzledSelector = @selector(mockCreateFromDeviceClassId:);
    Method swizzledMethod = class_getClassMethod([__ABAddressBook_Swizzle class], swizzledSelector);
    return class_replaceMethod(objc_getMetaClass("WDEDeviceAccessInformation"),
                               originalSelector,
                               method_getImplementation(swizzledMethod),
                               @encode(WFGUID*));
}

+ (void)tearDownMock:(IMP)implementation {
    class_replaceMethod(objc_getMetaClass("WDEDeviceAccessInformation"),
                        @selector(createFromDeviceClassId:),
                        implementation,
                        @encode(WFGUID*));
}

+ (WDEDeviceAccessInformation*)mockCreateFromDeviceClassId:(WFGUID*)deviceClassId {
    auto fakeDeviceAccessInformation = Make<MockDeviceAccessInformation>();

    fakeDeviceAccessInformation->Setget_CurrentStatus([](DeviceAccessStatus* result) {
        *result = static_cast<DeviceAccessStatus>(statusToMock);
        return S_OK;
    });

    return [WDEDeviceAccessInformation createWith:fakeDeviceAccessInformation.Get()];
}

@end

TEST(AddressBook, AddressBook_AuthorizationStatus) {
    IMP originalImplementation = [__ABAddressBook_Swizzle setupMock];

    statusToMock = WDEDeviceAccessStatusUnspecified;
    ASSERT_EQ_MSG(kABAuthorizationStatusNotDetermined,
                  ABAddressBookGetAuthorizationStatus(),
                  "FAILED: Authorization Status should be undetermined!\n");

    statusToMock = WDEDeviceAccessStatusAllowed;
    ASSERT_EQ_MSG(kABAuthorizationStatusAuthorized,
                  ABAddressBookGetAuthorizationStatus(),
                  "FAILED: Authorization Status should be authorized!\n");

    statusToMock = WDEDeviceAccessStatusDeniedByUser;
    ASSERT_EQ_MSG(kABAuthorizationStatusDenied, ABAddressBookGetAuthorizationStatus(), "FAILED: Authorization Status should be denied!\n");

    statusToMock = WDEDeviceAccessStatusDeniedBySystem;
    ASSERT_EQ_MSG(kABAuthorizationStatusRestricted,
                  ABAddressBookGetAuthorizationStatus(),
                  "FAILED: Authorization Status should be restricted!\n");

    [__ABAddressBook_Swizzle tearDownMock:originalImplementation];
}

TEST(AddressBook, AddressBook_RequestAuthorization) {
    IMP originalImplementation = [__ABAddressBook_Swizzle setupMock];

    // Test the case when permissions are not granted.
    statusToMock = WDEDeviceAccessStatusUnspecified;
    ABAddressBookRequestAccessWithCompletion(NULL, ^(bool granted, CFErrorRef error) {
        ASSERT_FALSE_MSG(granted, "FAILED: Access should not be granted\n");
    });

    // Test the case where permissions are granted.
    statusToMock = WDEDeviceAccessStatusAllowed;
    ABAddressBookRequestAccessWithCompletion(NULL, ^(bool granted, CFErrorRef error) {
        ASSERT_TRUE_MSG(granted, "FAILED: Access should be granted\n");
    });

    [__ABAddressBook_Swizzle tearDownMock:originalImplementation];
}
