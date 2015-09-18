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

#include <pugixml.hpp>
#include "sbassert.h"
#include "utils.h"
#include "SBLog.h"
#include "XMLFuncs.h"
#include "PBXProject.h"
#include "XCScheme.h"

XCScheme::XCScheme(const String& absSchemePath, const PBXProject* owner)
: m_absPath(absSchemePath), m_parentProject(owner)
{
  // Record the scheme name
  m_name = sb_fname(sb_basename(m_absPath));

#if defined(_MSC_VER)
  // Disambiguate scheme names from different users
  String userDir = sb_basename(sb_dirname(sb_dirname(m_absPath)));
  if (strEndsWith(userDir, ".xcuserdatad"))
    m_name = m_name + " (" + sb_fname(userDir) + ")";
#endif
}

XCScheme* XCScheme::createFromFile(const String& schemePath, const PBXProject* owner)
{
  // Check that the owner is valid
  if (!owner) {
    return NULL;
  }

  // Get absolute path to the scheme file
  String absSchemePath = sb_realpath(schemePath);
  if (absSchemePath.empty()) {
    SBLog::warning() << "The \"" << schemePath << "\" scheme file does not exist." << std::endl;
    return NULL;
  }

  // Read the scheme file
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_file(schemePath.c_str());
  if (!result) {
    SBLog::warning() << "Failed to parse \"" << schemePath << "\" scheme file." << std::endl;
    return NULL;
  }

  // Create a XCScheme and initialize it
  XCScheme* ret = new XCScheme(absSchemePath, owner);
  if (!ret->initFromXML(doc)) {
    delete ret;
    ret = NULL;
  }
  return ret;
}

bool XCScheme::initFromXML(const pugi::xml_document& doc)
{
  // Create an error reporter for parsing
  ErrorReporter reporter(SB_INFO, "Error parsing \"" + m_name + "\" scheme for \"" + m_parentProject->getName() + "\" project. ");
  
  // Find and process all BuildActionEntry nodes
  pugi::xpath_node_set baSet = doc.select_nodes("/Scheme/BuildAction/BuildActionEntries/BuildActionEntry");
  for (pugi::xpath_node_set::const_iterator it = baSet.begin(); it != baSet.end(); ++it)
    parseBuildAction(it->node(), reporter);
    
  // Find and process all ArchiveAction nodes
  pugi::xpath_node_set aaSet = doc.select_nodes("/Scheme/ArchiveAction");
  for (pugi::xpath_node_set::const_iterator it = aaSet.begin(); it != aaSet.end(); ++it)
    parseArchiveAction(it->node(), reporter);
  
  // Make sure we got enough information
  if (m_targets.empty()) {
    reporter.reportError("Failed to read any archiveable targets.");
    return false;
  } else if (m_configName.empty()) {
    reporter.reportError("Failed to read a valid build configuration name.");
    return false;
  } else {
    return true;
  }
}

void XCScheme::parseArchiveAction(const pugi::xml_node& node, const ErrorReporter& reporter)
{
  // Get the buildConfiguration
  getXMLProperty(node, "buildConfiguration", m_configName, VALUE_REQUIRED, reporter);
}

void XCScheme::parseBuildAction(const pugi::xml_node& node, const ErrorReporter& reporter)
{
  // Get the BuildableReference node
  BuildRef br;
  const pugi::xml_node brNode = node.first_child();
  
  // Get the product name
  getXMLProperty(brNode, "BuildableName", br.productName, VALUE_REQUIRED, reporter);
  
  // Get the target name
  getXMLProperty(brNode, "BlueprintName", br.targetName, VALUE_REQUIRED, reporter);
  
  // Get the container (project) for the target
  getXMLProperty(brNode, "ReferencedContainer", br.container, VALUE_REQUIRED, reporter);
  br.container = br.container.substr(10);
  
  // Get target id
  getXMLProperty(brNode, "BlueprintIdentifier", br.id, VALUE_REQUIRED, reporter);
  
  // Check that all fields were read
  if (br.productName.empty() || br.targetName.empty() ||
      br.container.empty() || br.id.empty()) {
    reporter.reportError("BuildableReference is incomplete.");
    return;
  }

  // Get the value of buildForArchiving
  String shouldArchive;
  getXMLProperty(node, "buildForArchiving", shouldArchive, VALUE_REQUIRED, reporter);
  if (shouldArchive == "YES") {
    m_targets.push_back(br);
  } else {
    SBLog::info() << "Ignoring BuildableReference to \"" << br.targetName << "\" target because it is not archivable." << std::endl;
  }
}

