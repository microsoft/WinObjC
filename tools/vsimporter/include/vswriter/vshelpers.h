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
#include <pugixml.hpp>
#include "ConditionalValue.h"

std::string getVSConfigurationPlatform(const std::string& configName, const std::string& platformName);
std::string getVSConfigurationPlatformCond(const std::string& configName, const std::string& platformName);
std::string formatVSGUID(const std::string& guid);
pugi::xml_node appendNodeWithText(pugi::xml_node& parent,
                                  const std::string& nodeName,
                                  const std::string& nodeText,
                                  const std::string& nodeCond = "");
void writePropertiesMap(const std::map<std::string, std::string>& props, pugi::xml_node& parent);
void writePropertiesMap(const ConditionalValueListMap& props, pugi::xml_node& parent);
void removeNode(pugi::xml_node& node);
void mergeNodes(pugi::xml_node toNode, pugi::xml_node& fromNode);