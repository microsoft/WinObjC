#include "Utils.h"
#include <time.h>
#include <sys/timeb.h>
#include <stdlib.h>
#include <stdint.h>
#include <random>
#include <functional>

using namespace ApplicationInsights::core;

#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#include <Windows.h>
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // store or phone
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Storage;
#endif
#endif

/// <summary>
/// Gets the current date time.
/// </summary>
/// <returns>wstring represenation of the current time</returns>
std::wstring Utils::GetCurrentDateTime() {
	struct tm newtime;
	time_t now;
	int milli;
	wchar_t date[80] = {0};

#if _WIN32 || WINAPI_FAMILY
	struct _timeb timebuffer;

	_ftime_s(&timebuffer);
	now = timebuffer.time;
	milli = timebuffer.millitm;
	
	errno_t err = gmtime_s(&newtime, &now);
	if (err)
#else
    now = time(nullptr);
    if (!gmtime_r(reinterpret_cast<time_t *>(&now), &newtime))
#endif
	{
		return L"";
	}

	wcsftime(date, _ARRAY_SIZE(date), L"%Y-%m-%dT%H:%M:%S", &newtime);
    return std::wstring(date) + L"." + std::to_wstring(milli) + L"Z";
}

/// <summary>
/// Generates the random UUID.
/// </summary>
/// <returns>wstring respresentationof the generated UUID</returns>
std::wstring Utils::GenerateRandomUUID(){
	int partSizes[] = { 8, 4, 4, 4, 12 };
	wchar_t uuid[37];
	memset(uuid, 0, sizeof(uuid));
	int num;
	srand((int)time(nullptr));
	int index = 0;
	for (int part = 0; part < 5; part++)
	{
		if (part > 0)
		{
			uuid[index] = '-';
			index++;
		}

		// Generating UUID format version 4 
		// http://en.wikipedia.org/wiki/Universally_unique_identifier
		for (int i = 0; i < partSizes[part]; i++, index++)
		{
			if (part == 2 && i == 0)
			{
				num = 4;
			}
			else if (part == 4 && i == 0)
			{
				num = (rand() % 4) + 8;
			}
			else
			{
				num = rand() % 16;
			}

			if (num < 10)
			{
				uuid[index] = (wchar_t)(L'0' + num);
			}
			else
			{
				uuid[index] = (wchar_t)(L'a' + (num - 10));
			}
		}
	}

	return uuid;

}

/// <summary>
/// Writes the debug line.
/// </summary>
/// <param name="output">The output.</param>
void Utils::WriteDebugLine(const std::wstring &output)
{
#ifdef _DEBUG
#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
	OutputDebugString((L"\r\nAPPLICATION INSIGHTS : \r\n" + output).c_str());
#endif
#endif
}

#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) 
/// <summary>
/// Opens the reg key for application Insights.
/// </summary>
/// <param name="hKey">The hKey.</param>
/// <param name="iKey">The iKey.</param>
/// <returns></returns>
bool Utils::OpenRegKey(HKEY &hKey, std::wstring iKey)  // Windows desktop
{
	wchar_t regKey[128];
	swprintf_s(regKey, 128, L"SOFTWARE\\AppInsights\\%ls", iKey.c_str());
	LONG ret = RegCreateKeyEx(HKEY_CURRENT_USER, regKey, 0, nullptr, 0, KEY_READ | KEY_WRITE, nullptr, &hKey, nullptr);
	if (ret != ERROR_SUCCESS)
	{
		Utils::WriteDebugLine(L"ERROR: Failed to open reg key");
		return false;
	}
	return true;
}

#else // store or phone
/// <summary>
/// Gets the local settings container.
/// </summary>
/// <returns>the local settings container for AppInsights</returns>
Windows::Foundation::Collections::IPropertySet^ Utils::GetLocalSettingsContainer()
{
	ApplicationDataContainer^ localSettings = ApplicationData::Current->LocalSettings;
	ApplicationDataContainer^ container = localSettings->CreateContainer("AppInsights", ApplicationDataCreateDisposition::Always);
	return localSettings->Containers->Lookup("AppInsights")->Values;
}
#endif
#endif