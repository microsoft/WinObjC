//
// App.xaml.cpp
// Implementation of the App class.
//

// clang-format off

#include "pch.h"

using namespace HelloOpenGL;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

/// <summary>
/// Initializes the singleton application object.  This is the first line of authored code
/// executed, and as such is the logical equivalent of main() or WinMain().
/// </summary>
App::App() {
    InitializeComponent();
    Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

extern "C" int main(int argc, char* argv[]);
extern "C" void UIApplicationActivated(Windows::ApplicationModel::Activation::IActivatedEventArgs^ e);
extern "C" void UIApplicationLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e);
#ifdef ENABLE_BACKGROUND_TASK
extern "C" void UIApplicationBackgroundActivated(Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs^ e);
#endif

/// <summary>
/// Invoked when the application is launched normally by the end user.  Other entry points
/// will be used such as when the application is launched to open a specific file.
/// </summary>
/// <param name="e">Details about the launch request and process.</param>
void App::OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ e) {
    main(0, NULL);
    UIApplicationLaunched(e);
}

void App::OnActivated(Windows::ApplicationModel::Activation::IActivatedEventArgs^ e) {
    main(0, NULL);
    UIApplicationActivated(e);
}

void App::OnFileActivated(FileActivatedEventArgs^ args)
{
    main(0, NULL);
    UIApplicationActivated(args);
}

#ifdef ENABLE_BACKGROUND_TASK
void App::OnBackgroundActivated(Windows::ApplicationModel::Activation::BackgroundActivatedEventArgs^ e) {
    __super ::OnBackgroundActivated(e);
    UIApplicationBackgroundActivated(e);
}
#endif

/// <summary>
/// Invoked when application execution is being suspended.  Application state is saved
/// without knowing whether the application will be terminated or resumed with the contents
/// of memory still intact.
/// </summary>
/// <param name="sender">The source of the suspend request.</param>
/// <param name="e">Details about the suspend request.</param>
void App::OnSuspending(Object^ /*sender*/, SuspendingEventArgs^ /*e*/) {
    // TODO: Save application state and stop any background activity
}

/// <summary>
/// Invoked when Navigation to a certain page fails
/// </summary>
/// <param name="sender">The Frame which failed navigation</param>
/// <param name="e">Details about the navigation failure</param>
void App::OnNavigationFailed(Platform::Object^ sender, Windows::UI::Xaml::Navigation::NavigationFailedEventArgs^ e) {
    throw ref new FailureException("Failed to load Page " + e->SourcePageType.Name);
}

// clang-format on
