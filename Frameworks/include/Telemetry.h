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

#ifdef __cplusplus
extern "C" {
#endif
//
// Send a telemetry event with the given name. E.g.:
//
// TelemetryEvent(L"MY_EVENT");
//
void TelemetryEvent(const wchar_t* name);

//
// Send telemetry metric with name and value. E.g.:
//
// TelemetryMetric(L"MY_METRIC", 1.23);
//
void TelemetryMetric(const wchar_t* name, double value);

//
// Send a verbose telemetry trace. Also sends to local TraceVerbose. E.g.:
//
// TelemetryTraceVerbose(L"MY_TAG", "Message");
//
void TelemetryTraceVerbose(const wchar_t* tag, const wchar_t* format, ...);

//
// Send an info telemetry trace. Also sends to local TraceInfo.
//
void TelemetryTraceInfo(const wchar_t* tag, const wchar_t* format, ...);

//
// Send a warning telemetry trace. Also sends to local TraceWarning.
//
void TelemetryTraceWarning(const wchar_t* tag, const wchar_t* format, ...);

//
// Send an error telemetry trace. Also sends to local TraceError.
//
void TelemetryTraceError(const wchar_t* tag, const wchar_t* format, ...);

//
// Send a critical telemetry trace. Also sends to local TraceCritical.
//
void TelemetryTraceCritical(const wchar_t* tag, const wchar_t* format, ...);

#ifdef __cplusplus
}
#endif