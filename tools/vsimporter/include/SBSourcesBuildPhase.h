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

#ifndef _SBSOURCESBUILDPHASE_H_
#define _SBSOURCESBUILDPHASE_H_

#include "SBBuildPhase.h"

class PBXSourcesBuildPhase;
class SBNativeTarget;

class SBSourcesBuildPhase : public SBBuildPhase {
public:
    static SBBuildPhase* create(const PBXBuildPhase* phase, SBTarget& parentTarget);
    virtual ~SBSourcesBuildPhase() {
    }
    virtual void writeVCProjectFiles(VCProject& proj) const;

private:
    SBSourcesBuildPhase(const PBXSourcesBuildPhase* phase, const SBNativeTarget& parentTarget);
    void fixOtherFlags(StringVec& otherFlagTokens, const String& vsProjectDir) const;

    const PBXSourcesBuildPhase* m_phase;
};

#endif /* _SBSOURCESBUILDPHASE_H_ */
