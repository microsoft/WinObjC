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

#include "VCSharedProject.h"
#include "VCProjectItem.h"
#include "sole/sole.hpp"
#include "sbassert.h"
#include "SBLog.h"
#include "fileutils.h"
#include "vshelpers.h"

VCSharedProject::~VCSharedProject() {
}

VCSharedProject::VCSharedProject(VSTemplateProject* projTemplate) : VCProject(projTemplate) {
    m_sharedId = sole::uuid4().str();

    m_globalProps.clear();
    addGlobalProperty("ItemsProjectGuid", formatVSGUID(m_id));
    addGlobalProperty("SharedGUID", formatVSGUID(m_sharedId));
}

const std::string& VCSharedProject::getSharedId() const {
    return m_sharedId;
}

void VCSharedProject::setUserMacro(const std::string& name, const std::string& value) {
}

void VCSharedProject::addProjectReference(const VCProject* refProj) {
}

void VCSharedProject::addSharedProject(const VCProject* sharedProj) {
}

VCProjectConfiguration* VCSharedProject::addConfiguration(const std::string& name) {
    return NULL;
}

void VCSharedProject::addBuildExtension(const std::string& extension) {
}

VCProjectItem* VCSharedProject::addItem(const std::string& itemName, const std::string& includePath, const std::string& filterPath) {
    // Without this fix, VS looks for the files in the wrong place
    String fixedIncludePath(includePath);
    if (!isAbsolutePath(includePath)) {
        fixedIncludePath = "$(MSBuildThisFileDirectory)" + fixedIncludePath;
    }
    return VCProject::addItem(itemName, fixedIncludePath, filterPath);
}

bool VCSharedProject::writeProject() const {
    LabelHandlerFnMap nodeHandlers;
    nodeHandlers["GlobalProperties"] = &VCSharedProject::writeGlobalProperties;
    nodeHandlers["ProjectItems"] = &VCSharedProject::writeProjectItems;

    return writeTemplate(getPath(), nodeHandlers);
}