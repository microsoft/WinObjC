#ifndef TELEMETRYCLIENTCONFIG_H
#define TELEMETRYCLIENTCONFIG_H

#include "Common/Common.h"
#include <string>

namespace ApplicationInsights
{
	namespace core
	{
		struct TELEMETRYCLIENT_API TelemetryClientConfig
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="TelemetryClientConfig"/> struct.
			/// </summary>
			/// <param name="iKey">The i key.</param>
			TelemetryClientConfig(const std::wstring& iKey) {
				m_instrumentationKey = iKey;
			}

			/// <summary>
			/// Sets the iKey.
			/// </summary>
			/// <param name="iKey">The iKey.</param>
			void SetIKey(const std::wstring& iKey) { m_instrumentationKey = iKey; }

			/// <summary>
			/// Gets the iKey.
			/// </summary>
			/// <returns>the iKey</returns>
			const std::wstring& GetIKey() const { return m_instrumentationKey; }

		private:
			/**
			* The instrumentation key for this telemetryContext
			*/
			std::wstring m_instrumentationKey;
		};
	}
}
#endif
