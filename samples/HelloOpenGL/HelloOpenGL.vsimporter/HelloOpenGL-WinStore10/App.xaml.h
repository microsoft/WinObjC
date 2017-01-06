//
// App.xaml.h
// Declaration of the App class.
//

// clang-format off
#pragma once

#include "App.g.h"

namespace HelloOpenGL {
/// <summary>
/// Provides application-specific behavior to supplement the default Application class.
/// </summary>
ref class App sealed {
protected:
    virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e) override;
    virtual void OnActivated(Windows::ApplicationModel::Activation::IActivatedEventArgs^ e) override;
#ifdef ENABLE_BACKGROUND_TASK
    virtual void OnBackgroundActivated(Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs^ e) override;
#endif

    void OnFileActivated(Windows::ApplicationModel::Activation::FileActivatedEventArgs^ args) override;

    internal : App();

private:
    void OnSuspending(Platform::Object ^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);
    void OnNavigationFailed(Platform::Object ^ sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs^ e);
};
}

// clang-format on
