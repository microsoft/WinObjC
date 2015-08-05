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

SBWorkspace* SBWorkspace::s_workspace = NULL;

SBWorkspace::SBWorkspace() : m_workspace(NULL), m_mainProject(NULL) {}

SBWorkspace* SBWorkspace::get()
{
  return s_workspace;
}

SBWorkspace* SBWorkspace::createFromProject(const String &projectDir)
{
  sbAssert(!s_workspace);
  
  // Create the workspace
  s_workspace = new SBWorkspace();

  // Open project
  SBProject* proj = s_workspace->openProject(projectDir);

  // Failing to open a project here is fatal
  sbValidate(proj);

  // Save a ptr to the project, so later we can access the "main" project
  s_workspace->m_mainProject = proj;
  
  return s_workspace;
}

SBWorkspace* SBWorkspace::createFromWorkspace(const String &workspaceDir)
{
  sbAssert(!s_workspace);
  
  // Create the workspace
  s_workspace = new SBWorkspace();
  s_workspace->m_workspace = XCWorkspace::createFromFile(workspaceDir);
  sbValidate(s_workspace->m_workspace);

  // Record location of the workspace
  VariableCollectionManager& settingsManager = VariableCollectionManager::get();
  settingsManager.setGlobalVar("WORKSPACE_FILE_PATH", workspaceDir);

  // Open all projects referenced by the workspace
  const StringVec& projPaths = s_workspace->m_workspace->getProjectPaths();
  for (unsigned i = 0; i < projPaths.size(); i++) {
    s_workspace->openProject(projPaths[i]);
  }

  // A workspace MUST contain at least one scheme
  sbValidate(!s_workspace->m_schemes.empty(), "The \"" + s_workspace->getName() + "\" workspace does not contain any schemes.");
  
  // A workspace MUST also contain at least one open project
  sbValidate(!s_workspace->m_openProjects.empty(), "The \"" + s_workspace->getName() + "\" workspace does not contain any valid projects.");
  
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

void SBWorkspace::findProjectSchemes(const String& projectAbsPath, const PBXProject* proj)
{
  StringList schemePaths;

  // Find all scheme files in the shareddata directory
  String sharedDir = joinPaths(projectAbsPath, "xcshareddata");
  if (fileExists(sharedDir))
    findFiles(sharedDir.c_str(), "*.xcscheme", DT_REG, true, schemePaths);

  String userDir = joinPaths(projectAbsPath, "xcuserdata");
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
    XCScheme* scheme = XCScheme::createFromFile(*it, proj);
    if (scheme)
      m_schemes.push_back(scheme);
  }
}

void SBWorkspace::printSummary() const
{ 
  if (!m_mainProject)
    std::cout << "Information about workspace \"" << getName() << "\":" << std::endl;
  else
    m_mainProject->printSummary();
  
  if (!m_schemes.empty()) {
    std::cout << "    Schemes:" << std::endl;
    for (int i = 0; i < m_schemes.size(); i++)
      std::cout << "\t" << m_schemes[i]->getName() << std::endl;
  } else if (m_mainProject) {
    std::cout << "    The project does not contain any schemes." << std::endl;
  }
  std::cout << std::endl;
}

void SBWorkspace::querySchemes(SchemeVec& ret) const
{
  String queryMessage;
  if (m_workspace)
    queryMessage = "The \"" + getName() + "\" workspace contains multiple schemes.";
  else
    queryMessage = "The project contains multiple schemes.";
  
  queryListSelection(m_schemes, queryMessage, "scheme", ret);
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
  if (isInteractive) {
    // Query the user to select schemes
    querySchemes(schemePtrs);
  } else if (schemeNames.empty()) {
    // Queue up all schemes
    schemePtrs.insert(schemePtrs.end(), m_schemes.begin(), m_schemes.end());
  } else {
    getSchemes(schemeNames, schemePtrs);
  }

  // Process all schemes
  for (auto scheme : schemePtrs) {
    // Process all build references in the scheme
    for (auto buildRef : scheme->getTargets()) {
      // Get the project to which the scheme belongs
      const PBXProject* parentProject = scheme->getProject();
      // Construct a path to the project specified by the BuildRef
      String projectPath = joinPaths(parentProject->getProjectDir(), buildRef.container);
      // Find or create the project
      SBProject* targetProj = openProject(projectPath);

      // Create the target
      if (targetProj) {
        targetProj->queueProjectTargetWithId(buildRef.id, configNames);
      } else {
        SBLog::warning() << "Failed to open \"" << buildRef.container << "\" project referenced by \"" << scheme->getName() << "\" scheme. "
                         << "Ignoring \"" << buildRef.targetName << "\" target." << std::endl;
      }
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
    findProjectSchemes(absProjPath, ret->getPBXProject());
  }

  return ret;
}

void SBWorkspace::queueTargets(const StringSet& targetNames, const StringSet& configNames)
{
  sbAssert(m_mainProject);
  m_mainProject->queueProjectTargets(targetNames, configNames);
}

void SBWorkspace::queueAllTargets(const StringSet& configNames)
{
  const StringSet emptySet;
  for (auto project : m_openProjects) {
    project.second->queueProjectTargets(emptySet, configNames);
  }
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
    project.second->getTargets(targets);
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

void SBWorkspace::generateFiles()
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

  // Resolve dependencies
  for (auto proj : vcProjects) {
    proj.first->resolveVCProjectDependecies(proj.second, vcProjects);
  }

  // Write solution/projects to disk
  sbValidate(!vcProjects.empty(), "No valid targets to import.");
  sln->write();
}