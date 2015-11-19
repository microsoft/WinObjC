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
#include "BuildSettings.h"
#include "PBXResourcesBuildPhase.h"
#include "SBResourcesBuildPhase.h"
#include "SBNativeTarget.h"
#include "VCProjectConfiguration.h"
#include "VCProject.h"
#include "VCProjectItem.h"
#include "xc2vs.h"

SBBuildPhase* SBResourcesBuildPhase::create(const PBXBuildPhase* phase, SBTarget& parentTarget)
{
  const PBXResourcesBuildPhase* resourcesPhase = dynamic_cast<const PBXResourcesBuildPhase*>(phase);
  SBNativeTarget& nativeParent = dynamic_cast<SBNativeTarget&>(parentTarget);
  return new SBResourcesBuildPhase(resourcesPhase, nativeParent);
}

// PBXResourcesBuildPhase can be NULL, if it wasn't explicitly specified in the project.
SBResourcesBuildPhase::SBResourcesBuildPhase(const PBXResourcesBuildPhase* phase, const SBNativeTarget& parentTarget)
  : SBBuildPhase(phase, parentTarget),
    m_phase(phase)
{}

void SBResourcesBuildPhase::writeVCProjectFiles(VCProject& proj) const
{
  TargetProductType productType = m_parentTarget.getProductType();
  if (productType != TargetApplication && productType != TargetBundle) {
    return;
  }

  SBBuildPhase::writeVSFileDescriptions(proj, "SBResourceCopy");

  // Process all Info.plist files
  std::map<std::string, VCProjectItem*> infoPlistMap;
  for (auto bs : m_parentTarget.getBuildSettings()) {
    VCProjectConfiguration* config = proj.addConfiguration(bs.first);

    // Exclude all plist from building, by default
    config->setItemDefinition("SBInfoPlistCopy", "ExcludedFromBuild", "true");
    
    // Get absolute path to plist
    String plistPath = bs.second->getValue("INFOPLIST_FILE");
    plistPath = m_parentTarget.makeAbsolutePath(plistPath);

    // Add plist file to project (only once)
    if (infoPlistMap.find(plistPath) == infoPlistMap.end()) {
      infoPlistMap[plistPath] = addRelativeFilePathToVS("SBInfoPlistCopy", plistPath, "", proj, *bs.second);
    }

    // Un-exclude building plist for configuration
    String condition = "'$(Configuration)'=='" + bs.first + "'";
    infoPlistMap[plistPath]->setDefinition("ExcludedFromBuild", "false", condition);

    // Specify which variables files to use
    String varsFile = m_parentTarget.getName() + "-" + bs.first + "-xcvars.txt";
    infoPlistMap[plistPath]->setDefinition("VariableFile", varsFile, condition);
  }
}
