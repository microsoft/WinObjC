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

#ifndef _PBXTARGETDEPENDENCY_H_
#define _PBXTARGETDEPENDENCY_H_

#include "PBXObject.h"

class PBXTarget;
class PBXContainerItemProxy;
class PBXDocument;

class PBXTargetDependency : public PBXObject {
public:
    virtual ~PBXTargetDependency();
    virtual void resolvePointers();
    const PBXTarget* getTarget() const {
        return m_targetPtr;
    }
    const PBXContainerItemProxy* getTargetProxy() const {
        return m_targetProxyPtr;
    }

    static PBXTargetDependency* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

private:
    PBXTargetDependency();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    String m_name;
    String m_targetId;
    String m_targetProxyId;
    /* End of serialized values */

    const PBXTarget* m_targetPtr;
    const PBXContainerItemProxy* m_targetProxyPtr;
};

#endif /* _PBXTARGETDEPENDENCY_H_ */
