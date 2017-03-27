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
#include "PBXBuildPhase.h"
#include "PBXBuildFile.h"
#include "PBXObjectIdConvert.h"

PBXBuildPhase::~PBXBuildPhase() {
}

PBXBuildPhase::PBXBuildPhase() {
}

void PBXBuildPhase::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXObject::initFromPlist(id, plist, pbxDoc);

    // Get files
    getStringVectorForKey(plist, "files", m_fileIds, VALUE_REQUIRED, m_parseER);
}

void PBXBuildPhase::resolvePointers() {
    // Get files ptrs
    convertObjectIdList(m_pbxDoc, m_fileIds, m_filePtrs);
}
