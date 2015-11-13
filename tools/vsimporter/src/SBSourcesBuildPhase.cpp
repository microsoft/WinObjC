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
#include "BuildSettings.h"
#include "PBXSourcesBuildPhase.h"
#include "SBSourcesBuildPhase.h"
#include "SBNativeTarget.h"
#include "SBProject.h"
#include "VCProject.h"
#include "VCProjectConfiguration.h"
#include "clangoptparser.h"
#include "xc2vs.h"

SBBuildPhase* SBSourcesBuildPhase::create(const PBXBuildPhase* phase, SBTarget& parentTarget)
{
  const PBXSourcesBuildPhase* compilePhase = dynamic_cast<const PBXSourcesBuildPhase*>(phase);
  SBNativeTarget& nativeParent = dynamic_cast<SBNativeTarget&>(parentTarget);
  return new SBSourcesBuildPhase(compilePhase, nativeParent);
}

SBSourcesBuildPhase::SBSourcesBuildPhase(const PBXSourcesBuildPhase* phase, const SBNativeTarget& parentTarget)
  : SBBuildPhase(phase, parentTarget),
    m_phase(phase)
{}

void SBSourcesBuildPhase::writeVCProjectFiles(VCProject& proj) const
{
  // We don't support source compilation when building bundles
  TargetProductType productType = m_parentTarget.getProductType();
  if (productType == TargetBundle)
  {
    if (!m_phase->getBuildFileList().empty()) {
      SBLog::warning() << "Ignoring all source files in \"" << m_parentTarget.getName() << "\" bundle target." << std::endl;
    }
    return;
  }

  SBBuildPhase::writeVSFileDescriptions(proj, "Text");

  String xcProjectDir = m_parentTarget.getProject().getProjectDir();
  String vsProjectDir = sb_dirname(proj.getPath());
  StringSet prefixHeaders;
  for (auto bs : m_parentTarget.getBuildSettings()) {
    VCProjectConfiguration* config = proj.addConfiguration(bs.first);

    // Prefix header (recalculate relative path)
    String prefixHeader = bs.second->getValue("GCC_PREFIX_HEADER");
    if (!prefixHeader.empty()) {
      String absHeaderPath = m_parentTarget.makeAbsolutePath(prefixHeader);
      String relHeaderPath = m_parentTarget.makeRelativePath(prefixHeader, vsProjectDir);;
      relHeaderPath = winPath(relHeaderPath);
      config->setItemDefinition("ClangCompile", "PrefixHeader", relHeaderPath);

      // Add plist file to project (only once)
      if (prefixHeaders.find(absHeaderPath) == prefixHeaders.end()) {
        addRelativeFilePathToVS("ClInclude", absHeaderPath, "", proj, *bs.second);
        prefixHeaders.insert(absHeaderPath);
      }
    }

    // Preprocessor definitions
    StringVec preprocessorTokens;
    bs.second->getValue("GCC_PREPROCESSOR_DEFINITIONS", preprocessorTokens);
    String preprocessorDefs = joinStrings(preprocessorTokens, ";");
    if (!preprocessorDefs.empty()) {
      config->setItemDefinition("ClangCompile", "PreprocessorDefinitions", preprocessorDefs);
    }

    // Optimization level
    String optimizationLevel = bs.second->getValue("GCC_OPTIMIZATION_LEVEL");
    if (!optimizationLevel.empty()) {
      String vsOptimizationLevel;
      if (optimizationLevel == "s") {
        vsOptimizationLevel = "MinSpace";
      } else if (optimizationLevel == "0") {
        vsOptimizationLevel = "Disabled";
      } else {
        vsOptimizationLevel = "MaxSpeed";
      }
      config->setItemDefinition("ClangCompile", "OptimizationLevel", vsOptimizationLevel);
    }

    // ARC
    String enableARC = bs.second->getValue("CLANG_ENABLE_OBJC_ARC");
    if (enableARC == "YES") {
      config->setItemDefinition("ClangCompile", "ObjectiveCARC", "true");
    }

    // Header search paths (make them relative)
    StringVec includePaths;
    bs.second->getValue("HEADER_SEARCH_PATHS", includePaths);
    for (auto &cur : includePaths) {
      cur = m_parentTarget.makeRelativePath(cur, vsProjectDir);
      cur = winPath(cur);
    }
    if (!includePaths.empty()) {
      config->setItemDefinition("ClangCompile", "IncludePaths", joinStrings(includePaths, ";"));
    }

    // User header search paths (make them relative)
    StringVec userIncludePaths;
    bs.second->getValue("USER_HEADER_SEARCH_PATHS", userIncludePaths);
    for (auto &cur : userIncludePaths) {
      cur = m_parentTarget.makeRelativePath(cur, vsProjectDir);
      cur = winPath(cur);
    }
    if (!userIncludePaths.empty()) {
      config->setItemDefinition("ClangCompile", "UserIncludePaths", joinStrings(userIncludePaths, ";"));
    }

    // Header map
    if (bs.second->getValue("USE_HEADERMAP") == "YES") {
      if (bs.second->getValue("ALWAYS_SEARCH_USER_PATHS") == "YES") {
        config->setItemDefinition("ClangCompile", "HeaderMap", "Combined");
      } else if (bs.second->getValue("HEADERMAP_INCLUDES_PROJECT_HEADERS") == "YES") {
        config->setItemDefinition("ClangCompile", "HeaderMap", "Project");
      }
    }

    // Other C flags
    String otherCFlags = bs.second->getValue("OTHER_CFLAGS");
    processClangFlags(otherCFlags, xcProjectDir, vsProjectDir);
    if (!otherCFlags.empty()) {
      config->setItemDefinition("ClangCompile", "OtherCFlags", otherCFlags);
    }

    // Other C++ flags
    String otherCPlusPlusFlags = bs.second->getValue("OTHER_CPLUSPLUSFLAGS");
    processClangFlags(otherCPlusPlusFlags, xcProjectDir, vsProjectDir);
    if (!otherCPlusPlusFlags.empty()) {
      config->setItemDefinition("ClangCompile", "OtherCPlusPlusFlags", otherCPlusPlusFlags);
    }
  }
}