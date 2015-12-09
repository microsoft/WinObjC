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

#include "utils.h"
#include "sbassert.h"
#include "PBXDocument.h"
#include "PBXProject.h"
#include "PBXTarget.h"
#include "XCBuildConfiguration.h"
#include "XCConfigurationList.h"
#include "SBWorkspace.h"
#include "VariableCollectionManager.h"
#include "BuildSettings.h"

BuildSettings::BuildSettings(const PBXProject* project)
{
  // Get the VariableCollectionManager for the default and global settings
  VariableCollectionManager& manager = VariableCollectionManager::get();

  // Construct a rudimentary settings hierarchy
  addLevel(manager.getDefaultSettings());
  addLevel(manager.getProjectSettings(project));
  addLevel(manager.getGlobalSettings());
  addLevel(&m_overrideSettings);
}

BuildSettings::BuildSettings(const PBXTarget* target, const String& configName)
{
  // Get PBXProject for the target
  const PBXDocument& pbxDoc = target->getOwner();
  const PBXProject* project = pbxDoc.getProject();

  // Find project configuration with specified name
  const XCBuildConfiguration* projectConfig = NULL;
  const XCConfigurationList* buildConfigList = project->getBuildConfigurationList();
  if (buildConfigList)
    projectConfig = buildConfigList->getConfiguration(configName);
  sbAssert(projectConfig);

  // Find target configuration with specified name
  const XCBuildConfiguration* targetConfig = NULL;
  buildConfigList = target->getBuildConfigurationList();
  if (buildConfigList)
    targetConfig = buildConfigList->getConfiguration(configName);

  // Get the VariableCollectionManager for the default and global settings
  VariableCollectionManager& manager = VariableCollectionManager::get();

  // Construct the settings hierarchy
  addLevel(manager.getDefaultSettings());
  addLevel(manager.getProjectSettings(project));
  addLevel(manager.getTargetSettings(target));
  addXCBuildConfiguration(projectConfig);
  addXCBuildConfiguration(targetConfig);
  addLevel(manager.getGlobalSettings());
  addLevel(&m_overrideSettings);

  // Insert a few extra variables into the build settings
  m_overrideSettings["CONFIGURATION"] = configName;
  m_overrideSettings["SDKROOT"] = "${WINOBJC_SDK_ROOT}";
}

void BuildSettings::addLevel(const VariableCollection* vc)
{
  if (vc)
    m_vch.push_back(*vc);
}

void BuildSettings::addXCBuildConfiguration(const XCBuildConfiguration* config)
{
  if (!config)
    return;
  
  // Get the base configuration file
  const PBXFileReference* baseConfig = config->getBaseConfiguration();
  
  // Get the VariableCollectionManager to parse the file
  VariableCollectionManager& manager = VariableCollectionManager::get();
  const VariableCollection* baseLevel = manager.getSettingsFromFileRef(baseConfig);
  
  // Add the base configuration settings
  addLevel(baseLevel);
  
  // Add the actual build configuration settings
  addLevel(&config->getBuildSettings());
}

void BuildSettings::addOverride(const String& varName, const String& varValue)
{
  m_overrideSettings.insert(varName, varValue);
}

void BuildSettings::clearOverride(const String& varName)
{
  m_overrideSettings.erase(varName);
}

String BuildSettings::expand(const String& str, ValueType type) const
{
  return m_vch.expand(str);
}

String BuildSettings::getValue(const String& varName) const
{
  return m_vch.getValue(varName);
}

void BuildSettings::getValue(const String& varName, StringVec& ret) const
{
  m_vch.getValue(varName, ret);
}

const VariableCollectionHierarchy& BuildSettings::getHierarchy() const
{
  return m_vch;
}

void BuildSettings::print(const VarPrintFunc& pf) const
{
  m_vch.print(pf);
}