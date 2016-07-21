//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#include "VCProject.h"
#include "VCProjectConfiguration.h"
#include "VCProjectItem.h"
#include "VSTemplateProject.h"
#include "vshelpers.h"
#include "sole/sole.hpp"
#include "pugixml.hpp"
#include "utils.h"
#include "sbassert.h"
#include "SBLog.h"
#include "..\WBITelemetry\WBITelemetry.h"

#include <fstream>

typedef std::set<std::string> StringSet;

VCProject::VCProject(VSTemplateProject* projTemplate, const std::string& id)
: m_template(projTemplate)
{
  sbAssert(projTemplate);
  sbAssert(isAbsolutePath(projTemplate->getPath()));

  // Determine subtype (shared or not)
   m_subType = projTemplate->isShared() ? VCShared : VCNone;

  // TODO: validate passed in id
  if (!id.empty())
    m_id = id;
  else
    m_id = sole::uuid4().str();

  string guid = formatVSGUID(m_id);
  if (m_subType == VCShared)
  {
      TELEMETRY_EVENT_GUID(L"VSImporterSharedProjectGuid", guid);
  }
  else
  {
      TELEMETRY_EVENT_GUID(L"VSImporterProjectGuid", guid);
  }
  addGlobalProperty("ProjectGuid", guid);
}

VCProject::~VCProject() {}

const std::string& VCProject::getId() const
{
  return m_id;
}

const std::string VCProject::getName() const
{
  return m_template->getName();
}

const std::string& VCProject::getPath() const
{
  return m_template->getPath();
}

bool VCProject::isDeployable() const
{
  return m_template->isDeployable();
}

std::string VCProject::getTypeId() const
{
  return "8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942";
}

VCProjectSubType VCProject::getSubType() const
{
  return m_subType;
}

const VCProjectSet& VCProject::getSharedProjects() const
{
  return m_sharedProjects;
}

const VCProjectSet& VCProject::getProjectReferences() const
{
  return m_projectRefs;
}

const ConditionalValueListMap& VCProject::getGlobalProperties() const
{
  return m_globalProps;
}

const ConditionalValueListMap& VCProject::getUserMacros() const
{
  return m_userMacros;
}

const StringSet& VCProject::getUrlSchemes() const
{
    return m_urlSchemes;
}

void VCProject::addGlobalProperty(const std::string& name, const std::string& value, const std::string& condition)
{
  if (!name.empty())
    m_globalProps[name].push_back(ConditionalValue(value, condition));
}

void VCProject::addUserMacro(const std::string& name, const std::string& value, const std::string& condition)
{
  if (!name.empty())
    m_userMacros[name].push_back(ConditionalValue(value, condition));
}

const void VCProject::getPlatforms(StringSet& ret) const
{
  for (auto configKV : m_configurations) {
    const PlatformMap& platforms = configKV.second->getPlatforms();
    for (auto platformKV : platforms) {
      ret.insert(platformKV.first);
    }
  }
}

void VCProject::addSharedProject(const VCProject* ref)
{
  if (ref && ref->getSubType() == VCShared)
    m_sharedProjects.insert(ref);
}

void VCProject::addProjectReference(const VCProject* ref)
{
  if (ref && ref->getSubType() != VCShared)
    m_projectRefs.insert(ref);
}

VCProjectConfiguration* VCProject::addConfiguration(const std::string& name)
{
  VCProjectConfiguration* ret = NULL;
  if (!name.empty()) {
    ConfigurationMap::iterator cIt = m_configurations.find(name);
    if (cIt != m_configurations.end()) {
      ret = cIt->second;
    } else {
      ret = new VCProjectConfiguration(name);
      m_configurations[name] = ret;
    }

    for (auto platformName : m_template->getPlatforms()) {
      ret->addPlatform(platformName);
    }
  }

  
  return ret;
}

VCProjectItem* VCProject::addItem(const std::string& itemName, const std::string& includePath, const std::string& filterPath)
{
  VCProjectItem* ret = NULL;
  if (!itemName.empty() && !includePath.empty()) {
    ret = new VCProjectItem(itemName, includePath, filterPath);
    m_items.push_back(ret);
  }

  return ret;
}

void VCProject::addBuildExtension(const std::string& extension)
{
  m_buildExtensions.push_back(extension);
}

void VCProject::setUrlSchemes(const StringSet& schemes)
{
    if (!m_urlSchemes.empty() && (schemes != m_urlSchemes)) {
        SBLog::warning() << "Inconsistent URL schemes across configurations; using first set only" << std::endl;
        return;
    }

    m_urlSchemes = schemes;
}

bool VCProject::write() const
{
  // Write the template
  m_template->write(m_urlSchemes);

  return writeProject() && writeFilters();
}
  
void VCProject::writeProjectConfigSummary(pugi::xml_node& node) const
{
  for (auto configKV : m_configurations) {
    configKV.second->writeSummary(node);
  }
}

void VCProject::writeGlobalProperties(pugi::xml_node& node) const
{
  pugi::xml_node tempNode = node.parent().append_child("Temp");
  writePropertiesMap(m_globalProps, tempNode);
  mergeNodes(node, tempNode);
}

void VCProject::writeConfigurationProperties(pugi::xml_node& node) const
{
  for (auto configKV : m_configurations) {
    configKV.second->writeProperties(node);
  }

  // The node is a bookmark. Remove it.
  removeNode(node);
}

void VCProject::writeBuildExtensionProperties(pugi::xml_node& node) const
{
  pugi::xml_node tempNode = node.parent().append_child("Temp");
  for (auto ext : m_buildExtensions) {
    if (sb_fextension(ext) == "props") {
      pugi::xml_node propsFile = tempNode.append_child("Import");
      propsFile.append_attribute("Project") = ext.c_str();
    }
  }
  mergeNodes(node, tempNode);
}

void VCProject::writeBuildExtensionTargets(pugi::xml_node& node) const
{
  pugi::xml_node tempNode = node.parent().append_child("Temp");
  for (auto ext : m_buildExtensions) {
    if (sb_fextension(ext) == "targets") {
      pugi::xml_node propsFile = tempNode.append_child("Import");
      propsFile.append_attribute("Project") = ext.c_str();
    }
  }
  mergeNodes(node, tempNode);
}

void VCProject::writeSharedProjects(pugi::xml_node& node) const
{
  std::string projectPath = getPath();
  std::string projectDir = sb_dirname(projectPath);

  pugi::xml_node tempNode = node.parent().append_child("Temp");
  for (auto sproj : m_sharedProjects) {
    std::string sprojRelativePath = getRelativePath(projectDir, sproj->getPath());
    pugi::xml_node importProj = tempNode.append_child("Import");
    importProj.append_attribute("Project") = sprojRelativePath.c_str();
    importProj.append_attribute("Label") = "Shared";
  }
  mergeNodes(node, tempNode);
}

void VCProject::writeConfigurationPropertySheets(pugi::xml_node& node) const
{
  for (auto configKV : m_configurations) {
    configKV.second->writePropertySheets(node);
  }

  // The node is a bookmark. Remove it.
  removeNode(node);
}

void VCProject::writeUserMacros(pugi::xml_node& node) const
{
  pugi::xml_node tempNode = node.parent().append_child("Temp");
  writePropertiesMap(m_userMacros, tempNode);
  mergeNodes(node, tempNode);
}

void VCProject::writeConfigurationItemDefinitions(pugi::xml_node& node) const
{
  for (auto configKV : m_configurations) {
    configKV.second->writeItemDefinitions(node);
  }

  // The node is a bookmark. Remove it.
  removeNode(node);
}

void VCProject::writeProjectItems(pugi::xml_node& node) const
{
  pugi::xml_node tempNode = node.parent().append_child("Temp");
  for (auto item : m_items) {
    item->writeDescription(tempNode);
  }
  mergeNodes(node, tempNode);
}

void VCProject::writeProjectReferences(pugi::xml_node& node) const
{
  std::string projectPath = getPath();
  std::string projectDir = sb_dirname(projectPath);

  for (auto dep : m_projectRefs) {
    std::string depGUID = formatVSGUID(dep->getId());
    std::string depRelativePath = getRelativePath(projectDir, dep->getPath());
    pugi::xml_node projRef = node.append_child("ProjectReference");
    projRef.append_attribute("Include") = depRelativePath.c_str();
    appendNodeWithText(projRef, "Project", depGUID);
  }
}

#define callMemberFunction(objectPtr, ptrToMember) ((objectPtr)->*(ptrToMember))
bool VCProject::writeTemplate(const std::string& filePath, const LabelHandlerFnMap& handlers) const
{
  // Open the template
  pugi::xml_document projDoc;
  pugi::xml_parse_result result = projDoc.load_file(filePath.c_str());
  sbValidate(result, "Failed to open template file: " + filePath);
  pugi::xml_node projRoot = projDoc.first_child();

  for (pugi::xml_node child = projRoot.first_child(); child; child = child.next_sibling()) {
    // Check each child for a VSImporterLabel attribute
    pugi::xml_attribute sblabelAttr = child.attribute("VSImporterLabel");
    std::string sblabelValue = sblabelAttr.value();

    // Get rid of the attribute, if one was found
    if (sblabelAttr) {
      child.remove_attribute(sblabelAttr);
    } else {
      continue;
    }

    // Handle the label
    auto nodeHandlerIt = handlers.find(sblabelValue);
    if (nodeHandlerIt != handlers.end()) {
      callMemberFunction(this, nodeHandlerIt->second)(child);
    } else {
      SBLog::warning() << "Unrecognized VSImporterLabel attribute \"" << sblabelValue << "\" in " << filePath << std::endl;
    }
  }

  // Output tree
  return projDoc.save_file(filePath.c_str(), "  ");
}

bool VCProject::writeProject() const
{
  LabelHandlerFnMap nodeHandlers;
  nodeHandlers["ProjectConfigSummary"] = &VCProject::writeProjectConfigSummary;
  nodeHandlers["GlobalProperties"] = &VCProject::writeGlobalProperties;
  nodeHandlers["ConfigurationProperties"] = &VCProject::writeConfigurationProperties;
  nodeHandlers["BuildExtensionProperties"] = &VCProject::writeBuildExtensionProperties;
  nodeHandlers["BuildExtensionTargets"] = &VCProject::writeBuildExtensionTargets;
  nodeHandlers["SharedProjects"] = &VCProject::writeSharedProjects;
  nodeHandlers["ConfigurationPropertySheets"] = &VCProject::writeConfigurationPropertySheets;
  nodeHandlers["UserMacros"] = &VCProject::writeUserMacros;
  nodeHandlers["ConfigurationItemDefinitions"] = &VCProject::writeConfigurationItemDefinitions;
  nodeHandlers["ProjectItems"] = &VCProject::writeProjectItems;
  nodeHandlers["ProjectReferences"] = &VCProject::writeProjectReferences;

  return writeTemplate(getPath(), nodeHandlers);
}

static void recordFilterPath(const std::string& filterPath, StringSet& filterSet)
{
  if (!filterPath.empty() && filterPath != "." && filterSet.insert(filterPath).second)
    recordFilterPath(sb_dirname(filterPath), filterSet);
}

void VCProject::writeFilterItemDescriptions(pugi::xml_node& node) const
{
  pugi::xml_node tempNode = node.parent().append_child("Temp");
  for (auto item : m_items) {
    std::string itemName = item->getItemName();
    std::string includePath = item->getIncludePath();
    std::string filterPath = item->getFilterPath();

    pugi::xml_node fItem = tempNode.append_child(itemName.c_str());
    fItem.append_attribute("Include") = includePath.c_str();
    if (!filterPath.empty() && filterPath != ".") {
      appendNodeWithText(fItem, "Filter", winPath(filterPath));
    }
  }
  mergeNodes(node, tempNode);
}

void VCProject::writeFilterDescriptions(pugi::xml_node& node) const
{
  StringSet filters;
  for (auto item : m_items) {
    recordFilterPath(item->getFilterPath(), filters);
  }

  pugi::xml_node tempNode = node.parent().append_child("Temp");
  for (auto filter : filters) {
    // Generate a unique id
    std::string id = sole::uuid4().str();

    // Fix up the filter path to be Windows-style
    std::string winFilterPath = winPath(filter);

    // Create a filter description node
    pugi::xml_node filterDesc = tempNode.append_child("Filter");
    filterDesc.append_attribute("Include") = winFilterPath.c_str();
    appendNodeWithText(filterDesc, "UniqueIdentifier", formatVSGUID(id));
  }
  mergeNodes(node, tempNode);
}

bool VCProject::writeFilters() const
{
  std::string filtersFilePath = getPath() + ".filters";
  LabelHandlerFnMap nodeHandlers;
  nodeHandlers["FilterItemDescriptions"] = &VCProject::writeFilterItemDescriptions;
  nodeHandlers["FilterDescriptions"] = &VCProject::writeFilterDescriptions;

  return writeTemplate(filtersFilePath, nodeHandlers);
}