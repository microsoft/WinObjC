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
#include "PBXLegacyTarget.h"

PBXLegacyTarget::~PBXLegacyTarget() {
}

PBXLegacyTarget::PBXLegacyTarget() {
}

PBXLegacyTarget* PBXLegacyTarget::createFromPlist(const String& id, const Plist::dictionary_type& dict, const PBXDocument* pbxDoc) {
    PBXLegacyTarget* ret = new PBXLegacyTarget;
    ret->initFromPlist(id, dict, pbxDoc);
    return ret;
}

void PBXLegacyTarget::initFromPlist(const String& id, const Plist::dictionary_type& dict, const PBXDocument* pbxDoc) {
    // Call super init
    PBXTarget::initFromPlist(id, dict, pbxDoc);

    // Get buildArgumentsString
    getStringForKey(dict, "buildArgumentsString", m_buildArgumentsString, VALUE_REQUIRED, m_parseER);
    // m_buildArgumentsString = removeQuotes(m_buildArgumentsString);

    // Get buildToolPath
    getStringForKey(dict, "buildToolPath", m_buildToolPath, VALUE_REQUIRED, m_parseER);

    // Get buildWorkingDirectory
    getStringForKey(dict, "buildWorkingDirectory", m_buildWorkingDirectory, VALUE_REQUIRED, m_parseER);

    // Get passBuildSettingsInEnvironment
    m_passBuildSettingsInEnvironment = getIntForKey(dict, "passBuildSettingsInEnvironment", VALUE_REQUIRED, m_parseER);
}
