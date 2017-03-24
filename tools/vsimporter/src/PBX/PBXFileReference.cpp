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
#include "PBXFileReference.h"
#include "fileutils.h"

PBXFileReference::~PBXFileReference() {
}

PBXFileReference::PBXFileReference() {
}

PBXFileReference* PBXFileReference::createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    PBXFileReference* ret = new PBXFileReference;
    ret->initFromPlist(id, plist, pbxDoc);
    return ret;
}

void PBXFileReference::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXFile::initFromPlist(id, plist, pbxDoc);

    // Check lastKnownFileType first
    getStringForKey(plist, "lastKnownFileType", m_fileType, VALUE_OPTIONAL, m_parseER);

    // Check explicitFileType second, so it can override the lastKnownFileType
    getStringForKey(plist, "explicitFileType", m_fileType, VALUE_OPTIONAL, m_parseER);

    // If no filetype was specified, use the extension
    if (m_fileType.empty())
        m_fileType = PBXFile::getFileType(m_path);
}
