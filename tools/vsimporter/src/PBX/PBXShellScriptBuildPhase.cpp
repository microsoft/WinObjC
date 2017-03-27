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
#include "PBXShellScriptBuildPhase.h"

PBXShellScriptBuildPhase::~PBXShellScriptBuildPhase() {
}

PBXShellScriptBuildPhase::PBXShellScriptBuildPhase() {
}

PBXShellScriptBuildPhase* PBXShellScriptBuildPhase::createFromPlist(const String& id,
                                                                    const Plist::dictionary_type& plist,
                                                                    const PBXDocument* pbxDoc) {
    PBXShellScriptBuildPhase* ret = new PBXShellScriptBuildPhase;
    ret->initFromPlist(id, plist, pbxDoc);
    return ret;
}

void PBXShellScriptBuildPhase::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXBuildPhase::initFromPlist(id, plist, pbxDoc);

    // Get name
    getStringForKey(plist, "name", m_name, VALUE_OPTIONAL, m_parseER);

    // Get inputPaths
    getStringVectorForKey(plist, "inputPaths", m_inputPaths, VALUE_OPTIONAL, m_parseER);

    // Get outputPaths
    getStringVectorForKey(plist, "outputPaths", m_outputPaths, VALUE_OPTIONAL, m_parseER);

    // Get shellPath
    getStringForKey(plist, "shellPath", m_shellPath, VALUE_REQUIRED, m_parseER);

    // Get shellScript
    getStringForKey(plist, "shellScript", m_shellScript, VALUE_REQUIRED, m_parseER);
}
