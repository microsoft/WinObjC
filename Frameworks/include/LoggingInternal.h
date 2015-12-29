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

// These must be pre-processor because of the TraceLogging macros.
#define FIELD_NAME_TAG "Tag"
#define FIELD_NAME_MESSAGE "Message"
#define EVENT_NAME_TRACE "Trace"
#define LABEL_VERBOSE "V"
#define LABEL_INFO "I"
#define LABEL_WARNING "W"
#define LABEL_ERROR "E"
#define LABEL_CRITICAL "C"
#define TRACE_FORMAT L"%s: [%s] "

const unsigned int c_bufferCount = 1024;

// Print to debug output window using va_list
void _vdebugPrintf(const wchar_t* format, va_list va);

// Print to debug output window using varargs
void _debugPrintf(const wchar_t* format, ...);

// Print formatted message to VS debug output.
#define _V_DEBUG_TRACE(LABEL, TAG, FMT, VA)     \
    _debugPrintf(TRACE_FORMAT, (LABEL), (TAG)); \
    _vdebugPrintf((FMT), (VA));                 \
    _debugPrintf(L"\n");

// Trace to ETL and VS debug output.
// This must be a macro because otherwise it doesn't work with the TraceLogging macros.
#define _V_TRACE(LEVEL, LABEL, TAG, FMT, VA)                      \
    wchar_t buf[c_bufferCount];                                   \
    _vsnwprintf_s(buf, _countof(buf), _TRUNCATE, (FMT), (VA));    \
    _V_DEBUG_TRACE((LABEL), (TAG), (FMT), (VA));                  \
                                                                  \
    TraceLoggingWrite(s_traceLoggingProvider,                     \
                      EVENT_NAME_TRACE,                           \
                      TraceLoggingValue((TAG), FIELD_NAME_TAG),   \
                      TraceLoggingValue(buf, FIELD_NAME_MESSAGE), \
                      TraceLoggingLevel((LEVEL)));