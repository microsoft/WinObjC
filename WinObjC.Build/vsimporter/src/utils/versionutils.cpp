#include <Windows.h>
#include <Psapi.h>
#include "SBLog.h"
#include "versionutils.h"
#include "telemetryutils.h"

using String = std::string;

String getBinaryLocation()
{
#if defined(_MSC_VER)
  char pathToExe[MAX_PATH];
  GetModuleFileNameEx(GetCurrentProcess(), NULL, pathToExe, sizeof(pathToExe) / sizeof(pathToExe[0]));
  return pathToExe;
#else
#error Function not defined for current platform.
#endif
}

static String getQueryString(LPVOID versionInfo, LPCTSTR queryValue)
{
  CHAR query[256];
  DWORD* langId = NULL;
  UINT langIdSize = 0;
  if (VerQueryValue(versionInfo, TEXT("\\VarFileInfo\\Translation"), (LPVOID*)&langId, &langIdSize)) {
    sprintf_s(query, sizeof(query), "\\StringFileInfo\\%04X%04X\\%s", LOWORD(langId[0]), HIWORD(langId[0]), queryValue);
  } else {
    sprintf_s(query, sizeof(query), "\\StringFileInfo\\%04X04B0\\%s", GetUserDefaultLangID(), queryValue);
  }

  UINT queryResultSize = 0;
  LPCSTR queryResult = NULL;
  if (VerQueryValue(versionInfo, TEXT(query), (LPVOID*)&queryResult, &queryResultSize)) {
    return String(queryResult, queryResultSize - 1);
  } else {
    return String();
  }
}

String getProductVersion()
{
  String productVersion;
  String binaryPath = getBinaryLocation();

  DWORD dwSize = GetFileVersionInfoSize(binaryPath.c_str(), NULL);
  if (dwSize) {
    std::vector<BYTE> versionInfo(dwSize);
    BOOL status = GetFileVersionInfo(binaryPath.c_str(), NULL, dwSize, &versionInfo[0]);
    if (status) {
      productVersion = getQueryString(&versionInfo[0], "ProductVersion");
    }
  }

  if (productVersion.empty()) {
    return "unknown";
  } else {
    return productVersion;
  }
}