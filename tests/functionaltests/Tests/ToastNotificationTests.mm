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

#include <TestFramework.h>
#include <COMIncludes.h>
#include "MockClass.h"
#include <windows.applicationModel.activation.h>
#include <COMIncludes_End.h>

#include <UWP/WindowsApplicationModelActivation.h>
#include <Foundation/Foundation.h>
#include "UIKit/UIApplication.h"
#include "StringHelpers.h"

using namespace ABI::Windows::ApplicationModel::Activation;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;

// Method to call in tests to activate app
extern "C" void UIApplicationActivationTest(IInspectable* args, void* delegateClassName);

MOCK_CLASS(MockToastNotificationActivatedEventArgs,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IToastNotificationActivatedEventArgs, IActivatedEventArgs> {

               // Claim to be the implementation for the real system RuntimeClass for ToastNotificationActivatedEventArgs.
               InspectableClass(RuntimeClass_Windows_ApplicationModel_Activation_ToastNotificationActivatedEventArgs, BaseTrust);

           public:
               MOCK_STDCALL_METHOD_1(get_Argument);
               MOCK_STDCALL_METHOD_1(get_UserInput);
               MOCK_STDCALL_METHOD_1(get_Kind);
               MOCK_STDCALL_METHOD_1(get_PreviousExecutionState);
               MOCK_STDCALL_METHOD_1(get_SplashScreen);
           });

@interface ToastNotificationForegroundActivationTestDelegate : NSObject <UIApplicationDelegate>
@property (nonatomic, readonly) StrongId<NSMutableDictionary> methodsCalled;
@end

@implementation ToastNotificationForegroundActivationTestDelegate
- (id)init {
    if (self = [super init]) {
        _methodsCalled.attach([NSMutableDictionary new]);
    }
    return self;
}

- (BOOL)application:(UIApplication*)application willFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    EXPECT_NE(nullptr, launchOptions[UIApplicationLaunchOptionsToastActionKey]);
    NSDictionary* toastAction = launchOptions[UIApplicationLaunchOptionsToastActionKey];
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST", toastAction[UIApplicationLaunchOptionsToastActionArgumentKey]);
    NSDictionary* userInput = toastAction[UIApplicationLaunchOptionsToastActionUserInputKey];
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST_VALUE", userInput[@"TOAST_NOTIFICATION_TEST_KEY"]);
    [_methodsCalled setObject:@(YES) forKey:NSStringFromSelector(_cmd)];
    return true;
}

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    EXPECT_NE(nullptr, launchOptions[UIApplicationLaunchOptionsToastActionKey]);
    NSDictionary* toastAction = launchOptions[UIApplicationLaunchOptionsToastActionKey];
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST", toastAction[UIApplicationLaunchOptionsToastActionArgumentKey]);
    NSDictionary* userInput = toastAction[UIApplicationLaunchOptionsToastActionUserInputKey];
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST_VALUE", userInput[@"TOAST_NOTIFICATION_TEST_KEY"]);
    [_methodsCalled setObject:@(YES) forKey:NSStringFromSelector(_cmd)];
    return true;
}

- (void)application:(UIApplication*)application didReceiveToastAction:(NSDictionary*)toastAction {
    // Delegate method should only be called once
    EXPECT_EQ([[self methodsCalled] objectForKey:NSStringFromSelector(_cmd)], nil);
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST", toastAction[UIApplicationLaunchOptionsToastActionArgumentKey]);
    NSDictionary* userInput = toastAction[UIApplicationLaunchOptionsToastActionUserInputKey];
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST_VALUE", userInput[@"TOAST_NOTIFICATION_TEST_KEY"]);
    [_methodsCalled setObject:@(YES) forKey:NSStringFromSelector(_cmd)];
    return;
}

@end

@interface ActivatedAppReceivesToastNotificationDelegate : NSObject <UIApplicationDelegate>
@property (nonatomic, readonly) StrongId<NSMutableDictionary> methodsCalled;
@end

@implementation ActivatedAppReceivesToastNotificationDelegate
- (id)init {
    if (self = [super init]) {
        _methodsCalled.attach([NSMutableDictionary new]);
    }
    return self;
}

- (BOOL)application:(UIApplication*)application willFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    // This should never be called if we are already activated
    ADD_FAILURE();
    return true;
}

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    // This should never be called if we are already activated
    ADD_FAILURE();
    return true;
}

- (void)application:(UIApplication*)application didReceiveToastAction:(NSDictionary*)toastAction {
    // Delegate method should only be called once
    EXPECT_EQ([[self methodsCalled] objectForKey:NSStringFromSelector(_cmd)], nil);
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST", toastAction[UIApplicationLaunchOptionsToastActionArgumentKey]);
    [_methodsCalled setObject:@(YES) forKey:NSStringFromSelector(_cmd)];
    return;
}

@end

// Creates test method which we call in TEST_CLASS_SETUP to activate app
TEST(ToastNotificationTest, ForegroundActivation) {
    LOG_INFO("Toast Notification Foreground Activation Test: ");

    // Create mocked data to pass into application
    RTObject* value = [WFPropertyValue createString:@"TOAST_NOTIFICATION_TEST_VALUE"];
    WFCValueSet* wfcUserInput = [WFCValueSet make];
    [wfcUserInput setObject:value forKey:@"TOAST_NOTIFICATION_TEST_KEY"];

    auto fakeToastNotificationActivatedEventArgs = Make<MockToastNotificationActivatedEventArgs>();
    fakeToastNotificationActivatedEventArgs->Setget_Argument([](HSTRING* argument) {
        Wrappers::HString value;
        value.Set(L"TOAST_NOTIFICATION_TEST");
        *argument = value.Detach();
        return S_OK;
    });

    fakeToastNotificationActivatedEventArgs->Setget_UserInput([&wfcUserInput](IPropertySet** userInput) {
        wfcUserInput.comObj.CopyTo(userInput);
        return S_OK;
    });

    fakeToastNotificationActivatedEventArgs->Setget_Kind([](ActivationKind* kind) {
        *kind = ActivationKind_ToastNotification;
        return S_OK;
    });

    fakeToastNotificationActivatedEventArgs->Setget_PreviousExecutionState([](ApplicationExecutionState* state) {
        *state = ApplicationExecutionState_NotRunning;
        return S_OK;
    });

    // Pass activation argument to method which activates the app
    UIApplicationActivationTest(reinterpret_cast<IInspectable*>(fakeToastNotificationActivatedEventArgs.Get()),
                                NSStringFromClass([ToastNotificationForegroundActivationTestDelegate class]));
}

TEST(ToastNotificationTest, ForegroundActivationDelegateMethodsCalled) {
    ToastNotificationForegroundActivationTestDelegate* testDelegate = [[UIApplication sharedApplication] delegate];
    NSDictionary* methodsCalled = [testDelegate methodsCalled];
    EXPECT_TRUE(methodsCalled);
    EXPECT_TRUE([methodsCalled objectForKey:@"application:willFinishLaunchingWithOptions:"]);
    EXPECT_TRUE([methodsCalled objectForKey:@"application:didFinishLaunchingWithOptions:"]);
    EXPECT_TRUE([methodsCalled objectForKey:@"application:didReceiveToastAction:"]);
}

TEST(ToastNotificationTest, ActivatedAppReceivesToastNotification) {
    LOG_INFO("Activated App Receives Toast Notification Test: ");

    ActivatedAppReceivesToastNotificationDelegate* testDelegate = [ActivatedAppReceivesToastNotificationDelegate new];
    [[UIApplication sharedApplication] setDelegate:testDelegate];

    // Create mocked data to pass into application
    RTObject* value = [WFPropertyValue createString:@"TOAST_NOTIFICATION_TEST_VALUE"];
    WFCValueSet* wfcUserInput = [WFCValueSet make];
    [wfcUserInput setObject:value forKey:@"TOAST_NOTIFICATION_TEST_KEY"];

    auto fakeToastNotificationActivatedEventArgs = Make<MockToastNotificationActivatedEventArgs>();
    fakeToastNotificationActivatedEventArgs->Setget_Argument([](HSTRING* argument) {
        Wrappers::HString value;
        value.Set(L"TOAST_NOTIFICATION_TEST");
        *argument = value.Detach();
        return S_OK;
    });

    fakeToastNotificationActivatedEventArgs->Setget_UserInput([&wfcUserInput](IPropertySet** userInput) {
        wfcUserInput.comObj.CopyTo(userInput);
        return S_OK;
    });

    fakeToastNotificationActivatedEventArgs->Setget_Kind([](ActivationKind* kind) {
        *kind = ActivationKind_ToastNotification;
        return S_OK;
    });

    fakeToastNotificationActivatedEventArgs->Setget_PreviousExecutionState([](ApplicationExecutionState* state) {
        *state = ApplicationExecutionState_Running;
        return S_OK;
    });

    // Calls OnActivated, which should not go through activation because we are activated
    // But should still call our new delegate method
    UIApplicationActivationTest(reinterpret_cast<IInspectable*>(fakeToastNotificationActivatedEventArgs.Get()),
                                NSStringFromClass([ToastNotificationForegroundActivationTestDelegate class]));

    NSDictionary* methodsCalled = [testDelegate methodsCalled];
    EXPECT_TRUE(methodsCalled);
    EXPECT_TRUE([methodsCalled objectForKey:@"application:didReceiveToastAction:"]);
}
