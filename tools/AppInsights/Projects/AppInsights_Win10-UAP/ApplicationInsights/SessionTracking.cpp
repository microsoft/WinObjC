#include "SessionTracking.h"

#include <Windows.Foundation.Collections.h>

using namespace ApplicationInsights::CX;
using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::Foundation;
using namespace Windows::Storage;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;

const int RENEW_TIMESPAN_IN_SECONDS = 20;
const int CONVERSION_FOR_100_NANOSECOND_UNITS_IN_A_SECOND = 10000 * 1000;

/// <summary>
/// Initializes a new instance of the <see cref="SessionTracking"/> class.
/// </summary>
SessionTracking::SessionTracking()
{
}

/// <summary>
/// Initializes the specified application.
/// </summary>
/// <param name="application">The application.</param>
/// <param name="frame">The frame.</param>
/// <param name="iKey">The iKey.</param>
void SessionTracking::Initialize(Windows::UI::Xaml::Application^ application, Windows::UI::Xaml::Controls::Frame^ frame, Platform::String^ iKey)
{	
	if (iKey == nullptr || application == nullptr)
	{
		
		if (iKey == nullptr)
		{
			m_tc = nullptr;
			OutputDebugString(L"\n\nAPPLICATION INSIGHTS:\nNULL pointer was provided for iKey.  Please set assign value to your iKey from your Azure application.\nSee http://azure.microsoft.com/documentation/articles/app-insights-get-started/ for more information.\n\n");
		}

		if (application == nullptr)
		{
			m_tc = ref new TelemetryClient(iKey);
			OutputDebugString(L"\n\nAPPLICATION INSIGHTS:\nNULL pointer was provided for application.\n\n");
		}
	}
	else if (frame == nullptr)
	{
		m_tc = ref new TelemetryClient(iKey);
		OutputDebugString(L"\n\nAPPLICATION INSIGHTS:\nNULL pointer was provided for frame.  Please call Initialize after frame has been created.\n\n");
	}
	else
	{
		m_app = application;
		m_iKey = iKey;

		application->Suspending += ref new SuspendingEventHandler(this, &SessionTracking::OnSuspending);
		application->Resuming += ref new EventHandler<Platform::Object^>(this, &SessionTracking::OnResume);

		m_page = ref new PageTracking();
		m_page->Initialize(frame, iKey);

		m_tc = ref new TelemetryClient(iKey);

		//Send start session
		m_tc->TrackSessionStart();
		m_tc->Flush();
	}
}

/// <summary>
/// Called when [suspending].
/// </summary>
/// <param name="sender">The sender.</param>
/// <param name="e">The e.</param>
void SessionTracking::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
	if (m_tc != nullptr)
	{
		ApplicationDataContainer^ localSettings = ApplicationData::Current->LocalSettings;
		ApplicationDataContainer^ container = localSettings->CreateContainer("AppInsights", ApplicationDataCreateDisposition::Always);
		auto values = localSettings->Containers->Lookup("AppInsights")->Values;
		Windows::Globalization::Calendar^ cal = ref new Windows::Globalization::Calendar();
		Windows::Foundation::DateTime dateToFormat = cal->GetDateTime();

		values->Insert("lastBackground", PropertyValue::CreateDateTime(dateToFormat));

		m_tc->Flush();
	}
}

/// <summary>
/// Called when [resume].
/// </summary>
/// <param name="sender">The sender.</param>
/// <param name="e">The e.</param>
void SessionTracking::OnResume(Object^ sender, Platform::Object^ e)
{
	if (m_tc != nullptr)
	{
		ApplicationDataContainer^ localSettings = ApplicationData::Current->LocalSettings;
		ApplicationDataContainer^ container = localSettings->CreateContainer("AppInsights", ApplicationDataCreateDisposition::Always);
		auto values = localSettings->Containers->Lookup("AppInsights")->Values;

		Windows::Globalization::Calendar^ cal = ref new Windows::Globalization::Calendar();
		Windows::Foundation::DateTime now = cal->GetDateTime();

		if (values->HasKey("lastBackground"))
		{
			DateTime lastBackground = (DateTime)values->Lookup("lastBackground");

			if ((now.UniversalTime - lastBackground.UniversalTime) > RENEW_TIMESPAN_IN_SECONDS * CONVERSION_FOR_100_NANOSECOND_UNITS_IN_A_SECOND)
			{
				//Renew session
				m_tc->RenewSession();

				//Send start session
				m_tc->TrackSessionStart();
				m_tc->Flush();
			}
		}
	}
}
