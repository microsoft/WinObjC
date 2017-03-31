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
#include <set>

namespace pugi {
class xml_node;
};

class VCProjectConfigurationPlatform;

typedef std::map<std::string, VCProjectConfigurationPlatform*> PlatformMap;

class VCProjectConfiguration {
public:
    friend class VCProject;

    ~VCProjectConfiguration();
    const std::string& getName() const;
    const PlatformMap& getPlatforms() const;
    VCProjectConfigurationPlatform* addPlatform(const std::string& platformName);
    void removePlatform(const std::string& platform);
    bool setProperty(const std::string& pName, const std::string& pValue);
    bool setItemDefinition(const std::string& item, const std::string& pName, const std::string& pValue);

    void writeSummary(pugi::xml_node& parent) const;
    void writeProperties(pugi::xml_node& bookmark) const;
    void writePropertySheets(pugi::xml_node& bookmark) const;
    void writeItemDefinitions(pugi::xml_node& bookmark) const;

private:
    VCProjectConfiguration(const std::string& name);

    std::string m_name;
    PlatformMap m_platforms;
};