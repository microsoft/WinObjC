//******************************************************************************
//
// Copyright (c) Microsoft Corporation. All rights reserved.
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
#include <functional>
#include <clang-c\Index.h>
#include <memory>
#include "ClangHelpers.h"

namespace Helpers {
bool replaceAll(std::string& in, const std::string& chars, const std::string& with);
std::string replace(std::string in, const std::string& chars, const std::string& with);
size_t splitString(const std::string& s, std::vector<std::string>& words, const std::string& separators, bool firstTokenOnly = false);
std::string newUuid();
std::string getPointerSuffix(std::string type);
std::vector<std::string> getStringBetweenSymbols(const std::string& value,
                                                 const char startSymbol,
                                                 const char endSymbol,
                                                 bool findLastOfEndSymbol = false);
std::vector<std::string> separateKeyAndValueTypes(const std::string& str, size_t& pos);
std::string getContainerName(const std::string& typeSpelling);

// If set, trueBaseType will remove all pointers ('*') from the input.
std::string baseType(const std::string& in, bool trueBaseType = false);

std::string annotate(const std::string& name, const std::string& val);

// Intersperse [separator] between each element of [data] that passes [filter], using [transform] to convert to a std::string type
template <typename Container, typename TransformFn>
static std::string addSeparators(const Container& data,
                                 const TransformFn& transform,
                                 const std::string& separator = ", ",
                                 std::function<bool(const typename Container::value_type&)> filter = [](auto val) { return true; }) {
    auto first = find_if(begin(data), end(data), filter);
    if (first == end(data)) {
        return "";
    }

    stringstream ss;
    ss << transform(*first);
    for_each(next(first), end(data), [&](const auto& val) {
        if (filter(val)) {
            ss << separator << transform(val);
        }
    });
    return ss.str();
}

std::string Trim(std::string str);

class Errors {
private:
    static unsigned int _errorCount;

public:
    static void WriteError(CXCursor cursor, const std::string& errorMsg, bool recoverable);
    static void WriteError(std::shared_ptr<ClangHelpers::SourceLocationInfo> location, const std::string& errorMsg, bool recoverable);
    static unsigned int GetErrorCount();
    static void Throw_On_Error(int errorCode);
    static void Throw_On_Error_Msg(int errorCode, const std::string& msg);
};

} // namespace Helpers
