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

#include <map>

typedef std::map<std::string, std::string> StringMap;
typedef std::map<std::string, StringMap> ItemDefinitionsMap;

class VCProjectConfigurationPlatform {
public:
    friend class VCProjectConfiguration;

    const std::string& getName() const;
    const VCProjectConfiguration& getParent() const;
    const StringMap& getProperties() const;
    const ItemDefinitionsMap& getItemDefinitions() const;

    void setProperty(const std::string& name, const std::string& value);
    void setItemDefinition(const std::string& itemName, const std::string& propName, const std::string& propValue);

private:
    VCProjectConfigurationPlatform(const std::string& name, const VCProjectConfiguration& parent);

    std::string m_name;
    const VCProjectConfiguration& m_parent;
    StringMap m_properties;
    ItemDefinitionsMap m_itemDefinitions;
};