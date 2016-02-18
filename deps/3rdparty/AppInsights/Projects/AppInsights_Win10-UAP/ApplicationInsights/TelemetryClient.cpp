#include "TelemetryClient.h"
#include "../../../src/core/contracts/SessionStateData.h"

using namespace ApplicationInsights::CX;
using namespace Platform;

/// <summary>
/// Initializes a new instance of the <see cref="TelemetryClient"/> class.
/// </summary>
/// <param name="iKey">The iKey.</param>
TelemetryClient::TelemetryClient(String^ iKey)
{
	std::wstring iKeyString = iKey->Data();
	m_tc = new ApplicationInsights::core::TelemetryClient(iKeyString);
}

/// <summary>
/// Finalizes an instance of the <see cref="" /> class.
/// </summary>
/// <returns></returns>
TelemetryClient::~TelemetryClient()
{
	delete m_tc;
}

/// <summary>
/// Tracks the event.
/// </summary>
/// <param name="eventName">Name of the event.</param>
void TelemetryClient::TrackEvent(String^ eventName)
{
	std::wstring name = eventName->Data();
	m_tc->TrackEvent(name);
}

/// <summary>
/// Tracks the trace.
/// </summary>
/// <param name="message">The message.</param>
void TelemetryClient::TrackTrace(String^ message)
{
	std::wstring msg = message->Data();
	m_tc->TrackTrace(msg);
}

/// <summary>
/// Tracks the metric.
/// </summary>
/// <param name="name">The name.</param>
/// <param name="value">The value.</param>
void TelemetryClient::TrackMetric(String^ name, double value)
{
	std::wstring metricName = name->Data();
	m_tc->TrackMetric(metricName, value);
}

/// <summary>
/// Tracks the page view.
/// </summary>
/// <param name="pageName">Name of the page.</param>
void TelemetryClient::TrackPageView(String^ pageName)
{
	std::wstring name = pageName->Data();
	m_tc->TrackPageView(name);
}

/// <summary>
/// Tracks the page view.
/// </summary>
/// <param name="pageName">Name of the page.</param>
/// <param name="duration">The duration.</param>
void TelemetryClient::TrackPageView(String^ pageName, String^ duration)
{
	std::wstring name = pageName->Data();
	std::wstring durationString = duration->Data();
	m_tc->TrackPageView(name, durationString);
}

/// <summary>
/// Tracks the session start.
/// </summary>
void TelemetryClient::TrackSessionStart()
{
	//Send start session
	m_tc->TrackSessionStart();
}

/// <summary>
/// Flushes this queue.
/// </summary>
void TelemetryClient::Flush()
{
	m_tc->Flush();
}

/// <summary>
/// Disables all tracking.
/// </summary>
void TelemetryClient::DisableTracking()
{
	m_tc->DisableTracking();
}

/// <summary>
/// Enables all tracking.
/// </summary>
void TelemetryClient::EnableTracking()
{
	m_tc->EnableTracking();
}

/// <summary>
/// Renews the session.
/// </summary>
void TelemetryClient::RenewSession()
{
	m_tc->GetContext()->RenewSession();
}