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

#include "VSBuildableSolutionProject.h"
#include "VCProject.h"
#include "VSSolution.h"
#include "utils.h"
#include "vshelpers.h"

VSBuildableSolutionProject::VSBuildableSolutionProject(VCProject* project, VSSolution& parent)
    : VSSolutionProject(parent), m_project(project) {
}

VSBuildableSolutionProject::~VSBuildableSolutionProject() {
}

std::string VSBuildableSolutionProject::getName() const {
    return m_project->getName();
}

std::string VSBuildableSolutionProject::getPath() const {
    // Return a path relative to the solution directory
    std::string solutionDir = sb_dirname(m_parent.getPath());
    std::string relativePath = getRelativePath(solutionDir, m_project->getPath());
    relativePath = winPath(relativePath);
    return relativePath;
}

std::string VSBuildableSolutionProject::getTypeId() const {
    return m_project->getTypeId();
}

std::string VSBuildableSolutionProject::getId() const {
    return m_project->getId();
}

const VCProject* VSBuildableSolutionProject::getProject() const {
    return m_project;
}

void VSBuildableSolutionProject::writeProjectDependencies(std::ostream& out) const {
    const VCProjectSet& refs = m_project->getProjectReferences();
    if (refs.empty())
        return;

    out << "\t"
        << "ProjectSection(ProjectDependencies) = postProject" << std::endl;
    for (auto dep : refs) {
        std::string depProjId = formatVSGUID(dep->getId());
        out << "\t\t" << depProjId << " = " << depProjId << std::endl;
    }
    out << "\t"
        << "EndProjectSection" << std::endl;
}

void VSBuildableSolutionProject::writeDescription(std::ostream& out) const {
    out << getDescription() << std::endl;
    writeProjectDependencies(out);
    out << "EndProject" << std::endl;
}

void VSBuildableSolutionProject::writeSharedProjects(std::ostream& out) const {
    if (m_project->getSubType() == VCShared) {
        out << "\t\t" << getPath() << "*" << formatVSGUID(m_project->getId()) << "*SharedItemsImports = 9" << std::endl;
    } else {
        for (auto sproj : m_project->getSharedProjects()) {
            VSBuildableSolutionProject* solutionProj = m_parent.findBuildableProject(sproj->getPath());
            if (solutionProj) {
                out << "\t\t" << solutionProj->getPath() << "*" << formatVSGUID(m_project->getId()) << "*SharedItemsImports = 4"
                    << std::endl;
            }
        }
    }
}

void VSBuildableSolutionProject::mapConfiguration(const std::string& slnConfig, const std::string& projConfig) {
    m_configurations[slnConfig] = projConfig;
}

void VSBuildableSolutionProject::mapPlatform(const std::string& slnPlatform, const std::string& projPlatform) {
    m_platforms[slnPlatform] = projPlatform;
}

std::string VSBuildableSolutionProject::getMappedConfiguration(const std::string& slnConfig) const {
    StringMap::const_iterator it = m_configurations.find(slnConfig);
    if (it != m_configurations.end())
        return it->second;
    else
        return slnConfig;
}

std::string VSBuildableSolutionProject::getMappedPlatform(const std::string& slnPlatform) const {
    StringMap::const_iterator it = m_platforms.find(slnPlatform);
    if (it != m_platforms.end())
        return it->second;
    else
        return slnPlatform;
}