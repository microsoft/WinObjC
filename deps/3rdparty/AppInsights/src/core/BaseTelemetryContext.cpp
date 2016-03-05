#include "BaseTelemetryContext.h"
#include "Common/Utils.h"

using namespace ApplicationInsights::core;

#define AddToMapIfHasValue(map, key, value) if (value.HasValue()) { map[key] = value.GetValue(); }

/// <summary>
/// Initializes a new instance of the <see cref="BaseTelemetryContext"/> class.
/// </summary>
/// <param name="iKey">The i key.</param>
BaseTelemetryContext::BaseTelemetryContext(const std::wstring& iKey)
{
	m_iKey = iKey;
}

/// <summary>
/// Finalizes an instance of the <see cref="BaseTelemetryContext"/> class.
/// </summary>
BaseTelemetryContext::~BaseTelemetryContext()
{
}

/// <summary>
/// Initializes the context.
/// </summary>
void BaseTelemetryContext::InitContext()
{
	InitUser();
	InitDevice();
	InitApplication();
	InitSession();
}

/// <summary>
/// Initializes the user context.
/// </summary>
void BaseTelemetryContext::InitUser()
{
	Nullable<std::wstring> uuid = Utils::GenerateRandomUUID(); 
	Nullable<std::wstring> date = Utils::GetCurrentDateTime();
	user.SetId(uuid);
	user.SetAccountAcquisitionDate(date);
}


/// <summary>
/// Initializes the device context.
/// </summary>
void BaseTelemetryContext::InitDevice()
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
void BaseTelemetryContext::InitApplication()
{
	//TODO
}

/// <summary>
/// Initializes the session.
/// </summary>
void BaseTelemetryContext::InitSession()
{
	Nullable<std::wstring> sessionId = Utils::GenerateRandomUUID();
	session.SetId(sessionId);

	Nullable<std::wstring> strTrue = std::wstring(L"True");
	session.SetIsFirst(strTrue);
	session.SetIsNew(strTrue);
}

/// <summary>
/// Renews the session.
/// </summary>
void BaseTelemetryContext::RenewSession()
{
	Nullable<std::wstring> sessionId = Utils::GenerateRandomUUID();
	session.SetId(sessionId);

	Nullable<std::wstring> strTrue = std::wstring(L"True");
	Nullable<std::wstring> strFalse = std::wstring(L"False");
	session.SetIsFirst(strFalse);
	session.SetIsNew(strTrue);
}

/// <summary>
/// Gets the context tags.
/// </summary>
/// <param name="tags">The tags.</param>
/// <returns>RESULT_OK if succedded</returns>
RESULT BaseTelemetryContext::GetContextTags(wstring_wstring_map& tags)
{
	tags.clear();

    AddToMapIfHasValue(tags, L"ai.user.accountAcquisitionDate", user.GetAccountAcquisitionDate());
    AddToMapIfHasValue(tags, L"ai.user.accountId", user.GetAccountId());
    AddToMapIfHasValue(tags, L"ai.user.userAgent", user.GetUserAgent());
    AddToMapIfHasValue(tags, L"ai.user.id", user.GetId());

    AddToMapIfHasValue(tags, L"ai.device.id", device.GetId());
    AddToMapIfHasValue(tags, L"ai.device.ip", device.GetIp());
    AddToMapIfHasValue(tags, L"ai.device.language", device.GetLanguage());
    AddToMapIfHasValue(tags, L"ai.device.locale", device.GetLocale());
    AddToMapIfHasValue(tags, L"ai.device.model", device.GetModel());
    AddToMapIfHasValue(tags, L"ai.device.network", device.GetNetwork());
    AddToMapIfHasValue(tags, L"ai.device.oemName", device.GetOemName());
    AddToMapIfHasValue(tags, L"ai.device.os", device.GetOs());
    AddToMapIfHasValue(tags, L"ai.device.osVersion", device.GetOsVersion());
    AddToMapIfHasValue(tags, L"ai.device.roleInstance", device.GetRoleInstance());
    AddToMapIfHasValue(tags, L"ai.device.roleName", device.GetRoleName());
    AddToMapIfHasValue(tags, L"ai.device.screenResolution", device.GetScreenResolution());
    AddToMapIfHasValue(tags, L"ai.device.type", device.GetType());
    AddToMapIfHasValue(tags, L"ai.device.machineName", device.GetMachineName());

    AddToMapIfHasValue(tags, L"ai.application.ver", app.GetVer());

    AddToMapIfHasValue(tags, L"ai.session.id", session.GetId());
    AddToMapIfHasValue(tags, L"ai.session.isFirst", session.GetIsFirst());
    AddToMapIfHasValue(tags, L"ai.session.isNew", session.GetIsNew());

	return RESULT_OK;
}