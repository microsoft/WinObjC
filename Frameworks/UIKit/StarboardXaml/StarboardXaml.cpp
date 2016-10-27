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

#include "ApplicationMain.h"
#include "LayerRegistration.h"
#include "StringConversion.h"
#include "Windows.UI.Xaml.h"

#include "ApplicationCompositor.h"
#include "XamlCompositor.h"
#include "StringHelpers.h"
#include <LoggingNative.h>
#include <UIKit\UIKitExport.h>
#include "StarboardXaml.h"
#include "..\UIApplicationMainInternal.h"
#include "UWPBackgroundTask.h"
#include "ppltasks.h"

using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Media::SpeechRecognition;
using namespace Windows::Foundation;
using namespace Windows::UI;
using namespace Windows::System;
using namespace Windows::UI::Core;
using namespace Windows::ApplicationModel::Core;

static Platform::String^ g_principalClassName;
static Platform::String^ g_delegateClassName;

static const wchar_t* TAG = L"StarboardXaml";

Xaml::Markup::IXamlType^ App::GetXamlType(Xaml::Interop::TypeName type) {
    if (!_provider) {
        _provider = ref new XamlTypeInfo::InfoProvider::XamlTypeInfoProvider();
    }

    return _provider->GetXamlTypeByType(type);
}

Xaml::Markup::IXamlType^ App::GetXamlType(Platform::String^ fullName) {
    if (!_provider) {
        _provider = ref new XamlTypeInfo::InfoProvider::XamlTypeInfoProvider();
    }

    return _provider->GetXamlTypeByName(fullName);
}

Platform::Array<Xaml::Markup::XmlnsDefinition>^ App::GetXmlnsDefinitions() {
    return ref new Platform::Array<Xaml::Markup::XmlnsDefinition>(0);
}

void AppEventListener::_RegisterEventHandlers() {
    Windows::UI::Xaml::Application::Current->Suspending +=
        ref new Xaml::SuspendingEventHandler(this, &AppEventListener::_OnSuspending);
    Windows::UI::Xaml::Application::Current->Resuming +=
        ref new Windows::Foundation::EventHandler<Platform::Object^>(this, &AppEventListener::_OnResuming);

#ifdef ENABLE_BACKGROUND_TASK
    Windows::UI::Xaml::Application::Current->EnteredBackground +=
        ref new Xaml::EnteredBackgroundEventHandler(this, &AppEventListener::_OnEnteredBackground);
    Windows::UI::Xaml::Application::Current->LeavingBackground +=
        ref new Xaml::LeavingBackgroundEventHandler(this, &AppEventListener::_OnLeavingBackground);
#else
    // Register for Window Visibility change event.
    // TODO: Move this out of the Windows Visibility event in future
    Xaml::Window::Current->VisibilityChanged +=
        ref new Xaml::WindowVisibilityChangedEventHandler(this, &AppEventListener::_OnAppVisibilityChanged);
#endif

    // Register for Application Memory Usage Increase event.
    MemoryManager::AppMemoryUsageIncreased +=
        ref new Windows::Foundation::EventHandler<Platform::Object^>(this, &AppEventListener::_OnAppMemoryUsageChanged);
}

void AppEventListener::_OnAppVisibilityChanged(Platform::Object^ sender, Core::VisibilityChangedEventArgs^ args)
{
    TraceVerbose(TAG, L"VisibilityChanged event received - %d", args->Visible);
    UIApplicationMainHandleWindowVisibilityChangeEvent(args->Visible);
}

void AppEventListener::_OnAppMemoryUsageChanged(Platform::Object^ sender, Platform::Object^ args)
{
    auto level = MemoryManager::AppMemoryUsageLevel;

    TraceVerbose(TAG, L"AppMemoryUsageIncreased event received - %d", level);
    if (level == AppMemoryUsageLevel::High) {
        UIApplicationMainHandleHighMemoryUsageEvent();
    }
}

void AppEventListener::_OnResuming(Platform::Object^ sender, Platform::Object^ args)
{
    TraceVerbose(TAG, L"Resuming event received");
    UIApplicationMainHandleResumeEvent();
}

void AppEventListener::_OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ args)
{
    TraceVerbose(TAG, L"Suspending event received");
    Windows::ApplicationModel::SuspendingDeferral^ deferral = args->SuspendingOperation->GetDeferral();

    // TODO: revisit this if new event tells us we are entering background (for deferred suspend)
    UIApplicationMainHandleSuspendEvent();
    deferral->Complete();
}

#ifdef ENABLE_BACKGROUND_TASK
void AppEventListener::_OnEnteredBackground(Platform::Object^ sender, Windows::ApplicationModel::EnteredBackgroundEventArgs^ args)
{
    TraceVerbose(TAG, L"EnteredBackground event received");
    _enteredBackgroundEventDeferral = args->GetDeferral();
    UIApplicationMainHandlePLMEvent(false);
    _enteredBackgroundEventDeferral->Complete();
    _enteredBackgroundEventDeferral = nullptr;
}

void AppEventListener::_OnLeavingBackground(Platform::Object^ sender, Windows::ApplicationModel::LeavingBackgroundEventArgs^ args)
{
    TraceVerbose(TAG, L"LeavingBackground event received");
    UIApplicationMainHandlePLMEvent(true);
}

void AppEventListener::_OnBackgroundTaskCancelled(
    Windows::ApplicationModel::Background::IBackgroundTaskInstance^ taskInstance,
    Windows::ApplicationModel::Background::BackgroundTaskCancellationReason reason)
{
    TraceVerbose(TAG, L"Background task cancelled called for task %s", taskInstance->Task->Name->Data());
    if (wcscmp(taskInstance->Task->Name->Data(), c_backgroundTaskName) == 0) {
        TraceVerbose(TAG, L"Background task cancelled called for ApplicationTrigger task due to reason %ld", reason);
        _applicationTriggerDeferral->Complete();
        _applicationTriggerDeferral = nullptr;
        taskInstance->Task->Unregister(true);
    }
}
#endif

static AppEventListener ^_appEvents;

void App::InitializeComponent() {
}

void App::Connect(int connectionId, Platform::Object^ target) {
}

void App::OnLaunched(LaunchActivatedEventArgs^ args) {
    UIApplicationLaunched(args);
}

void App::OnActivated(IActivatedEventArgs^ args) {
    UIApplicationActivated(args);
}

void App::OnFileActivated(FileActivatedEventArgs^ args)
{
    UIApplicationActivated(args);
}

#ifdef ENABLE_BACKGROUND_TASK
void App::OnBackgroundActivated(BackgroundActivatedEventArgs^ args) {
    __super::OnBackgroundActivated(args);
    UIApplicationBackgroundActivated(args);
}
#endif

extern "C"
void UIApplicationLaunched(LaunchActivatedEventArgs^ args) {
    TraceVerbose(TAG, L"OnLaunched event received for %d. Previous app state was %d", args->Kind, args->PreviousExecutionState);
    // Opt out of prelaunch for now. MSDN guidance is to check the flag and just return.
    // Or skip re-initializing as the app is being resumed from memory.
    bool initiateAppLaunch = (!(args->PrelaunchActivated)
                                && (args->PreviousExecutionState != ApplicationExecutionState::Running)
                                && (args->PreviousExecutionState != ApplicationExecutionState::Suspended));

    if (initiateAppLaunch) {
        TraceVerbose(TAG, L"Initializing application");
        _ApplicationLaunch(ActivationTypeNone, args);
    }
}

extern "C"
void UIApplicationActivated(IActivatedEventArgs^ args) {
    TraceVerbose(TAG, L"OnActivated event received for %d. Previous app state was %d", args->Kind, args->PreviousExecutionState);
    bool initiateAppLaunch = false;
    if ((args->PreviousExecutionState != ApplicationExecutionState::Running) &&
        (args->PreviousExecutionState != ApplicationExecutionState::Suspended)) {
        TraceVerbose(TAG, L"Initializing application");
        initiateAppLaunch = true;
    }

    if (args->Kind == ActivationKind::ToastNotification) {
        ToastNotificationActivatedEventArgs^ toastArgs = safe_cast<ToastNotificationActivatedEventArgs^>(args);
        TraceVerbose(TAG, L"Received toast notification with argument - %ls", toastArgs->Argument->Data());

        if (initiateAppLaunch) {
            _ApplicationLaunch(ActivationTypeToast, toastArgs);
        }

        UIApplicationMainHandleToastActionEvent(reinterpret_cast<HSTRING>(toastArgs->Argument),
            reinterpret_cast<IInspectable*>(toastArgs->UserInput));

    } else if (args->Kind == ActivationKind::VoiceCommand) {
        SpeechRecognitionResult^ result = safe_cast<VoiceCommandActivatedEventArgs^>(args)->Result;
        TraceVerbose(TAG, L"Received voice command with argument - %ls", result->Text->Data());

        if (initiateAppLaunch) {
            _ApplicationLaunch(ActivationTypeVoiceCommand, result);
        }

        UIApplicationMainHandleVoiceCommandEvent(reinterpret_cast<IInspectable*>(result));

    } else if (args->Kind == ActivationKind::Protocol) {
        ProtocolActivatedEventArgs^ protocolArgs = safe_cast<ProtocolActivatedEventArgs^>(args);
        Windows::Foundation::Uri^ argUri = protocolArgs->Uri;
        const wchar_t* caller = protocolArgs->CallerPackageFamilyName->Data();
        TraceVerbose(TAG, L"Received protocol with uri- %s from %s", argUri->ToString()->Data(), caller);

        if (initiateAppLaunch) {
            _ApplicationLaunch(ActivationTypeProtocol, argUri);
        }

        UIApplicationMainHandleProtocolEvent(reinterpret_cast<IInspectable*>(argUri), caller);
    } else if (args->Kind == ActivationKind::File) {
        FileActivatedEventArgs^ result = safe_cast<FileActivatedEventArgs^>(args);
        TraceVerbose(TAG, L"Received file activation");

        if (initiateAppLaunch) {
            _ApplicationLaunch(ActivationTypeFile, result);
        }

        UIApplicationMainHandleFileEvent(reinterpret_cast<IInspectable*>(result));
    } else {
        TraceWarning(TAG, L"Received unhandled activation kind - %d", args->Kind);

        if (initiateAppLaunch) {
            _ApplicationLaunch(ActivationTypeNone, nullptr);
        }
    }
}

#ifdef ENABLE_BACKGROUND_TASK
extern "C"
void UIApplicationBackgroundActivated(BackgroundActivatedEventArgs^ args) {
    TraceVerbose(TAG, L"OnBackgroundActivated called for task %s", args->TaskInstance->Task->Name->Data());

    if (wcscmp(args->TaskInstance->Task->Name->Data(), c_backgroundTaskName) == 0) {
        TraceVerbose(TAG, L"OnBackgroundActivated called for ApplicationTrigger task.");
        FAIL_FAST_IF(_appEvents->_applicationTriggerDeferral != nullptr);
        _appEvents->_applicationTriggerDeferral = args->TaskInstance->GetDeferral();
    }

    args->TaskInstance->Canceled +=
        ref new Windows::ApplicationModel::Background::BackgroundTaskCanceledEventHandler(_appEvents,
            &AppEventListener::_OnBackgroundTaskCancelled);
}
#endif

void DoApplicationLaunch(ActivationType activationType, Platform::Object^ activationArg) {
    auto uiElem = ref new Xaml::Controls::Grid();
    auto rootFrame = ref new Xaml::Controls::Frame();
    rootFrame->Content = uiElem;

    SetXamlRoot(uiElem, activationType);

    if (activationType != ActivationTypeLibrary) {
        Xaml::Window::Current->Content = rootFrame;
        Xaml::Window::Current->Activate();
    }

    auto startupRect = Xaml::Window::Current->Bounds;
    RunApplicationMain(g_principalClassName, g_delegateClassName, startupRect.Width, startupRect.Height, activationType, activationArg);

    _appEvents = ref new AppEventListener();
    _appEvents->_RegisterEventHandlers();
}

void _ApplicationLaunch(ActivationType activationType, Platform::Object^ activationArg) {
    auto coreWindow = CoreWindow::GetForCurrentThread();
    if (coreWindow == nullptr) {
        CoreDispatcher^ c = CoreApplication::MainView->Dispatcher;
        auto task = concurrency::create_task(c->RunAsync(Windows::UI::Core::CoreDispatcherPriority::Normal, ref new Windows::UI::Core::DispatchedHandler([=]()
        {
            DoApplicationLaunch(activationType, activationArg);
        })));
        task.wait();
    } else {
        DoApplicationLaunch(activationType, activationArg);
    }
}

// This is the actual entry point from the app into our framework.
// Note: principalClassName and delegateClassName are actually NSString*s.
UIKIT_EXPORT
int UIApplicationMain(int argc, char* argv[], void* principalClassName, void* delegateClassName) {
    // Make method only run once
    static int once = [principalClassName, delegateClassName] () -> int {

        // Initialize COM on this thread
        ::CoInitializeEx(nullptr, COINIT_MULTITHREADED);

        // Register tracelogging
        TraceRegister();

        // Copy the principal and delegate class names into our globals
        if (principalClassName) {
            auto rawString = _RawBufferFromNSString(principalClassName);
            g_principalClassName = reinterpret_cast<Platform::String^>(Strings::NarrowToWide<HSTRING>(rawString).Detach());
        }

        if (delegateClassName) {
            auto rawString = _RawBufferFromNSString(delegateClassName);
            g_delegateClassName = reinterpret_cast<Platform::String^>(Strings::NarrowToWide<HSTRING>(rawString).Detach());
        }

        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IApplicationStatics> appStatics = nullptr;
        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IApplication> currentApplication = nullptr;
        HRESULT hr = RoGetActivationFactory(Platform::StringReference(RuntimeClass_Windows_UI_Xaml_Application).GetHSTRING(),
            ABI::Windows::UI::Xaml::IID_IApplicationStatics,
            reinterpret_cast<void **>(appStatics.GetAddressOf()));

        if (hr == S_OK && appStatics) {
            appStatics->get_Current(currentApplication.GetAddressOf());
        }

        if (currentApplication == nullptr) {
            // Start our application
            Xaml::Application::Start(
                ref new Xaml::ApplicationInitializationCallback([](Xaml::ApplicationInitializationCallbackParams^ p) {
                // Simply creating the app will kick off the rest of the launch sequence
                auto app = ref new App();
            }));
        }
        return 0;
    }();
    return once;
}

// This is the initialization function for non-Islandwood apps that intend to call into Islandwood:
// test executables and general WinRT apps that want to call Islandwood libraries
UIKIT_EXPORT
void UIApplicationInitialize(const wchar_t* principalClassName, const wchar_t* delegateClassName) {
    // Register tracelogging
    TraceRegister();

    if (principalClassName != nullptr) {
        g_principalClassName = ref new Platform::String(principalClassName);
    } else {
        g_principalClassName = ref new Platform::String();
    }

    if (delegateClassName != nullptr) {
        g_delegateClassName = ref new Platform::String(delegateClassName);
    } else {
        g_delegateClassName = ref new Platform::String();
    }

    _ApplicationLaunch(ActivationTypeLibrary, nullptr);
}

// Note: Like UIApplicationMain, delegateClassName is actually an NSString*.
UIKIT_EXPORT
void UIApplicationActivationTest(IInspectable* activationArgs, void* delegateClassName){
    // Initialize COM on this thread
    ::CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    // Register tracelogging
    TraceRegister();

    if (delegateClassName) {
        auto rawString = _RawBufferFromNSString(delegateClassName);
        g_delegateClassName = reinterpret_cast<Platform::String^>(Strings::NarrowToWide<HSTRING>(rawString).Detach());
    } else {
        g_delegateClassName = ref new Platform::String();
    }

    UIApplicationActivated(static_cast<IActivatedEventArgs^>(reinterpret_cast<Platform::Object^>(activationArgs)));
}

// clang-format on
