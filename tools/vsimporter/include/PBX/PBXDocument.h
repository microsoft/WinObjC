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

#ifndef _PBXDOCUMENT_H_
#define _PBXDOCUMENT_H_

#include "Plist.hpp"
#include "types.h"
#include "ErrorReporter.h"

class PBXObject;
class PBXProject;

class PBXDocument {
public:
    ~PBXDocument();
    PBXProject* getProject() {
        return m_rootObjectPtr;
    }
    const PBXProject* getProject() const {
        return m_rootObjectPtr;
    }
    PBXObject* findObjectWithId(const String& id) const;
    const String& getPath() const {
        return m_path;
    }
    String getDir() const;
    String getName() const;

    static PBXDocument* createFromPlist(const Plist::dictionary_type& plist, const String& projectPath);
    static PBXDocument* createFromFile(const String& projPath);

private:
    typedef std::map<String, PBXObject*> PBXObjectMap;

    PBXDocument(const String& projectPath);
    bool initFromPlist(const Plist::dictionary_type& plist);
    void resolvePointers();
    void constructObjects(const Plist::dictionary_type& objectsDict);

    /* Start of serialized values */
    int m_archiveVersion;
    int m_objectVersion;
    PBXObjectMap m_objects;
    String m_rootObjectId;
    /* End of serialized values */

    // The parent directory and name of the project
    String m_path;
    // Error reporter for initialization stage
    ErrorReporter m_parseER;

    PBXProject* m_rootObjectPtr;
};

#endif /* _PBXDOCUMENT_H_ */
