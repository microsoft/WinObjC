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

#ifndef _VariableCollectionManager_H_
#define _VariableCollectionManager_H_

#include "types.h"
#include "SimpleVariableCollection.h"

class PBXFileReference;
class PBXObject;
class PBXProject;
class PBXTarget;

class VariableCollectionManager {
public:
    ~VariableCollectionManager();

    void processGlobalConfigFile(const String& absFilePath);
    void processGlobalAssignment(const String& assignment);
    void setGlobalVar(const String& varName, const String& varValue);

    const VariableCollection* getSettingsFromFileRef(const PBXFileReference* fileRef);
    const VariableCollection* getSettingsFromFile(const String& absFilePath, const String& projectDir);
    const VariableCollection* getDefaultSettings() const {
        return &m_defaultSettings;
    }
    const VariableCollection* getGlobalSettings() const {
        return &m_globalSettings;
    }
    const VariableCollection* getTargetSettings(const PBXTarget* target);
    const VariableCollection* getProjectSettings(const PBXProject* project);

    static VariableCollectionManager& get();

private:
    typedef std::map<String, const VariableCollection*> ConfigFileMap;
    typedef std::map<const PBXObject*, const VariableCollection*> PBXObjectMap;

    VariableCollectionManager();

    void cacheCollection(const PBXObject* object, const VariableCollection* vc);
    void cacheCollection(const String& absFilePath, const VariableCollection* vc);
    const VariableCollection* getCachedCollection(const PBXObject* object);
    const VariableCollection* getCachedCollection(const String& absPath);

    SimpleVariableCollection m_defaultSettings;
    SimpleVariableCollection m_globalSettings;

    ConfigFileMap m_cfileMap;
    PBXObjectMap m_objectMap;

    static VariableCollectionManager* s_manager;
};

#endif /* _VariableCollectionManager_H_ */
