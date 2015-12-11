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
#include "pch.h"
#include "Logger.h"

#include <WexTestClass.h>

namespace FunctionalTestLogPrivate {

// TODO::
// Move this is a common place that the project can share.
wchar_t* charToWChar(const char* text) {
    size_t size = strlen(text) + 1;
    wchar_t* wideText = new wchar_t[size];
    mbstowcs(wideText, text, size);
    return wideText;
}

} /* namespace FunctionalTestLogPrivate */

namespace FunctionalTestLog {

void LogComment(const char* comment) {
    WEX::Logging::Log::Comment(FunctionalTestLogPrivate::charToWChar(comment));
}

void LogWarning(const char* comment, const char* file, const char* function, const int line) {
    WEX::Logging::Log::Warning(FunctionalTestLogPrivate::charToWChar(comment),
                               FunctionalTestLogPrivate::charToWChar(file),
                               FunctionalTestLogPrivate::charToWChar(function),
                               line);
}

void LogError(const char* comment, const char* file, const char* function, const int line) {
    WEX::Logging::Log::Error(FunctionalTestLogPrivate::charToWChar(comment),
                             FunctionalTestLogPrivate::charToWChar(file),
                             FunctionalTestLogPrivate::charToWChar(function),
                             line);
}

void LogErrorAndAbort(const char* comment, const char* file, const char* function, const int line) {
    LogError(comment, file, function, line);
    // This will stop the current test from executing further.
    WEX::TestExecution::Verify::Fail(
        WEX::TestExecution::ErrorInfo(FunctionalTestLogPrivate::charToWChar(file), FunctionalTestLogPrivate::charToWChar(function), line));
}

} /* namespace FunctionalTestLog */