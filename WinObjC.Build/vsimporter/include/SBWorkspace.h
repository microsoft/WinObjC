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

#ifndef _SBWORKSPACE_H_
#define _SBWORKSPACE_H_

#include "types.h"

class XCWorkspace;
class PBXProject;
class PBXTarget;
class XCScheme;
class SBProject;
class SBTarget;
class VCProject;

class SBWorkspace {
public:
  /* Factory functions */
  static SBWorkspace* get();
  static SBWorkspace* createFromProject(const String& project);
  static SBWorkspace* createFromWorkspace(const String& workspace);
  /*********************/
  
  String getName() const;
  String getPath() const;
  const StringSet& getConfigurations() const;

  /* Called from main */
  void printSummary() const;
  void generateFiles(bool genProjectionsProj);
  void queueSchemes(const StringSet& schemeNames, const StringSet& configNames);
  void queueTargets(const StringSet& targetNames, const StringSet& configNames);
  /********************/
  
  SBTarget* queueTargetWithProductName(const String& productName);
  SBTarget* queueTargetWithName(const String& targetName, const StringSet& configNames);
  SBProject* openProject(const String& projectPath);

private:
  typedef std::vector<SBTarget*> SBTargetVec;
  typedef std::map<String, SBProject*> ProjectMap;
  typedef std::vector<SBProject*> SBProjectVec;
  typedef std::vector<const XCScheme*> SchemeVec;
  typedef std::pair<const PBXTarget*, SBProject*> TargetProjectPair;
  typedef std::vector<TargetProjectPair> PotentialTargetsVec;

  SBWorkspace();
  
  void findSchemes(const String& containerAbsPath);
  void printSchemes() const;
  
  SBProject* findOpenProject(const String& absProjPath) const;
  const XCScheme* getScheme(const String& schemeName) const;
  void getSchemes(const StringSet& schemeNames, SchemeVec& ret) const;
  void selectTargets(PotentialTargetsVec& ret);
  void detectProjectCollisions() const;
  VCProject* generateGlueProject() const;
  void getAllTargets(PotentialTargetsVec& targets) const;
  TargetProjectPair findTargetWithName(const String& targetName) const;

  // Relevant if Workspace was constructed from a workspace file
  XCWorkspace* m_workspace;
  // Relevant if Workspace was constructed from a project file
  SBProject* m_mainProject;
  // All open Projects
  ProjectMap m_openProjects;
  // Schemes for all open projects
  SchemeVec m_schemes;
  // All user-specified configurations
  StringSet m_configNames;
  
  static SBWorkspace* s_workspace;
};

#endif /* _SBWORKSPACE_H_ */
