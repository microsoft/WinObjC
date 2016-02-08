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
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
#include <codecvt>

#include "WBITelemetry.h"

using namespace ApplicationInsights::core;

namespace WBITelemetry
{
    int     WBITelemetryManager::nTestVal   = 0;
    wstring WBITelemetryManager::m_iKey     = L"AIF-47606e3a-4264-4368-8f7f-ed6ec3366dca"; // "AIF-" Vortex will reject if "AIF-" prefix is missing.

    ApplicationInsights::core::TelemetryClient WBITelemetryManager::m_tc = ApplicationInsights::core::TelemetryClient(m_iKey);

    // Initialize AI with the Instrumentation Key.  Caller will provide.
    void WBITelemetryManager::InitializeAppInsights(wstring ikey)
    {
        m_iKey     = ikey;
        ApplicationInsights::core::TelemetryClientConfig* conf = m_tc.GetConfig();
        conf->SetIKey(m_iKey);
    }

    // Simple logging function.
    void WBITelemetryManager::AITrackEvent(wstring eventMessage)
    {
        //Need to validate m_tc
        WBITelemetryManager::m_tc.TrackEvent(eventMessage);
        WBITelemetryManager::m_tc.Flush();
    }

    // Logging function in the form of EventName, eventData.  This version accomodates incoming wstring type.
    void WBITelemetryManager::AITrackEventData(wstring eventName, wstring eventData)
    {
        ApplicationInsights::core::wstring_wstring_map props; //typedef std::map<std::wstring, std::wstring> wstring_wstring_map;
        props.insert({ std::wstring(L"Data"), std::wstring(eventData) });
        WBITelemetryManager::m_tc.TrackEvent(eventName, props);
        WBITelemetryManager::m_tc.Flush();
    }

    // Logging function in the form of EventName, eventData.  This version accomodates incoming char* type.
    void WBITelemetryManager::AITrackEventData(wstring eventName, const char* eventData)
    {
        std::string str = std::string(eventData);
        std::wstring wsData;
        wsData.assign(str.begin(), str.end());
        AITrackEventData(eventName, wsData);
    }

    // Logging function that allows list of values.
    void WBITelemetryManager::AITrackEventParams(wstring eventMessage, ...)
    {
        int nSize = 0;
        wchar_t buff[4096];
        va_list args;
        va_start(args, eventMessage);
        nSize = _vsnwprintf_s(buff, sizeof(buff)-1, eventMessage.c_str(), args);

        WBITelemetryManager::m_tc.TrackEvent(buff);
        WBITelemetryManager::m_tc.Flush();

        va_end(args);
    }

    void WBITelemetryManager::AITrackTrace(wstring traceMessage)
    {
        //Need to validate m_tc
        WBITelemetryManager::m_tc.TrackTrace(traceMessage);
        WBITelemetryManager::m_tc.Flush();
    }

    void WBITelemetryManager::AITrackMetric(wstring eventMessage, double value)
    {
        //Need to validate m_tc
        WBITelemetryManager::m_tc.TrackMetric(eventMessage, value);
        WBITelemetryManager::m_tc.Flush();
    }
}