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

#include <string.h>
#include <sstream>
#include <iterator> // std::ostream_iterator

#include "stringutils.h"

bool matchWildcardList(const String& str, const StringVec& wildcardList) {
    for (unsigned i = 0; i < wildcardList.size(); i++) {
        if (WildcardMatch(str.c_str(), wildcardList[i].c_str())) {
            return true;
        }
    }
    return false;
}

static char getUnescapedChar(char c) {
    switch (c) {
        case 't':
            return '\t';
        case 'r':
            return '\r';
        case 'n':
            return '\n';
        default:
            return c;
    }
}

static char getEscapedChar(char c) {
    switch (c) {
        case '\t':
            return 't';
        case '\r':
            return 'r';
        case '\n':
            return 'n';
        default:
            return c;
    }
}

String processEscapes(const String& str) {
    // Process all escaped characters
    String ret;
    for (unsigned i = 0; i < str.length(); i++) {
        if (str[i] == '\\' && i < str.length() - 1)
            ret.push_back(getUnescapedChar(str[++i]));
        else
            ret.push_back(str[i]);
    }

    return ret;
}

String addEscapes(const String& str, const String& specialChars) {
    String ret;
    for (unsigned i = 0; i < str.length(); i++) {
        if (String::npos != specialChars.find_first_of(str[i])) {
            ret += '\\';
            ret += getEscapedChar(str[i]);
        } else {
            ret += str[i];
        }
    }

    return ret;
}

String removeQuotes(const String& str, const String& quotes) {
    bool quoted = false;
    char savedQuote;
    String ret;

    for (unsigned i = 0; i < str.length(); i++) {
        if (String::npos != quotes.find_first_of(str[i])) {
            if (quoted && str[i] == savedQuote) {
                quoted = false;
                continue;
            } else if (!quoted) {
                quoted = true;
                savedQuote = str[i];
                continue;
            }
        }
        ret.push_back(str[i]);
    }

    return ret;
}

String quoteIfNeeded(const String& str, bool forceQuote) {
    static String specialChars(" \"\\'");
    for (unsigned i = 0; !forceQuote && i < str.length(); i++)
        forceQuote |= (specialChars.find_first_of(str[i]) != string::npos);

    if (forceQuote)
        return "\"" + addEscapes(str, "\"") + "\"";
    else
        return str;
}

bool strBeginsWith(const String& str, const String& needle) {
    return (!str.compare(0, needle.length(), needle));
}

bool strEndsWith(const String& str, const String& needle) {
    if (str.length() >= needle.length()) {
        return (0 == str.compare(str.length() - needle.length(), needle.length(), needle));
    }
    return false;
}

String trim(const String& str, const String& whitespace) {
    std::size_t strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return "";

    std::size_t strEnd = str.find_last_not_of(whitespace);
    std::size_t strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}

// http://stackoverflow.com/questions/5288396/c-ostream-out-manipulation/5289170#5289170
template <typename T>
String joinStrings(const T& elements, const String& separator) {
    switch (elements.size()) {
        case 0:
            return "";
        case 1:
            return *elements.begin();
        default:
            std::ostringstream os;
            std::copy(elements.begin(), --elements.end(), std::ostream_iterator<String>(os, separator.c_str()));
            os << *elements.rbegin();
            return os.str();
    }
}

template String joinStrings<StringList>(const StringList& elements, const String& separator);
template String joinStrings<StringVec>(const StringVec& elements, const String& separator);
template String joinStrings<StringSet>(const StringSet& elements, const String& separator);

String sb_replace(const String& str, const String& pattern, const String& dstPattern, int count) {
    String retStr;
    String::size_type pos;

    int szStr = str.length();
    int szPattern = pattern.size();
    int i = 0;
    int l_count = 0;
    if (-1 == count) // replace all
        count = szStr;

    for (i = 0; i < szStr; i++) {
        pos = str.find(pattern, i);

        if (std::string::npos == pos)
            break;
        if (pos < szStr) {
            std::string s = str.substr(i, pos - i);
            retStr += s;
            retStr += dstPattern;
            i = pos + pattern.length() - 1;
            if (++l_count >= count) {
                i++;
                break;
            }
        }
    }
    retStr += str.substr(i);
    return retStr;
}

String sb_hash(const String& str) {
    // Get the filename hash
    std::hash<String> str_hash;
    std::size_t hash = str_hash(str);

    // Convert the hash to a string :(
    std::ostringstream ss;
    ss << hash;
    return ss.str();
}

bool sb_getenv(const String& varName, String& varValue) {
    char* varValuePtr = getenv(varName.c_str());
    if (varValuePtr)
        varValue = varValuePtr;
    return varValuePtr;
}
