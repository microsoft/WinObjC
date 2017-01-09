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
#include "XCConfigurationList.h"
#include "XCBuildConfiguration.h"
#include "PBXObjectIdConvert.h"

XCConfigurationList::~XCConfigurationList() {}

XCConfigurationList::XCConfigurationList() {}

XCConfigurationList* XCConfigurationList::createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc)
{
  XCConfigurationList* ret = new XCConfigurationList;
  ret->initFromPlist(id, plist, pbxDoc);
  return ret;
}

void XCConfigurationList::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc)
{
  // Call super init
  PBXObject::initFromPlist(id, plist, pbxDoc);
  
  // Get buildConfigurations
  getStringVectorForKey(plist, "buildConfigurations", m_buildConfigurationIds, VALUE_REQUIRED, m_parseER);
  
  // Get defaultConfigurationName
  getStringForKey(plist, "defaultConfigurationName", m_defaultConfigurationName, VALUE_REQUIRED, m_parseER);
}

void XCConfigurationList::resolvePointers()
{
  // Resolve buildConfigurations ptrs
  convertObjectIdList(m_pbxDoc, m_buildConfigurationIds, m_buildConfigurationPtrs);
}

const XCBuildConfiguration* XCConfigurationList::getConfiguration(const String& configName) const
{
  for (unsigned i = 0; i < m_buildConfigurationPtrs.size(); i++) {
    if (m_buildConfigurationPtrs[i]->getName() == configName)
      return m_buildConfigurationPtrs[i];
  }
  
  SBLog::warning() << "Failed to find \"" << configName << "\" build configuration in \"" << m_pbxDoc->getName() << "\" project." << std::endl;
  return NULL;
}

void XCConfigurationList::getValidConfigurations(const StringSet& configNames, StringSet& ret) const
{
  for (auto configName : configNames) {
    const XCBuildConfiguration* config = getConfiguration(configName);
    if (config)
      ret.insert(configName);
  }
}