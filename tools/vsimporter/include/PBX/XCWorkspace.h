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

#ifndef _XCWORKSPACE_H_
#define _XCWORKSPACE_H_

#include "types.h"

namespace pugi {
class xml_document;
class xml_node;
};

class XCWorkspace {
public:
    static XCWorkspace* createFromFile(const String& workspacePath);
    const String& getPath() const;
    String getName() const;
    const StringVec& getProjectPaths() const;

private:
    XCWorkspace(const String& absWorkspacePath);
    bool initFromXMLDoc(const pugi::xml_document& doc);
    void processGroup(const pugi::xml_node& groupNode, const String& parentPath);
    String extractLocation(const pugi::xml_node& node, const String& parentPath);

    String m_absPath;
    StringVec m_projectPaths;
};

#endif /* _XCWORKSPACE_H_ */