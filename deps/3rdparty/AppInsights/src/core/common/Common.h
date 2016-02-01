#ifndef COMMON_H
#define COMMON_H

#ifdef WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <map>

namespace ApplicationInsights
{
	namespace core
	{
#ifdef TELEMETRY_CLIENT_DLL_EXPORT
#define TELEMETRYCLIENT_API __declspec(dllexport)
#else
#define TELEMETRYCLIENT_API
#endif

		typedef std::map<std::wstring, std::wstring> wstring_wstring_map;

		typedef long				RESULT;

#define RESULT_OK					(0L)
#define RESULT_ERR					(-1L)
#define RESULT_ERR_NOT_CONNECTED	(-2L)
#define RESULT_ERR_MAX_RETRIES		(-3L)
	}
}
#endif
