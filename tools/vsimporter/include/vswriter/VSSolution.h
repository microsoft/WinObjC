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
#include <set>
#include <map>

class VSSolutionProject;
class VSBuildableSolutionProject;
class VSSolutionFolderProject;
class VCProject;

class VSSolution {
public:
    VSSolution(const std::string& absPath, unsigned version = 15);
    ~VSSolution();
    const std::string& getPath();
    VSBuildableSolutionProject* addProject(VCProject* project,
                                           VSSolutionFolderProject* parent = NULL); // own the VSBuildableSolutionProject but not VCProject
    VSSolutionFolderProject* addFolder(const std::string& name, VSSolutionFolderProject* parent = NULL); // own the VSSolutionFolderProject
    VSSolutionProject* getProjectWithId(const std::string& id);

    VSBuildableSolutionProject* findBuildableProject(const std::string& path);
    const VSBuildableSolutionProject* findBuildableProject(const std::string& path) const;

    void addConfiguration(const std::string& name);
    void addPlatform(const std::string& name);

    bool write() const;
    void write(std::ostream& out) const;

private:
    typedef std::map<std::string, VSBuildableSolutionProject*> BuildableProjectMap;
    typedef std::multimap<VSSolutionFolderProject*, VSSolutionProject*> ProjectNestingMap;
    typedef std::set<std::string> StringSet;

    VSSolutionProject* findProjectWithName(const std::string& name, VSSolutionFolderProject* parent);
    void validateUUIDs() const;
    void writeProjectDescriptions(std::ostream& out) const;
    void writeSharedMSBuildProjectFiles(std::ostream& out) const;
    void writeSolutionConfigurationPlatforms(std::ostream& out) const;
    void writeProjectConfigurationPlatforms(std::ostream& out) const;
    void writeSolutionProperties(std::ostream& out) const;
    void writeNestedProjects(std::ostream& out) const;

    unsigned m_version;
    std::string m_absFilePath;
    BuildableProjectMap m_buildableProjects;
    ProjectNestingMap m_nestingMap;
    StringSet m_configurations;
    StringSet m_platforms;
};