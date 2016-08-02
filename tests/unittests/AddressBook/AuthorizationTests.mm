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

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

#import "UWP/WindowsDevicesEnumeration.h"
#import <AddressBook/ABAddressBook.h>

using namespace ABI::Windows::Devices::Enumeration;
using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;

// Status to be returned by mocked version of get_CurrentStatus.
static WDEDeviceAccessStatus statusToMock = WDEDeviceAccessStatusUnspecified;

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

class AddressBookTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        _originalImplementation = [__ABAddressBook_Swizzle setupMock];
    }

    virtual void TearDown() {
        [__ABAddressBook_Swizzle tearDownMock:_originalImplementation];
    }

    void testABAddressBookGetAuthorizationStatus(WDEDeviceAccessStatus toMock,
                                                 ABAuthorizationStatus expected,
                                                 char* errorMessage) {
        statusToMock = toMock;
        ASSERT_EQ_MSG(expected, ABAddressBookGetAuthorizationStatus(), errorMessage);
    }

    void testABAddressBookRequestAccess(WDEDeviceAccessStatus toMock, ABAddressBookRequestAccessCompletionHandler completion) {
        statusToMock = toMock;
        ABAddressBookRequestAccessWithCompletion(NULL, completion);
    }

    IMP _originalImplementation;
};

TEST_F(AddressBookTest, AuthorizationStatusNotDetermined) {
    testABAddressBookGetAuthorizationStatus(WDEDeviceAccessStatusUnspecified,
                                            kABAuthorizationStatusNotDetermined,
                                            "FAILED: Authorization Status should be undetermined!\n");
}

TEST_F(AddressBookTest, AuthorizationStatusAuthorized) {
    testABAddressBookGetAuthorizationStatus(WDEDeviceAccessStatusAllowed,
                                            kABAuthorizationStatusAuthorized,
                                            "FAILED: Authorization Status should be authorized!\n");
}

TEST_F(AddressBookTest, AuthorizationStatusDenied) {
    testABAddressBookGetAuthorizationStatus(WDEDeviceAccessStatusDeniedByUser,
                                            kABAuthorizationStatusDenied,
                                            "FAILED: Authorization Status should be denied!\n");
}

TEST_F(AddressBookTest, AuthorizationStatusRestricted) {
    testABAddressBookGetAuthorizationStatus(WDEDeviceAccessStatusDeniedBySystem,
                                            kABAuthorizationStatusRestricted,
                                            "FAILED: Authorization Status should be restricted!\n");
}

TEST_F(AddressBookTest, RequestAuthorizationNotGranted) {
    testABAddressBookRequestAccess(WDEDeviceAccessStatusUnspecified, ^(bool granted, CFErrorRef error) {
        ASSERT_FALSE_MSG(granted, "FAILED: Access should not be granted\n");
    });
}

TEST_F(AddressBookTest, RequestAuthorizationGranted) {
    testABAddressBookRequestAccess(WDEDeviceAccessStatusAllowed, ^(bool granted, CFErrorRef error) {
        ASSERT_TRUE_MSG(granted, "FAILED: Access should be granted\n");
    });
}