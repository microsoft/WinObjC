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
MOCK_CLASS(MockDeviceAccessInformation,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IDeviceAccessInformation> {
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

class AddressBookTest : public ::testing::TestWithParam<::testing::tuple<WDEDeviceAccessStatus, ABAuthorizationStatus, const char*>> {
protected:
    virtual void SetUp() {
        _originalImplementation = [__ABAddressBook_Swizzle setupMock];
    }

    virtual void TearDown() {
        [__ABAddressBook_Swizzle tearDownMock:_originalImplementation];
    }

    IMP _originalImplementation;
};

class AddressBookTest2 : public ::testing::TestWithParam<::testing::tuple<WDEDeviceAccessStatus, bool>> {
protected:
    virtual void SetUp() {
        _originalImplementation = [__ABAddressBook_Swizzle setupMock];
    }

    virtual void TearDown() {
        [__ABAddressBook_Swizzle tearDownMock:_originalImplementation];
    }

    IMP _originalImplementation;
};

TEST_P(AddressBookTest, AuthorizationStatus) {
    statusToMock = ::testing::get<0>(GetParam());
    ASSERT_EQ_MSG(::testing::get<1>(GetParam()), ABAddressBookGetAuthorizationStatus(), ::testing::get<2>(GetParam()));
}

TEST_P(AddressBookTest2, RequestAuthorization) {
    statusToMock = ::testing::get<0>(GetParam());
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);
    dispatch_time_t timeout = dispatch_time(DISPATCH_TIME_NOW, (int64_t)(10.0 * NSEC_PER_SEC));
    __block bool grantedStatus = false;
    ABAddressBookRequestAccessWithCompletion(NULL,
                                             ^(bool granted, CFErrorRef error) {
                                                 grantedStatus = granted;
                                                 dispatch_semaphore_signal(semaphore);
                                             });
    ASSERT_EQ_MSG(dispatch_semaphore_wait(semaphore, timeout), 0, "FAILED: Callback not called within timeout!\n");
    ASSERT_EQ_MSG(grantedStatus, ::testing::get<1>(GetParam()), "FAILED: incorrect granted status!\n");
}

INSTANTIATE_TEST_CASE_P(AddressBook,
                        AddressBookTest,
                        ::testing::Values(::testing::make_tuple(WDEDeviceAccessStatusUnspecified,
                                                                kABAuthorizationStatusNotDetermined,
                                                                "FAILED: Authorization Status should be undetermined!\n"),
                                          ::testing::make_tuple(WDEDeviceAccessStatusAllowed,
                                                                kABAuthorizationStatusAuthorized,
                                                                "FAILED: Authorization Status should be authorized!\n"),
                                          ::testing::make_tuple(WDEDeviceAccessStatusDeniedByUser,
                                                                kABAuthorizationStatusDenied,
                                                                "FAILED: Authorization Status should be denied!\n"),
                                          ::testing::make_tuple(WDEDeviceAccessStatusDeniedBySystem,
                                                                kABAuthorizationStatusRestricted,
                                                                "FAILED: Authorization Status should be restricted!\n")));

INSTANTIATE_TEST_CASE_P(AddressBook,
                        AddressBookTest2,
                        ::testing::Values(::testing::make_tuple(WDEDeviceAccessStatusUnspecified, false),
                                          ::testing::make_tuple(WDEDeviceAccessStatusAllowed, true)));