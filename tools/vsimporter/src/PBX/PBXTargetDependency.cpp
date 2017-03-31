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
#include "PBXTargetDependency.h"
#include "PBXTarget.h"
#include "PBXContainerItemProxy.h"
#include "PBXObjectIdConvert.h"

PBXTargetDependency::~PBXTargetDependency() {
}

PBXTargetDependency::PBXTargetDependency() : m_targetPtr(NULL), m_targetProxyPtr(NULL) {
}

PBXTargetDependency* PBXTargetDependency::createFromPlist(const String& id,
                                                          const Plist::dictionary_type& plist,
                                                          const PBXDocument* pbxDoc) {
    PBXTargetDependency* ret = new PBXTargetDependency;
    ret->initFromPlist(id, plist, pbxDoc);
    return ret;
}

void PBXTargetDependency::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXObject::initFromPlist(id, plist, pbxDoc);

    // Get name. Not sure about its usefullness though.
    getStringForKey(plist, "name", m_name, VALUE_OPTIONAL, m_parseER);

    // Get target
    getStringForKey(plist, "target", m_targetId, VALUE_OPTIONAL, m_parseER);

    // Get targetProxy
    // Not sure what it means when targetProxy is not specified, but sometimes it's not.
    getStringForKey(plist, "targetProxy", m_targetProxyId, VALUE_OPTIONAL, m_parseER);
}

void PBXTargetDependency::resolvePointers() {
    // Resolve target ptr
    convertObjectId(m_pbxDoc, m_targetId, m_targetPtr);

    // Resolve targetProxy ptr
    convertObjectId(m_pbxDoc, m_targetProxyId, m_targetProxyPtr);
}
