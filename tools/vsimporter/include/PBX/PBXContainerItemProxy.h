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

#ifndef _PBXCONTAINERITEMPROXY_H_
#define _PBXCONTAINERITEMPROXY_H_

#include "PBXObject.h"

class PBXProject;
class PBXFileReference;

class PBXContainerItemProxy : public PBXObject {
public:
    virtual ~PBXContainerItemProxy();
    virtual void resolvePointers();
    String getPortalPath() const;
    const String& getRemoteId() const;

    static PBXContainerItemProxy* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

private:
    PBXContainerItemProxy();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    String m_containerPortalId;
    String m_remoteGlobalIDString;
    /* End of serialized values */

    // The portal could be a PBXProject or a PBXFileReference to another project file
    PBXProject* m_projectPortalPtr;
    PBXFileReference* m_filePortalPtr;
};

#endif /* _PBXCONTAINERITEMPROXY_H_ */
