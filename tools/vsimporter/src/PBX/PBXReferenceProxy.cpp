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
#include "PBXReferenceProxy.h"
#include "PBXContainerItemProxy.h"
#include "PBXObjectIdConvert.h"

PBXReferenceProxy::~PBXReferenceProxy() {
}

PBXReferenceProxy::PBXReferenceProxy() : m_remoteRefPtr(NULL) {
}

PBXReferenceProxy* PBXReferenceProxy::createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    PBXReferenceProxy* ret = new PBXReferenceProxy;
    ret->initFromPlist(id, plist, pbxDoc);
    return ret;
}

void PBXReferenceProxy::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXFile::initFromPlist(id, plist, pbxDoc);

    // Get fileType
    getStringForKey(plist, "fileType", m_fileType, VALUE_REQUIRED, m_parseER);

    // Get remoteRef
    getStringForKey(plist, "remoteRef", m_remoteRefId, VALUE_REQUIRED, m_parseER);
}

void PBXReferenceProxy::resolvePointers() {
    // Get remoteRef ptr
    convertObjectId(m_pbxDoc, m_remoteRefId, m_remoteRefPtr);
}
