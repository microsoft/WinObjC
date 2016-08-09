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
#import "Starboard.h"
#import "LoggingNative.h"
#import <Foundation/NSString.h>
#import <windows.h>
#import "NSLogInternal.h"
#import "StringHelpers.h"

// Only used in Foundation unit tests.
bool g_isNSLogTestHookEnabled = false;

/**
 @Status Interoperable
*/
void NSLogv(NSString* format, va_list list) {
    StrongId<NSString> formattedString = [[NSString alloc] initWithFormat:format arguments:list];
    std::wstring wideBuffer = Strings::NarrowToWide<std::wstring>(formattedString);

    // This traces to ETW in debug and release modes.
    // This prints to OutputDebugString only in debug mode.
    TraceVerbose(L"NSLog", L"%ws", wideBuffer.c_str());

// This prints to OutputDebugString only in release mode.
#ifndef _DEBUG
    OutputDebugStringW(wideBuffer.c_str());
    OutputDebugStringW(L"\n");
#endif

    // Only print to stderr if we are a console application
    if (_fileno(stderr) >= 0 && !g_isNSLogTestHookEnabled) {
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
