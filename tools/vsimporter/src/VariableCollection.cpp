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

#include "VariableCollection.h"

void VariableCollection::insert(const StringPair& keyVal) {
    insert(keyVal.first, keyVal.second);
}

void VariableCollection::insert(const VariableCollection& vc) {
    StringSet varSet;
    vc.getVariableSet(varSet);

    StringSet::iterator varsIt = varSet.begin();
    for (; varsIt != varSet.end(); ++varsIt) {
        insert(*varsIt, vc.getValue(*varsIt));
    }
}

String VariableCollection::getValue(const String& varName) const {
    String ret;
    getValue(varName, ret);
    return ret;
}

bool VariableCollection::isSet(const String& varName) const {
    String ret;
    return getValue(varName, ret);
}

void VariableCollection::print(const VarPrintFunc& pf) const {
    StringSet varSet;
    getVariableSet(varSet);

    StringSet::iterator varsIt = varSet.begin();
    for (; varsIt != varSet.end(); ++varsIt) {
        pf.print(*varsIt, getValue(*varsIt));
    }
}