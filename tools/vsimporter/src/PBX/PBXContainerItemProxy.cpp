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

#include "PlistFuncs.h"
#include "SBLog.h"
#include "PBXContainerItemProxy.h"
#include "PBXProject.h"
#include "PBXDocument.h"
#include "PBXFileReference.h"
#include "PBXObjectIdConvert.h"

PBXContainerItemProxy::~PBXContainerItemProxy() {
}

PBXContainerItemProxy::PBXContainerItemProxy() : m_projectPortalPtr(NULL), m_filePortalPtr(NULL) {
}

PBXContainerItemProxy* PBXContainerItemProxy::createFromPlist(const String& id,
                                                              const Plist::dictionary_type& dict,
                                                              const PBXDocument* pbxDoc) {
    PBXContainerItemProxy* ret = new PBXContainerItemProxy;
    ret->initFromPlist(id, dict, pbxDoc);
    return ret;
}

void PBXContainerItemProxy::initFromPlist(const String& id, const Plist::dictionary_type& dict, const PBXDocument* pbxDoc) {
    // Call super init
    PBXObject::initFromPlist(id, dict, pbxDoc);

    // Get containerPortal
    getStringForKey(dict, "containerPortal", m_containerPortalId, VALUE_REQUIRED, m_parseER);

    // Get remoteGlobalIDString
    getStringForKey(dict, "remoteGlobalIDString", m_remoteGlobalIDString, VALUE_REQUIRED, m_parseER);
}

void PBXContainerItemProxy::resolvePointers() {
    // Get containerPortal ptrs
    convertObjectId(m_pbxDoc, m_containerPortalId, m_projectPortalPtr);
    convertObjectId(m_pbxDoc, m_containerPortalId, m_filePortalPtr);
}

String PBXContainerItemProxy::getPortalPath() const {
    checkFieldPtr(m_projectPortalPtr || m_filePortalPtr, "containerPortal");

    if (m_projectPortalPtr) {
        const PBXDocument& pbxDoc = getOwner();
        const PBXProject* project = pbxDoc.getProject();
        checkFieldVal(m_projectPortalPtr == project, m_containerPortalId, "containerPortal");
        if (m_projectPortalPtr == project)
            return pbxDoc.getPath();
    } else if (m_filePortalPtr) {
        return m_filePortalPtr->getFullPath();
    }

    return "";
}

const String& PBXContainerItemProxy::getRemoteId() const {
    checkFieldNonEmpty(m_remoteGlobalIDString, "remoteGlobalIDString");
    return m_remoteGlobalIDString;
}