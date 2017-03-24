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

#include "EnvironmentVariableCollection.h"
#include <stdlib.h>

#if defined(_MSC_VER)
#include <windows.h> // GetEnvironmentStrings
#else
extern char** environ;
#endif

EnvironmentVariableCollection EnvironmentVariableCollection::s_envVC;

void EnvironmentVariableCollection::insert(const String& varName, const String& varValue) {
#if defined(_MSC_VER)
    _putenv_s(varName.c_str(), varValue.c_str());
#else
    setenv(varName.c_str(), varValue.c_str(), 1);
#endif
}

void EnvironmentVariableCollection::erase(const String& varName) {
#if defined(_MSC_VER)
    _putenv_s(varName.c_str(), "");
#else
    unsetenv(varName.c_str());
#endif
}

bool EnvironmentVariableCollection::getValue(const String& varName, String& ret) const {
    const char* val = getenv(varName.c_str());
    if (val)
        ret = val;
    return val != NULL;
}

static void addVarName(const String& assign, StringSet& varSet) {
    String varName = assign.substr(0, assign.find_first_of('='));
    if (!varName.empty())
        varSet.insert(varName);
}

void EnvironmentVariableCollection::getVariableSet(StringSet& ret) const {
#if defined(_MSC_VER)
    const char* vars = GetEnvironmentStrings();
    unsigned i = 0;
    for (unsigned j = 0; vars[i]; j++) {
        if (vars[j] == '\0') {
            String assignment(vars + i, vars + j);
            addVarName(assignment, ret);
            i = j + 1;
        }
    }
#else
    unsigned i = 0;
    while (environ[i]) {
        addVarName(environ[i++], ret);
    }
#endif
}