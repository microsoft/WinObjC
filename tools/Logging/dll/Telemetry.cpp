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

// This file is included under the DLL because the compiler cannot statically link to a library that references the 
// AppInsights UAP library.

#include "LoggingInternal.h"
#include "Telemetry.h"

using namespace ApplicationInsights::CX;
using namespace Platform;

// This is the internal key for WinObjC telemetry
const wchar_t* c_ikey = L"AIF-47606e3a-4264-4368-8f7f-ed6ec3366dca";

TelemetryClient^ _getTelemetryClient() {
    static TelemetryClient^ telemetryClient = ref new TelemetryClient(StringReference(c_ikey));

    return telemetryClient;
}

void TelemetryEvent(const wchar_t* name) {
    _getTelemetryClient()->TrackEvent(StringReference(name));
}

void TelemetryMetric(const wchar_t* name, double value) {
    _getTelemetryClient()->TrackMetric(StringReference(name), value);
}

// Has to be a macro to feed into _V_TRACE macro.
#define _V_TELEMETRY_TRACE(LEVEL, LABEL, TAG, FMT, VA)                                        \
    wchar_t telemBuf[c_bufferCount];                                                          \
    _vsnwprintf_s(telemBuf, _countof(telemBuf), _TRUNCATE, (FMT), (VA));                      \
    String ^ tagString = ref new String((TAG));                                               \
    String ^ msgString = ref new String(telemBuf);                                            \
    _getTelemetryClient()->TrackTrace((LABEL) + ": [" + tagString + "] " + msgString + "\n"); \
    _V_TRACE_WIDE((LEVEL), (LABEL), (TAG), (FMT), (VA))

void TelemetryTraceVerbose(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    _V_TELEMETRY_TRACE(WINEVENT_LEVEL_VERBOSE, LABEL_VERBOSE, tag, format, varArgs);
    va_end(varArgs);
}

void TelemetryTraceInfo(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    _V_TELEMETRY_TRACE(WINEVENT_LEVEL_INFO, LABEL_INFO, tag, format, varArgs);
    va_end(varArgs);
}

void TelemetryTraceWarning(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    _V_TELEMETRY_TRACE(WINEVENT_LEVEL_WARNING, LABEL_WARNING, tag, format, varArgs);
    va_end(varArgs);
}

void TelemetryTraceError(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    _V_TELEMETRY_TRACE(WINEVENT_LEVEL_ERROR, LABEL_ERROR, tag, format, varArgs);
    va_end(varArgs);
}

void TelemetryTraceCritical(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    _V_TELEMETRY_TRACE(WINEVENT_LEVEL_CRITICAL, LABEL_CRITICAL, tag, format, varArgs);
    va_end(varArgs);
}
