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
#include "utils.h"
#include "XCBuildConfiguration.h"
#include "PBXFileReference.h"
#include "PBXObjectIdConvert.h"

XCBuildConfiguration::~XCBuildConfiguration() {
}

XCBuildConfiguration::XCBuildConfiguration() {
}

XCBuildConfiguration* XCBuildConfiguration::createFromPlist(const String& id,
                                                            const Plist::dictionary_type& plist,
                                                            const PBXDocument* pbxDoc) {
    XCBuildConfiguration* ret = new XCBuildConfiguration;
    ret->initFromPlist(id, plist, pbxDoc);
    return ret;
}

void XCBuildConfiguration::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXObject::initFromPlist(id, plist, pbxDoc);

    // Get name
    getStringForKey(plist, "name", m_name, VALUE_REQUIRED, m_parseER);

    // Get baseConfigurationReference
    getStringForKey(plist, "baseConfigurationReference", m_baseConfigurationId, VALUE_OPTIONAL, m_parseER);

    // Get buildSettings
    getStringMapForKey(plist, "buildSettings", m_buildSettings, VALUE_REQUIRED, m_parseER);
}

void XCBuildConfiguration::resolvePointers() {
    // Resolve baseConfigurationReference ptr
    convertObjectId(m_pbxDoc, m_baseConfigurationId, m_baseConfigurationPtr);
}
