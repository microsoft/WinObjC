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
#include <iostream>

class VCProject;
class VSSolution;

class VSSolutionProject {
public:
    virtual ~VSSolutionProject();
    virtual std::string getName() const = 0;
    virtual std::string getPath() const = 0;
    virtual std::string getTypeId() const = 0;
    virtual std::string getId() const = 0;
    virtual const VCProject* getProject() const = 0;
    virtual void writeDescription(std::ostream& out) const = 0;

protected:
    VSSolutionProject(VSSolution& parent);
    std::string getDescription() const;

    VSSolution& m_parent;
};