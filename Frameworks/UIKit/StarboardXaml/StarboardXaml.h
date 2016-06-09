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
#pragma once

#ifdef __cplusplus_winrt
#include "LayerRegistration.h"
#endif

typedef enum {
    ActivationTypeNone = 0,
    ActivationTypeToast = 1,
} ActivationType;

#ifdef __cplusplus_winrt

ref class App : public Windows::UI::Xaml::Application, Windows::UI::Xaml::Markup::IXamlMetadataProvider {
public:
    virtual Windows::UI::Xaml::Markup::IXamlType^ GetXamlType(Windows::UI::Xaml::Interop::TypeName type);
    virtual Windows::UI::Xaml::Markup::IXamlType^ GetXamlType(Platform::String^ fullName);
    virtual Platform::Array<Windows::UI::Xaml::Markup::XmlnsDefinition>^ GetXmlnsDefinitions();
    void InitializeComponent();
    void Connect(int connectionId, Platform::Object^ target);
    void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ args) override;
    void OnActivated(Windows::ApplicationModel::Activation::IActivatedEventArgs^ args) override;

private:
    XamlTypeInfo::InfoProvider::XamlTypeInfoProvider^ _provider;

    void _ApplicationMainLaunch(ActivationType activationType, Platform::String^ activationArg);
    void _RegisterEventHandlers();
    void _OnAppVisibilityChanged(Platform::Object^ sender, Windows::UI::Core::VisibilityChangedEventArgs^ args);
    void _OnAppMemoryUsageChanged(Platform::Object^ sender, Platform::Object^ args);
    void _OnResuming(Platform::Object^ sender, Platform::Object^ args);
    void _OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ args);
};

extern "C" void _ApplicationLaunch(ActivationType activationType, Platform::String^ activationArg);

#endif

// clang-format on