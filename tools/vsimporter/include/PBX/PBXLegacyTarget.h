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

#ifndef _PBXLEGACYTARGET_H_
#define _PBXLEGACYTARGET_H_

#include "PBXTarget.h"

class PBXLegacyTarget : public PBXTarget {
public:
  virtual ~PBXLegacyTarget();
  virtual String getTargetType() const { return "Legacy";  }

  const String& getBuildArguments() const { return m_buildArgumentsString; }
  const String& getBuildToolPath() const { return m_buildToolPath; }
  const String& getBuildWorkingDir() const { return m_buildWorkingDirectory; }
  bool getPassBuildSettings() const { return m_passBuildSettingsInEnvironment; }
  
  static PBXLegacyTarget* createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);
  
private:
  PBXLegacyTarget();
  virtual void initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc);
  
/* Start of serialized values */
  String m_buildArgumentsString;
  String m_buildToolPath;
  String m_buildWorkingDirectory;
  int m_passBuildSettingsInEnvironment;
/* End of serialized values */
};

#endif /* _PBXLEGACYTARGET_H_ */
