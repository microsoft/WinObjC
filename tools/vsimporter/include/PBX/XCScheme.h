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

#ifndef _XCSCHEME_H_
#define _XCSCHEME_H_

#include "types.h"

namespace pugi {
class xml_document;
class xml_node;
};

class PBXProject;
class ErrorReporter;

struct BuildRef {
    String id;
    String targetName;
    String productName;
    String container;
};

typedef std::list<BuildRef> BuildRefList;

class XCScheme {
public:
    static XCScheme* createFromFile(const String& schemePath, const String& containerAbsPath);
    const String& getPath() const {
        return m_absPath;
    }
    const String& getName() const {
        return m_name;
    }
    const StringSet& getConfig() const {
        return m_configName;
    }
    const BuildRefList& getTargets() const {
        return m_targets;
    }

    // Returns the parent directory of the container which has the scheme file.
    const String getContainerParentDir() const {
        return sb_dirname(m_containerAbsPath);
    };

private:
    XCScheme(const String& absSchemePath, const String& containerAbsPath);
    bool initFromXML(const pugi::xml_document& doc);
    void parseBuildAction(const pugi::xml_node& node, const ErrorReporter& report);
    void parseLaunchAction(const pugi::xml_node& node, const ErrorReporter& report);

    // Scheme path
    String m_absPath;
    // Scheme name
    String m_name;
    // List of targets to build
    BuildRefList m_targets;
    // Build configuration name
    StringSet m_configName;
    // Workspace or project abosolute path where this scheme is present.
    const String m_containerAbsPath;
};

#endif /* _XCSCHEME_H_ */
