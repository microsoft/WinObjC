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

#ifndef _XCCONFIGURATIONLIST_H_
#define _XCCONFIGURATIONLIST_H_

#include <string>
#include <list>

#include "types.h"
#include "PBXObject.h"

class XCBuildConfiguration;

typedef std::vector<const XCBuildConfiguration*> BuildConfigurationList;

class XCConfigurationList : public PBXObject {
public:
  virtual ~XCConfigurationList();
  virtual void resolvePointers();
  
  const BuildConfigurationList& getConfigurations() const { return m_buildConfigurationPtrs; }
  void getValidConfigurations(const StringSet& configNames, StringSet& ret) const;
  const XCBuildConfiguration* getConfiguration(const String& configName) const;
  const String& getDefaultConfigurationName() const { return m_defaultConfigurationName; }
  
  static XCConfigurationList* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);
  
private:
  XCConfigurationList();
  virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);
  
/* Start of serialized values */
  StringVec m_buildConfigurationIds;
  String m_defaultConfigurationName;
/* End of serialized values */

  BuildConfigurationList m_buildConfigurationPtrs;
};

#endif /* _XCCONFIGURATIONLIST_H_ */
