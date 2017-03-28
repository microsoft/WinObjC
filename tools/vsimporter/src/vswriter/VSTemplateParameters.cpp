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

#include "VSTemplateParameters.h"
#include "BuildSettings.h"
#include "utils.h"
#include <sole/sole.hpp>

static std::string getSafeString(std::string str, char replacement) {
    if (!str.empty()) {
        // First characters must be a letter (or the replacement character)
        // Subsequent letters can be alphanumeric (or the replacement character)
        for (size_t posn = 0; posn < str.size(); posn++) {
            if (!isalnum(str[posn]) || (posn == 0 && !isalpha(str[posn])))
                str[posn] = replacement;
        }
    }

    return str;
}

VSTemplateParameters::VSTemplateParameters() {
    const BuildSettings bs(NULL);

    // Set up basic parameters map
    for (unsigned i = 1; i <= 10; i++) {
        m_params["$guid" + std::to_string(i) + "$"] = sole::uuid4().str();
    }
    m_params["$targetnametoken$"] = "$targetnametoken$";

    m_params["$ToolsVersion$"] = bs.getValue("TOOLS_VERSION");
    m_params["$MinimumVisualStudioVersion$"] = bs.getValue("MINIMUM_VISUAL_STUDIO_VERSION");
    m_params["$PlatformToolset$"] = bs.getValue("PLATFORM_TOOLSET");
}

void VSTemplateParameters::setProjectName(const std::string& val) {
    m_params["$projectname$"] = val;
    m_params["$safeprojectname$"] = getSafeString(val, '_');
}

void VSTemplateParameters::setPublisherName(const std::string& val) {
    if (!val.empty()) {
        m_params["$XmlEscapedPublisher$"] = val;
        m_params["$XmlEscapedPublisherDistinguishedName$"] = "CN=" + val;
    }
}

void VSTemplateParameters::setIsPackageable(const bool val) {
    setPackageConfig((val ? "packageable." : ""));
}

void VSTemplateParameters::setPackageConfig(const std::string& val) {
    m_params["$packageconfig$"] = val;
}

void VSTemplateParameters::setValue(const std::string& key, const std::string& value) {
    m_params[key] = value;
}

const std::string& VSTemplateParameters::getValue(const std::string& key) const {
    auto foundKV = m_params.find(key);
    if (foundKV != m_params.end()) {
        return foundKV->second;
    } else {
        static std::string emptyStr;
        return emptyStr;
    }
}

const StringMap& VSTemplateParameters::getValuesMap() const {
    return m_params;
}