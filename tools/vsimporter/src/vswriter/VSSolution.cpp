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

#include <fstream>

#include "sbassert.h"
#include "utils.h"
#include "VSSolution.h"
#include "VCProject.h"
#include "VSBuildableSolutionProject.h"
#include "VSSolutionFolderProject.h"
#include "vshelpers.h"
#include "..\WBITelemetry\WBITelemetry.h"

VSSolution::VSSolution(const std::string& absPath, unsigned version)
: m_absFilePath(platformPath(sanitizePath(absPath))), m_version(version)
{
	sbAssertWithTelemetry(isAbsolutePath(absPath), "Path to VS solution is not absolute");
}

VSSolution::~VSSolution()
{
  for (auto project : m_nestingMap)
    delete project.second;
}

const std::string& VSSolution::getPath()
{
  return m_absFilePath;
}

const VSBuildableSolutionProject* VSSolution::findBuildableProject(const std::string& path) const
{
  auto foundIt = m_buildableProjects.find(path);
  if (foundIt != m_buildableProjects.end())
    return foundIt->second;
  else
    return NULL;
}

VSBuildableSolutionProject* VSSolution::findBuildableProject(const std::string& path)
{
  return const_cast<VSBuildableSolutionProject*>(static_cast<const VSSolution*>(this)->findBuildableProject(path));
}

VSSolutionProject* VSSolution::findProjectWithName(const std::string& name, VSSolutionFolderProject* parent)
{
  std::pair<ProjectNestingMap::iterator,ProjectNestingMap::iterator> siblingsRange = m_nestingMap.equal_range(parent);
  ProjectNestingMap::iterator sIt = siblingsRange.first;
  for (; sIt != siblingsRange.second && sIt->second->getName() != name; sIt++) {}
  if (sIt != siblingsRange.second)
    return sIt->second;
  else
    return NULL;
}

VSSolutionProject* VSSolution::getProjectWithId(const std::string& id)
{
  for (auto project : m_nestingMap) {
    if (project.second->getId() == id) {
      return project.second;
    }
  }
  return NULL;
}

VSBuildableSolutionProject* VSSolution::addProject(VCProject* project, VSSolutionFolderProject* parent)
{
  // Check if project is valid
  if (!project)
    return NULL;

  // Check if project is in the solution already
  VSBuildableSolutionProject* existingProject = findBuildableProject(project->getPath());
  if (existingProject)
    return existingProject;

  // Check for an existing project with the same name
  VSSolutionProject* otherProject = findProjectWithName(project->getName(), parent);
  if (otherProject)
    return NULL;

  // Create the project
  VSBuildableSolutionProject* buildableProject = new VSBuildableSolutionProject(project, *this);
  m_buildableProjects.insert(std::make_pair(project->getPath(), buildableProject));
  m_nestingMap.insert(std::make_pair(parent, buildableProject));
  return buildableProject;
}

VSSolutionFolderProject* VSSolution::addFolder(const std::string& name, VSSolutionFolderProject* parent)
{
  // Check if name is valid
  if (name.empty())
    return NULL;

  // Check for an existing project with the same name
  VSSolutionProject* otherProject = findProjectWithName(name, parent);
  if (otherProject)
    return dynamic_cast<VSSolutionFolderProject*>(otherProject);

  // Create the project
  VSSolutionFolderProject* folder = new VSSolutionFolderProject(name, *this);
  m_nestingMap.insert(std::make_pair(parent, folder));
  return folder;
}

void VSSolution::addConfiguration(const std::string& name)
{
  if (!name.empty())
    m_configurations.insert(name);
}
void VSSolution::addPlatform(const std::string& name)
{
  if (!name.empty())
    m_platforms.insert(name);
}

bool VSSolution::write() const
{
  // Open solution file for writing
  std::ofstream ofs;
  openOutputFileStream(ofs, m_absFilePath);
  write(ofs);

  return ofs.is_open();
}

void VSSolution::writeProjectDescriptions(std::ostream& out) const
{
  for (auto project : m_nestingMap)
    project.second->writeDescription(out);
}

void VSSolution::writeSolutionConfigurationPlatforms(std::ostream& out) const
{
  out << "\t" << "GlobalSection(SolutionConfigurationPlatforms) = preSolution" << std::endl;
  for (auto config : m_configurations) {
    for (auto platform : m_platforms) {
      out << "\t\t" << config << "|" << platform << " = " << config << "|" << platform << std::endl;
    }
  }
  out << "\t" << "EndGlobalSection" << std::endl;
}

void VSSolution::writeSharedMSBuildProjectFiles(std::ostream& out) const
{
  out << "\t" << "GlobalSection(SharedMSBuildProjectFiles) = preSolution" << std::endl;
  for (auto project : m_buildableProjects) {
    project.second->writeSharedProjects(out);
  }
  out << "\t" << "EndGlobalSection" << std::endl;
}

void VSSolution::writeProjectConfigurationPlatforms(std::ostream& out) const
{
  out << "\t" << "GlobalSection(ProjectConfigurationPlatforms) = postSolution" << std::endl;
  for (auto project : m_buildableProjects) {
    std::string projId = formatVSGUID(project.second->getId());

    // Keeping for now - will be phased out once we get enough traction on project tracking for
    // solution folder, shared project, standard project
    TELEMETRY_EVENT_GUID(L"VSImporterNewProject", projId);

    // Ignore shared projects
    if (project.second->getProject()->getSubType() == VCShared)
        continue;
    bool isDeployable = project.second->getProject()->isDeployable();
    for (auto config : m_configurations) {
      for (auto platform : m_platforms) {

          std::string projConfig = project.second->getMappedConfiguration(config);
        std::string projPlatform = project.second->getMappedPlatform(platform);
        out << "\t\t" << projId << "." << config << "|" << platform << ".ActiveCfg = "
                                               << projConfig << "|" << projPlatform << std::endl;
        out << "\t\t" << projId << "." << config << "|" << platform << ".Build.0 = "
                                               << projConfig << "|" << projPlatform << std::endl;
        if (isDeployable) {
          out << "\t\t" << projId << "." << config << "|" << platform << ".Deploy.0 = "
                                        << projConfig << "|" << projPlatform << std::endl;
        }
      }
    }
  }
  out << "\t" << "EndGlobalSection" << std::endl;
}

void VSSolution::writeSolutionProperties(std::ostream& out) const
{
  out << "\t" << "GlobalSection(SolutionProperties) = preSolution" << std::endl;
  out << "\t\t" << "HideSolutionNode = FALSE" << std::endl;
  out << "\t" << "EndGlobalSection" << std::endl;
}

void VSSolution::writeNestedProjects(std::ostream& out) const
{
  out << "\t" << "GlobalSection(NestedProjects) = preSolution" << std::endl;
  for (auto project : m_nestingMap) {
    if (project.first) {
      std::string childId = formatVSGUID(project.second->getId());
      std::string parentId = formatVSGUID(project.first->getId());
      out << "\t\t" << childId << " = " << parentId << std::endl;
    }
  }
  out << "\t" << "EndGlobalSection" << std::endl;
}

void VSSolution::validateUUIDs() const
{
  StringSet uuids;
  for (auto project : m_nestingMap) {
    auto result = uuids.insert(project.second->getId());
    sbValidateWithTelemetry(result.second, "UUID collision detected.");
  }
}

void VSSolution::write(std::ostream& out) const
{
  // Ensure that UUIDs are unique
  validateUUIDs();

  // Write header
  out << "Microsoft Visual Studio Solution File, Format Version 12.00" << std::endl;
  if (m_version == 12) {
    out << "# Visual Studio 2013" << std::endl;
    out << "VisualStudioVersion = 12.0.21005.1" << std::endl;
  } else {
    out << "# Visual Studio 14" << std::endl;
    out << "VisualStudioVersion = 14.0.22823.1" << std::endl;
  }
  out << "MinimumVisualStudioVersion = 10.0.40219.1" << std::endl;

  // Write project descriptions
  writeProjectDescriptions(out);

  // Write globals
  out << "Global" << std::endl;
  writeSharedMSBuildProjectFiles(out);
  writeSolutionConfigurationPlatforms(out);
  writeProjectConfigurationPlatforms(out);
  writeSolutionProperties(out);
  writeNestedProjects(out);
  out << "EndGlobal" << std::endl;

  // Write project files
  for (auto project : m_buildableProjects) {
    project.second->getProject()->write();
    std::cout << "Generated " << project.second->getProject()->getPath() << std::endl;
  }

  std::cout << "Generated " << m_absFilePath << std::endl;
}