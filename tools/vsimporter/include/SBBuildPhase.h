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

#ifndef _SBBUILDPHASE_H_
#define _SBBUILDPHASE_H_

#include "types.h"
#include "PBXTarget.h"

class SBTarget;
class SBBuildPhase;
class VCProject;

typedef std::vector<SBBuildPhase*> SBBuildPhaseList;

class SBBuildPhase {
public:
    static void create(const BuildPhaseList& buildPhaseList, SBTarget& parentTarget, SBBuildPhaseList& ret);
    virtual ~SBBuildPhase() {
    }
    virtual void writeVCProjectFiles(VCProject& proj) const {
    }

protected:
    SBBuildPhase(const PBXBuildPhase* phase, const SBTarget& parentTarget);
    void writeVSFileDescriptions(VCProject& proj, const String& defaultGroup) const;

    const PBXBuildPhase* m_phase;
    const SBTarget& m_parentTarget;
};

#endif /* _SBBUILDPHASE_H_ */
