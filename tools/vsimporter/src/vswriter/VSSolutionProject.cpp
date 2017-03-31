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

#include "VSSolutionProject.h"
#include "vshelpers.h"

VSSolutionProject::VSSolutionProject(VSSolution& parent) : m_parent(parent) {
}

VSSolutionProject::~VSSolutionProject() {
}

std::string VSSolutionProject::getDescription() const {
    std::string typeId = formatVSGUID(getTypeId());
    std::string id = formatVSGUID(getId());
    return "Project(\"" + typeId + "\") = \"" + getName() + "\", \"" + getPath() + "\", \"" + id + "\"";
}