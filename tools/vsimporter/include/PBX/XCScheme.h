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
  static XCScheme* createFromFile(const String& schemePath, const PBXProject* owner);
  const String& getPath() const { return m_absPath; }
  const String& getName() const { return m_name; }
  const String& getConfig() const { return m_configName; }
  const PBXProject* getProject() const { return m_parentProject; }
  const BuildRefList& getTargets() const { return  m_targets; }

private:
  XCScheme(const String& absSchemePath, const PBXProject* owner);
  bool initFromXML(const pugi::xml_document& doc);
  void parseBuildAction(const pugi::xml_node& node, const ErrorReporter& report);
  void parseArchiveAction(const pugi::xml_node& node, const ErrorReporter& report);
  
  // Scheme path
  String m_absPath;
  // Scheme name
  String m_name;
  // List of targets to build
  BuildRefList m_targets;
  // Build configuration name
  String m_configName;
  // Project to which this scheme belongs
  const PBXProject* m_parentProject;
};

#endif /* _XCSCHEME_H_ */
