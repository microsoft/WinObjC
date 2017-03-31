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

#ifndef _PBXPROJECT_H_
#define _PBXPROJECT_H_

#include "PBXObject.h"

class XCConfigurationList;
class PBXGroup;
class PBXTarget;
class PBXFileReference;
class PBXDocument;
class VariableCollection;

typedef std::vector<const PBXTarget*> PBXTargetList;
typedef std::pair<PBXFileReference*, PBXGroup*> ProjectRefPair;
typedef std::vector<ProjectRefPair> ProjectRefList;

class PBXProject : public PBXObject {
public:
    virtual ~PBXProject();
    virtual void resolvePointers();

    const XCConfigurationList* getBuildConfigurationList() const;
    const PBXTargetList& getTargets() const {
        return m_targetPtrs;
    }
    void getTargets(const StringSet& targetNames, PBXTargetList& ret) const;
    const PBXGroup* getMainGroup() const {
        return m_mainGroupPtr;
    }
    const PBXTarget* getTargetWithName(const String& targetName) const;
    const PBXTarget* getTargetWithId(const String& targetId) const;
    const PBXTarget* getTargetWithProductName(const String& productName) const;
    const PBXTarget* getTargetWithProductReference(const String& productRef) const;
    String getProjectDir() const;
    const String& getPath() const;
    String getName() const;
    void getBuildSettings(VariableCollection& settings) const;

    static PBXProject* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

private:
    PBXProject();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    static PBXProject* createFromOpenStep(const String& projPath);

    /* Start of serialized values */
    String m_buildConfigurationListId;
    String m_mainGroupId;
    String m_projectDirPath;
    String m_projectRoot;
    StringPairList m_projectReferenceIds;
    StringVec m_targetIds;
    /* End of serialized values */

    XCConfigurationList* m_buildConfigurationListPtr;
    const PBXGroup* m_mainGroupPtr;
    ProjectRefList m_projectReferencePtrs;
    PBXTargetList m_targetPtrs;
};

#endif /* _PBXPROJECT_H_ */
