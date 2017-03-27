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

#include "utils.h"
#include "settingmodifiers.h"
#include "SBLog.h"

static void applyIdentifier(String& varValue, char replacement) {
    if (varValue.empty())
        return;

    // First characters must be a letter (or the replacement character)
    if (!isalpha(varValue[0]))
        varValue[0] = replacement;

    // Subsequent letters can be alphanumeric (or the replacement character)
    for (size_t posn = 0; posn < varValue.size(); posn++) {
        if (!isalnum(varValue[posn]))
            varValue[posn] = replacement;
    }
}

static String escapeWhitespace(const String& varValue) {
    String ret;
    for (size_t posn = 0; posn < varValue.size(); posn++) {
        if (varValue[posn] == ' ' || varValue[posn] == '\\')
            ret += '\\';
        ret += varValue[posn];
    }

    return ret;
}

void applySettingModifiers(String& varValue, const StringVec& modifiers) {
    for (unsigned i = 0; i < modifiers.size(); i++) {
        if (modifiers[i] == "lower") {
            varValue = strToLower(varValue);
        } else if (modifiers[i] == "upper") {
            varValue = strToUpper(varValue);
        } else if (modifiers[i] == "identifier") {
            applyIdentifier(varValue, '_');
        } else if (modifiers[i] == "rfc1034identifier") {
            applyIdentifier(varValue, '-');
        } else if (modifiers[i] == "dir") {
            String dir = sb_dirname(varValue);
            varValue = (dir == "/" ? dir : dir + '/');
        } else if (modifiers[i] == "file") {
            varValue = (varValue.empty() ? "" : sb_basename(varValue));
        } else if (modifiers[i] == "base") {
            varValue = sb_fname(sb_basename(varValue));
        } else if (modifiers[i] == "suffix") {
            String ext = sb_fextension(varValue);
            varValue = (ext.empty() ? ext : "." + ext);
        } else if (modifiers[i] == "quote") {
            varValue = escapeWhitespace(varValue);
        } else {
            SBLog::warning() << "Unknown variable modifier \"" << modifiers[i] << "\"" << std::endl;
        }
    }
}
