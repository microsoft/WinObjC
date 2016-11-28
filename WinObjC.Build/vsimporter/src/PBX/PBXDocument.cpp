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

#include "PBXDocument.h"
#include "PBXProject.h"
#include "PBXBuildFile.h"
#include "PBXFileReference.h"
#include "PBXGroup.h"
#include "PBXVariantGroup.h"
#include "XCVersionGroup.h"
#include "PBXReferenceProxy.h"
#include "PBXContainerItemProxy.h"
#include "PBXTargetDependency.h"
#include "XCConfigurationList.h"
#include "PBXLegacyTarget.h"
#include "PBXAggregateTarget.h"
#include "PBXNativeTarget.h"
#include "PBXFrameworksBuildPhase.h"
#include "PBXSourcesBuildPhase.h"
#include "PBXResourcesBuildPhase.h"
#include "PBXHeadersBuildPhase.h"
#include "PBXCopyFilesBuildPhase.h"
#include "PBXShellScriptBuildPhase.h"
#include "XCBuildConfiguration.h"
#include "PBXBuildRule.h"
#include "..\WBITelemetry\WBITelemetry.h"

PBXDocument::~PBXDocument()
{
  PBXObjectMap::iterator objIt = m_objects.begin();
  PBXObjectMap::iterator objEnd = m_objects.end();
  for (; objIt != objEnd; objIt++) {
    delete objIt->second;
  }
}

PBXDocument::PBXDocument(const String& projectPath)
  : m_rootObjectPtr(NULL),
    m_path(platformPath(sanitizePath(projectPath))),
    m_parseER(SB_DEBUG)
{
  // Set context for any parse errors that we might encounter
  m_parseER.setContext("Error parsing \"" + getName() + "\" project description. ");
}

String PBXDocument::getDir() const { return sb_dirname(m_path); }

String PBXDocument::getName() const { return sb_fname(sb_basename(m_path)); }

PBXDocument* PBXDocument::createFromPlist(const Plist::dictionary_type& plist, const String& projectPath)
{
  PBXDocument* ret = new PBXDocument(projectPath);
  if (!ret->initFromPlist(plist)) {
    delete ret;
    ret = NULL;
  }

  return ret;
}

bool PBXDocument::initFromPlist(const Plist::dictionary_type& plist)
{
  // Get archiveVersion
  m_archiveVersion = getIntForKey(plist, "archiveVersion", VALUE_REQUIRED, m_parseER);
  
  // Get objectVersion
  m_objectVersion = getIntForKey(plist, "objectVersion", VALUE_REQUIRED, m_parseER);
  TELEMETRY_EVENT_DATA(L"VSImporterObjectVersion", to_string(m_objectVersion).c_str());

  // Get objects
  const Plist::dictionary_type& objectsDict = getContainerForKey<Plist::dictionary_type>(plist, "objects", VALUE_REQUIRED, m_parseER);
  constructObjects(objectsDict);
  
  // Get rootObject
  getStringForKey(plist, "rootObject", m_rootObjectId, VALUE_REQUIRED, m_parseER);

  // Resolve pointers between objects
  resolvePointers();

  // Basic validation
  if (!m_rootObjectPtr) {
    m_parseER.reportError("Root project object is NULL.");
    return false;
  }

  // Track hash of rootObject
  hash<String> rootObject_hash;
  string hash_str = to_string(rootObject_hash(m_rootObjectId));
  TELEMETRY_EVENT_DATA(L"VSImporterRootObjectIdHash", hash_str.c_str());
  return true;
}

void PBXDocument::constructObjects(const Plist::dictionary_type& objectsDict)
{
  // Iterate over arrray and deserialize objects
  Plist::dictionary_type::const_iterator objsIt = objectsDict.begin();
  Plist::dictionary_type::const_iterator objsEnd  = objectsDict.end();
  for (; objsIt != objsEnd; ++objsIt) {
    // Get object id
    String objectId = objsIt->first;

    // Get object contents
    const Plist::dictionary_type& objectDict = castContainer<Plist::dictionary_type>(objsIt->second, VALUE_REQUIRED, m_parseER);
    
    // Get object type
    String isa;
    getStringForKey(objectDict, "isa", isa, VALUE_REQUIRED, m_parseER);
    
    PBXObject* object = NULL;
    
    if (isa == "PBXBuildFile") {
      object = PBXBuildFile::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXFileReference") {
      object = PBXFileReference::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXReferenceProxy") {
      object = PBXReferenceProxy::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXGroup") {
      object = PBXGroup::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXVariantGroup") {
      object = PBXVariantGroup::createFromPlist(objectId, objectDict, this);
    } else if (isa == "XCVersionGroup") {
      object = XCVersionGroup::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXContainerItemProxy") {
      object = PBXContainerItemProxy::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXTargetDependency") {
      object = PBXTargetDependency::createFromPlist(objectId, objectDict, this);
    } else if (isa == "XCConfigurationList") {
      object = XCConfigurationList::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXLegacyTarget") {
      object = PBXLegacyTarget::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXAggregateTarget") {
      object = PBXAggregateTarget::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXNativeTarget") {
      object = PBXNativeTarget::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXFrameworksBuildPhase") {
      object = PBXFrameworksBuildPhase::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXSourcesBuildPhase") {
      object = PBXSourcesBuildPhase::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXResourcesBuildPhase") {
      object = PBXResourcesBuildPhase::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXHeadersBuildPhase") {
      object = PBXHeadersBuildPhase::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXCopyFilesBuildPhase") {
      object = PBXCopyFilesBuildPhase::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXShellScriptBuildPhase") {
      object = PBXShellScriptBuildPhase::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXProject") {
      object = PBXProject::createFromPlist(objectId, objectDict, this);
    } else if (isa == "XCBuildConfiguration") {
      object = XCBuildConfiguration::createFromPlist(objectId, objectDict, this);
    } else if (isa == "PBXBuildRule") {
      object = PBXBuildRule::createFromPlist(objectId, objectDict, this);
    } else {
      m_parseER.reportError("Object type is unsupported: " + isa);
    }

    // Add object to the map
    if (object)
      m_objects[objectId] = object;
  }
}

void PBXDocument::resolvePointers()
{
  // Resolve pointer to the PBXProject
  m_rootObjectPtr = dynamic_cast<PBXProject*>(findObjectWithId(m_rootObjectId));
  
  // Resolve pointers for all objects
  PBXObjectMap::iterator objIt = m_objects.begin();
  PBXObjectMap::iterator objEnd = m_objects.end();
  for (; objIt != objEnd; objIt++) {
    if (objIt->second)
      objIt->second->resolvePointers();
  }
}

PBXObject* PBXDocument::findObjectWithId(const String& id) const
{
  if (id.empty())
    return NULL;
  
  PBXObjectMap::const_iterator it = m_objects.find(id);
  if (it != m_objects.end()) {
    return it->second;
  } else {
    m_parseER.reportError("Failed to find object with id:" + id);
    return NULL;
  }
}
