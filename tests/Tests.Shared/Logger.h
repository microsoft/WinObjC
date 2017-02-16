//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#include <mutex>
#include <string>
#include <vector>

class TestLog {
public:
    // WEX logger wrapper to log a test comment.
    // @param comment comment to log.
    static TestLog LogComment(const char* comment);

    // WEX logger wrapper to log a test warning.
    // @param comment warning comment to log.
    // @param file file name from which the warning was logged.
    // @param function function name from which the warning was logged.
    // @param line line number from which the warning was logged.
    static TestLog LogWarning(const char* comment, const char* file, const char* function, const int line);

    // WEX logger wrapper to log a test error.
    // @param comment error comment to log.
    // @param file file name from which the error was logged.
    // @param function function name from which the error was logged.
    // @param line line number from which the error was logged.
    // @param continueTest continues test execution after logging the error.
    static TestLog LogError(const char* comment, const char* file, const char* function, const int line);

    // WEX logger wrapper to log a test error and abort the current test from executing further.
    // @param comment error comment to log.
    // @param file file name from which the error was logged.
    // @param function function name from which the error was logged.
    // @param line line number from which the error was logged.
    // @param continueTest continues test execution after logging the error.
    static TestLog LogErrorAndAbort(const char* comment, const char* file, const char* function, const int line);

    static void SetUserComment(const std::vector<char>& comment);

    TestLog& operator<<(const char* value);

    template <typename T>
    TestLog& operator<<(const T& value) {
        return operator<<(std::to_string(value).c_str());
    }

private:
    enum Severity {
        Comment,
        Warning,
        Error,
    } _severity;

    thread_local static std::wstring _userComment;

    TestLog(Severity sev) : _severity(sev){};
}; /* class TestLog */
