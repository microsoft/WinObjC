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

#ifndef _VARIABLECOLLECTION_H_
#define _VARIABLECOLLECTION_H_

#include "types.h"

class VarPrintFunc {
public:
    virtual ~VarPrintFunc() {
    }
    virtual void print(const String& varName, const String& varValue) const = 0;
};

class VariableCollection {
public:
    virtual ~VariableCollection() {
    }

    void insert(const VariableCollection& vc);
    void insert(const StringPair& keyVal);
    virtual void insert(const String& varName, const String& varValue) = 0;
    virtual void erase(const String& varName) = 0;

    virtual String getValue(const String& varName) const;
    virtual bool getValue(const String& varName, String& ret) const = 0;

    virtual bool empty() const = 0;
    virtual bool isSet(const String& varName) const;
    virtual void getVariableSet(StringSet& ret) const = 0;
    virtual void print(const VarPrintFunc& pf) const;
};

#endif /* _VARIABLECOLLECTION_H_ */