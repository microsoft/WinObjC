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

#include "XCWorkspace.h"
#include "ErrorReporter.h"
#include "SBLog.h"
#include "utils.h"
#include "XMLFuncs.h"
#include "BuildSettings.h"
#include "pugixml.hpp"

XCWorkspace::XCWorkspace(const String& absWorkspacePath) : m_absPath(absWorkspacePath) {
}

const String& XCWorkspace::getPath() const {
    return m_absPath;
}

String XCWorkspace::getName() const {
    return sb_fname(sb_basename(m_absPath));
}

const StringVec& XCWorkspace::getProjectPaths() const {
    return m_projectPaths;
}

XCWorkspace* XCWorkspace::createFromFile(const String& workspacePath) {
    // Get absolute path to the workspace directory
    String absWorkspacePath = sb_realpath(workspacePath);
    if (absWorkspacePath.empty()) {
        SBLog::error() << "The \"" << workspacePath << "\" workspace directory does not exist." << std::endl;
        return NULL;
    }

    // Construct full path to the workspace data file
    String workspaceFile = joinPaths(absWorkspacePath, "contents.xcworkspacedata");

    // Read the workspace file
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(workspaceFile.c_str());
    if (!result) {
        SBLog::error() << "Failed to parse the \"" << workspaceFile << "\" workspace file." << std::endl;
        return NULL;
    }

    // Create a XCWorkspace and initialize it
    XCWorkspace* ret = new XCWorkspace(absWorkspacePath);
    if (!ret->initFromXMLDoc(doc)) {
        delete ret;
        ret = NULL;
    }
    return ret;
}

bool XCWorkspace::initFromXMLDoc(const pugi::xml_document& doc) {
    // Get the root node
    pugi::xml_node rootNode = doc.first_child();
    String rootName = rootNode.name();
    String version = rootNode.attribute("version").value();

    // Verify the root node
    if (rootName != "Workspace") {
        SBLog::error() << "Unexpected root node in \"" << getName() << "\" workspace." << std::endl;
        return false;
    }
    if (!version.empty() && version != "1.0") {
        SBLog::warning() << "Unexpected workspace version: " << version << std::endl;
    }

    // Process the workspace description
    processGroup(rootNode, sb_dirname(m_absPath));

    return true;
}

void XCWorkspace::processGroup(const pugi::xml_node& groupNode, const String& parentPath) {
    String location;
    String groupName = groupNode.name();
    if (groupName == "Group")
        location = extractLocation(groupNode, parentPath);
    else if (groupName == "Workspace")
        location = parentPath;

    for (pugi::xml_node node = groupNode.first_child(); node; node = node.next_sibling()) {
        String name = node.name();
        if (node.type() != pugi::node_element) {
            // Ignore node
        } else if (name == "Group") {
            processGroup(node, location);
        } else if (name == "FileRef") {
            String filePath = extractLocation(node, location);
            if (strEndsWith(filePath, ".xcodeproj")) {
                m_projectPaths.push_back(filePath);
            } else {
                SBLog::debug() << "Ignoring workspace reference to \"" << filePath << "\"." << std::endl;
            }
        }
    }
}

String XCWorkspace::extractLocation(const pugi::xml_node& node, const String& parentPath) {
    String location;
    ErrorReporter reporter(SB_WARN, "Failure parsing \"" + getName() + "\" workspace. ");
    getXMLProperty(node, "location", location, VALUE_REQUIRED, reporter);

    // Get position of semicolon
    std::size_t posn = location.find_first_of(':');

    // Separate location into two parts based on the semicolon
    String pathPrefix;
    String filePath;
    if (posn != String::npos) {
        pathPrefix = location.substr(0, posn);
        filePath = location.substr(posn + 1);
    }

    /* self: workspace is inside the project
     * container: relative to workspace dir
     * group: relative to group
     * developer: relative to developer dir
     * absolute: absolute path
     */
    String combinedPath;
    if (pathPrefix == "self") {
        combinedPath = joinPaths("../..", filePath);
        combinedPath = joinPaths(m_absPath, combinedPath);
    } else if (pathPrefix == "container" || pathPrefix == "absolute") {
        combinedPath = joinPaths("..", filePath);
        combinedPath = joinPaths(m_absPath, combinedPath);
    } else if (pathPrefix == "group") {
        combinedPath = joinPaths(parentPath, filePath);
    } else if (pathPrefix == "developer") {
        const BuildSettings bs(NULL);
        combinedPath = joinPaths(bs.getValue("VSIMPORTER_BINARY_DIR"), filePath);
    } else {
        reporter.reportError("Failed to parse location: " + location);
    }

    return combinedPath;
}