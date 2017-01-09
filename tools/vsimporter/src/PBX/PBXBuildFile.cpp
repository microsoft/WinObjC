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

#include "PlistFuncs.h"
#include "sbassert.h"
#include "PBXBuildFile.h"
#include "PBXFile.h"
#include "PBXObjectIdConvert.h"

PBXBuildFile::~PBXBuildFile() {}

PBXBuildFile::PBXBuildFile()
  : m_attributes(ATTR_NONE),
    m_fileRefPtr(NULL)
{}

PBXBuildFile* PBXBuildFile::createFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc)
{
  PBXBuildFile* ret = new PBXBuildFile;
  ret->initFromPlist(id, plist, pbxDoc);
  return ret;
}

void PBXBuildFile::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc)
{
  // Call super init
  PBXObject::initFromPlist(id, plist, pbxDoc);

  // Get settings
  const Plist::dictionary_type& settingsDict = getContainerForKey<Plist::dictionary_type>(plist, "settings", VALUE_OPTIONAL, m_parseER);
  
  // Get settings.COMPILER_FLAGS
  getStringForKey(settingsDict, "COMPILER_FLAGS", m_compilerFlags, VALUE_OPTIONAL, m_parseER);
  
  // Get settings.ATTRIBUTES
  StringVec attributes;
  getStringVectorForKey(settingsDict, "ATTRIBUTES", attributes, VALUE_OPTIONAL, m_parseER);
  
  // Parse attributes
  for (unsigned i = 0; i < attributes.size(); i++) {
    if (attributes[i] == "Public")
      m_attributes |= ATTR_PUBLIC;
    else if (attributes[i] == "Private")
      m_attributes |= ATTR_PRIVATE;
  }
  
  // Get fileRef
  getStringForKey(plist, "fileRef", m_fileRefId, VALUE_REQUIRED, m_parseER);
}

void PBXBuildFile::resolvePointers()
{
  // Get fileRef ptr
  convertObjectId(m_pbxDoc, m_fileRefId, m_fileRefPtr);
}

const PBXFile* PBXBuildFile::getFile() const
{
  checkFieldPtr(m_fileRefPtr, "fileRef");
  return m_fileRefPtr;
}
