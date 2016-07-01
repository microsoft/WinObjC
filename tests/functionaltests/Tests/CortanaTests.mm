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
#include <COMIncludes_End.h>

#include <UWP/WindowsApplicationModelActivation.h>
#include <UWP/WindowsMediaSpeechRecognition.h>
#include <UWP/WindowsUIXaml.h>
#include "StringHelpers.h"
#include "UIKit/UIApplication.h"

using namespace ABI::Windows::ApplicationModel::Activation;
using namespace ABI::Windows::Media::SpeechRecognition;
using namespace Microsoft::WRL;

// Method to call in tests to activate app
extern "C" void UIApplicationActivationTest(IInspectable* args);

// These are for testing that delegate methods are actually called
static bool willFinishLaunchingWithOptionsCalled = false;
static bool didFinishLaunchingWithOptionsCalled = false;
static bool didReceiveVoiceCommandCalled = false;

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

MOCK_CLASS(MockProtocolActivatedEventArgs,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IProtocolActivatedEventArgs, IActivatedEventArgs> {

               // Claim to be the implementation for the real system RuntimeClass for ProtocolActivatedEventArgs.
               InspectableClass(RuntimeClass_Windows_ApplicationModel_Activation_ProtocolActivatedEventArgs, BaseTrust);

           public:
               MOCK_STDCALL_METHOD_1(get_Uri);
               MOCK_STDCALL_METHOD_1(get_Kind);
               MOCK_STDCALL_METHOD_1(get_PreviousExecutionState);
               MOCK_STDCALL_METHOD_1(get_SplashScreen);
           });

// Delegate for testing Cortana foreground activation
// Use text value to guarantee it is the same argument we create
@interface CortanaForegroundTestDelegate : NSObject <UIApplicationDelegate>
@end

@implementation CortanaForegroundTestDelegate
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

// Create method in UIApplication to swizzle setDelegate: so we can use our delegate for testing
@interface UIApplication (CortanaForegroundTest)
- (void)swizzleDelegate:(id)delegateAddr;
@end

@implementation UIApplication (CortanaForegroundTest)
- (void)swizzleDelegate:(id)delegateAddr {
    [self swizzleDelegate:[CortanaForegroundTestDelegate new]];
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
    Method swizzledMethod = class_getInstanceMethod([UIApplication class], @selector(swizzleDelegate:));
    method_exchangeImplementations(originalMethod, swizzledMethod);

    // Pass activation argument to method which activates the app
    auto args = fakeVoiceCommandActivatedEventArgs.Detach();
    UIApplicationActivationTest(reinterpret_cast<IInspectable*>(args));

	// Un-Swizzle the methods now that we are done
    method_exchangeImplementations(originalMethod, swizzledMethod);
}

TEST(CortanaTest, DelegateMethodsCalled) {
    ASSERT_TRUE(willFinishLaunchingWithOptionsCalled);
    ASSERT_TRUE(didFinishLaunchingWithOptionsCalled);
    ASSERT_TRUE(didReceiveVoiceCommandCalled);
}