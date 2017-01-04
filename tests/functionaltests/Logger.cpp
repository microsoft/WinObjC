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

thread_local std::wstring FunctionalTestLog::_userComment;

void FunctionalTestLog::SetUserComment(const std::vector<char>& comment) {
    FunctionalTestLog::_userComment = Strings::NarrowToWide<std::wstring>(comment.data());
}

void FunctionalTestLog::LogComment(const char* comment) {
    WEX::Logging::Log::Comment(Strings::NarrowToWide<std::wstring>(comment).c_str());
}

void FunctionalTestLog::LogWarning(const char* comment, const char* file, const char* function, const int line) {
    if (!FunctionalTestLog::_userComment.empty()) {
        std::wstring newComment = FunctionalTestLog::_userComment + L" \n " + Strings::NarrowToWide<std::wstring>(comment);
        FunctionalTestLog::_userComment.clear();
        WEX::Logging::Log::Warning(newComment.c_str(),
                                   Strings::NarrowToWide<std::wstring>(file).c_str(),
                                   Strings::NarrowToWide<std::wstring>(function).c_str(),
                                   line);
    } else {
        WEX::Logging::Log::Warning(Strings::NarrowToWide<std::wstring>(comment).c_str(),
                                   Strings::NarrowToWide<std::wstring>(file).c_str(),
                                   Strings::NarrowToWide<std::wstring>(function).c_str(),
                                   line);
    }
}

void FunctionalTestLog::LogError(const char* comment, const char* file, const char* function, const int line) {
    if (!FunctionalTestLog::_userComment.empty()) {
        std::wstring newComment = FunctionalTestLog::_userComment + L" \n " + Strings::NarrowToWide<std::wstring>(comment);
        FunctionalTestLog::_userComment.clear();
        WEX::Logging::Log::Error(newComment.c_str(),
                                 Strings::NarrowToWide<std::wstring>(file).c_str(),
                                 Strings::NarrowToWide<std::wstring>(function).c_str(),
                                 line);
    } else {
        WEX::Logging::Log::Error(Strings::NarrowToWide<std::wstring>(comment).c_str(),
                                 Strings::NarrowToWide<std::wstring>(file).c_str(),
                                 Strings::NarrowToWide<std::wstring>(function).c_str(),
                                 line);
    }
}

void FunctionalTestLog::LogErrorAndAbort(const char* comment, const char* file, const char* function, const int line) {
    LogError(comment, file, function, line);

    // This will stop the current test from executing further.
    WEX::TestExecution::Verify::Fail(WEX::TestExecution::ErrorInfo(Strings::NarrowToWide<std::wstring>(file).c_str(),
                                                                   Strings::NarrowToWide<std::wstring>(function).c_str(),
                                                                   line));
}