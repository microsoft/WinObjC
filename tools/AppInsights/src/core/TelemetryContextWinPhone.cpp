#if _WIN32
#include <windows.h>
#if WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#include "TelemetryContext.h"

using namespace ApplicationInsights::core;

/// <summary>
/// Stores the context.
/// </summary>
/// <param name="iKey">The iKey.</param>
/// <returns></returns>
TelemetryContext::TelemetryContext(const std::wstring& iKey) :
BaseTelemetryContext(iKey)
{
}

/// <summary>
/// Finalizes an instance of the <see cref=""/> class.
/// </summary>
/// <returns></returns>
TelemetryContext::~TelemetryContext()
{
}

/// <summary>
/// Initializes the device.
/// </summary>
void TelemetryContext::InitDevice()
{
	Nullable<std::wstring> strOs;
	strOs.SetValue(L"Windows");
	device.SetOs(strOs);

	Nullable<std::wstring> strType;
	strType.SetValue(L"Other");
	device.SetType(strType);
}

/// <summary>
/// Initializes the application.
/// </summary>
void TelemetryContext::InitApplication()
{
	//TODO
}

/// <summary>
/// Initializes the user.
/// </summary>
void TelemetryContext::InitUser()
{
	//TODO
}

#endif
#endif
