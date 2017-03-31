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

#ifndef _PBXBUILDRULE_H_
#define _PBXBUILDRULE_H_

#include "PBXObject.h"

class PBXBuildRule : public PBXObject {
public:
    virtual ~PBXBuildRule();
    virtual void resolvePointers() {
    }

    const String& getCompilerSpec() const {
        return m_compilerSpec;
    }
    const String& getFileType() const {
        return m_fileType;
    }
    const String& getFilePatterns() const {
        return m_filePatterns;
    }
    const StringVec& getOutputFiles() const {
        return m_outputFiles;
    }
    const String& getScript() const {
        return m_script;
    }

    static PBXBuildRule* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

private:
    PBXBuildRule();
    virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);

    /* Start of serialized values */
    String m_compilerSpec;
    String m_filePatterns;
    String m_fileType;
    StringVec m_outputFiles;
    String m_script;
    /* End of serialized values */
};

#endif /* _PBXBUILDRULE_H_ */