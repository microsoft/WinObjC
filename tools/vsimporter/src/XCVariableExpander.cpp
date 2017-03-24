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

#include "XCVariableExpander.h"
#include "settingmodifiers.h"
#include "VariableCollectionHierarchy.h"
#include "VariableCollection.h"

static size_t extractVarModifiers(const String& str, size_t posn, char closeBracket, StringVec& ret) {
    String modifier;
    for (; posn < str.length(); posn++) {
        if (str[posn] == ':') {
            if (!modifier.empty()) {
                ret.push_back(modifier);
                modifier.clear();
            }
        } else if (str[posn] == closeBracket) {
            break;
        } else {
            modifier += str[posn];
        }
    }

    if (!modifier.empty())
        ret.push_back(modifier);

    // Last character read is not part of the modifers so we need to backtrack
    return --posn;
}

XCVariableExpander::XCVariableExpander(const VariableCollectionHierarchy& vch, size_t maxSearchLevel)
    : m_vch(vch), m_maxSearchLevel(maxSearchLevel) {
}

size_t XCVariableExpander::processBracketedVar(const String& str, size_t posn, String& ret) {
    char closeBracket = str[posn++] == '(' ? ')' : '}';
    String varName;
    StringVec modifiers;

    for (; posn < str.length(); posn++) {
        if (str[posn] == closeBracket) {
            // Found closing bracket for variable name
            break;
        } else if (str[posn] == ':') {
            // Process modifiers
            posn = extractVarModifiers(str, posn, closeBracket, modifiers);
        } else if (str[posn] == '$') {
            // Possible start of another variable name
            posn = processPossibleVar(str, posn, varName);
        } else {
            varName += str[posn];
        }
    }

    String val;
    getExpandedValue(varName, val);
    applySettingModifiers(val, modifiers);
    ret += val;

    return posn;
}

size_t XCVariableExpander::processSimpleVar(const String& str, size_t posn, String& ret) {
    String varName;
    varName += str[posn++];

    for (; posn < str.length(); posn++) {
        if (isalnum(str[posn]) || str[posn] == '_')
            varName += str[posn];
        else
            break;
    }

    String val;
    if (getExpandedValue(varName, val)) {
        ret += val;
    } else {
        // Strange Xcode behaviour for simple variables (e.g. $VAR)
        // for which no value was found.
        ret += "$" + varName;
    }

    // Last character read is not part of the variable name so we need to backtrack
    return --posn;
}

size_t XCVariableExpander::processPossibleVar(const String& str, size_t posn, String& ret) {
    // $ is the last character of the string
    if (++posn >= str.length())
        goto notVar;

    if (str[posn] == '(' || str[posn] == '{') {
        return processBracketedVar(str, posn, ret);
    } else if (isalpha(str[posn]) || str[posn] == '_') {
        return processSimpleVar(str, posn, ret);
    } else if (str[posn] == '$') {
        // Escape (skip) one of the $'s
        posn++;
    }

notVar:
    // Not a variable name.
    // The $ that we took to be the start of a variable name is a part of the string.
    ret += '$';
    return --posn;
}

String XCVariableExpander::getInheritedName(const String& varName) {
    return varName == "inherited" ? m_currentVar : varName;
}

void XCVariableExpander::expandString(const String& str, String& ret) {
    for (size_t posn = 0; posn < str.length(); posn++) {
        if (str[posn] == '$') {
            posn = processPossibleVar(str, posn, ret);
        } else {
            ret += str[posn];
        }
    }
}

bool XCVariableExpander::getExpandedValue(const String& varName, String& ret) {
    // Resolve inherited variable name
    String fixedVarName = getInheritedName(varName);
    if (fixedVarName.empty())
        return false;

    // Get the hierarchy depth at which to start searching
    size_t& searchDepth = m_varMarkers.insert(make_pair(fixedVarName, m_maxSearchLevel)).first->second;

    // Save the current state
    size_t savedDepth = searchDepth;
    String savedVar = m_currentVar;

    // Set the current variable being expanded
    m_currentVar = fixedVarName;

    // Find a value for the variable
    bool found = false;
    String val;
    for (; searchDepth > 0 && !found; searchDepth--) {
        found = m_vch[searchDepth - 1].getValue(fixedVarName, val);
    }

    // Expand the value
    expandString(val, ret);

    // Restore the original state
    searchDepth = savedDepth;
    m_currentVar = savedVar;

    return found;
}