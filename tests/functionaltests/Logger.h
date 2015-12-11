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
#pragma once

#include <string>
#include <vector>

#ifdef __OBJC__
#include <objc/objc.h>
#include <Foundation/NSString.h>
#endif

namespace FunctionalTestLogPrivate {

#if defined __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wformat-security"
#endif // __clang__

template <typename... Args>
char* Format(const char* message, Args... args) {
#ifdef __OBJC__
    static NSString* (*formatImp)(id, SEL, NSString*, ...) = reinterpret_cast<decltype(formatImp)>(
        class_getMethodImplementation(object_getClass([NSString class]), @selector(stringWithFormat:)));
    NSString* string = formatImp([NSString class], @selector(stringWithFormat:), [NSString stringWithUTF8String:message], args...);
    return const_cast<char*>([string UTF8String]);
#else
    char buffer[4096];
    _snprintf_s(buffer, sizeof(buffer), sizeof(buffer), message, args...);
    return buffer;
#endif
}

#if defined __clang__
#pragma clang diagnostic pop
#endif // __clang__

} /* namespace FunctionalTestLogPrivate */

namespace FunctionalTestLog {

// WEX logger wrapper to log a test comment.
// @param comment comment to log.
void LogComment(const char* comment);

// WEX logger wrapper to log a test warning.
// @param comment warning comment to log.
// @param file file name from which the warning was logged.
// @param function function name from which the warning was logged.
// @param line line number from which the warning was logged.
void LogWarning(const char* comment, const char* file, const char* function, const int line);

// WEX logger wrapper to log a test error.
// @param comment error comment to log.
// @param file file name from which the error was logged.
// @param function function name from which the error was logged.
// @param line line number from which the error was logged.
// @param continueTest continues test execution after logging the error.
void LogError(const char* comment, const char* file, const char* function, const int line);

// WEX logger wrapper to log a test error and abort the current test from executing further.
// @param comment error comment to log.
// @param file file name from which the error was logged.
// @param function function name from which the error was logged.
// @param line line number from which the error was logged.
// @param continueTest continues test execution after logging the error.
void LogErrorAndAbort(const char* comment, const char* file, const char* function, const int line);

} /* namespace FunctionalTestLog */
