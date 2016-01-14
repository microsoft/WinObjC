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
#include "PBXBuildPhase.h"
#include "PBXBuildFile.h"
#include "SBTarget.h"
#include "SBProject.h"
#include "SBFrameworksBuildPhase.h"
#include "SBResourcesBuildPhase.h"
#include "SBSourcesBuildPhase.h"
#include "SBNativeTarget.h"
#include "SBBuildPhase.h"
#include "xc2vs.h"

void SBBuildPhase::create(const BuildPhaseList& buildPhaseList, SBTarget& parentTarget, SBBuildPhaseList& ret)
{
  SBBuildPhase* frameworksPhase = NULL;
  SBBuildPhase* sourcesPhase = NULL;
  SBBuildPhase* resourcesPhase = NULL;

  for (unsigned i = 0; i < buildPhaseList.size(); i++) {
    const String& isa = buildPhaseList[i]->getType();
    SBBuildPhase* phase = NULL;

    if (isa == "PBXFrameworksBuildPhase")
      frameworksPhase = phase = SBFrameworksBuildPhase::create(buildPhaseList[i], parentTarget);
    else if (isa == "PBXResourcesBuildPhase")
      resourcesPhase = phase = SBResourcesBuildPhase::create(buildPhaseList[i], parentTarget);
    else if (isa == "PBXSourcesBuildPhase")
      sourcesPhase = phase = SBSourcesBuildPhase::create(buildPhaseList[i], parentTarget);
    else
      SBLog::warning() << "Ignoring unsupported " << isa << " in \"" << parentTarget.getName() << "\" target." << std::endl;

    if (phase)
      ret.push_back(phase);
  }

  // Force creation of a PBXFrameworksBuildPhase and/or PBXResourcesBuildPhase,
  // if they were not created explicitly.
  if (sourcesPhase && !frameworksPhase)
    ret.push_back(SBFrameworksBuildPhase::create(NULL, parentTarget));
  if (sourcesPhase && !resourcesPhase)
    ret.push_back(SBResourcesBuildPhase::create(NULL, parentTarget));
}

SBBuildPhase::SBBuildPhase(const PBXBuildPhase* phase, const SBTarget& parentTarget)
  : m_phase(phase),
    m_parentTarget(parentTarget)
{}

void SBBuildPhase::writeVSFileDescriptions(VCProject& proj, const String& defaultGroup) const
{
  // The m_phase pointer can be NULL for implicit build phases.
  if (!m_phase)
    return;

  const BuildSettings& projBS = m_parentTarget.getProject().getBuildSettings();
  VCItemHint itemHint = { defaultGroup, "" };
  for (auto buildFile : m_phase->getBuildFileList()) {
    addBuildFileToVS(buildFile, proj, projBS, &itemHint);
  }
}