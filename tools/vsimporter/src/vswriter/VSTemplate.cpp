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

#include "VSTemplate.h"
#include "VSTemplateProject.h"
#include "BuildSettings.h"
#include <pugixml.hpp>
#include "utils.h"
#include "SBLog.h"

VSTemplate::VSTemplate(const std::string& absPath)
: m_absPath(absPath) {}

VSTemplate::~VSTemplate()
{
  for (auto proj : m_projects) {
    delete proj;
  }
}

VSTemplate* VSTemplate::getTemplate(const std::string& templateName)
{
  // Get template directory
  const BuildSettings bs(NULL);
  String templatesDir = bs.getValue("VSIMPORTER_TEMPLATES_DIR");
  String outputFormat = bs.getValue("VSIMPORTER_OUTPUT_FORMAT");

  // Construct template name
  String templateFile = joinPaths(outputFormat + "-" + templateName, "Project.vstemplate");
  String templatePath = joinPaths(templatesDir, templateFile);

  return VSTemplate::createFromFile(templatePath);
}

VSTemplate* VSTemplate::createFromFile(const std::string& templatePath)
{
  // Get absolute path to the template file
  String absTemplatePath = sb_realpath(templatePath);
  if (absTemplatePath.empty()) {
    SBLog::warning() << "The \"" << templatePath << "\" VS template file does not exist." << std::endl;
    return NULL;
  }

  // Read the template file
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_file(templatePath.c_str());
  if (!result) {
    SBLog::warning() << "Failed to parse \"" << templatePath << "\" VS template file." << std::endl;
    return NULL;
  }

  // Create a VSTemplate and initialize it
  VSTemplate* ret = new VSTemplate(absTemplatePath);
  if (!ret->initFromXML(doc)) {
    delete ret;
    ret = NULL;
  }
  return ret;
}

bool VSTemplate::initFromXML(const pugi::xml_document& doc)
{
  // Get the root node
  pugi::xml_node rootNode = doc.first_child();
  String rootName = rootNode.name();
  String templateVersion = rootNode.attribute("Version").value();
  String templateType = rootNode.attribute("Type").value();

  // Verify the root node
  String errDesc = "Problem reading " + m_absPath + ". ";
  if (rootName != "VSTemplate") {
    SBLog::error() << errDesc << "Unexpected root node: " << rootName << std::endl;
    return false;
  }
  if (templateVersion != "0.0.0") {
    SBLog::warning() << errDesc << "Unexpected version: " << templateVersion << std::endl;
    return false;
  }
  if (templateType != "Project") {
    SBLog::warning() << errDesc << "Unexpected type: " << templateType << std::endl;
    return false;
  }

  bool status = true;
  for (pugi::xml_node child = rootNode.first_child(); child && status; child = child.next_sibling()) {
    if (child.name() == std::string("TemplateContent")) {
      status = initTemplateContents(child);
    }
  }

  return status;
}

bool VSTemplate::initTemplateContents(const pugi::xml_node& tcNode)
{
  bool status = true;
  for (pugi::xml_node child = tcNode.first_child(); child && status; child = child.next_sibling()) {
    if (child.name() == std::string("Project")) {
      VSTemplateProject* proj = VSTemplateProject::createFromXML(child);
      if (proj) {
        m_projects.push_back(proj);
      }
    }
  }

  return status;
}

void VSTemplate::expand(const std::string& destDir, const VSTemplateParameters& params)
{
  std::string srcDir = sb_dirname(m_absPath);

  for (auto project : m_projects) {
    project->expand(srcDir, destDir, params);
  }
}

const VSTemplateProjectVec& VSTemplate::getProjects() const
{
  return m_projects;
}