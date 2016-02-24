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
#include "pch.h"
#include "Logger.h"
#include <gtest-api.h>
#include <WexTestClass.h>
#include <StringHelpers.h>

namespace FunctionalTestLogPrivate {

// TODO::
// Move this is a common place that the project can share.
wchar_t* CharToWChar(const char* text) {
    size_t size = strlen(text) + 1;
    wchar_t* wideText = new wchar_t[size];
    mbstowcs_s(nullptr, wideText, size, text, size);
    return wideText;
}

std::vector<char> Concat(const std::vector<char>& string1, const char* string2) {
    std::vector<char> buffer(2048);
    snprintf(buffer.data(), 2048, "%s \n %s", string1.data(), string2);
    return buffer;
}

} /* namespace FunctionalTestLogPrivate */

thread_local std::vector<char> FunctionalTestLog::_userComment;

void FunctionalTestLog::LogComment(const char* comment) {
    WEX::Logging::Log::Comment(FunctionalTestLogPrivate::CharToWChar(comment));
}

void FunctionalTestLog::LogWarning(const char* comment, const char* file, const char* function, const int line) {
    if (!FunctionalTestLog::_userComment.empty()) {
        std::vector<char> newComment;
        newComment = FunctionalTestLogPrivate::Concat(FunctionalTestLog::_userComment, comment);
        FunctionalTestLog::_userComment.clear();
        WEX::Logging::Log::Warning(FunctionalTestLogPrivate::CharToWChar(newComment.data()),
                                   FunctionalTestLogPrivate::CharToWChar(file),
                                   FunctionalTestLogPrivate::CharToWChar(function),
                                   line);
    } else {
        WEX::Logging::Log::Warning(FunctionalTestLogPrivate::CharToWChar(comment),
                                   FunctionalTestLogPrivate::CharToWChar(file),
                                   FunctionalTestLogPrivate::CharToWChar(function),
                                   line);
    }
}

void FunctionalTestLog::LogError(const char* comment, const char* file, const char* function, const int line) {
    if (!FunctionalTestLog::_userComment.empty()) {
        std::vector<char> newComment;
        newComment = FunctionalTestLogPrivate::Concat(FunctionalTestLog::_userComment, comment);
        FunctionalTestLog::_userComment.clear();
        WEX::Logging::Log::Error(FunctionalTestLogPrivate::CharToWChar(newComment.data()),
                                 FunctionalTestLogPrivate::CharToWChar(file),
                                 FunctionalTestLogPrivate::CharToWChar(function),
                                 line);
    } else {
        WEX::Logging::Log::Error(FunctionalTestLogPrivate::CharToWChar(comment),
                                 FunctionalTestLogPrivate::CharToWChar(file),
                                 FunctionalTestLogPrivate::CharToWChar(function),
                                 line);
    }
}

void FunctionalTestLog::LogErrorAndAbort(const char* comment, const char* file, const char* function, const int line) {
    if (!FunctionalTestLog::_userComment.empty()) {
        std::vector<char> newComment;
        newComment = FunctionalTestLogPrivate::Concat(FunctionalTestLog::_userComment, comment);
        FunctionalTestLog::_userComment.clear();
        LogError(newComment.data(), file, function, line);
    } else {
        LogError(comment, file, function, line);
    }

    // This will stop the current test from executing further.
    WEX::TestExecution::Verify::Fail(
        WEX::TestExecution::ErrorInfo(FunctionalTestLogPrivate::CharToWChar(file), FunctionalTestLogPrivate::CharToWChar(function), line));
}