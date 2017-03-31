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

namespace pugi {
class xml_document;
class xml_node;
};

class VSTemplateProject;
class VSTemplateParameters;

enum VSProjectType { UnknownProj, VcxProj, NuProj };

typedef std::vector<VSTemplateProject*> VSTemplateProjectVec;

class VSTemplate {
public:
    static VSTemplate* createFromFile(const std::string& templatePath);
    static VSTemplate* getTemplate(const std::string& templateName);
    ~VSTemplate();

    void expand(const std::string& destDir, const VSTemplateParameters& params);
    const VSTemplateProjectVec& getProjects() const;

private:
    VSTemplate(const std::string& absPath);
    bool initFromXML(const pugi::xml_document& doc);
    bool initTemplateData(const pugi::xml_node& tcNode);
    bool initTemplateContents(const pugi::xml_node& tcNode);

    std::string m_absPath;
    VSTemplateProjectVec m_projects;
    VSProjectType m_projectType;
};