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
// clang-format does not seem to like C++/CX
// clang-format off
#pragma once

typedef enum {
    ActivationTypeNone = 0,
    ActivationTypeToast = 1,
    ActivationTypeVoiceCommand = 2,
    ActivationTypeProtocol = 3,
    ActivationTypeLibrary = 4,
    ActivationTypeFile = 5,
} ActivationType;

#ifdef __cplusplus_winrt

#include <collection.h>

ref class AppEventListener
{
public:
    void _RegisterEventHandlers();

internal:
    Platform::Agile<Windows::ApplicationModel::Background::BackgroundTaskDeferral> _applicationTriggerDeferral;
#ifdef ENABLE_BACKGROUND_TASK
    void _OnBackgroundTaskCancelled(
        Windows::ApplicationModel::Background::IBackgroundTaskInstance^ taskInstance,
        Windows::ApplicationModel::Background::BackgroundTaskCancellationReason reason);
#endif

private:
    void _OnAppVisibilityChanged(Platform::Object^ sender, Windows::UI::Core::VisibilityChangedEventArgs^ args);
    void _OnAppMemoryUsageChanged(Platform::Object^ sender, Platform::Object^ args);
    void _OnResuming(Platform::Object^ sender, Platform::Object^ args);
    void _OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ args);
#ifdef ENABLE_BACKGROUND_TASK
    void _OnEnteredBackground(Platform::Object^ sender, Windows::ApplicationModel::EnteredBackgroundEventArgs^ args);
    void _OnLeavingBackground(Platform::Object^ sender, Windows::ApplicationModel::LeavingBackgroundEventArgs^ args);
#endif

    Windows::Foundation::Deferral^ _enteredBackgroundEventDeferral;
};

extern "C" void UIApplicationActivated(Windows::ApplicationModel::Activation::IActivatedEventArgs^ args);
extern "C" void UIApplicationLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ args);
#ifdef ENABLE_BACKGROUND_TASK
extern "C" void UIApplicationBackgroundActivated(Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs^ args);
#endif
void _ApplicationLaunch(ActivationType activationType, Platform::Object^ activationArg);

#endif

// clang-format on
