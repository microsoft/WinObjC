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

#ifndef _PBXBUILDPHASE_H_
#define _PBXBUILDPHASE_H_

#include "PBXObject.h"

class PBXBuildFile;

typedef std::vector<PBXBuildFile*> BuildFileList;

class PBXBuildPhase : public PBXObject {
public:
    virtual ~PBXBuildPhase() = 0;
    virtual void resolvePointers();
    const BuildFileList& getBuildFileList() const {
        return m_filePtrs;
    }

    static PBXBuildPhase* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

protected:
    PBXBuildPhase();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    StringVec m_fileIds;
    /* End of serialized values */

    BuildFileList m_filePtrs;
};

#endif /* _PBXBUILDPHASE_H_ */
