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

#ifndef _BUILDSETTINGS_H_
#define _BUILDSETTINGS_H_

#include "types.h"
#include "BuildSettingsInfo.h"
#include "SimpleVariableCollection.h"
#include "VariableCollectionHierarchy.h"

class PBXProject;
class PBXTarget;
class XCBuildConfiguration;

class BuildSettings {
public:
    BuildSettings(const PBXProject* project);
    BuildSettings(const PBXTarget* target, const String& configName);

    void addOverride(const String& varName, const String& varValue);
    void clearOverride(const String& varName);

    String expand(const String& str, ValueType type = StringValue) const;
    String getValue(const String& varName) const;
    void getValue(const String& varName, StringVec& ret) const;
    const VariableCollectionHierarchy& getHierarchy() const;
    void print(const VarPrintFunc& pf) const;

private:
    void addLevel(const VariableCollection* level);
    void addXCBuildConfiguration(const XCBuildConfiguration* config);

    VariableCollectionHierarchy m_vch;
    SimpleVariableCollection m_overrideSettings;
};

#endif /* _BUILDSETTINGS_H_ */
