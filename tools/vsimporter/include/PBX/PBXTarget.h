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

#ifndef _PBXTARGET_H_
#define _PBXTARGET_H_

#include "PBXObject.h"

class PBXBuildPhase;
class PBXTargetDependency;
class XCConfigurationList;
class PBXDocument;
class VariableCollection;

typedef std::vector<const PBXBuildPhase*> BuildPhaseList;
typedef std::vector<const PBXTargetDependency*> DependencyList;

class PBXTarget : public PBXObject {
public:
  virtual ~PBXTarget() = 0;
  virtual void resolvePointers();
  virtual String getProductFileName() const { return ""; }
  virtual String getProductFileType() const { return ""; }
  virtual String getProductReference() const { return ""; }
  virtual String getTargetType() const = 0;
  virtual void getBuildSettings(VariableCollection& settings) const;
  
  const XCConfigurationList* getBuildConfigurationList() const { return m_buildConfigurationListPtr; }
  const String& getName() const { return m_name; }
  String getNameWithType() const { return getName() + " [" + getTargetType() + "]"; }
  const String& getProductName() const { return m_productName; }
  const DependencyList& getDependencies() const { return m_dependencyPtrs; }
  const BuildPhaseList& getBuildPhases() const { return m_buildPhasePtrs; }

protected:
  PBXTarget();
  virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

/* Start of serialized values */
  String m_buildConfigurationListId;
  StringVec m_buildPhaseIds;
  StringVec m_dependencyIds;
  String m_name;
  String m_productName;
/* End of serialized values */

  XCConfigurationList* m_buildConfigurationListPtr;
  BuildPhaseList m_buildPhasePtrs;
  DependencyList m_dependencyPtrs;
};

#endif /* _PBXTARGET_H_ */
