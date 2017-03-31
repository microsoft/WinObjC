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
#include "VSSolutionProject.h"

class VCProject;
class VSBuildableSolutionProject;

class VSSolutionFolderProject : public VSSolutionProject {
public:
    friend class VSSolution;

    virtual std::string getName() const;
    virtual std::string getPath() const;
    virtual std::string getTypeId() const;
    virtual std::string getId() const;
    virtual const VCProject* getProject() const {
        return NULL;
    }
    virtual void writeDescription(std::ostream& out) const;

    VSBuildableSolutionProject* addProject(VCProject* project);
    VSSolutionFolderProject* addFolder(const std::string& name);
    void addFile(const std::string& filePath);

private:
    typedef std::set<std::string> StringSet;

    VSSolutionFolderProject(const std::string& name, VSSolution& parent);
    void writeFileDescriptions(std::ostream& out) const;

    std::string m_name;
    std::string m_id;
    StringSet m_files;
};