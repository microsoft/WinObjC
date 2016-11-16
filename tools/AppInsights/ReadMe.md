##Application Insights SDK C++ - For UAP apps##

###Introduction###
This document describes how to integrate AppInsights into your projects and the APIs available to you.

###Requirements:###
This SDK will run on Windows C++ - VS 2015 UAP projects

###Download:###
1. Download the ApplicationInsightsCpp.zip file.
2. Unzip the folder to a location on your computer (i.e. c:\sdk).  The folder contains static libs for debug and release and the *.h files.

###Setup:###
1. In your project, in both **release and debug mode**, Add the `<sdk location>`\ApplicationInsights\inc to the project properties -> VC++ Directories -> Include Directories
2. In both **release and debug**, add AppInsights_Win10-UAP.lib to your project properties -> Link -> input -> additional dependencies
3. In **release**:
	- add the `<sdk location>`\ApplicationInsights\lib\ `<PLATFORM TYPE>`\\ **release**\AppInsights_Win10-UAP to the project properties -> VC++ Directories -> Library Directories
	- add `<sdk location>`\ApplicationInsights\lib\ `<PLATFORM TYPE>`\\**release**\ApplicationInsights to  project properties -> VC++ Directories -> Library WinRT Directories
4. In **debug**:
	- add the `<sdk location>`\ApplicationInsights\lib\ `<PLATFORM TYPE>`\\ **debug**\AppInsights_Win10-UAP to the project properties -> VC++ Directories -> Library Directories
	- add `<sdk location>`\ApplicationInsights\lib\ `<PLATFORM TYPE>`\\**debug**\ApplicationInsights to  project properties -> VC++ Directories -> Library WinRT Directories
5. Add ApplicationInsights.winmd as a refernce to your project from `<sdk location>`\ApplicationInsights\lib\ `<PLATFORM TYPE>`\ `<BUILD TYPE>`\ApplicationInsights
6. Add the AppInsights_Win10-UAP.dll from `<sdk location>`\ApplicationInsights\lib\ `<PLATFORM TYPE>`\ `<BUILD TYPE>`\AppInsights_Win10-UAP.  Go to properties and set content to YES.  This will copy the dll to your build directory.
7. In App.xaml.h:
	- Add ApplicationInsights::CX::SessionTracking^ m_session;
8.  In your App.xaml.cpp:
	- add using namespace ApplicationInsights::CX;
	- In App:App()
		```cpp
		// this will do automatic session tracking and automatic page view collection
		m_session = ref new ApplicationInsights::CX::SessionTracking();
		```
		
	- Once you have created the root Frame, (usually at the end of App::OnLaunched) initalize m_session
		```cpp
		String^ iKey = L"<YOUR INSTRUMENTATION KEY>";
		m_session->Initialize(this, rootFrame, iKey);
		```
9. To use tracking elsewhere in your application, you can declare an instance of Telemetry client.
	```cpp
	using namespace ApplicationInsights::CX;
	
	TelemetryClient^ tc = ref new TelemetryClient(L"<YOUR INSTRUMENTATION KEY>");
	tc->TrackEvent(L"I'M ON PAGE 1");
	tc->TrackMetric(L"Test Metric", 5.03);
	```


###APIs###
```cpp
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
```