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

#ifndef _VARIABLECOLLECTIONHIERARCHY_H_
#define _VARIABLECOLLECTIONHIERARCHY_H_

#include "types.h"

class VariableCollection;
class VarPrintFunc;

class VariableCollectionHierarchy {
public:
    void push_back(const VariableCollection& vc);
    void pop_back();

    String expand(const String& str) const;
    String getValue(const String& varName) const;
    String getValue(const String& varName, size_t searchLevel) const;
    bool getValue(const String& varName, String& ret) const;
    bool getValue(const String& varName, size_t searchLevel, String& ret) const;
    bool getValue(const String& varName, StringVec& ret) const;
    bool getValue(const String& varName, size_t searchLevel, StringVec& ret) const;
    const VariableCollection& operator[](size_t level) const;
    void getVariableSet(StringSet& ret) const;
    void print(const VarPrintFunc& pf) const;
    size_t size() const;

private:
    std::vector<const VariableCollection*> m_vcs;
};

#endif /* _VARIABLECOLLECTIONHIERARCHY_H_ */