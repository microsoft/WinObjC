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

#include "sbassert.h"
#include "SBLog.h"
#include "PlistFuncs.h"
#include "PBXObject.h"
#include "PBXDocument.h"

PBXObject::~PBXObject() {}

PBXObject::PBXObject()
  : m_pbxDoc(NULL),
    m_parseER(SB_INFO),
    m_accessER(SB_WARN)
{}

void PBXObject::initFromPlist(const String& id, const Plist::dictionary_type& plist, const PBXDocument* pbxDoc)
{
  // Sanity checks
  sbAssert(!id.empty());
  sbAssert(pbxDoc);
  
  // Set id
  m_id = id;
  
  // Set owner
  m_pbxDoc = pbxDoc;
  
  // Get isa
  getStringForKey(plist, "isa", m_isa, VALUE_REQUIRED, m_parseER);
  
  // Set context for any parse errors that we might encounter
  m_parseER.setContext("Error parsing " + m_isa + " (" + m_id + ") in \"" + m_pbxDoc->getName() + "\" project. ");
  // Set context for runtime access errors
  m_accessER.setContext("Accessing malformed field of " + m_isa + " (" + m_id + ") in \"" + m_pbxDoc->getName() + "\" project. ");
}

void PBXObject::resolvePointers() {}
