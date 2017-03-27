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

#ifndef _EXPANDVARS_H_
#define _EXPANDVARS_H_

#include "types.h"

class VariableCollectionHierarchy;

class XCVariableExpander {
public:
    XCVariableExpander(const VariableCollectionHierarchy& vch, size_t maxSearchLevel);

    void expandString(const String& str, String& ret);
    bool getExpandedValue(const String& varName, String& ret);

private:
    typedef std::map<const String, size_t> VariableMarkerMap;
    typedef std::pair<const String, size_t> VariableMarkerPair;

    XCVariableExpander(); // disallow
    size_t processPossibleVar(const String& str, size_t posn, String& ret);
    size_t processBracketedVar(const String& str, size_t posn, String& ret);
    size_t processSimpleVar(const String& str, size_t posn, String& ret);
    String getInheritedName(const String& varName);

    VariableMarkerMap m_varMarkers;
    String m_currentVar;
    const VariableCollectionHierarchy& m_vch;
    size_t m_maxSearchLevel;
};

#endif /* _EXPANDVARS_H_ */
