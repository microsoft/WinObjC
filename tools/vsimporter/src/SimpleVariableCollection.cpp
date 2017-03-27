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

#include "SimpleVariableCollection.h"
#include <stdlib.h>

void SimpleVariableCollection::insert(const String& varName, const String& varValue) {
    m_vars[varName] = varValue;
}

void SimpleVariableCollection::erase(const String& varName) {
    m_vars.erase(varName);
}

String& SimpleVariableCollection::operator[](const String& varName) {
    return m_vars[varName];
}

bool SimpleVariableCollection::getValue(const String& varName, String& ret) const {
    StringMap::const_iterator it = m_vars.find(varName);
    bool found = it != m_vars.end();
    if (found)
        ret = it->second;
    return found;
}

void SimpleVariableCollection::getVariableSet(StringSet& ret) const {
    StringMap::const_iterator it = m_vars.begin();
    StringMap::const_iterator itEnd = m_vars.end();
    for (; it != itEnd; it++)
        ret.insert(it->first);
}

bool SimpleVariableCollection::empty() const {
    return m_vars.empty();
}