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

unsigned long starboardGetCurrentThreadId() {
    return ::GetCurrentThreadId();
}

long starboardInterlockedIncrementNoFence(long volatile* addend) {
    return ::InterlockedIncrementNoFence(addend);
}

unsigned long starboardGetLastError() {
    return ::GetLastError();
}

void starboardCopyMemory(void* destination, const void* source, size_t length) {
    ::CopyMemory(destination, source, length);
}

void starboardZeroMemory(void* destination, size_t length) {
    ::ZeroMemory(destination, length);
}

unsigned long starboardFormatMessageW(unsigned long flags,
                                  const void* source,
                                  unsigned long messageId,
                                  unsigned long languageId,
                                  wchar_t* buffer,
                                  unsigned long size,
                                  va_list* arguments) {
    return ::FormatMessageW(flags, source, messageId, languageId, buffer, size, arguments);
}

void starboardOutputDebugStringW(wchar_t* outputString) {
    return ::OutputDebugStringW(outputString);
}

long starboardInterlockedDecrementRelease(long volatile* addend) {
    return ::InterlockedDecrementRelease(addend);
}

void* starboardInterlockedCompareExchangePointer(void* volatile* destination, void* exchange, void* comparand) {
    return ::InterlockedCompareExchangePointer(destination, exchange, comparand);
}

bool failFastOnUnimplemented() {
    return false;
}
