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

#include "VCProjectConfiguration.h"
#include "VCProjectConfigurationPlatform.h"
#include "pugixml.hpp"
#include "vshelpers.h"
#include <assert.h>

VCProjectConfiguration::VCProjectConfiguration(const std::string& name)
: m_name(name) {}

VCProjectConfiguration::~VCProjectConfiguration()
{
  for (auto platform : m_platforms)
    delete platform.second;
}

const std::string& VCProjectConfiguration::getName() const
{
  return m_name;
}

VCProjectConfigurationPlatform* VCProjectConfiguration::addPlatform(const std::string& platformName)
{
  if (platformName.empty())
    return NULL;

  auto pIt = m_platforms.find(platformName);
  if (pIt != m_platforms.end()) {
    return pIt->second;
  } else {
    VCProjectConfigurationPlatform* platform = new VCProjectConfigurationPlatform(platformName, *this);
    m_platforms[platformName] = platform;
    return platform;
  }
}

void VCProjectConfiguration::removePlatform(const std::string& platform)
{
  auto pIt = m_platforms.find(platform);
  if (pIt != m_platforms.end()) {
    delete pIt->second;
    m_platforms.erase(pIt);
  }
}

bool VCProjectConfiguration::setProperty(const std::string& pName, const std::string& pValue)
{
  if (pName.empty())
    return false;

  for (auto platform : m_platforms) {
    platform.second->setProperty(pName, pValue);
  }
  return true;
}

const PlatformMap& VCProjectConfiguration::getPlatforms() const
{
  return m_platforms;
}

bool VCProjectConfiguration::setItemDefinition(const std::string& item, const std::string& pName, const std::string& pValue)
{
  if (item.empty() || pName.empty())
    return false;

  for (auto platform : m_platforms) {
    platform.second->setItemDefinition(item, pName, pValue);
  }
  return true;
}

void VCProjectConfiguration::writeSummary(pugi::xml_node& parent) const
{
  for (auto platform : m_platforms) {
    std::string configPlatform = getVSConfigurationPlatform(m_name, platform.first);
    pugi::xml_node configDesc = parent.append_child("ProjectConfiguration");
    configDesc.append_attribute("Include") = configPlatform.c_str();
    appendNodeWithText(configDesc, "Configuration", m_name);
    appendNodeWithText(configDesc, "Platform", platform.first);
  }
}

static void pruneDescendants(pugi::xml_node& node, const std::string& configName)
{
  // Remove any child nodes that don't match the configuration name
  for (pugi::xml_node child = node.first_child(); child; )
  {
    // Figure out next sibling immediately, in case we remove things from the tree
    pugi::xml_node nextSibling = child.next_sibling();

    // Try to get the VSImporterConfigname attribute
    pugi::xml_attribute sbConfigNameAttr = child.attribute("VSImporterConfigName");

    // Figure out if property node should be kept
    bool keepNode = !sbConfigNameAttr || sbConfigNameAttr.value() == configName;

    // Remove things, as necessary
    if (keepNode) {
      if (sbConfigNameAttr) {
        child.remove_attribute(sbConfigNameAttr);
      }
      pruneDescendants(child, configName);
    } else {
      node.remove_child(child);
    }

    // Go on to next child
    child = nextSibling;
  }
}

void VCProjectConfiguration::writeProperties(pugi::xml_node& proto) const
{
  // Insert nodes after the bookmark
  pugi::xml_node parent = proto.parent();
  pugi::xml_node prevSibling = proto;

  for (auto platform : m_platforms) {
    std::string configCond = getVSConfigurationPlatformCond(m_name, platform.first);
    pugi::xml_node configPropsGroup = parent.insert_copy_before(proto, prevSibling);
    configPropsGroup.append_attribute("Condition") = configCond.c_str();

    // Remove nodes not applicable to current configuration
    pruneDescendants(configPropsGroup, m_name);

    pugi::xml_node tempNode = proto.parent().append_child("Temp");
    writePropertiesMap(platform.second->getProperties(), tempNode);
    mergeNodes(configPropsGroup, tempNode);

    prevSibling = configPropsGroup;
  }
}

void VCProjectConfiguration::writePropertySheets(pugi::xml_node& proto) const
{
  // Insert nodes after the bookmark
  pugi::xml_node parent = proto.parent();
  pugi::xml_node prevSibling = proto;

  for (auto platform : m_platforms) {
    std::string configCond = getVSConfigurationPlatformCond(m_name, platform.first);
    pugi::xml_node importGroup = parent.insert_copy_before(proto, prevSibling);
    importGroup.append_attribute("Condition") = configCond.c_str();

    prevSibling = importGroup;
  }
}

void VCProjectConfiguration::writeItemDefinitions(pugi::xml_node& proto) const
{
  // Insert nodes after the bookmark
  pugi::xml_node parent = proto.parent();
  pugi::xml_node prevSibling = proto;

  for (auto platform : m_platforms) {
    std::string configCond = getVSConfigurationPlatformCond(m_name, platform.first);
    pugi::xml_node itemDefsGroup = parent.insert_copy_before(proto, prevSibling);
    itemDefsGroup.append_attribute("Condition") = configCond.c_str();

    // Remove nodes not applicable to current configuration
    pruneDescendants(itemDefsGroup, m_name);

    pugi::xml_node tempNode = proto.parent().append_child("Temp");
    const ItemDefinitionsMap& itemDefs = platform.second->getItemDefinitions();
    for (auto item : itemDefs) {
      pugi::xml_node itemGroup = tempNode.append_child(item.first.c_str());
      writePropertiesMap(item.second, itemGroup);
    }
    mergeNodes(itemDefsGroup, tempNode);

    prevSibling = itemDefsGroup;
  }
}