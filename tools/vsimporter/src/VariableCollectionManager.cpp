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

#include "sbassert.h"
#include "utils.h"
#include "xcconfigparser.h"
#include "SBLog.h"
#include "PBXDocument.h"
#include "PBXProject.h"
#include "PBXFileReference.h"
#include "PBXNativeTarget.h"
#include "BuildSettings.h"
#include "BuildSettingsInfo.h"
#include "VariableCollectionManager.h"

VariableCollectionManager* VariableCollectionManager::s_manager = NULL;

VariableCollectionManager::~VariableCollectionManager() {
}

VariableCollectionManager::VariableCollectionManager() {
    getDefaultSettingValues(m_defaultSettings, UniversalSetting);
}

VariableCollectionManager& VariableCollectionManager::get() {
    if (!s_manager)
        s_manager = new VariableCollectionManager();

    return *s_manager;
}

void VariableCollectionManager::cacheCollection(const PBXObject* object, const VariableCollection* vc) {
    m_objectMap[object] = vc;
}

void VariableCollectionManager::cacheCollection(const String& absFilePath, const VariableCollection* vc) {
    m_cfileMap[absFilePath] = vc;
}

const VariableCollection* VariableCollectionManager::getCachedCollection(const PBXObject* object) {
    PBXObjectMap::const_iterator sIt = m_objectMap.find(object);
    if (sIt != m_objectMap.end())
        return sIt->second;
    else
        return NULL;
}

const VariableCollection* VariableCollectionManager::getCachedCollection(const String& absFilePath) {
    ConfigFileMap::const_iterator sIt = m_cfileMap.find(absFilePath);
    if (sIt != m_cfileMap.end())
        return sIt->second;
    else
        return NULL;
}

const VariableCollection* VariableCollectionManager::getSettingsFromFileRef(const PBXFileReference* fileRef) {
    if (!fileRef)
        return NULL;

    // Get the document/project to which the file reference belongs
    const PBXDocument& pbxDoc = fileRef->getOwner();
    const PBXProject* project = pbxDoc.getProject();

    // Construct an absolute path to the file
    BuildSettings projectSettings(project);
    String expandedPath = projectSettings.expand(fileRef->getFullPath());
    // String absPath = joinPaths(project->getProjectDir(), expandedPath);

    // Get the VariableCollection using the full path
    const VariableCollection* ret = getSettingsFromFile(expandedPath, project->getProjectDir());
    if (!ret)
        SBLog::warning() << "Failed to load \"" << fileRef->getFullPath() << "\" configuration file belonging to the \"" << pbxDoc.getName()
                         << "\" project." << std::endl;

    return ret;
}

void VariableCollectionManager::processGlobalConfigFile(const String& absFilePath) {
    const VariableCollection* settings = getSettingsFromFile(absFilePath, ".");

    // Combine the created settings map with the global settings map
    if (settings)
        m_globalSettings.insert(*settings);
    else
        SBLog::warning() << "Failed to load \"" << absFilePath << "\" configuration file." << std::endl;
}

void VariableCollectionManager::processGlobalAssignment(const String& assignment) {
    processVariableAssignment(assignment, ASSIGN_CMDARG, m_globalSettings);
}

void VariableCollectionManager::setGlobalVar(const String& varName, const String& varValue) {
    m_globalSettings.insert(varName, varValue);
}

const VariableCollection* VariableCollectionManager::getSettingsFromFile(const String& absFilePath, const String& projectDir) {
    // Check if this file has been processed previously
    const VariableCollection* cachedVC = getCachedCollection(absFilePath);
    if (cachedVC)
        return cachedVC;

    // Create the VariableCollection from file
    const VariableCollection* ret = parseXCConfigFile(absFilePath, projectDir);

    // Cache the settings map for the future
    cacheCollection(absFilePath, ret);

    return ret;
}

const VariableCollection* VariableCollectionManager::getTargetSettings(const PBXTarget* target) {
    if (!target)
        return NULL;

    // Check if the settings are cached
    const VariableCollection* cachedVC = getCachedCollection(target);
    if (cachedVC)
        return cachedVC;

    // Create the VariableCollection from the target information
    VariableCollection* ret = new SimpleVariableCollection;

    // Add the appropriate defaults for the NativeTarget type
    const PBXNativeTarget* nativeTarget = dynamic_cast<const PBXNativeTarget*>(target);
    if (!nativeTarget) {
        // Do nothing
    } else if (nativeTarget->getProductType() == "com.apple.product-type.library.static") {
        getDefaultSettingValues(*ret, StaticLibSetting);
    } else if (nativeTarget->getProductType() == "com.apple.product-type.application") {
        getDefaultSettingValues(*ret, AppSetting);
    }

    // Add target-specific information
    target->getBuildSettings(*ret);

    // Cache the settings map for the future
    cacheCollection(target, ret);

    return ret;
}

const VariableCollection* VariableCollectionManager::getProjectSettings(const PBXProject* project) {
    if (!project)
        return NULL;

    // Check if the settings are cached
    const VariableCollection* cachedVC = getCachedCollection(project);
    if (cachedVC)
        return cachedVC;

    // Create the VariableCollection from the project information
    VariableCollection* ret = new SimpleVariableCollection;
    project->getBuildSettings(*ret);

    // Cache the settings map for the future
    cacheCollection(project, ret);

    return ret;
}