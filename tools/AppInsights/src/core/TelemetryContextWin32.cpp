#include "TelemetryContext.h"
#include "common/Utils.h"
#include <codecvt>
#include <locale>

#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // desktop, no store or phone

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
	BaseTelemetryContext::InitApplication();
}

/// <summary>
/// Initializes the user.
/// </summary>
void TelemetryContext::InitUser()
{
	BaseTelemetryContext::InitUser();
}

/// <summary>
/// Initializes the session.
/// </summary>
void TelemetryContext::InitSession()
{
	BaseTelemetryContext::InitSession();
}
#endif
#endif