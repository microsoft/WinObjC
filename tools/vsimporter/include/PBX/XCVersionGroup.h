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

#ifndef _XCVERSIONGROUP_H_
#define _XCVERSIONGROUP_H_

#include "PBXGroup.h"

class PBXFileReference;
class PBXDocument;

class XCVersionGroup : public PBXGroup {
public:
    virtual ~XCVersionGroup();
    virtual void resolvePointers();

    // virtual String getFullPath() const;
    virtual const String& getFileType() const {
        return m_versionGroupType;
    }

    static XCVersionGroup* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

private:
    XCVersionGroup();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    String m_versionGroupType;
    String m_currentVersionId;
    /* End of serialized values */

    PBXFileReference* m_currentVersionPtr;
};

#endif /* _XCVERSIONGROUP_H_ */
