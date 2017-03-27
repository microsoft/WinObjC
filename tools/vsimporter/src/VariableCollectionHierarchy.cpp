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

#include "VariableCollectionHierarchy.h"
#include "VariableCollection.h"
#include "XCVariableExpander.h"
#include "tokenizer.h"

String VariableCollectionHierarchy::expand(const String& str) const {
    XCVariableExpander varExpander(*this, size()); // XCVariableExpander uses one-based indexing
    String val;
    varExpander.expandString(str, val);
    return val;
}

String VariableCollectionHierarchy::getValue(const String& varName) const {
    return getValue(varName, size() - 1);
}

String VariableCollectionHierarchy::getValue(const String& varName, size_t searchLevel) const {
    String val;
    getValue(varName, searchLevel, val);
    return val;
}

bool VariableCollectionHierarchy::getValue(const String& varName, String& ret) const {
    return getValue(varName, size() - 1, ret);
}

bool VariableCollectionHierarchy::getValue(const String& varName, size_t searchLevel, String& ret) const {
    if (searchLevel >= size())
        return false;

    XCVariableExpander varExpander(*this, searchLevel + 1); // XCVariableExpander uses one-based indexing
    return varExpander.getExpandedValue(varName, ret);
}

bool VariableCollectionHierarchy::getValue(const String& varName, StringVec& ret) const {
    return getValue(varName, size() - 1, ret);
}

bool VariableCollectionHierarchy::getValue(const String& varName, size_t searchLevel, StringVec& ret) const {
    String val;
    bool found = getValue(varName, searchLevel, val);
    tokenize(val, ret, " \t", "", "\"'", "", "", true, false);
    return found;
}

void VariableCollectionHierarchy::push_back(const VariableCollection& vc) {
    m_vcs.push_back(&vc);
}

void VariableCollectionHierarchy::pop_back() {
    m_vcs.pop_back();
}

const VariableCollection& VariableCollectionHierarchy::operator[](size_t level) const {
    return *m_vcs[level];
}

size_t VariableCollectionHierarchy::size() const {
    return m_vcs.size();
}

void VariableCollectionHierarchy::getVariableSet(StringSet& ret) const {
    for (size_t i = 0; i < m_vcs.size(); i++)
        m_vcs[i]->getVariableSet(ret);
}

void VariableCollectionHierarchy::print(const VarPrintFunc& pf) const {
    StringSet varSet;
    getVariableSet(varSet);

    String tst = getValue("GCC_PREPROCESSOR_DEFINITIONS");

    StringSet::iterator varsIt = varSet.begin();
    for (; varsIt != varSet.end(); ++varsIt) {
        pf.print(*varsIt, getValue(*varsIt));
    }
}