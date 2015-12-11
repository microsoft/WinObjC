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
#include "SBLog.h"
#include "PBXTarget.h"
#include "PBXBuildFile.h"
#include "PBXFile.h"
#include "PBXReferenceProxy.h"
#include "PBXContainerItemProxy.h"
#include "PBXTargetDependency.h"
#include "SBTarget.h"
#include "SBNativeTarget.h"
#include "SBAggregateTarget.h"
#include "SBProject.h"
#include "SBWorkspace.h"
#include "SBBuildPhase.h"
#include "BuildSettings.h"

#include "xc2vs.h"
#include "VSSolution.h"
#include "VSSolutionProject.h"
#include "VSSolutionFolderProject.h"
#include "VCProject.h"
#include "VCProjectConfiguration.h"
#include "VSTemplateProject.h"

SBTarget::~SBTarget() {}

SBTarget::SBTarget(const PBXTarget* target, const StringSet& configNames, SBProject& parentProject)
  : m_target(target),
    m_parentProject(parentProject)
{
  sbAssert(target);
  sbAssert(!configNames.empty());

  for (auto configName : configNames) {
    m_buildSettings[configName] = new BuildSettings(target, configName);
  }
}

SBTarget* SBTarget::create(const PBXTarget* target, const StringSet& configNames, SBProject& parentProject)
{
  if (!target)
    return NULL;
    
  const String& isa = target->getType();
  SBTarget* ret = NULL;
  if (isa == "PBXNativeTarget")
    ret = SBNativeTarget::create(target, configNames, parentProject);
  else if (isa == "PBXAggregateTarget")
    ret = SBAggregateTarget::create(target, configNames, parentProject);
  else
    SBLog::warning() << "Ignoring unsupported " << isa << " in \"" << parentProject.getName() << "\" project." << std::endl;
    
  return ret;
}

void SBTarget::validateSDK()
{
  // Check if this is an iphoneos target
  // Could take the form of "iphone" or a full path to the SDK
  for (auto bs : m_buildSettings) {
    const VariableCollectionHierarchy& vch = bs.second->getHierarchy();
    String sdkRoot = vch.getValue("SDKROOT", vch.size() - 2);
    sdkRoot = sb_basename(sdkRoot);
    strToLower(sdkRoot);
    if (!strBeginsWith(sdkRoot, "iphoneos")) {
      SBLog::warning() << "The \"" << bs.first << "\" configuration of the \"" << getName() << "\" target does not target an iOS SDK." << std::endl;
    }
  }
}

bool SBTarget::init()
{
  validateSDK();

  // Process dependencies
  processDependencies();

  // Create build phases (must be done after construction)
  SBBuildPhase::create(m_target->getBuildPhases(), *this, m_buildPhases);
  
  return true;
}

void SBTarget::addDependency(SBTarget* depTarget)
{
  if (!depTarget)
    return;

  // Look for the target in dependency list
  SBDependencyList::const_iterator depsIt = m_dependencies.begin();
  SBDependencyList::const_iterator depsEnd = m_dependencies.end();
  for (; (depsIt != depsEnd) && (*depsIt != depTarget); ++depsIt) {}

  // Add dependency target if it's not already in the list
  if (depsIt == depsEnd)
    m_dependencies.push_back(depTarget);
}

void SBTarget::processDependencies()
{
  const BuildSettings& projBS = m_parentProject.getBuildSettings();

  const DependencyList& depsList = m_target->getDependencies();
  for (unsigned i = 0; i < depsList.size(); i++) {
    String errStr = "Failed to process PBXTargetDependency (" + depsList[i]->getId() + ") for \"" + getName() + "\" target. ";

    const PBXTarget* target = depsList[i]->getTarget();
    const PBXContainerItemProxy* targetProxy = depsList[i]->getTargetProxy();

    SBProject* targetProject = NULL;
    SBTarget* depTarget = NULL;
    if (target) {
      targetProject = &m_parentProject;
      depTarget = targetProject->queueTarget(target);
    } else if (targetProxy) {
      String targetId = targetProxy->getRemoteId();
      String projectPath = targetProxy->getPortalPath();
      String absProjectPath = projBS.expand(projectPath, PathValue);

      targetProject = SBWorkspace::get()->openProject(absProjectPath);
      if (targetProject)
        depTarget = targetProject->queueTargetWithId(targetId);
      else
        SBLog::warning() << errStr << "Unable to open referenced project path: " << projectPath << std::endl;
    } else {
      SBLog::warning() << errStr << "Missing remote target info." << std::endl;
    }

    if (targetProject && !depTarget)
      SBLog::warning() << errStr << "Unable to create dependency target in \"" << targetProject->getName() << "\" project." << std::endl;
  
    addDependency(depTarget);
  }
}

const String& SBTarget::getName() const
{
  return m_target->getName();
}

const String& SBTarget::getId() const
{
  return m_target->getId();
}

String SBTarget::getProductFileName() const
{
  return m_target->getProductFileName();
}

const BuildSettingsMap& SBTarget::getBuildSettings() const
{
  return m_buildSettings;
}

const SBProject& SBTarget::getProject() const
{
  return m_parentProject;
}

String SBTarget::makeAbsolutePath(const String& path) const
{
  const BuildSettings& projBS = m_parentProject.getBuildSettings();
  return joinPaths(m_parentProject.getProjectDir(), projBS.expand(path, PathValue));
}

String SBTarget::makeRelativePath(const String& path, const String& absRoot) const
{
  String absPath = makeAbsolutePath(path);
  if (absRoot.empty()) {
    return getRelativePath(m_parentProject.getProjectDir(), absPath);
  } else {
    return getRelativePath(absRoot, absPath);
  }
}

SBTarget* SBTarget::getPossibleTarget(const PBXBuildFile* buildFile)
{
  static const char* const _productWildcards[] = {"lib*.a", "*.app", "*.framework", "*.bundle"};
  static StringVec productWildcards(_productWildcards, _productWildcards + sizeof(_productWildcards) / sizeof(char*));

  sbAssert(buildFile);
  const PBXFile* file = buildFile->getFile();
  
  String filePath, fileName;
  if (file) {
    filePath = file->getFullPath();
    fileName = sb_basename(filePath);
  }

  SBTarget* depTarget = NULL;
  const PBXReferenceProxy* proxyFile = NULL;

  // We are interested in any potential Xcode build products
  if (!matchWildcardList(fileName, productWildcards)) {
    // Do nothing
  } else if ((proxyFile = dynamic_cast<const PBXReferenceProxy*>(file))) {
    // Construct base error string, to hopefully never be used
    String errStr = "Failed to process PBXBuildFile (" + buildFile->getId() + ") for " + getName() + " target. ";

    // Get remote proxy container
    const PBXContainerItemProxy* container = proxyFile->getContainer();

    // Ignore build file, if necessary
    if (!container) {
      SBLog::warning() << errStr << "Unable to get the PBXContainerItemProxy.";
      return NULL;
    }

    // Get remote project and target identifier from the proxy
    const String& remoteId = container->getRemoteId();
    String projectPath = container->getPortalPath();

    // Expand the project path
    const BuildSettings& projBS = m_parentProject.getBuildSettings();
    String absProjectPath = projBS.expand(projectPath, PathValue);
      
    // Try to open the remote project
    SBProject* remoteProject = SBWorkspace::get()->openProject(absProjectPath);

    // Try to queue up the target with the given product reference
    if (remoteProject) {
      depTarget = remoteProject->queueTargetWithProductReference(remoteId);
      if (!depTarget)
        SBLog::warning() << errStr << "Unable to create proxy target " << remoteId << " from the \"" << remoteProject->getName() << "\" project." << std::endl;
    } else {
      SBLog::warning() << errStr << "Unable to open referenced project path: " << projectPath << std::endl;
    }
  } else {
    // Look for target in current project first
    depTarget = m_parentProject.queueTargetWithProductName(fileName);

    // Look for target in workspace, if it hasn't been found already
    if (!depTarget)
      depTarget = SBWorkspace::get()->queueTargetWithProductName(fileName);
  }

  // Add the target to the dependency set
  addDependency(depTarget);

  // Indicate whether this was a dependency or not
  return depTarget;
}

VCProject* SBTarget::constructVCProject(VSTemplateProject* projTemplate)
{
  // Create the project
  VCProject* proj = new VCProject(projTemplate);

  // Get path to WinObjC SDK
  const BuildSettings& projBS = m_parentProject.getBuildSettings();
  String useRelativeSdkPath = projBS.getValue("VSIMPORTER_RELATIVE_SDK_PATH");
  String sdkDir = projBS.getValue("WINOBJC_SDK_ROOT");

  // Try to create a relative path to the SDK, if requested
  if (strToUpper(useRelativeSdkPath) == "YES") {
    String projectDir = sb_dirname(projTemplate->getPath());
    sdkDir = getRelativePath(projectDir, sdkDir);
  }
  proj->setGlobalProperty("WINOBJC_SDK_ROOT", platformPath(sdkDir));

  // Set configuration properties
  for (auto configBS : m_buildSettings) {
    VCProjectConfiguration *projConfig = proj->addConfiguration(configBS.first);
    String execName = configBS.second->getValue("EXECUTABLE_NAME");
    if (getProductType() == TargetStaticLib)
      execName = sb_fname(execName);

    if (!execName.empty())
      projConfig->setProperty("TargetName", execName);
  }

  // Write files associated with each build phase
  SBBuildPhaseList::const_iterator phaseIt = m_buildPhases.begin();
  for (; phaseIt != m_buildPhases.end(); ++phaseIt)
    (*phaseIt)->writeVCProjectFiles(*proj);

  return proj;
}

static bool isSubset(const StringSet& subset, const StringSet& superset)
{
  for (auto e : subset) {
    if (superset.count(e) == 0) {
      return false;
    }
  }
  return true;
}

void SBTarget::resolveVCProjectDependecies(VCProject* proj, std::multimap<SBTarget*, VCProject*>& vcProjects)
{
  // Get the VCProject's platforms
  StringSet platforms;
  proj->getPlatforms(platforms);
 
  // Iterate over the target's dependencies
  for (auto dep : m_dependencies) {
    // Find all VCProjects generated from the SBTarget
    auto possibleDeps = vcProjects.equal_range(dep);

    // Look for the best-matching VCProject
    // BIG ASSUMPTION: Projects will have distinct platform sets, so only one match exists
    VCProject* match = NULL;
    for (auto it = possibleDeps.first; it != possibleDeps.second; ++it) {
      VCProject* depVCProject = it->second;
      StringSet depPlatforms;
      depVCProject->getPlatforms(depPlatforms);

      if (isSubset(platforms, depPlatforms)) {
        match = depVCProject;
        break;
      }
    }

    sbAssert(match);
    proj->addProjectReference(match);
  }
}