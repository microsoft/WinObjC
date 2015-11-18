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

#ifndef _SBTARGET_H_
#define _SBTARGET_H_

#include "types.h"
#include "PBXBuildPhase.h"
#include "SBBuildPhase.h"

class BuildSettings;
class PBXTarget;
class SBProject;
class VSSolution;
class VSTemplateProject;

enum TargetProductType {
  TargetProductUnknown = 0,
  TargetApplication = 1,
  TargetStaticLib = 2,
  TargetBundle = 3
};

typedef std::map<String, BuildSettings*> BuildSettingsMap;

class SBTarget {
public:
  static SBTarget* create(const PBXTarget* target, const StringSet& configNames, SBProject& parentProject);
  virtual ~SBTarget() = 0;
  virtual TargetProductType getProductType() const { return TargetProductUnknown; }

  const String& getName() const;
  const String& getId() const;
  String getProductFileName() const;
  const SBProject& getProject() const;
  const BuildSettingsMap& getBuildSettings() const;
  String makeAbsolutePath(const String& path) const;
  String makeRelativePath(const String& path, const String& absRoot = "") const;
  SBTarget* getPossibleTarget(const PBXBuildFile* buildFile);
  
  virtual VCProject* constructVCProject(VSTemplateProject* projTemplate) = 0;
  void resolveVCProjectDependecies(VCProject* proj, std::multimap<SBTarget*, VCProject*>& vcProjects);

protected:
  typedef std::vector<SBTarget*> SBDependencyList;

  SBTarget(const PBXTarget* target, const StringSet& configNames, SBProject& parentProject);
  bool init();
  void validateSDK();

  const PBXTarget* m_target;
  SBProject& m_parentProject;
  BuildSettingsMap m_buildSettings;
  SBDependencyList m_dependencies;
  SBBuildPhaseList m_buildPhases;

private:
  void addDependency(SBTarget* depTarget);
  void processDependencies();
  bool writeVCProject();
};

#endif /* _SBTARGET_H_ */
