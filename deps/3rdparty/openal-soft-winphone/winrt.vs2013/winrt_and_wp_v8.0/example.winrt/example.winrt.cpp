#include "pch.h"
#include "example.winrt.h"
#include "BasicTimer.h"

using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Core;
using namespace Windows::System;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;
using namespace concurrency;

example_winrt::example_winrt() :
	m_windowClosed(false),
	m_windowVisible(true)
{
}

void example_winrt::Initialize(CoreApplicationView^ applicationView)
{
	applicationView->Activated +=
        ref new TypedEventHandler<CoreApplicationView^, IActivatedEventArgs^>(this, &example_winrt::OnActivated);

	CoreApplication::Suspending +=
        ref new EventHandler<SuspendingEventArgs^>(this, &example_winrt::OnSuspending);

	CoreApplication::Resuming +=
        ref new EventHandler<Platform::Object^>(this, &example_winrt::OnResuming);

	m_renderer = ref new CubeRenderer();
}

void example_winrt::SetWindow(CoreWindow^ window)
{
	window->SizeChanged += 
        ref new TypedEventHandler<CoreWindow^, WindowSizeChangedEventArgs^>(this, &example_winrt::OnWindowSizeChanged);

	window->VisibilityChanged +=
		ref new TypedEventHandler<CoreWindow^, VisibilityChangedEventArgs^>(this, &example_winrt::OnVisibilityChanged);

	window->Closed += 
        ref new TypedEventHandler<CoreWindow^, CoreWindowEventArgs^>(this, &example_winrt::OnWindowClosed);

	window->PointerCursor = ref new CoreCursor(CoreCursorType::Arrow, 0);

	window->PointerPressed +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &example_winrt::OnPointerPressed);

	window->PointerMoved +=
		ref new TypedEventHandler<CoreWindow^, PointerEventArgs^>(this, &example_winrt::OnPointerMoved);

	m_renderer->Initialize(CoreWindow::GetForCurrentThread());
}

void example_winrt::Load(Platform::String^ entryPoint)
{
}

void example_winrt::Run()
{
	BasicTimer^ timer = ref new BasicTimer();

	while (!m_windowClosed)
	{
		if (m_windowVisible)
		{
			timer->Update();
			CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessAllIfPresent);
			m_renderer->Update(timer->Total, timer->Delta);
			m_renderer->Render();
			m_renderer->Present(); // This call is synchronized to the display frame rate.
		}
		else
		{
			CoreWindow::GetForCurrentThread()->Dispatcher->ProcessEvents(CoreProcessEventsOption::ProcessOneAndAllPending);
		}
	}
}

void example_winrt::Uninitialize()
{
}

void example_winrt::OnWindowSizeChanged(CoreWindow^ sender, WindowSizeChangedEventArgs^ args)
{
	m_renderer->UpdateForWindowSizeChange();
}

void example_winrt::OnVisibilityChanged(CoreWindow^ sender, VisibilityChangedEventArgs^ args)
{
	m_windowVisible = args->Visible;
}

void example_winrt::OnWindowClosed(CoreWindow^ sender, CoreWindowEventArgs^ args)
{
	m_windowClosed = true;
}

void example_winrt::OnPointerPressed(CoreWindow^ sender, PointerEventArgs^ args)
{
	// Insert your code here.
}

void example_winrt::OnPointerMoved(CoreWindow^ sender, PointerEventArgs^ args)
{
	// Insert your code here.
}

void example_winrt::OnActivated(CoreApplicationView^ applicationView, IActivatedEventArgs^ args)
{
	CoreWindow::GetForCurrentThread()->Activate();
}

void example_winrt::OnSuspending(Platform::Object^ sender, SuspendingEventArgs^ args)
{
	// Save app state asynchronously after requesting a deferral. Holding a deferral
	// indicates that the application is busy performing suspending operations. Be
	// aware that a deferral may not be held indefinitely. After about five seconds,
	// the app will be forced to exit.
	SuspendingDeferral^ deferral = args->SuspendingOperation->GetDeferral();

	create_task([this, deferral]()
	{
		// Insert your code here.

		deferral->Complete();
	});
}
 
void example_winrt::OnResuming(Platform::Object^ sender, Platform::Object^ args)
{
	// Restore any data or state that was unloaded on suspend. By default, data
	// and state are persisted when resuming from suspend. Note that this event
	// does not occur if the app was previously terminated.
}

IFrameworkView^ Direct3DApplicationSource::CreateView()
{
    return ref new example_winrt();
}

[Platform::MTAThread]
int main(Platform::Array<Platform::String^>^)
{
	auto direct3DApplicationSource = ref new Direct3DApplicationSource();
	CoreApplication::Run(direct3DApplicationSource);
	return 0;
}
