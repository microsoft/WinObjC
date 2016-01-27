#include "TelemetryContext.h"

#ifndef WINAPI_FAMILY_PARTITION // Not Windows

using namespace ApplicationInsights::core;

/// <summary>
/// Stores the context.
/// </summary>
/// <returns></returns>
TelemetryContext::TelemetryContext(std::wstring& iKey) :
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
	//Nullable<std::wstring> strDevId = L"TODO";
	//device.SetId(strDevId);
	//device.SetLanguage();
	//device.SetLocale();
	//device.SetMachineName();
	//device.SetModel();
	//device.SetNetwork();
	//device.SetOemName();
	Nullable<std::wstring> strOs;
	strOs.SetValue(L"Windows");
	device.SetOs(strOs);

	//device.SetOsVersion();
	//device.SetScreenResolution();

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

/// <summary>
/// Initializes the session.
/// </summary>
void TelemetryContext::InitSession()
{
	//TODO
}

#endif