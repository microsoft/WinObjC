#pragma once
#include "../../../src/core/TelemetryClient.h"
namespace ApplicationInsights
{
	namespace CX
	{
		[Windows::Foundation::Metadata::WebHostHiddenAttribute]
		public ref class TelemetryClient sealed
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="TelemetryClient"/> class.
			/// </summary>
			/// <param name="iKey">The iKey.</param>
			TelemetryClient(Platform::String^ iKey);

			/// <summary>
			/// Finalizes an instance of the <see cref="" /> class.
			/// </summary>
			/// <returns></returns>
			virtual ~TelemetryClient();

			/// <summary>
			/// Tracks the event.
			/// </summary>
			/// <param name="eventName">Name of the event.</param>
			void TrackEvent(Platform::String^ eventName);
			
			/// <summary>
			/// Tracks the trace.
			/// </summary>
			/// <param name="message">The message.</param>
			void TrackTrace(Platform::String^ message);
			
			/// <summary>
			/// Tracks the metric.
			/// </summary>
			/// <param name="name">The name.</param>
			/// <param name="value">The value.</param>
			void TrackMetric(Platform::String^ name, double value);

			/// <summary>
			/// Tracks the page view.
			/// </summary>
			/// <param name="pageName">Name of the page.</param>
			void TrackPageView(Platform::String^ pageName);

			/// <summary>
			/// Tracks the page view.
			/// </summary>
			/// <param name="pageName">Name of the page.</param>
			/// <param name="duration">The duration.</param>
			void TrackPageView(Platform::String^ pageName, Platform::String^ duration);
			
			/// <summary>
			/// Tracks the session start.
			/// </summary>
			void TrackSessionStart();

			/// <summary>
			/// Flushes this queue.
			/// </summary>
			void Flush();

			/// <summary>
			/// Disables all tracking.
			/// </summary>
			void DisableTracking();

			/// <summary>
			/// Enables all tracking.
			/// </summary>
			void EnableTracking();

			/// <summary>
			/// Renews the session.
			/// </summary>
			void RenewSession();
		private:
			ApplicationInsights::core::TelemetryClient *m_tc;
		};
	}
}
