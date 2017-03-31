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

#ifndef _STRINGUTILS_H_
#define _STRINGUTILS_H_

#include <algorithm>
#include <string>

#include "types.h"
#include "tokenizer.h"

/*
 * Converts all characters of str to lower case, in place.
 */
inline String strToLower(const String& str) {
    String tmp(str);
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
    return tmp;
}

inline String strToUpper(const String& str) {
    String tmp(str);
    std::transform(tmp.begin(), tmp.end(), tmp.begin(), ::toupper);
    return tmp;
}

/*
 * Returns true if input string pszString matches the pszMatch mask.
 *   A ? sign matches any character, except an empty string.
 *   A * sign matches any string inclusive an empty string.
 *   Characters are compared caseless.
 */
bool WildcardMatch(const char* pszString, const char* pszMatch);

/*
 * Returns true if str matches any members of wildcardList.
 */
bool matchWildcardList(const String& str, const StringVec& wildcardList);

/*
 * Returns a string with all escaped characters transformed.
 * Quoted characters are not processed.
 */
String processEscapes(const String& str);

/*
 * Returns a string with all special characters escaped.
 */
String addEscapes(const String& str, const String& specialChars = "\"\\");

/*
 * Remove balanced quotes from the string.
 */
String removeQuotes(const String& str, const String& quotes = "'\"");

String quoteIfNeeded(const String& str, bool forceQuote = false);

/*
 * Returns true if str begins (or ends) with the specified needle string.
 */
bool strBeginsWith(const String& str, const String& needle);
bool strEndsWith(const String& str, const String& needle);

/*
 * Trims all whitespace characters from the beginning and end of str.
 */
String trim(const String& str, const String& whitespace = " \t");

/*
 * Joins a list of strings into one string, with the provided separator.
 */
template <typename T>
String joinStrings(const T& elements, const String& separator);

/*
 * Replaces pattern with dstPattern in str.
 */
String sb_replace(const String& str, const String& pattern, const String& dstPattern, int count);

/*
 * Returns a string value of str's hash.
 */
String sb_hash(const String& str);

/*
 * Tries to get value for specified environment variables.
 * On success, returns true and puts the value in varValue.
 */
bool sb_getenv(const String& varName, String& varValue);

/*
 * Escapes all spaces in the string.
 */
inline String escapeSpaces(const String& str) {
    return sb_replace(str, " ", "\\ ", -1);
}

#endif /* _STRINGUTILS_H_ */
