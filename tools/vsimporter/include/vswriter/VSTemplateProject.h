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
#include <vector>
#include <map>
#include <set>

namespace pugi {
class xml_node;
};

class VSTemplateParameters;
class ProjectItem;
enum VSProjectType;

typedef std::vector<ProjectItem*> ProjectItemVec;
typedef std::vector<std::string> StringVec;
typedef std::map<std::string, std::string> StringMap;
typedef std::set<std::string> StringSet;

class VSTemplateProject {
public:
    static VSTemplateProject* createFromXML(const pugi::xml_node& pNode, const VSProjectType projectType);
    ~VSTemplateProject();

    void expand(const std::string& srcDir, const std::string& destDir, const VSTemplateParameters& params);
    void write(const StringSet& urlSchemes) const;

    bool isShared() const;
    bool isDeployable() const;
    const std::string& getName() const;
    const std::string& getPath() const;
    const StringVec& getPlatforms() const;
    const VSProjectType getProjectType() const;

private:
    VSTemplateProject();
    bool initFromXML(const pugi::xml_node& pNode, const VSProjectType projectType);

    bool m_shared;
    bool m_deployable;
    std::string m_outputDir;
    StringVec m_platforms;
    ProjectItemVec m_items;
    StringMap m_params;
    VSProjectType m_projectType;
};