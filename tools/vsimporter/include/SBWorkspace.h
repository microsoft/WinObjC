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
class XCScheme;
class SBProject;
class SBTarget;

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
  void generateFiles();
  void queueSchemes(const StringSet& schemeNames, const StringSet& configNames);
  void queueAllTargets(const StringSet& configNames);
  void queueTargets(const StringSet& targetNames, const StringSet& configNames);
  /********************/
  
  SBTarget* queueTargetWithProductName(const String& productName);
  SBProject* openProject(const String& projectPath);

private:
  typedef std::vector<SBTarget*> SBTargetVec;
  typedef std::map<String, SBProject*> ProjectMap;
  typedef std::vector<const XCScheme*> SchemeVec;

  SBWorkspace();
  
  void findSchemes(const String& containerAbsPath);
  
  SBProject* findOpenProject(const String& absProjPath) const;
  const XCScheme* getScheme(const String& schemeName) const;
  void getSchemes(const StringSet& schemeNames, SchemeVec& ret) const;
  void querySchemes(SchemeVec& ret) const;
  void detectProjectCollisions() const;

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
