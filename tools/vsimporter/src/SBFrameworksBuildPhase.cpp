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
#include "clangoptparser.h"
#include "BuildSettings.h"
#include "PBXFrameworksBuildPhase.h"
#include "PBXBuildPhase.h"
#include "PBXBuildFile.h"
#include "PBXFile.h"
#include "SBFrameworksBuildPhase.h"
#include "SBNativeTarget.h"
#include "SBLog.h"

#include "VCProject.h"
#include "VCProjectConfiguration.h"

SBBuildPhase* SBFrameworksBuildPhase::create(const PBXBuildPhase* phase, SBTarget& parentTarget)
{
  const PBXFrameworksBuildPhase* linkPhase = dynamic_cast<const PBXFrameworksBuildPhase*>(phase);
  SBNativeTarget& nativeParent = dynamic_cast<SBNativeTarget&>(parentTarget);
  return new SBFrameworksBuildPhase(linkPhase, nativeParent);
}

// PBXFrameworksBuildPhase can be NULL, if it wasn't explicitly specified in the project.
SBFrameworksBuildPhase::SBFrameworksBuildPhase(const PBXFrameworksBuildPhase* phase, SBNativeTarget& parentTarget)
  : SBBuildPhase(phase, parentTarget),
    m_phase(phase)
{
  if (!m_phase)
    return;

  // Figure out if any of the frameworks are built from source
  for (auto buildFile : m_phase->getBuildFileList()) {
    m_buildFileTargets.push_back(parentTarget.getPossibleTarget(buildFile));
  }
}

void SBFrameworksBuildPhase::writeVCProjectFiles(VCProject& proj) const
{
  // We don't support linking with frameworks when building bundles
  TargetProductType productType = m_parentTarget.getProductType();
  if (productType == TargetBundle) {
    if (!m_phase->getBuildFileList().empty()) {
      SBLog::warning() << "Ignoring all frameworkss in \"" << m_parentTarget.getName() << "\" bundle target." << std::endl;
    }
    return;
  }

  String linkTarget;
  if (productType == TargetApplication)
    linkTarget = "Link";
  else if (productType == TargetStaticLib)
    linkTarget = "Lib";

  // Get paths to all the build files (frameworks)
  StringVec buildFilePaths;
  if (m_phase) {
    const BuildFileList& buildFiles = m_phase->getBuildFileList();
    sbAssert(buildFiles.size() == m_buildFileTargets.size());
    for (size_t i = 0; i < buildFiles.size(); i++) {
      const PBXFile* file = buildFiles[i]->getFile();
      // Ignore any frameworks build from source (they will be added as project references)
      if (file && !m_buildFileTargets[i])
        buildFilePaths.push_back(file->getFullPath());
    }
  }

  for (auto bs : m_parentTarget.getBuildSettings()) {
    VCProjectConfiguration* config = proj.addConfiguration(bs.first);

    // Extrace libs/frameworks from OTHER_LDFLAGS
    StringVec buildFilePaths(buildFilePaths);
    processLDFlags(bs.second->getValue("OTHER_LDFLAGS"), buildFilePaths);

    // Construct a list of libraries to link against
    StringVec linkedLibs;
    linkedLibs.push_back("%(AdditionalDependencies)");
    for (auto filePath : buildFilePaths) {
      if (productType == TargetStaticLib && !strEndsWith(filePath, ".a"))
        continue;

      String winLibName = sb_fname(sb_basename(filePath)) + ".lib";
      linkedLibs.push_back(winLibName);
    }

    // AdditionalDependencies
    String additionalDeps = joinStrings(linkedLibs, ";");
    if (!additionalDeps.empty()) {
      config->setItemDefinition(linkTarget, "AdditionalDependencies", additionalDeps);
    }
  }
}
