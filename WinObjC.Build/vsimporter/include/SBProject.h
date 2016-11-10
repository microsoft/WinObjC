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

#ifndef _SBPROJECT_H_
#define _SBPROJECT_H_

#include "PBXGroup.h"
#include "types.h"

class BuildSettings;
class PBXDocument;
class PBXProject;
class PBXTarget;
class XCBuildConfiguration;
class SBTarget;
class VSSolution;
class VCProject;

typedef std::vector<const XCBuildConfiguration*> BuildConfigurationList;
typedef std::vector<const SBTarget*> SBTargetList;

class SBProject {
public:
  static SBProject* createFromPath(const String& projectPath);

  ~SBProject();
  void printSummary();
  const String& getPath() const;
  String getProjectDir() const;
  String getName() const;
  const StringSet& getSelectedConfigurations() const;
  void getQueuedTargets(SBTargetList& ret) const;
  const BuildSettings& getBuildSettings() const;
  const PBXProject* getPBXProject() const;

  void queueAllTargets(const StringSet* configNames = NULL);
  SBTarget* queueTargetWithId(const String& targetId, const StringSet* configNames = NULL);
  SBTarget* queueTargetWithName(const String& targetName, const StringSet* configNames = NULL);
  SBTarget* queueTarget(const PBXTarget* target, const StringSet* configNames = NULL);  
  SBTarget* queueTargetWithProductName(const String& productName, const StringSet* configNames = NULL);
  SBTarget* queueTargetWithProductReference(const String& productRef, const StringSet* configNames = NULL);
  void constructVCProjects(VSSolution& sln, const StringSet& slnConfigs, std::multimap<SBTarget*, VCProject*>& vcProjects);

private:
  typedef std::vector<const PBXTarget*> PBXTargetList;
  typedef std::map<const PBXTarget*, SBTarget*> TargetMap;
  typedef std::set<const PBXTarget*> TargetSet;

  SBProject(const PBXDocument* pbxDoc, const PBXProject* project);
  void queryBuildConfigurations();
  void selectBuildConfigurations(const StringSet* configNames);
  void getMatchingFiles(fileMatchFunc matchFunc, ConstFileList& ret) const;

  static bool checkTargetCycle(const PBXTarget* target);

  // The project being wrapped
  const PBXDocument* m_pbxDoc;
  const PBXProject* m_project; // owned by PBXDocument
  // All SBTargets belonging to this project
  TargetMap m_existingTargets;
  StringSet m_selectedConfigs;
  BuildSettings* m_buildSettings;

  static PBXTargetList s_cycleTracker;
};

#endif /* _SBPROJECT_H_ */
