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

MOCK_CLASS(MockSpeechRecognitionResult,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ISpeechRecognitionResult, ISpeechRecognitionResult2> {
               InspectableClass(RuntimeClass_Windows_Media_SpeechRecognition_SpeechRecognitionResult,
                                BaseTrust); // claim to be the implementation for the real system RuntimeClass for SpeechRecognitionResult.

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

MOCK_CLASS(
    MockVoiceCommandActivatedEventArgs,
    public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IVoiceCommandActivatedEventArgs, IActivatedEventArgs> {
        InspectableClass(RuntimeClass_Windows_ApplicationModel_Activation_VoiceCommandActivatedEventArgs,
                         BaseTrust); // claim to be the implementation for the real system RuntimeClass for VoiceCommandActivatedEventArgs.

    public:
        MOCK_STDCALL_METHOD_1(get_Result);
        MOCK_STDCALL_METHOD_1(get_Kind);
        MOCK_STDCALL_METHOD_1(get_PreviousExecutionState);
        MOCK_STDCALL_METHOD_1(get_SplashScreen);
    });

MOCK_CLASS(MockProtocolActivatedEventArgs,
           public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, IProtocolActivatedEventArgs, IActivatedEventArgs> {
               InspectableClass(RuntimeClass_Windows_ApplicationModel_Activation_ProtocolActivatedEventArgs,
                                BaseTrust); // claim to be the implementation for the real system RuntimeClass for Accel.

           public:
               MOCK_STDCALL_METHOD_1(get_Uri);
               MOCK_STDCALL_METHOD_1(get_Kind);
               MOCK_STDCALL_METHOD_1(get_PreviousExecutionState);
               MOCK_STDCALL_METHOD_1(get_SplashScreen);
           });

// TODO: 8008558 Test handling foreground activation parameters from Cortana
TEST(CortanaTest, VoiceCommandForegroundActivation) {
    LOG_INFO("CortanaTest Voice Command Foreground Activation Test: ");
    // Get current application to test on
    WXApplication* app = [WXApplication current];
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
}