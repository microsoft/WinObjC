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

#ifndef _SIMPLEVARIABLECOLLECTION_H_
#define _SIMPLEVARIABLECOLLECTION_H_

#include "VariableCollection.h"
#include "types.h"

class SimpleVariableCollection : public VariableCollection {
public:
    virtual ~SimpleVariableCollection() {
    }

    using VariableCollection::insert;
    virtual void insert(const String& varName, const String& varValue);
    virtual void erase(const String& varName);
    String& operator[](const String& varName);
    virtual bool getValue(const String& varName, String& ret) const;
    virtual void getVariableSet(StringSet& ret) const;
    virtual bool empty() const;

private:
    StringMap m_vars;
};

#endif /* _SIMPLEVARIABLECOLLECTION_H_ */