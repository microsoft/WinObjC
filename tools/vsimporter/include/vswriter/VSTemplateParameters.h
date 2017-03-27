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

typedef std::map<std::string, std::string> StringMap;

class VSTemplateParameters {
public:
    VSTemplateParameters();
    void setProjectName(const std::string& val);
    void setPublisherName(const std::string& val);
    void setTargetName(const std::string& val);
    void setIsPackageable(const bool val);
    void setPackageConfig(const std::string& val);

    void setValue(const std::string& key, const std::string& value);
    const std::string& getValue(const std::string& key) const;
    const StringMap& getValuesMap() const;

private:
    StringMap m_params;
};