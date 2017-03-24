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

#ifndef _XCBUILDCONFIGURATION_H_
#define _XCBUILDCONFIGURATION_H_

#include <string>

#include "types.h"
#include "PBXObject.h"
#include "SimpleVariableCollection.h"

class PBXFileReference;

class XCBuildConfiguration : public PBXObject {
public:
    virtual ~XCBuildConfiguration();
    virtual void resolvePointers();

    const String& getName() const {
        return m_name;
    }
    const VariableCollection& getBuildSettings() const {
        return m_buildSettings;
    }
    const PBXFileReference* getBaseConfiguration() const {
        return m_baseConfigurationPtr;
    }

    static XCBuildConfiguration* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

private:
    XCBuildConfiguration();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    String m_baseConfigurationId;
    SimpleVariableCollection m_buildSettings;
    String m_name;
    /* End of serialized values */

    PBXFileReference* m_baseConfigurationPtr;
};

#endif /* _XCBUILDCONFIGURATION_H_ */
