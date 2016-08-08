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

#include <COMIncludes.h>
#include "MockClass.h"
#include <windows.applicationModel.activation.h>
#include <COMIncludes_End.h>

#include <UWP/WindowsApplicationModelActivation.h>
#include <TestFramework.h>
#include <Foundation/Foundation.h>
#include "UIKit/UIApplication.h"
#include "StringHelpers.h"

using namespace ABI::Windows::ApplicationModel::Activation;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;

// Method to call in tests to activate app
extern "C" void UIApplicationActivationTest(IInspectable* args, void* delegateClassName);

MOCK_CLASS(MockPropertyValue,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IPropertyValue> {

           public:
               MOCK_STDCALL_METHOD_1(get_Type);
               MOCK_STDCALL_METHOD_1(get_IsNumericScalar);
               MOCK_STDCALL_METHOD_1(GetUInt8);
               MOCK_STDCALL_METHOD_1(GetInt16);
               MOCK_STDCALL_METHOD_1(GetUInt16);
               MOCK_STDCALL_METHOD_1(GetInt32);
               MOCK_STDCALL_METHOD_1(GetUInt32);
               MOCK_STDCALL_METHOD_1(GetInt64);
               MOCK_STDCALL_METHOD_1(GetUInt64);
               MOCK_STDCALL_METHOD_1(GetSingle);
               MOCK_STDCALL_METHOD_1(GetDouble);
               MOCK_STDCALL_METHOD_1(GetChar16);
               MOCK_STDCALL_METHOD_1(GetBoolean);
               MOCK_STDCALL_METHOD_1(GetString);
               MOCK_STDCALL_METHOD_1(GetGuid);
               MOCK_STDCALL_METHOD_1(GetDateTime);
               MOCK_STDCALL_METHOD_1(GetTimeSpan);
               MOCK_STDCALL_METHOD_1(GetPoint);
               MOCK_STDCALL_METHOD_1(GetSize);
               MOCK_STDCALL_METHOD_1(GetRect);
               MOCK_STDCALL_METHOD_2(GetUInt8Array);
               MOCK_STDCALL_METHOD_2(GetInt16Array);
               MOCK_STDCALL_METHOD_2(GetUInt16Array);
               MOCK_STDCALL_METHOD_2(GetInt32Array);
               MOCK_STDCALL_METHOD_2(GetUInt32Array);
               MOCK_STDCALL_METHOD_2(GetInt64Array);
               MOCK_STDCALL_METHOD_2(GetUInt64Array);
               MOCK_STDCALL_METHOD_2(GetSingleArray);
               MOCK_STDCALL_METHOD_2(GetDoubleArray);
               MOCK_STDCALL_METHOD_2(GetChar16Array);
               MOCK_STDCALL_METHOD_2(GetBooleanArray);
               MOCK_STDCALL_METHOD_2(GetStringArray);
               MOCK_STDCALL_METHOD_2(GetInspectableArray);
               MOCK_STDCALL_METHOD_2(GetGuidArray);
               MOCK_STDCALL_METHOD_2(GetDateTimeArray);
               MOCK_STDCALL_METHOD_2(GetTimeSpanArray);
               MOCK_STDCALL_METHOD_2(GetPointArray);
               MOCK_STDCALL_METHOD_2(GetSizeArray);
               MOCK_STDCALL_METHOD_2(GetRectArray);
           });

MOCK_CLASS(MockKeyValuePair,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IKeyValuePair<HSTRING, IInspectable*>> {

           public:
               MOCK_STDCALL_METHOD_1(get_Key);
               MOCK_STDCALL_METHOD_1(get_Value);
           });

MOCK_CLASS(MockIterator,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IIterator<IKeyValuePair<HSTRING, IInspectable*>*>> {

           public:
               MOCK_STDCALL_METHOD_1(get_Current);
               MOCK_STDCALL_METHOD_1(get_HasCurrent);
               MOCK_STDCALL_METHOD_1(MoveNext);
               MOCK_STDCALL_METHOD_3(GetMany);
           });

MOCK_CLASS(MockValueSet,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                               IPropertySet,
                               IObservableMap<HSTRING, IInspectable*>,
                               IMap<HSTRING, IInspectable*>,
                               IIterable<IKeyValuePair<HSTRING, IInspectable*>*>> {

               // Claim to be the implementation for the real system RuntimeClass for ToastNotificationActivatedEventArgs.
               InspectableClass(RuntimeClass_Windows_Foundation_Collections_ValueSet, BaseTrust);

           public:
               MOCK_STDCALL_METHOD_2(add_MapChanged);
               MOCK_STDCALL_METHOD_1(remove_MapChanged);
               MOCK_STDCALL_METHOD_2(Lookup);
               MOCK_STDCALL_METHOD_1(get_Size);
               MOCK_STDCALL_METHOD_2(HasKey);
               MOCK_STDCALL_METHOD_1(GetView);
               MOCK_STDCALL_METHOD_3(Insert);
               MOCK_STDCALL_METHOD_1(Remove);
               MOCK_STDCALL_METHOD_0(Clear);
               MOCK_STDCALL_METHOD_1(First);
           });

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
@property (nonatomic, readonly) NSMutableDictionary* methodsCalled;
@end

@implementation ToastNotificationForegroundActivationTestDelegate
- (id)init {
    self = [super init];
    if (self) {
        _methodsCalled = [NSMutableDictionary new];
    }
    return self;
}

- (BOOL)application:(UIApplication*)application willFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    EXPECT_TRUE(launchOptions[UIApplicationLaunchOptionsToastActionKey]);
    NSDictionary* toastAction = launchOptions[UIApplicationLaunchOptionsToastActionKey];
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST", toastAction[UIApplicationLaunchOptionsToastActionArgumentKey]);
    NSDictionary* userInput = toastAction[UIApplicationLaunchOptionsToastActionUserInputKey];
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST_VALUE", userInput[@"TOAST_NOTIFICATION_TEST_KEY"]);
    _methodsCalled[NSStringFromSelector(_cmd)] = @(YES);
    return true;
}

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    EXPECT_TRUE(launchOptions[UIApplicationLaunchOptionsToastActionKey]);
    NSDictionary* toastAction = launchOptions[UIApplicationLaunchOptionsToastActionKey];
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST", toastAction[UIApplicationLaunchOptionsToastActionArgumentKey]);
    NSDictionary* userInput = toastAction[UIApplicationLaunchOptionsToastActionUserInputKey];
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST_VALUE", userInput[@"TOAST_NOTIFICATION_TEST_KEY"]);
    _methodsCalled[NSStringFromSelector(_cmd)] = @(YES);
    return true;
}

- (BOOL)application:(UIApplication*)application didReceiveToastAction:(NSDictionary*)toastAction {
    // Delegate method should only be called once
    EXPECT_EQ([[self methodsCalled] objectForKey:NSStringFromSelector(_cmd)], nil);
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST", toastAction[UIApplicationLaunchOptionsToastActionArgumentKey]);
    NSDictionary* userInput = toastAction[UIApplicationLaunchOptionsToastActionUserInputKey];
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST_VALUE", userInput[@"TOAST_NOTIFICATION_TEST_KEY"]);
    _methodsCalled[NSStringFromSelector(_cmd)] = @(YES);
    return true;
}

@end

@interface ActivatedAppReceivesToastNotificationDelegate : NSObject <UIApplicationDelegate>
@property (nonatomic, readonly) NSMutableDictionary* methodsCalled;
@end

@implementation ActivatedAppReceivesToastNotificationDelegate
- (id)init {
    self = [super init];
    if (self) {
        _methodsCalled = [NSMutableDictionary new];
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

- (BOOL)application:(UIApplication*)application didReceiveToastAction:(NSDictionary*)toastAction {
    // Delegate method should only be called once
    EXPECT_EQ([[self methodsCalled] objectForKey:NSStringFromSelector(_cmd)], nil);
    EXPECT_OBJCEQ(@"TOAST_NOTIFICATION_TEST", toastAction[UIApplicationLaunchOptionsToastActionArgumentKey]);
    _methodsCalled[NSStringFromSelector(_cmd)] = @(YES);
    return true;
}

@end

// Creates test method which we call in TEST_CLASS_SETUP to activate app
TEST(ToastNotificationTest, ForegroundActivation) {
    LOG_INFO("Toast Notification Foreground Activation Test: ");

    // Create mocked data to pass into application
    auto fakePropertyValue = Make<MockPropertyValue>();
    fakePropertyValue->SetGetString([](HSTRING* value) {
        Wrappers::HString str;
        str.Set(L"TOAST_NOTIFICATION_TEST_VALUE");
        *value = str.Detach();
        return S_OK;
    });

    auto fakeKeyValuePair = Make<MockKeyValuePair>();
    fakeKeyValuePair->Setget_Key([](HSTRING* key) {
        Wrappers::HString str;
        str.Set(L"TOAST_NOTIFICATION_TEST_KEY");
        *key = str.Detach();
        return S_OK;
    });

    fakeKeyValuePair->Setget_Value([&fakePropertyValue](IInspectable** value) {
        fakePropertyValue.CopyTo(value);
        return S_OK;
    });

    auto fakeIterator = Make<MockIterator>();

    fakeIterator->Setget_HasCurrent([](boolean* hasCurrent) {
        *hasCurrent = true;
        return S_OK;
    });

    fakeIterator->Setget_Current([&fakeKeyValuePair](IKeyValuePair<HSTRING, IInspectable*>** current) {
        fakeKeyValuePair.CopyTo(current);
        return S_OK;
    });

    fakeIterator->SetMoveNext([](boolean* hasCurrent) {
        *hasCurrent = false;
        return S_OK;
    });

    auto fakeUserInput = Make<MockValueSet>();
    fakeUserInput->SetFirst([fakeIterator](IIterator<IKeyValuePair<HSTRING, IInspectable*>*>** first) {
        fakeIterator.CopyTo(first);
        return S_OK;
    });

    // Only return the value after we have been called to bypass attempted conversion to String^
    bool copyValue = false;
    fakeUserInput->SetLookup([&fakePropertyValue, &copyValue](HSTRING key, IInspectable** value) {
        if (copyValue) {
            fakePropertyValue.CopyTo(value);
        } else {
            copyValue = true;
        }
        return S_OK;
    });

    fakeUserInput->SetInsert([](HSTRING key, IInspectable* value, boolean* replaced) {
        *replaced = true;
        return S_OK;
    });

    auto fakeToastNotificationActivatedEventArgs = Make<MockToastNotificationActivatedEventArgs>();
    fakeToastNotificationActivatedEventArgs->Setget_Argument([](HSTRING* argument) {
        Wrappers::HString value;
        value.Set(L"TOAST_NOTIFICATION_TEST");
        *argument = value.Detach();
        return S_OK;
    });

    fakeToastNotificationActivatedEventArgs->Setget_UserInput([&fakeUserInput](IPropertySet** userInput) {
        fakeUserInput.CopyTo(userInput);
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
    auto args = fakeToastNotificationActivatedEventArgs.Detach();
    UIApplicationActivationTest(reinterpret_cast<IInspectable*>(args),
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
    auto fakeIterator = Make<MockIterator>();
    fakeIterator->Setget_HasCurrent([](boolean* hasCurrent) {
        *hasCurrent = false;
        return S_OK;
    });

    auto fakeUserInput = Make<MockValueSet>();
    fakeUserInput->SetFirst([fakeIterator](IIterator<IKeyValuePair<HSTRING, IInspectable*>*>** first) {
        fakeIterator.CopyTo(first);
        return S_OK;
    });

    auto fakeToastNotificationActivatedEventArgs = Make<MockToastNotificationActivatedEventArgs>();
    fakeToastNotificationActivatedEventArgs->Setget_Argument([](HSTRING* argument) {
        Wrappers::HString value;
        value.Set(L"TOAST_NOTIFICATION_TEST");
        *argument = value.Detach();
        return S_OK;
    });

    fakeToastNotificationActivatedEventArgs->Setget_UserInput([&fakeUserInput](IPropertySet** userInput) {
        fakeUserInput.CopyTo(userInput);
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
    auto args = fakeToastNotificationActivatedEventArgs.Detach();
    UIApplicationActivationTest(reinterpret_cast<IInspectable*>(args),
                                NSStringFromClass([ToastNotificationForegroundActivationTestDelegate class]));

    NSDictionary* methodsCalled = [testDelegate methodsCalled];
    EXPECT_TRUE(methodsCalled);
    EXPECT_TRUE([methodsCalled objectForKey:@"application:didReceiveToastAction:"]);
}
