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

#ifndef _PBXSHELLSCRIPTBUILDPHASE_H_
#define _PBXSHELLSCRIPTBUILDPHASE_H_

#include "PBXBuildPhase.h"

class PBXShellScriptBuildPhase : public PBXBuildPhase {
public:
    virtual ~PBXShellScriptBuildPhase();
    const String& getName() const {
        return m_name;
    }
    const StringVec& getInputPaths() const {
        return m_inputPaths;
    }
    const StringVec& getOutputPaths() const {
        return m_outputPaths;
    }
    const String& getShellPath() const {
        return m_shellPath;
    }
    const String& getShellScript() const {
        return m_shellScript;
    }

    static PBXShellScriptBuildPhase* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

private:
    PBXShellScriptBuildPhase();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    String m_name;
    StringVec m_inputPaths;
    StringVec m_outputPaths;
    String m_shellPath;
    String m_shellScript;
    /* End of serialized values */
};

#endif /* _PBXSHELLSCRIPTBUILDPHASE_H_ */
