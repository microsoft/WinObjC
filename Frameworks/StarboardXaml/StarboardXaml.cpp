//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "LayerRegistration.h"
#include "StringConversion.h"

#include "winobjc\winobjc.h"
#include "LoggingNative.h"

using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI;
using namespace Windows::System;

static Platform::String^ g_principalClassName;
static Platform::String^ g_delegateClassName;

static const wchar_t* TAG = L"StarboardXaml";

ref class App : public Xaml::Application, Xaml::Markup::IXamlMetadataProvider {
    XamlTypeInfo::InfoProvider::XamlTypeInfoProvider ^ _provider;

public:
    virtual Xaml::Markup::IXamlType^ GetXamlType(Xaml::Interop::TypeName type) {
        if (!_provider) {
            _provider = ref new XamlTypeInfo::InfoProvider::XamlTypeInfoProvider();
        }

        return _provider->GetXamlTypeByType(type);
    }

    virtual Xaml::Markup::IXamlType^ GetXamlType(Platform::String^ fullName) {
        if (!_provider) {
            _provider = ref new XamlTypeInfo::InfoProvider::XamlTypeInfoProvider();
        }

        return _provider->GetXamlTypeByName(fullName);
    }

    virtual Platform::Array<Xaml::Markup::XmlnsDefinition>^ GetXmlnsDefinitions() {
        return ref new Platform::Array<Xaml::Markup::XmlnsDefinition>(0);
    }

    void InitializeComponent() {
    }

    void Connect(int connectionId, Platform::Object^ target) {
    }

    void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e) override {
        if (e->PrelaunchActivated) {
            // Opt out of prelaunch for now. MSDN guidance is to check the flag and just return.
            return;
        }

        if ((e->PreviousExecutionState == ApplicationExecutionState::Running) ||
            (e->PreviousExecutionState == ApplicationExecutionState::Suspended)) {
            // Skip re-initializing as the app is being resumed from memory.
            return;
        }

        auto uiElem = ref new Xaml::Controls::Grid();
        auto rootFrame = ref new Xaml::Controls::Frame();
        rootFrame->Content = uiElem;

        IWSetXamlRoot(uiElem);

        Xaml::Window::Current->Content = rootFrame;
        Xaml::Window::Current->Activate();

        auto startupRect = Xaml::Window::Current->Bounds;
        IWRunApplicationMain(g_principalClassName, g_delegateClassName, startupRect.Width, startupRect.Height);

        _RegisterEventHandlers();
    }

private:
    void _RegisterEventHandlers() {
        // Register for Window Visibility change event.
        // TODO::
        // todo-nithishm-03072016 - Move this out of the Windows Visibility event in future.
        Xaml::Window::Current->VisibilityChanged += ref new Xaml::WindowVisibilityChangedEventHandler(this, &App::_OnAppVisibilityChanged);
        // Register for Application Memory Usage Increase event.
        MemoryManager::AppMemoryUsageIncreased += ref new Windows::Foundation::EventHandler<Platform::Object^>(this, &App::_OnAppMemoryUsageChanged);
    }

    void _OnAppVisibilityChanged(Platform::Object^ sender, Core::VisibilityChangedEventArgs^ args)
    {
        TraceVerbose(TAG, L"VisibilityChanged event received - %d", args->Visible);
        IWHandleWindowVisibilityChangeEvent(args->Visible);
    }

    void _OnAppMemoryUsageChanged(Platform::Object^ sender, Platform::Object^ args)
    {
        auto level = MemoryManager::AppMemoryUsageLevel;

        TraceVerbose(TAG, L"AppMemoryUsageIncreased event received - %d", level);
        if (level == AppMemoryUsageLevel::High) {
            IWHandleHighMemoryUsageEvent();
        }
    }
};

// This is the actual entry point from the app into our framework.
// Note: principalClassName and delegateClassName are actually NSString*s.
extern "C" __declspec(dllexport) int UIApplicationMain(int argc, char* argv[], void* principalClassName, void* delegateClassName) {
    // Initialize COM on this thread
    ::CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    // Register tracelogging
    TraceRegister();

    // Copy the principal and delegate class names into our globals
    if (principalClassName) {
        uint32_t len = 0;
        auto rawString = _RawBufferFromNSString(principalClassName, &len);
        g_principalClassName = ref new Platform::String(rawString, len);
    }

    if (delegateClassName) {
        uint32_t len = 0;
        auto rawString = _RawBufferFromNSString(delegateClassName, &len);
        g_delegateClassName = ref new Platform::String(rawString, len);
    }

    // Start our application
    Xaml::Application::Start(
        ref new Xaml::ApplicationInitializationCallback([](Xaml::ApplicationInitializationCallbackParams ^ p) {
            // Simply creating the app will kick off the rest of the launch sequence
            auto app = ref new App();
        }));

    return 0;
}

// clang-format on