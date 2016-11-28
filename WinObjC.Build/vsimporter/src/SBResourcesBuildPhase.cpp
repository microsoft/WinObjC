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
#include "BuildSettings.h"
#include "PBXResourcesBuildPhase.h"
#include "PBXBuildFile.h"
#include "SBResourcesBuildPhase.h"
#include "SBNativeTarget.h"
#include "SBProject.h"
#include "VCProjectConfiguration.h"
#include "VCProject.h"
#include "VCProjectItem.h"
#include "xc2vs.h"

static void parsePlist(const String& plistPath, VCProject& proj)
{
    //
    // Find any URL schemes registered to this bundle, in this format:
    //
    // <key>CFBundleURLTypes</key>
    // <array>
    //     <dict>
    //        <key>CFBundleURLSchemes</key>
    //        <array>
    //            <string>scheme1</string>
    //            <string>scheme2</string>
    //        </array>
    //    </dict>
    // </array>
    //

    using namespace Plist;
    using boost::any_cast;

    StringSet registeredUrlSchemes;

    boost::any plist;
    readPlist(plistPath.c_str(), plist);

    dictionary_type* dict = any_cast<dictionary_type>(&plist);
    if (dict == nullptr) {
        SBLog::warning() << "Unexpected Plist format in " << plistPath << std::endl;
        return;
    }

    auto iter = dict->find("CFBundleURLTypes");
    if (iter == dict->end()) {
        return;
    }

    array_type* urlTypes = any_cast<array_type>(&iter->second);
    if (urlTypes == nullptr) {
        SBLog::warning() << "Unexpected CFBundleURLTypes format in " << plistPath << std::endl;
        return;
    }

    for (auto& urlTypeElement : *urlTypes) {
        dictionary_type* urlType = any_cast<dictionary_type>(&urlTypeElement);
        if (urlType == nullptr) {
            SBLog::warning() << "Unexpected CFBundleURLTypes format in " << plistPath << std::endl;
            continue;
        }

        iter = urlType->find("CFBundleURLSchemes");
        if (iter == urlType->end()) {
            continue;
        }

        array_type* urlSchemes = any_cast<array_type>(&iter->second);
        if (urlSchemes == nullptr) {
            SBLog::warning() << "Unexpected CFBundleURLSchemes format in " << plistPath << std::endl;
            continue;
        }

        for (auto& urlScheme : *urlSchemes) {
            string_type* scheme = any_cast<string_type>(&urlScheme);
            if (scheme == nullptr) {
                SBLog::warning() << "Unexpected CFBundleURLSchemes format in " << plistPath << std::endl;
                continue;
            }

            registeredUrlSchemes.insert(*scheme);
        }
    }

    if (!registeredUrlSchemes.empty()) {
        proj.setUrlSchemes(registeredUrlSchemes);
    }
}

SBBuildPhase* SBResourcesBuildPhase::create(const PBXBuildPhase* phase, SBTarget& parentTarget)
{
  const PBXResourcesBuildPhase* resourcesPhase = dynamic_cast<const PBXResourcesBuildPhase*>(phase);
  SBNativeTarget& nativeParent = dynamic_cast<SBNativeTarget&>(parentTarget);
  return new SBResourcesBuildPhase(resourcesPhase, nativeParent);
}

// PBXResourcesBuildPhase can be NULL, if it wasn't explicitly specified in the project.
SBResourcesBuildPhase::SBResourcesBuildPhase(const PBXResourcesBuildPhase* phase, SBNativeTarget& parentTarget)
  : SBBuildPhase(phase, parentTarget),
    m_phase(phase)
{
  // Check if any of the resources are build products (e.g. bundles)
  if (m_phase) {
    for (auto buildFile : m_phase->getBuildFileList()) {
      m_buildFileTargets.push_back(parentTarget.getPossibleTarget(buildFile));
    }
  }
}

void SBResourcesBuildPhase::writeVCProjectFiles(VCProject& proj) const
{
  TargetProductType productType = m_parentTarget.getProductType();
  if (productType != TargetApplication && productType != TargetBundle) {
    return;
  }

  // Process build files
  const BuildSettings& projBS = m_parentTarget.getProject().getBuildSettings();
  const BuildFileList& buildFiles = m_phase->getBuildFileList();
  sbAssertWithTelemetry(buildFiles.size() == m_buildFileTargets.size(), "Inconsistent number of Resource build files");
  for (size_t i = 0; i < buildFiles.size(); i++) {
    // Construct a path for Bundle build products, relative to the SolutionDir,
    // instead of using the Xcode path
    String pathOverride;
    if (m_buildFileTargets[i]) {
      String productFileName = sb_basename(buildFiles[i]->getFile()->getFullPath());
      String productFileType = buildFiles[i]->getFile()->getFileType();
      if (productFileType == "wrapper.cfbundle") {
        pathOverride = "$(SolutionDir)$(Configuration)\\" + productFileName;
      } else {
        SBLog::warning() << "Unexpected build product in ResourceBuildPhase: " << productFileName << std::endl;
      }
    }

    VCItemHint itemHint = { "SBResourceCopy" , pathOverride, "" };
    addBuildFileToVS(buildFiles[i], proj, projBS, &itemHint);
  }

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
      parsePlist(plistPath, proj);
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
