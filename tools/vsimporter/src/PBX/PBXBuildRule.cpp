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
#include "PBXBuildRule.h"

PBXBuildRule::~PBXBuildRule() {
}

PBXBuildRule::PBXBuildRule() {
}

PBXBuildRule* PBXBuildRule::createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    PBXBuildRule* ret = new PBXBuildRule;
    ret->initFromPlist(id, plist, pbxDoc);
    return ret;
}

void PBXBuildRule::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXObject::initFromPlist(id, plist, pbxDoc);

    // Get compilerSpec
    getStringForKey(plist, "compilerSpec", m_compilerSpec, VALUE_REQUIRED, m_parseER);

    // Get filePatterns
    getStringForKey(plist, "filePatterns", m_filePatterns, VALUE_OPTIONAL, m_parseER);

    // Get fileType
    getStringForKey(plist, "fileType", m_fileType, VALUE_REQUIRED, m_parseER);

    // Get outputFiles
    getStringVectorForKey(plist, "outputFiles", m_outputFiles, VALUE_REQUIRED, m_parseER);

    // Get script
    getStringForKey(plist, "script", m_script, VALUE_OPTIONAL, m_parseER);
}
