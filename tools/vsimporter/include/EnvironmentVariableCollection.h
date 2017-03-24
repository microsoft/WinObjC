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

#ifndef _ENVIRONMENTVARIABLECOLLECTION_H_
#define _ENVIRONMENTVARIABLECOLLECTION_H_

#include "VariableCollection.h"

class EnvironmentVariableCollection : public VariableCollection {
public:
    static EnvironmentVariableCollection& get() {
        return s_envVC;
    }

    using VariableCollection::insert;
    virtual ~EnvironmentVariableCollection() {
    }
    virtual void insert(const String& varName, const String& varValue);
    virtual void erase(const String& varName);
    virtual bool getValue(const String& varName, String& ret) const;
    virtual void getVariableSet(StringSet& ret) const;
    virtual bool empty() const {
        return false;
    }

private:
    EnvironmentVariableCollection() {
    }

    static EnvironmentVariableCollection s_envVC;
};

#endif /* _ENVIRONMENTVARIABLECOLLECTION_H_ */