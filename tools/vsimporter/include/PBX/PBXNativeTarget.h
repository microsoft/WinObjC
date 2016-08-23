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

#ifndef _PBXNATIVETARGET_H_
#define _PBXNATIVETARGET_H_

#include "PBXTarget.h"

class PBXFileReference;
class PBXBuildRule;
class PBXDocument;

typedef std::vector<PBXBuildRule*> BuildRuleList;

class PBXNativeTarget : public PBXTarget {
public:
  virtual ~PBXNativeTarget();
  virtual void resolvePointers();
  virtual String getProductFileName() const;
  virtual String getProductFileType() const;
  virtual String getProductReference() const { return m_productReferenceId; }
  virtual void getBuildSettings(VariableCollection& settings) const;
  virtual String getTargetType() const;
  const String& getProductType() const { return m_productType; }
  const PBXFileReference* getProductFile() const { return m_productReferencePtr; }
  const BuildRuleList& getBuildRules() const { return m_buildRulePtrs; }
  
  static PBXNativeTarget* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);
  
private:
  PBXNativeTarget();
  virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);
  
/* Start of serialized values */
  String m_productReferenceId;
  String m_productType;
  StringVec m_buildRuleIds;
/* End of serialized values */

  PBXFileReference* m_productReferencePtr;
  BuildRuleList m_buildRulePtrs;
};

#endif /* _PBXNATIVETARGET_H_ */
