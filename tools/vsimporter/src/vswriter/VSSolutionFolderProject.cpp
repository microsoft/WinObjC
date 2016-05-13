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

#include "VSSolutionFolderProject.h"
#include "VSSolution.h"
#include "vshelpers.h"
#include "sole/sole.hpp"
#include "..\WBITelemetry\WBITelemetry.h"


VSSolutionFolderProject::VSSolutionFolderProject(const std::string& name, VSSolution& parent)
: VSSolutionProject(parent), m_name(name)
{
  m_id = sole::uuid4().str();
  std::string guid = formatVSGUID(m_id);
  TELEMETRY_EVENT_GUID(L"VSImporterSolutionFolderGuid", guid);
}

std::string VSSolutionFolderProject::getName() const
{
  return m_name;
}

std::string VSSolutionFolderProject::getPath() const
{
  return m_name;
}

std::string VSSolutionFolderProject::getTypeId() const
{
  return "2150E333-8FDC-42A3-9474-1A3956D46DE8";
}

std::string VSSolutionFolderProject::getId() const
{
  return m_id;
}

void VSSolutionFolderProject::writeFileDescriptions(std::ostream& out) const
{
  if (m_files.empty())
    return;

  out << "\t" << "ProjectSection(SolutionItems) = preProject" << std::endl;
  for (auto file : m_files) {
    out << "\t" << file << " = " << file << std::endl;
  }
  out << "\t" << "EndProjectSection" << std::endl;
}

void VSSolutionFolderProject::writeDescription(std::ostream& out) const
{
  out << getDescription() << std::endl;
  writeFileDescriptions(out);
  out << "EndProject" << std::endl;
}

VSBuildableSolutionProject* VSSolutionFolderProject::addProject(VCProject* project)
{
  return m_parent.addProject(project, this);
}

VSSolutionFolderProject* VSSolutionFolderProject::addFolder(const std::string& name)
{
  return m_parent.addFolder(name, this);
}

void VSSolutionFolderProject::addFile(const std::string& filePath)
{
  m_files.insert(filePath);
}
