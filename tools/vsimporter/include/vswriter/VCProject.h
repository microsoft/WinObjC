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

#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>
#include "ConditionalValue.h"

namespace pugi {
  class xml_node;
};

class VCProject;
class VCProjectConfiguration;
class VCProjectItem;
class VSTemplateProject;

enum VCProjectSubType {
  VCShared,
  VCNone,
};

typedef std::set<const VCProject*> VCProjectSet;
typedef std::set<std::string> StringSet;
typedef std::vector<std::string> StringVec;
typedef std::map<std::string, std::string> StringMap;

class VCProject {
public:
  virtual ~VCProject();
  VCProject(VSTemplateProject* projTemplate, const std::string& id = "");
  bool isDeployable() const;
  const std::string getName() const;
  const std::string& getPath() const;
  const std::string& getId() const;
  std::string getTypeId() const;
  VCProjectSubType getSubType() const;

  const VCProjectSet& getSharedProjects() const;
  const VCProjectSet& getProjectReferences() const;
  const ConditionalValueListMap& getGlobalProperties() const;
  const ConditionalValueListMap& getUserMacros() const;
  const void getPlatforms(StringSet& ret) const;
  const StringSet& getUrlSchemes() const;

  bool write() const;

  virtual void addGlobalProperty(const std::string& name, const std::string& value, const std::string& condition = "");
  virtual void addUserMacro(const std::string& name, const std::string& value, const std::string& condition = "");
  virtual void addProjectReference(const VCProject* refProj);
  virtual void addSharedProject(const VCProject* sharedProj);
  virtual VCProjectConfiguration* addConfiguration(const std::string& name);
  virtual VCProjectItem* addItem(const std::string& itemName, const std::string& itemPath, const std::string& filterPath = "");
  virtual void addBuildExtension(const std::string& extension);
  virtual void setUrlSchemes(const StringSet& schemes);

protected:
  typedef std::map<std::string, VCProjectConfiguration*> ConfigurationMap;
  typedef std::vector<VCProjectItem*> ItemList;
  typedef void (VCProject::*LabelHandlerFn)(pugi::xml_node& node) const;
  typedef std::map<std::string, LabelHandlerFn> LabelHandlerFnMap;

  bool writeTemplate(const std::string& filePath, const LabelHandlerFnMap& handlers) const;
  virtual bool writeFilters() const;
  virtual bool writeProject() const;

  void writeProjectConfigSummary(pugi::xml_node& node) const;
  void writeGlobalProperties(pugi::xml_node& node) const;
  void writeConfigurationProperties(pugi::xml_node& node) const;
  void writeBuildExtensionProperties(pugi::xml_node& node) const;
  void writeBuildExtensionTargets(pugi::xml_node& node) const;
  void writeSharedProjects(pugi::xml_node& node) const;
  void writeConfigurationPropertySheets(pugi::xml_node& node) const;
  void writeUserMacros(pugi::xml_node& node) const;
  void writeConfigurationItemDefinitions(pugi::xml_node& node) const;
  void writeProjectItems(pugi::xml_node& node) const;
  void writeProjectReferences(pugi::xml_node& node) const;
  void writeFilterItemDescriptions(pugi::xml_node& node) const;
  void writeFilterDescriptions(pugi::xml_node& node) const;

  VSTemplateProject* m_template;
  VCProjectSubType m_subType;
  std::string m_id;
  VCProjectSet m_projectRefs;
  VCProjectSet m_sharedProjects;
  ConditionalValueListMap m_globalProps;
  ConditionalValueListMap m_userMacros;
  StringVec m_buildExtensions;
  ConfigurationMap m_configurations;
  StringSet m_urlSchemes;
  ItemList m_items;
};