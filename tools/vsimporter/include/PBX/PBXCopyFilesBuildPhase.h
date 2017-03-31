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

#ifndef _PBXCOPYFILESBUILDPHASE_H_
#define _PBXCOPYFILESBUILDPHASE_H_

#include "PBXBuildPhase.h"

class PBXCopyFilesBuildPhase : public PBXBuildPhase {
public:
    virtual ~PBXCopyFilesBuildPhase();
    const String& getName() const {
        return m_name;
    }
    const String& getDestPath() const {
        return m_dstPath;
    }
    int getDestSubfolderSpec() const {
        return m_dstSubfolderSpec;
    }

    static PBXCopyFilesBuildPhase* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

private:
    PBXCopyFilesBuildPhase();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    String m_name;
    String m_dstPath;
    int m_dstSubfolderSpec;
    /* End of serialized values */
};

#endif /* _PBXCOPYFILESBUILDPHASE_H_ */
