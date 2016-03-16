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
#ifdef __clang__
#error This file must be compiled with CL.exe
#endif

#pragma once

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include <winmeta.h>
#include <windows.h>
#include <TraceLoggingProvider.h>
#include "LoggingTesting.h"

// Init for WinObjCTraceLoggingProvider with GUID {E4BABC11-825E-4D44-8104-D6CFAC39AE13}
TRACELOGGING_DECLARE_PROVIDER(s_traceLoggingProvider);

// These must be pre-processor because of the TraceLogging macros.
#define FIELD_NAME_TAG "Tag"
#define FIELD_NAME_MESSAGE "Message"
#define EVENT_NAME_TRACE "Trace"
#define LABEL_VERBOSE "V"
#define LABEL_INFO "I"
#define LABEL_WARNING "W"
#define LABEL_ERROR "E"
#define LABEL_CRITICAL "C"

#define TRACE_FORMAT_WIDE L"%hs/%ws: %ws\n"
#define TRACE_FORMAT_NARROW L"%hs/%ws: %hs\n"

const unsigned int c_bufferCount = 1024;

// Print to debug output window using va_list
void _vdebugPrintf(const wchar_t* format, va_list va);

// Print to debug output window using varargs
void _debugPrintf(const wchar_t* format, ...);

// Print formatted message to ETL.
#define _V_ETL_TRACE(LEVEL, TAG, BUF)                               \
    TraceLoggingWrite(s_traceLoggingProvider,                       \
                      EVENT_NAME_TRACE,                             \
                      TraceLoggingValue((TAG), FIELD_NAME_TAG),     \
                      TraceLoggingValue((BUF), FIELD_NAME_MESSAGE), \
                      TraceLoggingLevel((LEVEL)));

#define _V_ETL_WIDE_TEST_HOOK(LEVEL, TAG, BUF) \
    if (g_isTestHookEnabled) {                 \
        g_etlLevelTestHook = (LEVEL);          \
        std::wstring tagString((TAG));         \
        std::wstring bufString((BUF));         \
        g_etlTagTestHook = tagString;          \
        g_etlBufferTestHook = bufString;       \
    }

#define _V_ETL_NARROW_TEST_HOOK(LEVEL, TAG, BUF) \
    if (g_isTestHookEnabled) {                   \
        g_etlLevelTestHook = (LEVEL);            \
        std::wstring tagString((TAG));           \
        std::string bufString((BUF));            \
        g_etlTagTestHook = tagString;            \
        g_etlBufferNarrowTestHook = bufString;   \
    }

// Trace to ETL and VS debug output.
// This must be a macro because otherwise it doesn't work with the TraceLogging macros.
#define _V_TRACE_WIDE(LEVEL, LABEL, TAG, FMT, VA)                      \
    wchar_t wideBuf[c_bufferCount];                                    \
    _vsnwprintf_s(wideBuf, _countof(wideBuf), _TRUNCATE, (FMT), (VA)); \
    _debugPrintf(TRACE_FORMAT_WIDE, (LABEL), (TAG), wideBuf);          \
    _V_ETL_TRACE((LEVEL), (TAG), wideBuf)                              \
    _V_ETL_WIDE_TEST_HOOK((LEVEL), (TAG), wideBuf)

#define _V_TRACE_NARROW(LEVEL, LABEL, TAG, FMT, VA)                       \
    char narrowBuf[c_bufferCount];                                        \
    _vsnprintf_s(narrowBuf, _countof(narrowBuf), _TRUNCATE, (FMT), (VA)); \
    _debugPrintf(TRACE_FORMAT_NARROW, (LABEL), (TAG), narrowBuf);         \
    _V_ETL_TRACE((LEVEL), (TAG), narrowBuf)                               \
    _V_ETL_NARROW_TEST_HOOK((LEVEL), (TAG), narrowBuf)
