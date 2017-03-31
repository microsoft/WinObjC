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

#ifndef _PBXFILEBASE_H_
#define _PBXFILEBASE_H_

#include "PBXObject.h"

class PBXGroup;

class PBXFile : public PBXObject {
public:
    virtual ~PBXFile() = 0;
    void setParent(PBXGroup* parent) {
        m_parent = parent;
    }

    const String& getPath() const {
        return m_path;
    }
    const String& getName() const {
        return m_name;
    }
    String getFullPath() const;
    String getVirtualPath() const;
    virtual const String& getFileType() const;

    // FIXME: rename this?
    static String getFileType(const String& fileName);

protected:
    PBXFile();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    String m_path;
    String m_name;
    String m_sourceTree;
    /* End of serialized values */

    PBXGroup* m_parent;
};

#endif /* _PBXFILEBASE_H_ */
