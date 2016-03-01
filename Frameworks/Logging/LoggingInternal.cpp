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

#include "LoggingInternal.h"

void _vdebugPrintf(const wchar_t* format, va_list va) {
#ifdef _DEBUG
    wchar_t buf[c_bufferCount];
    _vsnwprintf_s(buf, _countof(buf), _TRUNCATE, format, va);
    OutputDebugStringW(buf);
    if (g_isTestHookEnabled) {
        std::wstring bufString(buf);
        g_debugTestHook = bufString;
    }
#endif
}

void _debugPrintf(const wchar_t* format, ...) {
#ifdef _DEBUG
    va_list va;
    va_start(va, format);
    _vdebugPrintf(format, va);
    va_end(va);
#endif
}
