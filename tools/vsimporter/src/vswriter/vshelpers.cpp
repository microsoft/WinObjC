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

#include "vshelpers.h"
#include "stringutils.h"
#include "SBLog.h"
#include <pugixml.hpp>

typedef std::string String;
typedef std::map<std::string, std::string> StringMap;

String getVSConfigurationPlatform(const String& configName, const String& platformName)
{
  return configName + "|" + platformName;
}

String getVSConfigurationPlatformCond(const String& configName, const String& platformName)
{
  return String("'$(Configuration)|$(Platform)'=='") +
         getVSConfigurationPlatform(configName, platformName) + "'"; 
}

String formatVSGUID(const String& guid)
{
  return String("{") + strToUpper(guid) + "}";
}

pugi::xml_node appendNodeWithText(pugi::xml_node& parent, const String& nodeName, const String& nodeText, const String& nodeCond)
{
  pugi::xml_node node = parent.append_child(nodeName.c_str());
  node.append_child(pugi::node_pcdata).set_value(nodeText.c_str());
  if (!nodeCond.empty()) {
    node.append_attribute("Condition") = nodeCond.c_str();
  }
  
  return node;
}

void writePropertiesMap(const StringMap& props, pugi::xml_node& parent)
{
  for (auto propKV : props) {
    if (!propKV.first.empty()) {
      appendNodeWithText(parent, propKV.first, propKV.second);
    }
  }
}

void writePropertiesMap(const ConditionalValueListMap& props, pugi::xml_node& parent)
{
  for (auto propKV : props) {
    if (propKV.first.empty())
      continue;

    for (auto cvalue : propKV.second) {
      appendNodeWithText(parent, propKV.first, cvalue.value, cvalue.condition);
    }
  }
}

void removeNode(pugi::xml_node& node)
{
  pugi::xml_node nodeToRemove = node;
  node = node.previous_sibling();
  nodeToRemove.parent().remove_child(nodeToRemove);
}

static pugi::xml_node findSimilarNode(pugi::xml_node searchNode, pugi::xml_node searchRoot, unsigned maxDistance)
{
  std::string searchNodeName = searchNode.name();
  pugi::xml_node match;

  // Examine children of searchRoot that have matching names to searchNode
  unsigned i = 0;
  pugi::xml_node child = searchRoot.first_child();
  for (; child && i < maxDistance && !match; child = child.next_sibling(), i++) {
    // Ignore nodes with non-matching names
    if (searchNodeName != child.name())
      continue;

    // Assume child is a match, until shown otherwise
    match = child;

    // Check that all attributes of searchNode match the child node's attributes
    for (pugi::xml_attribute attr : searchNode.attributes()) {
      std::string searchNodeAttr = attr.value();
      std::string matchAttr = child.attribute(attr.name()).value();
      if (searchNodeAttr != matchAttr) {
        match = pugi::xml_node();
        break;
      }
    }
  }

  return match;
}

void mergeNodes(pugi::xml_node toNode, pugi::xml_node& fromNode)
{
  // Base case = both nodes are text nodes
  pugi::xml_text fromNodeText = fromNode.text();
  pugi::xml_text toNodeText = toNode.text();
  if (fromNodeText && toNodeText) {
    SBLog::info() << "Overwriting template value of \"" << toNode.name() << "\" from \"" << toNodeText.get() << "\" to \"" << fromNodeText.get() << "\"." << std::endl;
    toNodeText.set(fromNodeText.get());
    return;
  }

  // Calculate number of children in toNode
  unsigned maxDistance = std::distance(toNode.begin(), toNode.end());

  // Merge children
  for (pugi::xml_node fromNodeChild = fromNode.first_child(); fromNodeChild; ) {
    // Figure out next sibling immediately, in case of node removal
    pugi::xml_node nextSibling = fromNodeChild.next_sibling();

    // Find appropriate merge point
    pugi::xml_node toNodeChild = findSimilarNode(fromNodeChild, toNode, maxDistance);
    if (toNodeChild) {
      mergeNodes(toNodeChild, fromNodeChild);
    } else {
      toNode.append_copy(fromNodeChild);
    }

    // Proceed to next sibling
    fromNodeChild = nextSibling;
  }

  // Erase fromNode
  removeNode(fromNode);
}