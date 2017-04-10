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

#include <COMIncludes.h>
#import <winrt/Windows.Devices.Enumeration.h>
#include <COMIncludes_End.h>

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

#import <AddressBook/ABAddressBook.h>

namespace WDE = winrt::Windows::Devices::Enumeration;

// Status to be returned by mocked version of currentStatus.
static WDE::DeviceAccessStatus statusToMock = WDE::DeviceAccessStatus::Unspecified;
@class _ABAddressBookDevice;

@interface __ABAddressBookDevice_Swizzle : NSObject

/**
 * Swizzles _ABAddressBookDevice's currentStatus to return a movked status,
 * and returns the original implementation of currentStatus.
 */
+ (IMP)setupMock;

/**
 * Swizzles the given implementation to _ABAddressBookDevice's currentStatus
 * (the passed in implementation should be the value returend from setupMock).
 */
+ (void)tearDownMock:(IMP)implementation;

/**
 * Returns a mocked version of WDE::DeviceAccessStatus.
 */
+ (WDE::DeviceAccessStatus)mockCurrentStatus;

@end

@implementation __ABAddressBookDevice_Swizzle

+ (IMP)setupMock {
    SEL originalSelector = @selector(currentStatus);
    SEL swizzledSelector = @selector(mockCurrentStatus);
    Method swizzledMethod = class_getClassMethod([__ABAddressBookDevice_Swizzle class], swizzledSelector);
    return class_replaceMethod([_ABAddressBookDevice class],
                               originalSelector,
                               method_getImplementation(swizzledMethod),
                               [[NSString stringWithFormat:@"%s@:", @encode(WDE::DeviceAccessStatus)] UTF8String]);
}

+ (void)tearDownMock:(IMP)implementation {
    class_replaceMethod([_ABAddressBookDevice class],
                        @selector(currentStatus),
                        implementation,
                        [[NSString stringWithFormat:@"%s@:", @encode(WDE::DeviceAccessStatus)] UTF8String]);
}

+ (WDE::DeviceAccessStatus)mockCurrentStatus {
    return statusToMock;
}

@end

class AddressBookTest : public ::testing::TestWithParam<::testing::tuple<WDE::DeviceAccessStatus, ABAuthorizationStatus, const char*>> {
protected:
    virtual void SetUp() {
        _originalImplementation = [__ABAddressBookDevice_Swizzle setupMock];
    }

    virtual void TearDown() {
        [__ABAddressBookDevice_Swizzle tearDownMock:_originalImplementation];
    }

    IMP _originalImplementation;
};

class AddressBookTest2 : public ::testing::TestWithParam<::testing::tuple<WDE::DeviceAccessStatus, bool>> {
protected:
    virtual void SetUp() {
        _originalImplementation = [__ABAddressBookDevice_Swizzle setupMock];
    }

    virtual void TearDown() {
        [__ABAddressBookDevice_Swizzle tearDownMock:_originalImplementation];
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
                        ::testing::Values(::testing::make_tuple(WDE::DeviceAccessStatus::Unspecified,
                                                                kABAuthorizationStatusNotDetermined,
                                                                "FAILED: Authorization Status should be undetermined!\n"),
                                          ::testing::make_tuple(WDE::DeviceAccessStatus::Allowed,
                                                                kABAuthorizationStatusAuthorized,
                                                                "FAILED: Authorization Status should be authorized!\n"),
                                          ::testing::make_tuple(WDE::DeviceAccessStatus::DeniedByUser,
                                                                kABAuthorizationStatusDenied,
                                                                "FAILED: Authorization Status should be denied!\n"),
                                          ::testing::make_tuple(WDE::DeviceAccessStatus::DeniedBySystem,
                                                                kABAuthorizationStatusRestricted,
                                                                "FAILED: Authorization Status should be restricted!\n")));

INSTANTIATE_TEST_CASE_P(AddressBook,
                        AddressBookTest2,
                        ::testing::Values(::testing::make_tuple(WDE::DeviceAccessStatus::Unspecified, false),
                                          ::testing::make_tuple(WDE::DeviceAccessStatus::Allowed, true)));