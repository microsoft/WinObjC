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

#ifndef _PBXGROUP_H_
#define _PBXGROUP_H_

#include "types.h"
#include "PBXFile.h"

class PBXDocument;

typedef std::vector<const PBXFile*> ConstFileList;
typedef bool (*fileMatchFunc)(const PBXFile*);

class PBXGroup : public PBXFile {
public:
    virtual ~PBXGroup();
    virtual void resolvePointers();

    const ConstFileList& getChildren() const {
        return m_childrenPtrs;
    }

    void getMatchingFiles(fileMatchFunc matchFunc, ConstFileList& ret) const;

    static PBXGroup* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

protected:
    PBXGroup();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    StringVec m_childrenIds;
    /* End of serialized values */

    ConstFileList m_childrenPtrs;
};

#endif /* _PBXGROUP_H_ */
