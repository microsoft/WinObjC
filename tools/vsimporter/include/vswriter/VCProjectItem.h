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
#include "ConditionalValue.h"

namespace pugi {
class xml_node;
};

class VCProjectItem {
public:
    friend class VCProject;

    const std::string& getItemName() const;
    const std::string& getIncludePath() const;
    const std::string& getFilterPath() const;
    const ConditionalValueListMap& getDefinitions() const;

    void setItemName(const std::string& itemName);
    void setItemPath(const std::string& itemPath);
    void setFilterPath(const std::string& filterPath);
    void setDefinition(const std::string& name, const std::string& value, const std::string& condition = "");

    void writeDescription(pugi::xml_node& parent) const;

private:
    VCProjectItem(const std::string& itemName, const std::string& includePath, const std::string& filterPath = "");

    std::string m_itemName;
    std::string m_includePath;
    std::string m_filterPath;
    ConditionalValueListMap m_definitions;
};