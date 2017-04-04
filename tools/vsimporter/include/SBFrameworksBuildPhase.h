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

#ifndef _SBFRAMEWORKSBUILDPHASE_H_
#define _SBFRAMEWORKSBUILDPHASE_H_

#include "SBBuildPhase.h"

class PBXFrameworksBuildPhase;
class SBNativeTarget;
class BuildSettings;

class SBFrameworksBuildPhase : public SBBuildPhase {
public:
    static SBBuildPhase* create(const PBXBuildPhase* phase, SBTarget& parentTarget);
    virtual ~SBFrameworksBuildPhase() {
    }
    virtual void writeVCProjectFiles(VCProject& proj) const;

private:
    // Blocked libraries and their replacements are loaded in a std::map for quick lookup.
    // This class provides a case insensitive comparator for the std::map.
    static class CaseInsensitiveComparator {
    public:
        bool operator()(const String& firstString, const String& secondString) const {
            return _stricmp(firstString.c_str(), secondString.c_str()) < 0;
        }
    };

    typedef std::vector<const SBTarget*> SBTargetList;

    SBFrameworksBuildPhase(const PBXFrameworksBuildPhase* phase, SBNativeTarget& parentTarget);

    // Frameworks included from WinObjC packages are already added as dependencies from the package's
    // consumption targets. Therefore, the imported project should skip adding those libraries as
    // dependencies as it would be redundant.
    void loadFrameworksListFromFile(const String& fileName);

    // Static list of libraries from WinObjC.Frameworks and WinObjC.Frameworks.Core packages
    static StringSet s_WinObjCLibraries;

    const PBXFrameworksBuildPhase* m_phase;
    SBTargetList m_buildFileTargets;
};

#endif /* _SBFRAMEWORKSBUILDPHASE_H_ */
