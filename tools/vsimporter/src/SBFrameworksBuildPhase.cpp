//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#include "..\WBITelemetry\WBITelemetry.h"

std::map<String, String, SBFrameworksBuildPhase::CaseInsensitiveComparator> SBFrameworksBuildPhase::s_blockedLibraries;

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

  // Load our blocked libraries and their replacements from file if not already loaded.
  if (s_blockedLibraries.empty())
  {
      loadFrameworkBlockListFromFile("framework-blocklist.txt");
  }
}

void SBFrameworksBuildPhase::loadFrameworkBlockListFromFile(const String& fileName)
{
    // Get the path to the file which has the block list.
    const BuildSettings bs(NULL);
    String templateDir = bs.getValue("VSIMPORTER_TEMPLATES_DIR");
    
    // If we have reached this far the folder is guaranteed to exist as we must have already called checkWinObjCSDK().
    assert(!sb_realpath(templateDir).empty());
    
    String blockListFilePath = joinPaths(templateDir, fileName);
    ifstream file(blockListFilePath);
    if (file.is_open())
    {
        String line;
        while (getline(file, line))
        {
            StringVec tokens;
            tokenize(line, tokens, "-> ");
            if (tokens.size() == 0)
            {
                // empty line
                continue;
            }

            // We do not expect more than 2 tokens per line.
            // First is the blocked library name and possibly a second token which is the replacement library name.
            sbValidateWithTelemetry(tokens.size() <= 2, 
                "Invalid Block List. Only one blocked library and an optional replacement library separated by '->' are allowed per line");
            
            String blockedLibrary = tokens[0];

            // We may or may not have the replacement library specified.
            String replaceWithLibrary = "";
            if (tokens.size() > 1)
            {
                replaceWithLibrary = tokens[1];

                // Check if the library replacements form a cycle.
                auto it = s_blockedLibraries.find(replaceWithLibrary);
                while (it != s_blockedLibraries.end())
                {
                    replaceWithLibrary = it->second;
					sbValidateWithTelemetry(blockedLibrary != replaceWithLibrary,
                        blockedLibrary + " is trying to cyclically replace itself with another blocked library.");
                    it = s_blockedLibraries.find(replaceWithLibrary);
                }
            }

            s_blockedLibraries.insert(pair<String, String>(blockedLibrary, replaceWithLibrary));
        }
        file.close();
    }
}

void SBFrameworksBuildPhase::writeVCProjectFiles(VCProject& proj) const
{
  // We don't support linking with frameworks when building bundles
  TargetProductType productType = m_parentTarget.getProductType();
  if (productType == TargetBundle) {
      if (!m_phase->getBuildFileList().empty()) {
          SBLog::warning() << "Ignoring all frameworks in \"" << m_parentTarget.getName() << "\" bundle target." << std::endl;
          TELEMETRY_EVENT(L"VSImporterLinkingFrameworksWithBundles");

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
	sbAssertWithTelemetry(buildFiles.size() == m_buildFileTargets.size(), "Inconsistent number of Framework build files");
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
    StringSet linkedLibs;
    linkedLibs.insert("%(AdditionalDependencies)");
    for (auto filePath : buildFilePaths) {
      if (productType == TargetStaticLib && !strEndsWith(filePath, ".a"))
        continue;

      String winLibName = sb_fname(sb_basename(filePath)) + ".lib";

      // If the library is blocked then add the replacement library to our additional dependencies 
      auto it = s_blockedLibraries.find(winLibName);
      while (it != s_blockedLibraries.end())
      {
          // get the replacement library.
          winLibName = it->second;

          // follow any transitive replacement.
          it = s_blockedLibraries.find(winLibName);
      }

      if (!winLibName.empty())
      {
          linkedLibs.insert(winLibName);
      }
    }

    // AdditionalDependencies
    String additionalDeps = joinStrings(linkedLibs, ";");
    if (!additionalDeps.empty()) {
      config->setItemDefinition(linkTarget, "AdditionalDependencies", additionalDeps);
    }
  }
}
