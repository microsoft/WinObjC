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

#include "Logging.h"
#include "LoggingInternal.h"

#include <mutex>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include <winmeta.h>
#include <windows.h>
#include <TraceLoggingProvider.h>

// Init for WinObjCTraceLoggingProvider with GUID {E4BABC11-825E-4D44-8104-D6CFAC39AE13}
TRACELOGGING_DECLARE_PROVIDER(s_traceLoggingProvider);

TRACELOGGING_DEFINE_PROVIDER(s_traceLoggingProvider,
                             "WinObjCTraceLoggingProvider",
                             (0xe4babc11, 0x825e, 0x4d44, 0x81, 0x4, 0xd6, 0xcf, 0xac, 0x39, 0xae, 0x13));

bool s_isRegistered = false;
std::mutex s_isRegisteredMutex;

void TraceVerbose(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    TraceRegister();
    _V_TRACE(WINEVENT_LEVEL_VERBOSE, LABEL_VERBOSE, tag, format, varArgs);
    va_end(varArgs);
}

void TraceInfo(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    TraceRegister();
    _V_TRACE(WINEVENT_LEVEL_INFO, LABEL_INFO, tag, format, varArgs);
    va_end(varArgs);
}

void TraceWarning(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    TraceRegister();
    _V_TRACE(WINEVENT_LEVEL_WARNING, LABEL_WARNING, tag, format, varArgs);
    va_end(varArgs);
}

void TraceError(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    TraceRegister();
    _V_TRACE(WINEVENT_LEVEL_ERROR, LABEL_ERROR, tag, format, varArgs);
    va_end(varArgs);
}

void TraceCritical(const wchar_t* tag, const wchar_t* format, ...) {
    va_list varArgs;
    va_start(varArgs, format);
    TraceRegister();
    _V_TRACE(WINEVENT_LEVEL_CRITICAL, LABEL_CRITICAL, tag, format, varArgs);
    va_end(varArgs);
}

void TraceRegister() {
    std::lock_guard<std::mutex> lock(s_isRegisteredMutex);

    if (!s_isRegistered) {
        s_isRegistered = true;
        TraceLoggingRegister(s_traceLoggingProvider);
    }
}

void TraceUnregister() {
    std::lock_guard<std::mutex> lock(s_isRegisteredMutex);

    if (s_isRegistered) {
        s_isRegistered = false;
        TraceLoggingUnregister(s_traceLoggingProvider);
    }
}

void EbrDebugLogShim(const char* format, ...) {
#ifdef _DEBUG
    va_list va;

    va_start(va, format);
    char buf[c_bufferCount];
    int len = vsnprintf_s(buf, _countof(buf), _TRUNCATE, format, va);
    va_end(va);

    // Trim off newline for EBR debug.
    if ((len > 0) && (len < (c_bufferCount - 1)) && (buf[len - 1] == '\n')) {
        buf[len - 1] = '\0';
    }
    wchar_t wbuf[c_bufferCount];
    size_t wlen;
    mbstowcs_s(&wlen, wbuf, _countof(wbuf), buf, _TRUNCATE);
    TraceVerbose(L"EbrDebugLog", wbuf);
#endif
}