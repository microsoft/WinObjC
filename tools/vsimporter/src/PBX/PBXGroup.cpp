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

#include "utils.h"
#include "PlistFuncs.h"
#include "SBLog.h"
#include "PBXGroup.h"
#include "PBXObjectIdConvert.h"

PBXGroup::~PBXGroup() {
}

PBXGroup::PBXGroup() {
}

PBXGroup* PBXGroup::createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    PBXGroup* ret = new PBXGroup;
    ret->initFromPlist(id, plist, pbxDoc);
    return ret;
}

void PBXGroup::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXFile::initFromPlist(id, plist, pbxDoc);

    // Get children
    getStringVectorForKey(plist, "children", m_childrenIds, VALUE_REQUIRED, m_parseER);
}

void PBXGroup::resolvePointers() {
    // Get children ptrs
    convertObjectIdList(m_pbxDoc, m_childrenIds, m_childrenPtrs);

    // Set this Group as the parent for all children
    // FIXME: Const casting is pretty sketchy.
    ConstFileList::iterator cIt = m_childrenPtrs.begin();
    ConstFileList::iterator cEnd = m_childrenPtrs.end();
    for (; cIt != cEnd; cIt++)
        const_cast<PBXFile*>(*cIt)->setParent(this);
}

void PBXGroup::getMatchingFiles(fileMatchFunc matchFunc, ConstFileList& ret) const {
    // Do a depth-first traversal of the children
    for (unsigned i = 0; i < m_childrenPtrs.size(); i++) {
        const PBXFile* childFile = m_childrenPtrs[i];
        const PBXGroup* childGroup = dynamic_cast<const PBXGroup*>(childFile);
        if (childGroup) {
            childGroup->getMatchingFiles(matchFunc, ret);
        } else if (matchFunc(childFile)) {
            ret.push_back(childFile);
        }
    }
}
