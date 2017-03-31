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

#include "VCProjectItem.h"
#include "pugixml.hpp"
#include "vshelpers.h"

VCProjectItem::VCProjectItem(const std::string& itemName, const std::string& includePath, const std::string& filterPath)
    : m_itemName(itemName), m_includePath(includePath), m_filterPath(filterPath) {
}

const std::string& VCProjectItem::getItemName() const {
    return m_itemName;
}

const std::string& VCProjectItem::getIncludePath() const {
    return m_includePath;
}

const std::string& VCProjectItem::getFilterPath() const {
    return m_filterPath;
}

void VCProjectItem::setItemName(const std::string& itemName) {
    m_itemName = itemName;
}

void VCProjectItem::setItemPath(const std::string& includePath) {
    m_includePath = includePath;
}

void VCProjectItem::setFilterPath(const std::string& filterPath) {
    m_filterPath = filterPath;
}

const ConditionalValueListMap& VCProjectItem::getDefinitions() const {
    return m_definitions;
}

void VCProjectItem::setDefinition(const std::string& name, const std::string& value, const std::string& condition) {
    if (!name.empty())
        m_definitions[name].push_back(ConditionalValue(value, condition));
}

void VCProjectItem::writeDescription(pugi::xml_node& parent) const {
    pugi::xml_node item = parent.append_child(m_itemName.c_str());
    item.append_attribute("Include") = m_includePath.c_str();
    writePropertiesMap(m_definitions, item);
}