//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#include "Starboard.h"
#include "ErrorHandling.h"

#include <Windows.h>

/* TEMPORARY: Intrinsic shims, removal contingent upon VSO 159174/159179 */
extern "C" void __fastfail(unsigned) {
    RaiseFailFastException(nullptr, nullptr, 0);

    // If control reaches here, abort
    abort();
}
/* End Intrinsic Shims */

unsigned long _loggingGetCurrentThreadId() {
    return ::GetCurrentThreadId();
}

long _loggingInterlockedIncrementNoFence(long volatile* addend) {
    return ::InterlockedIncrementNoFence(addend);
}

unsigned long _loggingGetLastError() {
    return ::GetLastError();
}

void _loggingCopyMemory(void* destination, const void* source, size_t length) {
    ::CopyMemory(destination, source, length);
}

void _loggingZeroMemory(void* destination, size_t length) {
    ::ZeroMemory(destination, length);
}

unsigned long _loggingFormatMessageW(unsigned long flags,
                                     const void* source,
                                     unsigned long messageId,
                                     unsigned long languageId,
                                     wchar_t* buffer,
                                     unsigned long size,
                                     va_list* arguments) {
    return ::FormatMessageW(flags, source, messageId, languageId, buffer, size, arguments);
}

void _loggingOutputDebugStringW(wchar_t* outputString) {
    return ::OutputDebugStringW(outputString);
}

long _loggingInterlockedDecrementRelease(long volatile* addend) {
    return ::InterlockedDecrementRelease(addend);
}

void* _loggingInterlockedCompareExchangePointer(void* volatile* destination, void* exchange, void* comparand) {
    return ::InterlockedCompareExchangePointer(destination, exchange, comparand);
}

bool _loggingFailFastOnUnimplemented() {
    return false;
}
