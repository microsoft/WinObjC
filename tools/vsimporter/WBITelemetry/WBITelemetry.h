//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************
#pragma once

#include "..\..\AppInsights\src\core\TelemetryClient.h"

#define TELEMETRY_INIT(ikey) {\
        WBITelemetry::WBITelemetryManager::InitializeAppInsights(ikey);\
    }

#define TELEMETRY_ENABLE() {\
        WBITelemetry::WBITelemetryManager::EnableTracking();\
    }

#define TELEMETRY_DISABLE() {\
        WBITelemetry::WBITelemetryManager::DisableTracking();\
    }

#define TELEMETRY_SET_MACHINEID(machineId) {\
        WBITelemetry::WBITelemetryManager::SetMachineId(machineId);\
    }

#define TELEMETRY_SET_INTERNAL(isInternal) {\
        WBITelemetry::WBITelemetryManager::SetIsInternal(isInternal);\
    }

#define TELEMETRY_FLUSH() {\
        WBITelemetry::WBITelemetryManager::Flush();\
    }

#define TELEMETRY_EVENT(msg) {\
        WBITelemetry::WBITelemetryManager::AITrackEvent(msg);\
    }

#define TELEMETRY_EVENT_DATA(eventName, eventData) {\
        WBITelemetry::WBITelemetryManager::AITrackEventData(eventName, eventData);\
    }

// Used to skim the leading and trailing braces from the GUID.
#define TELEMETRY_EVENT_GUID(eventName, guid) {\
        WBITelemetry::WBITelemetryManager::AITrackEventGuidData(eventName, guid);\
    }

#define TELEMETRY_EVENT_PARMS(msg, ...) {\
        WBITelemetry::WBITelemetryManager::AITrackEventParams(msg,__VA_ARGS__);\
    }

#define TELEMETRY_METRIC(msg, value) {\
        WBITelemetry::WBITelemetryManager::AITrackMetric(msg, value);\
    }

#define TELEMETRY_TRACE(msg) {\
        WBITelemetry::WBITelemetryManager::AITrackTrace(msg);\
    }

#define TEST1(msg){\
        WBITelemetry::WBITelemetryManager::Test1(msg);\
        }

#include <stdio.h>
#include <string>

using namespace std;

namespace WBITelemetry
{
    class WBITelemetryManager
    {
    public:
        static int nTestVal;

        static wstring m_iKey;
        static wstring m_endPoint;

        static wstring s_machineId;
        static bool s_isInternal;
        
        static ApplicationInsights::core::TelemetryClient m_tc;

        static void InitializeAppInsights(wstring ikey);

        static void EnableTracking();
        static void DisableTracking();

        static void SetMachineId(const char* machineId);
        static void SetIsInternal(bool isInternal);

        static void Flush();

        static void AITrackEvent(wstring eventMessage);

        static void AITrackEventData(wstring eventName, wstring eventData);
        static void AITrackEventData(wstring eventName, const char* eventData);

        static void AITrackEventGuidData(wstring eventName, string eventData);

        static void AITrackEventParams(wstring eventMessage, ...);

        static void AITrackTrace(wstring traceMessage);

        static void AITrackMetric(wstring eventMessage, double value);
    };
}
