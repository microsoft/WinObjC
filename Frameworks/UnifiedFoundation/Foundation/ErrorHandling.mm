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

#import <Windows.h>

#import "ErrorHandling.h"

namespace {

// Create the extra information we can communicate as part of the exception:
NSDictionary* _createFailureInfoDict(const wil::FailureInfo& fi) {
    id ret = [NSDictionary dictionaryWithObjectsAndKeys:[NSString stringWithUTF8String:fi.pszFile],
                                                        [NSString stringWithCString:"file"],
                                                        [NSString stringWithUTF8String:fi.pszFunction],
                                                        [NSString stringWithCString:"function"],
                                                        [NSNumber numberWithInt:fi.uLineNumber],
                                                        [NSString stringWithCString:"line"],
                                                        [NSNumber numberWithInt:fi.hr],
                                                        [NSString stringWithCString:"hresult"],
                                                        nil];

    return ret;
}
}

const NSString* _NSHResultErrorDictKey = @"hresult";

// Construct an NSError for the out parameter representing a failure info from WRL:
NSError* _NSErrorFromFailureInfo(const wil::FailureInfo& fi) {
    return [NSError errorWithDomain:_hresultDomain() code:fi.hr userInfo:_createFailureInfoDict(fi)];
}

NSString* _NSStringFromHResult(HRESULT hr) {
    wchar_t errorText[256];
    errorText[0] = L'\0';
    FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                   nullptr,
                   hr,
                   MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                   errorText,
                   ARRAYSIZE(errorText),
                   nullptr);
    return [NSString stringWithCharacters:reinterpret_cast<const unichar*>(errorText) length:wcslen(errorText)];
}

// This is a helper to create NSExceptions from HRESULTs:
NSException* _NSExceptionFromFailureInfo(const wil::FailureInfo& fi) {
    NSString* msg = [NSString string];
    if (fi.pszMessage) {
        msg = [NSString stringWithCharacters:reinterpret_cast<const unichar*>(fi.pszMessage) length:wcslen(fi.pszMessage)];
    }

    return [NSException _exceptionWithHRESULT:fi.hr reason:msg userInfo:_createFailureInfoDict(fi)];
}