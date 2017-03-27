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

#include "VCProject.h"

class VCSharedProject : public VCProject {
public:
    virtual ~VCSharedProject();
    VCSharedProject(VSTemplateProject* projTemplate);
    const std::string& getSharedId() const;

    virtual VCProjectItem* addItem(const std::string& itemName, const std::string& includePath, const std::string& filterPath = "");

    // These functions will do nothing
    virtual void setUserMacro(const std::string& name, const std::string& value);
    virtual void addProjectReference(const VCProject* refProj);
    virtual void addSharedProject(const VCProject* sharedProj);
    virtual VCProjectConfiguration* addConfiguration(const std::string& name);
    virtual void addBuildExtension(const std::string& extension);

protected:
    virtual bool writeProject() const;

    std::string m_sharedId;
};