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
#include "PBXTarget.h"
#include "PBXBuildPhase.h"
#include "PBXTargetDependency.h"
#include "XCConfigurationList.h"
#include "PBXObjectIdConvert.h"
#include "VariableCollection.h"

PBXTarget::~PBXTarget() {
}

PBXTarget::PBXTarget() {
}

void PBXTarget::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc) {
    // Call super init
    PBXObject::initFromPlist(id, plist, pbxDoc);

    // Get buildConfigurationList
    getStringForKey(plist, "buildConfigurationList", m_buildConfigurationListId, VALUE_REQUIRED, m_parseER);

    // Get buildPhases
    getStringVectorForKey(plist, "buildPhases", m_buildPhaseIds, VALUE_REQUIRED, m_parseER);

    // Get dependencies
    getStringVectorForKey(plist, "dependencies", m_dependencyIds, VALUE_REQUIRED, m_parseER);

    // Get name
    getStringForKey(plist, "name", m_name, VALUE_REQUIRED, m_parseER);

    // Get productName
    getStringForKey(plist, "productName", m_productName, VALUE_REQUIRED, m_parseER);
}

void PBXTarget::resolvePointers() {
    // Resolve buildConfigurationList ptr
    convertObjectId(m_pbxDoc, m_buildConfigurationListId, m_buildConfigurationListPtr);

    // Resolve buildPhases ptrs
    convertObjectIdList(m_pbxDoc, m_buildPhaseIds, m_buildPhasePtrs);

    // Resolve dependencies ptrs
    convertObjectIdList(m_pbxDoc, m_dependencyIds, m_dependencyPtrs);
}

void PBXTarget::getBuildSettings(VariableCollection& settings) const {
    settings.insert("TARGET_NAME", m_name);
    settings.insert("PRODUCT_NAME", m_productName);
}
