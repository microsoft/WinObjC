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

#include "Starboard.h"
#include "LoggingNative.h"

#include <Foundation/NSString.h>
#include <Windows.h>

/**
 @Status Interoperable
*/
void NSLogv(NSString* format, va_list list) {
    StrongId<NSString> formattedString = [[NSString alloc] initWithFormat:format arguments:list];
    const wchar_t* wideBuffer = (const wchar_t*)[formattedString _rawTerminatedCharacters];

    // This traces to ETW in debug and release modes.
    // This prints to OutputDebugString only in debug mode.
    TraceVerbose(L"NSLog", L"%ws", wideBuffer);

// This prints to OutputDebugString only in release mode.
#ifndef _DEBUG
    OutputDebugStringW(wideBuffer);
    OutputDebugStringW(L"\n");
#endif

    // Only print to stderr if we are a console application
    if (_fileno(stderr) >= 0) {
        fprintf(stderr, "%s\n", [formattedString UTF8String]);
    }
}

/**
 @Status Interoperable
*/
void NSLog(NSString* fmt, ...) {
    va_list list;
    va_start(list, fmt);
    NSLogv(fmt, list);
    va_end(list);
}
