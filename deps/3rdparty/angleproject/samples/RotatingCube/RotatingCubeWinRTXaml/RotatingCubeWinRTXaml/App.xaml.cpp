//
// App.xaml.cpp
// Implementation of the App class.
//

#include "pch.h"
#include "DirectXPage.xaml.h"

using namespace RotatingCubeWinRTXaml;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Storage;
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
App::App()
{
	InitializeComponent();
	Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

/// <summary>
/// Invoked when the application is launched normally by the end user.  Other entry points
/// will be used when the application is launched to open a specific file, to display
/// search results, and so forth.
/// </summary>
/// <param name="args">Details about the launch request and process.</param>
void App::OnLaunched(LaunchActivatedEventArgs^ args)
{
	m_directXPage = ref new DirectXPage();

	if (args->PreviousExecutionState == ApplicationExecutionState::Terminated)
	{
		m_directXPage->LoadInternalState(ApplicationData::Current->LocalSettings->Values);
	}

	// Place the page in the current window and ensure that it is active.
	Window::Current->Content = m_directXPage;
	Window::Current->Activate();
}

/// <summary>
/// Invoked when the application is being suspended.
/// </summary>
/// <param name="sender">Details about the origin of the event.</param>
/// <param name="args">Details about the suspending event.</param>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ args)
{
	(void) sender; // Unused parameter.
	(void) args; // Unused parameter.

	m_directXPage->SaveInternalState(ApplicationData::Current->LocalSettings->Values);
}