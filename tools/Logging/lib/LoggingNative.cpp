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

#include "LoggingNative.h"
#include "LoggingInternal.h"

#include <mutex>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include <winmeta.h>
#include <windows.h>
#include <TraceLoggingProvider.h>

// We export the WIL logging hook from this binary
#include "ErrorHandling.h"

bool s_isRegistered = false;

// This is where we store the WIL logging hook
namespace wil {
namespace details {

void(__stdcall* g_pfnLoggingCallback)(wil::FailureInfo const& failure) WI_NOEXCEPT;
}
}

void TraceVerbose(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    _V_TRACE_WIDE(WINEVENT_LEVEL_VERBOSE, LABEL_VERBOSE, tag, format, varArgs);
    va_end(varArgs);
}

void TraceInfo(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    _V_TRACE_WIDE(WINEVENT_LEVEL_INFO, LABEL_INFO, tag, format, varArgs);
    va_end(varArgs);
}

void TraceWarning(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    _V_TRACE_WIDE(WINEVENT_LEVEL_WARNING, LABEL_WARNING, tag, format, varArgs);
    va_end(varArgs);
}

void TraceError(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    _V_TRACE_WIDE(WINEVENT_LEVEL_ERROR, LABEL_ERROR, tag, format, varArgs);
    va_end(varArgs);
}

void TraceCritical(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    _V_TRACE_WIDE(WINEVENT_LEVEL_CRITICAL, LABEL_CRITICAL, tag, format, varArgs);
    va_end(varArgs);
}

// WIL logging hook
void __stdcall _wilLoggingCallback(wil::FailureInfo const& failure) {
    wchar_t debugString[2048];
    wil::GetFailureLogString(debugString, _countof(debugString), failure);
    TraceError(L"WIL", debugString);
}

void TraceRegister() {
    if (!s_isRegistered) {
        s_isRegistered = true;
        TraceLoggingRegister(s_traceLoggingProvider);
    }

    // Set WIL logging hook
    wil::SetResultLoggingCallback(&_wilLoggingCallback);
}

void TraceUnregister() {
    if (s_isRegistered) {
        s_isRegistered = false;
        TraceLoggingUnregister(s_traceLoggingProvider);
    }

    // Clear WIL logging hook
    wil::SetResultLoggingCallback(nullptr);
}
