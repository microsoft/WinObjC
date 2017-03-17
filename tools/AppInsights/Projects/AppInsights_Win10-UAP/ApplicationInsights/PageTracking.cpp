#include "PageTracking.h"
#include <Windows.Foundation.Collections.h>

using namespace ApplicationInsights::CX;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Storage;

const int CONVERSION_FOR_100_NANOSECOND_UNITS_TO_MILLISECONDS = 10000 ;

/// <summary>
/// Initializes a new instance of the <see cref="PageTracking"/> class.
/// </summary>
PageTracking::PageTracking()
{
}

/// <summary>
/// Finalizes an instance of the <see cref="PageTracking"/> class.
/// </summary>
PageTracking::~PageTracking()
{
	if (m_tc != nullptr)
	{
		m_tc->Flush();
	}
}

/// <summary>
/// Initializes the specified frame.
/// </summary>
/// <param name="frame">The frame.</param>
/// <param name="iKey">The iKey.</param>
void PageTracking::Initialize(Windows::UI::Xaml::Controls::Frame^ frame, String^ iKey)
{
	if (iKey == nullptr || frame == nullptr)
	{

		if (iKey == nullptr)
		{
			m_tc = nullptr;
			OutputDebugString(L"\n\nAPPLICATION INSIGHTS:\nNULL pointer was provided for iKey.  Please set assign value to your iKey from your Azure application.\nSee http://azure.microsoft.com/documentation/articles/app-insights-get-started/ for more information.\n\n");
		}

		if (frame == nullptr)
		{
			m_tc = ref new TelemetryClient(iKey);
			OutputDebugString(L"\n\nAPPLICATION INSIGHTS:\nNULL pointer was provided for frame.\n\n");
		}
	}
	else
	{
		m_frame = frame;
		m_iKey = iKey;

		m_frame->Navigating += ref new Windows::UI::Xaml::Navigation::NavigatingCancelEventHandler(this, &PageTracking::OnNavigating);
		m_frame->Navigated += ref new Windows::UI::Xaml::Navigation::NavigatedEventHandler(this, &PageTracking::OnNavigated);

		m_tc = ref new TelemetryClient(iKey);
	}
}

/// <summary>
/// Convert Ms to string representation of time span.
/// </summary>
/// <param name="totalms">The totalms.</param>
/// <returns>String representation of time span</returns>
String^ MsToTimeSpan(long totalms)
{
	if (totalms < 0) {
		totalms = 0;
	}

	String^ ms = (totalms % 1000).ToString();
	String^ sec = ((int)(totalms / 1000) % 60).ToString();
	String^ min = ((int)(totalms / (1000 * 60)) % 60).ToString();
	String^ hour = ((int)(totalms / (1000 * 60 * 60)) % 24).ToString();

	ms = ms->Length() == 1 ? "00" + ms : ms->Length() == 2 ? "0" + ms : ms;
	sec = sec->Length() < 2 ? "0" + sec : sec;
	min = min->Length() < 2 ? "0" + min : min;
	hour = hour->Length() < 2 ? "0" + hour : hour;

	return hour + ":" + min + ":" + sec + "." + ms;
}

/// <summary>
/// Called when [navigating].
/// </summary>
/// <param name="sender">The sender.</param>
/// <param name="e">The e.</param>
void PageTracking::OnNavigating(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs ^e)
{
	ApplicationDataContainer^ localSettings = ApplicationData::Current->LocalSettings;
	ApplicationDataContainer^ container = localSettings->CreateContainer("AppInsights", ApplicationDataCreateDisposition::Always);
	auto values = localSettings->Containers->Lookup("AppInsights")->Values;
	Windows::Globalization::Calendar^ cal = ref new Windows::Globalization::Calendar();
	Windows::Foundation::DateTime dateToFormat = cal->GetDateTime();

	values->Insert("StartPageLoad", PropertyValue::CreateDateTime(dateToFormat));
}

/// <summary>
/// Called when [navigated].
/// </summary>
/// <param name="sender">The sender.</param>
/// <param name="e">The e.</param>
void PageTracking::OnNavigated(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationEventArgs ^e)
{	
	ApplicationDataContainer^ localSettings = ApplicationData::Current->LocalSettings;
	ApplicationDataContainer^ container = localSettings->CreateContainer("AppInsights", ApplicationDataCreateDisposition::Always);
	auto values = localSettings->Containers->Lookup("AppInsights")->Values;

	Windows::Globalization::Calendar^ cal = ref new Windows::Globalization::Calendar();
	Windows::Foundation::DateTime now = cal->GetDateTime();

	if (values->HasKey("StartPageLoad"))
	{	
		if (m_tc != nullptr && m_frame != nullptr)
		{
			String ^pageName(m_frame->Content->GetType()->FullName);
			DateTime startLoad = (DateTime)values->Lookup("StartPageLoad");
			long loadTimeMs = (long)(now.UniversalTime - startLoad.UniversalTime) / CONVERSION_FOR_100_NANOSECOND_UNITS_TO_MILLISECONDS;

			m_tc->TrackPageView(pageName, MsToTimeSpan(loadTimeMs));
		}
		values->Remove("StartPageLoad");
	}
	else
	{
		if (m_tc != nullptr && m_frame != nullptr)
		{
			String ^pageName(m_frame->Content->GetType()->FullName);
			m_tc->TrackPageView(pageName);
		}
	}
	m_tc->Flush();
}

