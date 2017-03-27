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
#include "PBXCopyFilesBuildPhase.h"

PBXCopyFilesBuildPhase::~PBXCopyFilesBuildPhase() {
}

PBXCopyFilesBuildPhase::PBXCopyFilesBuildPhase() {
}

PBXCopyFilesBuildPhase* PBXCopyFilesBuildPhase::createFromPlist(const String& id,
                                                                const Plist::dictionary_type& plist,
                                                                const PBXDocument* pbxDoc) {
    PBXCopyFilesBuildPhase* ret = new PBXCopyFilesBuildPhase;
    ret->initFromPlist(id, plist, pbxDoc);
    return ret;
}

void PBXCopyFilesBuildPhase::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXBuildPhase::initFromPlist(id, plist, pbxDoc);

    // Get name
    getStringForKey(plist, "name", m_name, VALUE_OPTIONAL, m_parseER);

    // Get dstPath
    getStringForKey(plist, "dstPath", m_dstPath, VALUE_REQUIRED, m_parseER);

    // Get dstSubfolderSpec
    m_dstSubfolderSpec = getIntForKey(plist, "dstSubfolderSpec", VALUE_REQUIRED, m_parseER);
}
