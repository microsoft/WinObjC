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

#ifndef _SBRESOURCESBUILDPHASE_H_
#define _SBRESOURCESBUILDPHASE_H_

#include "SBBuildPhase.h"

class PBXResourcesBuildPhase;
class SBNativeTarget;

class SBResourcesBuildPhase : public SBBuildPhase {
public:
  static SBBuildPhase* create(const PBXBuildPhase* phase, SBTarget& parentTarget);
  virtual ~SBResourcesBuildPhase() {}
  virtual void writeVCProjectFiles(VCProject& proj) const;

private:
  typedef std::vector<const SBTarget*> SBTargetList;

  SBResourcesBuildPhase(const PBXResourcesBuildPhase* phase, SBNativeTarget& parentTarget);

  const PBXResourcesBuildPhase* m_phase;
  SBTargetList m_buildFileTargets;
};

#endif /* _SBRESOURCESBUILDPHASE_H_ */
