#ifndef TELEMETRYCHANNEL_H
#define TELEMETRYCHANNEL_H

#include <string>
#include <list>
#include "../TelemetryClientConfig.h"
#include "../TelemetryContext.h"
#include "../Contracts/Contracts.h"
#include "../Common/Common.h"
#include "Utils/HttpRequest.h"

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Windows phone or store
#include <Windows.h>
#endif 
#endif

namespace ApplicationInsights
{
	namespace core
	{
		class TELEMETRYCLIENT_API TelemetryChannel
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="TelemetryChannel"/> class.
			/// </summary>
			/// <param name="config">The configuration.</param>
			TelemetryChannel(TelemetryClientConfig &config);

			/// <summary>
			/// Finalizes an instance of the <see cref="TelemetryChannel"/> class.
			/// </summary>
			virtual ~TelemetryChannel();

			/// <summary>
			/// Enqueues the specified context.
			/// </summary>
			/// <param name="context">The context.</param>
			/// <param name="telemetry">The telemetry.</param>
			void Enqueue(TelemetryContext &context, Domain &telemetry);

			/// <summary>
			/// Sends this instance.
			/// </summary>
			void Send();

		protected:
			int m_channelId;
			int m_seqNum;
			int m_maxBufferSize;
			TelemetryClientConfig *m_config;
			std::vector<std::wstring> m_buffer;

			HttpResponse resp;

#ifdef WINAPI_FAMILY_PARTITION
#if !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) // Windows phone or store
			HANDLE hRespRecv;
#endif
#endif
			bool TelemetryChannel::IsUTCAvailable();
			std::wstring TraceLoggingSanitizer(std::wstring data);
		};
	}
}
#endif