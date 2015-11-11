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

#include "error-handling.h"
#include <windows.h>

OBJCRT_EXPORT extern unsigned long objc_getCurrentThreadId() {
    return ::GetCurrentThreadId();
}

OBJCRT_EXPORT extern long objc_interlockedIncrementNoFence(long volatile* addend) {
    return ::InterlockedIncrementNoFence(addend);
}

OBJCRT_EXPORT extern unsigned long objc_getLastError() {
    return ::GetLastError();
}

OBJCRT_EXPORT extern void objc_copyMemory(void* destination, const void* source, size_t length) {
    ::CopyMemory(destination, source, length);
}

OBJCRT_EXPORT extern void objc_zeroMemory(void* destination, size_t length) {
    ::ZeroMemory(destination, length);
}

OBJCRT_EXPORT extern unsigned long objc_formatMessageW(unsigned long flags, const void* source, unsigned long messageId, unsigned long languageId, wchar_t* buffer, unsigned long size, va_list* arguments) {
    return ::FormatMessageW(flags, source, messageId, languageId, buffer, size, arguments);
}

OBJCRT_EXPORT extern void objc_outputDebugStringW(wchar_t* outputString) {
    return ::OutputDebugStringW(outputString);
}

OBJCRT_EXPORT extern long objc_interlockedDecrementRelease(long volatile* addend) {
    return ::InterlockedDecrementRelease(addend);
}

OBJCRT_EXPORT extern void* objc_interlockedCompareExchangePointer(void* volatile* destination, void* exchange, void* comparand) {
    return ::InterlockedCompareExchangePointer(destination, exchange, comparand);
}

// These two are temporary, since they're supposed to be intrinsics. When our compiler supports them correct they will be removed:

OBJCRT_EXPORT extern "C" void* _ReturnAddress() {
    return nullptr;
}

OBJCRT_EXPORT extern "C" void __fastfail(unsigned) {
    RaiseFailFastException(nullptr, nullptr, 0);
}
