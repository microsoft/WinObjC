#include <string>
#include <vector>
#include <map>
#include "TelemetryClient.h"
#include "common/Utils.h"

#if defined(WINAPI_FAMILY_PARTITION) // it's SOME kind of Windows
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Win32, no store, no phone
#include "Windows.h"
#else
using namespace Windows::Storage;
using namespace Windows::Foundation;
#endif
#endif

using namespace ApplicationInsights::core;


/// <summary>
/// Initializes a new instance of the <see cref="TelemetryClient"/> class.
/// </summary>
/// <param name="iKey">The ikey.</param>
TelemetryClient::TelemetryClient(std::wstring& iKey)
{
	m_config = new TelemetryClientConfig(iKey);
	m_context = new TelemetryContext(iKey);
	m_context->InitContext();
	m_channel = new TelemetryChannel(*m_config);
}

/// <summary>
/// Initializes a new instance of the <see cref="TelemetryClient"/> class.
/// </summary>
/// <param name="config">The configuration.</param>
/// <param name="context">The context.</param>
TelemetryClient::TelemetryClient(TelemetryClientConfig &config,	TelemetryContext &context) 
	: m_config(&config), m_context(&context)
{
}

/// <summary>
/// Finalizes an instance of the <see cref="TelemetryClient"/> class.
/// </summary>
TelemetryClient::~TelemetryClient()
{
	// Flush any pending data
	Flush();

	// Free allocated memory
	Utils::SafeDelete(m_channel);
	Utils::SafeDelete(m_context);
	Utils::SafeDelete(m_config);
}

/// <summary>
/// Tracks the event.
/// </summary>
/// <param name="eventName">Name of the event.</param>
void TelemetryClient::TrackEvent(const std::wstring& eventName)
{
	wstring_wstring_map props;
	std::map<std::wstring, double> measurements;
	TrackEvent(eventName, props, measurements);
}


/// <summary>
/// Tracks the event.
/// </summary>
/// <param name="eventName">Name of the event.</param>
/// <param name="properties">The properties.</param>
void TelemetryClient::TrackEvent(const std::wstring& eventName, const wstring_wstring_map& properties)
{
	std::map<std::wstring, double> measurements;
	TrackEvent(eventName, properties, measurements);
}

/// <summary>
/// Tracks the event.
/// </summary>
/// <param name="eventName">Name of the event.</param>
/// <param name="properties">The properties.</param>
/// <param name="measurements">The measurements.</param>
void TelemetryClient::TrackEvent(const std::wstring& eventName, const wstring_wstring_map& properties, const std::map<std::wstring, double>& measurements)
{
	EventData telemetry;
	telemetry.SetName(eventName);
	if (properties.size() > 0)
	{
		telemetry.SetProperties(properties);
	}
	if (measurements.size() > 0)
	{
		telemetry.SetMeasurements(measurements);
	}

	Track(telemetry);
}

/// <summary>
/// Tracks the trace.
/// </summary>
/// <param name="message">The message.</param>
void TelemetryClient::TrackTrace(const std::wstring& message)
{
	wstring_wstring_map properties;
	TrackTrace(message, properties);
}

/// <summary>
/// Tracks the trace.
/// </summary>
/// <param name="message">The message.</param>
/// <param name="properties">The properties.</param>
void TelemetryClient::TrackTrace(const std::wstring& message, const wstring_wstring_map& properties)
{
	MessageData telemetry;
	telemetry.SetMessage(message);
	if (properties.size() > 0)
	{
		telemetry.SetProperties(properties);
	}

	Track(telemetry);
}

/// <summary>
/// Tracks the metric.
/// </summary>
/// <param name="name">The name.</param>
/// <param name="value">The value.</param>
void TelemetryClient::TrackMetric(const std::wstring& name, const double& value)
{
	MetricData telemetry;
	DataPoint data;
	data.SetCount(1);
	data.SetKind(Measurement);
	data.SetMax(value);
	data.SetMax(value);
	data.SetName(name);
	data.SetValue(value);
	std::vector<DataPoint*> metricsList;
	metricsList.push_back(&data);

	telemetry.SetMetrics(metricsList);
	Track(telemetry);
}

/// <summary>
/// Tracks the page view.
/// </summary>
/// <param name="pageName">Name of the page.</param>
void TelemetryClient::TrackPageView(const std::wstring& pageName)
{
	wstring_wstring_map properties;
	std::map<std::wstring, double> measurements;
	std::wstring duration = L"";
	TrackPageView(pageName, duration, properties, measurements);
}

/// <summary>
/// Tracks the page view.
/// </summary>
/// <param name="pageName">Name of the page.</param>
/// <param name="duration">The duration.</param>
void TelemetryClient::TrackPageView(const std::wstring& pageName, const std::wstring& duration)
{
	wstring_wstring_map properties;
	std::map<std::wstring, double> measurements;
	
	TrackPageView(pageName, duration, properties, measurements);
}

/// <summary>
/// Tracks the page view.
/// </summary>
/// <param name="pageName">Name of the page.</param>
/// <param name="duration">The duration.</param>
/// <param name="properties">The properties.</param>
void TelemetryClient::TrackPageView(const std::wstring& pageName, const std::wstring& duration, const wstring_wstring_map& properties)
{
	std::map<std::wstring, double> measurements;
	TrackPageView(pageName, duration, properties, measurements);
}

/// <summary>
/// Tracks the page view.
/// </summary>
/// <param name="pageName">Name of the page.</param>
/// <param name="duration">The duration.</param>
/// <param name="properties">The properties.</param>
/// <param name="measurements">The measurements.</param>
void TelemetryClient::TrackPageView(const std::wstring& pageName, const std::wstring& duration, const wstring_wstring_map& properties, const std::map<std::wstring, double>& measurements)
{
	PageViewData telemetry;
	telemetry.SetName(pageName);
	telemetry.SetUrl(pageName);
	if (duration.length() != 0)
	{
		telemetry.SetDuration(duration);
	}

	if (properties.size() > 0)
	{
		telemetry.SetProperties(properties);
	}
	if (measurements.size() > 0)
	{
		telemetry.SetMeasurements(measurements);
	}

	Track(telemetry);
}

/// <summary>
/// Tracks the session start.
/// </summary>
void TelemetryClient::TrackSessionStart()
{
	SessionStateData session;
	session.SetState(SessionState::Start);

	Track(session);
}

/// <summary>
/// Tracks the specified telemetry.
/// </summary>
/// <param name="telemetry">The telemetry.</param>
void TelemetryClient::Track(Domain& telemetry)
{
	if (IsTrackingEnabled())
	{
		m_channel->Enqueue(*m_context, telemetry);
	}
}

/// <summary>
/// Flushes this instance.
/// </summary>
void TelemetryClient::Flush() 
{
	if (m_channel)
	{
		m_channel->Send();
	}
}


/// <summary>
/// Disables all tracking.
/// </summary>
void TelemetryClient::DisableTracking()
{
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Win32, no store, no phone
	//Use registry settings 
	HKEY hKey;
	if (Utils::OpenRegKey(hKey, m_config->GetIKey()))
	{
		DWORD disable = 1;
		if (RegSetValueEx(hKey, TEXT("DisableTracking"), 0, REG_DWORD, (const BYTE *)&disable, sizeof(disable)) != ERROR_SUCCESS)
		{
			//Unable to set registry value
			Utils::WriteDebugLine(L"ERROR: Failed to set reg key for disable tracking");
			RegCloseKey(hKey);
		}
		RegCloseKey(hKey);
	}	
		
#else  //Windows phone or store
	auto values = Utils::GetLocalSettingsContainer();

	values->Insert("Tracking", dynamic_cast<PropertyValue^>(PropertyValue::CreateString("Disable")));
	
#endif
#endif
}

/// <summary>
/// Enables all tracking.
/// </summary>
void TelemetryClient::EnableTracking()
{
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Win32, no store, no phone
	//Use registry settings 
	HKEY hKey;
	if (Utils::OpenRegKey(hKey, m_config->GetIKey()))
	{
		if (RegDeleteValue(hKey, TEXT("DisableTracking")) != ERROR_SUCCESS)
		{
			//Unable to set registry value
			Utils::WriteDebugLine(L"ERROR: Failed to remove reg key for disable tracking");
			RegCloseKey(hKey);
		}
		RegCloseKey(hKey);
	}
#else  //Windows phone or store
	auto values = Utils::GetLocalSettingsContainer();
	values->Remove("Tracking");
	
#endif
#endif
}

/// <summary>
/// Determines whether [is tracking enabled].
/// </summary>
/// <returns>True if the tracking is enabled, otherwise false</returns>
bool TelemetryClient::IsTrackingEnabled()
{
#if defined(WINAPI_FAMILY_PARTITION) // it's SOME kind of Windows
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Win32, no store, no phone
	//Use registry settings 
	HKEY hKey;
	
	DWORD szBuffer = 0;
	DWORD dwBufferSize = sizeof(szBuffer);
	bool trackingEnabled = true;

	if (Utils::OpenRegKey(hKey, m_config->GetIKey()))
	{
		if (RegQueryValueEx(hKey, TEXT("DisableTracking"), nullptr, nullptr, (LPBYTE)szBuffer, &dwBufferSize) == ERROR_SUCCESS)
		{
			trackingEnabled = false;
		}
		RegCloseKey(hKey);
	}
	return trackingEnabled;
#else  //Windows phone or store
	bool enabled = true;
	
	auto values = Utils::GetLocalSettingsContainer();

	enabled = !(values->HasKey("Tracking"));
	
	return enabled;
#endif
#endif
}