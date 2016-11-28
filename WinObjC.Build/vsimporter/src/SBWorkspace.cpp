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

#include <string.h>
#include <iostream>
#include <limits>
#include <iterator>

#include "sbassert.h"
#include "utils.h"
#include "query.h"
#include "SBLog.h"
#include "XCScheme.h"
#include "XCWorkspace.h"
#include "PBXProject.h"
#include "BuildSettings.h"
#include "VariableCollectionManager.h"
#include "SBWorkspace.h"
#include "SBProject.h"
#include "SBTarget.h"
#include "VSSolution.h"
#include "VSTemplate.h"
#include "VSTemplateProject.h"
#include "VSTemplateParameters.h"
#include "VCProject.h"
#include "VCProjectConfiguration.h"

SBWorkspace* SBWorkspace::s_workspace = NULL;

SBWorkspace::SBWorkspace() : m_workspace(NULL), m_mainProject(NULL) {}

SBWorkspace* SBWorkspace::get()
{
  return s_workspace;
}

SBWorkspace* SBWorkspace::createFromProject(const String &projectDir)
{
  sbAssertWithTelemetry(!s_workspace, "Workspace already exists");
  
  // Create the workspace
  s_workspace = new SBWorkspace();

  // Open project
  SBProject* proj = s_workspace->openProject(projectDir);

  // Failing to open a project here is fatal
  sbValidateWithTelemetry(proj, "Failed to open main project");

  // Save a ptr to the project, so later we can access the "main" project
  s_workspace->m_mainProject = proj;
  
  return s_workspace;
}

SBWorkspace* SBWorkspace::createFromWorkspace(const String &workspaceDir)
{
  sbAssertWithTelemetry(!s_workspace, "Workspace already exists");
  
  // Create the workspace
  s_workspace = new SBWorkspace();
  s_workspace->m_workspace = XCWorkspace::createFromFile(workspaceDir);
  sbValidateWithTelemetry(s_workspace->m_workspace, "Failed to open main workspace");

  // Record location of the workspace
  VariableCollectionManager& settingsManager = VariableCollectionManager::get();
  settingsManager.setGlobalVar("WORKSPACE_FILE_PATH", workspaceDir);

  // Open all projects referenced by the workspace
  const StringVec& projPaths = s_workspace->m_workspace->getProjectPaths();
  for (unsigned i = 0; i < projPaths.size(); i++) {
    s_workspace->openProject(projPaths[i]);
  }

  s_workspace->findSchemes(workspaceDir);

  // A workspace MUST contain at least one scheme
  sbValidateWithTelemetry(!s_workspace->m_schemes.empty(), "The workspace does not contain any schemes.");
  
  // A workspace MUST also contain at least one open project
  sbValidateWithTelemetry(!s_workspace->m_openProjects.empty(), "The workspace does not contain any valid projects.");
  
  return s_workspace;
}

String SBWorkspace::getName() const
{
  if (m_mainProject) {
    return m_mainProject->getName();
  } else if (m_workspace) {
    return m_workspace->getName();
  } else {
    sbAssert(0); // unreachable
    return "";
  }
}

String SBWorkspace::getPath() const
{
  if (m_mainProject) {
    return m_mainProject->getPath();
  } else if (m_workspace) {
    return m_workspace->getPath();
  } else {
    sbAssert(0); // unreachable
    return "";
  }
}

const StringSet& SBWorkspace::getConfigurations() const
{
  return m_configNames;
}

SBProject* SBWorkspace::findOpenProject(const String &absProjPath) const
{
  // Check the map of all open projects for a pointer to a project
  // matching the specified path.
  ProjectMap::const_iterator pmIt = m_openProjects.find(absProjPath);
  if (pmIt != m_openProjects.end())
    return pmIt->second;
  else
    return NULL;
}

static bool schemeCompare (const XCScheme* i, const XCScheme* j)
{
  return (i->getName() < j->getName());
}

void SBWorkspace::findSchemes(const String& containerAbsPath)
{
  if (containerAbsPath.empty()) {
      SBLog::error() << "No container specified for schemes." << std::endl;
      return;
  }

  StringList schemePaths;

  // Find all scheme files in the shareddata directory
  String sharedDir = joinPaths(containerAbsPath, "xcshareddata");
  if (fileExists(sharedDir))
    findFiles(sharedDir.c_str(), "*.xcscheme", DT_REG, true, schemePaths);

  String userDir = joinPaths(containerAbsPath, "xcuserdata");
#if !defined(_MSC_VER)
  // Only search the current user's data directory
  String user;
  sb_getenv("USER", user);
  userDir = joinPaths(userDir, user + ".xcuserdatad");
#endif

  // Find scheme files in the xcuserdata directory
  if (fileExists(userDir))
    findFiles(userDir.c_str(), "*.xcscheme", DT_REG, true, schemePaths);

  // Try to create a XCScheme out of each path
  StringList::iterator it = schemePaths.begin();
  StringList::iterator itEnd = schemePaths.end();
  for (; it != itEnd; it++) {
    XCScheme* scheme = XCScheme::createFromFile(*it, containerAbsPath);
    if (scheme) {
        m_schemes.push_back(scheme);
    }
  }
}

void SBWorkspace::printSchemes() const
{
  std::cout << "    Schemes:" << std::endl;
  for (int i = 0; i < m_schemes.size(); i++) {
    std::cout << "\t" << m_schemes[i]->getName() << std::endl;
  }
  std::cout << std::endl;
}

void SBWorkspace::printSummary() const
{ 
  if (!m_mainProject) {
    std::cout << "Information about workspace \"" << getName() << "\":" << std::endl;
    printSchemes();
  }

  for (auto project : m_openProjects) {
    project.second->printSummary();
  }

  if (m_mainProject) {
    printSchemes();
  }
}

void SBWorkspace::selectTargets(PotentialTargetsVec& ret)
{
  String queryMessage;
  if (m_workspace) {
    queryMessage = "The \"" + getName() + "\" workspace contains multiple targets.";
  } else {
    queryMessage = "The project contains multiple targets.";
  }

  // Get all possible targets in the solution
  PotentialTargetsVec allTargets;
  getAllTargets(allTargets);

  // Construct vector of target names for the query, maintaining order
  StringVec targetNames;
  std::transform(allTargets.begin(),
                 allTargets.end(),
                 back_inserter(targetNames),
                 [](auto kv) { return kv.first->getNameWithType(); });
  sbAssertWithTelemetry(!targetNames.empty(), "The workspace contains no targets");

  // Query the user for which targets should be queued
  std::vector<size_t> selection;
  queryListSelection(targetNames, queryMessage, "target", selection);

  // Return selection of targets
  ret.clear();
  std::transform(selection.begin(),
                 selection.end(),
                 back_inserter(ret),
                 [&allTargets](size_t i) { return allTargets[i]; });
}

const XCScheme* SBWorkspace::getScheme(const String& schemeName) const
{
  for (int i = 0; i < m_schemes.size(); i++) {
    if (m_schemes[i]->getName() == schemeName)
      return m_schemes[i];
  }
  
  SBLog::warning() << "Failed to find scheme with name: " << schemeName << std::endl;
  return NULL;
}

void SBWorkspace::getSchemes(const StringSet& schemeNames, SchemeVec& ret) const
{
  for (auto schemeName : schemeNames) {
    const XCScheme* scheme = getScheme(schemeName);
    if (scheme)
      ret.push_back(scheme);
  }
}

void SBWorkspace::queueSchemes(const StringSet& schemeNames, const StringSet& configNames)
{
  BuildSettings bs(NULL);
  bool isInteractive = bs.getValue("VSIMPORTER_INTERACTIVE") == "YES";
  
  // Get the specified schemes
  SchemeVec schemePtrs;
  if (schemeNames.empty()) {
    // Queue up all schemes
    schemePtrs.insert(schemePtrs.end(), m_schemes.begin(), m_schemes.end());
  } else {
    getSchemes(schemeNames, schemePtrs);
  }

  // Process all schemes
  for (auto scheme : schemePtrs) {
    // Process all build references in the scheme
    for (auto buildRef : scheme->getTargets()) {
      // Construct a path to the project specified by the BuildRef
      String projectPath = joinPaths(scheme->getContainerParentDir(), buildRef.container);

      // Find or create the project
      SBProject* targetProj = openProject(projectPath);

      // Create the target
      SBTarget* target = NULL;
      if (targetProj) {
        target = targetProj->queueTargetWithId(buildRef.id, &configNames);
      } else {
        SBLog::warning() << "Failed to open \"" << buildRef.container << "\" project referenced by \"" << scheme->getName() << "\" scheme. "
                         << "Ignoring \"" << buildRef.targetName << "\" target." << std::endl;
      }

      // Mark target as having been explicitly queued up
      if (target) {
        target->markExplicit();
      }
    }
  }
}

void SBWorkspace::getAllTargets(PotentialTargetsVec& targets) const
{
  for (auto projectKV : m_openProjects) {
    SBProject* sbProject = projectKV.second;
    const PBXProject* pbxProject = sbProject->getPBXProject();
    const PBXTargetList& projectTargets = pbxProject->getTargets();
    std::transform(projectTargets.begin(),
                   projectTargets.end(),
                   back_inserter(targets),
                   [sbProject](const PBXTarget* target) { return std::make_pair(target, sbProject); });
  }
}

void SBWorkspace::queueTargets(const StringSet& targetNames, const StringSet& configNames)
{
  BuildSettings bs(NULL);
  bool isInteractive = bs.getValue("VSIMPORTER_INTERACTIVE") == "YES";

  // Get the specified targets
  PotentialTargetsVec selectedTargets;
  if (isInteractive) {
    // Query the user to select targets to be queued
    selectTargets(selectedTargets);
  } else if (targetNames.empty()) {
    // Queue up all targets
    getAllTargets(selectedTargets);
  } else {
    // Try to find matching targets by name
    for (auto targetName : targetNames) {
      TargetProjectPair targetKV = findTargetWithName(targetName);
      if (targetKV.first) {
        selectedTargets.push_back(targetKV);
      }
    }
  }

  // Queue targets
  for (auto targetKV : selectedTargets) {
    SBTarget* target = targetKV.second->queueTarget(targetKV.first, &configNames);

    // Mark target as having been explicitly queued up
    if (target) {
      target->markExplicit();
    }
  }
}

SBProject* SBWorkspace::openProject(const String& projectPath)
{
  // Get absolute path to the project
  String absProjPath = sb_realpath(projectPath);

  // Check that the path is valid
  if (absProjPath.empty()) {
    SBLog::warning() << "Invalid project path: " << projectPath << std::endl;
    return NULL;
  }

  // Check if the project has already been opened
  SBProject* ret = s_workspace->findOpenProject(absProjPath);
  if (ret)
    return ret;

  // Create the project because it doesn't exist yet
  ret = SBProject::createFromPath(absProjPath);
  
  // Save a pointer to the newly create project and find all of its schemes
  if (ret) {
    m_openProjects[absProjPath] = ret;
    findSchemes(absProjPath);
  }

  return ret;
}

SBTarget* SBWorkspace::queueTargetWithProductName(const String& productName)
{
  // Ask every open project to try building the target with specified product name
  // until we find one that can.
  SBTarget* target = NULL;
  for (auto project : m_openProjects) {
    target = project.second->queueTargetWithProductName(productName);
    if (target)
      break;
  }
  return target;
}

SBTarget* SBWorkspace::queueTargetWithName(const String& targetName, const StringSet& configNames)
{
  // Ask every open project to try building the target with specified name
  SBTarget* target = NULL;
  for (auto project : m_openProjects) {
    target = project.second->queueTargetWithName(targetName, &configNames);
    if (target)
      break;
  }

  if (!target) {
    SBLog::warning() << "Unable to convert \"" << targetName << "\" target." << std::endl;
  }

  return target;
}

SBWorkspace::TargetProjectPair SBWorkspace::findTargetWithName(const String& targetName) const
{
  for (auto project : m_openProjects) {
    SBProject* sbProject = project.second;
    const PBXTarget* target = sbProject->getPBXProject()->getTargetWithName(targetName);
    if (target) {
      return make_pair(target, sbProject);
    }
  }

  SBLog::warning() << "Failed to find \"" << targetName << "\" target in workspace." << std::endl;
  return { NULL, NULL };
}

void SBWorkspace::detectProjectCollisions() const
{
  SBTargetList targets;
  std::map<String, const SBProject*> projectSolutionPaths;
  for (auto project : m_openProjects) {
    // Check for any project name collisions
    auto result = projectSolutionPaths.insert(make_pair(project.second->getName(), project.second));
    if (!result.second) {
      SBLog::error() << "Solution folder name collision detected between " << result.first->second->getPath() << " and " << project.second->getPath() << " projects." << std::endl;
    }

    // Get all project targets
    project.second->getQueuedTargets(targets);
  }

  // Check for any target name collisions
  std::map<String, const SBTarget*> targetOutputPaths;
  for (auto target : targets) {
    String projDir = target->getProject().getProjectDir();
    String outputFile = joinPaths(projDir, target->getName() + ".vcxproj");

    auto result = targetOutputPaths.insert(make_pair(outputFile, target));
    if (!result.second) {
      SBLog::error() << "Output file collision detected between " << target->getName() << " targets from " << result.first->second->getProject().getName() << " and " << target->getProject().getName() << " projects." << std::endl;
    }
  }
}

VCProject* SBWorkspace::generateGlueProject() const
{
  // Get a set of all configurations appearing in all projects
  StringSet slnConfigs;
  for (auto project : m_openProjects) {
    const StringSet& configs = project.second->getSelectedConfigurations();
    slnConfigs.insert(configs.begin(), configs.end());
  }

  // Get the template
  VSTemplate* vstemplate = VSTemplate::getTemplate("WinRT");
  sbAssertWithTelemetry(vstemplate, "Failed to get WinRT VS template");

  // Set up basis template parameters
  string projectName = getName() + "WinRT";
  VSTemplateParameters templateParams;
  templateParams.setProjectName(projectName);

  // Expand the template and get the template project
  vstemplate->expand(sb_dirname(getPath()), templateParams);
  const VSTemplateProjectVec& projTemplates = vstemplate->getProjects();
  sbAssertWithTelemetry(projTemplates.size() == 1, "Unexpected WinRT template size");

  // Create the glue project and add it to the solution
  VCProject* glueProject = new VCProject(projTemplates.front());

  // Get path to WinObjC SDK
  BuildSettings globalBS(NULL);
  String useRelativeSdkPath = globalBS.getValue("VSIMPORTER_RELATIVE_SDK_PATH");
  String sdkDir = globalBS.getValue("WINOBJC_SDK_ROOT");

  // Try to create a relative path to the SDK, if requested
  if (strToUpper(useRelativeSdkPath) == "YES") {
    String projectDir = sb_dirname(projTemplates.front()->getPath());
    sdkDir = getRelativePath(projectDir, sdkDir);
  }
  glueProject->addGlobalProperty("WINOBJC_SDK_ROOT", platformPath(sdkDir), "'$(WINOBJC_SDK_ROOT)' == ''");

  // Set configuration properties
  for (auto configName : slnConfigs) {
    VCProjectConfiguration *projConfig = glueProject->addConfiguration(configName);
    projConfig->setProperty("TargetName", getName());
  }

  // Set RootNamespace
  glueProject->addGlobalProperty("RootNamespace", getName());

  return glueProject;
}

void SBWorkspace::generateFiles(bool genProjectionsProj)
{
  // Detect and warn about about any collisions
  detectProjectCollisions();

  // Get a set of all configurations appearing in all projects
  StringSet slnConfigs;
  for (auto project : m_openProjects) {
    const StringSet& configs = project.second->getSelectedConfigurations();
    slnConfigs.insert(configs.begin(), configs.end());
  }

  // Create a solution
  BuildSettings globalBS(NULL);
  String outputFormat = globalBS.getValue("VSIMPORTER_OUTPUT_FORMAT");
  String solutionPath = sb_fname(getPath()) + "-" + outputFormat + ".sln";
  VSSolution* sln = new VSSolution(solutionPath);

  // Register all configurations with the solution
  for (auto configName : slnConfigs) {
    sln->addConfiguration(configName);
  }

  // Construct VS Projects
  std::multimap<SBTarget*, VCProject*> vcProjects;
  for (auto project : m_openProjects) {
    project.second->constructVCProjects(*sln, slnConfigs, vcProjects);
  }

  // Construct a projections project, if required
  VCProject* glueProject = nullptr;
  if (genProjectionsProj) {
    glueProject = generateGlueProject();
    sln->addProject(glueProject);
  }

  // Resolve dependencies
  for (auto proj : vcProjects) {
    proj.first->resolveVCProjectDependecies(proj.second, vcProjects);

    // Add a dependency on all static/framework target projects
    if (glueProject && proj.first->getProductType() == TargetStaticLib) {
      glueProject->addProjectReference(proj.second);
    }
  }

  // Write solution/projects to disk
  sbValidateWithTelemetry(!vcProjects.empty(), "No valid targets to import.");
  sln->write();
}