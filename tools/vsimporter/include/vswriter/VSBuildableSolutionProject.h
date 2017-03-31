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
#include <map>
#include "VSSolutionProject.h"

class VCProject;

class VSBuildableSolutionProject : public VSSolutionProject {
public:
    friend class VSSolution;

    virtual ~VSBuildableSolutionProject();
    virtual std::string getName() const;
    virtual std::string getPath() const;
    virtual std::string getTypeId() const;
    virtual std::string getId() const;
    virtual const VCProject* getProject() const;
    virtual void writeDescription(std::ostream& out) const;
    void writeSharedProjects(std::ostream& out) const;

    void mapConfiguration(const std::string& slnConfig, const std::string& projConfig);
    void mapPlatform(const std::string& slnPlatform, const std::string& projPlatform);
    std::string getMappedConfiguration(const std::string& slnConfig) const;
    std::string getMappedPlatform(const std::string& slnPlatform) const;

private:
    typedef std::map<std::string, std::string> StringMap;

    VSBuildableSolutionProject(VCProject* project, VSSolution& parent); // does NOT takes ownership of pointer
    void writeProjectDependencies(std::ostream& out) const;

    VCProject* m_project;
    StringMap m_configurations;
    StringMap m_platforms;
};