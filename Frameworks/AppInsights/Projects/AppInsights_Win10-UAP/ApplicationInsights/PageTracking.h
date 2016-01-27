#pragma once
#include <TelemetryClient.h>

namespace ApplicationInsights
{
	namespace CX
	{
		[Windows::Foundation::Metadata::WebHostHiddenAttribute]
		public ref class PageTracking sealed
		{
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="PageTracking"/> class.
			/// </summary>
			PageTracking();

			/// <summary>
			/// Finalizes an instance of the <see cref="PageTracking"/> class.
			/// </summary>
			virtual ~PageTracking();

			/// <summary>
			/// Initializes the specified frame.
			/// </summary>
			/// <param name="frame">The frame.</param>
			/// <param name="iKey">The iKey.</param>
			void Initialize(Windows::UI::Xaml::Controls::Frame^ frame, Platform::String^ iKey);

			/// <summary>
			/// Called when [navigating].
			/// </summary>
			/// <param name="sender">The sender.</param>
			/// <param name="e">The e.</param>
			void OnNavigating(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs ^e);

			/// <summary>
			/// Called when [navigated].
			/// </summary>
			/// <param name="sender">The sender.</param>
			/// <param name="e">The e.</param>
			void OnNavigated(Platform::Object ^sender, Windows::UI::Xaml::Navigation::NavigationEventArgs ^e);
		private:
			Windows::UI::Xaml::Controls::Frame^ m_frame;
			Platform::String^ m_iKey;
			TelemetryClient^ m_tc;
		};
	}
}

