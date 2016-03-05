#pragma once
#include <TelemetryClient.h>
#include "PageTracking.h"

namespace ApplicationInsights
{
	namespace CX
	{
		[Windows::Foundation::Metadata::WebHostHiddenAttribute]
		public ref class SessionTracking sealed
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="SessionTracking"/> class.
			/// </summary>
			SessionTracking();

			/// <summary>
			/// Initializes the specified application.
			/// </summary>
			/// <param name="application">The application.</param>
			/// <param name="frame">The frame.</param>
			/// <param name="iKey">The iKey.</param>
			void Initialize(Windows::UI::Xaml::Application^ application, Windows::UI::Xaml::Controls::Frame^ frame, Platform::String^ iKey);

			/// <summary>
			/// Called when [suspending].
			/// </summary>
			/// <param name="sender">The sender.</param>
			/// <param name="e">The e.</param>
			void OnSuspending(Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);

			/// <summary>
			/// Called when [resume].
			/// </summary>
			/// <param name="sender">The sender.</param>
			/// <param name="e">The e.</param>
			void OnResume(Object^ sender, Platform::Object^ e);

		private:
			Windows::UI::Xaml::Application^ m_app;
			Platform::String^ m_iKey;
			PageTracking^ m_page;
			ApplicationInsights::CX::TelemetryClient^ m_tc;
		};
	}
}
