//
// DirectXPage.xaml.cpp
// Implementation of the DirectXPage.xaml class.
//

#include "pch.h"
#include "DirectXPage.xaml.h"

using namespace RotatingCubeWinRTXaml;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Display;
using namespace Windows::UI::Input;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

DirectXPage::DirectXPage() :
	m_renderNeeded(true),
	m_lastPointValid(false)
{
	InitializeComponent();

	m_renderer = ref new CubeRenderer();

	m_renderer->Initialize(
		Window::Current->CoreWindow,
		SwapChainPanel,
		DisplayProperties::LogicalDpi
		);

	Window::Current->CoreWindow->SizeChanged += 
		ref new TypedEventHandler<CoreWindow^, WindowSizeChangedEventArgs^>(this, &DirectXPage::OnWindowSizeChanged);

	DisplayProperties::LogicalDpiChanged +=
		ref new DisplayPropertiesEventHandler(this, &DirectXPage::OnLogicalDpiChanged);

	DisplayProperties::OrientationChanged +=
        ref new DisplayPropertiesEventHandler(this, &DirectXPage::OnOrientationChanged);

	DisplayProperties::DisplayContentsInvalidated +=
		ref new DisplayPropertiesEventHandler(this, &DirectXPage::OnDisplayContentsInvalidated);
	
	m_eventToken = CompositionTarget::Rendering::add(ref new EventHandler<Object^>(this, &DirectXPage::OnRendering));

	m_timer = ref new BasicTimer();
}


void DirectXPage::OnPointerMoved(Object^ sender, PointerRoutedEventArgs^ args)
{
	auto currentPoint = args->GetCurrentPoint(nullptr);
	if (currentPoint->IsInContact)
	{
		if (m_lastPointValid)
		{
			Windows::Foundation::Point delta(
				currentPoint->Position.X - m_lastPoint.X,
				currentPoint->Position.Y - m_lastPoint.Y
				);
			//m_renderer->UpdatePosition(delta);
			m_renderNeeded = true;
		}
		m_lastPoint = currentPoint->Position;
		m_lastPointValid = true;
	}
	else
	{
		m_lastPointValid = false;
	}
}

void DirectXPage::OnPointerReleased(Object^ sender, PointerRoutedEventArgs^ args)
{
	m_lastPointValid = false;
}

void DirectXPage::OnWindowSizeChanged(CoreWindow^ sender, WindowSizeChangedEventArgs^ args)
{
	m_renderer->UpdateForWindowSizeChange();
	m_renderNeeded = true;
}

void DirectXPage::OnLogicalDpiChanged(Object^ sender)
{
	m_renderer->SetDpi(DisplayProperties::LogicalDpi);
	m_renderNeeded = true;
}

void DirectXPage::OnOrientationChanged(Object^ sender)
{
	m_renderer->UpdateForWindowSizeChange();
	m_renderNeeded = true;
}

void DirectXPage::OnDisplayContentsInvalidated(Object^ sender)
{
	m_renderer->ValidateDevice();
	m_renderNeeded = true;
}

void DirectXPage::OnRendering(Object^ sender, Object^ args)
{
	if (m_renderNeeded)
	{
		m_timer->Update();
		m_renderer->Update(m_timer->Total, m_timer->Delta);
		m_renderer->Render();
		m_renderer->Present();
		m_renderNeeded = true;
	}
}

void DirectXPage::OnPreviousColorPressed(Object^ sender, RoutedEventArgs^ args)
{
	m_renderer->BackgroundColorPrevious();
	m_renderNeeded = true;
}

void DirectXPage::OnNextColorPressed(Object^ sender, RoutedEventArgs^ args)
{
	m_renderer->BackgroundColorNext();
	m_renderNeeded = true;
}

void DirectXPage::SaveInternalState(IPropertySet^ state)
{
	//m_renderer->SaveInternalState(state);
}

void DirectXPage::LoadInternalState(IPropertySet^ state)
{
	//m_renderer->LoadInternalState(state);
}
