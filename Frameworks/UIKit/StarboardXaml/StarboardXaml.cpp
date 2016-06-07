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
// clang-format does not seem to like C++/CX
// clang-format off

#include "ApplicationMain.h"
#include "LayerRegistration.h"
#include "StringConversion.h"

#include "ApplicationCompositor.h"
#include "XamlCompositor.h"
#include "StringHelpers.h"
#include <LoggingNative.h>
#include <UIKit\UIKitExport.h>
#include "StarboardXaml.h"
#include "..\UIApplicationMainInternal.h"

using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI;
using namespace Windows::System;

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

void App::InitializeComponent() {
}

void App::Connect(int connectionId, Platform::Object^ target) {
}

void App::OnLaunched(LaunchActivatedEventArgs^ args) {
    if (args->PrelaunchActivated) {
        // Opt out of prelaunch for now. MSDN guidance is to check the flag and just return.
        return;
    }

    if ((args->PreviousExecutionState == ApplicationExecutionState::Running) ||
        (args->PreviousExecutionState == ApplicationExecutionState::Suspended)) {
        // Skip re-initializing as the app is being resumed from memory.
        return;
    }

    _ApplicationMainLaunch(ActivationTypeNone, nullptr);
}

void App::OnActivated(IActivatedEventArgs^ args) {
    TraceVerbose(TAG, L"OnActivated event received for %d. Previous app state was %d", args->Kind, args->PreviousExecutionState);

    bool initiateAppLaunch = false;
    if ((args->PreviousExecutionState != ApplicationExecutionState::Running) &&
        (args->PreviousExecutionState != ApplicationExecutionState::Suspended)) {
        TraceVerbose(TAG, L"Initializing application");
        initiateAppLaunch = true;
    }

    if (args->Kind == ActivationKind::ToastNotification) {
        Platform::String^ argsString = safe_cast<ToastNotificationActivatedEventArgs^>(args)->Argument;
        TraceVerbose(TAG, L"Received toast notification with argument - %s", argsString->Data());
        if (initiateAppLaunch) {
            _ApplicationMainLaunch(ActivationTypeToast, argsString);
        }
        UIApplicationMainHandleToastNotificationEvent(Strings::WideToNarrow(argsString->Data()).c_str());
    } else {
        if (initiateAppLaunch) {
            _ApplicationMainLaunch(ActivationTypeNone, nullptr);
        }
    }
}

void App::_ApplicationMainLaunch(ActivationType activationType, Platform::String^ activationArg) {
    _ApplicationLaunch(activationType, activationArg);
    _RegisterEventHandlers();
}

void App::_RegisterEventHandlers() {
    this->Suspending += ref new Xaml::SuspendingEventHandler(this, &App::_OnSuspending);
    this->Resuming += ref new Windows::Foundation::EventHandler<Platform::Object^>(this, &App::_OnResuming);

    // Register for Window Visibility change event.
    // TODO::
    // todo-nithishm-03072016 - Move this out of the Windows Visibility event in future.
    Xaml::Window::Current->VisibilityChanged += ref new Xaml::WindowVisibilityChangedEventHandler(this, &App::_OnAppVisibilityChanged);
    // Register for Application Memory Usage Increase event.
    MemoryManager::AppMemoryUsageIncreased += ref new Windows::Foundation::EventHandler<Platform::Object^>(this, &App::_OnAppMemoryUsageChanged);
}

void App::_OnAppVisibilityChanged(Platform::Object^ sender, Core::VisibilityChangedEventArgs^ args)
{
    TraceVerbose(TAG, L"VisibilityChanged event received - %d", args->Visible);
    UIApplicationMainHandleWindowVisibilityChangeEvent(args->Visible);
}

void App::_OnAppMemoryUsageChanged(Platform::Object^ sender, Platform::Object^ args)
{
    auto level = MemoryManager::AppMemoryUsageLevel;

    TraceVerbose(TAG, L"AppMemoryUsageIncreased event received - %d", level);
    if (level == AppMemoryUsageLevel::High) {
        UIApplicationMainHandleHighMemoryUsageEvent();
    }
}

void App::_OnResuming(Platform::Object^ sender, Platform::Object^ args)
{
    TraceVerbose(TAG, L"Resuming event received");
}

void App::_OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ args)
{
    TraceVerbose(TAG, L"Suspending event received");
}

extern "C" void _ApplicationLaunch(ActivationType activationType, Platform::String^ activationArg) {
    auto uiElem = ref new Xaml::Controls::Grid();
    auto rootFrame = ref new Xaml::Controls::Frame();
    rootFrame->Content = uiElem;

    SetXamlRoot(uiElem);

    Xaml::Window::Current->Content = rootFrame;
    Xaml::Window::Current->Activate();

    auto startupRect = Xaml::Window::Current->Bounds;
    RunApplicationMain(g_principalClassName, g_delegateClassName, startupRect.Width, startupRect.Height, activationType, activationArg);
}

// This is the actual entry point from the app into our framework.
// Note: principalClassName and delegateClassName are actually NSString*s.
UIKIT_EXPORT
int UIApplicationMain(int argc, char* argv[], void* principalClassName, void* delegateClassName) {
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

    // Start our application
    Xaml::Application::Start(
        ref new Xaml::ApplicationInitializationCallback([](Xaml::ApplicationInitializationCallbackParams ^ p) {
            // Simply creating the app will kick off the rest of the launch sequence
            auto app = ref new App();
        }));

    return 0;
}

UIKIT_EXPORT
void UIApplicationMainTest() {
    // Initialize COM on this thread
    ::CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    // Register tracelogging
    TraceRegister();

    _ApplicationLaunch(ActivationTypeNone, nullptr);
}

// clang-format on