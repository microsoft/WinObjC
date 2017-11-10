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

#include "stdafx.h"
#include <rpc.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace Helpers {
bool replaceAll(std::string& in, const std::string& chars, const std::string& with) {
    bool replaced = false;
    while (true) {
        size_t offs = in.find(chars);
        if (offs == std::string::npos)
            break;

        in.replace(offs, chars.length(), with);
        replaced = true;
    }
    return replaced;
}

std::string replace(std::string in, const std::string& chars, const std::string& with) {
    replaceAll(in, chars, with);
    return in;
}

size_t splitString(const std::string& s, std::vector<std::string>& words, const std::string& separators, bool firstTokenOnly) {
    words.resize(0);

    size_t idx = s.find_first_not_of(separators);
    while (idx != std::string::npos) {
        size_t idx2 = s.find_first_of(separators, idx);
        std::string word = s.substr(idx, (idx2 != std::string::npos) ? (idx2 - idx) : std::string::npos);
        words.push_back(word);
        if (firstTokenOnly) {
            return idx2;
        }
        idx = s.find_first_not_of(separators, idx2);
    }

    return 0;
}

std::string newUuid() {
    UUID uuid;
    UuidCreate(&uuid);

    unsigned char* str;
    UuidToStringA(&uuid, &str);

    std::string ret(reinterpret_cast<char*>(str));
    RpcStringFreeA(&str);
    return ret;
}

string getPointerSuffix(string type) {
    string suffix;
    size_t pos = type.find_first_of('*');
    if (pos != type.npos) {
        suffix = type.substr(pos);
    }

    return suffix;
}

vector<string> getStringBetweenSymbols(const string& value, const char startSymbol, const char endSymbol, bool findLastOfEndSymbol) {
    vector<string> retValues;
    string str = value;
    bool done = false;
    size_t startPos = str.find(startSymbol);
    while (startPos != str.npos) {
        size_t endPos;
        if (findLastOfEndSymbol) {
            endPos = str.find_last_of(endSymbol);
        } else {
            endPos = str.find_first_of(endSymbol);
        }

        if (endPos == str.npos) {
            Helpers::Errors::WriteError(nullptr, "Malformed metadata string provided: " + value, false);
        }

        retValues.push_back(Helpers::Trim(str.substr(startPos + 1, (endPos - startPos - 1))));
        str = str.substr(endPos + 1);
        startPos = str.find(startSymbol);
    }

    if (retValues.size() == 0) {
        retValues.push_back(value);
    }

    return retValues;
}

std::vector<std::string> separateKeyAndValueTypes(const std::string& str, size_t& pos) {
    int symbolCount = 0;
    int length = str.length();
    vector<string> ret;
    for (int i = 0; i < length; i++) {
        switch (str[i]) {
            case '[':
            case '<':
                symbolCount++;
                break;
            case ']':
            case '>':
                symbolCount--;
                break;
            case ',':
                if (symbolCount == 0) {
                    ret.push_back(str.substr(0, i));
                    ret.push_back(str.substr(i + 1));
                    pos = i;
                    return ret;
                }
        }
    }
    pos = str.npos;
    ret.push_back(str);
    return ret;
}

string getContainerName(const std::string& typeSpelling) {
    size_t pos = typeSpelling.find_first_of('<');
    if (pos == typeSpelling.npos) {
        return "";
    }

    return Helpers::Trim(Helpers::baseType(typeSpelling.substr(0, pos), true));
}

std::string baseType(const std::string& in, bool trueBaseType) {
    std::string res;

    if (in.empty()) {
        return res;
    }

    // No comments, please.
    size_t idx = in.find(" /*");
    if (idx != std::string::npos) {
        res = in.substr(0, idx);
    } else {
        res = in;
    }

    if (trueBaseType) {
        size_t pos = in.find_last_not_of("* ");
        if (pos != in.npos) {
            res = in.substr(0, pos + 1);
        } else {
            std::string err = "Invalid symbol encountered: " + in;
            Helpers::Errors::WriteError(nullptr, err.c_str(), false);
        }
    } else {
        size_t len = res.size();

        if (len <= 2) {
            res = in;
        } else if (res.substr(len - 2) == " *") {
            res = res.substr(0, len - 2);
        } else if (res.substr(len - 1) == "*") {
            res = res.substr(0, len - 1);
        }
    }

    return res;
}

std::string annotate(const std::string& name, const std::string& val) {
    return "[" + name + "(" + val + ")]\n";
}

std::string Trim(std::string str) {
    size_t pos = str.find_first_not_of(" \t");
    if (pos == str.npos) {
        return "";
    }

    str = str.substr(pos);
    pos = str.find_last_not_of(" \t");
    str = str.substr(0, pos + 1);

    return str;
}

extern "C" unsigned int g_MaxErrors;
unsigned int Errors::_errorCount = 0;

void Errors::WriteError(CXCursor cursor, const std::string& errorMsg, bool recoverable) {
    std::shared_ptr<ClangHelpers::SourceLocationInfo> location = ClangHelpers::GetSourceStartingLocation(cursor);
    Errors::WriteError(location, errorMsg, recoverable);
}

void Errors::WriteError(std::shared_ptr<ClangHelpers::SourceLocationInfo> location, const std::string& errorMsg, bool recoverable) {
    _errorCount++;

    string msg = errorMsg;
    if (!recoverable) {
        msg = "Fatal Error: " + msg;
    }

    if (location) {
        std::cerr << location->fileName << "(" << location->line << ", " << location->column << ") : " << msg;
    } else {
        std::cerr << msg;
    }
    if ((_errorCount >= g_MaxErrors) || !recoverable) {
        if (!recoverable) {
            std::cerr << "Unrecoverable error." << std::endl;
        } else {
            std::cerr << "Max errors " << g_MaxErrors << " reached." << std::endl;
        }
        exit(-1);
    }
}

void Errors::Throw_On_Error(int errorCode) {
    Throw_On_Error_Msg(errorCode, "");
}

void Errors::Throw_On_Error_Msg(int errorCode, const std::string& msg) {
    if (errorCode != 0) {
        // TODO: Use wil
        std::string error;
        error = msg + "- error code: " + std::to_string(errorCode);
        throw new std::exception(error.c_str());
    }
}

unsigned int Errors::GetErrorCount() {
    return _errorCount;
}

} // namespace Helpers
