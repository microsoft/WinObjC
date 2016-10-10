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

#include <fstream>
#include <iostream>
#include <string.h>

#include "utils.h"
#include "PlistFuncs.h"
#include "SBLog.h"
#include "PBXProject.h"
#include "PBXTarget.h"
#include "PBXGroup.h"
#include "XCConfigurationList.h"
#include "PBXFileReference.h"
#include "PBXObjectIdConvert.h"
#include "VariableCollection.h"

PBXProject::~PBXProject() {}

PBXProject::PBXProject() {}

PBXProject* PBXProject::createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc)
{
  PBXProject* ret = new PBXProject;
  ret->initFromPlist(id, plist, pbxDoc);
  return ret;
}

void PBXProject::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc)
{
  // Call super init
  PBXObject::initFromPlist(id, plist, pbxDoc);

  // Get buildConfigurationList
  getStringForKey(plist, "buildConfigurationList", m_buildConfigurationListId, VALUE_REQUIRED, m_parseER);
  
  // Get mainGroup
  getStringForKey(plist, "mainGroup", m_mainGroupId, VALUE_REQUIRED, m_parseER);
  
  // Get projectDirPath
  getStringForKey(plist, "projectDirPath", m_projectDirPath, VALUE_OPTIONAL, m_parseER);
  
  // Get projectRoot
  getStringForKey(plist, "projectRoot", m_projectRoot, VALUE_OPTIONAL, m_parseER);
  if (!m_projectRoot.empty())
    m_parseER.reportError("Non-empty projectRoot.");
  
  // Get projectReferences
  const Plist::array_type& projRefArray = getContainerForKey<Plist::array_type>(plist, "projectReferences", VALUE_OPTIONAL, m_parseER);
  Plist::array_type::const_iterator rIt = projRefArray.begin();
  Plist::array_type::const_iterator rEnd = projRefArray.end();
  for (; rIt != rEnd; ++rIt) {
    const Plist::dictionary_type& refDict = castContainer<Plist::dictionary_type>(*rIt, VALUE_OPTIONAL, m_parseER);

    // Get ProjectRef and ProductGroup
    StringPair refPair;
    getStringForKey(refDict, "ProjectRef", refPair.first, VALUE_REQUIRED, m_parseER);
    getStringForKey(refDict, "ProductGroup", refPair.second, VALUE_REQUIRED, m_parseER);

    m_projectReferenceIds.push_back(refPair);
  }
  
  // Get targets
  getStringVectorForKey(plist, "targets", m_targetIds, VALUE_REQUIRED, m_parseER);
}

void PBXProject::resolvePointers()
{
  // Get buildConfigurationList ptr
  convertObjectId(m_pbxDoc, m_buildConfigurationListId, m_buildConfigurationListPtr);
  
  // Get mainGroup ptr
  convertObjectId(m_pbxDoc, m_mainGroupId, m_mainGroupPtr);
  
  // Get projectReferences ptrs
  StringPairList::iterator pIt = m_projectReferenceIds.begin();
  StringPairList::iterator pEnd = m_projectReferenceIds.end();
  for (; pIt != pEnd; pIt++) {
    ProjectRefPair refPair;
    convertObjectId(m_pbxDoc, pIt->first, refPair.first);
    convertObjectId(m_pbxDoc, pIt->second, refPair.second);
    m_projectReferencePtrs.push_back(refPair);
  }
  
  // Get targets ptrs
  convertObjectIdList(m_pbxDoc, m_targetIds, m_targetPtrs);
}

String PBXProject::getProjectDir() const
{
  return joinPaths(m_pbxDoc->getDir(), m_projectDirPath);
}

const String& PBXProject::getPath() const
{
  return m_pbxDoc->getPath();
}

String PBXProject::getName() const
{
  return m_pbxDoc->getName();
}

void PBXProject::getTargets(const StringSet& targetNames, PBXTargetList& ret) const
{
  for (auto targetName : targetNames) {
    const PBXTarget* target = getTargetWithName(targetName);
    if (target)
      ret.push_back(target);
  }
}

const PBXTarget* PBXProject::getTargetWithName(const String& targetName) const
{
  for (unsigned i = 0; i < m_targetPtrs.size(); i++) {
    if (m_targetPtrs[i]->getName() == targetName)
      return m_targetPtrs[i];
  }
  
  return NULL;
}

// TODO: use function pointers
const PBXTarget* PBXProject::getTargetWithId(const String& targetId) const
{
  for (unsigned i = 0; i < m_targetPtrs.size(); i++) {
    if (m_targetPtrs[i]->getId() == targetId)
      return m_targetPtrs[i];
  }
  
  SBLog::warning() << "Failed to find target with " << targetId << " id in \"" << m_pbxDoc->getName() << "\" project." << std::endl;
  return NULL;
}

// TODO: use function pointers
const PBXTarget* PBXProject::getTargetWithProductName(const String& productName) const
{
  for (unsigned i = 0; i < m_targetPtrs.size(); i++) {
    String productFile = sb_basename(m_targetPtrs[i]->getProductFileName());
    if (productFile == productName)
      return m_targetPtrs[i];
  }
  
  return NULL;
}

// TODO: use function pointers
const PBXTarget* PBXProject::getTargetWithProductReference(const String& productRef) const
{
  for (unsigned i = 0; i < m_targetPtrs.size(); i++) {
    if (m_targetPtrs[i]->getProductReference() == productRef)
      return m_targetPtrs[i];
  }
  
  SBLog::warning() << "Failed to find target with " << productRef << " product reference in \"" << m_pbxDoc->getName() << "\" project." << std::endl;
  return NULL;
}

const XCConfigurationList* PBXProject::getBuildConfigurationList() const
{
  checkFieldPtr(m_buildConfigurationListPtr, "buildConfigurationList");
  return m_buildConfigurationListPtr;
}

void PBXProject::getBuildSettings(VariableCollection& settings) const
{
  const PBXDocument& pbxDoc = getOwner();
  settings.insert("PROJECT_NAME", pbxDoc.getName());
  settings.insert("PROJECT_DIR", getProjectDir());
  settings.insert("PROJECT_FILE_PATH", pbxDoc.getPath());
}
