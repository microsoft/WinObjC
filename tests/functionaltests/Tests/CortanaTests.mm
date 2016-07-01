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
#include <Foundation/Foundation.h>

#include <COMIncludes.h>
#include "MockClass.h"
#include <windows.applicationModel.activation.h>
#include <windows.media.speechRecognition.h>
#include <windows.foundation.h>
#include <COMIncludes_End.h>

#include <UWP/WindowsApplicationModelActivation.h>
#include <UWP/WindowsMediaSpeechRecognition.h>
#include <UWP/WindowsUIXaml.h>
#include "StringHelpers.h"
#include "UIKit/UIApplication.h"

using namespace ABI::Windows::ApplicationModel::Activation;
using namespace ABI::Windows::Media::SpeechRecognition;
using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;

// Method to call in tests to activate app
extern "C" void UIApplicationActivationTest(IInspectable* args);

// These are for testing that delegate methods are actually called
static bool willFinishLaunchingWithOptionsCalled = false;
static bool didFinishLaunchingWithOptionsCalled = false;
static bool didReceiveVoiceCommandCalled = false;
static bool didReceiveProtocolCalled = false;

MOCK_CLASS(MockSpeechRecognitionResult,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ISpeechRecognitionResult, ISpeechRecognitionResult2> {

               // Claim to be the implementation for the real system RuntimeClass for SpeechRecognitionResult.
               InspectableClass(RuntimeClass_Windows_Media_SpeechRecognition_SpeechRecognitionResult, BaseTrust);

           public:
               MOCK_STDCALL_METHOD_1(get_Status);
               MOCK_STDCALL_METHOD_1(get_Text);
               MOCK_STDCALL_METHOD_1(get_Confidence);
               MOCK_STDCALL_METHOD_1(get_SemanticInterpretation);
               MOCK_STDCALL_METHOD_2(GetAlternates);
               MOCK_STDCALL_METHOD_1(get_Constraint);
               MOCK_STDCALL_METHOD_1(get_RulePath);
               MOCK_STDCALL_METHOD_1(get_RawConfidence);
               MOCK_STDCALL_METHOD_1(get_PhraseStartTime);
               MOCK_STDCALL_METHOD_1(get_PhraseDuration);
           });

MOCK_CLASS(MockVoiceCommandActivatedEventArgs,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IVoiceCommandActivatedEventArgs, IActivatedEventArgs> {

               // Claim to be the implementation for the real system RuntimeClass for VoiceCommandActivatedEventArgs.
               InspectableClass(RuntimeClass_Windows_ApplicationModel_Activation_VoiceCommandActivatedEventArgs, BaseTrust);

           public:
               MOCK_STDCALL_METHOD_1(get_Result);
               MOCK_STDCALL_METHOD_1(get_Kind);
               MOCK_STDCALL_METHOD_1(get_PreviousExecutionState);
               MOCK_STDCALL_METHOD_1(get_SplashScreen);
           });

MOCK_CLASS(
    MockUri,
    public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IUriRuntimeClass, IUriRuntimeClassWithAbsoluteCanonicalUri, IStringable> {

        // Claim to be the implementation for the real system RuntimeClass for Uri.
        InspectableClass(RuntimeClass_Windows_Foundation_Uri, BaseTrust);

    public:
        MOCK_STDCALL_METHOD_1(get_AbsoluteUri);
        MOCK_STDCALL_METHOD_1(get_DisplayUri);
        MOCK_STDCALL_METHOD_1(get_Domain);
        MOCK_STDCALL_METHOD_1(get_Extension);
        MOCK_STDCALL_METHOD_1(get_Fragment);
        MOCK_STDCALL_METHOD_1(get_Host);
        MOCK_STDCALL_METHOD_1(get_Password);
        MOCK_STDCALL_METHOD_1(get_Path);
        MOCK_STDCALL_METHOD_1(get_Query);
        MOCK_STDCALL_METHOD_1(get_QueryParsed);
        MOCK_STDCALL_METHOD_1(get_RawUri);
        MOCK_STDCALL_METHOD_1(get_SchemeName);
        MOCK_STDCALL_METHOD_1(get_UserName);
        MOCK_STDCALL_METHOD_1(get_Port);
        MOCK_STDCALL_METHOD_1(get_Suspicious);
        MOCK_STDCALL_METHOD_2(Equals);
        MOCK_STDCALL_METHOD_2(CombineUri);
        MOCK_STDCALL_METHOD_1(get_AbsoluteCanonicalUri);
        MOCK_STDCALL_METHOD_1(get_DisplayIri);
        MOCK_STDCALL_METHOD_1(ToString);
    });

MOCK_CLASS(MockProtocolActivatedEventArgs,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                               IProtocolActivatedEventArgs,
                               IActivatedEventArgs,
                               IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData,
                               IApplicationViewActivatedEventArgs,
                               IViewSwitcherProvider> {

               // Claim to be the implementation for the real system RuntimeClass for ProtocolActivatedEventArgs.
               InspectableClass(RuntimeClass_Windows_ApplicationModel_Activation_ProtocolActivatedEventArgs, BaseTrust);

           public:
               MOCK_STDCALL_METHOD_1(get_Uri);
               MOCK_STDCALL_METHOD_1(get_Kind);
               MOCK_STDCALL_METHOD_1(get_PreviousExecutionState);
               MOCK_STDCALL_METHOD_1(get_SplashScreen);
               MOCK_STDCALL_METHOD_1(get_CallerPackageFamilyName);
               MOCK_STDCALL_METHOD_1(get_Data);
               MOCK_STDCALL_METHOD_1(get_CurrentlyShownApplicationViewId);
               MOCK_STDCALL_METHOD_1(get_ViewSwitcher);
           });

// Delegate for testing Cortana foreground activation
// Use text value to guarantee it is the same argument we create
@interface CortanaVoiceCommandForegroundTestDelegate : NSObject <UIApplicationDelegate>
@end

@implementation CortanaVoiceCommandForegroundTestDelegate
- (BOOL)application:(UIApplication*)application willFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    ASSERT_TRUE(launchOptions[UIApplicationLaunchOptionsVoiceCommandKey]);
    WMSSpeechRecognitionResult* result = launchOptions[UIApplicationLaunchOptionsVoiceCommandKey];
    ASSERT_STREQ("CORTANA_TEST", [result.text UTF8String]);
    willFinishLaunchingWithOptionsCalled = true;
    return true;
}

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    ASSERT_TRUE(launchOptions[UIApplicationLaunchOptionsVoiceCommandKey]);
    WMSSpeechRecognitionResult* result = launchOptions[UIApplicationLaunchOptionsVoiceCommandKey];
    ASSERT_STREQ("CORTANA_TEST", [result.text UTF8String]);
    didFinishLaunchingWithOptionsCalled = true;
    return true;
}

- (BOOL)application:(UIApplication*)application didReceiveVoiceCommand:(WMSSpeechRecognitionResult*)result {
    ASSERT_STREQ("CORTANA_TEST", [result.text UTF8String]);
    didReceiveVoiceCommandCalled = true;
    return true;
}
@end

@interface CortanaProtocolForegroundTestDelegate : NSObject <UIApplicationDelegate>
@end

@implementation CortanaProtocolForegroundTestDelegate
- (BOOL)application:(UIApplication*)application willFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    ASSERT_TRUE(launchOptions[UIApplicationLaunchOptionsProtocolKey]);
    WFUri* uri = launchOptions[UIApplicationLaunchOptionsProtocolKey];
    ASSERT_STREQ("CORTANA_TEST", [uri.toString UTF8String]);
    willFinishLaunchingWithOptionsCalled = true;
    return true;
}

- (BOOL)application:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions {
    ASSERT_TRUE(launchOptions[UIApplicationLaunchOptionsProtocolKey]);
    WFUri* uri = launchOptions[UIApplicationLaunchOptionsProtocolKey];
    ASSERT_STREQ("CORTANA_TEST", [uri.toString UTF8String]);
    didFinishLaunchingWithOptionsCalled = true;
    return true;
}

- (BOOL)application:(UIApplication*)application didReceiveProtocol:(WFUri*)uri {
    ASSERT_STREQ("CORTANA_TEST", [uri.toString UTF8String]);
    didReceiveProtocolCalled = true;
    return true;
}
@end

// Create method in UIApplication to swizzle setDelegate: so we can use our delegate for testing
@interface UIApplication (CortanaForegroundTest)
- (void)swizzleVoiceCommandDelegate:(id)delegateAddr;
- (void)swizzleProtocolDelegate:(id)delegateAddr;
@end

@implementation UIApplication (CortanaForegroundTest)
- (void)swizzleVoiceCommandDelegate:(id)delegateAddr {
    [self swizzleVoiceCommandDelegate:[CortanaVoiceCommandForegroundTestDelegate new]];
}
- (void)swizzleProtocolDelegate:(id)delegateAddr {
    [self swizzleProtocolDelegate:[CortanaProtocolForegroundTestDelegate new]];
}
@end

// Creates test method which we call in TEST_CLASS_SETUP to activate app
TEST(CortanaTest, VoiceCommandForegroundActivation) {
    LOG_INFO("CortanaTest Voice Command Foreground Activation Test: ");

    // Create mocked data to pass into application
    auto fakeSpeechRecognitionResult = Make<MockSpeechRecognitionResult>();
    fakeSpeechRecognitionResult->Setget_Text([](HSTRING* text) {
        Wrappers::HString value;
        value.Set(L"CORTANA_TEST");
        *text = value.Detach();
        return S_OK;
    });

    auto fakeVoiceCommandActivatedEventArgs = Make<MockVoiceCommandActivatedEventArgs>();
    fakeVoiceCommandActivatedEventArgs->Setget_Result([&fakeSpeechRecognitionResult](ISpeechRecognitionResult** result) {
        fakeSpeechRecognitionResult.CopyTo(result);
        return S_OK;
    });

    fakeVoiceCommandActivatedEventArgs->Setget_Kind([](ActivationKind* kind) {
        *kind = ActivationKind_VoiceCommand;
        return S_OK;
    });

    fakeVoiceCommandActivatedEventArgs->Setget_PreviousExecutionState([](ApplicationExecutionState* state) {
        *state = ApplicationExecutionState_NotRunning;
        return S_OK;
    });

    // Swizzle method to use our delegate for testing
    Method originalMethod = class_getInstanceMethod([UIApplication class], @selector(setDelegate:));
    Method swizzledMethod = class_getInstanceMethod([UIApplication class], @selector(swizzleVoiceCommandDelegate:));
    method_exchangeImplementations(originalMethod, swizzledMethod);

    // Pass activation argument to method which activates the app
    auto args = fakeVoiceCommandActivatedEventArgs.Detach();
    UIApplicationActivationTest(reinterpret_cast<IInspectable*>(args));

    // Un-Swizzle the methods now that we are done
    method_exchangeImplementations(originalMethod, swizzledMethod);
}

TEST(CortanaTest, VoiceCommandForegroundActivationDelegateMethodsCalled) {
    ASSERT_TRUE(willFinishLaunchingWithOptionsCalled);
    ASSERT_TRUE(didFinishLaunchingWithOptionsCalled);
    ASSERT_TRUE(didReceiveVoiceCommandCalled);

    // Set flags to false so they can be used for other tests.
    willFinishLaunchingWithOptionsCalled = false;
    didFinishLaunchingWithOptionsCalled = false;
    didReceiveVoiceCommandCalled = false;
}

// Creates test method which we call in TEST_CLASS_SETUP to activate app
TEST(CortanaTest, ProtocolForegroundActivation) {
    LOG_INFO("CortanaTest Protocol Foreground Activation Test: ");

    // Create mocked data to pass into application
    auto fakeUri = Make<MockUri>();
    fakeUri->SetToString([](HSTRING* text) {
        Wrappers::HString value;
        value.Set(L"CORTANA_TEST");
        *text = value.Detach();
        return S_OK;
    });

    auto fakeProtocolActivatedEventArgs = Make<MockProtocolActivatedEventArgs>();
    fakeProtocolActivatedEventArgs->Setget_Uri([&fakeUri](IUriRuntimeClass** uri) {
        fakeUri.CopyTo(uri);
        return S_OK;
    });

    fakeProtocolActivatedEventArgs->Setget_Kind([](ActivationKind* kind) {
        *kind = ActivationKind_Protocol;
        return S_OK;
    });

    fakeProtocolActivatedEventArgs->Setget_PreviousExecutionState([](ApplicationExecutionState* state) {
        *state = ApplicationExecutionState_NotRunning;
        return S_OK;
    });

    // Swizzle method to use our delegate for testing
    Method originalMethod = class_getInstanceMethod([UIApplication class], @selector(setDelegate:));
    Method swizzledMethod = class_getInstanceMethod([UIApplication class], @selector(swizzleProtocolDelegate:));
    method_exchangeImplementations(originalMethod, swizzledMethod);

    // Pass activation argument to method which activates the app
    auto args = fakeProtocolActivatedEventArgs.Detach();
    UIApplicationActivationTest(reinterpret_cast<IInspectable*>(args));

    // Un-Swizzle the methods now that we are done
    method_exchangeImplementations(originalMethod, swizzledMethod);
}

TEST(CortanaTest, ProtocolForegroundActivationDelegateMethodsCalled) {
    ASSERT_TRUE(willFinishLaunchingWithOptionsCalled);
    ASSERT_TRUE(didFinishLaunchingWithOptionsCalled);
    ASSERT_TRUE(didReceiveProtocolCalled);

    // Set flags to false so they can be used for other tests.
    willFinishLaunchingWithOptionsCalled = false;
    didFinishLaunchingWithOptionsCalled = false;
    didReceiveProtocolCalled = false;
}