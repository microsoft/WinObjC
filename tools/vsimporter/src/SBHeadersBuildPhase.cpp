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

#include "PBXHeadersBuildPhase.h"
#include "PBXBuildFile.h"
#include "SBHeadersBuildPhase.h"
#include "SBNativeTarget.h"
#include "SBProject.h"
#include "sbassert.h"
#include "xc2vs.h"

SBBuildPhase* SBHeadersBuildPhase::create(const PBXBuildPhase* phase, SBTarget& parentTarget)
{
  const PBXHeadersBuildPhase* headersPhase = dynamic_cast<const PBXHeadersBuildPhase*>(phase);
  SBNativeTarget& nativeParent = dynamic_cast<SBNativeTarget&>(parentTarget);
  return new SBHeadersBuildPhase(headersPhase, nativeParent);
}

SBHeadersBuildPhase::SBHeadersBuildPhase(const PBXHeadersBuildPhase* phase, const SBNativeTarget& parentTarget)
  : SBBuildPhase(phase, parentTarget),
  m_phase(phase)
{}

void SBHeadersBuildPhase::writeVCProjectFiles(VCProject& proj) const
{
  TargetProductType productType = m_parentTarget.getProductType();
  if (productType != TargetStaticLib) {
    return;
  }

  // Process public headers
  const BuildSettings& projBS = m_parentTarget.getProject().getBuildSettings();
  const BuildFileList& buildFiles = m_phase->getBuildFileList();
  for (size_t i = 0; i < buildFiles.size(); i++) {
    if (buildFiles[i]->getAttributes() & ATTR_PUBLIC) {
      VCItemHint itemHint = { "ClInclude" , "", "Public Headers" };
      addBuildFileToVS(buildFiles[i], proj, projBS, &itemHint);
    }
  }
}