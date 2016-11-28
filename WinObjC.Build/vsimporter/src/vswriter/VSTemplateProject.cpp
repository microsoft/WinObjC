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

#include "VSTemplateProject.h"
#include "VSTemplateParameters.h"
#include <pugixml.hpp>
#include "sbassert.h"
#include "SBLog.h"
#include "utils.h"
#include "tokenizer.h"

struct ProjectItem {
  ProjectItem(const std::string& input, const std::string& output, bool replace)
    : replaceParams(replace), inFile(input), outFile(output) {}
  ProjectItem() : replaceParams(true) {}

  bool replaceParams;
  std::string inFile;
  std::string outFile;
};

VSTemplateProject::VSTemplateProject()
: m_shared(false) {}

VSTemplateProject::~VSTemplateProject()
{
  for (auto item : m_items) {
    delete item;
  }
}

bool VSTemplateProject::isShared() const
{
  return m_shared;
}

bool VSTemplateProject::isDeployable() const
{
  return m_deployable;
}

const std::string& VSTemplateProject::getName() const
{
  auto projectNameIt = m_params.find("$projectname$");
  if (projectNameIt != m_params.end()) {
    return projectNameIt->second;
  } else {
    return "";
  }
}

const std::string& VSTemplateProject::getPath() const
{
  sbAssertWithTelemetry(!m_items.empty(), "VSTemplateProject contains no items");
  return m_items.front()->outFile;
}

const StringVec& VSTemplateProject::getPlatforms() const
{
  return m_platforms;
}

VSTemplateProject* VSTemplateProject::createFromXML(const pugi::xml_node& pNode)
{
  // Create a VSTemplate and initialize it
  VSTemplateProject* ret = new VSTemplateProject();
  if (!ret->initFromXML(pNode)) {
    delete ret;
    ret = NULL;
  }
  return ret;
}

bool VSTemplateProject::initFromXML(const pugi::xml_node& pNode)
{
  // Create a ProjectItem from the project description
  ProjectItem* projectDesc = new ProjectItem;
  projectDesc->inFile = pNode.attribute("File").value();
  projectDesc->outFile = pNode.attribute("TargetFileName").value();
  projectDesc->replaceParams = pNode.attribute("ReplaceParameters").as_bool();
  m_items.push_back(projectDesc);
  
  tokenize(pNode.attribute("Platforms").value(), m_platforms, ";");
  m_shared = pNode.attribute("Shared").as_bool();
  m_deployable = pNode.attribute("Deployable").as_bool();
  m_outputDir = pNode.attribute("OutputDirectory").value();
  if (m_outputDir.empty()) {
    m_outputDir = "$projectname$";
  }

  // Extract project items
  for (pugi::xml_node child = pNode.first_child(); child; child = child.next_sibling()) {
    if (child.name() == std::string("ProjectItem")) {
      bool replaceParams = child.attribute("ReplaceParameters").as_bool();
      std::string inFile = child.child_value();
      std::string outFile = child.attribute("TargetFileName").value();
      if (outFile.empty()) {
        outFile = sb_basename(inFile);
      }

      ProjectItem* item = new ProjectItem(inFile, outFile, replaceParams);
      m_items.push_back(item);
    }
  }

  // Validate
  if (m_platforms.empty() && !m_shared) {
    SBLog::warning() << "Ignoring " << projectDesc->inFile << " project because it specifies no platforms." << std::endl;
    return false;
  }
  return true;
}

static void expandString(std::string& str, const StringMap& params)
{
  for (auto paramKV : params) {
    str = sb_replace(str, paramKV.first, paramKV.second, -1);
  }
}

static void expandProjectItem(const std::string& srcDir, const std::string& destDir, const StringMap& params, ProjectItem* item)
{
  // Expand paths to be absolute and pretty
  if (item) {
    expandString(item->outFile, params);
    item->outFile = joinPaths(destDir, item->outFile);
    item->outFile = platformPath(sanitizePath(item->outFile));
    item->inFile = joinPaths(srcDir, item->inFile);
    item->inFile = platformPath(sanitizePath(item->inFile));
  }
}

static bool isAppxManifestFileName(const String& fileName)
{
    const String extension = ".appxmanifest";

    if (fileName.length() < extension.length()) {
        return false;
    }

    return 0 == fileName.compare(fileName.length() - extension.length(), String::npos, extension);
}

static void insertUrlSchemes(const String& file, const StringSet& schemes)
{
    //
    // Inject registered URL schemes into the AppX manifest file, in this format:
    //
    // <Application>
    //     <Application ...>
    //         <Extensions>
    //             <uap:Extension Category="windows.protocol">
    //                 <uap:Protocol name="scheme1" />
    //             </uap:Extension>
    //             <uap:Extension Category="windows.protocol">
    //                 <uap:Protocol name="scheme2" />
    //             </uap:Extension>
    //         </Extensions>
    //     </Application>
    // </Application>
    //

    pugi::xml_document doc;
    if (!doc.load_file(file.c_str())) {
        SBLog::error() << "Failed to parse AppX manifest file " << file << std::endl;
        return;
    }

    pugi::xpath_node app = doc.select_single_node(PUGIXML_TEXT("/Package/Applications/Application"));
    if (!app) {
        SBLog::error() << "Failed to find Application element in AppX manifest file " << file << std::endl;
        return;
    }

    pugi::xml_node extensions = app.node().append_child(PUGIXML_TEXT("Extensions"));

    for (const String& scheme : schemes) {
        // pugixml doesn't have great support for handling namespaces. We just better hope
        // that our template manifests have the uap prefix mapped to the namespace
        // "http://schemas.microsoft.com/appx/manifest/uap/windows10".
        pugi::xml_node extension = extensions.append_child(PUGIXML_TEXT("uap:Extension"));

        extension.append_attribute(PUGIXML_TEXT("Category")).set_value(PUGIXML_TEXT("windows.protocol"));

        pugi::string_t schemeValue(scheme.begin(), scheme.end());

        pugi::xml_node protocol = extension.append_child(PUGIXML_TEXT("uap:Protocol"));
        protocol.append_attribute(PUGIXML_TEXT("Name")).set_value(schemeValue.c_str());
    }

    doc.save_file(file.c_str());
}

static void writeProjectItem(const ProjectItem* item, const StringMap& params, const StringSet& urlSchemes)
{
  if (!item)
    return;

  // Open input file
  auto inMode = item->replaceParams ? ios::in : ios::binary;
  ifstream ifs(item->inFile.c_str(), inMode);
  if (!ifs.is_open()) {
    SBLog::warning() << "Failed to open " << item->inFile << " for reading." << std::endl;
    return;
  }

  // Open output file
  ofstream ofs;
  auto outMode = item->replaceParams ? ios::out : ios::binary;
  openOutputFileStream(ofs, item->outFile, outMode);

  if (item->replaceParams) {
    // Expand input line by line and write it out
    std::string line;
    while (std::getline(ifs, line)) {
      expandString(line, params);
      ofs << line << std::endl;
    }
  } else {
    // Copy the file contents
    ofs << ifs.rdbuf();
  }

  if (!urlSchemes.empty() && isAppxManifestFileName(item->inFile)) {
      ofs.close();
      insertUrlSchemes(item->outFile, urlSchemes);
  }
}

void VSTemplateProject::expand(const std::string& srcDir, const std::string& destDir, const VSTemplateParameters& params)
{
  // Make a copy of the parameters map
  m_params = params.getValuesMap();

  // Expand the output directory and update destDir
  expandString(m_outputDir, m_params);
  std::string updatedDestDir = joinPaths(destDir, m_outputDir);

  // Handle the project items
  for (auto item : m_items) {
    expandProjectItem(srcDir, updatedDestDir, m_params, item);;
  }

}

void VSTemplateProject::write(const StringSet& urlSchemes) const
{
  for (auto item : m_items) {
    writeProjectItem(item, m_params, urlSchemes);
  }
}