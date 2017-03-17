#include "TelemetryContext.h"

#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone

#include <windows.h>
#include "Common/Utils.h"

using namespace ApplicationInsights::core;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::Foundation;
using namespace Windows::Globalization;
using namespace Windows::Graphics::Display;
using namespace Windows::Networking::Connectivity;
using namespace Windows::Security::Cryptography;
using namespace Windows::Security::Cryptography::Core;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Windows::System::Profile;


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
/// Initializes the user.
/// </summary>
void TelemetryContext::InitUser()
{
	try {
		ApplicationDataContainer^ localSettings = ApplicationData::Current->LocalSettings;

		ApplicationDataContainer^ container =
			localSettings->CreateContainer("AppInsight", ApplicationDataCreateDisposition::Always);

		if (localSettings->Containers->HasKey("AppInsight"))
		{
			auto values = localSettings->Containers->Lookup("AppInsight")->Values;

			//Get/Set the userID
			if (values->HasKey("userId") == false)
			{
				Platform::String^ id = ref new Platform::String(Utils::GenerateRandomUUID().c_str());
				values->Insert("userId", dynamic_cast<PropertyValue^>(PropertyValue::CreateString(id)));
			}

			String^ userId = safe_cast<String^>(localSettings->Containers->Lookup("AppInsight")->Values->Lookup("userId"));
			Nullable<std::wstring> uuid(userId->Data());
			user.SetId(uuid);

			//Get/Set the acquisition date
			if (values->HasKey("acquisitionDate") == false)
			{
				Platform::String^ acqDate = ref new Platform::String(Utils::GetCurrentDateTime().c_str());
				values->Insert("acquisitionDate", dynamic_cast<PropertyValue^>(PropertyValue::CreateString(acqDate)));
			}

			String^ acquisitionDate = safe_cast<String^>(localSettings->Containers->Lookup("AppInsight")->Values->Lookup("acquisitionDate"));
			Nullable<std::wstring> date(acquisitionDate->Data());
			user.SetAccountAcquisitionDate(date);
		}
	}
	catch (Exception^) {
		Utils::WriteDebugLine(L"WARNING: Failed to get application context");
	}
	catch (std::exception &) {
		Utils::WriteDebugLine(L"WARNING: Failed to get application context");
	}
	catch (...) {
		Utils::WriteDebugLine(L"WARNING: Failed to get application context");
	}
}

/// <summary>
/// Initializes the device.
/// </summary>
void TelemetryContext::InitDevice()
{
	try {
		Nullable<std::wstring> strId(Utils::GenerateRandomUUID().c_str());
		device.SetId(strId);

		String^ lang = Language::CurrentInputMethodLanguageTag;
		Nullable<std::wstring> strLang(lang->Data());
		device.SetLanguage(strLang);

		GeographicRegion geographicRegion;
		String^ region = geographicRegion.DisplayName;
		Nullable<std::wstring> strRegion(region->Data());
		device.SetLocale(strRegion);

		ConnectionProfile^ connectionProfile = NetworkInformation::GetInternetConnectionProfile();
		if (connectionProfile != nullptr)
		{
			String^ network = connectionProfile->ProfileName;
			Nullable<std::wstring> strNetwork(network->Data());
			device.SetNetwork(strNetwork);
		}

		Nullable<std::wstring> strOs(L"Windows");
		device.SetOs(strOs);
		//
		//DisplayInformation^ displayInformation = DisplayInformation::GetForCurrentView();
		//float x = displayInformation->RawDpiX;
		//float y = displayInformation->RawDpiY;
		//wchar_t strResolution[256];
		//swprintf_s(strResolution, 256, L"%fx%f", x, y);
		//Nullable<std::wstring> strRes(strResolution);
		//device.SetScreenResolution(strRes);

		Nullable<std::wstring> strType(L"Store");
		device.SetType(strType);
	}
	catch (Exception^) {
		Utils::WriteDebugLine(L"WARNING: Failed to get device context");
	}
	catch (std::exception &) {
		Utils::WriteDebugLine(L"WARNING: Failed to get device context");
	}
	catch (...) {
		Utils::WriteDebugLine(L"WARNING: Failed to get device context");
	}
}

/// <summary>
/// Initializes the application.
/// </summary>
void TelemetryContext::InitApplication()
{
	try {
		PackageId^ appId = Package::Current->Id;
		PackageVersion version = appId->Version;
		wchar_t strVerNumber[256];
		swprintf_s(strVerNumber, 256, L"%d.%d.%d.%d", version.Build, version.Major, version.Minor, version.Revision);
		String^ ver = appId->Name + " (" + ref new String(strVerNumber) + ")";
		Nullable<std::wstring> strVer(ver->Data());

		app.SetVer(strVer);
	}
	catch (Exception^) {
		Utils::WriteDebugLine(L"WARNING: Failed to get application context");
	}
	catch (std::exception &) {
		Utils::WriteDebugLine(L"WARNING: Failed to get application context");
	}
	catch (...) {
		Utils::WriteDebugLine(L"WARNING: Failed to get application context");
	}
}

/// <summary>
/// Initializes the session.
/// </summary>
void TelemetryContext::InitSession()
{
	auto values = Utils::GetLocalSettingsContainer();

	if (!values->HasKey("SessionId"))
	{
		BaseTelemetryContext::InitSession();
	}
}
#endif
#endif