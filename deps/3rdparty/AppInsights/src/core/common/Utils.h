#ifndef UTILS_H
#define UTILS_H

#include "../Common/Common.h"
#include <string>

#define _ARRAY_SIZE(_array)  (sizeof(_array) / sizeof(_array[0]))

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API Utils
		{
		public:
			/// <summary>
			/// Gets the current date time.
			/// </summary>
			/// <returns>wstring represenation of the current time</returns>
			static std::wstring GetCurrentDateTime();

			/// <summary>
			/// Generates the random UUID.
			/// </summary>
			/// <returns>wstring respresentationof the generated UUID</returns>
			static std::wstring GenerateRandomUUID();

			/// <summary>
			/// Safely deletes a ptr.
			/// </summary>
			/// <param name="ptr">The PTR.</param>
			template <class T>
			static void SafeDelete(T& ptr)
			{
				if (ptr != nullptr)
				{
					delete ptr;
					ptr = nullptr;
				}
			}

			/// <summary>
			/// Safely deletes an array.
			/// </summary>
			/// <param name="ptr">The PTR.</param>
			template <class T>
			static void SafeDeleteArray(T& ptr)
			{
				if (ptr != nullptr)
				{
					delete[] ptr;
					ptr = nullptr;
				}
			}

			/// <summary>
			/// Writes the debug line.
			/// </summary>
			/// <param name="output">The output.</param>
			static void WriteDebugLine(const std::wstring &output);



#ifdef WINAPI_FAMILY_PARTITION // it's SOME kind of Windows
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Desktop
			/// <summary>
			/// Opens the reg key for application Insights.
			/// </summary>
			/// <param name="hKey">The hKey.</param>
			/// <param name="iKey">The iKey.</param>
			/// <returns></returns>
			static bool Utils::OpenRegKey(HKEY &hKey, std::wstring iKey);
#else
			// store or phone
			/// <summary>
			/// Gets the local settings container.
			/// </summary>
			/// <returns>the local settings container for AppInsights</returns>
			static Windows::Foundation::Collections::IPropertySet^ GetLocalSettingsContainer();
#endif
#endif
		};
	}
}
#endif