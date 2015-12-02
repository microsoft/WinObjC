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

#include <Windows.h>
#include "Starboard.h"
#include <Foundation/Foundation.h>
#include <Foundation/NSArray.h>
#include "error-handling.h"

namespace {

// We need to lazy-load these because we may use them from CoreFoundation and it does not have access to Foundation directly.
IWLazyClassLookup _LazyNSDictionary("NSDictionary");
IWLazyClassLookup _LazyNSNumber("NSNumber");

// Create the extra information we can communicate as part of the exception:
NSDictionary* _createFailureInfoDict(const wil::FailureInfo& fi) {
    id ret = [_LazyNSDictionary dictionaryWithObjectsAndKeys:
        [_LazyNSString stringWithUTF8String:fi.pszFile], [_LazyNSString stringWithCString:"file"],
        [_LazyNSString stringWithUTF8String:fi.pszFunction], [_LazyNSString stringWithCString:"function"],
        [_LazyNSNumber numberWithInt:fi.uLineNumber], [_LazyNSString stringWithCString:"line"],
        [_LazyNSNumber numberWithInt:fi.hr], [_LazyNSString stringWithCString:"hresult"],
        nil
    ];

    return ret;
}

}

// Construct an NSError for the out parameter representing a failure info from WRL:
NSError* _errorFromFailureInfo(const wil::FailureInfo& fi) {
    return [_LazyNSError errorWithDomain:_hresultDomain() code:fi.hr userInfo:_createFailureInfoDict(fi)];
}

NSString* _stringFromHresult(HRESULT hr) {
    wchar_t errorText[256];
    errorText[0] = L'\0';
    FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                   nullptr,
                   hr,
                   MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                   errorText,
                   ARRAYSIZE(errorText),
                   nullptr);
    return [_LazyNSString stringWithCharacters:reinterpret_cast<const unichar*>(errorText) length:wcslen(errorText)];
}


// This has to be exported so that we can use it in wil/result.h, since we can't use @"" because that requires CFConstantString.
NSString* _hresultErrorDictKey() {
    static NSString* s_hresultErrorDictKey = [_LazyNSString stringWithCString:"hresult"];
    return s_hresultErrorDictKey;
}

// This is a helper to create NSExceptions from HRESULTs:
NSException* _exceptionFromFailureInfo(const wil::FailureInfo& fi) {
    NSString* msg = [_LazyNSString string];
    if (fi.pszMessage) {
        msg = [_LazyNSString stringWithCharacters:reinterpret_cast<const unichar*>(fi.pszMessage) length:wcslen(fi.pszMessage)];
    }

    return [_LazyNSException exceptionWithName:_exceptionName() reason:msg userInfo:_createFailureInfoDict(fi)];
}


unsigned long objc_getCurrentThreadId() {
    return ::GetCurrentThreadId();
}

long objc_interlockedIncrementNoFence(long volatile* addend) {
    return ::InterlockedIncrementNoFence(addend);
}

unsigned long objc_getLastError() {
    return ::GetLastError();
}

void objc_copyMemory(void* destination, const void* source, size_t length) {
    ::CopyMemory(destination, source, length);
}

void objc_zeroMemory(void* destination, size_t length) {
    ::ZeroMemory(destination, length);
}

unsigned long objc_formatMessageW(unsigned long flags, const void* source, unsigned long messageId, unsigned long languageId, wchar_t* buffer, unsigned long size, va_list* arguments) {
    return ::FormatMessageW(flags, source, messageId, languageId, buffer, size, arguments);
}

void objc_outputDebugStringW(wchar_t* outputString) {
    return ::OutputDebugStringW(outputString);
}

long objc_interlockedDecrementRelease(long volatile* addend) {
    return ::InterlockedDecrementRelease(addend);
}

void* objc_interlockedCompareExchangePointer(void* volatile* destination, void* exchange, void* comparand) {
    return ::InterlockedCompareExchangePointer(destination, exchange, comparand);
}

bool failFastOnUnimplemented() {
    return false;
}
