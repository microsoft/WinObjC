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
#include "XCVersionGroup.h"
#include "PBXFileReference.h"
#include "PBXObjectIdConvert.h"

XCVersionGroup::~XCVersionGroup() {
}

XCVersionGroup::XCVersionGroup() {
}

XCVersionGroup* XCVersionGroup::createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    XCVersionGroup* ret = new XCVersionGroup;
    ret->initFromPlist(id, plist, pbxDoc);
    return ret;
}

void XCVersionGroup::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXGroup::initFromPlist(id, plist, pbxDoc);

    // Get versionGroupType
    getStringForKey(plist, "versionGroupType", m_versionGroupType, VALUE_REQUIRED, m_parseER);

    // Get currentVersion
    getStringForKey(plist, "currentVersion", m_currentVersionId, VALUE_REQUIRED, m_parseER);
}

void XCVersionGroup::resolvePointers() {
    // Resolve pointers for super
    PBXGroup::resolvePointers();

    // Resolve currentVersion ptr
    convertObjectId(m_pbxDoc, m_currentVersionId, m_currentVersionPtr);
}
