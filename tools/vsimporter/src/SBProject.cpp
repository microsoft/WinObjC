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

#include <iostream>
#include <iterator>
#include "types.h"
#include "utils.h"
#include "sbassert.h"
#include "query.h"
#include "BuildSettings.h"
#include "SBLog.h"
#include "PBXProject.h"
#include "PBXDocument.h"
#include "PBXTarget.h"
#include "PBXGroup.h"
#include "XCConfigurationList.h"
#include "XCBuildConfiguration.h"
#include "SBProject.h"
#include "SBWorkspace.h"
#include "SBTarget.h"
#include "VCSharedProject.h"
#include "VSSolution.h"
#include "VSSolutionFolderProject.h"
#include "VSBuildableSolutionProject.h"
#include "VSTemplate.h"
#include "VSTemplateParameters.h"
#include "VSTemplateProject.h"
#include "xc2vs.h"

PBXTargetList SBProject::s_cycleTracker;

SBProject::~SBProject()
{
  delete m_pbxDoc;
  delete m_buildSettings;
}

SBProject::SBProject(const PBXDocument* pbxDoc, const PBXProject* project)
: m_pbxDoc(pbxDoc),
  m_project(project),
  m_buildSettings(new BuildSettings(project))
{}

void SBProject::printSummary()
{
  const PBXTargetList& targets = m_project->getTargets();

  if (targets.empty()) {
    std::cout << "There are no targets in the \"" << getName() << "\" project." << std::endl;
  } else {
    std::cout << "Information about project \"" << getName() << "\":" << std::endl;
    std::cout << "    Targets:" << std::endl;
    for (int i = 0; i < targets.size(); i++) {
      std::cout << "\t" << targets[i]->getNameWithType() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "    Build Configurations:" << std::endl;
    const XCConfigurationList* buildConfigList = m_project->getBuildConfigurationList();
	sbAssertWithTelemetry(buildConfigList, "The XCConfigurationList is NULL for project: " + m_project->getName());
    const BuildConfigurationList& buildConfigs = buildConfigList->getConfigurations();
    for (int i = 0; i < buildConfigs.size(); i++)
      std::cout << "\t" << buildConfigs[i]->getName() << std::endl;
    std::cout << std::endl;
  }
}

const String& SBProject::getPath() const
{
  return m_project->getPath();
}

String SBProject::getProjectDir() const
{
  return m_project->getProjectDir();
}

String SBProject::getName() const
{
  return m_project->getName();
}

const PBXProject* SBProject::getPBXProject() const
{
  return m_project;
}

const BuildSettings& SBProject::getBuildSettings() const
{
  assert(m_buildSettings);
  return *m_buildSettings;
}

const StringSet& SBProject::getSelectedConfigurations() const
{
  return m_selectedConfigs;
}

void SBProject::getQueuedTargets(SBTargetList& ret) const
{
  for (auto targetKV : m_existingTargets) {
    ret.push_back(targetKV.second);
  }
}

SBTarget* SBProject::queueTargetWithName(const String& targetName, const StringSet* configNames)
{
  const PBXTarget* pbxTarget = m_project->getTargetWithName(targetName);
  return queueTarget(pbxTarget, configNames);
}

SBTarget* SBProject::queueTargetWithId(const String& targetId, const StringSet* configNames)
{
  const PBXTarget* pbxTarget = m_project->getTargetWithId(targetId);
  return queueTarget(pbxTarget, configNames);
}

SBTarget* SBProject::queueTargetWithProductName(const String& productName, const StringSet* configNames)
{
  const PBXTarget* pbxTarget = m_project->getTargetWithProductName(productName);
  return queueTarget(pbxTarget, configNames);
}

SBTarget* SBProject::queueTargetWithProductReference(const String& productRef, const StringSet* configNames)
{
  const PBXTarget* pbxTarget = m_project->getTargetWithProductReference(productRef);
  return queueTarget(pbxTarget, configNames);
}

bool SBProject::checkTargetCycle(const PBXTarget* target)
{
  PBXTargetList::const_iterator tIt = s_cycleTracker.begin();
  PBXTargetList::const_iterator tEnd = s_cycleTracker.end();
  for (; tIt != tEnd; tIt++) {
    if (*tIt == target)
      break;
  }

  // Construct cycle description
  String cycle;
  for (; tIt != tEnd; tIt++)
    cycle += (*tIt)->getName() + " -> ";

  // Check if a cycle was found
  if (cycle.empty()) {
    return true;
  } else {
    SBLog::info() << "Detected dependency cycle: " << cycle << target->getName() << std::endl;
    return false;
  }
}

void SBProject::selectBuildConfigurations(const StringSet* configNames)
{
  // Use previously-selected configurations, if possible
  if (!m_selectedConfigs.empty())
    return;

  // If not configuration names were specified, get them from the workspace
  if (!configNames) {
    const StringSet& globalConfigs = SBWorkspace::get()->getConfigurations();
    configNames = &globalConfigs;
  }

  // Figure out which build configurations to use
  BuildSettings bs(NULL);
  bool isInteractive = bs.getValue("VSIMPORTER_INTERACTIVE") == "YES";
  const XCConfigurationList* buildConfigList = m_project->getBuildConfigurationList();
  if (isInteractive) {
    queryBuildConfigurations();
  } else if (configNames->empty()) {
    const BuildConfigurationList& projectConfigs = buildConfigList->getConfigurations();
    std::transform(projectConfigs.begin(),
                   projectConfigs.end(),
                   std::inserter(m_selectedConfigs, m_selectedConfigs.end()),
                   [](const XCBuildConfiguration* c) { return c->getName(); });
  } else {
    buildConfigList->getValidConfigurations(*configNames, m_selectedConfigs);
  }

  // Add the default configuration, if not all configurations were found
  if (configNames->size() > m_selectedConfigs.size()) {
    m_selectedConfigs.insert(buildConfigList->getDefaultConfigurationName());
  }
}

void SBProject::queueAllTargets(const StringSet* configNames)
{
  for (auto target : m_project->getTargets()) {
    queueTarget(target, configNames);
  }
}

SBTarget* SBProject::queueTarget(const PBXTarget* target, const StringSet* configNames)
{
  // Fast return check
  if (!target)
    return NULL;
    
  // Check if target has already been created
  TargetMap::iterator targetIt = m_existingTargets.find(target);
  if (targetIt != m_existingTargets.end())
    return targetIt->second;
  
  // Check for a dependency cycle
  if (!checkTargetCycle(target))
    return NULL;
    
  // Figure out which build configuration to use
  selectBuildConfigurations(configNames);
  
  // Mark the target as dirty for the duration of its creation
  s_cycleTracker.push_back(target);

  // Create the target
  SBTarget* sbTarget = SBTarget::create(target, m_selectedConfigs, *this);
  if (sbTarget) {
    m_existingTargets[target] = sbTarget;
  }
  
  // Mark the target as clean after its creation is complete
  s_cycleTracker.pop_back();

  return sbTarget;
}

void SBProject::queryBuildConfigurations()
{
  String queryMessage = "The \"" + getName() + "\" project has multiple build configurations.";

  const XCConfigurationList* buildConfigList = m_project->getBuildConfigurationList();
  sbAssertWithTelemetry(buildConfigList, "The XCConfigurationList is NULL for project: " + m_project->getName());
  const BuildConfigurationList& buildConfigs = buildConfigList->getConfigurations();

  StringVec configNames;
  std::transform(buildConfigs.begin(),
                 buildConfigs.end(),
                 back_inserter(configNames),
                 [](const XCBuildConfiguration* c) { return c->getName(); });
  sbAssertWithTelemetry(!configNames.empty(), "The XCConfigurationList is empty for project: " + m_project->getName());

  std::vector<size_t> selection;
  queryListSelection(configNames, queryMessage, "configuration", selection);
  for (size_t i = 0; i < selection.size(); i++) {
    size_t currentSelection = selection[i];
    m_selectedConfigs.insert(configNames[currentSelection]);
  }
}

SBProject* SBProject::createFromPath(const String& projectPath)
{
  // Create PBXDocument, which owns all PBXObjects in the project
  PBXDocument* pbxDoc = PBXDocument::createFromFile(projectPath);
  if (!pbxDoc)
    return NULL;
    
  // Validate that the project has the bare essentials
  PBXProject* project = pbxDoc->getProject();
  if (!project->getBuildConfigurationList()) {
    SBLog::warning() << "The \"" << pbxDoc->getName() << "\" project contains no build configurations. Ignoring it." << std::endl;
    return NULL;
  }
  
  // Create an SBProject that wraps the PBXDocument/PBXProject
  SBProject* ret = new SBProject(pbxDoc, project);
  return ret;
}

void SBProject::getMatchingFiles(fileMatchFunc matchFunc, ConstFileList& ret) const
{
  const PBXGroup* mainGroup = m_project->getMainGroup();
  if (mainGroup)
    mainGroup->getMatchingFiles(matchFunc, ret);
}

static bool headerTypeMatch(const PBXFile* file)
{
  return matchWildcardList(file->getFileType(), getHeaderTypes());
}

void SBProject::constructVCProjects(VSSolution& sln, const StringSet& slnConfigs, std::multimap<SBTarget*, VCProject*>& vcProjects)
{
  // Nothing to do if project contains no queued targets
  if (m_existingTargets.empty()) {
    return;
  }

  // Get the output format and directory
  String outputDir = m_buildSettings->getValue("VSIMPORTER_OUTPUT_DIR");

  // Create a solution folder for the project, as long as some Xcode target was imported.
  // The solution folder is necessary for VS build telemetry to work properly.
  VSSolutionFolderProject* projFolder = sln.addFolder(getName());

  // Get the default project configuration
  const XCConfigurationList* buildConfigList = m_project->getBuildConfigurationList();
  String defaultConfig = buildConfigList->getDefaultConfigurationName();

  // Create VS projects from targets
  std::list<VCProject*> compilableProjects;
  for (auto target : m_existingTargets) {
    // Construct template name
    String templateName;
    TargetProductType productType = target.second->getProductType();
    if (productType == TargetApplication) {
      templateName = "App";
    } else if (productType == TargetStaticLib) {
      templateName = "StaticLib";
    } else if (productType == TargetBundle) {
      templateName = "Bundle";
    } else if (target.first->getType() == "PBXAggregateTarget") {
      templateName = "Aggregate";
    } else {
      SBLog::warning() << "Failed to construct VS template name for \"" << target.second->getName() << "\" target." << std::endl;
    }

    // Get the template
    VSTemplate* vstemplate = VSTemplate::getTemplate(templateName);
	sbAssertWithTelemetry(vstemplate, "Failed to get " + templateName + " VS template");

    // Set up template parameters
    VSTemplateParameters templateParams;
    templateParams.setProjectName(target.second->getName());
    templateParams.setPublisherName(m_buildSettings->getValue("USER"));

    // Expand the template
    vstemplate->expand(outputDir, templateParams);
    const VSTemplateProjectVec& projTemplates = vstemplate->getProjects();
	sbAssertWithTelemetry(projTemplates.size() == 1, "Unexpected " + templateName + " VS template size");

    for (auto projTemplate : projTemplates) {
      // Create the project from template
      VCProject* proj = target.second->constructVCProject(projTemplate);
      vcProjects.insert(make_pair(target.second, proj));

      // Add project platforms to the solution
      for (auto platformName : projTemplate->getPlatforms()) {
        sln.addPlatform(platformName);
      }

      // Keep track of projects that compile things
      if (productType == TargetApplication || productType == TargetStaticLib) {
        compilableProjects.push_back(proj);
      }

      // Add the project to the solution
      VSBuildableSolutionProject* slnProj = sln.addProject(proj, projFolder);

      // Map project configurations to solution configurations
      for (auto slnConfig : slnConfigs) {
        if (m_selectedConfigs.find(slnConfig) != m_selectedConfigs.end()) {
          slnProj->mapConfiguration(slnConfig, slnConfig);
        } else {
          slnProj->mapConfiguration(slnConfig, defaultConfig);
        }
      }
    }
  }

  // Get all header files from the Xcode project
  VCProject* headerProj = NULL;
  ConstFileList headerFiles;
  getMatchingFiles(&headerTypeMatch, headerFiles);
  if (compilableProjects.size() == 1) {
    headerProj = compilableProjects.front();
  } else if (!headerFiles.empty()) {
    // Get the template
    VSTemplate* vstemplate = VSTemplate::getTemplate("SharedHeaders");
	sbAssertWithTelemetry(vstemplate, "Failed to get SharedHeaders VS template");

    // Set up basis template parameters
    VSTemplateParameters templateParams;
    templateParams.setProjectName(getName() + "-Headers");

    // Expand the template and get the template project
    vstemplate->expand(outputDir, templateParams);
    const VSTemplateProjectVec& projTemplates = vstemplate->getProjects();
	sbAssertWithTelemetry(projTemplates.size() == 1, "Unexpected SharedHeaders VS template size");

    // Create a shared project for the headers and add it to the solution
    headerProj = new VCSharedProject(projTemplates.front());
    sln.addProject(headerProj, projFolder);
  }

  // Add projects headers
  if (headerProj) {
    VCItemHint headerHint = { "ClInclude", "", "" };
    for (auto file : headerFiles) {
      addFileToVS(file, *headerProj, getBuildSettings(), &headerHint);
    }

    // If headers were added to a shared project, add appropriate references
    if (headerProj->getSubType() == VCShared) {
      for (auto project : compilableProjects) {
        project->addSharedProject(headerProj);
      }
    }
  }
}
