#ifndef TELEMETRYCONTEXT_H
#define TELEMETRYCONTEXT_H

#include "BaseTelemetryContext.h"
#include <string>
#include "TelemetryClientConfig.h"
#include "Contracts/Contracts.h"
#include "Common/Common.h"

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API TelemetryContext : public BaseTelemetryContext
		{
		public:
			/// <summary>
			/// Stores the context.
			/// </summary>
			/// <param name="iKey">The iKey.</param>
			/// <returns></returns>
			TelemetryContext(const std::wstring& iKey);

			/// <summary>
			/// Finalizes an instance of the <see cref=""/> class.
			/// </summary>
			/// <returns></returns>
			virtual ~TelemetryContext();

			/// <summary>
			/// Initializes the user.
			/// </summary>
			virtual void InitUser();

			/// <summary>
			/// Initializes the device.
			/// </summary>
			virtual void InitDevice();

			/// <summary>
			/// Initializes the application.
			/// </summary>
			virtual void InitApplication();

			/// <summary>
			/// Initializes the session.
			/// </summary>
			virtual void InitSession();
		};
	}
}
#endif
