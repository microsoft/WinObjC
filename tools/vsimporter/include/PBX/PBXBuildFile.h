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

#ifndef _PBXBUILDFILE_H_
#define _PBXBUILDFILE_H_

#include "PBXObject.h"

class PBXFile;
class PBXDocument;

enum BuildFileAttributes { ATTR_NONE = 0, ATTR_PUBLIC = 1, ATTR_PRIVATE = 2 };

class PBXBuildFile : public PBXObject {
public:
    virtual ~PBXBuildFile();
    virtual void resolvePointers();

    const PBXFile* getFile() const;
    int getAttributes() const {
        return m_attributes;
    }
    const String& getCompilerFlags() const {
        return m_compilerFlags;
    }

    static PBXBuildFile* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

private:
    PBXBuildFile();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    String m_fileRefId;
    int m_attributes;
    String m_compilerFlags;
    /* End of serialized values */

    const PBXFile* m_fileRefPtr;
};

#endif /* _PBXBUILDFILE_H_ */
